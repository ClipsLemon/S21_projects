#include "s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  int code = S21_OTHER_OK;
  if (!result) {
    code = S21_OTHER_ERROR;
  } else if (!s21_is_decimal_correct(value)) {
    code = S21_OTHER_ERROR;
  } else {
    *result = value;
    s21_inverse_bit(result, BIT_SIGN);
  }

  return code;
}