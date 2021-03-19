#include "mainwindow.h"
#include "ZorkUL.h"

#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    ZorkUL(getUI(w));
    w.show();
    return a.exec();
}
