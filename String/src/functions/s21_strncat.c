#include "s21_string.h"

// к dest добавляет n символов из src
char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  byte *ptr_dest = (byte *)dest;
  byte *ptr_src = (byte *)src;
  // доходим до конца итоговой строки
  while (*(ptr_dest) != '\0') {
    ptr_dest++;
  }

  while (n--) {
    *(ptr_dest++) = *(ptr_src++);
  }
  *(ptr_dest) = '\0';
  ptr_dest = (byte *)dest;
  return (char *)ptr_dest;
}