#include "s21_tests.h"

START_TEST(s21_to_lower_test) {
  char str1[] = "The/Avocado/Fr!!uit/@@Is/A/Climacteric,/Single-Seeded/Berry";
  char res1[] = "the/avocado/fr!!uit/@@is/a/climacteric,/single-seeded/berry";
  char str2[] = "all letter is low";
  char res2[] = "all letter is low";
  char str3[] = "182397*(&!@#*9&!@#EAWJK#NM! @<MDA*@)";
  char res3[] = "182397*(&!@#*9&!@#eawjk#nm! @<mda*@)";

  char *to_lower_res1 = (char *)s21_to_lower(str1);
  char *to_lower_res2 = (char *)s21_to_lower(str2);
  char *to_lower_res3 = (char *)s21_to_lower(str3);

  ck_assert_str_eq(to_lower_res1, res1);
  ck_assert_str_eq(to_lower_res2, res2);
  ck_assert_str_eq(to_lower_res3, res3);

  free(to_lower_res1);
  free(to_lower_res2);
  free(to_lower_res3);
  to_lower_res1 = S21_NULL;
  to_lower_res2 = S21_NULL;
  to_lower_res3 = S21_NULL;
}
END_TEST

Suite *to_lower_test() {
  Suite *suite = suite_create("s21_to_lower_test");
  TCase *test_cases = tcase_create("s21_to_lower_test");

  tcase_add_test(test_cases, s21_to_lower_test);

  suite_add_tcase(suite, test_cases);

  return suite;
}