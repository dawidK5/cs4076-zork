#include "Item.h"
#include <iostream>
using std::cout;

Item::Item(QString inDescription) {
    description = inDescription;
}

Item::Item(const Item& orig) {
    description = orig.getShortDescription();
}

template <typename T>
T setWeaponCheck(T isWeapon) {
    if(isWeapon > 0 || isWeapon < 0)
        cout << "Item not a weapon\n" ;
    else
        cout << "Item is a weapon\n" ;
}

QString Item::getShortDescription() const
{
    return description;
}

QString Item::getLongDescription() const
{
    return " item(s), " + description + ".\n";
}
