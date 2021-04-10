#include "Item.h"
#include <iostream>
using std::cout;
/*
Item::Item (QString inDescription, float inValue, int weaponCheck) {
    description = inDescription;
    //setWeight(inWeightGrams);
    value = inValue;
    //weaponCheck(isWeapon);
}
*/
Item::Item(QString inDescription) {
    description = inDescription;
}

Item::Item(const Item& orig) {
    description = orig.getShortDescription();
}
/*void Item::setWeight(int inWeightGrams)
{
    if (inWeightGrams > 9999 || inWeightGrams < 0)
       cout << "weight invalid, must be 0<weight<9999" ;
    else
       weightGrams = inWeightGrams;
}


void Item::setValue(float inValue)
{
    if (inValue > 9999 || inValue < 0)
       cout << "value invalid, must be 0<value<9999" ;
    else
       value = inValue;
}
*/
template <typename T>
T setWeaponCheck(T isWeapon) {
    if(isWeapon > 0 || isWeapon < 0)
        cout << "Item not a weapon" ;
    else
        cout << "Item is a weapon" ;
}

/*
void Item::setWeaponCheck(int isWeapon)
{
    if(isWeapon > 0 || isWeapon < 0)
        cout << "Item not a weapon" ;
    else
        cout << "Item is a weapon" ;
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
