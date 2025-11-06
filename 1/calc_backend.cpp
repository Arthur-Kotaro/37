#include "calc_backend.h"

void Calculator::add0()
{
    if(cursor_on_first_number) LineEdit_value1->setText(LineEdit_value1->text() + "0");
    else  LineEdit_value2->setText(LineEdit_value2->text() + "0");
};
void Calculator::add1()
{
    if(cursor_on_first_number) LineEdit_value1->setText(LineEdit_value1->text() + "1");
    else  LineEdit_value2->setText(LineEdit_value2->text() + "1");
};
void Calculator::add2()
{
    if(cursor_on_first_number) LineEdit_value1->setText(LineEdit_value1->text() + "2");
    else  LineEdit_value2->setText(LineEdit_value2->text() + "2");
};
void Calculator::add3()
{
    if(cursor_on_first_number) LineEdit_value1->setText(LineEdit_value1->text() + "3");
    else  LineEdit_value2->setText(LineEdit_value2->text() + "3");
};
void Calculator::add4()
{
    if(cursor_on_first_number) LineEdit_value1->setText(LineEdit_value1->text() + "4");
    else  LineEdit_value2->setText(LineEdit_value2->text() + "4");
};
void Calculator::add5()
{
    if(cursor_on_first_number) LineEdit_value1->setText(LineEdit_value1->text() + "5");
    else  LineEdit_value2->setText(LineEdit_value2->text() + "5");
};
void Calculator::add6()
{
    if(cursor_on_first_number) LineEdit_value1->setText(LineEdit_value1->text() + "6");
    else  LineEdit_value2->setText(LineEdit_value2->text() + "6");
};
void Calculator::add7()
{
    if(cursor_on_first_number) LineEdit_value1->setText(LineEdit_value1->text() + "7");
    else  LineEdit_value2->setText(LineEdit_value2->text() + "7");
};
void Calculator::add8()
{
    if(cursor_on_first_number) LineEdit_value1->setText(LineEdit_value1->text() + "8");
    else  LineEdit_value2->setText(LineEdit_value2->text() + "8");
};
void Calculator::add9()
{
    if(cursor_on_first_number) LineEdit_value1->setText(LineEdit_value1->text() + "9");
    else  LineEdit_value2->setText(LineEdit_value2->text() + "9");
};

Calculator::Calculator(QWidget* parent): QMainWindow(parent), cursor_on_first_number(true), first_num_double(false), second_num_double(false){}

void Calculator::addition() { calc_operator('+'); };
void Calculator::substraction() { calc_operator('-'); };
void Calculator::multiplication() { calc_operator('*'); };
void Calculator::division() { calc_operator('/'); };


void Calculator::decimal_point()
{
    if(cursor_on_first_number && !first_num_double)
    {
        LineEdit_value1->setText(LineEdit_value1->text() + ".");
        first_num_double = true;
    }
    else if(!cursor_on_first_number && !second_num_double)
    {
        LineEdit_value2->setText(LineEdit_value2->text() + ".");
        second_num_double = true;
    }
};

void Calculator::reset()
{
    cursor_on_first_number = true;
    first_num_double = false;
    second_num_double = false;
    LineEdit_value1->clear();
    LineEdit_value2->clear();
    LineEdit_result->clear();
};

void Calculator::calc_operator(char in_symbol)
{
    if(cursor_on_first_number)
    {
        cursor_on_first_number = false;
        operator_symbol = in_symbol;
        if(first_num_double) first_num_d = LineEdit_value1->text().toDouble();
        else first_num_i = LineEdit_value1->text().toLong();
        LineEdit_value1->setText(LineEdit_value1->text() + " " + operator_symbol);
    }
}

void Calculator::calculate()
{
    if(!cursor_on_first_number)
    {
        if (second_num_double) second_num_d = LineEdit_value2->text().toDouble();
        else second_num_i = LineEdit_value2->text().toLong();
        if (!first_num_double && !second_num_double)
        {
            switch (operator_symbol)
            {
                case '+': result_i = first_num_i + second_num_i;
                    break;
                case '-': result_i = first_num_i - second_num_i;
                    break;
                case '/':
                {
                    if(second_num_i == 0)
                    {
                        LineEdit_result->setText("Inf");
                        return;
                    }
                    else
                    {
                        result_i = first_num_i / second_num_i;
                        break;
                    }
                }

                case '*': result_i = first_num_i * second_num_i;
                    break;
            }

            LineEdit_result->setText(QString::number(result_i));
        }
        else
        {
            if (first_num_double && second_num_double)
                switch (operator_symbol)
                {
                    case '+': result_d = first_num_d + second_num_d;
                        break;
                    case '-': result_d = first_num_d - second_num_d;
                        break;
                    case '/': result_d = first_num_d / second_num_d;
                        break;
                    case '*': result_d = first_num_d * second_num_d;
                        break;
                }

            if (first_num_double && !second_num_double)
                switch (operator_symbol)
                {
                    case '+': result_d = first_num_d + static_cast<double>(second_num_i);
                        break;
                    case '-': result_d = first_num_d - static_cast<double>(second_num_i);
                        break;
                    case '/': result_d = first_num_d / static_cast<double>(second_num_i);
                        break;
                    case '*': result_d = first_num_d * static_cast<double>(second_num_i);
                        break;
                }

            if (!first_num_double && second_num_double)
                switch (operator_symbol)
                {
                    case '+': result_d = result_d = static_cast<double>(first_num_i) + second_num_d;
                        break;
                    case '-': result_d = result_d = static_cast<double>(first_num_i) - second_num_d;
                        break;
                    case '/': result_d = result_d = static_cast<double>(first_num_i) / second_num_d;
                        break;
                    case '*': result_d = result_d = static_cast<double>(first_num_i) * second_num_d;
                        break;
                }
            LineEdit_result->setText(QString::number(result_d));
        }
#ifdef DEBUG
        std::cout << "first_num_i = "<< first_num_i << std::endl << "second_num_i = "<< second_num_i << std::endl << "result_i = " << result_i << std::endl << std::endl
        << "first_num_d = "<< first_num_d << std::endl << "second_num_d = "<< second_num_d << std::endl << "result_d = " << result_d << std::endl << std::endl;
#endif
    }
};