#include "s21_string.h"

//  сравнивает n байтов, то есть игнориует \0
int s21_memcmp(void const *str1, void const *str2, s21_size_t n) {
  if (!n) return (0);
  while (--n && *(byte *)str1 == *(byte *)str2) {
    str1 = (byte *)str1 + 1;
    str2 = (byte *)str2 + 1;
  }
  return (*((byte *)str1) - *((byte *)str2));
}
