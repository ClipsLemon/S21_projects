#include "s21_string.h"

// заменяет n байтов (игнор \0) на c
void *s21_memset(void *str, int c, s21_size_t n) {
  byte *ptr_str = (byte *)str;
  while (n--) {
    *ptr_str++ = c;
  }
  return str;
}