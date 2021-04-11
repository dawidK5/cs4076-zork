#include "weapon.h"

Weapon::Weapon(QString name, int wDamage) : Item(name)
{
    damage = wDamage;
}

int Weapon::getDamage() const {
    return damage;
}
