#ifndef TESTS_H
#define TESTS_H
#include <check.h>
#include <limits.h>
#include <locale.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <wchar.h>

#include "s21_string.h"

Suite *insert_test();
Suite *memchr_test();
Suite *memcmp_test();
Suite *memcpy_test();
Suite *memset_test();
Suite *strchr_test();
Suite *strcspn_test();
Suite *strerror_test();
Suite *strlen_test();
Suite *strncat_test();
Suite *strncmp_test();
Suite *strncpy_test();
Suite *strpbrk_test();
Suite *strrchr_test();
Suite *strstr_test();
Suite *strtok_test();
Suite *to_lower_test();
Suite *to_upper_test();
Suite *trim_test();

Suite *s21_sprintf_test();
Suite *s21_sscanf_test();

#endif  // TESTS_H