#include "Room.h"
// #include "Command.h"
#include <iterator>
#include <QMap>



Room::Room(QString roomName) {

    this->roomName = roomName;
    firstVisit = true;
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
/*
QString operator+(const QString& lhs) {

}
*/
