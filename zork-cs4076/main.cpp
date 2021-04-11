#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#line 0

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    std::cout << QStringLiteral("Reached line %1 in main.cpp").arg(__LINE__).toStdString() << std::endl;
    return a.exec();
}
