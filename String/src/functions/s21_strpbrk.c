#include "s21_string.h"

// находит первое вхождение любого из символов str2 в str1 не включая \0
char *s21_strpbrk(const char *str1, const char *str2) {
  byte *ptr_str1 = (byte *)str1;
  byte *ptr_str2 = (byte *)str2;
  s21_size_t position = 0;
  s21_size_t min_position = s21_strlen(str1);
  while (*ptr_str2) {
    while (*ptr_str1) {
      if (*ptr_str1 == *ptr_str2) {
        if (min_position > position) {
          min_position = position;
        }
        break;
      }
      ptr_str1++;
      position++;
    }
    if (min_position == 0) break;
    position = 0;
    ptr_str2++;
    ptr_str1 = (byte *)str1;
  }
  if (min_position == s21_strlen(str1))
    ptr_str1 = S21_NULL;
  else
    ptr_str1 = (byte *)(str1 + min_position);
  return (char *)ptr_str1;
}