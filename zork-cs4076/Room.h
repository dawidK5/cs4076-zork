#ifndef ROOM_H_
#define ROOM_H_

#include <QString>
#include <QMap>
/*






*/
#include "droid.h"
#include "Item.h"
#include "npc.h"
#include <vector>
#include <map>
using std::vector;
using std::map;



class Room {

private:
    static QMap<QString, QString> descrMap;
    QString roomName;
    map<QString, Room*> exits;
    QString exitString();
    vector <Item> itemsInRoom;
    bool firstVisit;
    Npc* nonpc;

public:
    Room(QString roomName);
    ~Room();
    droidfrnd::droid* getDroid();
    Npc* getNpc();
    bool hasNpc() const;
    bool hasDroid() const;
    int numberOfItems();

	void setExits(Room *north, Room *east, Room *south, Room *west);
    QString getRoomName() const;
    QString longDescription();
    Room* nextRoom(QString direction);
    void addItem(Item *inItem);
    void addNpc(Npc*);
    QString displayItem();
    int isItemInRoom(QString inString);
    void removeItemFromRoom(int location);
    void removeItems();
    vector<Item> getItems();
    void killDroid();
    static QMap<QString, QString>& getTheMap();
};

#endif
