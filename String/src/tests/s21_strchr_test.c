#include "s21_tests.h"

START_TEST(s21_strchr_test) {
  char str1[] = "The avocado fruit \0is a climacteric,$ single-seeded berry";
  char str2[] = "The avocado fruit is a climacteric, $single-seeded berry";
  char str3[] = "masdl:!@#!@MCZ@!#)(_)*@#";
  char symbl1 = '\0';
  char symbl2 = 'i';
  char symbl3 = 'T';
  char symbl4 = 'y';
  char symbl5 = ')';
  char symbl6 = '$';
  ck_assert_str_eq(strchr(str1, symbl1), s21_strchr(str1, symbl1));
  ck_assert_str_eq(strchr(str1, symbl2), s21_strchr(str1, symbl2));
  ck_assert_str_eq(strchr(str2, symbl3), s21_strchr(str2, symbl3));
  ck_assert_str_eq(strchr(str2, symbl4), s21_strchr(str2, symbl4));
  ck_assert_str_eq(strchr(str3, symbl5), s21_strchr(str3, symbl5));
  ck_assert_uint_eq((uintmax_t)strchr(str3, 300),
                    (uintmax_t)s21_strchr(str3, 300));
  ck_assert_uint_eq((uintmax_t)strchr(str3, symbl6),
                    (uintmax_t)s21_strchr(str3, symbl6));
}
END_TEST

Suite *strchr_test() {
  Suite *suite = suite_create("s21_strchr_test");
  TCase *test_cases = tcase_create("s21_strchr_test");

  tcase_add_test(test_cases, s21_strchr_test);

  suite_add_tcase(suite, test_cases);

  return suite;
}