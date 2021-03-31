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
    // loadAssets();
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
    ui->minimap->translate(-10, 1);
    countMoves++;
        if (countMoves == 4){
            ui->daysLeftLCD->display(dayValue--);
            countMoves = 0;
        }
}
void MainWindow::on_southBt_clicked() {
    print(game->go("south"));
    countMoves++;
        if (countMoves == 4){
            ui->daysLeftLCD->display(dayValue--);
            countMoves = 0;
        }

}
void MainWindow::on_eastBt_clicked() {
    print(game->go("east"));
    countMoves++;
        if (countMoves == 4){
            ui->daysLeftLCD->display(dayValue--);
            countMoves = 0;
        }
}
void MainWindow::on_westBt_clicked() {
    print(game->go("west"));
    countMoves++;
        if (countMoves == 4){
            ui->daysLeftLCD->display(dayValue--);
            countMoves = 0;
        }
}



void MainWindow::printWelcome() {
    QTextBrowser*& tBoxRef = ui->storyTextBox;
    const QVector<QString> msgVect { "Welcome to The Dwindling Light",
                                "You are an explorer. You have crash-landed on an unknown planet, it wasn't on any maps but you are here nonetheless.",
                              "Your Hyperdrive seems to be broken, maybe you can find some resemblence of life and some parts to fix your Hyperdrive.",
                              "Have a look around."};
    for (auto& itr : msgVect)
    tBoxRef->append(itr);

    // ui->daysLeftLCD->display(dayValue);
    QGraphicsScene* scene = new QGraphicsScene();
    // scene->setSceneRect(0, 0, 161, 131);

    QPixmap* image = new QPixmap(":/assets/mapwithgrid.png");
    image->setDevicePixelRatio(4);
    scene->addPixmap(*image);
    QPixmap* pin = new QPixmap(":/assets/pin.png");
    pin->setDevicePixelRatio(8);
    QGraphicsPixmapItem* pinMap = new QGraphicsPixmapItem(*pin);
    pinMap->setTransformationMode(Qt::SmoothTransformation);
    pinMap->setScale(1);
    scene->addItem(pinMap);

    pinMap->setPos(307, 300);
    /*


    scene->addPixmap(*pin);
    */
    ui->minimap->setScene(scene);
    // ui->minimap->fitInView(dynamic_cast<QGraphicsItem *>(pin));
    ui->minimap->centerOn(pinMap);
    ui->minimap->show();
    print(game->getCurrentRoom()->getRoomName());


}
void MainWindow::print(const QString& text) {
    ui->storyTextBox->append(text);
}

void MainWindow::on_viewMapBt_clicked()
{
    popout->show();
}

