#include <iostream>
#include "Room.h"
#include "nodescriptionexcpt.h"
using std::cout, std::endl;
using droidfrnd::droid, nde::NoDescriptionExcpt;

Room::Room(QString roomName) : roomName(roomName), firstVisit(true), nonpc(nullptr) { }
void Room::setName(QString rmName) {
    roomName = rmName;
}
void Room::setExits(Room *north, Room *east, Room *south, Room *west) {
	if (north != NULL)
		exits["north"] = north;
	if (east != NULL)
		exits["east"] = east;
	if (south != NULL)
		exits["south"] = south;
	if (west != NULL)
		exits["west"] = west;
}

QString Room::getRoomName() const {
    return roomName;
}

QString Room::longDescription() {
    if(firstVisit) {
        firstVisit = false;
        if(!descrMap.contains(roomName)) {
            throw NoDescriptionExcpt(QStringLiteral("The %1 room decription missing: check places.txt").arg(roomName));
        }
        return "room = " + roomName + ".\n" + descrMap[roomName] +"\n." + displayItem() + exitString();
    }
    return "room = " + roomName + ".\n" + displayItem() + exitString();
}

QString Room::exitString() {
    QString returnString = "\nexits =";
    for (map<QString, Room*>::iterator i = exits.begin(); i != exits.end(); i++) {
		// Loop through map
        returnString += "  " + i->first; // access the "first" element of the pair (direction as a QString)
    }

	return returnString;
}

void Room::removeItems() {
    vector <Item> itemsInRoom2;
    itemsInRoom = itemsInRoom2;
}
vector <Item> Room::getItems() {
    return itemsInRoom;
}

Room* Room::nextRoom(QString direction) {
    map<QString, Room*>::iterator next = exits.find(direction); //returns an iterator for the "pair"
	if (next == exits.end())
		return NULL; // if exits.end() was returned, there's no room in that direction.
	return next->second; // If there is a room, remove the "second" (Room*)
                // part of the "pair" (<QString, Room*>) and return it.
}

void Room::addItem(Item *inItem) {

    // cout << "Just added" + inItem->getLongDescription();
    itemsInRoom.push_back(*inItem);
}

QString Room::displayItem() {
    QString tempString = "items in room = ";
    int sizeItems = (itemsInRoom.size());
    if (itemsInRoom.size() < 1) {
        tempString = "no items in room";
        }
    else if (itemsInRoom.size() > 0) {
       int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            tempString = tempString + itemsInRoom[x].getShortDescription() + "  " ;
            x++;
            }
        }
    return tempString;
    }

int Room::numberOfItems() {
    return itemsInRoom.size();
}

int Room::isItemInRoom(QString inString)
{
    int sizeItems = (itemsInRoom.size());
    if (itemsInRoom.size() < 1) {
        return false;
        }
    else if (itemsInRoom.size() > 0) {
       int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            // compare inString with short roomName
            int tempFlag = inString.compare( itemsInRoom[x].getShortDescription());
            if (tempFlag == 0) {
                itemsInRoom.erase(itemsInRoom.begin()+x);
                return x;
            }
            x++;
            }
        }
    return -1;
}

QMap<QString,QString>& Room::getTheMap() {
    cout << &descrMap << endl;
    return descrMap;
}


bool Room::hasDroid() const {
    return (dynamic_cast<droid*>(nonpc) != nullptr);
}

droid* Room::getDroid() {
    if(!hasDroid()) {
        throw droidExcpt(QString("Dynamic cast exception in %1: This isn't the droid you are looking for").arg(__FILE__));
    }
    return dynamic_cast<droid*>(nonpc);
}

void Room::addNpc(Npc* n) {
    nonpc = n;
}

bool Room::hasNpc() const {
    return nonpc != nullptr;
}

void Room::killDroid() {
    delete nonpc;
}
Npc* Room::getNpc() {
    return nonpc;
}
void Room::clear() {
    itemsInRoom.clear();
    killDroid();
}
Room::~Room() {
    itemsInRoom.clear();
    delete nonpc;
}
