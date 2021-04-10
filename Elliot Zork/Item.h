#ifndef ITEM_H
#define ITEM_H

#include <map>
#include <QString>
#include <iostream>
using namespace std;

class Item {
private:
    QString description;
    QString longDescription;
    //int weightGrams;
    float value;
    bool weaponCheck;

public:
    Item (QString description, float inValue);
    Item (QString description);
    QString getShortDescription();
    QString getLongDescription();
    template <typename T>
    T setWeaponCheck(T isWeapon);
    //int getWeight();
    //void setWeight(int weightGrams);
    float getValue();
    void setValue(float value);
    int getWeaponCheck();
    void setWeaponCheck(int weaponCheck);
};

#endif // ITEM_H
