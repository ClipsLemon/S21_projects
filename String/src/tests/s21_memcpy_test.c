#include "s21_tests.h"

START_TEST(s21_memcpy_test) {
  char str1[] = "The avocado fruit is a climacteric, single-seeded berry";
  char str2[] = "  ";
  char str3[56];
  char str4[56] = "SOME OF THINGS CAN MAKE YOU REALLY HAPPY ^_^";
  char str5[14] = "\\ \0-/da/w123";

  char *memcpy_str1 = (char *)memcpy(str2, str1, 3);
  char *memcpy_str2 = (char *)memcpy(str3, str1, 55);
  char *memcpy_str3 = (char *)memcpy(str4, str1, 55);
  char *memcpy_str4 = (char *)memcpy(str1, str5, 14);

  char *s21_memcpy_str1 = (char *)s21_memcpy(str2, str1, 3);
  char *s21_memcpy_str2 = (char *)s21_memcpy(str3, str1, 55);
  char *s21_memcpy_str3 = (char *)s21_memcpy(str4, str1, 55);
  char *s21_memcpy_str4 = (char *)s21_memcpy(str1, str5, 14);

  ck_assert_uint_eq(
      s21_strncmp(memcpy_str1, s21_memcpy_str1, s21_strlen(s21_memcpy_str1)),
      0);
  ck_assert_uint_eq(
      s21_strncmp(memcpy_str2, s21_memcpy_str2, s21_strlen(s21_memcpy_str2)),
      0);
  ck_assert_uint_eq(
      s21_strncmp(memcpy_str3, s21_memcpy_str3, s21_strlen(s21_memcpy_str3)),
      0);
  ck_assert_uint_eq(
      s21_strncmp(memcpy_str4, s21_memcpy_str4, s21_strlen(s21_memcpy_str4)),
      0);
}
END_TEST

Suite *memcpy_test() {
  Suite *suite = suite_create("s21_memcpy_test");
  TCase *test_cases = tcase_create("s21_memcpy_test");

  tcase_add_test(test_cases, s21_memcpy_test);

  suite_add_tcase(suite, test_cases);

  return suite;
}