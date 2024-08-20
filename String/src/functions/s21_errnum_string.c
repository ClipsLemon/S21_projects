#include "s21_string.h"

// конвертирует номер неизвестной ошибки в строку
char *s21_errnum_string(int errnum, char *err_str) {
  int errnum_len = 0, errnum_tmp = errnum;
  int i;
  while (errnum_tmp != 0) {
    errnum_tmp /= 10;
    errnum_len++;
  }
  if (errnum > 0) {
    errnum_tmp = errnum;
    err_str[errnum_len] = '\0';
    while (errnum_len != 0) {
      i = errnum_tmp % 10;
      errnum_tmp /= 10;
      err_str[errnum_len - 1] = i + '0';
      errnum_len--;
    }
  } else {
    errnum_tmp = (errnum * (-1));
    errnum_len += 1;
    err_str[0] = '-';
    err_str[errnum_len] = '\0';
    while (errnum_len != 1) {
      i = errnum_tmp % 10;
      errnum_tmp /= 10;
      err_str[errnum_len - 1] = i + '0';
      errnum_len--;
    }
  }
  return err_str;
}
