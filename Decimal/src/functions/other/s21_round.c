#include "s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  int code = S21_OTHER_OK;

  if (!result) {
    code = S21_OTHER_ERROR;
    // Проверяем, что value является корректными decimal
  } else if (!s21_is_decimal_correct(value)) {
    code = S21_OTHER_ERROR;
    // если модуль числа [0, 1)
  } else {
    s21_decimal integer_part;
    s21_decimal fractional_part;
    s21_decimal pattern;
    s21_decimal zero;

    s21_reset_dec(&integer_part);
    s21_reset_dec(&fractional_part);
    s21_reset_dec(&pattern);
    s21_reset_dec(&zero);

    pattern.bits[0] = 5;
    s21_set_scale(&pattern, 1);

    // берем возвращаемую целую часть
    if (!s21_truncate(s21_abs_decimal(value), &integer_part)) {
      s21_sub(s21_abs_decimal(value), integer_part, &fractional_part);
      s21_set_scale(&fractional_part, s21_get_scale(&value));

      // после того как дима добавил новое сложение, перестало адекватно
      // работать сравнение. Это из-за алгоритма выравнивания, который
      // использует сложение
      if (s21_is_greater_or_equal(fractional_part, pattern)) {
        s21_decimal one;
        s21_reset_dec(&one);
        one.bits[0] = 1;
        s21_add(integer_part, one, &integer_part);
      }
      *result = integer_part;
      if (s21_check_sign(&value)) {
        s21_set_bit(result, BIT_SIGN);
      }
    } else {
      code = S21_OTHER_ERROR;
    }

    // берем дробную часть для сравнения с 0,5
  }

  return code;
}