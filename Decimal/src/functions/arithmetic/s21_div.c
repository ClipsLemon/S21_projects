#include "s21_decimal.h"

s21_big_decimal s21_big_decimal_shift_right_one(s21_big_decimal decimal);
s21_big_decimal s21_big_decimal_shift_right(s21_big_decimal decimal, int shift);

int s21_is_correct_decimal(s21_big_decimal big_decimal);
int s21_div_handle(s21_big_decimal value_2l, s21_big_decimal res,
                   s21_big_decimal remainder, s21_decimal* result);
int s21_div_calc_fractional(s21_big_decimal* res, s21_big_decimal value_2l,
                            s21_big_decimal* remainder);
/**
 * @brief Делит value_1 на value_2 и записывает результат в result
 *
 * @author Hubert Furr (hubertfu@student.21-school.ru)
 * @param value_1 делимое
 * @param value_2 делитель
 * @param result частное
 * @return int код ошибки:
 * 0 - OK
 * 1 - число слишком велико или равно бесконечности
 * 2 - число слишком мало или равно отрицательной бесконечности
 * 3 - деление на 0
 * 4 - некорректные входные данные
 */
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  int code = 0;

  if (!result) {
    // Если указатель на decimal является NULL
    code = 4;
  } else if (s21_is_empty_decimal(&value_2)) {
    // Проверяем случай, когда value_2 является нулем
    code = 3;
    s21_reset_dec(result);
  } else {
    // В остальных случаях считаем частное
    s21_reset_dec(result);
    int sign1 = s21_check_sign(&value_1);
    int sign2 = s21_check_sign(&value_2);
    s21_big_decimal value_1l = s21_from_dec_to_big_dec(value_1);
    s21_big_decimal value_2l = s21_from_dec_to_big_dec(value_2);
    // Выравниваем степени делимого и делителя (знак и степень при этом будут
    // обнулены)
    s21_align_scale(&value_1l, &value_2l);
    value_1l.bits[6] = 0;
    value_2l.bits[6] = 0;

    s21_big_decimal remainder;
    s21_reset_big_dec(&remainder);
    s21_big_decimal res;

    // Делим выравненное делимое на выравненный делитель, остаток от деления
    // будет записан в remainder
    res = s21_big_binary_division(value_1l, value_2l, &remainder);
    if (res.bits[5] || res.bits[4] || res.bits[3]) {
      // Если целый результат деления уже не помещается в decimal
      // (переполнение), то возвращаем соответствующие ошибки
      if (sign1 != sign2) {
        code = 2;
      } else {
        code = 1;
      }
      s21_reset_dec(result);
    } else {
      // В остальных случаях продолжаем вычисления и вызываем вспомогательную
      // функцию для расчетов
      code = s21_div_handle(value_2l, res, remainder, result);
      // Если знаки делимого и делителя отличаются, то необходимо сделать
      // результат отрицательным
      if (sign1 != sign2) {
        s21_set_bit(result, BIT_SIGN);
      }
      // Корректируем код ответа от вспомогательной функции в случае ошибки и
      // отрицательного результата
      if (s21_check_sign(result) && code == 1) {
        code = 2;
      }
      // Обрабатываем ситуацию, что результат получился слишком маленький (0
      // < |x| < 1e-28)
      // if (code == 0 && s21_is_empty_decimal(&value_1) &&
      // s21_is_empty_decimal(result)) {
      //   code = 2;
      // }
    }
  }

  return code;
}

/**
 * @brief Вспомогательная функция для деления
 *
 * @author Hubert Furr (hubertfu@student.21-school.ru)
 * @param value_2l - делитель
 * @param res - предварительно рассчитанная целая часть от целочисленного
 * деления
 * @param remainder - предварительно рассчитанный остаток от целочисленного
 * деления
 * @param result - результат деления (вида 12.5454334)
 * @return int код ошибки, для передачи в родительскую функцию (и последующей
 * обработки)
 */
int s21_div_handle(s21_big_decimal value_2l, s21_big_decimal res,
                   s21_big_decimal remainder, s21_decimal* result) {
  int code = 0;

  // рассчитываем дробную часть нашего результата и получаем в res результат,
  // включая дробную часть после расчетов в remainder останется остаток от
  // деления (который не поместился в дробную часть) power1 - значение
  // степени
  // результата
  int power1 = s21_div_calc_fractional(&res, value_2l, &remainder);

  s21_big_decimal tmp_res;
  s21_reset_big_dec(&tmp_res);
  // Переводи остаток, полученный в расчете выше, в decimal, чтобы
  // использовать
  // его для округления power2 - значение степени данного decimal
  int power2 = s21_div_calc_fractional(&tmp_res, value_2l, &remainder);

  // Устанавливаем полученную степень для нашего остатка
  s21_set_scale_big_dec(&tmp_res, power2);

  s21_big_decimal zerofive = {{5, 0, 0, 0, 0, 0, 0}};
  s21_set_scale_big_dec(&zerofive, 1);
  s21_big_decimal mindec = {{1, 0, 0, 0, 0, 0, 0}};
  s21_set_scale_big_dec(&mindec, 28);

  if (s21_big_dec_is_equal(tmp_res, zerofive)) {
    if (!s21_is_empty_big_decimal(&remainder)) {
      // Если остаток от деления в виде decimal получился ровно 0.5, но после
      // вычисления остаток от деления не равен 0, то корректируем остаток,
      //   т.к.
      // фактически он больше 0.5: 0.5 + 0.0000000000000000000000000001 =
      // 0.5000000000000000000000000001
      s21_big_add(tmp_res, mindec, &tmp_res);
    }
  }
  // Выполняем банковское округления результата, исходя из остатка от деления
  s21_bank_round(&res, &tmp_res);
  // Устанавливаем степень результата
  s21_set_scale_big_dec(&res, power1);
  // Анализируем результат на корректность (переполнение)
  if (!(res.bits[5] == 0 || res.bits[4] == 0 || res.bits[3] == 0)) {
    code = 1;
    s21_reset_dec(result);
  } else {
    result->bits[0] = res.bits[0];
    result->bits[1] = res.bits[1];
    result->bits[2] = res.bits[2];
    result->bits[3] = res.bits[6];
  }

  return code;
}

