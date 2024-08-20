#include "s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  *dst = 0.0;

  double tmp = 0.0;

  int sign = s21_check_sign(&src);
  int scale = s21_get_scale(&src);

  for (int i = 0; i < NUMBER_SIZE; i++) {
    if (s21_is_set_bit_dec(&src, i) != 0) {
      tmp += pow(2.0, i);
    }
  }

  double powerten = pow(10, scale);
  tmp /= powerten;

  if (sign == S21_NEGATIVE) {
    tmp *= -1.0;
  }

  *dst = (float)tmp;

  return 0;
}