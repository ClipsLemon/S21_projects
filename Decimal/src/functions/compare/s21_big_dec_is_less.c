
#include "s21_decimal.h"

/**
 * @brief Функция сравнения двух чисел относительно первого аргумента
 * Алгоритм:
 * 1. Провести проверку знаков.
 * 2. Выравнять оба числа (см. описание функции s21_big_argument_aligment)
 * 3. После выравнивания побитово сравнить оба числа. Идет от старшего к
 * младшему биту.
 *
 * @param first
 * @param second
 * @return
 * 1 - TRUE
 * 0 - FALSE
 */
int s21_big_dec_is_less(s21_big_decimal first, s21_big_decimal second) {
  int is_less = TRUE;
  // проверка на знак, оба имеют одинаковый знак
  // по умолчанию алгоритм работает под положительные числа
  // потом надо перевернуть ответ, если они оба отрицательные
  // if (s21_check_sign_big_dec(&second) == s21_check_sign_big_dec(&first)) {
  s21_big_dec_arg_aligment(&first, &second);
  for (int i = BIG_DEC_NUMBER_SIZE - 1; i >= 0; i--) {
    if (s21_is_set_bit_big_dec(&second, i) >
        s21_is_set_bit_big_dec(&first, i)) {
      is_less = TRUE;
      break;
    } else if (s21_is_set_bit_big_dec(&second, i) <
               s21_is_set_bit_big_dec(&first, i)) {
      is_less = FALSE;
      break;
    } else if (i == 0) {
      is_less = FALSE;
    }
  }
  // если первый отрицательный а второй положительный
  // } else if (s21_check_sign_big_dec(&first) == 1 &&
  // s21_check_sign_big_dec(&second) == 0)
  // {
  //   is_less = TRUE;
  //   // если первый положительный а второй отрицательный
  // } else if (s21_check_sign_big_dec(&first) == 0 &&
  // s21_check_sign_big_dec(&second) == 1)
  // {
  //   is_less = FALSE;
  // }
  // // если оба отрицательные, то результат инвертируем
  // if (s21_check_sign_big_dec(&first) == 1 && s21_check_sign_big_dec(&second)
  // == 1) {
  //   if (is_less == TRUE)
  //     is_less = FALSE;
  //   else
  //     is_less = TRUE;
  // }

  return is_less;
}