/**
 * @brief вспомогательная функция для расчета дробной части числа.
 *
 * Например, если изначально мы делим 62/16, то получаем 3 и 14 в остатке.
 * На входе функции в res записана целая часть числа, полученная при
 * предварительном целочисленном делении. Т.е. 3 из примера выше. value_2l на
 * входе содержит 16, а remainder содержит 14
 *
 * Что делает функция:
 * Остаток умножает на 10 и опять делит на value_2l, чтобы получить первую
 цифру
 * дробной части. новый остаток опять умножается на 10 и снова делит на
 value_2l
 * и т.д., т.е.:
 *
 * 1: 14 * 10 = 140 / 16 = 8 и 12 в остатке, целую часть умножаем на 10 и
 * прибавляем 8 - 38 2: 12 * 10 = 120 / 16 = 7 и 8 в остатке, 38 умножаем на
 10
 * прибавляем 7 - 387 3: 8 * 10  = 80  / 16 = 5 и 0 в остатке, 387 умножаем
 на
 * 10 прибавляем 5 - 3875
 *
 * Итого в res записываем 3875, в remainder записываем 0, а в return
 возвращаем
 * 3, т.к. именно степень 3 превратит 3875 в decimal 3.875 (который и
 является
 * результатом 62/16)
 *
 * Если бы знаков decimal не хватило бы, чтобы записать дробь, то в remainder
 * был бы записан остаток от последнего деления, например: 59 / 15 = 3 и 14 в
 * остатке.
 *
 * 1: 140 / 15 = 9 (остаток 5) - 39
 * 2: 50 / 15 = 3 (остаток 5) - 393
 * 3: 50 / 15 = 3 (остаток 5) - 3933
 * 4: 50 / 15 = 3 (остаток 5) - 39333
 * 5: 50 / 15 = 3 (остаток 5) - 393333
 * .......
 * 28: 50 / 15 = 3 (остаток 5) - 39333333333333333333333333333
 *
 * В res записываем 39333333333333333333333333333
 * В remainder 5
 * В return 28
 *
 * @param res предварительно рассчитанная целая часть от целочисленного
 деления
 * @param value_2l делитель
 * @param remainder предварительно рассчитанный остаток от целочисленного
 * деления
 * @return int
 */
int s21_div_calc_fractional(s21_big_decimal* res, s21_big_decimal value_2l,
                            s21_big_decimal* remainder) {
  int power = 0;
  s21_big_decimal number = *res;

  s21_big_decimal tmp;
  s21_big_decimal tmp_remainder = *remainder;

  // Производим расчеты пока остаток не будет полностью равен нулю или пока
  // степень не станет максимально допустимой (28)
  while ((!s21_is_empty_big_decimal(remainder)) && power < 28) {
    // Сохраняем значения полученных числа и остатка перед дальнейшей
    // итерацией
    // расчетов Чтобы вернуть эти значения в случае переполнения
    s21_big_decimal number_stored = number;
    s21_big_decimal remainder_stored = tmp_remainder;

    s21_big_mul_ten(&number);
    s21_big_mul_ten(&tmp_remainder);
    tmp = s21_big_binary_division(tmp_remainder, value_2l, &tmp_remainder);
    s21_big_add(number, tmp, &number);

    // Возвращаем предварительно сохраненные число и остаток, если произошло
    // переполнение при расчете
    if (!s21_is_correct_decimal(number)) {
      number = number_stored;
      tmp_remainder = remainder_stored;
      break;
    }

    ++power;
  }

  *res = number;
  *remainder = tmp_remainder;

  return power;
}

int s21_is_correct_decimal(s21_big_decimal big_decimal) {
  s21_decimal decimal_for_check = {{big_decimal.bits[0], big_decimal.bits[1],
                                    big_decimal.bits[2], big_decimal.bits[3]}};

  return s21_is_decimal_correct(decimal_for_check);
}

