#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ZorkUL.h"
#include "popout.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    friend Ui::MainWindow *& getUI(MainWindow &);   // return reference to the ui pointer


private slots:
    void on_northBt_clicked();
    void on_southBt_clicked();
    void on_eastBt_clicked();
    void on_westBt_clicked();
    void on_viewMapBt_clicked();

private:
    Ui::MainWindow *ui;
    ZorkUL* game;
    Popout* popout;
    void printWelcome();
    void print(const QString&);
};
#endif // MAINWINDOW_H
