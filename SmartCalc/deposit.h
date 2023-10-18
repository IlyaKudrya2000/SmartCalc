#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <QWidget>

namespace Ui {
class deposit;
}

class deposit : public QWidget
{
    Q_OBJECT

public:
    explicit deposit(QWidget *parent = nullptr);
    ~deposit();
    QString sum;
    QString time;
    QString percent_plus;
    QString nolog_percent;
    int withdrawals [5];
    int replenishment [5];
    int interest [5];
    QString withdrawals_str;
    QString replenishment_str;
    double withdrawals_coef = 0;
    double replenishment_coef = 0;
    double  time_coef = 1;
    int flag_interest;
    int flag_withdrawals;
    int flag_replenishment;

private slots:

    void on_nolog_percent_textEdited(const QString &arg1);

    void on_percent_plus_textEdited(const QString &arg1);

    void on_sum_textEdited(const QString &arg1);

    void on_time_textEdited(const QString &arg1);

    void on_total_clicked();

    void on_day_clicked();

    void on_month_clicked();

    void on_half_clicked();

    void on_year_clicked();

    void on_interest_clicked();

    void on_day_2_clicked();

    void on_month_2_clicked();

    void on_half_2_clicked();

    void on_year_2_clicked();

    void on_day_4_clicked();

    void on_lineEdit_textEdited(const QString &arg1);

    void on_day_3_clicked();

    void on_month_3_clicked();

    void on_half_3_clicked();

    void on_year_3_clicked();

    void on_day_5_clicked();

    void on_lineEdit_2_textEdited(const QString &arg1);

private:
    Ui::deposit *ui;
};

#endif // DEPOSIT_H
