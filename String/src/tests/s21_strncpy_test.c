#include "s21_tests.h"

START_TEST(s21_strncpy_test) {
  char str1[] = "simple string test";
  char dest1[19] = "";

  char str2[] = "test\0aaaaa";
  char dest2[12] = "1";

  char str3[] = "test ";
  char dest3[] = "crushcrush";

  ck_assert_str_eq(strncpy(dest1, str1, 18), s21_strncpy(dest1, str1, 18));
  ck_assert_str_eq(strncpy(dest2, str2, 6), s21_strncpy(dest2, str2, 6));
  ck_assert_str_eq(strncpy(dest3, str3, 10), s21_strncpy(dest3, str3, 10));
}
END_TEST

Suite *strncpy_test() {
  Suite *suite = suite_create("s21_strncpy_test");
  TCase *test_cases = tcase_create("s21_strncpy_test");

  tcase_add_test(test_cases, s21_strncpy_test);

  suite_add_tcase(suite, test_cases);

  return suite;
}