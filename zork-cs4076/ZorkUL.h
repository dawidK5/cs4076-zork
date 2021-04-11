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


    // Parser parser;
	Room *currentRoom;
    Room *facility1;
    Room *e7;
    const Item* weapon;
    Room rooms[45];
    // vector<Item> inventory;
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
