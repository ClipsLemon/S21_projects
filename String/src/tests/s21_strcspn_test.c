#include "s21_tests.h"

START_TEST(s21_strcspn_test) {
  char str1[] = "0123456789";
  char str2[] = "9876";
  char str3[] = "LOST: 4-8-15-16-23-42";
  char str4[] = "1234567890";
  char str5[] = "0/";
  char str6[] = "%%\\#";
  char str7[] = " ";
  char str8[] = "1234567890";
  ck_assert_uint_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
  ck_assert_uint_eq(s21_strcspn(str3, str4), strcspn(str3, str4));
  ck_assert_uint_eq(s21_strcspn(str3, str5), strcspn(str3, str5));
  ck_assert_uint_eq(s21_strcspn(str3, str6), strcspn(str3, str6));
  ck_assert_uint_eq(s21_strcspn(str3, str7), strcspn(str3, str7));
  ck_assert_uint_eq(s21_strcspn(str4, str8), strcspn(str4, str8));
  ck_assert_uint_eq(s21_strcspn(str2, str7), strcspn(str2, str7));
}
END_TEST

Suite *strcspn_test() {
  Suite *suite = suite_create("s21_strcspn_test");
  TCase *test_cases = tcase_create("s21_strcspn_test");

  tcase_add_test(test_cases, s21_strcspn_test);

  suite_add_tcase(suite, test_cases);

  return suite;
}