#include "dialog.h"
#include "human.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "nodescriptionexcpt.h"
#include "journals.h"
#include "food.h"
#include <iostream>
using std::cout;
using std::endl;

using droidfrnd::droid, nde::NoDescriptionExcpt;

int countMoves = 0;
int dayValue = 10;
int wining = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), popout(new Popout)
{
    ui->setupUi(this);
    game = new ZorkUL();

    setupAssets();
    resetGui();
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





void MainWindow::on_takeBt_clicked() {
    int x = 0;
    QString tempString;
    vector <Item> items = game->getCurrentRoom()->getItems();
    for (int n = game->getCurrentRoom()->numberOfItems(); n > 0; n--) {
        tempString = tempString + items[x].getShortDescription();
        print("Item Taken =" + tempString);
        ui->itemsList->addItem(tempString);
        if(tempString == "Nuts") {
            ui->eatBt->show();
        }
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

            game->resetGame();
            resetGui();

        }
        tempString = "";
        if(game->getCurrentRoom()->getRoomName() == "Facility"){
            ui->JournalsBt->show();
        }
        // Item *itemRem = &items[x];
        x++;
    }
    game->getCurrentRoom()->removeItems();
}

void MainWindow::on_JournalsBt_clicked() {
    Journals j;
    j.show();
}

void MainWindow::on_searchBt_clicked() {
    if(ui->torchOnBt->isChecked()) {
        try {
            print(game->setCurRoom());

        }  catch (NoDescriptionExcpt &e) {
            cout << e.what() <<endl;
        }

        updateCompass();

        /*ui->eastBt->setDisabled();
    ui->southBt->setDisabled();
    ui->westBt->setDisabled();*/
    } else {
        print("It's too dark out there, turn on your torch");
    }
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
        game->resetGame();
        resetGui();
    } else {
        checkForNpcs();
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
        game->resetGame();
        resetGui();
    } else {
        checkForNpcs();
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
        game->resetGame();
        resetGui();
    } else {
        checkForNpcs();
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
        game->resetGame();
        resetGui();
    }  else {
        checkForNpcs();
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
    if(game->getCurrentRoom()->getRoomName() == "Facility"){
        ui->searchBt->setText("Leave Facility");
        ui->searchBt->update();
        if(ui->torchOnBt->isChecked()) {
            checkForNpcs();
        }
    }else{
        ui->searchBt->setText("Search Facility");
        ui->searchBt->update();

    }
}

