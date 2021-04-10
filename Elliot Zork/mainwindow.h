#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include "ZorkUL.h"
#include "popout.h"
#include <array>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE



class MainWindow : public QMainWindow
{
    Q_OBJECT

friend QPixmap* getAssets(MainWindow &);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // friend Ui::MainWindow *& getUI(MainWindow &);   return reference to the ui pointer


private slots:
    void on_takeBt_clicked();
    void on_JournalsBt_clicked();
    void on_searchBt_clicked();
    void on_northBt_clicked();
    void on_southBt_clicked();
    void on_eastBt_clicked();
    void on_westBt_clicked();
    void on_viewMapBt_clicked();

private:
    Ui::MainWindow* ui;
    ZorkUL* game;
    Popout* popout;
    QPixmap* assets[2];
    QGraphicsPixmapItem* pinMap;

    void print(const QString&);
    void printWelcome();
    void setupAssets();
    void updateCompass();

};
#endif // MAINWINDOW_H
