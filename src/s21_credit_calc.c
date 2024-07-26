#include "s21_calc.h"

int s21_credit_calc(double sum, int deadline, double percent, int type,
                    Credit_struct* creditStruct) {
  int error = 0;
  if (creditStruct != NULL && sum >= 0.01 && deadline >= 1 && deadline <= 600 &&
      percent >= 0.01 && percent <= 999 && (type == 1 || type == 2)) {
    double p = percent / 100 / 12;
    if (type == 1) {
      creditStruct->monthly_payment =
          sum * (p + (p / (powl(1 + p, deadline) - 1)));
      creditStruct->total_payment = creditStruct->monthly_payment * deadline;
      creditStruct->overpayment = creditStruct->total_payment - sum;
    } else {
      creditStruct->monthly_payment = sum / deadline + sum * p;
      double sum_cpy = sum;
      for (int i = 1; i <= deadline; ++i) {
        double payment = sum / deadline + sum_cpy * p;
        creditStruct->total_payment += payment;
        sum_cpy = sum - i * sum / deadline;
      }
      creditStruct->overpayment = creditStruct->total_payment - sum;
    }
  } else
    error = -1;
  return error;
}