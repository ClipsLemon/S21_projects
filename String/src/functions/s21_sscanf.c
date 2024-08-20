#include "s21_string.h"
/**
 * @brief Реализация функции sscanf
 *
 * @param str Входная строка
 * @param format Интерпретация формата
 * @param ... Указатели на переменные, в которые будут сохранены данные из
 * строки
 *
 * @return Количество разобранных элементов
 */

int s21_tolower(int c) {
  if (c >= 'A' && c <= 'Z') {
    return c + ('a' - 'A');
  } else {
    return c;
  }
}

int read_int(const char *str, void *result, int width, char length) {
  int *int_result = (int *)result;
  *int_result = 0;
  int count = 0;
  int sign = 1;

  // Пропускаем начальные символы и учитываем знак
  while (str[count] != '\0' &&
         (!isdigit(str[count]) && str[count] != '-' && str[count] != '+')) {
    count++;
  }

  // Учитываем знак
  if (str[count] == '-') {
    sign = -1;
    count++;
  } else if (str[count] == '+') {
    count++;
  }

  // Считываем цифры, пока не достигнем конца строки или заданной ширины
  int digitCount = 0;

  // Учитываем флаги длины
  if (length == 'h') {
    // Для short int
    short int *short_result = (short int *)result;
    while (isdigit(str[count]) && (digitCount < width || width == 0)) {
      *short_result = *short_result * 10 + str[count] - '0';
      count++;
      digitCount++;
    }
    *short_result *= sign;
  } else if (length == 'l') {
    // Для long int
    long int *long_result = (long int *)result;
    while (isdigit(str[count]) && (digitCount < width || width == 0)) {
      *long_result = *long_result * 10 + str[count] - '0';
      count++;
      digitCount++;
    }
    *long_result *= sign;
  } else {
    // Для обычного int
    while (isdigit(str[count]) && (digitCount < width || width == 0)) {
      *int_result = *int_result * 10 + str[count] - '0';
      count++;
      digitCount++;
    }
    *int_result *= sign;
  }

  return count;
}

