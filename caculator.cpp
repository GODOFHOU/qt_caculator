#include "caculator.h"
#include "ui_caculatorHYW.h"
#include <QtMath>
#include <QDebug>
#include <math.h>

double Pi =M_PI;
//static int flag = 1;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("CaculatorHYW");
    this->init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
    a = 0;
    b = 0;
    result = 0;
    op = 0;
    string = "";
    isOperator = false;
}
void MainWindow::cal()
{
    switch(op){
    case 1 :
    {

        result = qPow(a, b);
        break;
    }
    case 2 :
     {
         result = double(a) + double(b);
         break;
     }
    case 3 :
     {
         result = double(a) - double(b);
         break;
     }
    case 4 :
     {
         result = double(a) * double(b);
         break;
     }
    case 5 :
     {
         result = double(a) / double(b);
         break;
     }
    case 6 :
     {
         result = a % b;
         break;
     }

    default : break;
    }
    a = result;
    b = 0;
    op = 0;
    ui->inputEdit->setText(string);
    ui->lcdNumber->display(QString("%1").arg(result));
    ui->resultEdit->setText(QString("%1").arg(result));
}

void MainWindow::on_acButton_clicked()
{
        this->init();
        ui->inputEdit->clear();
        ui->resultEdit->clear();
        ui->lcdNumber->display(0);
}

void MainWindow::on_cButton_clicked()
{
       ui->resultEdit->setText(QString("%1").arg(result));
       ui->inputEdit->clear();
       a = 0;
       b = 0;
       op = 0;
       string = "";
       isOperator = false;
}

void MainWindow::on_addButton_clicked()
{
    string += "+";
       if(op!=0)
       {
           this->cal();
       }
       op = 2;
       isOperator = true;
       ui->inputEdit->setText(string);

       qDebug()<<"a:"<<a<<endl;
       qDebug()<<"b:"<<b<<endl;
       qDebug()<<"aresult:"<<result<<endl;
}

void MainWindow::on_subButton_clicked()
{
    string += "-";
        if(op!=0)
        {
            this->cal();
        }
        op = 3;
        isOperator = true;
        ui->inputEdit->setText(string);

}

void MainWindow::on_chengButton_clicked()
{
    string += "*";
       if(op!=0)
       {
           this->cal();
       }
       op = 4;
       isOperator = true;
       ui->inputEdit->setText(string);
}

void MainWindow::on_chuButton_clicked()
{
    string += "/";
        if(op!=0)
        {
            this->cal();
        }
        op = 5;
        isOperator = true;
        ui->inputEdit->setText(string);
}
void MainWindow::on_zeroButton_clicked()
{
    if(isOperator)
            b = b*10+0;
        else
            a = a*10+0;

        string += "0";
        ui->inputEdit->setText(string);
}

void MainWindow::on_oneButton_clicked()
{
    if(isOperator)
           b = b*10+1;
       else
           a = a*10+1;

       string += "1";
       ui->inputEdit->setText(string);
}

void MainWindow::on_twoButton_clicked()
{
    if(isOperator)
           b = b*10+2;
       else
           a = a*10+2;

       string += "2";
       ui->inputEdit->setText(string);
}


void MainWindow::on_threeButton_clicked()
{
    if(isOperator)
            b = b*10+3;
        else
            a = a*10+3;

        string += "3";
        ui->inputEdit->setText(string);
}


void MainWindow::on_fourButton_clicked()
{
    if(isOperator)
            b = b*10+4;
        else
            a = a*10+4;

        string += "4";
        ui->inputEdit->setText(string);
}

void MainWindow::on_fiveButton_clicked()
{
    if(isOperator)
            b = b*10+5;
        else
            a = a*10+5;

        string += "5";
        ui->inputEdit->setText(string);
}

void MainWindow::on_sixButton_clicked()
{
    if(isOperator)
            b = b*10+6;
        else
            a = a*10+6;

        string += "6";
        ui->inputEdit->setText(string);
}

void MainWindow::on_sevenButton_clicked()
{
    if(isOperator)
            b = b*10+7;
        else
            a = a*10+7;

        string += "7";
        ui->inputEdit->setText(string);
}

void MainWindow::on_eightButton_clicked()
{
    if(isOperator)
            b = b*10+8;
        else
            a = a*10+8;

        string += "8";
        ui->inputEdit->setText(string);
}

void MainWindow::on_nineButton_clicked()
{
    if(isOperator)
            b = b*10+9;
        else
            a = a*10+9;

        string += "9";
        ui->inputEdit->setText(string);
}

void MainWindow::on_equalButton_clicked()
{
     this->cal();
}

void MainWindow::on_sinButton_clicked()
{

   string = "sin" + string;
       if(op!=0)
       {
           result = qSin(b*(Pi/180));
           b = result;
       }
       else
       {
           result = qSin(a*(Pi/180));
           a = result;
       }
       ui->inputEdit->setText(string);
       ui->lcdNumber->display(QString("%1").arg(result));
       ui->resultEdit->setText(QString("%1").arg(result));
       qDebug()<<"a:"<<a<<endl;
       qDebug()<<"b:"<<b<<endl;

       qDebug()<<"result:"<<result<<endl;

}

