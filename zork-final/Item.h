#ifndef ITEM_H
#define ITEM_H

#include <QString>

class Item {
private:
    QString description;
    QString longDescription;
    bool weaponCheck;
    bool isFood;

public:
    Item (QString description, bool weaponCheck = false, bool isFood = false);
    Item(const Item&);

    QString getShortDescription() const;
    QString getLongDescription() const;
    template <typename T>
    bool setWeaponCheck(T isWeapon) { return weaponCheck = (bool) isWeapon;};

    bool getWeaponCheck();
};

#endif // ITEM_H
