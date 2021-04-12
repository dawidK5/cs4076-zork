#include "human.h"

Human::Human(QString tradeable, Item* traded) : Npc(), reward(traded), allowedItem(tradeable), ind(0)
{

}

Human::~Human() {
    delete reward;
}

bool Human::tradesItem(const Item& i) {
    return (i.getShortDescription() == reward->getShortDescription());

}

QString Human::getInItemName() {
    return allowedItem;
}

Item Human::trade() {
    ind++;
    return *reward;
}
bool Human::stillHasItem() {
    return ind != 3;
}
QString Human::getDialogue() {

    switch(ind) {
    case 0 :
        ind++;
        return QStringLiteral("You see a little hut made of scrap metal from the crashed ship. A human emerges from the inside and approaches you.\n\"Hello, my name is Jeff\" the man said. From a distance you spot a part of your hyperdrive thorugh a small window in the hut. You ask Jeff to give it back but he replies: \"Nothing's free. I'm looking for modern PCB, like the ones that were used in the mountain facility. If you find it, bring it to me and I'll give you the engine part in exchange\"");
    case 1 : return QStringLiteral("Jeff greets you: \"Hello again! Have you found the PCB?\"");
    case 2 : ind = 3;
        return QStringLiteral("\"Oh, yes, that's exactly what I needed!\" Jeff exclaimed. \"Here you go, that's your missing engine part. Take it please\"");
    default : return QStringLiteral("\"Thank you for the PCB I hope you can bring me with you before the collision\"");
    }
}
