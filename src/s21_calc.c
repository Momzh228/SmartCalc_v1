#include "s21_calc.h"
int SmartCalc(const char* input_str, long double* result) {
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
        error = func(&str, &Stack_1, &Stack_2);
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
int calc_f(Stack_1** Stack_1, Stack_2** Stack_2, int error,
           long double* result) {
  while (*Stack_2 && !error) {
    error = calculator(Stack_1, Stack_2);
  }
  if (!error)
    s21_pop_1(Stack_1, result);
  else
    *result = 0;
  return error;
}
int calculator(Stack_1** Stack_1, Stack_2** Stack_2) {
  long double num1 = 0, num2 = 0;
  char oper = s21_pop_2(Stack_2);
  int error = s21_pop_1(Stack_1, &num2);
  if (strchr("/+-*%^~m", oper)) s21_pop_1(Stack_1, &num1);
  if (strchr("qlL", oper) && num2 < 0) oper = -1;
  if (num2 == 0 && strchr("/%", oper)) oper = -2;
  if (oper > -1) {
    if (oper == '+')
      s21_push_1(Stack_1, num1 + num2);
    else if (oper == '-' || oper == '~')
      s21_push_1(Stack_1, num1 - num2);
    else if (oper == '*')
      s21_push_1(Stack_1, num1 * num2);
    else if (oper == '/')
      s21_push_1(Stack_1, num1 / num2);
    else if (oper == '%' || oper == 'm')
      s21_push_1(Stack_1, fmodl(num1, num2));
    else if (oper == '^')
      s21_push_1(Stack_1, powl(num1, num2));
    else if (oper == 's')
      s21_push_1(Stack_1, sinl(num2));
    else if (oper == 'c')
      s21_push_1(Stack_1, cosl(num2));
    else if (oper == 't')
      s21_push_1(Stack_1, tanl(num2));
    else if (oper == 'S')
      s21_push_1(Stack_1, asinl(num2));
    else if (oper == 'C')
      s21_push_1(Stack_1, acosl(num2));
    else if (oper == 'T')
      s21_push_1(Stack_1, atanl(num2));
    else if (oper == 'l')
      s21_push_1(Stack_1, logl(num2));
    else if (oper == 'L')
      s21_push_1(Stack_1, log10l(num2));
    else if (oper == 'q')
      s21_push_1(Stack_1, sqrtl(num2));
  } else
    error = oper;
  return error;
}
int str_check(const char* str) {
  int error = 0;
  int flag = 0;
  char oper = 0;
  if (!strchr("sctalf(-+x", *str) && !isdigit(*str)) error = -1;
  while (*str && !error) {
    if (*str != ' ') {
      if (*str == '(') flag++;
      if (*str == ')') flag--;
      if (!strchr("sincoqrtalmdg.-+x()*/+-%^", *str) && !isdigit(*str))
        error = -1;
      if (strchr("/*^m)", *str) && strchr("+-(/*m^", oper)) error = -1;
      if (strchr("*", *str) && strchr("(", oper)) error = -1;

      oper = *str;
    }
    str++;
  }
  if (!strchr(")x", *(str - 1)) && !isdigit(*(str - 1))) error = -1;
  if (flag != 0) error = -1;
  return error;
}
int func(char** str, Stack_1** Stack_1, Stack_2** Stack_2) {
  int error = 0;
  char arith_oper = '0';
  char* prov_symbol = *str - 1;
  while (*prov_symbol == ' ') {
    prov_symbol--;
  }
  if ((**str == '-' || **str == '+') && (strchr("+-/*%(d", *prov_symbol))) {
    if (**str == '-') {
      s21_push_1(Stack_1, 0);
      arith_oper = '~';
    } else {
      arith_oper = '$';
    }
  } else
    choose_arith_oper(str, &arith_oper);
  if (str != NULL && arith_oper != '0' && arith_oper != '$') {
    int priority = 0, check_priority = 0, step = 0;
    check_priority = s21_peek_2(Stack_2);
    choose_priority(arith_oper, &priority, &step);
    while (check_priority >= priority && check_priority != 5 &&
           check_priority != -1 && !error && priority != 6 &&
           (check_priority != 3 || priority != 3)) {
      error = calculator(Stack_1, Stack_2);
      check_priority = s21_peek_2(Stack_2);
    }
    if (!error) {
      s21_push_2(Stack_2, arith_oper, priority);
      *str += step;
    }
  } else if (arith_oper != '$')
    error = -1;
  return error;
}

void choose_priority(char arith_oper, int* priority, int* step) {
  *priority = -1;
  *step = 0;
  if (strchr("+-", arith_oper))
    *priority = 0;
  else if (strchr("*/", arith_oper))
    *priority = 1;
  else if (strchr("%m", arith_oper)) {
    *priority = 2;
    if (arith_oper == 'm') *step = 2;
  } else if (strchr("sctSCTlLq", arith_oper)) {
    *priority = 4;
    if (strchr("sctL", arith_oper)) {
      *step = 2;
    }
    if (strchr("SCTq", arith_oper)) {
      *step = 3;
    }
    if (strchr("l", arith_oper)) {
      *step = 1;
    }
  } else if (strchr("^", arith_oper))
    *priority = 3;
  else if (strchr("~", arith_oper))
    *priority = 6;
}

void choose_arith_oper(char** str, char* arith_oper) {
  if (str != NULL) {
    int num = 3;
    if (strchr("+", **str))
      *arith_oper = '+';
    else if (strchr("-", **str))
      *arith_oper = '-';
    else if (strchr("*", **str))
      *arith_oper = '*';
    else if (strchr("/", **str))
      *arith_oper = '/';
    else if (strchr("%", **str))
      *arith_oper = '%';
    else if (strchr("^", **str))
      *arith_oper = '^';
    else if (!strncmp(*str, "ln(", num))
      *arith_oper = 'l';
    else if (!strncmp(*str, "mod", num))
      *arith_oper = 'm';
    else if (!strncmp(*str, "sin(", num++))
      *arith_oper = 's';
    else if (!strncmp(*str, "cos(", num))
      *arith_oper = 'c';
    else if (!strncmp(*str, "tan(", num))
      *arith_oper = 't';
    else if (!strncmp(*str, "log(", num))
      *arith_oper = 'L';
    else if (!strncmp(*str, "asin(", num++))
      *arith_oper = 'S';
    else if (!strncmp(*str, "acos(", num))
      *arith_oper = 'C';
    else if (!strncmp(*str, "atan(", num))
      *arith_oper = 'T';
    else if (!strncmp(*str, "sqrt(", num))
      *arith_oper = 'q';
    else
      *arith_oper = '0';
  }
}
void clear_stack(Stack_1** Stack_1, Stack_2** Stack_2) {
  long double clear;
  while (*Stack_1) s21_pop_1(Stack_1, &clear);
  while (*Stack_2) s21_pop_2(Stack_2);
}