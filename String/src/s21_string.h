#ifndef S21_STRING_H
#define S21_STRING_H

#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
  bool flag;
  int width;
  int accuracy;
  int length;
  char specifier;
} FormatInf;

int s21_sscanf(const char *str, const char *format, ...);

typedef unsigned long int s21_size_t;
typedef unsigned char byte;

#define S21_NULL NULL

// находит позицию символа по байтам, игнорирует \0
void *s21_memchr(void const *str, int c, s21_size_t n);

//  сравнивает n байтов, то есть игнориует \0
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);

// копириует в dest n байтов из src
void *s21_memcpy(void *dest, const void *src, s21_size_t n);

// заменяет n байтов (игнор \0) на c
void *s21_memset(void *str, int c, s21_size_t n);

// к dest добавляет n символов из src
char *s21_strncat(char *dest, const char *src, s21_size_t n);

// возвращает длину строки
s21_size_t s21_strlen(const char *str);

// ищет символ c и возвращает его позицию, иначе NULL, не включа \0
char *s21_strchr(const char *str, int c);

// сравнивает n символов не включая \0
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);

// копирует n символов строки, не включая \0
// если в dest изначально есть символы и их больше чем в src, то копируется src,
// а затем до n пишутся \0
char *s21_strncpy(char *dest, const char *src, s21_size_t n);

// находит ближайший вход в str1 любого символа из str2, включая \0
s21_size_t s21_strcspn(const char *str1, const char *str2);

// надо учитывать через макросы linux и macOS
char *s21_strerror(int errnum);
void s21_nulled(char *err_str);

// обычная конкатенация, без n
// сделал для strerror
char *s21_strcat(char *dest, const char *src);

char *s21_errnum_string(int errnum, char *err_str);

// находит первое вхождение любого из символов str2 в str1 не включая \0
char *s21_strpbrk(const char *str1, const char *str2);

// находит последнее вхождение символа c, включает \0
char *s21_strrchr(const char *str, int c);

// находит вхождение подстроки needle в haystack
char *s21_strstr(const char *haystack, const char *needle);
// по заданным разделителям разбивает строку str. Возвращает на строку после
// указателя. В самой str заместно разделителя ставит \0
char *s21_strtok(char *str, const char *delim);

// возвращает копию строки в верхнем регистре
void *s21_to_upper(const char *str);

// возвращает копию строки в нижнем регистре
void *s21_to_lower(const char *str);

// src - заданная строка, в нее с start_index вставляется строка str
void *s21_insert(const char *src, const char *str, s21_size_t start_index);

void *s21_trim(const char *src, const char *trim_chars);

// функция проверяет наличие ch в str
// нужна для s21_trim
int s21_in_str(const char *ch, const char *str);

int s21_sprintf(char *str, const char *format, ...);

int s21_sscanf(const char *string, const char *fmt, ...);
#endif  // S21_STRING_H