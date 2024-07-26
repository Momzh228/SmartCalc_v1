#include "s21_test.h"

START_TEST(s21_calc_1) {
  long double result = 0;
  char input_str[1024] = "2+2*2-2";
  int error = SmartCalc(input_str, &result);
  ck_assert_ldouble_eq_tol(result, 2 + 2 * 2 - 2, 1e-7);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_calc_2) {
  long double result = 0;
  char input_str[1024] = "sin(5)^2+cos(5)^2";
  int error = SmartCalc(input_str, &result);
  ck_assert_ldouble_eq_tol(result, pow(sin(5), 2) + pow(cos(5), 2), 1e-7);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_calc_3) {
  long double result = 0;
  char input_str[1024] = "acos(-1)*2^2^2";
  int error = SmartCalc(input_str, &result);
  ck_assert_ldouble_eq_tol(result, acos(-1) * pow(2, pow(2, 2)), 1e-7);
  ck_assert_int_eq(error, 0);
}

END_TEST

START_TEST(s21_calc_4) {
  long double result = 0;
  char input_str[1024] = "2 / 6 * 5 % 3 + 10 - 9";
  int error = SmartCalc(input_str, &result);
  ck_assert_ldouble_eq_tol(result, 2.0 / 6.0 * fmod(5, 3) + 10 - 9, 1e-7);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_calc_5) {
  long double result = 0;
  char input_str[1024] = "-5 + cos(10) * sin(1) / tan(1)";
  int error = SmartCalc(input_str, &result);
  ck_assert_ldouble_eq_tol(result, -5 + cos(10) * sin(1) / tan(1), 1e-7);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_calc_6) {
  long double result = 0;
  char input_str[1024] = "((ln(10)*2)+2)/2";
  int error = SmartCalc(input_str, &result);
  ck_assert_ldouble_eq_tol(result, ((log(10) * 2) + 2) / 2.0, 1e-7);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_calc_7) {
  long double result = 0;
  char input_str[1024] = "5mod3*10/15+6+atan(5)";
  int error = SmartCalc(input_str, &result);
  ck_assert_ldouble_eq_tol(result, fmod(5, 3) * 10.0 / 15.0 + 6 + atan(5),
                           1e-7);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_calc_8) {
  long double result = 0;
  char input_str[1024] = "asin(-1)+2^2+2";
  int error = SmartCalc(input_str, &result);
  ck_assert_ldouble_eq_tol(result, asin(-1) + pow(2, 2) + 2, 1e-7);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_calc_9) {
  long double result = 0;
  char input_str[1024] = "(sqrt(5) + 5) % 3";
  int error = SmartCalc(input_str, &result);
  ck_assert_ldouble_eq_tol(result, fmod((sqrt(5) + 5), 3), 1e-7);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_calc_10) {
  long double result = 0;
  char input_str[1024] = "log(5)^4+5/1";
  int error = SmartCalc(input_str, &result);
  ck_assert_ldouble_eq_tol(result, pow(log10l(5), 4) + 5.0 / 1.0, 1e-7);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_calc_11) {
  long double result = 0;
  char input_str[1024] = "2 - +3";
  int error = SmartCalc(input_str, &result);
  ck_assert_ldouble_eq_tol(result, 2 - 3, 1e-7);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_calc_12) {
  long double result = 0;
  char input_str[1024] = "sin(x)^2+cos(x)^2";
  long double x = 5;
  int error = SmartCalc_X(input_str, &result, x);
  ck_assert_ldouble_eq_tol(result, 1, 1e-7);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_calc_13) {
  long double result = 0;
  char input_str[1024] = "+1+x";
  long double x = 5.5;
  int error = SmartCalc_X(input_str, &result, x);
  ck_assert_ldouble_eq_tol(result, 6.5, 1e-7);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_calc_14) {
  long double result = 0;
  char input_str[1024] = "(x+x)*x";
  long double x = 10;
  int error = SmartCalc_X(input_str, &result, x);
  ck_assert_ldouble_eq_tol(result, 200, 1e-7);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_calc_15) {
  long double result = 0;
  char input_str[1024] = "2++2";
  int error = SmartCalc(input_str, &result);
  ck_assert_ldouble_eq_tol(result, 4, 1e-7);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_calc_16) {
  long double result = 0;
  char input_str[1024] = "tan(250)-cos(45)+2^(sin(52))*5";
  int error = SmartCalc(input_str, &result);
  ck_assert_ldouble_eq_tol(result, tan(250) - cos(45) + pow(2, sin(52)) * 5,
                           1e-7);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_calc_17) {
  long double result = 0;
  char input_str[1024] = "cos(5.25)+sin(2.5)+tan(55.5)";
  int error = SmartCalc(input_str, &result);
  ck_assert_ldouble_eq_tol(result, cos(5.25) + sin(2.5) + tan(55.5), 1e-7);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_calc_18) {
  long double result = 0;
  char input_str[1024] = "2^3^2";
  int error = SmartCalc(input_str, &result);
  ck_assert_ldouble_eq_tol(result, pow(2, pow(3, 2)), 1e-7);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_calc_19) {
  long double result = 0;
  char input_str[1024] = "-2mod9 + 3mod4";
  int error = SmartCalc(input_str, &result);
  ck_assert_ldouble_eq_tol(result, -2 % 9 + 3 % 4, 1e-7);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_calc_20) {
  long double result = 0;
  char input_str[1024] = "(sin(1)+cos(2))*(2^3)+1";
  int error = SmartCalc(input_str, &result);
  ck_assert_ldouble_eq_tol(result, (sin(1) + cos(2)) * (pow(2, 3)) + 1, 1e-7);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_calc_21) {
  long double result = 0;
  char input_str[1024] = "sqrt(4)+2^2^2+1337.1337/sin(1)";
  int error = SmartCalc(input_str, &result);
  ck_assert_ldouble_eq_tol(
      result, sqrt(4) + pow(2, pow(2, 2)) + 1337.1337 / sin(1), 1e-7);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_calc_22) {
  long double result = 0;
  char input_str[1024] = "0/1";
  int error = SmartCalc(input_str, &result);
  ck_assert_ldouble_eq_tol(result, 0, 1e-7);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_calc_23) {
  long double result = 0;
  char input_str[1024] = "(5mod3+sqrt(5))+sin(10)+(tan(1)+log(1))";
  int error = SmartCalc(input_str, &result);
  ck_assert_ldouble_eq_tol(
      result, (5 % 3 + sqrt(5)) + sin(10) + (tan(1) + log(1)), 1e-7);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_calc_24) {
  long double result = 0;
  char input_str[1024] = "sin()+1";
  int error = SmartCalc(input_str, &result);
  ck_assert_int_eq(error, -1);
}
END_TEST

