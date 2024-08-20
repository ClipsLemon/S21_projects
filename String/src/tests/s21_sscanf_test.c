#include "s21_tests.h"

START_TEST(combined) {
#line 8

  long int a = 0;
  float f = 0.0;
  char d[100] = "";
  char c = '\0';
  unsigned int u = 0;
  int hexVal = 0;

  s21_sscanf("-2 1A -2.5413231 asdasdas J 4", "%ld %x %f %s %c %u", &a, &hexVal,
             &f, d, &c, &u);

  long int orig_a = 0;
  float orig_f = 0.0;
  char orig_d[100] = "";
  char orig_c = '\0';
  unsigned int orig_u = 0;
  int orig_hexVal = 0;

  sscanf("-2 1A -2.5413231 asdasdas J 4", "%ld %x %f %s %c %u", &orig_a,
         &orig_hexVal, &orig_f, orig_d, &orig_c, &orig_u);

  ck_assert_int_eq(a, orig_a);
  ck_assert_int_eq(hexVal, orig_hexVal);
  ck_assert_float_eq(f, orig_f);
  ck_assert_str_eq(d, orig_d);
  ck_assert_int_eq(c, orig_c);
  ck_assert_uint_eq(u, orig_u);
}
END_TEST

START_TEST(c_specifier) {
#line 37

  const char *str_c = "A b";

  char a = '\0';
  char b = '\0';

  char orig_a = '\0';
  char orig_b = '\0';

  s21_sscanf(str_c, "%c %c", &a, &b);
  sscanf(str_c, "%c %c", &orig_a, &orig_b);

  ck_assert_int_eq(orig_a, a);
  ck_assert_int_eq(orig_b, b);
}
END_TEST

START_TEST(d_specifier) {
#line 53

  const char *str_d = "123 456 789";

  short int short_num = 0;
  int num = 0;
  long int long_num = 0;

  short int orig_short_num = 0;
  int orig_num = 0;
  long int orig_long_num = 0;

  s21_sscanf(str_d, "%hd %d %ld", &short_num, &num, &long_num);
  sscanf(str_d, "%hd %d %ld", &orig_short_num, &orig_num, &orig_long_num);

  ck_assert_int_eq(orig_short_num, short_num);
  ck_assert_int_eq(orig_num, num);
  ck_assert_int_eq(orig_long_num, long_num);
}
END_TEST

START_TEST(i_specifier) {
#line 72

  const char *str_i_decimal = "12345";
  const char *str_i_octal = "012345";
  const char *str_i_hex = "0x3039";

  short int short_dec = 0;
  int dec = 0;
  long int long_dec = 0;

  short int orig_short_dec = 0;
  int orig_dec = 0;
  long int orig_long_dec = 0;

  short int short_oct = 0;
  int oct = 0;
  long int long_oct = 0;

  short int orig_short_oct = 0;
  int orig_oct = 0;
  long int orig_long_oct = 0;

  short int short_hex = 0;
  int hex = 0;
  long int long_hex = 0;

  short int orig_short_hex = 0;
  int orig_hex = 0;
  long int orig_long_hex = 0;

  s21_sscanf(str_i_decimal, "%hi", &short_dec);
  s21_sscanf(str_i_decimal, "%i", &dec);
  s21_sscanf(str_i_decimal, "%li", &long_dec);

  sscanf(str_i_decimal, "%hi", &orig_short_dec);
  sscanf(str_i_decimal, "%i", &orig_dec);
  sscanf(str_i_decimal, "%li", &orig_long_dec);

  s21_sscanf(str_i_octal, "%hi", &short_oct);
  s21_sscanf(str_i_octal, "%i", &oct);
  s21_sscanf(str_i_octal, "%li", &long_oct);

  sscanf(str_i_octal, "%hi", &orig_short_oct);
  sscanf(str_i_octal, "%i", &orig_oct);
  sscanf(str_i_octal, "%li", &orig_long_oct);

  s21_sscanf(str_i_hex, "%hi", &short_hex);
  s21_sscanf(str_i_hex, "%i", &hex);
  s21_sscanf(str_i_hex, "%li", &long_hex);

  sscanf(str_i_hex, "%hi", &orig_short_hex);
  sscanf(str_i_hex, "%i", &orig_hex);
  sscanf(str_i_hex, "%li", &orig_long_hex);

  ck_assert_int_eq(orig_short_dec, short_dec);
  ck_assert_int_eq(orig_dec, dec);
  ck_assert_int_eq(orig_long_dec, long_dec);

  ck_assert_int_eq(orig_short_oct, short_oct);
  ck_assert_int_eq(orig_oct, oct);
  ck_assert_int_eq(orig_long_oct, long_oct);

  ck_assert_int_eq(orig_short_hex, short_hex);
  ck_assert_int_eq(orig_hex, hex);
  ck_assert_int_eq(orig_long_hex, long_hex);
}
END_TEST

