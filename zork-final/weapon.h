#pragma once

#include "Item.h"

class Weapon : public Item
{
public:
    Weapon(QString name, int wDamage);
    int getDamage() const;
private:
    int damage;
};
