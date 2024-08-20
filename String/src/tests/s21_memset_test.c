#include "s21_tests.h"

START_TEST(s21_memset_test) {
  char str1[] = "The avocado fruit \0is a climacteric, single-seeded berry";
  char str2[] = "The avocado fruit \0is a climacteric, single-seeded berry";
  char str3[] = "The avocado fruit \0is a climacteric, single-seeded berry";
  char str4[] = "The avocado fruit \0is a climacteric, single-seeded berry";
  char symbl1 = '\0';
  char symbl2 = 'r';
  char symbl3 = '\\';
  char symbl4 = ' ';
  char res1[] =
      "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0is a climacteric, single-seeded "
      "berry";
  char res2[] = "rrrrrrrrrrrrrrrrrrrrrrrrrlimacteric, single-seeded berry";
  char res3[] =
      "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\0is a climacteric, single-seeded "
      "berry";
  char res4[] = "                  \0is a climacteric, single-seeded berry";

  char *s21_memset_str1 = (char *)s21_memset(str1, symbl1, 18);
  char *s21_memset_str2 = (char *)s21_memset(str2, symbl2, 25);
  char *s21_memset_str3 = (char *)s21_memset(str3, symbl3, 18);
  char *s21_memset_str4 = (char *)s21_memset(str4, symbl4, 18);

  ck_assert_uint_eq(strncmp(res1, s21_memset_str1, strlen(s21_memset_str1)), 0);
  ck_assert_uint_eq(strncmp(res2, s21_memset_str2, strlen(s21_memset_str2)), 0);
  ck_assert_uint_eq(strncmp(res3, s21_memset_str3, strlen(s21_memset_str3)), 0);
  ck_assert_uint_eq(strncmp(res4, s21_memset_str4, strlen(s21_memset_str4)), 0);
}
END_TEST

Suite *memset_test() {
  Suite *suite = suite_create("s21_memset_test");
  TCase *test_cases = tcase_create("s21_memset_test");

  tcase_add_test(test_cases, s21_memset_test);

  suite_add_tcase(suite, test_cases);

  return suite;
}