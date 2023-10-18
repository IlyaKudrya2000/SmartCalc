#include "deposit.h"
#include "ui_deposit.h"
#include <math.h>

deposit::deposit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::deposit)
{
//    this->setStyleSheet("background-color: purple;");
    ui->setupUi(this);
}

deposit::~deposit()
{
    delete ui;
}

void deposit::on_total_clicked()
{
    double  s = sum.toDouble();
    double  d = time.toDouble();
    double  p = percent_plus.toDouble();
    double N = nolog_percent.toDouble();

    p = p / 100;
    N = N / 100;
    double  total_sum = 0;
    double delta = 0;

    flag_interest = 0;
    if(interest[0] == 1 || interest[1] == 1 || interest[2] == 1 || interest[3] == 1){

        double tmp = withdrawals_str.toDouble();
        total_sum = s;
        for(int i = 0; i < d * 365 +1 ; i++){
            if(i % int(floor(365/withdrawals_coef)) == 0 && i > 0 && flag_withdrawals == 1){
                 total_sum-= tmp;

            }
            if(i % int(floor(365/replenishment_coef)) == 0 && i > 0 && flag_replenishment == 1){
                 total_sum+= replenishment_str.toDouble();

            }
            if(i % int(floor(365/time_coef)) == 0 && i > 0){
                total_sum+=  total_sum * (p/ time_coef);
            }
        }
        delta = total_sum - s + tmp*withdrawals_coef*d - replenishment_coef*d*replenishment_str.toDouble();
    } else {
       total_sum = s + s * d * p * (1 - N) - withdrawals_str.toDouble() * d * withdrawals_coef + replenishment_str.toDouble() * d * replenishment_coef;
       delta = total_sum - s;
    }

    QString   nolog = QString::number(N * s * d * p, 'f', 7);
    QString   total_sum_str = QString::number(total_sum, 'f', 7);
    QString   delta_plus_str = QString::number(delta, 'f', 7);

    ui->plus_percent->setText(delta_plus_str);
    ui->total_sum->setText(total_sum_str);
    ui->total_nolog->setText(nolog);
}



void deposit::on_nolog_percent_textEdited(const QString &arg1)
{
    nolog_percent = arg1;
}


void deposit::on_percent_plus_textEdited(const QString &arg1)
{
    percent_plus = arg1;
}


void deposit::on_sum_textEdited(const QString &arg1)
{
    sum = arg1;
}


void deposit::on_time_textEdited(const QString &arg1)
{
    time = arg1;
}


void deposit::on_day_clicked()
{

    for(int i = 0; i < 5; i++){
        interest[i] = 0;
    }
    interest[0] = 1;
    time_coef = 365;
    flag_interest = 1;
}


void deposit::on_month_clicked()
{
    for(int i = 0; i < 5; i++){
        interest[i] = 0;
    }
    interest[1] = 1;
    time_coef = 12;
    flag_interest = 1;
}


void deposit::on_half_clicked()
{
    for(int i = 0; i < 5; i++){
        interest[i] = 0;
    }
    interest[2] = 1;
    time_coef = 2;
    flag_interest = 1;
}


void deposit::on_year_clicked()
{
    for(int i = 0; i < 5; i++){
        interest[i] = 0;
    }
    interest[3] = 1;
    time_coef = 1;
    flag_interest = 1;
}


void deposit::on_interest_clicked()
{
    for(int i = 0; i < 5; i++){
        interest[i] = 0;
    }
    flag_interest = 0;
}


void deposit::on_day_2_clicked()
{
    for(int i = 0; i < 5; i++){
        withdrawals[i] = 0;
    }
     withdrawals[0] = 1;
     withdrawals_coef = 365;
     flag_withdrawals = 1;
}


void deposit::on_month_2_clicked()
{
    for(int i = 0; i < 5; i++){
        withdrawals[i] = 0;
    }
     withdrawals[1] = 1;
     withdrawals_coef = 12;
      flag_withdrawals = 1;
}


void deposit::on_half_2_clicked()
{
    for(int i = 0; i < 5; i++){
        withdrawals[i] = 0;
    }
     withdrawals[2] = 1;
     withdrawals_coef = 2;
      flag_withdrawals = 1;
}


void deposit::on_year_2_clicked()
{
    for(int i = 0; i < 5; i++){
        withdrawals[i] = 0;
    }
     withdrawals[3] = 1;
     withdrawals_coef = 1;
      flag_withdrawals = 1;
}


void deposit::on_day_4_clicked() // off
{
    for(int i = 0; i < 5; i++){
        withdrawals[i] = 0;
    }
     flag_withdrawals = 0;
     withdrawals_coef = 0;
}


void deposit::on_lineEdit_textEdited(const QString &arg1)
{
    withdrawals_str = arg1;
}


void deposit::on_day_3_clicked()
{
     replenishment_coef = 365;
     flag_replenishment = 1;
}


void deposit::on_month_3_clicked()
{
    replenishment_coef = 12;
    flag_replenishment = 1;
}


void deposit::on_half_3_clicked()
{
    replenishment_coef = 2;
    flag_replenishment = 1;
}


void deposit::on_year_3_clicked()
{
    replenishment_coef = 1;
    flag_replenishment = 1;
}


void deposit::on_day_5_clicked()
{
    replenishment_coef = 0;
    flag_replenishment = 0;
}


void deposit::on_lineEdit_2_textEdited(const QString &arg1)
{
    replenishment_str = arg1;
}

