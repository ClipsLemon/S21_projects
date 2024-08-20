#include "s21_decimal.h"

s21_big_decimal s21_big_decimal_to_pow(int scale) {
  s21_big_decimal result;
  s21_reset_big_dec(&result);
  result.bits[0] = 1;
  if (scale != 0) {
    for (int i = 0; i < scale; i++) {
      s21_big_mul_ten(&result);
    }
  }
  return result;
}

/**
 * @brief Возвращает целые цифры числа value.
 * Любые дробные цифры отбрасываются, включая конечные нули.
 *
 * 123.999 -> 123
 * 123.000 -> 123
 * 123 -> 123
 *
 * Для получения целой части выполняем деление 96-разрядного целого числа
 * (bits[0], bits[1], bits[2]) на 10 ^ n (где n - показатель степени decimal)
 * Используется именно бинарное деление целых чисел, а не деление decimal:
 * в бинарном виде: 123999 / 1000 = 123
 * в делении decimal: 123999 / 1000 = 123.999
 * Очевидно, что нам нужен 1й вариант
 *
 * Затем корректно выставляем знак, анализируя знак исходного числа
 *
 * @param value обрабатываемый decimal
 * @param result указатель на decimal, куда запишется результат выполнения
 * функции
 * @return int код ошибки:
 *      0 - OK
 *      1 - ошибка вычисления
 */
int s21_truncate(s21_decimal value, s21_decimal* result) {
  int code = S21_OTHER_OK;
  s21_decimal one;
  s21_decimal zero;
  s21_reset_dec(&one);
  s21_reset_dec(&zero);

  one.bits[0] = 1;

  if (!result) {
    code = S21_OTHER_ERROR;
    // Проверяем, что value является корректными decimal
  } else if (!s21_is_decimal_correct(value)) {
    code = S21_OTHER_ERROR;
    // если модуль числа [0, 1)
  } else if (s21_is_less(s21_abs_decimal(value), one)) {
    s21_reset_dec(result);
  } else if (s21_get_scale(&value) == 0) {
    *result = value;
  } else {
    // В остальных случаях производим расчет
    s21_reset_dec(result);

    s21_big_decimal tmp = s21_from_dec_to_big_dec(value);
    // зануляем все информационные биты
    tmp.bits[6] = 0;
    tmp = s21_big_binary_division(
        tmp, s21_big_decimal_to_pow(s21_get_scale(&value)), NULL);
    // если будут ошибки при конвертации
    if (s21_from_big_dec_to_dec(tmp, result)) {
      code = S21_OTHER_ERROR;
    }
  }
  if (!code) {
    if (s21_check_sign(&value) == S21_NEGATIVE) {
      s21_set_bit(result, BIT_SIGN);
    }
  }

  return code;
}
