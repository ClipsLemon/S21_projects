#include "s21_tests.h"

START_TEST(s21_strtok_test) {
  char str1[] = "The/avocado/fruit/is/a/climacteric,/single-seeded/berry";
  char delim1[] = "/,-";

  char str2[] = "The/avocado/fruit/is/a/climacteric,/single-seeded/berry";
  char delim2[] = "/,-";
  char *my_strtok = s21_strtok(str1, delim1);
  char *orig_strtok = strtok(str2, delim2);
  while (my_strtok != S21_NULL) {
    ck_assert_str_eq(my_strtok, orig_strtok);
    my_strtok = s21_strtok(S21_NULL, delim1);
    orig_strtok = strtok(S21_NULL, delim2);
  }
}
END_TEST

Suite *strtok_test() {
  Suite *suite = suite_create("s21_strtok_test");
  TCase *test_cases = tcase_create("s21_strtok_test");

  tcase_add_test(test_cases, s21_strtok_test);

  suite_add_tcase(suite, test_cases);

  return suite;
}