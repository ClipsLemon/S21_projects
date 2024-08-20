#include "s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int code = 0;

  s21_big_decimal big_value_1 = s21_from_dec_to_big_dec(value_1);
  s21_big_decimal big_value_2 = s21_from_dec_to_big_dec(value_2);
  s21_big_decimal big_result;

  s21_big_mul(big_value_1, big_value_2, &big_result);

  if (s21_check_sign(&value_1) + s21_check_sign(&value_2) == 1)
    s21_set_bit_big_dec(&big_result, BIG_DEC_BIT_SIGN);
  else
    s21_reset_bit_big_dec(&big_result, BIG_DEC_BIT_SIGN);
  code = s21_from_big_dec_to_dec(big_result, result);
  return code;
}

void s21_big_mul(s21_big_decimal value_1, s21_big_decimal value_2,
                 s21_big_decimal *result) {
  int len1 = BIG_DEC_NUMBER_SIZE, len2 = BIG_DEC_NUMBER_SIZE;

  while (len1 >= 0 && !s21_is_set_bit_big_dec(&value_1, len1 - 1)) len1--;
  while (len2 >= 0 && !s21_is_set_bit_big_dec(&value_2, len2 - 1)) len2--;

  s21_reset_big_dec(result);

  if (len1 >= len2) {
    for (int i = 0; i < len2; i++) {
      if (s21_is_set_bit_big_dec(&value_2, i))
        s21_big_add(*result, value_1, result);
      s21_big_left_shift(&value_1);
    }
  } else {
    for (int i = 0; i < len1; i++) {
      if (s21_is_set_bit_big_dec(&value_1, i))
        s21_big_add(*result, value_2, result);
      s21_big_left_shift(&value_2);
    }
  }
  s21_set_scale_big_dec(result, s21_get_scale_big_dec(&value_1) +
                                    s21_get_scale_big_dec(&value_2));
}