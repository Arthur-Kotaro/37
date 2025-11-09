#include <QApplication>
#include <QMainWindow>

#include "./ui_calc.h"
#include "./calc_backend.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Calculator window(nullptr);
    Ui::MainWindow caller;
    caller.setupUi(&window);

    window.LineEdit_value1 = caller.lineEdit_value1;
    window.LineEdit_value2 = caller.lineEdit_value2;
    window.LineEdit_result = caller.lineEdit_result;

    window.resize(480, 640);
    window.show();


    return QApplication::exec();
}
