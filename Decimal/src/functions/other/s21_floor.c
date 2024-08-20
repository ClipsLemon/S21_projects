#include "s21_decimal.h"

/*
Здесь будет находиться функция округления до ближайшего наименьшего числа.
Правила округления:
    если число отрицательно и есть хоть какая нибудь дробь, то
число округляется вниз;
    если число положительное и дробь не равна 0, то число округляется вниз
Алгоритм следующий:
 1. Функция s21_truncate отбрасывает дробь в числе
 2. truncate оставляет только целую часть числа путем бинарного деления
 2. Производится анализ числа и соответствующее округление
*/
int s21_floor(s21_decimal value, s21_decimal *result) {
  int code = S21_OTHER_OK;
  if (!result) {
    code = S21_OTHER_ERROR;
  } else if (!s21_is_decimal_correct(value)) {
    code = S21_OTHER_ERROR;
  } else {
    s21_decimal integer_part;
    s21_decimal fractional_part;
    s21_decimal zero;
    s21_decimal one;

    s21_reset_dec(&integer_part);
    s21_reset_dec(&fractional_part);
    s21_reset_dec(&zero);
    s21_reset_dec(&one);

    one.bits[0] = 1;
    // если число имеет степень, проводим обрезку
    if (s21_get_scale(&value)) {
      // берем целую часть, не смотрим на знак
      if (!s21_truncate(s21_abs_decimal(value), &integer_part)) {
        // берем дробную часть
        s21_sub(s21_abs_decimal(value), integer_part, &fractional_part);

        // если дробная часть есть и число отрицательное, то увеличиваем модуль
        if (s21_is_not_equal(fractional_part, zero) && s21_check_sign(&value)) {
          s21_add(integer_part, one, &integer_part);
        }
        // во всех остальных случаях ничего не делаем
        *result = integer_part;
        if (s21_check_sign(&value)) {
          s21_set_bit(result, BIT_SIGN);
        }
      } else {
        code = S21_OTHER_ERROR;
      }

    } else {
      *result = value;
    }
  }

  return code;
}