START_TEST(e_specifier) {
#line 98

  const char *str_e1 = "1.23e3";
  const char *str_e2 = "-4.56e2";
  const char *str_e3 = "7.89e4";

  float f = 0.0;
  double d = 0.0;
  long double long_d = 0.0;

  float orig_f = 0.0;
  double orig_d = 0.0;
  long double orig_long_d = 0.0;

  s21_sscanf(str_e1, "%e", &f);
  s21_sscanf(str_e2, "%le", &d);
  s21_sscanf(str_e3, "%Le", &long_d);

  sscanf(str_e1, "%e", &orig_f);
  sscanf(str_e2, "%le", &orig_d);
  sscanf(str_e3, "%Le", &orig_long_d);

  ck_assert_float_eq(orig_f, f);
  ck_assert_float_eq(orig_d, d);
  ck_assert_float_eq(orig_long_d, long_d);
}
END_TEST

START_TEST(E_specifier) {
#line 124

  const char *str_E1 = "1.23E3";
  const char *str_E2 = "-4.56E2";
  const char *str_E3 = "7.89E4";

  float f = 0.0;
  double d = 0.0;
  long double long_d = 0.0;

  float orig_f = 0.0;
  double orig_d = 0.0;
  long double orig_long_d = 0.0;

  s21_sscanf(str_E1, "%E", &f);
  s21_sscanf(str_E2, "%lE", &d);
  s21_sscanf(str_E3, "%LE", &long_d);

  sscanf(str_E1, "%E", &orig_f);
  sscanf(str_E2, "%lE", &orig_d);
  sscanf(str_E3, "%LE", &orig_long_d);

  ck_assert_float_eq(orig_f, f);
  ck_assert_float_eq(orig_d, d);
  ck_assert_float_eq(orig_long_d, long_d);
}
END_TEST

START_TEST(f_specifier) {
#line 150

  const char *str_f1 = "3.14";
  const char *str_f2 = "123.456";
  const char *str_f3 = "2.71828";

  float f = 0.0;
  double d = 0.0;
  long double long_d = 0.0;

  float orig_f = 0.0;
  double orig_d = 0.0;
  long double orig_long_d = 0.0;

  s21_sscanf(str_f1, "%f", &f);
  s21_sscanf(str_f2, "%lf", &d);
  s21_sscanf(str_f3, "%Lf", &long_d);

  sscanf(str_f1, "%f", &orig_f);
  sscanf(str_f2, "%lf", &orig_d);
  sscanf(str_f3, "%Lf", &orig_long_d);

  ck_assert_float_eq(orig_f, f);
  ck_assert_float_eq(orig_d, d);
  ck_assert_float_eq(orig_long_d, long_d);
}
END_TEST

START_TEST(g_specifier) {
#line 176

  const char *str_g1 = "3.14e2";
  const char *str_g2 = "123.456";
  const char *str_g3 = "0.000789";

  float f = 0.0;
  double d = 0.0;
  long double long_d = 0.0;

  float orig_f = 0.0;
  double orig_d = 0.0;
  long double orig_long_d = 0.0;

  s21_sscanf(str_g1, "%g", &f);
  s21_sscanf(str_g2, "%lg", &d);
  s21_sscanf(str_g3, "%Lg", &long_d);

  sscanf(str_g1, "%g", &orig_f);
  sscanf(str_g2, "%lg", &orig_d);
  sscanf(str_g3, "%Lg", &orig_long_d);

  ck_assert_float_eq(orig_f, f);
  ck_assert_float_eq(orig_d, d);
  ck_assert_float_eq(orig_long_d, long_d);
}
END_TEST

