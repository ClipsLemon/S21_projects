#include "s21_decimal.h"

// возвращает модуль числа
s21_decimal s21_abs_decimal(s21_decimal decimal) {
  s21_reset_bit(&decimal, BIT_SIGN);
  return decimal;
}

s21_big_decimal s21_big_dec_abs(s21_big_decimal big_decimal) {
  s21_reset_bit_big_dec(&big_decimal, BIG_DEC_BIT_SIGN);
  return big_decimal;
}

void s21_set_bit(s21_decimal *ptr_dec_num, int index) {
  int indexRow = s21_get_row(index);
  int indexCol = s21_get_col(index);
  ((*ptr_dec_num).bits[indexRow] |= (1 << indexCol));
}
void s21_set_bit_big_dec(s21_big_decimal *ptr_dec_num, int index) {
  int indexRow = s21_get_row(index);
  int indexCol = s21_get_col(index);
  ((*ptr_dec_num).bits[indexRow] |= (1 << indexCol));
}

void s21_inverse_bit(s21_decimal *ptr_dec_num, int index) {
  int indexRow = s21_get_row(index);
  int indexCol = s21_get_col(index);
  ((*ptr_dec_num).bits[indexRow] ^= (1 << indexCol));
}

void s21_reset_bit(s21_decimal *ptr_dec_num, int index) {
  int indexRow = s21_get_row(index);
  int indexCol = s21_get_col(index);
  ((*ptr_dec_num).bits[indexRow] &= ~(1 << indexCol));
}
void s21_reset_bit_big_dec(s21_big_decimal *ptr_dec_num, int index) {
  int indexRow = s21_get_row(index);
  int indexCol = s21_get_col(index);
  ((*ptr_dec_num).bits[indexRow] &= ~(1 << indexCol));
}

int s21_is_set_bit_dec(s21_decimal *ptr_dec_num, int index) {
  int indexRow = s21_get_row(index);
  int indexCol = s21_get_col(index);
  return (((*ptr_dec_num).bits[indexRow] & (1 << indexCol)) != 0);
}

int s21_is_set_bit_big_dec(s21_big_decimal *ptr_dec_num, int index) {
  int indexRow = s21_get_row(index);
  int indexCol = s21_get_col(index);
  return (((*ptr_dec_num).bits[indexRow] & (1 << indexCol)) != 0);
}

void s21_set_bit_int(int *ptr_num, int index) { ((*ptr_num) |= (1 << index)); }

int s21_is_set_bit_int(int *ptr_num, int index) {
  return (((*ptr_num) & (1 << index)) != 0);
}

int s21_check_sign(s21_decimal *num_ptr) {
  return s21_is_set_bit_dec(num_ptr, BIT_SIGN);
}
int s21_check_sign_big_dec(s21_big_decimal *num_ptr) {
  return s21_is_set_bit_big_dec(num_ptr, BIG_DEC_BIT_SIGN);
}

int s21_get_col(int index) { return index % BYTE_SIZE; }
int s21_get_row(int index) { return index / BYTE_SIZE; }

// MIN_INT = -2147483648
s21_decimal s21_decimal_get_int_min() {
  s21_decimal result = {{0x80000000, 0x0, 0x0, 0x80000000}};
  return result;
}

// MAX_INT = 2147483647
s21_decimal s21_decimal_get_int_max() {
  s21_decimal result = {{0x7FFFFFFF, 0x0, 0x0, 0x0}};
  return result;
}

s21_decimal s21_decimal_get_inf(void) {
  s21_decimal result = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x7FFFFFFF}};

  return result;
}

int s21_is_empty_decimal(const s21_decimal *value) {
  return value->bits[0] == 0 && value->bits[1] == 0 && value->bits[2] == 0;
}

/**
 * @brief Функция проверяет числ decimal на корректность
 * Число считается некорректным, если выполняется хотя одного из условий:
 * 1) в bits[3] биты от 0 до 15 не равны нулю.
 * 2) в bits[3] степень < 0 или > 28.
 * 3) в bits[3] биты с 24 по 30 не равны нулю.
 *
 * @param decimal децимал число
 * @return int 1 - TRUE, 0 - FALSE
 */
