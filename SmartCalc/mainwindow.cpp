#include "secondwindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <fstream>
#include <unistd.h>
//...

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEdit_textEdited(const QString& arg1) {
    inputt = arg1;
}
void MainWindow::on_pushButton_clicked()
{
    inputt+="sin";
    ui->lineEdit->setText(inputt);
}


void MainWindow::on_pushButton_2_clicked()
{
    inputt+="cos";
    ui->lineEdit->setText(inputt);
}


void MainWindow::on_pushButton_3_clicked()
{
    inputt+="tan";
    ui->lineEdit->setText(inputt);
}


void MainWindow::on_pushButton_4_clicked()
{
    inputt+="acos";
    ui->lineEdit->setText(inputt);
}


void MainWindow::on_pushButton_6_clicked()
{
    inputt+="asin";
    ui->lineEdit->setText(inputt);
}


void MainWindow::on_pushButton_5_clicked()
{
    inputt+="atan";
    ui->lineEdit->setText(inputt);
}


void MainWindow::on_pushButton_8_clicked()
{
    inputt+="mod";
    ui->lineEdit->setText(inputt);
}


void MainWindow::on_pushButton_11_clicked()
{
    inputt+="sqrt";
    ui->lineEdit->setText(inputt);
}


void MainWindow::on_pushButton_9_clicked()
{
    inputt+="ln";
    ui->lineEdit->setText(inputt);
}


void MainWindow::on_pushButton_12_clicked()
{
    inputt+="log";
    ui->lineEdit->setText(inputt);
}


void MainWindow::on_pushButton_10_clicked()
{
    inputt+="^";
    ui->lineEdit->setText(inputt);
}


void MainWindow::on_pushButton_7_clicked()
{
    inputt+=".";
    ui->lineEdit->setText(inputt);
}


void MainWindow::on_pushButton_14_clicked()
{
    inputt+="1";
    ui->lineEdit->setText(inputt);
}


void MainWindow::on_pushButton_18_clicked()
{
    inputt+="2";
    ui->lineEdit->setText(inputt);
}


void MainWindow::on_pushButton_15_clicked()
{
    inputt+="3";
    ui->lineEdit->setText(inputt);
}


void MainWindow::on_pushButton_22_clicked()
{
    inputt+="4";
    ui->lineEdit->setText(inputt);
}


void MainWindow::on_pushButton_17_clicked()
{
    inputt+="5";
    ui->lineEdit->setText(inputt);
}


void MainWindow::on_pushButton_13_clicked()
{
    inputt+="6";
    ui->lineEdit->setText(inputt);
}


void MainWindow::on_pushButton_23_clicked()
{
    inputt+="7";
    ui->lineEdit->setText(inputt);
}


void MainWindow::on_pushButton_19_clicked()
{
    inputt+="8";
    ui->lineEdit->setText(inputt);
}


void MainWindow::on_pushButton_16_clicked()
{
    inputt+="9";
    ui->lineEdit->setText(inputt);
}


void MainWindow::on_pushButton_20_clicked()
{
    inputt+="(";
    ui->lineEdit->setText(inputt);
}


void MainWindow::on_pushButton_24_clicked()
{
    inputt+="0";
    ui->lineEdit->setText(inputt);
}


void MainWindow::on_pushButton_21_clicked()
{
    inputt+=")";
    ui->lineEdit->setText(inputt);

}


void MainWindow::on_pushButton_25_clicked()
{

    if(X_tmp == 1) {
        inputt = cerrQ;
    }
    char* c = new char[inputt.length() + 1];

    for (int i = 0; i < inputt.length() + 1; i++) {
      c[i] = inputt.toStdString().c_str()[i];
    }
        double res = 0;
         int flag = preRead(c, &res);
         if(!flag){
            inputt.clear();
            inputt = QString::number(res, 'f', 7);
            ui->lineEdit->setText(inputt);
         } else {
             inputt.clear();
             ui->lineEdit->setText("kuracha");
         }
        delete [] c;
}

void MainWindow::on_pushButton_27_clicked()
{
    inputt+="-";
    ui->lineEdit->setText(inputt);
}


void MainWindow::on_pushButton_30_clicked()
{
    inputt+="+";
    ui->lineEdit->setText(inputt);
}


void MainWindow::on_pushButton_31_clicked()
{
    inputt+="/";
    ui->lineEdit->setText(inputt);
}


void MainWindow::on_pushButton_28_clicked()
{
    inputt+="*";
    ui->lineEdit->setText(inputt);
}

void MainWindow::on_credit_calc_clicked()
{
    W2 = new SecondWindow();
    W2->show();
}

void MainWindow::on_pushButton_26_clicked() {
    ui->widget->setInteraction(QCP::iRangeZoom, true);
    ui->widget->setInteraction(QCP::iRangeDrag, true);
  double X = 0;
  QVector<double> y;
  QVector<double> x;
  if( h < 0.00001 && h > -0.000001 ) h = 0.1;
  if(xBegin==0) xBegin = -10;
  if(xEnd==0) xEnd = 10 + h;
  ui->widget->xAxis->setRange(-10, 10);
  ui->widget->yAxis->setRange(-10, 10);

  char* c = new char[inputt.length() + 1];
  char* tmp = new char[inputt.length() + 45];
  QString cerr;
  for (X = xBegin; X <= xEnd; X += h) {
    for (int i = 0; i < inputt.length() + 1; i++) {
      c[i] = inputt.toStdString().c_str()[i];
    }

    for (unsigned long i = 0; i < strlen(c); i++) {
      if (c[i] == 'x' || c[i] == 'X') {
        cerr = inputt.left(i);
        cerr += QString::number(X, 'f', 7);
        cerr += inputt.mid(i + 1);
      }
    }
    for (int i = 0; i < cerr.length() + 1; i++) {
      tmp[i] = cerr.toStdString().c_str()[i];
    }
    double readtemp = 0;
    preRead(tmp,&readtemp);
    x.push_back(X);
    y.push_back(readtemp);
  }
  ui->widget->addGraph();
  ui->widget->graph(0)->setData(x, y);
  ui->widget->replot();
  x.clear();
  y.clear();
  delete []c;
  delete []tmp;
}


void MainWindow::on_deposit_clicked()
{
    W3 = new deposit();
    W3->show();
}


void MainWindow::on_pushButton_29_clicked()
{
  X_tmp = 1;
}


void MainWindow::on_X_qwe_textEdited(const QString &arg1)
{
    x = arg1;
    char* k = new char[inputt.length() + 1];
    double X = x.toDouble();
    for(int i = 0; i < inputt.length() + 1; i++){
        k[i] = inputt.toStdString().c_str()[i];
    }
    for(unsigned long i = 0; i < strlen(k); i++){
        if(k[i] == 'x' || k[i] == 'X'){
            cerrQ = inputt.left(i);
            if(x<0){
                cerrQ += "(0";
            }
            cerrQ += QString::number(X, 'f', 7);
            if(x<0){
                cerrQ += ')';
            }
            cerrQ += inputt.mid(i+1);
        }
    }
    inputt = cerrQ;
    delete [] k;
}


void MainWindow::on_shag_h_valueChanged(double arg1)
{
    h = arg1;
}

void MainWindow::on_xBegin_valueChanged(int arg1)
{
    xBegin = arg1;
}

void MainWindow::on_xEnd_valueChanged(int arg1)
{
    xEnd = arg1;
}
