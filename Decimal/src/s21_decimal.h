#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#include <limits.h>
#include <math.h>
#include <stddef.h>  // NULL
#include <stdio.h>
#include <stdlib.h>

//----------------------ЛОГИЧЕСКИЕ КОНСТАНТЫ----------------------------

#define TRUE 1
#define FALSE 0

//----------------------ЗНАКОВЫЕ КОНСТАНТЫ----------------------------

#define S21_POSITIVE 0
#define S21_NEGATIVE 1

//----------------------КОНСТАНТЫ ДРУГИХ ФУНКЦИЙ ----------------------------

#define S21_OTHER_OK 0
#define S21_OTHER_ERROR 1

//----------------------РАЗМЕРНЫЕ КОНСТАНТЫ----------------------------

#define BYTE_SIZE 32    // размер байта
#define DEC_SIZE 128    // размер decimal
#define NUMBER_SIZE 96  // размер целой части

#define BIG_DEC_NUMBER_SIZE 192  // размер целой части

//----------------------ПОЗИЦИОННЫЕ КОНСТАНТЫ----------------------------

#define BIT_SIGN 127     // бит знака
#define SCALE_END 119    // старший бит
#define SCALE_START 112  // младший бит

#define BIG_DEC_BIT_SIGN 223
#define BIG_DEC_SCALE_START 208
#define BIG_DEC_SCALE_END 215

//----------------------ПРОЧИЕ КОНСТАНТЫ----------------------------
#define S21_NULL ((void *)0)

// 128 bit
typedef struct {
  int bits[4];
} s21_decimal;

// 224 bit
typedef struct {
  int bits[7];
} s21_big_decimal;

#define MAX_FLOAT_TO_CONVERT 79228157791897854723898736640.0f
#define MIN_FLOAT_TO_CONVERT \
  0.00000000000000000000000000010000000031710768509710513471352647538147514756461109f

//----------------------ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ----------------------------

int s21_get_col(int index);
int s21_get_row(int index);

int s21_check_sign(s21_decimal *num_ptr);
int s21_check_sign_big_dec(s21_big_decimal *num_ptr);

int s21_is_set_bit_int(int *ptr_num, int index);
int s21_is_set_bit_dec(s21_decimal *ptr_dec_num, int index);
int s21_is_set_bit_big_dec(s21_big_decimal *ptr_dec_num, int index);

// Сдвиг мантиссы влево на бит
int s21_big_left_shift(s21_big_decimal *val);
int s21_left_shift(s21_decimal *val);

void s21_set_bit(s21_decimal *ptr_dec_num, int index);
void s21_set_bit_big_dec(s21_big_decimal *ptr_dec_num, int index);
void s21_set_bit_int(int *ptr_num, int index);

void s21_inverse_bit(s21_decimal *ptr_dec_num, int index);

void s21_reset_bit(s21_decimal *ptr_dec_num, int index);
void s21_reset_bit_big_dec(s21_big_decimal *ptr_dec_num, int index);

void s21_reset_dec(s21_decimal *val);
void s21_reset_big_dec(s21_big_decimal *val);

// пере из децимал в биг децимал
s21_big_decimal s21_from_dec_to_big_dec(s21_decimal decimal);

int s21_from_big_dec_to_dec(s21_big_decimal big_decimal, s21_decimal *decimal);

/**
 * @brief Принимает int степень 10 и записывает ее в decimal
 *
 * @param point - степень, которая будет записана в битовом представлении
 */
void s21_set_scale(s21_decimal *number, int point);
void s21_set_scale_big_dec(s21_big_decimal *number, int point);

// функция возвращает степень decimal числа
int s21_get_scale(s21_decimal *number);
int s21_get_scale_big_dec(s21_big_decimal *number);

void s21_big_dec_arg_aligment(s21_big_decimal *first, s21_big_decimal *second);
void s21_big_argument_aligment(s21_decimal *first, s21_decimal *second);
int s21_align_scale(s21_big_decimal *value_1, s21_big_decimal *value_2);

