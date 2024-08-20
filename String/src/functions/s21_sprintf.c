#include "s21_sprintf.h"

#include <math.h>
#include <stdarg.h>

int s21_sprintf(char *str, const char *format, ...) {
  va_list arg;
  va_start(arg, format);

  s21_parse_format(str, format, arg);

  va_end(arg);
  return s21_strlen(str);
}

void s21_parse_format(char *str, const char *format, va_list arg) {
  s21_size_t i_s = 0, i_f = 0;
  for (; format[i_f + 1] != '\0'; i_s++, i_f++) {
    if (format[i_f] == '%') {
      if (format[i_f + 1] == '%')
        str[i_s] = '%';
      else
        s21_format(str, format, arg, &i_s, &i_f);
    } else {
      str[i_s] = format[i_f];
    }
  }
  str[i_s++] = format[i_f++];
  str[i_s] = '\0';
}

void s21_format(char *str, const char *format, va_list arg, s21_size_t *i_s,
                s21_size_t *i_f) {
  settings f_set = {0, -1, 0, 0, 0, 0, 0, ' ', ' '};

  for (; format[++(*i_f)] != '\0';) {
    if (format[(*i_f)] == '-')
      f_set.minus = 1;
    else if (format[(*i_f)] == '+')
      f_set.plus = 1;
    else if (format[(*i_f)] == ' ')
      f_set.space = 1;
    else if (format[(*i_f)] == '#')
      f_set.hash = 1;
    else if (format[(*i_f)] == '0')
      f_set.zero = 1;
    else if (format[(*i_f)] > '0' && format[(*i_f)] <= '9')
      f_set.width = s21_parse_number(format, i_f);
    else if (format[(*i_f)] == '*')
      f_set.width = va_arg(arg, int);
    else if (format[(*i_f)] == '.') {
      (*i_f)++;
      if (format[(*i_f)] == '*')
        f_set.precision = va_arg(arg, int);
      else
        f_set.precision = s21_parse_number(format, i_f);
    } else if (format[(*i_f)] == 'h')
      f_set.length = 'h';
    else if (format[(*i_f)] == 'l')
      f_set.length = 'l';
    else if (format[(*i_f)] == 'L')
      f_set.length = 'L';
    else if (s21_strchr(SPECS, format[(*i_f)]) != S21_NULL) {
      f_set.spec = format[(*i_f)];
      s21_specs(str, i_s, arg, f_set);
      break;
    }
  }
}

int s21_parse_number(const char *str, s21_size_t *p) {
  int num = 0;
  for (; str[(*p)] >= '0' && str[(*p)] <= '9'; (*p)++) {
    num = num * 10 + (int)str[(*p)] - 48;
  }
  (*p)--;
  return num;
}

void s21_specs(char *str, s21_size_t *i, va_list arg, settings f_set) {
  switch (f_set.spec) {
    case 'c': {
      if (f_set.length == 'l')
        s21_lc_form(va_arg(arg, wchar_t), str, i, f_set);
      else
        s21_c_form(va_arg(arg, int), str, i, f_set);
      break;
    }
    case 'd':
    case 'i': {
      if (f_set.length == 'h')
        s21_d_form((short)va_arg(arg, int), str, i, f_set, 10);
      else if (f_set.length == 'l')
        s21_d_form(va_arg(arg, long long), str, i, f_set, 10);
      else
        s21_d_form(va_arg(arg, int), str, i, f_set, 10);
      break;
    }
    case 'f': {
      if (f_set.length == 'L')
        s21_f_form(va_arg(arg, long double), f_set, str, i);
      else
        s21_f_form(va_arg(arg, double), f_set, str, i);
      break;
    }
    case 's': {
      s21_s_form(arg, str, i, f_set);
      break;
    }
    case 'u': {
      s21_u_form(va_arg(arg, long long unsigned int), str, i, 10, f_set);
      break;
    }
    case 'g':
    case 'G': {
      if (f_set.length == 'L')
        s21_g_form(va_arg(arg, long double), f_set, str, i);
      else
        s21_g_form(va_arg(arg, double), f_set, str, i);
      break;
    }
    case 'e':
    case 'E': {
      if (f_set.length == 'L')
        s21_e_form(va_arg(arg, long double), f_set, str, i);
      else
        s21_e_form(va_arg(arg, double), f_set, str, i);
      break;
    }
    case 'x':
    case 'X': {
      s21_u_form(va_arg(arg, long unsigned long), str, i, 16, f_set);
      break;
    }
    case 'o': {
      s21_u_form(va_arg(arg, long unsigned int), str, i, 8, f_set);
      break;
    }
    case 'p': {
      s21_p_form(va_arg(arg, long), f_set, str, i);
      break;
    }
    case 'n': {
      *(va_arg(arg, int *)) = (*i);
      break;
    }
  }
}

