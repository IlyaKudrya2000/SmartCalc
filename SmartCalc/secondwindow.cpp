#include "secondwindow.h"
#include "ui_secondwindow.h"
#include "mainwindow.h"

SecondWindow::SecondWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
}

SecondWindow::~SecondWindow()
{
    delete ui;
}

void SecondWindow::on_pushButton_clicked()
{
    double  s = sum.toDouble();
    double  d = data.toDouble();
    double  p = percent_per_month.toDouble();
    p = p / 100;
    double T = s*(p + p/(pow((p+1),d) - 1));
    double total_sum = T * d;
    double delta = total_sum - s;
    QString   T_str = QString::number(T, 'f', 7);
    QString   total_sum_str = QString::number(total_sum, 'f', 7);
    QString   delta_str = QString::number(delta, 'f', 7);
    ui->qwer->setText(T_str);
    ui->qwer_2->setText(total_sum_str);
    ui->qwer_3->setText(delta_str);

}

void SecondWindow::on_sum_textEdited(const QString &arg1)
{
    sum = arg1;
}


void SecondWindow::on_data_textEdited(const QString &arg1)
{
    data = arg1;
}


void SecondWindow::on_percent_per_month_textEdited(const QString &arg1)
{
    percent_per_month = arg1;
}


void SecondWindow::on_pushButton_2_clicked()
{
    double  s = sum.toDouble();
    double  s_tmp = s;
    double  d = data.toDouble();
    double  p = percent_per_month.toDouble();
    p = p / 100;
    double s_MONTH = s / d;
    double total_sum = 0;

    QString   diff;
    for(int i = 0; i < d; i++){
        diff+= "month  ";
        diff+= QString::number(i + 1, 'i', 0);
        diff+= "  to pay  ";
        diff+= QString::number((s * p / 12) + s_MONTH, 'f', 3);
        diff+='\n';
        ui->DIFF->setText(diff);
        s = s - s_MONTH;
        total_sum += (s * p / 12);
    }
    double delta = total_sum + s_tmp;

    QString   total_sum_str = QString::number(total_sum, 'f', 3);
    QString   delta_str = QString::number(delta, 'f', 3);

    ui->qwer_2->setText(total_sum_str);
    ui->qwer_3->setText(delta_str);
}

