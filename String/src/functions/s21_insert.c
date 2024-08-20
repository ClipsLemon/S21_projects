#include "s21_string.h"

// src - заданная строка, в нее с start_index вставляется строка str
void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *result_str = S21_NULL;
  const s21_size_t len_str = s21_strlen(str);
  const s21_size_t len_src = s21_strlen(src);

  if (str && src && start_index <= len_src) {
    // в идеале заменить на calloc, во время тестов нужно будет проверить
    // работоспособность
    result_str = (char *)calloc((len_src + len_str + 1), 1);
  }
  if (result_str) {
    // копируем часть до start_index
    s21_strncpy(result_str, src, start_index);
    // копируем str
    for (s21_size_t i = 0; i < len_str; i++) {
      *(result_str + start_index + i) = *(str + i);
    }
    s21_strncpy(result_str + start_index + len_str, (src + start_index),
                len_src - start_index);
  }
  return (void *)result_str;
}