void s21_c_form(const char c, char *str, s21_size_t *i, settings f_set) {
  if (f_set.width && !f_set.minus) {
    for (int j = 0; j < f_set.width - 1; j++) {
      str[(*i)] = ' ';
      (*i)++;
    }
    str[(*i)] = c;
  } else if (f_set.width && f_set.minus) {
    str[(*i)++] = c;
    for (int j = 0; j < f_set.width - 1; j++) {
      str[(*i)++] = ' ';
    }
    (*i)--;
  } else {
    str[(*i)] = c;
  }
}

void s21_lc_form(wchar_t c1, char *str, s21_size_t *i, settings f_set) {
  char tmp[5] = {'\0'};
  // tmp[0] = c1;
  wcstombs(tmp, &c1, 4);

  if (f_set.width && !f_set.minus) {
    for (int j = 0; j < f_set.width - 2; j++) {
      str[(*i)++] = ' ';
    }

    str[(*i)] = '\0';
    (*i) = s21_strlen(s21_strcat(str, tmp)) - 1;

  } else if (f_set.width && f_set.minus) {
    (*i) = s21_strlen(s21_strcat(str, tmp));
    for (int j = 0; j < f_set.width - 1; j++) {
      str[(*i)++] = ' ';
    }
    (*i)--;
  } else {
    (*i) = s21_strlen(s21_strcat(str, tmp));
  }
}

void s21_d_form(long long x, char *str, s21_size_t *i, settings f_set,
                int base) {
  int sign = 0;
  if (f_set.precision == 0) f_set.precision = 1;
  if (x < 0 && x != 0) {
    x = -x;
    sign = 1;
  }
  char d_str[32] = {'\0'};
  int el = 0;

  if (x == 0) {
    d_str[0] = '0';
    el++;
  } else {
    for (; x != 0; el++, x /= base) {
      d_str[el] = "0123456789abcdef"[x % base];
    }
  }

  int len = (int)s21_strlen(d_str);

  while (len++ < f_set.precision) d_str[el++] = '0';

  if (f_set.space && !sign) d_str[el] = ' ';
  if (f_set.plus && !sign) d_str[el] = '+';
  if (f_set.hash && !(f_set.spec == 'x' || f_set.spec == 'X')) d_str[el] = '0';
  if (sign) d_str[el] = '-';

  s21_apply_flags(d_str, f_set, str, i, 0);
}

void s21_print_extra(char *str, char *d_str, s21_size_t *i) {
  for (int k = 0; d_str[k] != '\0'; k++) {
    str[(*i)++] = d_str[k];
  }
  (*i)--;
}

