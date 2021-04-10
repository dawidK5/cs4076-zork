#ifndef DROID_H
#define DROID_H

#include "npc.h"
#include <exception>

class droidExcpt : public std::exception
{
private:
    std::string errorDes;
public:
    droidExcpt(QString er) : errorDes(er.toStdString()) { };
    const char * what () const noexcept {
        return errorDes.c_str();
    }
};

#include "weapon.h"

namespace droidfrnd {
#include "droid.h"

class droid : public Npc
{

    friend Item* getDropItem(droid & d);
public:
    droid(Item*); // drops one itemd
    ~droid();
    droid(const droid& origDroid); // deep copy
    QString operator+(const Item& weapon);
    void setDropItem(const Item&);

    inline bool isDead() { return info.dead & 1; };

    QString getDialogue();
private:
    constexpr static const char* droidLines[3] = {"You spot an old, massive battle droid approaching you. The doors slam behind you. Someone forgot to disable the voice debug mode.\"Enemy targeted\" the droid said.",
                                                  "You shot right at the camera sensor. In a fountain of sparks the droid starts swinging his arms but falls down and then freezes. You inspect it and find a fine quality PCB. Will you take it?", "The carcass of the battle droid that tried to kill you is still here."};
    unsigned char curLine;
    struct stats {
        uint16_t health              : 7;
        uint16_t attackDamage        : 6; // 63 max
        uint16_t                     : 0;
        uint16_t droppedWeaponDamage : 4; // 15 max
        uint16_t dead                : 1; // 0 => false
    } info;
    Item* drop;
};

}


#endif // DROID_H
