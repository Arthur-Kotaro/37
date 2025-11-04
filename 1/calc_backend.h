//
// Created by Kotaro on 04.11.2025.
//

#ifndef INC_1_CALC_BACKEND_H
#define INC_1_CALC_BACKEND_H

#include <QMainWindow>
#include <QtWidgets/QLineEdit>

class Calculator : public QMainWindow
{
    bool first_number = true;
    Q_OBJECT
public:
    QLineEdit* LineEdit_value1 = nullptr;
    QLineEdit* LineEdit_value2 = nullptr;
    QLineEdit* LineEdit_result = nullptr;
    explicit Calculator(QWidget* parent = nullptr): QMainWindow(parent) {}
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
        if(first_number) LineEdit_value1->setText(LineEdit_value1->text() + "0");
        else  LineEdit_value2->setText(LineEdit_value1->text() + "0");
    };
    void addition()
    {
        if(first_number) LineEdit_value1->setText(LineEdit_value1->text() + "0");
        else  LineEdit_value2->setText(LineEdit_value1->text() + "0");
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
        LineEdit_value1->text().clear();
        LineEdit_value2->text().clear();
        LineEdit_result->text().clear();
        update();

    };
    void calculate()
    {

    };
};

#endif //INC_1_CALC_BACKEND_H
