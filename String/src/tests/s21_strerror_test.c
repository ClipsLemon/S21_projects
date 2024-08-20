#include "s21_tests.h"

START_TEST(s21_strerror_test) {
  ck_assert_str_eq(strerror(-11), s21_strerror(-11));
  ck_assert_str_eq(strerror(-1), s21_strerror(-1));
  ck_assert_str_eq(strerror(0), s21_strerror(0));
  for (int i = 1; i < 100; i++) {
    ck_assert_str_eq(strerror(i), s21_strerror(i));
  }
  ck_assert_str_eq(strerror(106), s21_strerror(106));
  ck_assert_str_eq(strerror(134), s21_strerror(134));
  ck_assert_str_eq(strerror(12312423), s21_strerror(12312423));
  ck_assert_str_eq(strerror(-12312423), s21_strerror(-12312423));
}
END_TEST

Suite *strerror_test() {
  Suite *suite = suite_create("s21_strerror_test");
  TCase *test_cases = tcase_create("s21_strerror_test");

  tcase_add_test(test_cases, s21_strerror_test);

  suite_add_tcase(suite, test_cases);

  return suite;
}