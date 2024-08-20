#include "s21_string.h"

// функция проверяет наличие ch в str
int s21_in_str(const char *ch, const char *str) {
  int answer = 0;
  s21_size_t len = s21_strlen(str);
  for (s21_size_t i = 0; i < len; i++) {
    if (*ch == *(str + i)) {
      answer = 1;
      break;
    }
  }
  return answer;
}