#include "s21_tests.h"

START_TEST(s21_strrchr_test) {
  char str1[] = "The avocado fruit is a climacteric, single-seeded berry$//@";
  char str2[] = "  /213\\/\"";
  char symbl1 = '\0';
  char symbl2 = ' ';
  char symbl3 = '@';
  char symbl4 = '\\';
  char symbl5 = '3';
  char symbl6 = '\"';
  char unfinded_symbl = 'p';
  ck_assert_uint_eq((uintmax_t)strrchr(str1, unfinded_symbl),
                    (uintmax_t)s21_strrchr(str1, unfinded_symbl));

  ck_assert_str_eq(strrchr(str1, symbl1), s21_strrchr(str1, symbl1));
  ck_assert_str_eq(strrchr(str1, symbl2), s21_strrchr(str1, symbl2));
  ck_assert_str_eq(strrchr(str1, symbl3), s21_strrchr(str1, symbl3));
  ck_assert_str_eq(strrchr(str2, symbl4), s21_strrchr(str2, symbl4));
  ck_assert_str_eq(strrchr(str2, symbl5), s21_strrchr(str2, symbl5));
  ck_assert_str_eq(strrchr(str2, symbl6), s21_strrchr(str2, symbl6));
}
END_TEST

Suite *strrchr_test() {
  Suite *suite = suite_create("s21_strrchr_test");
  TCase *test_cases = tcase_create("s21_strrchr_test");

  tcase_add_test(test_cases, s21_strrchr_test);

  suite_add_tcase(suite, test_cases);

  return suite;
}