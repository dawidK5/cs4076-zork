#ifndef ROOM_H_
#define ROOM_H_

#include <map>
#include <QMap>
#include <QString>

#include <vector>
#include "Item.h"
// using namespace std;
using std::vector;
// using std::map;


class Room {

private:
    static QMap<QString, QString> descrMap;
    QString roomName;
    map<QString, Room*> exits;
    QString exitString();
    vector <Item> itemsInRoom;
    bool firstVisit;


public:

    int numberOfItems();
    Room(QString roomName);
	void setExits(Room *north, Room *east, Room *south, Room *west);
    QString getRoomName() const;
    QString longDescription();
    Room* nextRoom(QString direction);
    void addItem(Item *inItem);
    QString displayItem();
    int isItemInRoom(QString inString);
    void removeItemFromRoom(int location);
    static QMap<QString, QString>& getTheMap();
};

#endif
