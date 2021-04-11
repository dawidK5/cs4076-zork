#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ZorkUL.h"
#include <QGraphicsPixmapItem>
#include "popout.h"
#include <QListWidgetItem>

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



private slots:
    void on_takeBt_clicked();
    void on_JournalsBt_clicked();
    void on_searchBt_clicked();
    void on_northBt_clicked();
    void on_southBt_clicked();
    void on_eastBt_clicked();
    void on_westBt_clicked();
    void on_viewMapBt_clicked();
    void on_attackBt_clicked();
    void on_tradeBt_clicked();
    void on_itemsList_itemClicked(QListWidgetItem *item);

private:
    Ui::MainWindow* ui;
    ZorkUL* game;
    Popout* popout;
    QPixmap* assets[2];
    QGraphicsPixmapItem* pinMap;

    void print(const QString&);
    void printWelcome();
    void setupAssets();
    void resetGui();
    void updateCompass();
    void disableCompass();
    void checkForNpcs();

};
#endif // MAINWINDOW_H