// Простейшее вычитание (только натуральные числа, только от большего меньшее)
int s21_simp_sub(s21_big_decimal value_1, s21_big_decimal value_2,
                 s21_big_decimal *result);

// Умножение числа типа s21_decimal на 10
void s21_big_mul_ten(s21_big_decimal *val);
void s21_mul_ten(s21_decimal *val);

int s21_big_dec_get_not_zero_bit_left(s21_big_decimal decimal);

s21_big_decimal s21_big_dec_abs(s21_big_decimal big_decimal);

s21_big_decimal s21_big_binary_division(s21_big_decimal decimal_1,
                                        s21_big_decimal decimal_2,
                                        s21_big_decimal *remains);

s21_big_decimal s21_big_decimal_to_pow(int scale);

int s21_is_empty_big_decimal(const s21_big_decimal *value);
int s21_is_empty_decimal(const s21_decimal *value);

//----------------------ФУНКЦИИ СРАВНЕНИЯ----------------------------

int s21_is_less(s21_decimal first, s21_decimal second);
int s21_is_less_or_equal(s21_decimal first, s21_decimal second);
int s21_is_greater(s21_decimal first, s21_decimal second);
int s21_is_greater_or_equal(s21_decimal first, s21_decimal second);
int s21_is_equal(s21_decimal first, s21_decimal second);
int s21_is_not_equal(s21_decimal first, s21_decimal second);

int s21_big_dec_is_less(s21_big_decimal first, s21_big_decimal second);
int s21_big_dec_is_equal(s21_big_decimal first, s21_big_decimal second);
int s21_big_dec_is_not_equal(s21_big_decimal first, s21_big_decimal second);
int s21_big_dec_is_greater(s21_big_decimal first, s21_big_decimal second);

//----------------------ФУНКЦИИ ПРЕОБРАЗОВАНИЯ ТИПОВ----------------------------

int s21_from_decimal_to_float(s21_decimal src, float *dst);
void s21_bank_round(s21_big_decimal *value, s21_big_decimal *fractional);

//----------------------ДРУГИЕ ФУНКЦИИ----------------------------

int s21_negate(s21_decimal value, s21_decimal *result);
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);

//----------------------АРИФМЕТИЧЕСКИЕ ФУНКЦИИ----------------------------

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

void s21_big_add(s21_big_decimal value_1, s21_big_decimal value_2,
                 s21_big_decimal *result);
void s21_big_sub(s21_big_decimal value_1, s21_big_decimal value_2,
                 s21_big_decimal *result);
void s21_big_mul(s21_big_decimal value_1, s21_big_decimal value_2,
                 s21_big_decimal *result);
//--------------------------ПРЕОБРАЗОВАТЕЛИ-------------------------------

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

s21_decimal s21_decimal_get_int_min();

s21_decimal s21_decimal_get_int_max();

s21_decimal s21_decimal_get_inf();

s21_decimal s21_abs_decimal(s21_decimal decimal);

int s21_is_decimal_correct(s21_decimal decimal);

//----------------------ДОПОЛНИТЕЛЬНЫЕ ФУНКЦИИ----------------------------
// void printDecimal(s21_decimal *num);

// void printBigDecimal(s21_big_decimal *num);

// void printSimpleDecimal(s21_decimal *num);

// void printSimpleBigDecimal(s21_big_decimal *num);

// задает  случайную последовательность битов для каждого числа
// void setDiffRandomNumber(s21_decimal *first, s21_decimal *second);

// // задает случайную последовательность битов для обоих чисел
// void setEqRandomNumber(s21_decimal *first, s21_decimal *second);

// // выводит int в двоичном виде
// void printIntToBinary(int number);

// char *decimalToString(s21_decimal decimal);
// char *bigDecimalToString(s21_big_decimal decimal);

// char *decimalToString(s21_decimal decimal);

#endif  // S21_DECIMAL_H