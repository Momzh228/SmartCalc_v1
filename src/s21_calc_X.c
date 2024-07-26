#include "s21_calc.h"

int SmartCalc_X(const char* input_str, long double* result, long double x) {
  if (input_str == NULL) return -1;
  Stack_1* Stack_1 = NULL;
  Stack_2* Stack_2 = NULL;
  char* str = (char*)input_str;
  int error = str_check(str);
  if (*str == '-' || *str == '+') {
    s21_push_1(&Stack_1, 0);
  } else
    s21_push_1(&Stack_1, 1);
  while (*str != '\0' && !error) {
    if (isdigit(*str)) {
      long double num = strtold(str, &str);
      s21_push_1(&Stack_1, num);
    } else {
      if (*str == '(') {
        s21_push_2(&Stack_2, *str, 5);
      } else if (*str == ')') {
        while (Stack_2->oper != '(' && !error)
          error = calculator(&Stack_1, &Stack_2);
        s21_pop_2(&Stack_2);
      } else if (*str != ' ') {
        if (*str != 'x')
          error = func(&str, &Stack_1, &Stack_2);
        else
          s21_push_1(&Stack_1, x);
      }
      str++;
    }
  }
  if (!error) {
    error = calc_f(&Stack_1, &Stack_2, error, result);
  }
  if (Stack_1) {
    if (Stack_1->next != NULL) {
      error = -1;
      *result = 0;
    }
  }
  clear_stack(&Stack_1, &Stack_2);
  return error;
}