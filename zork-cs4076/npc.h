#ifndef NPC_H
#define NPC_H

#include "Item.h"
class Npc
{
public:
    virtual ~Npc() { };
    virtual QString getDialogue() = 0;

protected:
    Npc();


};


#endif // NPC_H
