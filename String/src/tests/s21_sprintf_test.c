#include "s21_tests.h"

#define STR_SIZE 512

// INDIVIDUAL TEST
START_TEST(s21_sprintf_c_test) {  // 0 <= char <= 127
  char str[STR_SIZE];
  char s21_str[STR_SIZE];

  // original
  sprintf(str, "%c %c %c %c %c %c %c %c %c %c %10c %-10c", '1', '0', '9', '~',
          ' ', 127, 46, 45, 29, 32, 50, 98);
  // s21
  s21_sprintf(s21_str, "%c %c %c %c %c %c %c %c %c %c %10c %-10c", '1', '0',
              '9', '~', ' ', 127, 46, 45, 29, 32, 50, 98);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(s21_sprintf_d_test) {
  char str[STR_SIZE];
  char s21_str[STR_SIZE];

  // original
  sprintf(str, "%d %d %d %d %d %d %d %d %d %d %d %d %d", '1', '0', '9', '~',
          ' ', 127, 46, 45, 29, 32, -INT_MAX, 0, INT_MAX);
  // s21
  s21_sprintf(s21_str, "%d %d %d %d %d %d %d %d %d %d %d %d %d", '1', '0', '9',
              '~', ' ', 127, 46, 45, 29, 32, -INT_MAX, 0, INT_MAX);
  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(s21_sprintf_i_test) {
  char str_oct[STR_SIZE];
  char str_hex[STR_SIZE];

  char s21_str_oct[STR_SIZE];
  char s21_str_hex[STR_SIZE];

  // octal
  // original
  sprintf(str_oct, "%i %i %i %i %i %i %i %i %i %i %i %i %i", 061, 060, 071,
          0176, 040, 0177, 056, 055, 035, 043, -017777777777, 00, 017777777777);
  // s21
  s21_sprintf(s21_str_oct, "%i %i %i %i %i %i %i %i %i %i %i %i %i", 061, 060,
              071, 0176, 040, 0177, 056, 055, 035, 043, -017777777777, 00,
              017777777777);
  // hexadecimal
  // original
  sprintf(str_hex, "%i %i %i %i %i %i %i %i %i %i %i %i %i", 0x31, 0x30, 0x39,
          0x7E, 0x20, 0x7F, 0x2E, 0x2D, 0x1D, 0x23, -0x7FFFFFFF, 0x0,
          0x7FFFFFFF);
  // s21
  s21_sprintf(s21_str_hex, "%i %i %i %i %i %i %i %i %i %i %i %i %i", 0x31, 0x30,
              0x39, 0x7E, 0x20, 0x7F, 0x2E, 0x2D, 0x1D, 0x23, -0x7FFFFFFF, 0x0,
              0x7FFFFFFF);

  ck_assert_str_eq(str_oct, s21_str_oct);
  ck_assert_str_eq(str_hex, s21_str_hex);
}
END_TEST

START_TEST(s21_sprintf_e_test) {
  char str_e[STR_SIZE];
  char str_E[STR_SIZE];

  char s21_str_e[STR_SIZE];
  char s21_str_E[STR_SIZE];
  // e
  // original
  sprintf(str_e, "%e %e %e %e %e %e %e %e %e %e %e %e %e", 0.2123,
          2147483647.99, -11235923.29273472, 231.00002, 0.0, -0.0, -1.0,
          8488388.2234, 11111.11111, 929.99999, INFINITY, -INFINITY, NAN);
  sprintf(str_E, "%E %E %E %E %E %E %E %E %E %E %E %E %E", 0.2123,
          2147483647.99, -11235923.29273472, 231.00002, 0.0, -0.0, -1.0,
          8488388.2234, 11111.11111, 929.99999, INFINITY, -INFINITY, NAN);
  // s21
  s21_sprintf(s21_str_e, "%e %e %e %e %e %e %e %e %e %e %e %e %e", 0.2123,
              2147483647.99, -11235923.29273472, 231.00002, 0.0, -0.0, -1.0,
              8488388.2234, 11111.11111, 929.99999, INFINITY, -INFINITY, NAN);
  s21_sprintf(s21_str_E, "%E %E %E %E %E %E %E %E %E %E %E %E %E", 0.2123,
              2147483647.99, -11235923.29273472, 231.00002, 0.0, -0.0, -1.0,
              8488388.2234, 11111.11111, 929.99999, INFINITY, -INFINITY, NAN);
  ck_assert_str_eq(str_e, s21_str_e);
  ck_assert_str_eq(str_E, s21_str_E);
}

START_TEST(s21_sprintf_f_test) {
  char str[STR_SIZE];
  char s21_str[STR_SIZE];

  // original
  sprintf(str, "%f %f %f %f %f %f %f %f %f %f %f %f %f", 0.2123, 2147483647.99,
          -11235923.29273472, 231.00002, 0.0, -0.0, -1.0, 8488388.2234,
          11111.11111, 929.99999, INFINITY, -INFINITY, NAN);
  // s21
  s21_sprintf(s21_str, "%f %f %f %f %f %f %f %f %f %f %f %f %f", 0.2123,
              2147483647.99, -11235923.29273472, 231.00002, 0.0, -0.0, -1.0,
              8488388.2234, 11111.11111, 929.99999, INFINITY, -INFINITY, NAN);
  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(s21_sprintf_g_test) {
  char str_g[STR_SIZE];
  char s21_str_g[STR_SIZE];

  char str_G[STR_SIZE];
  char s21_str_G[STR_SIZE];

  // g
  // original
  sprintf(str_g, "%g %g %g %g %g %g %g %g %g %g %g %g %g", 0.2123,
          2147483647.99, -11235923.29273472, 231.00002, 0.0, -0.0, -1.0,
          8488388.2234, 11111.11111, 929.99999, INFINITY, -INFINITY, NAN);
  sprintf(str_G, "%G %G %G %G %G %G %G %G %G %G %G %G %G", 0.2123,
          2147483647.99, -11235923.29273472, 231.00002, 0.0, -0.0, -1.0,
          8488388.2234, 11111.11111, 929.99999, INFINITY, -INFINITY, NAN);
  // s21
  s21_sprintf(s21_str_g, "%g %g %g %g %g %g %g %g %g %g %g %g %g", 0.2123,
              2147483647.99, -11235923.29273472, 231.00002, 0.0, -0.0, -1.0,
              8488388.2234, 11111.11111, 929.99999, INFINITY, -INFINITY, NAN);
  s21_sprintf(s21_str_G, "%G %G %G %G %G %G %G %G %G %G %G %G %G", 0.2123,
              2147483647.99, -11235923.29273472, 231.00002, 0.0, -0.0, -1.0,
              8488388.2234, 11111.11111, 929.99999, INFINITY, -INFINITY, NAN);
  ck_assert_str_eq(str_g, s21_str_g);
  ck_assert_str_eq(str_G, s21_str_G);
}
END_TEST

START_TEST(s21_sprintf_o_test) {
  char str[STR_SIZE];
  char s21_str[STR_SIZE];
  // original
  sprintf(str, "%o %o %o %o %o %o %o %o %o %o %o %o %o", '1', '0', '9', '~',
          ' ', 127, 46, 45, 29, 32, 0, UINT_MAX, -92394);
  // s21
  s21_sprintf(s21_str, "%o %o %o %o %o %o %o %o %o %o %o %o %o", '1', '0', '9',
              '~', ' ', 127, 46, 45, 29, 32, 0, UINT_MAX, -92394);
  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(s21_sprintf_s_test) {
  char str_1[STR_SIZE];
  char str_2[STR_SIZE];

  char s21_str_1[STR_SIZE];
  char s21_str_2[STR_SIZE];

  // original
  sprintf(str_1, "%s %s %s %10s %-10s", "Example number one,",
          "example number two,", "exmaple number three.", "four example",
          "five example");
  sprintf(str_2, "%s",
          "1234567890-=~!@#$%^&*()_+qwertyuiop[]\\asdfghjkl;\'zxcvbnm,./"
          "QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?");
  // s21
  s21_sprintf(s21_str_1, "%s %s %s %10s %-10s", "Example number one,",
              "example number two,", "exmaple number three.", "four example",
              "five example");
  s21_sprintf(s21_str_2, "%s",
              "1234567890-=~!@#$%^&*()_+qwertyuiop[]\\asdfghjkl;\'zxcvbnm,./"
              "QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?");

  ck_assert_str_eq(str_1, s21_str_1);
  ck_assert_str_eq(str_2, s21_str_2);
}
END_TEST

START_TEST(s21_sprintf_u_test) {
  char str[STR_SIZE];
  char s21_str[STR_SIZE];
  // original
  sprintf(str, "%u %u %u %u %u %u %u %u %u %u %u %u %u %u %u %u", '1', '0', '9',
          '~', ' ', 127, 46, 45, 29, 32, 0, UINT_MAX, -92394, -0, -1,
          -UINT_MAX);
  // s21
  s21_sprintf(s21_str, "%u %u %u %u %u %u %u %u %u %u %u %u %u %u %u %u", '1',
              '0', '9', '~', ' ', 127, 46, 45, 29, 32, 0, UINT_MAX, -92394, -0,
              -1, -UINT_MAX);
  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(s21_sprintf_x_test) {
  char str_x[STR_SIZE];
  char s21_str_x[STR_SIZE];

  char str_X[STR_SIZE];
  char s21_str_X[STR_SIZE];

  // original
  sprintf(str_x, "%x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x", '1', '0',
          '9', '~', ' ', 127, 46, 45, 29, 32, 0, UINT_MAX, -92394, -0, -1,
          -UINT_MAX);
  sprintf(str_X, "%X %X %X %X %X %X %X %X %X %X %X %X %X %X %X %X", '1', '0',
          '9', '~', ' ', 127, 46, 45, 29, 32, 0, UINT_MAX, -92394, -0, -1,
          -UINT_MAX);
  // s21
  s21_sprintf(s21_str_x, "%x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x", '1',
              '0', '9', '~', ' ', 127, 46, 45, 29, 32, 0, UINT_MAX, -92394, -0,
              -1, -UINT_MAX);
  s21_sprintf(s21_str_X, "%X %X %X %X %X %X %X %X %X %X %X %X %X %X %X %X", '1',
              '0', '9', '~', ' ', 127, 46, 45, 29, 32, 0, UINT_MAX, -92394, -0,
              -1, -UINT_MAX);
  ck_assert_str_eq(str_x, s21_str_x);
  ck_assert_str_eq(str_X, s21_str_X);
}
END_TEST

START_TEST(s21_sprintf_p_test) {
  int int_num = 10;
  double double_num = 10.999999;
  float float_num = 10.999999;
  char symbl = 'p';
  int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

  int *int_ptr = &int_num;
  double *double_ptr = &double_num;
  float *float_ptr = &float_num;
  char *char_ptr = &symbl;
  void *void_ptr = array;
  int *void_p = S21_NULL;

  char str[STR_SIZE];
  char s21_str[STR_SIZE];

  // original
  sprintf(str, "%p %p %p %p %p %p", int_ptr, double_ptr, float_ptr, char_ptr,
          void_ptr, void_p);
  // s21
  s21_sprintf(s21_str, "%p %p %p %p %p %p", int_ptr, double_ptr, float_ptr,
              char_ptr, void_ptr, void_p);
  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(s21_sprintf_n_test) {
  char str_1[] = "First string";   // 12 symbols
  char str_2[] = "Second string";  // 13 symbols
  char str_3[] = "Third string";   // 12 symbols

  char str[STR_SIZE];
  char s21_str[STR_SIZE];
  int num_str;
  int num_s21_str;
  // original
  sprintf(str, "%s %s %s %n", str_1, str_2, str_3, &num_str);
  // s21
  s21_sprintf(s21_str, "%s %s %s %n", str_1, str_2, str_3, &num_s21_str);

  ck_assert_uint_eq(num_str, num_s21_str);
}
END_TEST

START_TEST(s21_sprintf_minus_test) {
  char str_1[STR_SIZE];
  char str_2[STR_SIZE];
  char s21_str_1[STR_SIZE];
  char s21_str_2[STR_SIZE];
  // original
  sprintf(str_1,
          "Пример выравнивания, когда число вмещается в n "
          "символов:\n\'%-10d\'\n\'%-10d\'\n\'%-10d\'",
          -19929, 92222, 123456789);
  sprintf(str_2,
          "Пример выравнивания, когда число не вмещается в n "
          "символов:\n\'%-3d\'\n\'%-3d\'\n\'%-3d\'",
          -19929, 92222, 123456789);
  // s21
  s21_sprintf(s21_str_1,
              "Пример выравнивания, когда число вмещается в n "
              "символов:\n\'%-10d\'\n\'%-10d\'\n\'%-10d\'",
              -19929, 92222, 123456789);
  s21_sprintf(s21_str_2,
              "Пример выравнивания, когда число не вмещается в n "
              "символов:\n\'%-3d\'\n\'%-3d\'\n\'%-3d\'",
              -19929, 92222, 123456789);

  ck_assert_str_eq(str_1, s21_str_1);
  ck_assert_str_eq(str_2, s21_str_2);
}
END_TEST

START_TEST(s21_sprintf_plus_test) {
  char str_int[STR_SIZE];
  char str_double[STR_SIZE];
  char str_float[STR_SIZE];

  char s21_str_int[STR_SIZE];
  char s21_str_double[STR_SIZE];
  char s21_str_float[STR_SIZE];

  // original
  sprintf(
      str_int,
      "Пример положительных integer чисел со знаком \'+\': %+d %+d "
      "%+d\nПример отрицательных целых чисел со знаком \'-\': %+d %+d %+d\n",
      123456789, 987654321, 0, -82882828, -12394812, -0);
  sprintf(
      str_float,
      "Пример положительных float чисел со знаком \'+\': %+f %+f "
      "%+f\nПример отрицательных целых чисел со знаком \'-\': %+f %+f %+f\n",
      1234567.999999, 9876.666123, 0.0, -82882828.218732, -12394812.999999,
      -0.0);
  sprintf(
      str_double,
      "Пример положительных double чисел со знаком \'+\': %+f %+f "
      "%+f\nПример отрицательных целых чисел со знаком \'-\': %+f %+f %+f\n",
      783498.123456789876543, 98765.917372856492737, 0.0,
      -82882828.288388765412345, -12394812.292789266783756, -0.0);
  // s21
  s21_sprintf(
      s21_str_int,
      "Пример положительных integer чисел со знаком \'+\': %+d %+d "
      "%+d\nПример отрицательных целых чисел со знаком \'-\': %+d %+d %+d\n",
      123456789, 987654321, 0, -82882828, -12394812, -0);
  s21_sprintf(
      s21_str_float,
      "Пример положительных float чисел со знаком \'+\': %+f %+f "
      "%+f\nПример отрицательных целых чисел со знаком \'-\': %+f %+f %+f\n",
      1234567.999999, 9876.666123, 0.0, -82882828.218732, -12394812.999999,
      -0.0);
  s21_sprintf(
      s21_str_double,
      "Пример положительных double чисел со знаком \'+\': %+f %+f "
      "%+f\nПример отрицательных целых чисел со знаком \'-\': %+f %+f %+f\n",
      783498.123456789876543, 98765.917372856492737, 0.0,
      -82882828.288388765412345, -12394812.292789266783756, -0.0);

  ck_assert_str_eq(str_int, s21_str_int);
  ck_assert_str_eq(str_float, s21_str_float);
  ck_assert_str_eq(str_double, s21_str_double);
}
END_TEST

START_TEST(s21_sprintf_space_test) {
  char str_int[STR_SIZE];
  char str_double[STR_SIZE];
  char str_float[STR_SIZE];

  char s21_str_int[STR_SIZE];
  char s21_str_double[STR_SIZE];
  char s21_str_float[STR_SIZE];

  // original
  sprintf(str_int,
          "Пример integer чисел с \' \': % d % d "
          "% d % d\n",
          123456789, 987654321, 0, -929);
  sprintf(str_float,
          "Пример float чисел с \' \': % f % f "
          "% f % f\n",
          1234567.999999, 9876.666123, 0.0, -929.223113);
  sprintf(str_double,
          "Пример double чисел с \' \': % f % f "
          "% f % f\n",
          783498.123456789876543, 98765.917372856492737, 0.0,
          -929.223113223113355);
  // s21
  s21_sprintf(s21_str_int,
              "Пример integer чисел с \' \': % d % d "
              "% d % d\n",
              123456789, 987654321, 0, -929);
  s21_sprintf(s21_str_float,
              "Пример float чисел с \' \': % f % f "
              "% f % f\n",
              1234567.999999, 9876.666123, 0.0, -929.223113);
  s21_sprintf(s21_str_double,
              "Пример double чисел с \' \': % f % f "
              "% f % f\n",
              783498.123456789876543, 98765.917372856492737, 0.0,
              -929.223113223113355);
  ck_assert_str_eq(str_int, s21_str_int);
  ck_assert_str_eq(str_float, s21_str_float);
  ck_assert_str_eq(str_double, s21_str_double);
}
END_TEST

START_TEST(s21_sprintf_sharp_test) {
  char str_f[STR_SIZE];
  char str_e[STR_SIZE];
  char str_x[STR_SIZE];
  char str_o[STR_SIZE];

  char s21_str_f[STR_SIZE];
  char s21_str_e[STR_SIZE];
  char s21_str_x[STR_SIZE];
  char s21_str_o[STR_SIZE];

  // original
  sprintf(str_f, "%#f %#f %#f %#f %#f %#f", 8634533544.5446954, 4678.5446954,
          4678.0, INFINITY, -INFINITY, NAN);
  sprintf(str_e, "%#e %#e %#e %#e %#e %#e %#E %#E %#E %#E %#E %#E",
          8634533544.5446954, 4678.5446954, 4678.0, INFINITY, -INFINITY, NAN,
          8634533544.5446954, 4678.5446954, 4678.0, INFINITY, -INFINITY, NAN);
  sprintf(str_x, "%#x %#x %#x %#X %#X %#X", UINT_MAX, 2138328, 0, UINT_MAX,
          2138328, 0);
  sprintf(str_o, "%#o %#o %#o", UINT_MAX, 2138328, 0);
  // s21
  s21_sprintf(s21_str_f, "%#f %#f %#f %#f %#f %#f", 8634533544.5446954,
              4678.5446954, 4678.0, INFINITY, -INFINITY, NAN);
  s21_sprintf(s21_str_e, "%#e %#e %#e %#e %#e %#e %#E %#E %#E %#E %#E %#E",
              8634533544.5446954, 4678.5446954, 4678.0, INFINITY, -INFINITY,
              NAN, 8634533544.5446954, 4678.5446954, 4678.0, INFINITY,
              -INFINITY, NAN);
  s21_sprintf(s21_str_x, "%#x %#x %#x %#X %#X %#X", UINT_MAX, 2138328, 0,
              UINT_MAX, 2138328, 0);
  s21_sprintf(s21_str_o, "%#o %#o %#o", UINT_MAX, 2138328, 0);

  ck_assert_str_eq(str_f, s21_str_f);
  ck_assert_str_eq(str_e, s21_str_e);
  ck_assert_str_eq(str_x, s21_str_x);
  ck_assert_str_eq(str_o, s21_str_o);
}
END_TEST

START_TEST(s21_sprintf_zero_test) {
  char str_1[STR_SIZE];
  char str_2[STR_SIZE];
  char s21_str_1[STR_SIZE];
  char s21_str_2[STR_SIZE];
  // original
  sprintf(str_1,
          "Пример выравнивания, когда число вмещается в n "
          "символов:\n\'%010d\'\n\'%010d\'\n\'%010d\'\n\'%010f\'\n\'%"
          "010f\'\n\'%010f\'",
          -19929, 92222, 123456789, 12312.122, 22.2, 0.9284);
  sprintf(
      str_2,
      "Пример выравнивания, когда число не вмещается в n "
      "символов:\n\'%03d\'\n\'%03d\'\n\'%03d\'\n\'%03f\'\n\'%03f\'\n\'%03f\'",
      -19929, 92222, 123456789, 12312.122, 22.2, 0.9284);
  // s21
  s21_sprintf(s21_str_1,
              "Пример выравнивания, когда число вмещается в n "
              "символов:\n\'%010d\'\n\'%010d\'\n\'%010d\'\n\'%010f\'\n\'%"
              "010f\'\n\'%010f\'",
              -19929, 92222, 123456789, 12312.122, 22.2, 0.9284);
  s21_sprintf(
      s21_str_2,
      "Пример выравнивания, когда число не вмещается в n "
      "символов:\n\'%03d\'\n\'%03d\'\n\'%03d\'\n\'%03f\'\n\'%03f\'\n\'%03f\'",
      -19929, 92222, 123456789, 12312.122, 22.2, 0.9284);

  ck_assert_str_eq(str_1, s21_str_1);
  ck_assert_str_eq(str_2, s21_str_2);
}
END_TEST

START_TEST(s21_sprintf_num_width_test) {
  char str[STR_SIZE];
  char s21_str[STR_SIZE];
  // original
  sprintf(str, "%10d %10d %10d %10f %10f %10f", 42, 23, INT_MAX,
          8634533544.5446954, 4678.5446954, 22.3);
  // s21
  s21_sprintf(s21_str, "%10d %10d %10d %10f %10f %10f", 42, 23, INT_MAX,
              8634533544.5446954, 4678.5446954, 22.3);
  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(s21_sprintf_star_width_test) {
  char str_1[STR_SIZE];
  char str_2[STR_SIZE];
  char s21_str_1[STR_SIZE];
  char s21_str_2[STR_SIZE];
  int size_1 = 13;
  int size_2 = 3;
  // original
  sprintf(str_1,
          "Пример выравнивания, когда число вмещается в n "
          "символов:\n\'%*d\'\n\'%*d\'\n\'%*d\'\n\'%*f\'\n\'%"
          "*f\'\n\'%*f\'",
          size_1, -19929, size_1, 92222, size_1, 123456789, size_1, 12312.122,
          size_1, 22.2, size_1, 0.9284);
  sprintf(str_2,
          "Пример выравнивания, когда число не вмещается в n "
          "символов:\n\'%*d\'\n\'%*d\'\n\'%*d\'\n\'%*f\'\n\'%"
          "*f\'\n\'%*f\'",
          size_2, -19929, size_2, 92222, size_2, 123456789, size_2, 12312.122,
          size_2, 22.2, size_2, 0.9284);
  // s21
  s21_sprintf(s21_str_1,
              "Пример выравнивания, когда число вмещается в n "
              "символов:\n\'%*d\'\n\'%*d\'\n\'%*d\'\n\'%*f\'\n\'%"
              "*f\'\n\'%*f\'",
              size_1, -19929, size_1, 92222, size_1, 123456789, size_1,
              12312.122, size_1, 22.2, size_1, 0.9284);
  s21_sprintf(s21_str_2,
              "Пример выравнивания, когда число не вмещается в n "
              "символов:\n\'%*d\'\n\'%*d\'\n\'%*d\'\n\'%*f\'\n\'%"
              "*f\'\n\'%*f\'",
              size_2, -19929, size_2, 92222, size_2, 123456789, size_2,
              12312.122, size_2, 22.2, size_2, 0.9284);
  ck_assert_str_eq(str_1, s21_str_1);
  ck_assert_str_eq(str_2, s21_str_2);
}
END_TEST

START_TEST(s21_sprintf_accuracy_dot_test) {
  // d i o u x X
  // e E f g G
  // s
  char str_s[STR_SIZE];
  char str_e[STR_SIZE];  // e E
  char str_f[STR_SIZE];
  char str_d[STR_SIZE];  // d i u
  char str_x[STR_SIZE];  // x X

  char s21_str_s[STR_SIZE];
  char s21_str_e[STR_SIZE];  // e E
  char s21_str_f[STR_SIZE];
  char s21_str_d[STR_SIZE];  // d i u
  char s21_str_x[STR_SIZE];  // x X

  // original
  sprintf(str_s, "%.20s %.5s %.0s", "1234567890", "1234567890", "1234567890");
  sprintf(str_e, "%.15e, %.5e, %.e, %.0e %.15E, %.5E, %.E, %.0E", 823742.1234,
          823742.1234, 823742.1234, 823742.1234, -0.02349291222, 88.999999,
          26531.1, 22222.2222);
  sprintf(str_f, "%.15f, %.5f, %.f, %.0f %.15f, %.5f, %.f, %.0f", 823742.1234,
          823742.1234, 823742.1234, 823742.1234, -0.02349291222, 88.999999,
          26531.1, 22222.2222);
  sprintf(
      str_d,
      "%.20d, %.5d, %.d, %.0d, %.20i, %.5i, %.i, %.0i, %.20u, %.5u, %.u, %.0u",
      INT_MAX, 999999, 123773, -68239, INT_MAX, 999999, 123773, 68239, UINT_MAX,
      999999, 123773, 68239);
  sprintf(str_x, "%.20x, %.5x, %.x, %.0x, %.20X, %.5X, %.X, %.0X", UINT_MAX,
          999999, 123773, 68239, 1287821, 2210993, 39239, 221563);
  // s21
  s21_sprintf(s21_str_s, "%.20s %.5s %.0s", "1234567890", "1234567890",
              "1234567890");
  s21_sprintf(s21_str_e, "%.15e, %.5e, %.e, %.0e %.15E, %.5E, %.E, %.0E",
              823742.1234, 823742.1234, 823742.1234, 823742.1234,
              -0.02349291222, 88.999999, 26531.1, 22222.2222);
  s21_sprintf(s21_str_f, "%.15f, %.5f, %.f, %.0f %.15f, %.5f, %.f, %.0f",
              823742.1234, 823742.1234, 823742.1234, 823742.1234,
              -0.02349291222, 88.999999, 26531.1, 22222.2222);
  s21_sprintf(
      s21_str_d,
      "%.20d, %.5d, %.d, %.0d, %.20i, %.5i, %.i, %.0i, %.20u, %.5u, %.u, %.0u",
      INT_MAX, 999999, 123773, -68239, INT_MAX, 999999, 123773, 68239, UINT_MAX,
      999999, 123773, 68239);
  s21_sprintf(s21_str_x, "%.20x, %.5x, %.x, %.0x, %.20X, %.5X, %.X, %.0X",
              UINT_MAX, 999999, 123773, 68239, 1287821, 2210993, 39239, 221563);
  ck_assert_str_eq(str_s, s21_str_s);
  ck_assert_str_eq(str_e, s21_str_e);
  ck_assert_str_eq(str_f, s21_str_f);
  ck_assert_str_eq(str_d, s21_str_d);
  ck_assert_str_eq(str_x, s21_str_x);
}
END_TEST

START_TEST(s21_sprintf_accuracy_star_test) {
  char str_s[STR_SIZE];
  char str_e[STR_SIZE];  // e E
  char str_f[STR_SIZE];
  char str_d[STR_SIZE];  // d i u
  char str_x[STR_SIZE];  // x X

  char s21_str_s[STR_SIZE];
  char s21_str_e[STR_SIZE];  // e E
  char s21_str_f[STR_SIZE];
  char s21_str_d[STR_SIZE];  // d i u
  char s21_str_x[STR_SIZE];  // x X

  int size_1 = 15;
  int size_2 = 5;
  int size_3 = 0;
  // original
  sprintf(str_s, "%.*s %.*s %.s %.*s", size_1, "1234567890", size_2,
          "1234567890", "1234567890", size_3, "1234567890");
  sprintf(str_e, "%.*e, %.*e, %.e, %.*e %.*E, %.*E, %.E, %.*E", size_1,
          823742.1234, size_2, 823742.1234, 823742.1234, size_3, 823742.1234,
          size_1, -0.02349291222, size_2, 88.999999, 26531.1, size_3,
          22222.2222);
  sprintf(str_f, "%.*f, %.*f, %.f, %.*f", size_1, 823742.1234, size_2,
          823742.1234, 823742.1234, size_3, 823742.1234);
  sprintf(str_d,
          "%.*d, %.*d, %.d, %.*d, %.*i, %.*i, %.i, %.*i, %.*u, %.*u, %.u, %.*u",
          size_1, INT_MAX, size_2, 999999, 123773, size_3, -68239, size_1,
          INT_MAX, size_2, 999999, 123773, size_3, 68239, size_1, UINT_MAX,
          size_2, 999999, 123773, size_3, 68239);
  sprintf(str_x, "%.*x, %.*x, %.x, %.*x, %.*X, %.*X, %.X, %.*X", size_1,
          UINT_MAX, size_2, 999999, 123773, size_3, 68239, size_1, 1287821,
          size_2, 2210993, 39239, size_3, 221563);
  // s21
  s21_sprintf(s21_str_s, "%.*s %.*s %.s %.*s", size_1, "1234567890", size_2,
              "1234567890", "1234567890", size_3, "1234567890");
  s21_sprintf(s21_str_e, "%.*e, %.*e, %.e, %.*e %.*E, %.*E, %.E, %.*E", size_1,
              823742.1234, size_2, 823742.1234, 823742.1234, size_3,
              823742.1234, size_1, -0.02349291222, size_2, 88.999999, 26531.1,
              size_3, 22222.2222);
  s21_sprintf(s21_str_f, "%.*f, %.*f, %.f, %.*f", size_1, 823742.1234, size_2,
              823742.1234, 823742.1234, size_3, 823742.1234);
  s21_sprintf(
      s21_str_d,
      "%.*d, %.*d, %.d, %.*d, %.*i, %.*i, %.i, %.*i, %.*u, %.*u, %.u, %.*u",
      size_1, INT_MAX, size_2, 999999, 123773, size_3, -68239, size_1, INT_MAX,
      size_2, 999999, 123773, size_3, 68239, size_1, UINT_MAX, size_2, 999999,
      123773, size_3, 68239);
  s21_sprintf(s21_str_x, "%.*x, %.*x, %.x, %.*x, %.*X, %.*X, %.X, %.*X", size_1,
              UINT_MAX, size_2, 999999, 123773, size_3, 68239, size_1, 1287821,
              size_2, 2210993, 39239, size_3, 221563);

  ck_assert_str_eq(str_s, s21_str_s);
  ck_assert_str_eq(str_e, s21_str_e);
  ck_assert_str_eq(str_f, s21_str_f);
  ck_assert_str_eq(str_d, s21_str_d);
  ck_assert_str_eq(str_x, s21_str_x);
}
END_TEST

START_TEST(s21_sprintf_h_test) {
  char str_d[STR_SIZE];  // d i u
  char str_o[STR_SIZE];  // o
  char str_x[STR_SIZE];  // x X

  char s21_str_d[STR_SIZE];  // d i u
  char s21_str_o[STR_SIZE];  // o
  char s21_str_x[STR_SIZE];  // x X

  // original
  sprintf(str_d, "%hd %hd %hd %hi %hi %hi %hu %hu %hu", SHRT_MAX, SHRT_MIN,
          5243, SHRT_MAX, SHRT_MIN, 0, 21314, 65535, 0);
  sprintf(str_o, "%ho %ho %ho", SHRT_MAX, SHRT_MIN, 5243);
  sprintf(str_x, "%hx %hx %hx %hX %hX %hX", SHRT_MAX, SHRT_MIN, 5243, SHRT_MAX,
          SHRT_MIN, 5243);
  // s21
  s21_sprintf(s21_str_d, "%hd %hd %hd %hi %hi %hi %hu %hu %hu", SHRT_MAX,
              SHRT_MIN, 5243, SHRT_MAX, SHRT_MIN, 0, 21314, 65535, 0);
  s21_sprintf(s21_str_o, "%ho %ho %ho", SHRT_MAX, SHRT_MIN, 5243);
  s21_sprintf(s21_str_x, "%hx %hx %hx %hX %hX %hX", SHRT_MAX, SHRT_MIN, 5243,
              SHRT_MAX, SHRT_MIN, 5243);
}
END_TEST

START_TEST(s21_sprintf_l_test) {
  char str_d[STR_SIZE];  // d i u
  char str_o[STR_SIZE];  // o
  char str_x[STR_SIZE];  // x X
  char str_s[STR_SIZE];
  char str_c[STR_SIZE];

  char s21_str_d[STR_SIZE];  // d i u
  char s21_str_o[STR_SIZE];  // o
  char s21_str_x[STR_SIZE];  // x X
  char s21_str_s[STR_SIZE];
  char s21_str_c[STR_SIZE];
  // original
  sprintf(str_d, "%ld %ld %ld %li %li %li %lu %lu %lu", LONG_MAX, LONG_MIN + 1,
          (long int)0, LONG_MAX, LONG_MIN + 1, (long unsigned int)0, ULONG_MAX,
          (long unsigned int)123982345987521324, (long unsigned int)0);
  sprintf(str_o, "%lo %lo %lo", ULONG_MAX, (long unsigned int)2214412,
          (long unsigned int)0);
  sprintf(str_x, "%lx %lx %lx %lX %lX %lX", ULONG_MAX,
          (long unsigned int)2214412, (long unsigned int)732478234, ULONG_MAX,
          (long unsigned int)123983222158935, (long unsigned int)732478234);
  sprintf(str_s, "%ls %ls %ls", L"ﾃﾄﾅﾆﾇﾈﾉﾊﾋﾌ", L"ﾬﾭﾮﾯﾰﾱﾲﾳﾴ", L"ﰁ ﰂ ﰃ ﰄ ﰅ ﰆ ﰇ ");
  sprintf(str_c, "%lc %lc %lc %lc", L'￬', L'￩', L'￪', L'￫');
  // s21
  s21_sprintf(s21_str_d, "%ld %ld %ld %li %li %li %lu %lu %lu", LONG_MAX,
              LONG_MIN + 1, (long int)0, LONG_MAX, LONG_MIN + 1,
              (long unsigned int)0, ULONG_MAX,
              (long unsigned int)123982345987521324, (long unsigned int)0);

  s21_sprintf(s21_str_o, "%lo %lo %lo", ULONG_MAX, (long unsigned int)2214412,
              (long unsigned int)0);
  s21_sprintf(s21_str_x, "%lx %lx %lx %lX %lX %lX", ULONG_MAX,
              (long unsigned int)2214412, (long unsigned int)732478234,
              ULONG_MAX, (long unsigned int)123983222158935,
              (long unsigned int)732478234);
  s21_sprintf(s21_str_s, "%ls %ls %ls", L"ﾃﾄﾅﾆﾇﾈﾉﾊﾋﾌ", L"ﾬﾭﾮﾯﾰﾱﾲﾳﾴ",
              L"ﰁ ﰂ ﰃ ﰄ ﰅ ﰆ ﰇ ");
  s21_sprintf(s21_str_c, "%lc %lc %lc %lc", L'￬', L'￩', L'￪', L'￫');

  ck_assert_str_eq(str_d, s21_str_d);
  ck_assert_str_eq(str_o, s21_str_o);
  ck_assert_str_eq(str_x, s21_str_x);
  ck_assert_str_eq(str_s, s21_str_s);
}
END_TEST

START_TEST(s21_sprintf_L_test) {
  char str_e[STR_SIZE];  // e E
  char str_f[STR_SIZE];
  char str_g[STR_SIZE];  // g G

  char s21_str_e[STR_SIZE];  // e E
  char s21_str_f[STR_SIZE];
  char s21_str_g[STR_SIZE];  // g G

  // original
  sprintf(str_f, "%Lf %Lf %Lf", (long double)18446744073709541615.123456,
          (long double)-18446744073709541615.123456, (long double)0.0);
  sprintf(str_e, "%Le %Le %Le %LE %LE %LE",
          (long double)18446744073709541615.123456,
          (long double)-18446744073709541615.123456, (long double)0.0,
          (long double)18446744073709541615.123456,
          (long double)-18446744073709541615.123456, (long double)0.0);
  sprintf(str_g, "%Lg %Lg %Lg %LG %LG %LG",
          (long double)18446744073709541615.123456,
          (long double)-18446744073709541615.123456, (long double)0.0,
          (long double)18446744073709541615.123456,
          (long double)-18446744073709541615.123456, (long double)0.0);
  // s21
  s21_sprintf(s21_str_f, "%Lf %Lf %Lf",
              (long double)18446744073709541615.123456,
              (long double)-18446744073709541615.123456, (long double)0.0);
  s21_sprintf(s21_str_e, "%Le %Le %Le %LE %LE %LE",
              (long double)18446744073709541615.123456,
              (long double)-18446744073709541615.123456, (long double)0.0,
              (long double)18446744073709541615.123456,
              (long double)-18446744073709541615.123456, (long double)0.0);
  s21_sprintf(s21_str_g, "%Lg %Lg %Lg %LG %LG %LG",
              (long double)18446744073709541614.123456,
              (long double)-18446744073709541615.123456, (long double)0.0,
              (long double)18446744073709541615.123456,
              (long double)-18446744073709541615.123456, (long double)0.0);

  ck_assert_str_eq(str_e, s21_str_e);
  ck_assert_str_eq(str_f, s21_str_f);
  ck_assert_str_eq(str_g, s21_str_g);
}
END_TEST

Suite *s21_sprintf_test() {
  Suite *suite = suite_create("s21_sprintf_test");
  TCase *test_cases = tcase_create("s21_sprintf_test");

  tcase_add_test(test_cases, s21_sprintf_c_test);
  tcase_add_test(test_cases, s21_sprintf_d_test);
  tcase_add_test(test_cases, s21_sprintf_i_test);  // i oct & hex
  tcase_add_test(test_cases, s21_sprintf_e_test);  // e E
  tcase_add_test(test_cases, s21_sprintf_f_test);
  tcase_add_test(test_cases, s21_sprintf_g_test);  // g G
  tcase_add_test(test_cases, s21_sprintf_o_test);
  tcase_add_test(test_cases, s21_sprintf_s_test);
  tcase_add_test(test_cases, s21_sprintf_u_test);
  tcase_add_test(test_cases, s21_sprintf_x_test);  // x X
  tcase_add_test(test_cases, s21_sprintf_p_test);
  tcase_add_test(test_cases, s21_sprintf_n_test);
  tcase_add_test(test_cases, s21_sprintf_minus_test);
  tcase_add_test(test_cases, s21_sprintf_plus_test);
  tcase_add_test(test_cases, s21_sprintf_space_test);
  tcase_add_test(test_cases, s21_sprintf_sharp_test);
  tcase_add_test(test_cases, s21_sprintf_zero_test);
  tcase_add_test(test_cases, s21_sprintf_num_width_test);
  tcase_add_test(test_cases, s21_sprintf_star_width_test);
  tcase_add_test(test_cases, s21_sprintf_accuracy_dot_test);
  tcase_add_test(test_cases, s21_sprintf_accuracy_star_test);
  tcase_add_test(test_cases, s21_sprintf_h_test);
  tcase_add_test(test_cases, s21_sprintf_l_test);
  tcase_add_test(test_cases, s21_sprintf_L_test);

  suite_add_tcase(suite, test_cases);

  return suite;
}