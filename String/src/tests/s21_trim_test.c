#include "s21_tests.h"

START_TEST(s21_trim_test) {
  char str1[] = "*/// simple string //*** *";
  char trim_s1[] = "*/ ";
  char trim_s2[] = "*/";
  char trim_s3[] = " ";
  char trim_s4[] = "\0";
  char res1[] = "simple string";
  char res2[] = " simple string //*** ";

  char *trim_res1 = (char *)s21_trim(str1, trim_s1);
  char *trim_res2 = (char *)s21_trim(str1, trim_s2);
  char *trim_res3 = (char *)s21_trim(str1, trim_s3);
  char *trim_res4 = (char *)s21_trim(str1, trim_s4);

  ck_assert_str_eq(trim_res1, res1);
  ck_assert_str_eq(trim_res2, res2);
  ck_assert_str_eq(trim_res3, str1);
  ck_assert_str_eq(trim_res4, str1);

  free(trim_res1);
  free(trim_res2);
  free(trim_res3);
  free(trim_res4);
  trim_res1 = S21_NULL;
  trim_res2 = S21_NULL;
  trim_res3 = S21_NULL;
  trim_res4 = S21_NULL;
}
END_TEST

Suite *trim_test() {
  Suite *suite = suite_create("s21_trim_test");
  TCase *test_cases = tcase_create("s21_trim_test");

  tcase_add_test(test_cases, s21_trim_test);

  suite_add_tcase(suite, test_cases);

  return suite;
}