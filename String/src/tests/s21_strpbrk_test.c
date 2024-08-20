#include "s21_tests.h"

START_TEST(s21_strpbrk_test) {
  char str1[] = "The avocado fruit is a climacteric, single-seeded berry$//@";
  char subsymbl[] = "thave";
  char str2[] = "Hello, world";
  char *empty = "";
  char subsymbl2[] = "\0";
  char subsymbl3[] = "\0Hf";
  char subsymbl4[] = "@/$";
  ck_assert_uint_eq((uintmax_t)strpbrk(str2, empty),
                    (uintmax_t)s21_strpbrk(str2, empty));
  ck_assert_uint_eq((uintmax_t)strpbrk(str2, subsymbl2),
                    (uintmax_t)s21_strpbrk(str2, subsymbl2));
  ck_assert_uint_eq((uintmax_t)strpbrk(str1, subsymbl3),
                    (uintmax_t)s21_strpbrk(str1, subsymbl3));

  ck_assert_str_eq(strpbrk(str1, subsymbl), s21_strpbrk(str1, subsymbl));
  ck_assert_str_eq(strpbrk(str1, subsymbl4), s21_strpbrk(str1, subsymbl4));
}
END_TEST

Suite *strpbrk_test() {
  Suite *suite = suite_create("s21_strpbrk_test");
  TCase *test_cases = tcase_create("s21_strpbrk_test");

  tcase_add_test(test_cases, s21_strpbrk_test);

  suite_add_tcase(suite, test_cases);

  return suite;
}