#ifndef JOURNALS_H
#define JOURNALS_H

#include <QDialog>

namespace Ui {
class Journals;
}

class Journals : public QDialog
{
    Q_OBJECT

public:
    explicit Journals(QWidget *parent = nullptr);
    ~Journals();

private:
    Ui::Journals *ui;
};

#endif // JOURNALS_H
