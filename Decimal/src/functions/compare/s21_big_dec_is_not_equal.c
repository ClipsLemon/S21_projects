#include "s21_decimal.h"

int s21_big_dec_is_not_equal(s21_big_decimal first, s21_big_decimal second) {
  return !s21_big_dec_is_equal(first, second);
}