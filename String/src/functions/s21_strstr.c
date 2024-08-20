#include "s21_string.h"

// находит вхождение подстроки needle в haystack
char *s21_strstr(const char *haystack, const char *needle) {
  int needle_len = (int)s21_strlen(needle);
  byte *ptr_haystack = (byte *)haystack;
  byte *ptr_needle = (byte *)needle;
  if (*ptr_needle != '\0') {
    while (*ptr_haystack) {
      if (*ptr_haystack == *ptr_needle) {
        needle_len--;
        ptr_needle++;
      } else {
        needle_len = (int)s21_strlen(needle);
        ptr_needle = (byte *)needle;
      }
      if (needle_len == 0) {
        ptr_haystack = ptr_haystack - s21_strlen(needle) + 1;
        break;
      }
      ptr_haystack++;
    }
    if (needle_len != 0) {
      ptr_haystack = S21_NULL;
    }
  }
  return (char *)ptr_haystack;
}