void s21_f_form(long double f, settings f_set, char *str, s21_size_t *i) {
  if (f == INFINITY) {
    s21_print_extra(str, "inf", i);
  } else if (f == -INFINITY) {
    s21_print_extra(str, "-inf", i);
  } else if (f != f) {
    s21_print_extra(str, "nan", i);
  } else {
    int sign = 0;
    if (f_set.precision == -1) f_set.precision = 6;

    if (copysignl(1.0, f) < 0.0) {
      f = -f;
      sign = 1;
    }
    long double man = 0, ipartd = 0;
    unsigned long long ipart = 0;
    char d_str[STRF_SIZE] = {'\0'};

    man += modfl(f, &ipartd);
    ipart = (unsigned long long)ipartd;

    unsigned long del = 0;

    if (f_set.precision == 0) {
      man = 0;
    } else if (f_set.precision > 0) {
      del = pow(10, f_set.precision);
      man = roundl(man * del) / del;
    }

    int j = 0;
    ipart += (long)man;
    int count = f_set.precision == 0 ? 1 : f_set.precision;
    if (f_set.precision > 0) {
      unsigned long mani = man * powl(10, count);
      for (int k = 0; k < count; k++) {
        d_str[j++] = mani % 10 + '0';
        mani /= 10;
      }
    }

    if ((f_set.precision > 0) || f_set.hash) d_str[j++] = '.';

    if (ipart == 0) d_str[j++] = '0';
    while (ipart != 0) {
      d_str[j++] = ipart % 10 + '0';
      ipart /= 10;
    }

    if (f_set.plus && !sign)
      d_str[j] = '+';
    else if (sign)
      d_str[j] = '-';
    else if (f_set.space && !sign)
      d_str[j] = ' ';
    s21_apply_flags(d_str, f_set, str, i, count);
  }
}

void s21_s_form(va_list arg, char *str, s21_size_t *i, settings f_set) {
  int j = 0;
  char temp[STRF_SIZE] = {'\0'};

  if (f_set.length == 'l') {
    const wchar_t *wstr = va_arg(arg, wchar_t *);
    if (wstr != S21_NULL) {
      j = wcstombs(temp, wstr, STRF_SIZE);

      if (f_set.width && !f_set.minus) {
        for (int k = 0; k < f_set.width - j; k++) {
          str[(*i)++] = ' ';
        }
      }
      j = 0;
      while (temp[j] != '\0' && f_set.precision != 0 &&
             (j < f_set.precision || f_set.precision == -1)) {
        str[(*i)++] = temp[j++];
      }
      if (f_set.width && f_set.minus) {
        for (int k = 0; k < f_set.width - j; k++) {
          str[(*i)++] = ' ';
        }
      }
      (*i)--;
    } else {
      s21_strcat(str, "(null)");
      (*i) += 6;
    }
  } else {
    char *d_str = va_arg(arg, char *);
    if (d_str != S21_NULL) {
      j = s21_strlen(d_str);
      if (f_set.width && !f_set.minus) {
        for (int k = 0; k < f_set.width - j; k++) {
          str[(*i)++] = ' ';
        }
      }
      j = 0;
      while (d_str[j] != '\0' && f_set.precision != 0 &&
             (j < f_set.precision || f_set.precision == -1)) {
        str[(*i)++] = d_str[j++];
      }

      if (f_set.width && f_set.minus) {
        for (int k = 0; k < f_set.width - j; k++) {
          str[(*i)++] = ' ';
        }
      }
      (*i)--;
    } else {
      s21_strcat(str, "(null)");
      (*i) += 6;
    }
  }
}

