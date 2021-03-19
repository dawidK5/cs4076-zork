#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
