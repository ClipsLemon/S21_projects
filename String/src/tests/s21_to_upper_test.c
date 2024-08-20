#include "s21_tests.h"

START_TEST(s21_to_upper_test) {
  char str1[] = "The/Avocado/Fr!!uit/@@Is/A/Climacteric,/Single-Seeded/Berry";
  char res1[] = "THE/AVOCADO/FR!!UIT/@@IS/A/CLIMACTERIC,/SINGLE-SEEDED/BERRY";
  char str2[] = "all letter is up";
  char res2[] = "ALL LETTER IS UP";
  char str3[] = "182397*(&!@#*9&!@#EAWJK#NM! @<MDA*@)";
  char res3[] = "182397*(&!@#*9&!@#EAWJK#NM! @<MDA*@)";
  char *str4 = S21_NULL;
  char *res4 = S21_NULL;
  char *to_upper_res1 = (char *)s21_to_upper(str1);
  char *to_upper_res2 = (char *)s21_to_upper(str2);
  char *to_upper_res3 = (char *)s21_to_upper(str3);

  ck_assert_str_eq(to_upper_res1, res1);
  ck_assert_str_eq(to_upper_res2, res2);
  ck_assert_str_eq(to_upper_res3, res3);
  ck_assert_uint_eq((uintmax_t)s21_to_upper(str4), (uintmax_t)res4);

  free(to_upper_res1);
  free(to_upper_res2);
  free(to_upper_res3);
  to_upper_res1 = S21_NULL;
  to_upper_res2 = S21_NULL;
  to_upper_res3 = S21_NULL;
}
END_TEST

Suite *to_upper_test() {
  Suite *suite = suite_create("s21_to_upper_test");
  TCase *test_cases = tcase_create("s21_to_upper_test");

  tcase_add_test(test_cases, s21_to_upper_test);

  suite_add_tcase(suite, test_cases);

  return suite;
}