int s21_is_decimal_correct(s21_decimal decimal) {
  int code = TRUE;
  // проверяем биты с 0 по 15
  for (int i = 0; i <= 15; i++) {
    if (s21_is_set_bit_dec(&decimal, i + NUMBER_SIZE)) {
      code = FALSE;
      break;
    }
  }
  // проверяем биты с 24 по 30
  if (code) {
    for (int i = 24; i <= 30; i++) {
      if (s21_is_set_bit_dec(&decimal, i + NUMBER_SIZE)) {
        code = FALSE;
        break;
      }
    }
  }
  if (code) {
    int scale = s21_get_scale(&decimal);
    if (scale < 0 || scale > 28) {
      code = FALSE;
    }
  }
  return code;
}

int s21_align_scale(s21_big_decimal *value_1, s21_big_decimal *value_2) {
  int first_scale = s21_get_scale_big_dec(value_1);
  int second_scale = s21_get_scale_big_dec(value_2);
  int temp_sc = first_scale;
  int scale_diff = 0;
  if ((scale_diff = first_scale - second_scale) != 0) {
    s21_big_decimal *arg = S21_NULL;
    s21_set_scale_big_dec(value_1, 0);
    s21_set_scale_big_dec(value_2, 0);

    if (scale_diff > 0) {
      arg = value_2;
      temp_sc = first_scale;
    } else {
      arg = value_1;
      scale_diff = -scale_diff;
      temp_sc = second_scale;
    }

    for (; scale_diff > 0; scale_diff--) {
      s21_big_mul_ten(arg);
    }
    s21_set_scale_big_dec(value_1, temp_sc);
    s21_set_scale_big_dec(value_2, temp_sc);
  }
  return temp_sc;
}

void s21_big_mul_ten(s21_big_decimal *val) {
  s21_big_decimal temp;
  s21_reset_big_dec(&temp);
  s21_big_left_shift(val);
  s21_big_add(temp, *val, &temp);
  s21_big_left_shift(val);
  s21_big_left_shift(val);
  s21_big_add(*val, temp, val);
}

void s21_mul_ten(s21_decimal *val) {
  s21_decimal temp;
  s21_reset_dec(&temp);
  s21_left_shift(val);
  s21_add(temp, *val, &temp);
  s21_left_shift(val);
  s21_left_shift(val);
  s21_add(*val, temp, val);
}

int s21_big_left_shift(s21_big_decimal *val) {
  int flag = 0;
  if (!s21_is_set_bit_big_dec(val, BIG_DEC_NUMBER_SIZE - 1)) {
    val->bits[5] = (val->bits[5] << 1);
    if (s21_is_set_bit_big_dec(val, 159)) s21_set_bit_big_dec(val, 160);
    val->bits[4] = (val->bits[4] << 1);
    if (s21_is_set_bit_big_dec(val, 127)) s21_set_bit_big_dec(val, 128);
    val->bits[3] = (val->bits[3] << 1);
    if (s21_is_set_bit_big_dec(val, 95)) s21_set_bit_big_dec(val, 96);
    val->bits[2] = (val->bits[2] << 1);
    if (s21_is_set_bit_big_dec(val, 63)) s21_set_bit_big_dec(val, 64);
    val->bits[1] = (val->bits[1] << 1);
    if (s21_is_set_bit_big_dec(val, 31)) s21_set_bit_big_dec(val, 32);
    val->bits[0] = (val->bits[0] << 1);
  } else
    flag = 1;
  return flag;
}

int s21_left_shift(s21_decimal *val) {
  int flag = 0;
  if (!s21_is_set_bit_dec(val, 95)) {
    val->bits[2] = (val->bits[2] << 1);
    if (s21_is_set_bit_dec(val, 63)) s21_set_bit(val, 64);
    val->bits[1] = (val->bits[1] << 1);
    if (s21_is_set_bit_dec(val, 31)) s21_set_bit(val, 32);
    val->bits[0] = (val->bits[0] << 1);
  } else
    flag = 1;
  return flag;
}

