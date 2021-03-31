#include "popout.h"
#include "ui_popout.h"
#include <QPixmap>

Popout::Popout(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Popout)
{
    ui->setupUi(this);

    QPixmap pix(":/assets/mapwithgrid.png");
    pix.setDevicePixelRatio(4);
    ui->label->setPixmap(pix);
}

Popout::~Popout()
{
    delete ui;
}
