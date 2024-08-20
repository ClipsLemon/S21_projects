#include "s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  int code = 0;
  // если оба равны нулю по модулю
  if (s21_is_empty_decimal(&value_1) && s21_is_empty_decimal(&value_2)) {
    s21_reset_dec(result);
    if (s21_check_sign(&value_1)) {
      (*result).bits[3] = value_1.bits[3];
    } else if (s21_check_sign(&value_2)) {
      (*result).bits[3] = value_2.bits[3];
    }
  } else {
    s21_big_decimal big_value_1 = s21_from_dec_to_big_dec(value_1);
    s21_big_decimal big_value_2 = s21_from_dec_to_big_dec(value_2);
    s21_big_decimal big_result;

    s21_big_add(big_value_1, big_value_2, &big_result);
    code = s21_from_big_dec_to_dec(big_result, result);
  }
  return code;
}

// --------------------------------------------------------------------
//                    Сложение в s21_big_decimal
// --------------------------------------------------------------------
void s21_big_add(s21_big_decimal value_1, s21_big_decimal value_2,
                 s21_big_decimal* result) {
  // Обнуление результирующей переменной
  s21_reset_big_dec(result);

  // Выравнивание по запятой
  s21_set_scale_big_dec(result, s21_align_scale(&value_1, &value_2));

  // Сохраняем и сбрасываем знаки чисел для корректного сравнения по модулю
  int minus_v1 = s21_check_sign_big_dec(&value_1);
  s21_reset_bit_big_dec(&value_1, BIG_DEC_BIT_SIGN);
  int minus_v2 = s21_check_sign_big_dec(&value_2);
  s21_reset_bit_big_dec(&value_2, BIG_DEC_BIT_SIGN);

  if (minus_v1 == minus_v2) {
    // Установка того же знака в результат
    if (minus_v1)
      s21_set_bit_big_dec(result, BIG_DEC_BIT_SIGN);
    else
      s21_reset_bit_big_dec(result, BIG_DEC_BIT_SIGN);

    // Сложение
    for (int i = 0; i < BIG_DEC_NUMBER_SIZE; i++) {
      int comb = s21_is_set_bit_big_dec(&value_1, i) +
                 s21_is_set_bit_big_dec(&value_2, i) +
                 s21_is_set_bit_big_dec(result, i);
      switch (comb) {
        case 3:
          s21_set_bit_big_dec(result, i);
          s21_set_bit_big_dec(result, i + 1);
          break;
        case 2:
          s21_reset_bit_big_dec(result, i);
          s21_set_bit_big_dec(result, i + 1);
          break;
        case 1:
          s21_set_bit_big_dec(result, i);
          break;
        default:
          s21_reset_bit_big_dec(result, i);
          break;
      }
    }
  } else {
    // Вычитание меньшего из большего и запись знака большего в результат
    if (s21_big_dec_is_equal(value_1, value_2)) {
      s21_reset_big_dec(result);
    } else if (s21_big_dec_is_greater(value_1, value_2)) {
      s21_simp_sub(value_1, value_2, result);

      if (minus_v1)
        s21_set_bit_big_dec(result, BIG_DEC_BIT_SIGN);
      else
        s21_reset_bit_big_dec(result, BIG_DEC_BIT_SIGN);
    } else {
      s21_simp_sub(value_2, value_1, result);

      if (minus_v2)
        s21_set_bit_big_dec(result, BIG_DEC_BIT_SIGN);
      else
        s21_reset_bit_big_dec(result, BIG_DEC_BIT_SIGN);
    }
  }
}