void MainWindow::on_cosButton_clicked()
{
    string = "cos" + string;
        if(op!=0)
        {
            result = qAcos(b*(Pi/180));
            b = result;
        }
        else
        {
            result = qAcos(a*(Pi/180));
            a = result;
        }
        ui->inputEdit->setText(string);
        ui->lcdNumber->display(QString("%1").arg(result));
        ui->resultEdit->setText(QString("%1").arg(result));
}

void MainWindow::on_tanButton_clicked()
{
    string = "tan" + string;
        if(op!=0)
        {
            result = qTan(b*(Pi/180));
            b = result;
        }
        else
        {
            result = qTan(a*(Pi/180));
            a = result;
        }
        ui->inputEdit->setText(string);
        ui->lcdNumber->display(QString("%1").arg(result));
        ui->resultEdit->setText(QString("%1").arg(result));
}

void MainWindow::on_arcsinButton_clicked()
{
    string = "arcsin" + string;
        if(op!=0)
        {
            result = qAsin(b);
            b = result;
        }
        else
        {
            result = qAsin(a);
            a = result;
        }
        ui->inputEdit->setText(string);
        ui->lcdNumber->display(QString("%1").arg(result));
        ui->resultEdit->setText(QString("%1").arg(result));
}

void MainWindow::on_arccosButton_clicked()
{
    string = "arccos" + string;
        if(op!=0)
        {
            result = qAcos(b);
            b = result;
        }
        else
        {
            result = qAcos(a);
            a = result;
        }
        ui->inputEdit->setText(string);
        ui->lcdNumber->display(QString("%1").arg(result));
        ui->resultEdit->setText(QString("%1").arg(result));
}

void MainWindow::on_arctanButton_clicked()
{
    string = "arctan" + string;
        if(op!=0)
        {
            result = qAtan(b);
            b = result;
        }
        else
        {
            result = qAtan(a);
            a = result;
        }
        ui->inputEdit->setText(string);
        ui->lcdNumber->display(QString("%1").arg(result));
        ui->resultEdit->setText(QString("%1").arg(result));
}

void MainWindow::on_qiuyuButton_clicked()
{
    string += "%";
        if(op!=0)
        {
            this->cal();
        }
        op = 6;
        isOperator = true;
        ui->inputEdit->setText(string);
        ui->lcdNumber->display(QString("%1").arg(result));
}

void MainWindow::on_qiugenButton_clicked()
{
    string = "√" + string;
        if(op!=0)
        {
            result = qPow(b,0.5);
            b = result;
        }
        else
        {
            result = qPow(a,0.5);
            a = result;
        }
        ui->inputEdit->setText(string);
        ui->lcdNumber->display(QString("%1").arg(result));
        ui->resultEdit->setText(QString("%1").arg(result));
}

void MainWindow::on_lnButton_clicked()
{
    string = "ln" +  string;
       if(op!=0)
       {
           result = qLn(b);
           b = result;
       }
       else
       {
           result = qLn(a);
           a = result;
       }
       ui->inputEdit->setText(string);
       ui->resultEdit->setText(QString("%1").arg(result));
       ui->lcdNumber->display(QString("%1").arg(result));
}

void MainWindow::on_eButton_clicked()
{
    string = "e^" + string;
        if(op!=0)
        {
            result = qPow(2.71828,b);
            b = result;
        }
        else
        {
            result = qPow(2.71828,a);
            a = result;
        }
        ui->inputEdit->setText(string);
        ui->resultEdit->setText(QString("%1").arg(result));
        ui->lcdNumber->display(QString("%1").arg(result));
}

void MainWindow::on_qiumiButton_clicked()
{
    string += "^";
        if(op!=0)
        {
            this->cal();
        }
        op = 1;
        isOperator = true;
        ui->inputEdit->setText(string);
}

void MainWindow::on_jueduiButton_clicked()
{
    string = "|" + string + "|";
        if(op!=0)
        {
            result = qFabs(b);
            b = result;
        }
        else
        {
            result = qFabs(a);
            a = result;
        }
        ui->inputEdit->setText(string);
        ui->resultEdit->setText(QString("%1").arg(result));
        ui->lcdNumber->display(QString("%1").arg(result));

        qDebug()<<"a:"<<a<<endl;
        qDebug()<<"b:"<<b<<endl;

        qDebug()<<"result:"<<result<<endl;
}

void MainWindow::on_qiehuanButton_clicked()
{
    if(ui->widget->isHidden())
        ui->widget->show();
    else
        ui->widget->hide();

}

void MainWindow::on_pointButton_clicked()
{

   /* string =  string + ".";
    a=double(string.toDouble());
    ui->inputEdit->setText(string);
*/
    if(isOperator)
            double(b) = double(b)+0.1*double(b);
        else
            a = a+0.1*a;

        string += ".";
        ui->inputEdit->setText(string);
    qDebug()<<"a:"<<a<<endl;
    qDebug()<<"b:"<<b<<endl;
    qDebug()<<"result:"<<result<<endl;
}
