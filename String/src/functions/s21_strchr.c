#include "../s21_string.h"

// ищет символ c и возвращает его позицию, иначе NULL, не включа \0
char *s21_strchr(const char *str, int c) {
  byte *ptr_str = (byte *)str;
  while (*ptr_str != c && *ptr_str != '\0') {
    ptr_str++;
  }
  if (*ptr_str != c) {
    ptr_str = S21_NULL;
  }
  return (char *)ptr_str;
}