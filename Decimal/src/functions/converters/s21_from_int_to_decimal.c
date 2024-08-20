#include "s21_decimal.h"

s21_decimal s21_decimal_set_zero(void) {
  s21_decimal result;
  result.bits[0] = 0;
  result.bits[1] = 0;
  result.bits[2] = 0;
  result.bits[3] = 0;
  return result;
}

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int flag = 0;

  if (!dst) {
    flag = 1;
  } else {
    *dst = s21_decimal_set_zero();
    // int sign;

    if (src < 0) {
      s21_set_bit(dst, BIT_SIGN);
      if (src != INT_MIN) {
        src = -src;
      }
    }
    dst->bits[0] = src;
  }

  return flag;
}