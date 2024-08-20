#include "s21_decimal.h"

// /**
//  * @brief Функция осуществляет выравнивание двух чисел с разным положением
//  * запятой. Алгоритм:
//  * 1. Определить число с наименьшей степенью
//  * 2. Определить scale_diff - модуль разницы степеней чисел
//  * 3. Умножить число с наименьшей степенью на 10^scale_diff
//  *
//  * @param first
//  * @param second
//  */
void s21_big_dec_arg_aligment(s21_big_decimal *first, s21_big_decimal *second) {
  s21_big_decimal *aligment_arg = S21_NULL;

  /* степень.Стоит подумать над оптимизацией, выделять целый децимал
   * нецелесообразно */

  s21_big_decimal scale;
  s21_reset_big_dec(&scale);
  scale.bits[0] = 10;

  // аргумент разницы степеней
  int scale_diff = 0;

  // выравниваем тот аргумент, степень которого меньше
  if (s21_get_scale_big_dec(first) > s21_get_scale_big_dec(second)) {
    scale_diff = s21_get_scale_big_dec(first) - s21_get_scale_big_dec(second);
    aligment_arg = second;
  } else {
    scale_diff = s21_get_scale_big_dec(second) - s21_get_scale_big_dec(first);
    aligment_arg = first;
  }
  if (scale_diff) {
    for (int i = 0; i < scale_diff; i++) {
      s21_big_mul(*aligment_arg, scale, aligment_arg);
    }
  }
}

// /**
//  * @brief Функция сравнения двух чисел относительно первого аргумента
//  * Алгоритм:
//  * 1. Провести проверку знаков.
//  * 2. Выравнять оба числа (см. описание функции s21_big_argument_aligment)
//  * 3. После выравнивания побитово сравнить оба числа. Идет от старшего к
//  * младшему биту.
//  *
//  * @param first
//  * @param second
//  * @return
//  * 1 - TRUE
//  * 0 - FALSE
//  */
int s21_is_less(s21_decimal first, s21_decimal second) {
  s21_big_decimal big_first;
  s21_big_decimal big_second;
  s21_reset_big_dec(&big_first);
  s21_reset_big_dec(&big_second);

  big_first = s21_from_dec_to_big_dec(first);
  big_second = s21_from_dec_to_big_dec(second);
  int is_less = TRUE;
  // проверка на знак, оба имеют одинаковый знак
  // по умолчанию алгоритм работает под положительные числа
  // потом надо перевернуть ответ, если они оба отрицательные
  if (s21_check_sign_big_dec(&big_second) ==
      s21_check_sign_big_dec(&big_first)) {
    s21_big_dec_arg_aligment(&big_first, &big_second);
    big_first.bits[6] = first.bits[3];
    big_second.bits[6] = second.bits[3];

    for (int i = BIG_DEC_NUMBER_SIZE - 1; i >= 0; i--) {
      if (s21_is_set_bit_big_dec(&big_second, i) >
          s21_is_set_bit_big_dec(&big_first, i)) {
        is_less = TRUE;
        break;
      } else if (s21_is_set_bit_big_dec(&big_second, i) <
                 s21_is_set_bit_big_dec(&big_first, i)) {
        is_less = FALSE;
        break;
      } else if (i == 0) {
        is_less = FALSE;
      }
    }
    // если первый отрицательный а второй положительный
  } else if (s21_check_sign_big_dec(&big_first) == 1 &&
             s21_check_sign_big_dec(&big_second) == 0) {
    is_less = TRUE;
    // если первый положительный а второй отрицательный
  } else if (s21_check_sign_big_dec(&big_first) == 0 &&
             s21_check_sign_big_dec(&big_second) == 1) {
    is_less = FALSE;
  }
  // если оба отрицательные, то результат инвертируем и при этом они не равны
  if (s21_check_sign_big_dec(&big_first) == 1 &&
      s21_check_sign_big_dec(&big_second) == 1) {
    if (s21_big_dec_is_not_equal(big_first, big_second)) {
      if (is_less == TRUE)
        is_less = FALSE;
      else
        is_less = TRUE;
    }
  }

  return is_less;
}
