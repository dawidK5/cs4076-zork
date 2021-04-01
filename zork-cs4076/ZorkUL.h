#ifndef ZORKUL_H_
#define ZORKUL_H_


// #include "mainwindow.h"
// #include "ui_mainwindow.h"
// #include "Command.h"
// #include "Parser.h"
#include "Room.h"
// #include "item.h"
#include <iostream>

using namespace std;

class ZorkUL {
private:

    // Parser parser;
	Room *currentRoom;
	void createRooms();
	void printWelcome();
    // bool processCommand(Command command);
	void printHelp();
    // void goRoom(Command command);
    void createItems();
    void displayItems();
    // Ui::MainWindow *& myUi;


public:
    //ZorkUL(Ui::MainWindow *&);
    ZorkUL();
	void play();
    QString go(const QString& direction);
    inline Room* getCurrentRoom() const {
        return currentRoom;
    }

};

#endif /*ZORKUL_H_*/
