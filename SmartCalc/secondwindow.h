#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include <QAbstractButton>
#include <QApplication>
#include <math.h>

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();
    QString sum;
    QString data;
    QString percent_per_month;

private slots:
    void on_pushButton_clicked();

    void on_sum_textEdited(const QString &arg1);

    void on_data_textEdited(const QString &arg1);

    void on_percent_per_month_textEdited(const QString &arg1);

    void on_pushButton_2_clicked();

private:
    Ui::SecondWindow *ui;
//    SecondWindow *W2;
};

#endif // SECONDWINDOW_H
