/*

#include "weapon.h"
#include <random>

*/
#include "droid.h"
#include <time.h>
using droidfrnd::droid;

droid::droid(Item* dropp) : Npc() {//, drop(dropp) {
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
    uint16_t damage = static_cast<const Weapon&>(weapon).getDamage() * ((rand()/float(RAND_MAX))*3);
    if(damage > info.health) {
        info.dead = 1;
        QString finish = "Dealt " + QString(damage) + "damage."+ getDialogue();
        curLine++;
        return finish;
    }
    info.health -= damage;
    return "Dealt " + QString(damage) + "damage";
}

QString droid::getDialogue() {
    return droidLines[curLine+uchar(info.dead)];
}