void MainWindow::disableCompass() {
    ui->northBt->setDisabled(true);
    ui->southBt->setDisabled(true);
    ui->eastBt->setDisabled(true);
    ui->westBt->setDisabled(true);
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
void MainWindow::checkForNpcs() {
    Room& cRoom = *game->getCurrentRoom();
    if(cRoom.hasNpc()) {
        try {
            print(cRoom.getNpc()->getDialogue());
            if(!cRoom.hasDroid()) {  // not null, non droid, must be human
                // ui->tradeBt->setDisabled(true);
                // ui->tradeBt->show();
            } else {    // droid
                disableCompass();

                ui->tradeBt->hide();
                if(!cRoom.getDroid()->isDead()) {
                    ui->attackBt->show();
                    ui->searchBt->hide();
                } else {
                    ui->attackBt->hide();
                }


            }
        }  catch (const std::exception& e) {
            cout << e.what() <<endl;
        }
    } else {
        ui->tradeBt->hide();
    }
}

Item* droidfrnd::getDropItem(droid & d) {
    return d.drop;
}

void MainWindow::on_attackBt_clicked()
{
    droid* enemy = (game->getCurrentRoom()->getDroid());
    print( *enemy + (* (game->getWeapon())));

    if(enemy->isDead()) {

        ui->attackBt->hide();
        if(game->getCurrentRoom()->getRoomName() == "Facility") {

            ui->searchBt->show();

        } else {
            updateCompass();
        }
        game->getCurrentRoom()->addItem(new Item( *getDropItem(*enemy)) );

        return;

    } else {
        if(rand()%2) {
            int hit = rand() % 30 + 5;
            print(QStringLiteral("Ouch, you got hit! -%1 HP").arg(hit));
            int hp = ui->healthBar->value();
            if (hit >= hp)
            {
                print( QStringLiteral("Sorry, you died.") );
                ui->healthBar->setValue(0);
                // function call for resetting the game + dialog here
                Dialog d;
                d.show();
                game->resetGame();
                resetGui();

                // game = new ZorkUL();


            }
            ui->healthBar->setValue(hp-hit);
        }
    }
    // ui->attackBt->setDisabled(false);

}



void MainWindow::on_tradeBt_clicked()
{
    ui->tradeBt->setDisabled(true);
    QListWidget* const inv = ui->itemsList;
    Human* const tradesman = static_cast<Human*>(game->getCurrentRoom()->getNpc());
    QString iName = inv->currentItem()->text();
    if( iName == tradesman->getInItemName()) {

        ui->tradeBt->hide();
        ui->tradeBt->setDisabled(true);
        delete inv->takeItem(inv->currentRow());

        game->getCurrentRoom()->addItem(new Item(tradesman->trade()));
        print(tradesman->getDialogue());



    } else {
        if(inv->currentItem() != nullptr) {
            print(QStringLiteral("%1 is not what I'm looking for. If you find an advanced PCB come back so we can trade.\"").arg(inv->currentItem()->text()));
        } else {
            print("\"All right, so which item do you want to trade?\" Jeff asked.");
        }
        ui->tradeBt->setDisabled(false);
    }

}


void MainWindow::on_itemsList_itemClicked(QListWidgetItem *item)
{
    // item->setSelected(true);
    if(game->getCurrentRoom()->hasNpc() && !game->getCurrentRoom()->hasDroid()) {
        if(!static_cast<Human*>(game->getCurrentRoom()->getNpc())->stillHasItem()) {
            ui->tradeBt->setDisabled(true);
            ui->tradeBt->hide();
        } else {
            ui->tradeBt->setDisabled(false);
            ui->tradeBt->show();
        }
    }

}

void MainWindow::resetGui() {
    countMoves = 0;
    dayValue = 10;
    wining = 0;
    ui-> daysLeftLCD->display(10);
    ui->eatBt->hide();
    ui->healthBar->setValue(40);
    ui->itemsList->clear();
    ui->tradeBt->hide();
    ui->tradeBt->setDisabled(true);
    ui->attackBt->hide();
    // ui->attackBt->setDisabled(false);
    ui->JournalsBt->hide();
    ui->searchBt->hide();
    updateCompass();
    ui->torchOffBt->setChecked(true);
    pinMap->setPos(337, 323);
    ui->minimap->centerOn(pinMap);
    ui->storyTextBox->clear();
    printWelcome();
}

void MainWindow::on_torchOnBt_toggled(bool checked)
{
    print(QStringLiteral("Your torch is now ") + (checked ? "on" : "off"));
    if(game->getCurrentRoom()->getRoomName() == "Facility") {               // during fight
        if(!checked && !( game->getCurrentRoom()->getDroid()->isDead())) {
            print(QStringLiteral("You immerse yourself in darkness and use the force to guide your attacks. But you're not a Jedi and the droid had an IR sensor, so you die."));
            Dialog d;
            d.show();
            game->resetGame();
            resetGui();

        } else {
            checkForNpcs();
        }
    }
}

void MainWindow::on_torchOffBt_toggled(bool checked)
{

}


void MainWindow::on_eatBt_clicked()
{
    int row = ui->itemsList->currentRow();
    if(ui->itemsList->currentItem() != nullptr) {
        if(ui->itemsList->currentItem()->text() == "Nuts") {
            Food* f = new Food("Nuts", 60);
            ui->itemsList->takeItem( row );
            print(QStringLiteral("Nuts has been eaten, + %1HP").arg(f->eat()));
            ui->healthBar->setValue(ui->healthBar->value()+ 60);
            delete f;
        } else {
            print(QStringLiteral("Sorry, you can't eat %1").arg(ui->itemsList->currentItem()->text()));
        }
    } else {
        print(QStringLiteral("Click on  the item to eat"));
    }
}

