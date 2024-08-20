#include "s21_tests.h"

START_TEST(s21_memcmp_test) {
  char str1[] = "This is example of \0 $ text";
  char str1_eq[] = "This is example of \0 $ text";
  char str2[] = "Another text";
  char str3[] = "This is example of another text";
  char str4[] = " ";
  char str5[] = "\0";
  char str6[] = "And such Another text";

  ck_assert_uint_eq((uintmax_t)memcmp(str1, str1_eq, 27),
                    (uintmax_t)s21_memcmp(str1, str1_eq, 27));

  ck_assert_uint_eq((uintmax_t)memcmp(str1, str2, 13),
                    (uintmax_t)s21_memcmp(str1, str2, 13));

  ck_assert_uint_eq((uintmax_t)memcmp(str1, str3, 13),
                    (uintmax_t)s21_memcmp(str1, str3, 13));

  ck_assert_uint_eq((uintmax_t)memcmp(str1, str4, 2),
                    (uintmax_t)s21_memcmp(str1, str4, 2));

  ck_assert_uint_eq((uintmax_t)memcmp(str4, str1, 2),
                    (uintmax_t)s21_memcmp(str4, str1, 2));

  ck_assert_uint_eq((uintmax_t)memcmp(str4, str1, 2),
                    (uintmax_t)s21_memcmp(str4, str1, 2));

  ck_assert_uint_eq((uintmax_t)memcmp(str4, str1, 2),
                    (uintmax_t)s21_memcmp(str4, str1, 2));

  ck_assert_uint_eq((uintmax_t)memcmp(str2, str6, 2),
                    (uintmax_t)s21_memcmp(str2, str6, 2));

  ck_assert_uint_eq((uintmax_t)memcmp(str4, str5, 2),
                    (uintmax_t)s21_memcmp(str4, str5, 2));
}
END_TEST

Suite *memcmp_test() {
  Suite *suite = suite_create("s21_memcpm_test");
  TCase *test_cases = tcase_create("s21_memcmp_test");

  tcase_add_test(test_cases, s21_memcmp_test);

  suite_add_tcase(suite, test_cases);

  return suite;
}