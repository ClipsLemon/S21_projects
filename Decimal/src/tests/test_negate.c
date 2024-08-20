#include <check.h>
#include <limits.h>
#include <stdio.h>

#include "../s21_decimal.h"

static s21_decimal arr[] = {
    {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},  // 0
    {{0x00000001, 0x00000000, 0x00000000, 0x00000000}},  // 1
    {{0x00000001, 0x00000000, 0x00000000, 0x80000000}},  // -1
    {{0xCF5C048C, 0x004D2BEF, 0x00000000, 0x00070000}},  // 2172188218.2812812
    {{0xFEADBDA2, 0x000001FB, 0x00000000, 0x80060000}},  // -2181821.218210
    {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
      0x00000000}},  // 79228162514264337593543950335
    {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
      0x80000000}},  // -79228162514264337593543950335
    {{0x00000000, 0x00000000, 0x00000000, 0x00020000}},  // 0.00
    {{0x00000000, 0x00000000, 0x00000000, 0x80020000}},  // 0.00
    {{0x000F4240, 0x00000000, 0x00000000, 0x00020000}},  // 10000.00
    {{0x000F4240, 0x00000000, 0x00000000, 0x80020000}},  // -10000.00
    {{0x00000467, 0x0000007A, 0x00000000, 0x00040000}},  // 52398601.1239
    {{0x00000467, 0x0000007A, 0x00000000, 0x80000000}},  // -523986011239
    {{0x00000467, 0x0000007A, 0x00003215,
      0x00010000}},  // 23650570576955414727997.5
    {{0x00000467, 0x0000007A, 0x00205FF0,
      0x80020000}},  // -391386782621189641642978.31
    {{0x000F4240, 0x00002710, 0x00002710,
      0x80050000}},  // -1844674407800451901.20000
};

static s21_decimal result[] = {
    {{0x00000000, 0x00000000, 0x00000000, 0x80000000}},  // 0
    {{0x00000001, 0x00000000, 0x00000000, 0x80000000}},  //-1
    {{0x00000001, 0x00000000, 0x00000000, 0x00000000}},  // 1
    {{0xCF5C048C, 0x004D2BEF, 0x00000000, 0x80070000}},  //-2172188218.2812812
    {{0xFEADBDA2, 0x000001FB, 0x00000000, 0x00060000}},  // 2181821.218210
    {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
      0x80000000}},  //-79228162514264337593543950335
    {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
      0x00000000}},  // 79228162514264337593543950335
    {{0x00000000, 0x00000000, 0x00000000, 0x80020000}},  // 0.00
    {{0x00000000, 0x00000000, 0x00000000, 0x00020000}},  // 0.00
    {{0x000F4240, 0x00000000, 0x00000000, 0x80020000}},  //-10000.00
    {{0x000F4240, 0x00000000, 0x00000000, 0x00020000}},  // 10000.00
    {{0x00000467, 0x0000007A, 0x00000000, 0x80040000}},  //-52398601.1239
    {{0x00000467, 0x0000007A, 0x00000000, 0x00000000}},  // 523986011239
    {{0x00000467, 0x0000007A, 0x00003215,
      0x80010000}},  //-23650570576955414727997.5
    {{0x00000467, 0x0000007A, 0x00205FF0,
      0x00020000}},  // 391386782621189641642978.31
    {{0x000F4240, 0x00002710, 0x00002710,
      0x00050000}},  // 1844674407800451901.20000
};

START_TEST(test) {
  for (size_t i = 0; i < sizeof(arr) / sizeof(s21_decimal); ++i) {
    s21_decimal value = arr[i];
    s21_decimal tmp;
    int ret = s21_negate(value, &tmp);
    ck_assert_int_eq(result[i].bits[0], tmp.bits[0]);
    ck_assert_int_eq(result[i].bits[1], tmp.bits[1]);
    ck_assert_int_eq(result[i].bits[2], tmp.bits[2]);
    ck_assert_int_eq(result[i].bits[3], tmp.bits[3]);
    ck_assert_int_eq(ret, 0);
  }
}
END_TEST

START_TEST(error_test) {
  s21_decimal value1 = {{0, 0, 0, 0}};
  s21_set_bit_int(&(value1.bits[3]), 4);
  s21_decimal *tmp_1 = NULL;
  s21_decimal tmp_2;
  int ret1 = s21_negate(value1, tmp_1);
  int ret2 = s21_negate(value1, &tmp_2);

  ck_assert_int_eq(ret1, 1);
  ck_assert_int_eq(ret2, 1);
}
END_TEST

Suite *suite_negate(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_negate");
  tc = tcase_create("s21_negate");

  if (s != NULL && tc != NULL) {
    tcase_add_test(tc, test);
    tcase_add_test(tc, error_test);

    suite_add_tcase(s, tc);
  }

  return (s);
}
