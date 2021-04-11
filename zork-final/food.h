#ifndef FOOD_H
#define FOOD_H

#include "Item.h"
#include "edible.h"
class Food : public Item, public Edible
{
private:
    bool consumed;
    int healthBoost;
public:
    Food(QString name, int healthBoost);
    int eat();
};

#endif // FOOD_H
