#include "s21_string.h"

// по заданным разделителям разбивает строку str. Возвращает на строку после
// указателя. В самой str заместно разделителя ставит \0
char *s21_strtok(char *str, const char *delim) {
  static char *last_str;
  int symbl;

  if (str == S21_NULL) {
    str = last_str;
  }
  do {
    if ((symbl = *str++) == '\0') {
      return 0;
    }
  } while (s21_strchr(delim, symbl));
  str--;
  last_str = str + s21_strcspn(str, delim);
  if (*last_str != 0) {
    *last_str++ = 0;
  }
  return str;
}