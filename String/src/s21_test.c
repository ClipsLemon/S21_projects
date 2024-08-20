#include "s21_tests.h"

void case_test(Suite *s) {
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  srunner_free(runner);
}

int main(void) {
  setlocale(LC_ALL, "");
  setlocale(LC_NUMERIC, "C");

  case_test(insert_test());
  case_test(memchr_test());
  case_test(memcmp_test());
  case_test(memcpy_test());
  case_test(memset_test());
  case_test(strchr_test());
  case_test(strcspn_test());
  case_test(strerror_test());
  case_test(strlen_test());
  case_test(strncat_test());
  case_test(strncmp_test());
  case_test(strncpy_test());
  case_test(strpbrk_test());
  case_test(strrchr_test());
  case_test(strstr_test());
  case_test(strtok_test());
  case_test(to_lower_test());
  case_test(to_upper_test());
  case_test(trim_test());
  case_test(s21_sprintf_test());
  case_test(s21_sscanf_test());

  return 0;
}