#include "s21_tests.h"

START_TEST(s21_memchr_test) {
  char str1[] = "This is example of \0 $ some text";

  // отсутствующие символы
  char miss_symbl1 = '0';
  char miss_symbl2 = '9';
  char miss_symbl3 = '/';
  char miss_symbl4 = '>';
  char miss_symbl5 = '%';
  // присутствующие символы
  char pres_symbl1 = 't';
  char pres_symbl2 = 'T';
  char pres_symbl3 = '$';
  char pres_symbl4 = '\0';
  char pres_symbl5 = 'i';

  ck_assert_uint_eq((uintmax_t)memchr(str1, miss_symbl1, 32),
                    (uintmax_t)s21_memchr(str1, miss_symbl1, 32));
  ck_assert_uint_eq((uintmax_t)memchr(str1, miss_symbl2, 32),
                    (uintmax_t)s21_memchr(str1, miss_symbl2, 32));
  ck_assert_uint_eq((uintmax_t)memchr(str1, miss_symbl3, 32),
                    (uintmax_t)s21_memchr(str1, miss_symbl3, 32));
  ck_assert_uint_eq((uintmax_t)memchr(str1, miss_symbl4, 32),
                    (uintmax_t)s21_memchr(str1, miss_symbl4, 32));
  ck_assert_uint_eq((uintmax_t)memchr(str1, miss_symbl5, 32),
                    (uintmax_t)s21_memchr(str1, miss_symbl5, 32));

  ck_assert_uint_eq((uintmax_t)memchr(str1, pres_symbl1, 32),
                    (uintmax_t)s21_memchr(str1, pres_symbl1, 32));
  ck_assert_uint_eq((uintmax_t)memchr(str1, pres_symbl2, 32),
                    (uintmax_t)s21_memchr(str1, pres_symbl2, 32));
  ck_assert_uint_eq((uintmax_t)memchr(str1, pres_symbl3, 32),
                    (uintmax_t)s21_memchr(str1, pres_symbl3, 32));
  ck_assert_uint_eq((uintmax_t)memchr(str1, pres_symbl4, 32),
                    (uintmax_t)s21_memchr(str1, pres_symbl4, 32));
  ck_assert_uint_eq((uintmax_t)memchr(str1, pres_symbl5, 32),
                    (uintmax_t)s21_memchr(str1, pres_symbl5, 32));
}
END_TEST

Suite *memchr_test() {
  Suite *suite = suite_create("s21_memchr_test");
  TCase *test_cases = tcase_create("s21_memchr_test");

  tcase_add_test(test_cases, s21_memchr_test);

  suite_add_tcase(suite, test_cases);

  return suite;
}