#include "calculator.h"
#include "ui_calculator.h"
#include <cmath>

calculator::calculator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::calculator)
{
    ui->setupUi(this);
    ui->lcdNumber_3->setDecMode();
    ui->lcdNumber_3->setDigitCount(10);
    num1 = 0;
    num2 = 0;
    operation = 0;
    decimalPlaced = false;
    placesIn = 1;
}

calculator::~calculator()
{
    delete ui;
}

void calculator::on_pushButton_14_clicked() //Button 0
{
    if(decimalPlaced)
    {
        placesIn++;
        return;
    }

    num1 = num1 * 10 + 0;
    ui->lcdNumber_3->display(num1);
}

void calculator::on_pushButton_11_clicked() //Button 1
{
    numberPressed(1);
}

void calculator::on_pushButton_10_clicked() //Button 2
{
    numberPressed(2);
}

void calculator::on_pushButton_16_clicked() //Button .
{
    decimalPlaced = true;
}

void calculator::on_pushButton_17_clicked() //Clear button
{
    decimalPlaced = false;
    num1 = 0;
    ui->lcdNumber_3->display(num1);
}

void calculator::on_pushButton_18_clicked() //CE button
{
    decimalPlaced = false;
    num1 = 0;
    num2 = 0;
    operation = 0;
    placesIn = 1;
    ui->lcdNumber_3->display(num1);
}

void calculator::on_pushButton_15_clicked()
{
    switch(operation)
    {
        case 0:
            return;
        case 1:
            num1 = num1 + num2;
            break;
        case 2:
            num1 = num2 - num1;
            break;
        case 3:
            num1 = num2 * num1;
            break;
        case 4:
            num1 = num2 / num1;
            break;
    }
    operation = 0;
    ui->lcdNumber_3->display(num1);
    if(floor(num1) == num1)
    {
        decimalPlaced = false;
        placesIn = 1;
    }
    else {
        decimalPlaced = true;
        double n = abs(num1);
        short places = 1;
        while(floor(n) != n)
        {
            places++;
            n = n * 10;
        }
        placesIn = places;
    }
}

void calculator::on_pushButton_clicked() //+ button
{
    on_pushButton_15_clicked();
    num2 = num1;
    num1 = 0;
    operation = 1;
    decimalPlaced = false;
    placesIn = 1;
}

void calculator::on_pushButton_3_clicked() //- Button
{
    on_pushButton_15_clicked();
    num2 = num1;
    num1 = 0;
    operation = 2;
    decimalPlaced = false;
    placesIn = 1;
}

void calculator::on_pushButton_2_clicked() //* button
{
    on_pushButton_15_clicked();
    num2 = num1;
    num1 = 0;
    operation = 3;
    decimalPlaced = false;
    placesIn = 1;
}

void calculator::on_pushButton_13_clicked() // / button
{
    on_pushButton_15_clicked();
    num2 = num1;
    num1 = 0;
    operation = 4;
    decimalPlaced = false;
    placesIn = 1;
}

void calculator::on_pushButton_12_clicked() //3 button
{
    numberPressed(3);
}

void calculator::on_pushButton_7_clicked() //4 button
{
    numberPressed(4);
}

void calculator::numberPressed(int num)
{
    if(decimalPlaced)
    {
        if(num1 >= 0)
            num1 = num1 + (num*(1.0/pow(10,placesIn)));
        else {
            num1 = num1 - (num*(1.0/pow(10,placesIn)));
        }
        placesIn++;
        ui->lcdNumber_3->display((num1));
        return;
    }

    if(num1 >= 0)
        num1 = num1 * 10 + num;
    else {
        num1 = num1 * 10 - num;
    }
    ui->lcdNumber_3->display(num1);
}

void calculator::on_pushButton_8_clicked()
{
    numberPressed(5);
}

void calculator::on_pushButton_9_clicked()
{
    numberPressed(6);
}

void calculator::on_pushButton_4_clicked()
{
    numberPressed(7);
}

void calculator::on_pushButton_5_clicked()
{
    numberPressed(8);
}

void calculator::on_pushButton_6_clicked()
{
    numberPressed(9);
}

void calculator::on_pushButton_19_clicked() // Negative button
{
    num1 = num1 * -1;
    ui->lcdNumber_3->display(num1);
}
