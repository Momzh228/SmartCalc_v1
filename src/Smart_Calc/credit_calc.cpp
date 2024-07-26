#include "credit_calc.h"

#include "mainwindow.h"
#include "ui_credit_calc.h"

credit_calc::credit_calc(QWidget *parent)
    : QDialog(parent),
      ui(new Ui::credit_calc),
      input_validator(QRegularExpression("[0-9.]{25}")) {
  ui->setupUi(this);
  ui->pushButton_annuity->setChecked(true);
}

credit_calc::~credit_calc() { delete ui; }

void credit_calc::credit_calculator() {
  QString sum_text = ui->sum_credit->text();
  QString percent_text = ui->percent_credit->text();
  QString deadline_text = ui->deadline_credit->text();
  if (!(sum_text.isEmpty() || percent_text.isEmpty() ||
        deadline_text.isEmpty())) {
    double sum = sum_text.toDouble();
    double percent = percent_text.toDouble();
    int deadline = deadline_text.toInt();
    Credit_struct s21_Credit = {0, 0, 0};
    int type = 0, error = -1;
    if (ui->radioButton_ann->isChecked()) {
      type = 1;
    } else if (ui->radioButton_diff->isChecked()) {
      type = 2;
    } else {
      QMessageBox::critical(this, "Fail", "Необходимо выбрать тип расчета");
    }
    if (type) {
      error = s21_credit_calc(sum, deadline, percent, type, &s21_Credit);
      if (!error) {
        double total_sum = s21_Credit.total_payment;
        double monthly_payment = s21_Credit.monthly_payment;
        double overpayment = s21_Credit.overpayment;
        ui->label_monthly_pay_result->setText(
            QString("%L1").arg(monthly_payment, 0, 'f', 2));
        ui->label_total_sum_result->setText(
            QString("%L1").arg(total_sum, 0, 'f', 2));
        ui->label_overpayment_result->setText(
            QString("%L1").arg(overpayment, 0, 'f', 2));
      } else {
        QMessageBox::critical(this, "Fail", "Некорректный ввод");
      }
    }
  } else {
    QMessageBox::critical(this, "Fail", "Ошибка");
  }
}

void credit_calc::on_pushButton_annuity_clicked() {
  // on_pushButton_annuity_clicked();
  credit_calc::credit_calculator();
}
