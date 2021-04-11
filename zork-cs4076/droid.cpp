#include "droid.h"
#include <time.h>
using droidfrnd::droid;

droid::droid(Item* dropp) : Npc() {
    curLine = 0;
    info.health = 80;
    info.attackDamage = 16;
    info.droppedWeaponDamage = 5;
    info.dead = 0;
    srand(time(0));
    drop = dropp;
}


droid::~droid() {
    delete drop;
}

droid::droid(const droid& orig)
{
    info.health = orig.info.health;
    info.attackDamage = orig.info.attackDamage;
    info.droppedWeaponDamage = orig.info.droppedWeaponDamage;
    info.dead = orig.info.dead;
    drop = new Item("Advanced PCB");
}

QString droid::operator+(const Item& weapon) {
    int damage = static_cast<const Weapon&>(weapon).getDamage() * ((rand()/float(RAND_MAX))*2);
    if(damage > (int)info.health) {
        info.dead = 1;
        QString finish = QStringLiteral("Dealt %1 damage.").arg(damage) + getDialogue();
        curLine++;
        return finish;
    }
    info.health -= (uint16_t) damage;
    return QStringLiteral("Dealt %1 damage").arg(damage);
}

QString droid::getDialogue() {
    return droidLines[curLine+uchar(info.dead)];
}
