#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "popout.h"

#include <iostream>
using std::cout;
using std::endl;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), popout(new Popout)
{
    ui->setupUi(this);
    game = new ZorkUL();
    printWelcome();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete popout;
    delete game;
}

Ui::MainWindow *& getUI(MainWindow & win)
{
    return win.ui;
}




void MainWindow::on_northBt_clicked() {
    print(game->go("north"));
}
void MainWindow::on_southBt_clicked() {
    print(game->go("south"));
}
void MainWindow::on_eastBt_clicked() {
    print(game->go("east"));
}
void MainWindow::on_westBt_clicked() {
    print(game->go("west"));
}


void MainWindow::printWelcome() {
    QTextBrowser*& tBoxRef = ui->storyTextBox;
    const QVector<QString> msgVect { "Welcome to The Dwindling Light",
                                "You are an explorer. You have crash-landed on an unknown planet, it wasn't on any maps but you are here nonetheless.",
                              "Your Hyperdrive seems to be broken, maybe you can find some resemblence of life and some parts to fix your Hyperdrive.",
                              "Have a look around."};
    for (auto& itr : msgVect)
    tBoxRef->append(itr);


    // myUi->daysLeftLCD->set
    print(game->getCurrentRoom()->getRoomName());


}
void MainWindow::print(const QString& text) {
    ui->storyTextBox->append(text);
}

void MainWindow::on_viewMapBt_clicked()
{
    popout->show();
}

