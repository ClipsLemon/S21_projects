#include "s21_tests.h"

START_TEST(s21_strncat_test) {
  char str1[] = "The avocado fruit \0is a climacteric, single-seeded berry";
  char str2[] = "Okay, I'M new STRING!";
  char str4[] = "<<<>>>";
  char str1_c[] = "The avocado fruit \0is a climacteric, single-seeded berry";
  char str2_c[] = "Okay, I'M new STRING!";
  char str4_c[] = "<<<>>>";
  ck_assert_str_eq(strncat(str1, str2, 21), s21_strncat(str1_c, str2_c, 21));
  ck_assert_str_eq(strncat(str1, str4, 6), s21_strncat(str1_c, str4_c, 6));
  // больше символов чем есть в строке
  ck_assert_str_eq(strncat(str1, str4, 25), s21_strncat(str1_c, str4_c, 25));
  ck_assert_str_eq(strncat(str2, str1, 8), s21_strncat(str2_c, str1_c, 8));
}
END_TEST

Suite *strncat_test() {
  Suite *suite = suite_create("s21_strncat_test");
  TCase *test_cases = tcase_create("s21_strncat_test");

  tcase_add_test(test_cases, s21_strncat_test);

  suite_add_tcase(suite, test_cases);

  return suite;
}