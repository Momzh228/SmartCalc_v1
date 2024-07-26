#include "s21_stack.h"

void s21_push_1(Stack_1 **top, long double value) {
  Stack_1 *New = (Stack_1 *)malloc(sizeof(Stack_1));
  New->value = value;
  New->next = *top;
  *top = New;
}
void s21_push_2(Stack_2 **top, char oper, int priority) {
  Stack_2 *New = (Stack_2 *)malloc(sizeof(Stack_2));
  New->oper = oper;
  New->priority = priority;
  New->next = *top;
  *top = New;
}

int s21_pop_1(Stack_1 **top, long double *value) {
  int error = 0;
  if (top) {
    if (*top) {
      Stack_1 *tmp = *top;
      *top = (*top)->next;
      *value = tmp->value;
      free(tmp);
    } else
      error = -1;
  } else
    error = -1;
  return error;
}

int s21_pop_2(Stack_2 **top) {
  int oper;
  if (top) {
    if (*top) {
      Stack_2 *tmp = *top;
      *top = (*top)->next;
      oper = tmp->oper;
      free(tmp);
    } else
      oper = -1;
  } else
    oper = -1;
  return oper;
}

int s21_peek_2(Stack_2 **top) {
  int priority;
  if (top) {
    if (*top) {
      priority = (*top)->priority;
    } else
      priority = -1;
  } else
    priority = -1;
  return priority;
}