START_TEST(G_specifier) {
#line 202

  const char *str_g1 = "3.14e2";
  const char *str_g2 = "123.456";
  const char *str_g3 = "0.000789";

  float f = 0.0;
  double d = 0.0;
  long double long_d = 0.0;

  float orig_f = 0.0;
  double orig_d = 0.0;
  long double orig_long_d = 0.0;

  s21_sscanf(str_g1, "%G", &f);
  s21_sscanf(str_g2, "%lG", &d);
  s21_sscanf(str_g3, "%LG", &long_d);

  sscanf(str_g1, "%G", &orig_f);
  sscanf(str_g2, "%lG", &orig_d);
  sscanf(str_g3, "%LG", &orig_long_d);

  ck_assert_float_eq(orig_f, f);
  ck_assert_float_eq(orig_d, d);
  ck_assert_float_eq(orig_long_d, long_d);
}
END_TEST

START_TEST(o_specifier) {
#line 228

  const char *str_o1 = "123";
  const char *str_o2 = "456";
  const char *str_o3 = "12";

  unsigned short int short_o1 = 0;
  unsigned int o2 = 0;
  unsigned long int long_o3 = 0;

  unsigned short int orig_short_o1 = 0;
  unsigned int orig_o2 = 0;
  unsigned long int orig_long_o3 = 0;

  s21_sscanf(str_o1, "%ho", &short_o1);
  s21_sscanf(str_o2, "%o", &o2);
  s21_sscanf(str_o3, "%lo", &long_o3);

  sscanf(str_o1, "%ho", &orig_short_o1);
  sscanf(str_o2, "%o", &orig_o2);
  sscanf(str_o3, "%lo", &orig_long_o3);

  ck_assert_int_eq(orig_short_o1, short_o1);
  ck_assert_int_eq(orig_o2, o2);
  ck_assert_int_eq(orig_long_o3, long_o3);
}
END_TEST

START_TEST(s_specifier) {
#line 254

  const char *str_s1 = "Hello, World!";
  const char *str_s2 = "Programming is fun!";
  const char *str_s3 = "One Two Three";

  char s1[50];
  char s2[50];
  char s3[50];

  char orig_s1[50];
  char orig_s2[50];
  char orig_s3[50];

  s21_sscanf(str_s1, "%s", s1);
  s21_sscanf(str_s2, "%s", s2);
  s21_sscanf(str_s3, "%s", s3);

  sscanf(str_s1, "%s", orig_s1);
  sscanf(str_s2, "%s", orig_s2);
  sscanf(str_s3, "%s", orig_s3);

  ck_assert_str_eq(orig_s1, s1);
  ck_assert_str_eq(orig_s2, s2);
  ck_assert_str_eq(orig_s3, s3);
}
END_TEST

START_TEST(u_specifier) {
#line 280

  const char *str_u1 = "123";
  const char *str_u2 = "456";
  const char *str_u3 = "12";

  unsigned short int short_u1 = 0;
  unsigned int u2 = 0;
  unsigned long int long_u3 = 0;

  s21_sscanf(str_u1, "%hu", &short_u1);
  s21_sscanf(str_u2, "%u", &u2);
  s21_sscanf(str_u3, "%lu", &long_u3);

  ck_assert_int_eq(123, short_u1);
  ck_assert_int_eq(456, u2);
  ck_assert_int_eq(12, long_u3);
}
END_TEST

