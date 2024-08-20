#include "s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int flag = 0;

  if (!dst) {
    flag = 1;
  } else {
    *dst = 0;
    s21_decimal buf;
    s21_reset_dec(&buf);

    s21_truncate(src, &buf);

    if (s21_is_less(buf, s21_decimal_get_int_min())) {
      flag = 1;
    } else if (s21_is_greater(buf, s21_decimal_get_int_max())) {
      flag = 1;
    } else {
      // s21_truncate(src, &buf);
      long int tmp = 0;
      int sign = s21_check_sign(&src);

      for (int i = 0; i < NUMBER_SIZE; i++) {
        if (s21_is_set_bit_dec(&buf, i) != 0) {
          tmp += pow(2, i);
        }
      }

      if (sign == S21_NEGATIVE) {
        tmp *= -1;
      }

      *dst = (int)tmp;
    }
  }
  return flag;
}