void s21_u_form(long unsigned int d, char *str, s21_size_t *i, int base,
                settings f_set) {
  // if (f_set.length == 'l')
  //   d = (unsigned long long)d;
  // else
  if (f_set.length == 'h')
    d = (unsigned short)d;
  else if (f_set.length == ' ')
    d = (unsigned int)d;

  int is_zero = 0;
  // printf("%llu\n", d);
  char temp[STRF_SIZE] = {'\0'};
  int j = 0;

  if (d == 0) {
    temp[j++] = '0';
    is_zero = 1;
  } else {
    for (; d != 0; j++, d /= base) {
      if (f_set.spec == 'X')
        temp[j] = "0123456789ABCDEF"[d % base];
      else
        temp[j] = "0123456789abcdef"[d % base];
    }
  }

  int len = (int)s21_strlen(temp);

  while (len < f_set.precision) {
    temp[j++] = '0';
    f_set.precision--;
  }

  if (f_set.space) temp[j] = ' ';
  if (f_set.plus) temp[j] = '+';
  if (f_set.hash && f_set.spec == 'o' && !is_zero) temp[j] = '0';
  // printf("------%lu--\n", d);
  s21_apply_flags(temp, f_set, str, i, 0);
  // for (int h = j - 1; h >= 0; h--) {
  //   str[(*i)++] = temp[h];
  // }
  // (*i)--;
}

void s21_g_form(long double f, settings f_set, char *str, s21_size_t *i) {
  int sign = copysignl(1, f);
  if (f == INFINITY) {
    if (f_set.spec == 'G')
      s21_print_extra(str, "INF", i);
    else
      s21_print_extra(str, "inf", i);
  } else if (f == -INFINITY) {
    if (f_set.spec == 'G')
      s21_print_extra(str, "-INF", i);
    else
      s21_print_extra(str, "-inf", i);
  } else if (f != f) {
    if (f_set.spec == 'G')
      s21_print_extra(str, "NAN", i);
    else
      s21_print_extra(str, "nan", i);
  } else if (sign < 0.0 && f == 0.0)
    s21_print_extra(str, "-0", i);
  else if (f == 0.0)
    s21_print_extra(str, "0", i);
  else {
    char str_e[128] = {0}, str_f[128] = {0};
    s21_size_t i_e = 0, i_f = 0;

    if (f_set.precision == -1) f_set.precision = 5;
    if (f_set.spec == 'G') f_set.spec = 'E';
    s21_e_form(f, f_set, str_e, &i_e);
    int del = 10000;
    if (f > 10) {
      f_set.precision = 4;
      del = 10;
    }
    s21_f_form(roundl(f * del) / del, f_set, str_f, &i_f);

    if (i_e > i_f) {
      s21_rm_zeroes(str_f, &i_f);
      s21_print_extra(str, str_f, i);
      // s21_f_form(f, f_set, str, i);
    } else {
      s21_print_extra(str, str_e, i);
    }
  }
}

void s21_rm_zeroes(char *str, s21_size_t *i) {
  for (; str[(*i)] == '0' || str[(*i)] == '.'; (*i)--) {
    if (str[(*i)] == '.') {
      str[(*i)] = '\0';
      break;
    } else
      str[(*i)] = '\0';
  }
}

void s21_e_form(long double val, settings f_set, char *str, s21_size_t *i) {
  if (val == INFINITY) {
    if (f_set.spec == 'E')
      s21_print_extra(str, "INF", i);
    else
      s21_print_extra(str, "inf", i);
  } else if (val == -INFINITY) {
    if (f_set.spec == 'E')
      s21_print_extra(str, "-INF", i);
    else
      s21_print_extra(str, "-inf", i);
  } else if (val != val) {
    if (f_set.spec == 'E')
      s21_print_extra(str, "NAN", i);
    else
      s21_print_extra(str, "nan", i);
  } else {
    int pow = 0;
    char sign = (int)val == 0 ? '-' : '+';

    if ((int)val - val) {
      while ((int)val == 0) {
        pow++;
        val *= 10;
      }
    } else {
      sign = '+';
    }
    while ((int)(val / 10) != 0) {
      pow++;
      val /= 10;
    }
    if (f_set.precision == -1) f_set.precision = 6;

    if (f_set.precision == 0) {
      f_set.width -= 3;
      f_set.precision = 1;
      s21_f_form(round(val), f_set, str, i);
      s21_rm_zeroes(str, i);
      s21_mantiss(str, pow, sign, i, f_set.spec == 'E');
    } else {
      f_set.width -= 3;
      long del = powl(10, f_set.precision);
      f_set.precision += 1;
      s21_f_form(roundl(val * del) / del, f_set, str, i);
      s21_mantiss(str, pow, sign, i, f_set.spec == 'E');
    }
  }
}

