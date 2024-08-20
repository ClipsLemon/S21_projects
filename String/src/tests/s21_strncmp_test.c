#include "s21_tests.h"

START_TEST(s21_strncmp_test) {
  char str1[] = "The avocado fruit";
  char str2[] = "The avocado fruit is a climacteric, $single-seeded berry";
  char str3[] = "masdl:!@#!@MCZ@!#)($_)*@#";
  char str1_c[] = "The avocado fruit";
  char str2_c[] = "The avocado fruit is a climacteric, $single-seeded berry";
  char str3_c[] = "masdl:!@#!@MCZ@!#)($_)*@#";

  ck_assert_int_eq(strncmp(str1, str1_c, 17), s21_strncmp(str1, str1_c, 17));
  ck_assert_int_eq(strncmp(str2, str2_c, 56), s21_strncmp(str2, str2_c, 56));
  ck_assert_int_eq(strncmp(str3, str3_c, 25), s21_strncmp(str3, str3_c, 25));
  ck_assert_int_eq(strncmp(str3, str2_c, 10), s21_strncmp(str3, str2_c, 10));
  ck_assert_int_eq(strncmp(str2, str3_c, 25), s21_strncmp(str2, str3_c, 25));
}
END_TEST

Suite *strncmp_test() {
  Suite *suite = suite_create("s21_strncmp_test");
  TCase *test_cases = tcase_create("s21_strncmp_test");

  tcase_add_test(test_cases, s21_strncmp_test);

  suite_add_tcase(suite, test_cases);

  return suite;
}