START_TEST(s21_calc_25) {
  long double result = 0;
  char input_str[1024] = "tan(5.4444)+sin";
  int error = SmartCalc(input_str, &result);
  ck_assert_int_eq(error, -1);
}
END_TEST

START_TEST(s21_calc_26) {
  long double result = 0;
  char input_str[1024] = "1wer+1sdf";
  int error = SmartCalc(input_str, &result);
  ck_assert_int_eq(error, -1);
}
END_TEST

START_TEST(s21_calc_27) {
  long double result = 0;
  char input_str[1024] = "asig(5)+atin(5)";
  int error = SmartCalc(input_str, &result);
  ck_assert_int_eq(error, -1);
}
END_TEST

START_TEST(s21_calc_28) {
  long double result = 0;
  char input_str[1024] = "2//2";
  int error = SmartCalc(input_str, &result);
  ck_assert_int_eq(error, -1);
}
END_TEST

START_TEST(s21_calc_29) {
  long double result = 0;
  char input_str[1024] = "((2+2)";
  int error = SmartCalc(input_str, &result);
  ck_assert_int_eq(error, -1);
}
END_TEST

START_TEST(s21_calc_30) {
  long double result = 0;
  char input_str[1024] = "2/0";
  int error = SmartCalc(input_str, &result);
  ck_assert_int_eq(error, -2);
}
END_TEST

START_TEST(s21_calc_31) {
  int error = s21_pop_1(NULL, NULL);
  ck_assert_int_eq(error, -1);
}
END_TEST

START_TEST(s21_calc_32) {
  int error = s21_pop_2(NULL);
  ck_assert_int_eq(error, -1);
}
END_TEST

START_TEST(s21_calc_33) {
  Stack_1 *Stack_1 = NULL;
  long double value;
  int error = s21_pop_1(&Stack_1, &value);
  ck_assert_int_eq(error, -1);
}
END_TEST

START_TEST(s21_calc_34) {
  Stack_2 *Stack_2 = NULL;
  int error = s21_pop_2(&Stack_2);
  ck_assert_int_eq(error, -1);
}
END_TEST

START_TEST(s21_calc_35) {
  int error = s21_peek_2(NULL);
  ck_assert_int_eq(error, -1);
}
END_TEST

START_TEST(s21_calc_36) {
  long double result = 0;
  char input_str[1024] = "2 2";
  int error = SmartCalc(input_str, &result);
  ck_assert_int_eq(error, -1);
}
END_TEST