void s21_mantiss(char *str, int pow, char sign, s21_size_t *i, int mode) {
  if (mode)
    str[(*i)] = 'E';
  else
    str[(*i)] = 'e';
  str[(*i) + 1] = sign;
  str[(*i) + 3] = pow % 10 + '0';
  pow /= 10;
  str[(*i) + 2] = pow % 10 + '0';
  (*i) += 3;
}

void s21_p_form(long val, settings f_set, char *str, s21_size_t *i) {
  if (val)
    s21_d_form(val, str, i, f_set, 16);
  else {
    s21_print_extra(str, "(nil)", i);
  }
}

void s21_apply_flags(char *d_str, settings f_set, char *str, s21_size_t *i,
                     int mode) {
  int base_w = (int)s21_strlen(d_str);
  int sign_delta = 0;

  if ((f_set.hash && (f_set.spec == 'x' || f_set.spec == 'X')) ||
      f_set.spec == 'p') {
    if (!s21_check_zeroes(d_str) || f_set.spec == 'p') {
      f_set.precision += 2;
      f_set.width -= 1;
      if (f_set.width) f_set.width -= 2;
    }
  } else if (f_set.width && f_set.hash &&
             (f_set.spec == 'x' || f_set.spec == 'X' || f_set.spec == 'p'))
    f_set.width -= 2;

  if (f_set.width && !f_set.minus) {
    if (d_str[base_w - 1] == '-' && f_set.zero) {
      str[(*i)++] = '-';
      base_w--;
      sign_delta = 1;
    }
    for (int j = 0; j < f_set.width - base_w - sign_delta; j++) {
      if (!f_set.zero)
        str[(*i)++] = ' ';
      else
        str[(*i)++] = '0';
    }
    if ((f_set.hash && (f_set.spec == 'x' || f_set.spec == 'X')) ||
        f_set.spec == 'p') {
      if (!s21_check_zeroes(d_str) || f_set.spec == 'p') {
        str[(*i)++] = '0';
        if (f_set.spec == 'X')
          str[(*i)++] = 'X';
        else
          str[(*i)++] = 'x';
      }
    }
    for (int j = 0; j < base_w; j++) str[(*i)++] = d_str[base_w - 1 - j];
    (*i)--;
  } else if (f_set.width && f_set.minus) {
    if ((f_set.hash && (f_set.spec == 'x' || f_set.spec == 'X')) ||
        f_set.spec == 'p') {
      if (!s21_check_zeroes(d_str) || f_set.spec == 'p') {
        str[(*i)++] = '0';
        if (f_set.spec == 'X')
          str[(*i)++] = 'X';
        else
          str[(*i)++] = 'x';
      }
    }
    for (int j = 0; j < base_w; j++) str[(*i)++] = d_str[base_w - 1 - j];
    for (int j = 0; j < f_set.width - mode - base_w; j++) str[(*i)++] = ' ';
    (*i)--;
  } else {
    if ((f_set.hash && (f_set.spec == 'x' || f_set.spec == 'X')) ||
        f_set.spec == 'p') {
      if (!s21_check_zeroes(d_str) || f_set.spec == 'p') {
        str[(*i)++] = '0';
        if (f_set.spec == 'X')
          str[(*i)++] = 'X';
        else
          str[(*i)++] = 'x';
      }
    }
    for (int j = 0; j < base_w; j++) str[(*i)++] = d_str[base_w - 1 - j];
    (*i)--;
  }
}

int s21_check_zeroes(char *buf) {
  for (int i = 0; buf[i]; i++)
    if (buf[i] != '0') return 0;
  return 1;
}