START_TEST(x_specifier) {
#line 298

  const char *str_x1 = "1a";
  const char *str_x2 = "7FFF";
  const char *str_x3 = "1FFFFFFFF";

  unsigned short int short_x1 = 0;
  unsigned int x2 = 0;
  unsigned long int long_x3 = 0;

  unsigned short int orig_short_x1 = 0;
  unsigned int orig_x2 = 0;
  unsigned long int orig_long_x3 = 0;

  s21_sscanf(str_x1, "%hx", &short_x1);
  s21_sscanf(str_x2, "%x", &x2);
  s21_sscanf(str_x3, "%lx", &long_x3);

  sscanf(str_x1, "%hx", &orig_short_x1);
  sscanf(str_x2, "%x", &orig_x2);
  sscanf(str_x3, "%lx", &orig_long_x3);

  ck_assert_int_eq(orig_short_x1, short_x1);
  ck_assert_int_eq(orig_x2, x2);
  ck_assert_int_eq(orig_long_x3, long_x3);
}
END_TEST

START_TEST(X_specifier) {
#line 324

  const char *str_X1 = "1a";
  const char *str_X2 = "7FFF";
  const char *str_X3 = "1FFFFFFFF";

  unsigned short int short_X1 = 0;
  unsigned int X2 = 0;
  unsigned long int long_X3 = 0;

  unsigned short int orig_short_X1 = 0;
  unsigned int orig_X2 = 0;
  unsigned long int orig_long_X3 = 0;

  s21_sscanf(str_X1, "%hX", &short_X1);
  s21_sscanf(str_X2, "%X", &X2);
  s21_sscanf(str_X3, "%lX", &long_X3);

  sscanf(str_X1, "%hX", &orig_short_X1);
  sscanf(str_X2, "%X", &orig_X2);
  sscanf(str_X3, "%lX", &orig_long_X3);

  ck_assert_int_eq(orig_short_X1, short_X1);
  ck_assert_int_eq(orig_X2, X2);
  ck_assert_int_eq(orig_long_X3, long_X3);
}
END_TEST

START_TEST(p_specifier) {
#line 350

  const char *str_p1 = "0x7ffeefbfb788";
  const char *str_p2 = "0xdeadbeef";

  void *p1;
  void *p2;

  void *orig_p1;
  void *orig_p2;

  s21_sscanf(str_p1, "%p", &p1);
  s21_sscanf(str_p2, "%p", &p2);

  sscanf(str_p1, "%p", &orig_p1);
  sscanf(str_p2, "%p", &orig_p2);

  ck_assert_ptr_eq(orig_p1, p1);
  ck_assert_ptr_eq(orig_p2, p2);
}
END_TEST

START_TEST(n_specifier) {
#line 370

  const char *str_n = "4567 890";

  int n1 = 0;
  int n2 = 0;
  int count = 0;

  int orig_n1 = 0;
  int orig_n2 = 0;
  int orig_count = 0;

  s21_sscanf(str_n, "%d %d%n", &n1, &n2, &count);

  sscanf(str_n, "%d %d%n", &orig_n1, &orig_n2, &orig_count);

  ck_assert_int_eq(count, orig_count);
}
END_TEST

Suite *s21_sscanf_test() {
  Suite *suite = suite_create("s21_sscanf_test");
  TCase *test_cases = tcase_create("s21_sscanf_test");

  tcase_add_test(test_cases, combined);
  tcase_add_test(test_cases, c_specifier);
  tcase_add_test(test_cases, d_specifier);
  tcase_add_test(test_cases, i_specifier);
  tcase_add_test(test_cases, e_specifier);
  tcase_add_test(test_cases, E_specifier);
  tcase_add_test(test_cases, f_specifier);
  tcase_add_test(test_cases, g_specifier);
  tcase_add_test(test_cases, G_specifier);
  tcase_add_test(test_cases, o_specifier);
  tcase_add_test(test_cases, s_specifier);
  tcase_add_test(test_cases, u_specifier);
  tcase_add_test(test_cases, x_specifier);
  tcase_add_test(test_cases, X_specifier);
  tcase_add_test(test_cases, p_specifier);
  tcase_add_test(test_cases, n_specifier);

  suite_add_tcase(suite, test_cases);

  return suite;
}