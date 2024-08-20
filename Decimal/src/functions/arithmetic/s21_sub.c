#include "s21_decimal.h"

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int code = 0;
  if (s21_is_empty_decimal(&value_1) && s21_is_empty_decimal(&value_2) &&
      (!s21_check_sign(&value_1) && !s21_check_sign(&value_2))) {
    s21_reset_dec(result);
  } else if (s21_is_empty_decimal(&value_1) && s21_is_empty_decimal(&value_2) &&
             (s21_check_sign(&value_1) && !s21_check_sign(&value_2))) {
    s21_reset_dec(result);
    s21_set_bit(result, BIT_SIGN);
  } else {
    s21_big_decimal big_value_1 = s21_from_dec_to_big_dec(value_1);
    s21_big_decimal big_value_2 = s21_from_dec_to_big_dec(value_2);
    s21_big_decimal big_result;

    s21_big_sub(big_value_1, big_value_2, &big_result);
    code = s21_from_big_dec_to_dec(big_result, result);
  }
  return code;
}

int s21_simp_sub(s21_big_decimal value_1, s21_big_decimal value_2,
                 s21_big_decimal *result) {
  s21_big_decimal temp;
  s21_reset_big_dec(&temp);
  for (int i = 0; i < BIG_DEC_NUMBER_SIZE; i++) {
    if (s21_is_set_bit_big_dec(&value_2, i))
      s21_reset_bit_big_dec(&temp, i);
    else
      s21_set_bit_big_dec(&temp, i);
  }
  s21_set_scale_big_dec(&temp, s21_get_scale_big_dec(&value_2));
  s21_big_add(value_1, temp, result);
  s21_reset_big_dec(&temp);
  s21_set_scale_big_dec(&temp, s21_get_scale_big_dec(&value_2));
  temp.bits[0] = 1;
  s21_big_add(*result, temp, result);
  return 0;
}

// --------------------------------------------------------------------
//                    Вычитание в s21_big_decimal
// --------------------------------------------------------------------
void s21_big_sub(s21_big_decimal value_1, s21_big_decimal value_2,
                 s21_big_decimal *result) {
  // Обнуление результирующей переменной
  s21_reset_big_dec(result);

  // Выравнивание по запятой
  s21_set_scale_big_dec(result, s21_align_scale(&value_1, &value_2));

  // Сохраняем и сбрасываем знаки чисел для корректного сравнения по модулю
  int minus_v1 = s21_check_sign_big_dec(&value_1);
  s21_reset_bit_big_dec(&value_1, BIG_DEC_BIT_SIGN);
  int minus_v2 = s21_check_sign_big_dec(&value_2);
  s21_reset_bit_big_dec(&value_2, BIG_DEC_BIT_SIGN);

  if (!minus_v1 && minus_v2) {
    // От положительного отнимаем отрицательное: (x)-(-y) -> (z)
    s21_big_add(value_1, value_2, result);
  } else if (minus_v1 && !minus_v2) {
    // От отрицательного отнимаем положительное: (-x)-(y) -> (-z)
    s21_big_add(value_1, value_2, result);
    s21_set_bit_big_dec(result, BIG_DEC_BIT_SIGN);
  } else if (!s21_big_dec_is_less(value_1, value_2)) {
    if (minus_v1 && minus_v2) {
      // От отрицательного отнимаем отрицательное: (-x)-(-y) -> (-z)
      s21_simp_sub(value_1, value_2, result);
      s21_set_bit_big_dec(result, BIG_DEC_BIT_SIGN);
    } else if (!minus_v1 && !minus_v2) {
      // От положительного отнимаем положительное: (x)-(y) -> (z)
      s21_simp_sub(value_1, value_2, result);
    }
  } else {
    if (minus_v1 && minus_v2) {
      // От отрицательного отнимаем отрицательное: (-x)-(-y) -> (z)
      s21_simp_sub(value_2, value_1, result);
    } else if (!minus_v1 && !minus_v2) {
      // От положительного отнимаем положительное: (x)-(y) -> (-z)
      s21_simp_sub(value_2, value_1, result);
      s21_set_bit_big_dec(result, BIG_DEC_BIT_SIGN);
    }
  }
  if (s21_is_empty_big_decimal(result)) {
    s21_reset_big_dec(result);
    if (minus_v1) s21_set_bit_big_dec(result, BIG_DEC_BIT_SIGN);
  }
}
