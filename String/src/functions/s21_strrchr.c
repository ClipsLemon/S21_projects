#include "s21_string.h"

// находит последнее вхождение символа c, включает \0
char *s21_strrchr(const char *str, int c) {
  byte *ptr_str = (byte *)str;

  for (s21_size_t i = 0; i <= s21_strlen(str); i++) {
    if (*(str + i) == c) {
      ptr_str = (byte *)(str + i);
    }
  }
  if (ptr_str == (byte *)str && *ptr_str != c) ptr_str = S21_NULL;

  return (char *)ptr_str;
}
