#include "s21_decimal.h"

#define STR_LEN 64

// Удаляет незначащие нули из строки с числом в виде научной нотации
void s21_remove_trailing_zeroes(char *str) {
  int i = 0;
  while (str[i] != 'E' && str[i] != '\0') i++;
  i--;
  while (str[i] == '0' && str[i] != '\0') {
    for (int j = i; str[j] != '\0'; j++) str[j] = str[j + 1];
    i--;
  }
}

// Возвращает значение степени научной нотации числа передаваемого в виде строки
int s21_get_scale_from_str(char *str) {
  int res = 0;
  char *ptr = str;
  while (*ptr) {
    if (*ptr == 'E') {
      ptr++;
      res = strtol(ptr, NULL, 10);
      break;
    }
    ++ptr;
  }

  return res;
}

// Возвращает длину дробной части научной нотации числа в виде строки
int s21_fractional_len(const char *str) {
  int i = 0, cnt = 0;
  while (str[i] != '.' && str[i] != '\0') i++;
  i++;
  while (str[i++] != 'E' && str[i] != '\0') cnt++;
  return cnt;
}

// Возвращает мантиссу целого числа научной нотации числа передаваемого в виде
// строки
int get_mantiss(const char *str) {
  int res = 0, i = 0;
  while (str[i] != 'E' && str[i] != '\0') {
    if (str[i] != '.') {
      res *= 10;
      res += (str[i] - 48);
    }
    i++;
  }
  return res;
}

// Запись числа типа float в число типа s21_decimal
int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int flag = 0;

  if (!dst) {
    flag = 1;
  } else if (src == 0.0) {
    s21_reset_dec(dst);
    if (signbit(src)) s21_set_bit(dst, BIT_SIGN);
  } else if (isinf(src) || isnan(src)) {
    flag = 1;
    *dst = s21_decimal_get_inf();
  } else if (fabsf(src) > MAX_FLOAT_TO_CONVERT) {
    flag = 1;
    *dst = s21_decimal_get_inf();
  } else if (fabsf(src) < MIN_FLOAT_TO_CONVERT) {
    flag = 1;
    s21_reset_dec(dst);
  } else {
    s21_reset_dec(dst);
    s21_decimal res;
    s21_reset_dec(&res);
    char buf[STR_LEN];

    int sign = (src < 0) ? 1 : 0;
    src = fabsf(src);
    int float_precision = 6;

    sprintf(buf, "%.6E", src);
    int scale = s21_get_scale_from_str(buf);

    if (scale <= -23) {
      // Если степень слишком маленькая, то не все значащие цифры поместятся в
      // decimal Поэтому корректируем точность и заново приводим float в научную
      // запись уже с новой точностью
      float_precision = scale + 28;
    }
    sprintf(buf, "%.*E", float_precision, src);
    s21_remove_trailing_zeroes(buf);
    s21_from_int_to_decimal(get_mantiss(buf), &res);
    int f_len = s21_fractional_len(buf);
    if (scale < 0) {
      scale = -scale + f_len;
    } else {
      if (f_len >= scale)
        scale = f_len - scale;
      else {
        scale = scale - f_len;
        for (; scale > 0; scale--) {
          s21_mul_ten(&res);
        }
      }
    }
    s21_set_scale(&res, scale);

    if (sign) {
      s21_set_bit(&res, BIT_SIGN);
    }
    *dst = res;
  }
  return flag;
}