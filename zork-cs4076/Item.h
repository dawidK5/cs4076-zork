#ifndef ITEM_H
#define ITEM_H

#include <QString>

class Item {
private:
    QString description;
    QString longDescription;
    //int weightGrams;
    float value;
    bool weaponCheck;

public:
    Item (QString description, float inValue);
    Item(const Item&);
    Item (QString description);
    QString getShortDescription() const;
    QString getLongDescription() const;
    template <typename T>
    T setWeaponCheck(T isWeapon);

    int getWeaponCheck();
};

#endif // ITEM_H
