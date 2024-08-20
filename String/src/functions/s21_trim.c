#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  int new_s_index = 0, new_e_index = 0;
  int len_src = s21_strlen(src);
  char *new_string = S21_NULL;
  // сначала находим новый стартовый индекс
  for (int i = 0; i < len_src; i++) {
    if (s21_in_str((src + i), trim_chars)) {
      new_s_index++;
    } else {
      break;
    }
  }
  for (int i = len_src - 1; i >= 0; i--) {
    if (s21_in_str((src + i), trim_chars)) {
      new_e_index++;
    } else {
      break;
    }
  }
  if ((new_s_index + new_e_index) > 0) {
    int new_len = len_src - new_e_index - new_s_index;
    new_string = (char *)calloc((new_len + 1), sizeof(char));
    *(new_string + new_len) = '\0';
    s21_strncat(new_string, (src + new_s_index), new_len);
  } else {
    new_string = (char *)calloc((len_src + 1), sizeof(char));
    *(new_string + len_src) = '\0';
    s21_strncat(new_string, src, len_src);
  }

  return (void *)new_string;
}