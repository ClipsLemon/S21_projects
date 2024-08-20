#include "s21_string.h"

// возвращает длину строки
s21_size_t s21_strlen(const char *str) {
  byte *ptr_str = (byte *)str;
  s21_size_t len = 0;

  while (*(ptr_str++) != '\0') {
    len++;
  }

  return len;
}