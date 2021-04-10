#include "mainwindow.h"
#include <QApplication>
#include <iostream>
QMap<QString, QString> Room::descrMap = QMap<QString, QString>();


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
