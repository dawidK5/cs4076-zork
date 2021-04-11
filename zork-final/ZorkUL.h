#ifndef ZORKUL_H_
#define ZORKUL_H_



// #include "Command.h"
// #include "Parser.h"
//
// #include <iostream>

#include "Room.h"
#include "Item.h"

class ZorkUL {
private:

	Room *currentRoom;
    Room *facility1;
    Room *e7;
    Item* weapon;
    Room rooms[45];

	void createRooms();
	void printWelcome();

	void printHelp();

    void createItems();
    void displayItems();


public:
    ZorkUL();
    ~ZorkUL();
	void play();
    QString go(const QString& direction);
    inline Room* getCurrentRoom() const {
        return currentRoom;
    }
    QString setCurRoom();
    inline const Item* getWeapon() const {
        return weapon;
    };
    void resetGame();
    // void addInvItem(const Item&);
    // void removeInvItem();


};

#endif /*ZORKUL_H_*/
