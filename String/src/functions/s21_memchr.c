#include "s21_string.h"

// находит позицию символа по байтам, игнорирует \0
void *s21_memchr(void const *str, int c, s21_size_t n) {
  byte *ptr = (byte *)str;
  while (n-- > 0) {
    if (*ptr == c) return ptr;
    ptr++;
  }
  return S21_NULL;
}
