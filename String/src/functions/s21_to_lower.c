#include "s21_string.h"

// возвращает копию строки в нижнем регистре
void *s21_to_lower(const char *str) {
  char *out_str = S21_NULL;
  if (str) {
    // в идеале заменить на calloc, во время тестов нужно будет проверить
    // работоспособность
    out_str = (char *)calloc((s21_strlen(str) + 1), sizeof(char));
  }
  if (out_str) {
    s21_strncpy(out_str, str, s21_strlen(str) + 1);
    char *ptr_symbl = out_str;
    while (*ptr_symbl) {
      if (*ptr_symbl >= 'A' && *ptr_symbl <= 'Z') {
        *ptr_symbl += 32;
      }
      ptr_symbl++;
    }
  }
  return (char *)out_str;
}