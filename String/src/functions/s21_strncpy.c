#include "s21_string.h"

// копирует n символов, не включая \0
char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  byte *ptr_dest = (byte *)dest;
  byte *ptr_src = (byte *)src;
  int i = (int)n;
  // перекидываем символы из src
  while (i-- && *(ptr_src) != '\0') {
    *(ptr_dest++) = *(ptr_src++);
  }
  // забиваем все оставшиеся n \0 (так работает оригинальный strncpy)
  // включая последний символ после n
  while (i-- >= 0) {
    *(ptr_dest++) = '\0';
  }
  ptr_dest = (byte *)dest;
  return (char *)ptr_dest;
}
