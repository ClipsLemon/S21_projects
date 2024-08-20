#include "s21_tests.h"

START_TEST(s21_strstr_test) {
  char str1[] = "The avocado fruit is a climacteric, single-seeded berry$//@";
  char str2[] = "  /213\\/\"";
  char substr1[] = "The";
  char substr2[] = "$//@";
  char substr3[] = " is a ";
  ck_assert_uint_eq((uintmax_t)strstr(str1, str2),
                    (uintmax_t)s21_strstr(str1, str2));
  ck_assert_str_eq(strstr(str1, substr1), s21_strstr(str1, substr1));
  ck_assert_str_eq(strstr(str1, substr2), s21_strstr(str1, substr2));
  ck_assert_str_eq(strstr(str1, substr3), s21_strstr(str1, substr3));
}
END_TEST

Suite *strstr_test() {
  Suite *suite = suite_create("s21_strstr_test");
  TCase *test_cases = tcase_create("s21_strstr_test");

  tcase_add_test(test_cases, s21_strstr_test);

  suite_add_tcase(suite, test_cases);

  return suite;
}