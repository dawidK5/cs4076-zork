#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"

class Weapon : public Item
{
public:
    Weapon(QString name, int wDamage);
    int getDamage() const;
private:
    int damage;
};

#endif // WEAPON_H