int read_float(const char *str, void *result, int width, char length) {
  float *float_result = (float *)result;
  *float_result = 0.0;
  char buffer[100];  // Дополнительный буфер для чтения строки
  int i = 0;
  int sign = 1;

  // Пропускаем начальные символы и учитываем знак
  while (
      (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r') &&
      str[i] != '\0') {
    i++;
  }

  // Учитываем знак
  if (str[i] == '-') {
    sign = -1;
    i++;
  }

  // Считываем цифры, пока не достигнем конца строки или заданной ширины
  int digitCount = 0;
  while ((isdigit(str[i]) || str[i] == '.' || str[i] == 'e' || str[i] == 'E' ||
          str[i] == '-') &&
         (digitCount < width || width == 0)) {
    buffer[digitCount] = str[i];
    i++;
    digitCount++;
  }

  buffer[digitCount] = '\0';
  if (length == 'l') {
    double *double_result = (double *)result;
    *double_result = sign * atof(buffer);
  } else if (length == 'L') {
    long double *long_double_result = (long double *)result;
    *long_double_result = sign * atof(buffer);
  } else {
    *float_result = sign * atof(buffer);
  }

  return i;
}

int read_str(const char *str, char *result, int width) {
  int count = 0;

  // Пропускаем начальные пробелы и непечатные символы
  while (str[count] != '\0' && isspace(str[count])) {
    count++;
  }

  // Считываем символы, если необходимо
  int charCount = 0;
  while (str[count] != '\0' && !isspace(str[count]) &&
         (charCount < width || width == 0)) {
    result[charCount] = str[count];
    count++;
    charCount++;
  }

  // Добавляем завершающий символ
  result[charCount] = '\0';

  return count;
}

int read_char(const char *str, char *result, int width) {
  int count = 0;

  // Пропускаем начальные пробелы и непечатные символы
  while (str[count] != '\0' && isspace(str[count])) {
    count++;
  }

  // Считываем символ, если необходимо
  if (str[count] != '\0' && !isspace(str[count]) &&
      (width == 0 || count < width)) {
    *result = str[count];
    count++;
  }

  return count;
}

int read_uint(const char *str, void *result, int width, char length) {
  unsigned int *uint_result = (unsigned int *)result;
  *uint_result = 0;
  int count = 0;

  // Пропускаем начальные нецифровые символы
  while (str[count] != '\0' && !isdigit(str[count])) {
    count++;
  }

  // Считываем цифры, пока не достигнем конца строки или заданной ширины
  int digitCount = 0;

  // Учитываем флаги длины
  if (length == 'h') {
    unsigned short int *ushort_result = (unsigned short int *)result;
    while (str[count] != '\0' && isdigit(str[count]) &&
           (digitCount < width || width == 0)) {
      *ushort_result = *ushort_result * 10 + str[count] - '0';
      count++;
      digitCount++;
    }
  } else if (length == 'l') {
    unsigned long int *ulong_result = (unsigned long int *)result;
    while (str[count] != '\0' && isdigit(str[count]) &&
           (digitCount < width || width == 0)) {
      *ulong_result = *ulong_result * 10 + str[count] - '0';
      count++;
      digitCount++;
    }
  } else {
    while (str[count] != '\0' && isdigit(str[count]) &&
           (digitCount < width || width == 0)) {
      *uint_result = *uint_result * 10 + str[count] - '0';
      count++;
      digitCount++;
    }
  }

  return count;
}

int read_int_i(const char *str, void *result, int width, char length) {
  short int *short_result = (short int *)result;
  *short_result = 0;
  int count = 0;
  int sign = 1;

  // Пропускаем начальные символы и учитываем знак
  while (str[count] != '\0' &&
         (!isdigit(str[count]) && str[count] != '-' && str[count] != '+')) {
    count++;
  }

  // Учитываем знак
  if (str[count] == '-') {
    sign = -1;
    count++;
  } else if (str[count] == '+') {
    count++;
  }

  // Считываем цифры, пока не достигнем конца строки или заданной ширины
  int digitCount = 0;

  // Учитываем флаги длины
  if (length == 'h') {
    // Учитываем префикс (0x для шестнадцатеричных чисел)
    if (str[count] == '0' && (str[count + 1] == 'x' || str[count + 1] == 'X')) {
      count += 2;  // Пропускаем префикс
      while (isxdigit(str[count]) && (digitCount < width || width == 0)) {
        *short_result =
            *short_result * 16 + (isdigit(str[count])
                                      ? (str[count] - '0')
                                      : (s21_tolower(str[count]) - 'a' + 10));
        count++;
        digitCount++;
      }
    } else if (str[count] == '0') {
      count++;  // Пропускаем префикс "0" для восьмеричных чисел
      while (str[count] >= '0' && str[count] <= '7' &&
             (digitCount < width || width == 0)) {
        *short_result = *short_result * 8 + (str[count] - '0');
        count++;
        digitCount++;
      }
    } else {
      while (isdigit(str[count]) && (digitCount < width || width == 0)) {
        *short_result = *short_result * 10 + str[count] - '0';
        count++;
        digitCount++;
      }
    }
    *short_result *= sign;
  } else if (length == 'l') {
    long int *long_result = (long int *)result;
    // Учитываем префикс (0x для шестнадцатеричных чисел)
    if (str[count] == '0' && (str[count + 1] == 'x' || str[count + 1] == 'X')) {
      count += 2;  // Пропускаем префикс
      while (isxdigit(str[count]) && (digitCount < width || width == 0)) {
        *long_result =
            *long_result * 16 + (isdigit(str[count])
                                     ? (str[count] - '0')
                                     : (s21_tolower(str[count]) - 'a' + 10));
        count++;
        digitCount++;
      }
    } else if (str[count] == '0') {
      count++;  // Пропускаем префикс "0" для восьмеричных чисел
      while (str[count] >= '0' && str[count] <= '7' &&
             (digitCount < width || width == 0)) {
        *long_result = *long_result * 8 + (str[count] - '0');
        count++;
        digitCount++;
      }
    } else {
      while (isdigit(str[count]) && (digitCount < width || width == 0)) {
        *long_result = *long_result * 10 + str[count] - '0';
        count++;
        digitCount++;
      }
    }
    *long_result *= sign;
  } else {
    int *int_result = (int *)result;
    // Учитываем префикс (0x для шестнадцатеричных чисел)
    if (str[count] == '0' && (str[count + 1] == 'x' || str[count + 1] == 'X')) {
      count += 2;  // Пропускаем префикс
      while (isxdigit(str[count]) && (digitCount < width || width == 0)) {
        *int_result =
            *int_result * 16 + (isdigit(str[count])
                                    ? (str[count] - '0')
                                    : (s21_tolower(str[count]) - 'a' + 10));
        count++;
        digitCount++;
      }
    } else if (str[count] == '0') {
      count++;  // Пропускаем префикс "0" для восьмеричных чисел
      while (str[count] >= '0' && str[count] <= '7' &&
             (digitCount < width || width == 0)) {
        *int_result = *int_result * 8 + (str[count] - '0');
        count++;
        digitCount++;
      }
    } else {
      while (isdigit(str[count]) && (digitCount < width || width == 0)) {
        *int_result = *int_result * 10 + str[count] - '0';
        count++;
        digitCount++;
      }
    }
    *int_result *= sign;
  }

  return count;
}

int read_float_g(const char *str, void *result, int width, char length) {
  int i = 0;
  int sign = 1;
  char buffer[100];

  while (
      (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r') &&
      str[i] != '\0') {
    i++;
  }

  if (str[i] == '-') {
    sign = -1;
    i++;
  }

  int digitCount = 0;
  while ((isdigit(str[i]) || str[i] == '.' || str[i] == 'e' || str[i] == 'E' ||
          str[i] == '-') &&
         (digitCount < width || width == 0)) {
    buffer[digitCount] = str[i];
    i++;
    digitCount++;
  }

  buffer[digitCount] = '\0';
  if (length == 'l') {
    double *double_result = (double *)result;
    *double_result = sign * atof(buffer);
  } else if (length == 'L') {
    long double *long_double_result = (long double *)result;
    *long_double_result = sign * atof(buffer);
  } else {
    float *float_result = (float *)result;
    *float_result = sign * atof(buffer);
  }

  return i;
}

int read_oct(const char *str, void *result, int width, char length) {
  unsigned int *oct_result = (unsigned int *)result;
  *oct_result = 0;
  int count = 0;

  // Пропускаем начальные нецифровые символы
  while (str[count] != '\0' && !isdigit(str[count])) {
    count++;
  }

  // Считываем цифры, пока не достигнем конца строки или заданной ширины
  int digitCount = 0;

  // Учитываем флаги длины
  if (length == 'h') {
    unsigned short int *short_oct_result = (unsigned short int *)result;
    while (str[count] != '\0' && (str[count] >= '0' && str[count] <= '7') &&
           (digitCount < width || width == 0)) {
      *short_oct_result = (*short_oct_result * 8) + (str[count] - '0');
      count++;
      digitCount++;
    }
  } else if (length == 'l') {
    unsigned long int *long_oct_result = (unsigned long int *)result;
    while (str[count] != '\0' && (str[count] >= '0' && str[count] <= '7') &&
           (digitCount < width || width == 0)) {
      *long_oct_result = (*long_oct_result * 8) + (str[count] - '0');
      count++;
      digitCount++;
    }
  } else {
    while (str[count] != '\0' && (str[count] >= '0' && str[count] <= '7') &&
           (digitCount < width || width == 0)) {
      *oct_result = (*oct_result * 8) + (str[count] - '0');
      count++;
      digitCount++;
    }
  }

  return count;
}

int read_hex(const char *str, void *result, int width, char length) {
  unsigned int *hex_result = (unsigned int *)result;
  *hex_result = 0;
  int count = 0;

  // Пропускаем начальные нецифровые символы
  while (str[count] != '\0' && !isxdigit(str[count])) {
    count++;
  }

  // Считываем шестнадцатеричные цифры, пока не достигнем конца строки
  int digitCount = 0;

  // Учитываем флаги длины
  if (length == 'h') {
    unsigned short int *ushort_result = (unsigned short int *)result;
    while (str[count] != '\0' && isxdigit(str[count]) &&
           (digitCount < width || width == 0)) {
      *ushort_result =
          (*ushort_result << 4) |
          (isdigit(str[count]) ? (str[count] - '0')
                               : (s21_tolower(str[count]) - 'a' + 10));
      count++;
      digitCount++;
    }
  } else if (length == 'l') {
    unsigned long int *ulong_result = (unsigned long int *)result;
    while (str[count] != '\0' && isxdigit(str[count]) &&
           (digitCount < width || width == 0)) {
      *ulong_result =
          (*ulong_result << 4) |
          (isdigit(str[count]) ? (str[count] - '0')
                               : (s21_tolower(str[count]) - 'a' + 10));
      count++;
      digitCount++;
    }
  } else {
    while (str[count] != '\0' && isxdigit(str[count]) &&
           (digitCount < width || width == 0)) {
      *hex_result =
          (*hex_result << 4) |
          (isdigit(str[count]) ? (str[count] - '0')
                               : (s21_tolower(str[count]) - 'a' + 10));
      count++;
      digitCount++;
    }
  }

  return count;
}

int hex_char_to_int(char hex) {
  if (isdigit(hex)) {
    return hex - '0';
  } else {
    return s21_tolower(hex) - 'a' + 10;
  }
}

int read_ptr(const char *str, void **result) {
  s21_size_t ptr_value = 0;

  // Пропускаем начальные пробелы и непечатные символы
  while (*str && isspace(*str)) {
    str++;
  }

  // Пропускаем префикс "0x"
  if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X')) {
    str += 2;
  }

  // Считываем шестнадцатеричные цифры
  while (*str && isxdigit(*str)) {
    ptr_value = ptr_value * 16 + hex_char_to_int(*str);
    str++;
  }

  *result = (void *)ptr_value;
  return str - (str - 1);  // Возвращаем количество считанных символов
}

int s21_sscanf(const char *string, const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);

  const char *str = string;
  const char *format = fmt;

  int charCount = 0;
  int argCount = 0;

  for (int i = 0; format[i] != '\0'; i++) {
    if (format[i] != '%') {
      if (str[charCount] != format[i]) {
        va_end(args);
        exit(1);
      } else {
        charCount++;
      }
    } else {
      FormatInf token;
      token.flag = false;
      token.width = 0;
      token.accuracy = -1;
      token.length = '\0';

      i++;  // Переходим к следующему символу после %

      while (format[i] == '+' || format[i] == '-' || format[i] == '0' ||
             format[i] == ' ' || format[i] == '#') {
        token.flag = true;
        i++;
      }

      // Проверка ширины
      if (format[i] >= '1' && format[i] <= '9') {
        token.width = format[i] - '0';
        i++;
        // Если ширина больше 9
        while (format[i] >= '0' && format[i] <= '9') {
          token.width = token.width * 10 + format[i] - '0';
          i++;
        }
      }

      // Проверка точности
      if (format[i] == '.') {
        i++;
        if (format[i] >= '0' && format[i] <= '9') {
          token.accuracy = format[i] - '0';
          i++;

          // Если точность больше 9
          while (format[i] >= '0' && format[i] <= '9') {
            token.accuracy = token.accuracy * 10 + format[i] - '0';
            i++;
          }
        } else {
          token.accuracy = 0;
        }
      }

      // Проверка длины
      if (format[i] == 'h' || format[i] == 'l' || format[i] == 'L') {
        token.length = format[i];
        i++;
      }

      token.specifier = format[i];

      //  обработка спецификаторов
      switch (token.specifier) {
        case 'd': {
          charCount += read_int(&str[charCount], va_arg(args, void *),
                                token.width, token.length);
          break;
        }
        case 's': {
          char *result_str = va_arg(args, char *);
          charCount += read_str(&str[charCount], result_str, token.width);
          break;
        }
        case 'c': {
          char *result_char = va_arg(args, char *);
          charCount += read_char(&str[charCount], result_char, token.width);
          break;
        }
        case 'f': {
          charCount += read_float(&str[charCount], va_arg(args, void *),
                                  token.width, token.length);
          break;
        }
        case 'u': {
          charCount += read_uint(&str[charCount], va_arg(args, void *),
                                 token.width, token.length);
          break;
        }
        case 'i': {
          charCount += read_int_i(&str[charCount], va_arg(args, void *),
                                  token.width, token.length);
          break;
        }
        case 'e': {
          charCount += read_float(&str[charCount], va_arg(args, void *),
                                  token.width, token.length);
          break;
        }
        case 'E': {
          charCount += read_float(&str[charCount], va_arg(args, void *),
                                  token.width, token.length);
          break;
        }
        case 'g': {
          charCount += read_float_g(&str[charCount], va_arg(args, void *),
                                    token.width, token.length);
          break;
        }
        case 'G': {
          charCount += read_float_g(&str[charCount], va_arg(args, void *),
                                    token.width, token.length);
          break;
        }
        case 'o': {
          charCount += read_oct(&str[charCount], va_arg(args, void *),
                                token.width, token.length);
          break;
        }
        case 'x': {
          charCount += read_hex(&str[charCount], va_arg(args, void *),
                                token.width, token.length);
          break;
        }
        case 'X': {
          charCount += read_hex(&str[charCount], va_arg(args, void *),
                                token.width, token.length);
          break;
        }
        case 'p': {
          void **result_ptr = va_arg(args, void **);
          charCount += read_ptr(&str[charCount], result_ptr);
          break;
        }
        case 'n': {
          int *result_count = va_arg(args, int *);
          *result_count = charCount;
          break;
        }
        case '%': {
          // Проверяем наличие следующего символа %
          if (str[charCount] == '%') {
            charCount++;
          } else {
            // Обнаружена ошибка формата
            va_end(args);
            exit(-1);
          }
          break;
        }
        default: {
          va_end(args);
          exit(-1);
        }
      }

      argCount++;
    }
  }

  va_end(args);
  return argCount;
}