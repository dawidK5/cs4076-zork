#include "Item.h"
#include <iostream>
using std::cout;

Item::Item(QString inDescription, bool weaponCheck, bool isFood) :
    description(inDescription), weaponCheck(weaponCheck), isFood(isFood) { }

Item::Item(const Item& orig) {

    description = orig.getShortDescription();
    weaponCheck = orig.weaponCheck;
}
/*
template <typename T>
T Item::setWeaponCheck(T isWeapon) {
    if(isWeapon) {

        cout << "Item is a weapon\n";
        weaponCheck = true;

    } else {
        cout << "Item is not a weapon\n";
        weaponCheck = false;
    }
    return weaponCheck;
}
*/
QString Item::getShortDescription() const
{
    return description;
}

QString Item::getLongDescription() const
{
    return " item(s), " + description + ".\n";
}

