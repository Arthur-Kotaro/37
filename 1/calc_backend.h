// Created by Kotaro on 04.11.2025.

#ifndef INC_1_CALC_BACKEND_H
#define INC_1_CALC_BACKEND_H
#include <chrono>
#include <string>
#include <QMainWindow>
#include <QtWidgets/QLineEdit>

class Calculator : public QMainWindow
{
    bool first_number;
    bool first_num_float, second_num_float;
    long int first_num_i, second_num_i;
    double first_num_f, second_num_f;
    char operator_symbol;
    Q_OBJECT
public:
    QLineEdit* LineEdit_value1 = nullptr;
    QLineEdit* LineEdit_value2 = nullptr;
    QLineEdit* LineEdit_result = nullptr;
    explicit Calculator(QWidget* parent = nullptr): QMainWindow(parent), first_number(true), first_num_float(false), second_num_float(false){}
public slots:
    void add0()
    {
        if(first_number) LineEdit_value1->setText(LineEdit_value1->text() + "0");
        else  LineEdit_value2->setText(LineEdit_value1->text() + "0");
    };
    void add1()
    {
        if(first_number) LineEdit_value1->setText(LineEdit_value1->text() + "1");
        else  LineEdit_value2->setText(LineEdit_value1->text() + "1");
    };
    void add2()
    {
        if(first_number) LineEdit_value1->setText(LineEdit_value1->text() + "2");
        else  LineEdit_value2->setText(LineEdit_value1->text() + "2");
    };
    void add3()
    {
        if(first_number) LineEdit_value1->setText(LineEdit_value1->text() + "3");
        else  LineEdit_value2->setText(LineEdit_value1->text() + "3");
    };
    void add4()
    {
        if(first_number) LineEdit_value1->setText(LineEdit_value1->text() + "4");
        else  LineEdit_value2->setText(LineEdit_value1->text() + "4");
    };
    void add5()
    {
        if(first_number) LineEdit_value1->setText(LineEdit_value1->text() + "5");
        else  LineEdit_value2->setText(LineEdit_value1->text() + "5");
    };
    void add6()
    {
        if(first_number) LineEdit_value1->setText(LineEdit_value1->text() + "6");
        else  LineEdit_value2->setText(LineEdit_value1->text() + "6");
    };
    void add7()
    {
        if(first_number) LineEdit_value1->setText(LineEdit_value1->text() + "7");
        else  LineEdit_value2->setText(LineEdit_value1->text() + "7");
    };
    void add8()
    {
        if(first_number) LineEdit_value1->setText(LineEdit_value1->text() + "8");
        else  LineEdit_value2->setText(LineEdit_value1->text() + "8");
    };
    void add9()
    {
        if(first_number) LineEdit_value1->setText(LineEdit_value1->text() + "9");
        else  LineEdit_value2->setText(LineEdit_value1->text() + "9");
    };
    void decimal_point()
    {
        if(first_number && !first_num_float) 
        {
            LineEdit_value1->setText(LineEdit_value1->text() + ",");
            first_num_float = true;
        }
        else if(!first_number && !second_num_float)
        {
            LineEdit_value2->setText(LineEdit_value2->text() + ",");
            second_num_float = true;
        }
    };
    void addition()
    {
        if(first_number)
        {
            first_number = false;
            operator_symbol = '+';
            if(first_num_float) first_num_i = std::strtod();
            else first_num_float = std::strtol();
            LineEdit_value1->setText(LineEdit_value1->text() + " " + operator_symbol);
        }
    };
    void substraction()
    {
        if(first_number) LineEdit_value1->setText(LineEdit_value1->text() + "0");
        else  LineEdit_value2->setText(LineEdit_value1->text() + "0");
    };
    void multiplication()
    {
        if(first_number) LineEdit_value1->setText(LineEdit_value1->text() + "0");
        else  LineEdit_value2->setText(LineEdit_value1->text() + "0");
    };
    void division()
    {

    };
    void reset()
    {
        first_number = true;
        first_num_float = second_num_float = false;
        LineEdit_value1->text().erase();
        LineEdit_value2->text().erase();
        LineEdit_result->text().erase();
        update();

    };
    void calculate()
    {
        if(!first_number)
        {
            if (second_num_float) second_num_i = std::strtod();
            else second_num_float = std::strtol();
            if (first_num_float && second_num_float) LineEdit_result->setText(first_num_f + second_num_f);
            if (!first_num_float && !second_num_float) LineEdit_result->setText(first_num_i + second_num_i);
            if (first_num_float && !second_num_float) LineEdit_result-> setText(first_num_f + (double)second_num_i);
            if (!first_num_float && second_num_float) LineEdit_result->setText((double)first_num_i + second_num_f);
        }
    };
};

#endif //INC_1_CALC_BACKEND_H
