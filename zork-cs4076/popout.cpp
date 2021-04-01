#include "popout.h"
#include "ui_popout.h"
#include <QPixmap>

Popout::Popout(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Popout)
{
    ui->setupUi(this);
}

Popout::~Popout()
{
    delete ui;
}
void Popout::setMap(const QPixmap& map) {
    ui->label->setPixmap(map);
}
