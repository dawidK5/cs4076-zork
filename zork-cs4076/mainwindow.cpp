#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "popout.h"
#include <QGraphicsItem>
#include <iostream>

using std::cout;
using std::endl;

int countMoves = 0;
int dayValue = 29;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), popout(new Popout)
{
    ui->setupUi(this);
    game = new ZorkUL();
    setupAssets();
    printWelcome();
}

MainWindow::~MainWindow()
{
    delete popout;
    delete pinMap;
    delete ui;
    for(const auto& a : assets)
        delete a;
    delete game;

}

/*
Ui::MainWindow *& getUI(MainWindow & win)
{
    return win.ui;
}
*/



void MainWindow::on_northBt_clicked() {
    print(game->go("north"));
    //ui->minimap->translate(-10, 1);
    pinMap->setY(pinMap->y() - 64);
    ui->minimap->centerOn(pinMap);
    countMoves++;
        if (countMoves == 4){
            ui->daysLeftLCD->display(dayValue--);
            countMoves = 0;
        }
        updateCompass();
}
void MainWindow::on_southBt_clicked() {
    print(game->go("south"));
    pinMap->setY(pinMap->y() + 64);
    ui->minimap->centerOn(pinMap);
    countMoves++;
        if (countMoves == 4){
            ui->daysLeftLCD->display(dayValue--);
            countMoves = 0;
        }
        updateCompass();
}


void MainWindow::on_eastBt_clicked() {
    print(game->go("east"));
    pinMap->setX(pinMap->x() + 64);
    ui->minimap->centerOn(pinMap);
    countMoves++;
        if (countMoves == 4){
            ui->daysLeftLCD->display(dayValue--);
            countMoves = 0;
        }
        updateCompass();

}
void MainWindow::on_westBt_clicked() {
    print(game->go("west"));
    pinMap->setX(pinMap->x() - 64);
    ui->minimap->centerOn(pinMap);
    countMoves++;
        if (countMoves == 4){
            ui->daysLeftLCD->display(dayValue--);
            countMoves = 0;
        }
        updateCompass();
}

void MainWindow::updateCompass() {
    ui->northBt->setDisabled( !(game->getCurrentRoom()->nextRoom("north")) );
    ui->southBt->setDisabled( !(game->getCurrentRoom()->nextRoom("south")) );
    ui->eastBt->setDisabled( !(game->getCurrentRoom()->nextRoom("east")) );
    ui->westBt->setDisabled( !(game->getCurrentRoom()->nextRoom("west")) );
}



void MainWindow::setupAssets() {
    assets[0] = new QPixmap(":/assets/mapwithgrid2.png");
    assets[1] = new QPixmap(":/assets/pin.png");
    const float scaleRatios[2] = {1.5, 8};
    for (int i = 0; i < 2; i++) {
        assets[i]->setDevicePixelRatio(scaleRatios[i]);
    }
    popout->setMap(*assets[0]);
    QScopedPointer<QGraphicsScene> scene(new QGraphicsScene());

    scene->addPixmap(*assets[0]);

    // where is the scene deleted

    pinMap = new QGraphicsPixmapItem(*assets[1]);
    pinMap->setTransformationMode(Qt::SmoothTransformation);
    pinMap->setScale(1);
    scene->addItem(pinMap);

    pinMap->setPos(337, 323);
    QGraphicsView*& mini = ui->minimap;


    mini->setScene(scene.take());

    mini->centerOn(pinMap);
    mini->show();

}

void MainWindow::printWelcome() {
    QTextBrowser*& tBoxRef = ui->storyTextBox;
    const QVector<QString> msgVect { "Welcome to The Dwindling Light",
                                "You are an explorer. You have crash-landed on an unknown planet, it wasn't on any maps but you are here nonetheless.",
                              "Your Hyperdrive seems to be broken, maybe you can find some resemblence of life and some parts to fix your Hyperdrive.",
                              "Have a look around."};
    for (auto& itr : msgVect)
    tBoxRef->append(itr);


    print(game->getCurrentRoom()->getRoomName());


}
void MainWindow::print(const QString& text) {
    ui->storyTextBox->append(text);
}

void MainWindow::on_viewMapBt_clicked()
{
    popout->show();
}

