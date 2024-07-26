#ifndef S21_STACK_H
#define S21_STACK_H

#include <stdlib.h>

typedef struct Stack_1 {
  long double value;
  struct Stack_1 *next;
} Stack_1;

typedef struct Stack_2 {
  char oper;
  int priority;
  struct Stack_2 *next;
} Stack_2;

void s21_push_1(Stack_1 **top, long double value);
void s21_push_2(Stack_2 **top, char oper, int priority);
int s21_pop_1(Stack_1 **top, long double *value);
int s21_pop_2(Stack_2 **top);
int s21_peek_2(Stack_2 **top);
#endif