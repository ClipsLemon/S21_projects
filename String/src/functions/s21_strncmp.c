#include "s21_string.h"

// сравнивает n символов не включая \0
int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  byte *ptr_str1 = (byte *)str1;
  byte *ptr_str2 = (byte *)str2;

  while (n--) {
    if (*(ptr_str1) == *(ptr_str2)) {
      if (*(ptr_str1) != '\0' && *(ptr_str2) != '\0') {
        ptr_str1++;
        ptr_str2++;
      } else {
        break;
      }
    }
  }
  return ((*ptr_str1) - (*ptr_str2));
}