int s21_is_empty_big_decimal(const s21_big_decimal* value) {
  int flag = 1;
  for (int i = 0; i < 6; i++)
    if (value->bits[i] != 0) {
      flag = 0;
      break;
    }
  return flag;
}

s21_big_decimal s21_big_binary_division(s21_big_decimal decimal_1,
                                        s21_big_decimal decimal_2,
                                        s21_big_decimal* remains) {
  s21_big_decimal neg_zero;
  s21_big_decimal partial_remainder;
  s21_big_decimal result;
  s21_big_decimal quotient;

  s21_reset_big_dec(&neg_zero);
  s21_reset_big_dec(&partial_remainder);
  s21_reset_big_dec(&result);
  s21_reset_big_dec(&quotient);

  s21_set_bit_big_dec(&neg_zero, BIT_SIGN);

  if (s21_big_dec_is_less(decimal_1, decimal_2)) {
    partial_remainder = decimal_1;
  } else {
    int left1 = s21_big_dec_get_not_zero_bit_left(decimal_1);
    int left2 = s21_big_dec_get_not_zero_bit_left(decimal_2);
    int shift = left1 - left2;

    s21_big_decimal shifted_divisor = decimal_2;
    for (int i = 0; i < shift; i++) {
      s21_big_left_shift(&shifted_divisor);
    }

    s21_big_decimal dividend = s21_big_dec_abs(decimal_1);

    int need_sub = 1;
    while (shift >= 0) {
      if (need_sub == 1) {
        s21_big_sub(dividend, shifted_divisor, &partial_remainder);
      } else {
        s21_big_add(dividend, shifted_divisor, &partial_remainder);
      }
      s21_big_left_shift(&quotient);

      if (s21_is_set_bit_big_dec(&partial_remainder, BIG_DEC_BIT_SIGN) == 0) {
        s21_set_bit_big_dec(&quotient, 0);
      }
      dividend = partial_remainder;
      s21_big_left_shift(&dividend);
      if (s21_is_set_bit_big_dec(&dividend, BIG_DEC_BIT_SIGN) == 0) {
        need_sub = 1;
      } else {
        need_sub = 0;
      }
      --shift;
    }
    if (s21_is_set_bit_big_dec(&partial_remainder, BIG_DEC_BIT_SIGN)) {
      s21_big_add(partial_remainder, shifted_divisor, &partial_remainder);
    }

    partial_remainder =
        s21_big_decimal_shift_right(partial_remainder, left1 - left2);
  }

  result = quotient;
  if (remains != NULL) {
    *remains = partial_remainder;
  }
  return result;
}

s21_big_decimal s21_big_decimal_shift_right_one(s21_big_decimal decimal) {
  s21_big_decimal result;
  s21_reset_big_dec(&result);

  int b6 = s21_is_set_bit_int(&(decimal.bits[6]), 0);
  unsigned int result6 = decimal.bits[6];
  result6 = result6 >> 1;
  result.bits[6] = result.bits[6] >> 1;

  int b5 = s21_is_set_bit_int(&(decimal.bits[5]), 0);
  unsigned int result5 = decimal.bits[5];
  result5 = result5 >> 1;
  result.bits[5] = result.bits[5] >> 1;

  int b4 = s21_is_set_bit_int(&(decimal.bits[4]), 0);
  unsigned int result4 = decimal.bits[4];
  result4 = result4 >> 1;
  result.bits[4] = result4;

  int b3 = s21_is_set_bit_int(&(decimal.bits[3]), 0);
  unsigned int result3 = decimal.bits[3];
  result3 = result3 >> 1;
  result.bits[3] = result3;

  int b2 = s21_is_set_bit_int(&(decimal.bits[2]), 0);
  unsigned int result2 = decimal.bits[2];
  result2 = result2 >> 1;
  result.bits[2] = result2;

  int b1 = s21_is_set_bit_int(&(decimal.bits[1]), 0);
  unsigned int result1 = decimal.bits[1];
  result1 = result1 >> 1;
  result.bits[1] = result1;

  unsigned int result0 = decimal.bits[0];
  result0 = result0 >> 1;
  result.bits[0] = result0;

  if (b6) {
    s21_set_bit_int(&(result.bits[5]), 31);
  }

  if (b5) {
    s21_set_bit_int(&(result.bits[4]), 31);
  }

  if (b4) {
    s21_set_bit_int(&(result.bits[3]), 31);
  }

  if (b3) {
    s21_set_bit_int(&(result.bits[2]), 31);
  }

  if (b2) {
    s21_set_bit_int(&(result.bits[1]), 31);
  }

  if (b1) {
    s21_set_bit_int(&(result.bits[0]), 31);
  }

  return result;
}

s21_big_decimal s21_big_decimal_shift_right(s21_big_decimal decimal,
                                            int shift) {
  s21_big_decimal result = decimal;
  while (shift > 0) {
    // [3] может быть
    int b1 = s21_is_set_bit_int(&(result.bits[4]), 0);
    result = s21_big_decimal_shift_right_one(result);
    if (b1) {
      s21_set_bit_int(&(result.bits[3]), 127);
    }
    --shift;
  }

  return result;
}