// Установить значение показателя в переменной decimal
void s21_set_scale(s21_decimal *number, int point) {
  if (point > 28) point = 28;
  for (int i = 0; i < 5; i++) {
    s21_reset_bit(number, SCALE_START + i);
  }
  // максимальное кол-во знаков - 28, поэтому 5 бит
  for (int i = 0; i < 5; i++) {
    // если бит задан, задаем его же в decimal
    if ((point & (1 << i)) != 0) {
      s21_set_bit(number, SCALE_START + i);
    }
  }
}
void s21_set_scale_big_dec(s21_big_decimal *number, int point) {
  // if (point > 28) point = 28;
  for (int i = 0; i < 8; i++) {
    s21_reset_bit_big_dec(number, BIG_DEC_SCALE_START + i);
  }
  // максимальное кол-во знаков - 28, поэтому 5 бит
  for (int i = 0; i < 8; i++) {
    // если бит задан, задаем его же в decimal
    if ((point & (1 << i)) != 0) {
      s21_set_bit_big_dec(number, BIG_DEC_SCALE_START + i);
    }
  }
}

// Получить значение показателя в переменной decimal
int s21_get_scale(s21_decimal *number) {
  int scale = 0;
  for (int i = SCALE_START; i <= SCALE_END; i++) {
    if (s21_is_set_bit_dec(number, i)) {
      s21_set_bit_int(&scale, i - SCALE_START);
    }
  }
  return scale;
}

int s21_get_scale_big_dec(s21_big_decimal *number) {
  int scale = 0;
  for (int i = BIG_DEC_SCALE_START; i <= BIG_DEC_SCALE_END; i++) {
    if (s21_is_set_bit_big_dec(number, i)) {
      s21_set_bit_int(&scale, i - BIG_DEC_SCALE_START);
    }
  }
  return scale;
}

// Обнуление decimal переменной
void s21_reset_dec(s21_decimal *val) {
  val->bits[0] = 0;
  val->bits[1] = 0;
  val->bits[2] = 0;
  val->bits[3] = 0;
}

void s21_reset_big_dec(s21_big_decimal *val) {
  val->bits[0] = 0;
  val->bits[1] = 0;
  val->bits[2] = 0;
  val->bits[3] = 0;
  val->bits[4] = 0;
  val->bits[5] = 0;
  val->bits[6] = 0;
}

s21_big_decimal s21_from_dec_to_big_dec(s21_decimal decimal) {
  s21_big_decimal big_decimal;
  s21_reset_big_dec(&big_decimal);
  big_decimal.bits[0] = decimal.bits[0];
  big_decimal.bits[1] = decimal.bits[1];
  big_decimal.bits[2] = decimal.bits[2];

  big_decimal.bits[6] = decimal.bits[3];

  return big_decimal;
}

/**
 * @brief Функция находит максимальный установленный бит в части числа (191 - 0
 * биты) биг децимала
 *
 *
 * @param decimal
 * @return int - позиция максимального бита
 */
int s21_big_dec_get_not_zero_bit_left(s21_big_decimal decimal) {
  int result = 0;
  for (int i = BIG_DEC_NUMBER_SIZE - 1; i >= 0; i--) {
    if (s21_is_set_bit_big_dec(&decimal, i)) {
      result = i;
      break;
    }
  }
  return result;
}

