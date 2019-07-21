#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QString>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    enable(); // initialization : no coin inserted yet, so any option can't be selected
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int n)
{
    money += n;
    ui->lcdNumber->display(money);
}


void Widget::enable()
{

    if(money<100)
    {
        ui->pbCola->setEnabled(false);
        ui->pbTea->setEnabled(false);
        ui->pbCoffee->setEnabled(false);
    }
    else if(money<150)
    {
       ui->pbCola->setEnabled(false);
       ui->pbTea->setEnabled(false);
       ui->pbCoffee->setEnabled(true);
    }
    else if(money<200)
    {
      ui->pbCola->setEnabled(false);
      ui->pbTea->setEnabled(true);
      ui->pbCoffee->setEnabled(true);
    }
    else if(money>=200)
    {
        ui->pbCola->setEnabled(true);
        ui->pbTea->setEnabled(true);
        ui->pbCoffee->setEnabled(true);
    }


}





void Widget::on_pb10_clicked()
{
   changeMoney(10);
   enable();
}

void Widget::on_pb50_clicked()
{
   changeMoney(50);
   enable();
}

void Widget::on_pb100_clicked()
{
   changeMoney(100);
   enable();
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
    enable();
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
    enable();
}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
    enable();
}

void Widget::on_pbCola_clicked()
{
    changeMoney(-200);
    enable();
}

void Widget::on_ReturnChange_clicked()
{
    int c500 = 0;
    int c100 = 0;
    int c50 = 0;
    int c10 = 0;

    while(money!=0){

    if(money>=500)
    {
        changeMoney(-500);
        c500++;
    }
    else if(money >= 100)
    {
        changeMoney(-100);
        c100++;
    }
    else if(money >= 50)
    {
        changeMoney(-50);
        c50++;
    }
    else if(money >= 10)
    {
        changeMoney(-10);
        c10++;
    }

    }
    QString coinstr =
            "500: " + QString::number(c500) +
            "\n100:  "+QString::number(c100) +
            "\n50: "+QString::number(c50) +
            "\n10: "+QString::number(c10);


    QMessageBox msg;
    msg.information(nullptr,"coin change",coinstr);

}


