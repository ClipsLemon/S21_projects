#include "s21_tests.h"

START_TEST(s21_strlen_test) {
  char str1[] = "\0safkdasmlfds";
  char str2[] =
      "jsikl  k2jr,pmoquj djklw kl: AW\n d\a \taw "
      "d1fasdlmfd,sac.,adml3j3o4u88824u8432u8348492242";
  char str3[] = "ldfjksjfklkadds\0dskflsdfjkasfd";
  char str4[] = "ldfjksjfklkaddsdskflsdfjkasfd\0";

  ck_assert_uint_eq(strlen(str1), s21_strlen(str1));
  ck_assert_uint_eq(strlen(str2), s21_strlen(str2));
  ck_assert_uint_eq(strlen(str3), s21_strlen(str3));
  ck_assert_uint_eq(strlen(str4), s21_strlen(str4));
}
END_TEST

Suite *strlen_test() {
  Suite *suite = suite_create("s21_strlen_test");
  TCase *test_cases = tcase_create("s21_strlen_test");

  tcase_add_test(test_cases, s21_strlen_test);

  suite_add_tcase(suite, test_cases);

  return suite;
}