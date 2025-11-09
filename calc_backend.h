#define DEBUG
#ifdef DEBUG
#include <iostream>
#endif

#ifndef INC_1_CALC_BACKEND_H
#define INC_1_CALC_BACKEND_H
#include <chrono>
#include <string>
#include <cstdlib>
#include <QMainWindow>
#include <QtWidgets/QLineEdit>

class Calculator : public QMainWindow
{
    
private:
    bool cursor_on_first_number, first_num_double, second_num_double;
    long int first_num_i, second_num_i, result_i;
    double first_num_d, second_num_d, result_d;
    char operator_symbol;

    void calc_operator(char in_symbol);

    Q_OBJECT

public:
    QLineEdit* LineEdit_value1 = nullptr;
    QLineEdit* LineEdit_value2 = nullptr;
    QLineEdit* LineEdit_result = nullptr;

    explicit Calculator(QWidget* parent = nullptr);

public slots:
    void add0();
    void add1();
    void add2();
    void add3();
    void add4();
    void add5();
    void add6();
    void add7();
    void add8();
    void add9();
   
    void decimal_point();
    void addition();
    void substraction();
    void multiplication();
    void division();
    void calculate();
    void reset();
};

#endif //INC_1_CALC_BACKEND_H