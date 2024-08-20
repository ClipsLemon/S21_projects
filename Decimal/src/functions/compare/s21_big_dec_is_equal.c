#include "s21_decimal.h"

int s21_big_dec_is_equal(s21_big_decimal first, s21_big_decimal second) {
  int answer = TRUE;
  s21_big_decimal zero;
  s21_reset_big_dec(&zero);

  if (s21_check_sign_big_dec(&first) == s21_check_sign_big_dec(&second)) {
    if (s21_get_scale_big_dec(&first) != s21_get_scale_big_dec(&second))
      // производится выравнивание, чтобы избежать сравнения через степень
      s21_big_dec_arg_aligment(&first, &second);
    for (int i = 0; i < BIG_DEC_NUMBER_SIZE; i++) {
      if (s21_is_set_bit_big_dec(&first, i) !=
          s21_is_set_bit_big_dec(&second, i)) {
        answer = FALSE;
        break;
      }
    }
  } else if (!(s21_big_dec_is_equal(s21_big_dec_abs(first), zero) == 1 &&
               s21_big_dec_is_equal(s21_big_dec_abs(second), zero))) {
    answer = FALSE;
  }

  return answer;
}