START_TEST(s21_calc_37) {
  long double result = 0, x = 2;
  char input_str[1024] = "2 x";
  int error = SmartCalc_X(input_str, &result, x);
  ck_assert_int_eq(error, -1);
}
END_TEST

START_TEST(s21_creditcalc_1) {
  Credit_struct credit = {0};
  int error = s21_credit_calc(100000, 36, 9, 1, &credit);
  ck_assert_ldouble_eq_tol(credit.monthly_payment, 3179.97, 1e-2);
  ck_assert_ldouble_eq_tol(credit.overpayment, 14479.04, 1e-2);
  ck_assert_ldouble_eq_tol(credit.total_payment, 114479.04, 1e-2);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_creditcalc_2) {
  Credit_struct credit = {0};
  int error = s21_credit_calc(1337228, 13, 7, 1, &credit);
  ck_assert_ldouble_eq_tol(credit.monthly_payment, 107112.82, 1e-2);
  ck_assert_ldouble_eq_tol(credit.overpayment, 55238.61, 1e-2);
  ck_assert_ldouble_eq_tol(credit.total_payment, 1392466.61, 1e-2);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_creditcalc_3) {
  Credit_struct credit = {0};
  int error = s21_credit_calc(100000, 36, 9, 2, &credit);
  ck_assert_ldouble_eq_tol(credit.monthly_payment, 3527.78, 1e-2);
  ck_assert_ldouble_eq_tol(credit.overpayment, 13875, 1e-2);
  ck_assert_ldouble_eq_tol(credit.total_payment, 113875, 1e-2);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_creditcalc_4) {
  Credit_struct credit = {0};
  int error = s21_credit_calc(12092002, 12, 20, 2, &credit);
  ck_assert_ldouble_eq_tol(credit.monthly_payment, 1209200.20, 1e-2);
  ck_assert_ldouble_eq_tol(credit.overpayment, 1309966.88, 1e-2);
  ck_assert_ldouble_eq_tol(credit.total_payment, 13401968.88, 1e-2);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_creditcalc_5) {
  Credit_struct credit = {0};
  int error = s21_credit_calc(100000, 0, -1, 2, &credit);
  ck_assert_int_eq(error, -1);
}
END_TEST

Suite *test_SmartCalc() {
  Suite *s = suite_create("s21_calc");
  TCase *o = tcase_create("s21_calc");
  suite_add_tcase(s, o);
  tcase_add_test(o, s21_calc_1);
  tcase_add_test(o, s21_calc_2);
  tcase_add_test(o, s21_calc_3);
  tcase_add_test(o, s21_calc_4);
  tcase_add_test(o, s21_calc_5);
  tcase_add_test(o, s21_calc_6);
  tcase_add_test(o, s21_calc_7);
  tcase_add_test(o, s21_calc_8);
  tcase_add_test(o, s21_calc_9);
  tcase_add_test(o, s21_calc_10);
  tcase_add_test(o, s21_calc_11);
  tcase_add_test(o, s21_calc_12);
  tcase_add_test(o, s21_calc_13);
  tcase_add_test(o, s21_calc_14);
  tcase_add_test(o, s21_calc_15);
  tcase_add_test(o, s21_calc_16);
  tcase_add_test(o, s21_calc_17);
  tcase_add_test(o, s21_calc_18);
  tcase_add_test(o, s21_calc_19);
  tcase_add_test(o, s21_calc_20);
  tcase_add_test(o, s21_calc_21);
  tcase_add_test(o, s21_calc_22);
  tcase_add_test(o, s21_calc_23);
  tcase_add_test(o, s21_calc_24);
  tcase_add_test(o, s21_calc_25);
  tcase_add_test(o, s21_calc_26);
  tcase_add_test(o, s21_calc_27);
  tcase_add_test(o, s21_calc_28);
  tcase_add_test(o, s21_calc_29);
  tcase_add_test(o, s21_calc_30);
  tcase_add_test(o, s21_calc_31);
  tcase_add_test(o, s21_calc_32);
  tcase_add_test(o, s21_calc_33);
  tcase_add_test(o, s21_calc_34);
  tcase_add_test(o, s21_calc_35);
  tcase_add_test(o, s21_calc_36);
  tcase_add_test(o, s21_calc_37);
  tcase_add_test(o, s21_creditcalc_1);
  tcase_add_test(o, s21_creditcalc_2);
  tcase_add_test(o, s21_creditcalc_3);
  tcase_add_test(o, s21_creditcalc_4);
  tcase_add_test(o, s21_creditcalc_5);
  suite_add_tcase(s, o);
  return s;
}
