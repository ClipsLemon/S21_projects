#include "s21_tests.h"

START_TEST(s21_insert_test) {
  char str1[] = "The/Avocado/Fr!!uit/@@Is/A/Climacteric,/Single-Seeded/Berry";
  char res1[] =
      "The/AVOCADOAvocado/Fr!!uit/@@Is/A/Climacteric,/Single-Seeded/Berry";
  char res2[] =
      "The/Avocado/Fr!!uit/@@Is/A/Climacteric,/Single-Seeded/BerryBERRY";
  char res3[] =
      "THEThe/Avocado/Fr!!uit/@@Is/A/Climacteric,/Single-Seeded/Berry";

  char substr1[] = "AVOCADO";
  char substr2[] = "BERRY";
  char substr3[] = "THE";
  char *insert_res_1 = (char *)s21_insert(str1, substr1, 4);
  char *insert_res_2 = (char *)s21_insert(str1, substr2, 59);
  char *insert_res_3 = (char *)s21_insert(str1, substr3, 0);
  ck_assert_str_eq(insert_res_1, res1);
  ck_assert_str_eq(insert_res_2, res2);
  ck_assert_str_eq(insert_res_3, res3);
  free(insert_res_1);
  free(insert_res_2);
  free(insert_res_3);
  insert_res_1 = S21_NULL;
  insert_res_2 = S21_NULL;
  insert_res_3 = S21_NULL;
}
END_TEST

Suite *insert_test() {
  Suite *suite = suite_create("s21_insert_test");
  TCase *test_cases = tcase_create("s21_insert_test");

  tcase_add_test(test_cases, s21_insert_test);

  suite_add_tcase(suite, test_cases);

  return suite;
}