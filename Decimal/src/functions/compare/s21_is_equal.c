#include "s21_decimal.h"

int s21_is_equal(s21_decimal first, s21_decimal second) {
  s21_big_decimal big_first;
  s21_big_decimal big_second;
  s21_reset_big_dec(&big_first);
  s21_reset_big_dec(&big_second);

  big_first = s21_from_dec_to_big_dec(first);
  big_second = s21_from_dec_to_big_dec(second);

  int answer = s21_big_dec_is_equal(big_first, big_second);

  return answer;
}