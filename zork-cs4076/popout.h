#ifndef POPOUT_H
#define POPOUT_H

#include <QWidget>

namespace Ui {
class Popout;
}

class Popout : public QWidget
{
    Q_OBJECT

public:
    explicit Popout(QWidget *parent = nullptr);
    ~Popout();

private:
    Ui::Popout *ui;
};

#endif // POPOUT_H
