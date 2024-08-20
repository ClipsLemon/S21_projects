#ifndef S21_SPRINTF_H
#define S21_SPRINTF_H

#include "s21_string.h"

#define SPECS "icdfsugGeEoxXpn"
#define STRF_SIZE 1024

typedef struct {
  int width;
  int precision;
  int plus;
  int minus;
  int space;
  int hash;
  int zero;
  char length;
  char spec;
} settings;

void s21_parse_format(char *str, const char *format, va_list arg);
void s21_format(char *str, const char *format, va_list arg, s21_size_t *i_s,
                s21_size_t *i_f);
int s21_parse_number(const char *str, s21_size_t *p);
void s21_specs(char *str, s21_size_t *i, va_list arg, settings f_set);
void s21_c_form(const char c, char *str, s21_size_t *i, settings f_set);
void s21_lc_form(wchar_t c1, char *str, s21_size_t *i, settings f_set);
void s21_d_form(long long x, char *str, s21_size_t *i, settings f_set,
                int base);
void s21_f_form(long double f, settings f_set, char *str, s21_size_t *i);
void s21_s_form(va_list arg, char *str, s21_size_t *i, settings f_set);
void s21_u_form(unsigned long d, char *str, s21_size_t *i, int base,
                settings f_set);
void s21_g_form(long double f, settings f_set, char *str, s21_size_t *i);
void s21_rm_zeroes(char *str, s21_size_t *i);
void s21_e_form(long double val, settings f_set, char *str, s21_size_t *i);
void s21_mantiss(char *str, int pow, char sign, s21_size_t *i, int mode);
void s21_p_form(long val, settings f_set, char *str, s21_size_t *i);
void s21_apply_flags(char *d_str, settings f_set, char *str, s21_size_t *i,
                     int mode);
int s21_check_zeroes(char *buf);

#endif  // S21_SPRINTF_H