void s21_bank_round(s21_big_decimal *value, s21_big_decimal *fractional) {
  s21_big_decimal one = {{1, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal five = {{5, 0, 0, 0, 0, 0, 0}};
  s21_set_scale_big_dec(&five, 1);
  s21_set_scale_big_dec(&one, s21_get_scale_big_dec(value));
  if (s21_check_sign_big_dec(value))
    s21_set_bit_big_dec(&one, BIG_DEC_BIT_SIGN);
  if (s21_big_dec_is_greater(*fractional, five))
    // если остаток больше 0.5, то округляем вверх (12.6 -> 13)
    s21_big_add(*value, one, value);
  else if (s21_big_dec_is_equal(*fractional, five) &&
           s21_is_set_bit_big_dec(value, 0)) {
    // если остаток равен 0.5, то используем банковское округление (12.5 -> 12,
    // но 13.5 -> 14)
    // если число нечетное
    // increment_mantissa_Long_decimal(value);
    s21_big_add(*value, one, value);
  }
  // else - если остаток меньше 0.5, то оставляем число как есть (12.4 -> 12)
}

// Функция делит мантиссу на 10 и декрементирует экспоненту,
// причем *value будет с правильными экспонентой и знаком, а
// остаток будет положительным и с 0 экспонентой
s21_big_decimal convert_to_down_exponent(s21_big_decimal *value) {
  s21_big_decimal fractional = {{0, 0, 0, 0, 0, 0, 0}};
  int sign = s21_check_sign_big_dec(value);
  int exponent = s21_get_scale_big_dec(value);
  value->bits[6] = 0;

  s21_big_decimal dividor = {{10, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal integer_part = {{0, 0, 0, 0, 0, 0, 0}};
  integer_part = s21_big_binary_division(*value, dividor, NULL);
  s21_big_decimal temp_integer = integer_part;
  s21_big_mul_ten(&temp_integer);
  s21_big_sub(*value, temp_integer, &fractional);
  // bank_round(&integer_part, &fractional);
  *value = integer_part;

  s21_set_scale_big_dec(&fractional, exponent);
  // восстанавливаем знак для целой части
  if (sign) s21_set_bit_big_dec(value, BIG_DEC_BIT_SIGN);
  // уменьшаем исходную экспоненту на 1 в целой части
  s21_set_scale_big_dec(value, exponent - 1);
  return fractional;
}

/**
 * @brief Функция переводит из биг децимала в децимал.
 * Функция так же проверяет на вместимость в обычный децимал числа из биг
 * децимала.
 * Проверка проходит при помощи поиска крайнего бита в числовой части биг
 * децимала
 *
 * @param big_decimal
 * @param decimal
 * @return 0 - OK, ошибок при конвертации не было;
 *         1 - ERROR, возникли ошибки, биг децимал больше децимал;
 */
int s21_from_big_dec_to_dec(s21_big_decimal big_decimal, s21_decimal *decimal) {
  int code = 0;
  s21_reset_dec(decimal);
  s21_big_decimal temp_value = big_decimal;
  s21_big_decimal fractional;  // возможный остаток от деления при попытке
                               // сделать число валидным
  s21_reset_big_dec(&fractional);
  s21_big_decimal temp_fractional;
  s21_reset_big_dec(&temp_fractional);

  int exponent = s21_get_scale_big_dec(&temp_value);
  // int exponent_fractional = 0;
  // если при умножении сумма экспонент больше MAX_EXPONENT либо после других
  // операций в расширенной части установлены биты и экспонента != 0, то
  // преобразуем число в число равное по значению, но с меньшей экспонентой,
  // пока оно не станет валидным либо экспонента не станет == 0

  while ((exponent > 28) ||
         ((temp_value.bits[5] || temp_value.bits[4] || temp_value.bits[3]) &&
          exponent != 0)) {
    temp_fractional = convert_to_down_exponent(&temp_value);
    s21_big_add(fractional, temp_fractional, &fractional);
    // в случае нескольких преобразований, получаемые
    // остатки суммируются т.е. округление не по
    // послeдней цифре числа, а по всем отброшенным,
    // т.е. например не по 0.3, а по 0.325
    exponent = s21_get_scale_big_dec(&temp_value);
  }

  if (!s21_is_empty_big_decimal(&fractional)) {
    s21_big_decimal one = {{1, 0, 0, 0, 0, 0, 0}};
    s21_set_scale_big_dec(&one, 1);
    while (s21_big_dec_is_less(fractional, one))
      s21_set_scale_big_dec(&fractional,
                            s21_get_scale_big_dec(&fractional) - 1);
    // если есть дробная часть
    // получаем дробную часть в виде
    // 0.123, а не 0.000123
    // используем банковское округление
    s21_bank_round(&temp_value, &fractional);
  }
  if (temp_value.bits[5] == 0 && temp_value.bits[4] == 0 &&
      temp_value.bits[3] == 0) {
    // если удалось сделать число валидным
    // сохраняем мантиссу
    for (int part = 0; part < 3; ++part)
      decimal->bits[part] = temp_value.bits[part];
    // подготавливаем часть со знаком и экспонентой путем
    // очищения этой части
    s21_set_scale(decimal, s21_get_scale_big_dec(&temp_value));
    if (s21_check_sign_big_dec(&big_decimal)) s21_set_bit(decimal, BIT_SIGN);
  } else {
    code = s21_check_sign_big_dec(&big_decimal) == 0 ? 1 : 2;
  }
  return code;
}
