#ifndef HUMAN_H
#define HUMAN_H

#include "npc.h"

class Human : public Npc
{
    // friend Item* getReward(const Human&);
public:
    Human(QString, Item *);
    ~Human();
    // single bartering
    QString getDialogue();
    bool tradesItem(const Item&);
    Item trade();
    QString getInItemName();
    bool stillHasItem();

private:
    Item* reward;
    QString allowedItem;
    unsigned char ind;
};

#endif // HUMAN_H
