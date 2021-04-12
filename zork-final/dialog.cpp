#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>

Dialog::Dialog(QWidget *parent, bool win) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    QMessageBox msgBox;

    if(win){
        QString winText =   "You Win! \n"
                            "You Brought Jeff with you when you left. He told you what happened."
                            "What really was going on: \n"
                            "This planet was going to be used to hide and test a device developed by the Separatists. It was develped as a device that would be able to stop a ship and pull it out of hyperspace. "
                            "This, obviously, would need increadible amounts of power and pulling force. Generally, ships are made parts with plenty steel so the device was essentially a giant magnet."
                            "The side effect of being able to completely immobilise a ship traveling one hundred thousand times faster than the speed of light is the ability to also drag the planet's moon out "
                            "of orbit. The island used to be a lot larger before the CIS experimental gravity well device began to pull the moon into the planet.  Now the moon changed the tides and the "
                            "ecosystem, killing all animal life and drowning a large portion of the lower lying lands of the island.";
        msgBox.setText(winText);
    }else{
        msgBox.setText("You Lost!");
    }

    msgBox.setStandardButtons(QMessageBox::Close);
    msgBox.setDefaultButton(QMessageBox::Close);
    int ret = msgBox.exec();
}

Dialog::~Dialog()
{
    delete ui;
}
