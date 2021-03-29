#include "mainwindow.h"
#include "popout.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , popout(new Popout)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


Ui::MainWindow *& getUI(MainWindow & win)
{
    return win.ui;
}

void MainWindow::on_viewMapBt_clicked()
{
    popout->show();
}
