#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "popout.h"
#include "dialog.h"
#include "journals.h"
#include <QGraphicsItem>
#include <iostream>
#include <QListWidget>
#include "Item.h"
#include "Room.h"
#include "ZorkUL.h"

using std::cout;
using std::endl;

int countMoves = 0;
int dayValue = 30;
int wining = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), popout(new Popout)
{
    ui->setupUi(this);
    game = new ZorkUL();
    ui->JournalsBt->hide();
    ui->searchBt->hide();
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

void MainWindow::on_takeBt_clicked() {
    int x = 0;
    QString tempString;
    vector <Item> items = game->getCurrentRoom()->getItems();
    for (int n = game->getCurrentRoom()->numberOfItems(); n > 0; n--) {
        tempString = tempString + items[x].getShortDescription();
        print("Item Taken =" + tempString);
        ui->itemsList->addItem(tempString);
        if(tempString.size() > 6){
            tempString = tempString.left(6);
            //print();
        }
        if (tempString == "Engine"){
            wining = wining + 1;
        }
        if(wining == 4){
            bool test = true;
            Dialog win(nullptr, test);
            win.show();
            ui-> daysLeftLCD->display(30);
            game = new ZorkUL();
            printWelcome();
            countMoves = 0;
            dayValue = 30;
            pinMap->setPos(337, 323);
            updateCompass();
            ui->minimap->centerOn(pinMap);

        }
        tempString = "";
        if(game->getCurrentRoom()->getRoomName() == "Facility"){
            ui->JournalsBt->show();
        }
        Item *itemRem = &items[x];
        x++;
    }
    game->getCurrentRoom()->removeItems();
}

void MainWindow::on_JournalsBt_clicked() {
    Journals j;
    j.show();
}

void MainWindow::on_searchBt_clicked() {
    print(game->setCurRoom());
    updateCompass();
    if(game->getCurrentRoom()->getRoomName() == "Facility"){
        ui->searchBt->setText("Leave Facility");
        ui->searchBt->update();
    }else{
        ui->searchBt->setText("Search Facility");
        ui->searchBt->update();

    }
    /*ui->eastBt->setDisabled();
    ui->southBt->setDisabled();
    ui->westBt->setDisabled();*/
}

void MainWindow::on_northBt_clicked() {
    print(game->go("north"));
    //ui->minimap->translate(-10, 1);
    pinMap->setY(pinMap->y() - 64);
    ui->minimap->centerOn(pinMap);
    countMoves++;
        if (countMoves == 4){
            ui->daysLeftLCD->display(--dayValue);
            countMoves = 0;
        }
        updateCompass();
        if(dayValue == 0){
            Dialog d;
            d.show();
            ui-> daysLeftLCD->display(30);
            game = new ZorkUL();
            printWelcome();
            countMoves = 0;
            dayValue = 30;
            pinMap->setPos(337, 323);
            updateCompass();
            ui->minimap->centerOn(pinMap);
        }
        if(game->getCurrentRoom()->getRoomName() == "Mountain With Door"){
            ui->searchBt->show();
        }else{
            ui->searchBt->hide();
        }
}
void MainWindow::on_southBt_clicked() {
    print(game->go("south"));
    pinMap->setY(pinMap->y() + 64);
    ui->minimap->centerOn(pinMap);
    countMoves++;
        if (countMoves == 4){
            ui->daysLeftLCD->display(--dayValue);
            countMoves = 0;
        }
        updateCompass();
        if(dayValue == 0){
            Dialog d;
            d.show();
            ui-> daysLeftLCD->display(30);
            game = new ZorkUL();
            printWelcome();
            countMoves = 0;
            dayValue = 30;
            pinMap->setPos(337, 323);
            updateCompass();
            ui->minimap->centerOn(pinMap);
        }
        if(game->getCurrentRoom()->getRoomName() == "Mountain With Door"){
            ui->searchBt->show();
        }else{
            ui->searchBt->hide();
        }
}


void MainWindow::on_eastBt_clicked() {
    print(game->go("east"));
    pinMap->setX(pinMap->x() + 64);
    ui->minimap->centerOn(pinMap);
    countMoves++;
        if (countMoves == 4){
            ui->daysLeftLCD->display(--dayValue);
            countMoves = 0;
        }
        updateCompass();
        if(dayValue == 0){
            Dialog d;
            d.show();
            ui-> daysLeftLCD->display(30);
            game = new ZorkUL();
            printWelcome();
            countMoves = 0;
            dayValue = 30;
            pinMap->setPos(337, 323);
            updateCompass();
            ui->minimap->centerOn(pinMap);
        }
        if(game->getCurrentRoom()->getRoomName() == "Mountain With Door"){
            ui->searchBt->show();
        }else{
            ui->searchBt->hide();
        }

}
void MainWindow::on_westBt_clicked() {
    print(game->go("west"));
    pinMap->setX(pinMap->x() - 64);
    ui->minimap->centerOn(pinMap);
    countMoves++;
        if (countMoves == 4){
            ui->daysLeftLCD->display(--dayValue);
            countMoves = 0;
        }
        updateCompass();
        if(dayValue == 0){
            Dialog d;
            d.show();
            ui-> daysLeftLCD->display(30);
            game = new ZorkUL();
            printWelcome();
            countMoves = 0;
            dayValue = 30;
            pinMap->setPos(337, 323);
            updateCompass();
            ui->minimap->centerOn(pinMap);

        }
        if(game->getCurrentRoom()->getRoomName() == "Mountain With Door"){
            ui->searchBt->show();
        }else{
            ui->searchBt->hide();
        }
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

