// #include <iostream>

//using namespace std;
#include "ZorkUL.h"

/*
ZorkUL::ZorkUL(Ui::MainWindow *& myUi) : myUi(myUi) {
	createRooms();
    printWelcome();
   // myUi->storyTextBox->setText("Hello All!");

}
*/
ZorkUL::ZorkUL() {
    createRooms();
}

void ZorkUL::createRooms()  {
    Room *a4, *a5, *a6, *a7,
         *b2, *b3, *b4, *b5, *b6, *b7, *b8,
         *c2, *c3, *c4, *c5, *c6, *c7, *c8,
         *d2, *d3, *d4, *d5, *d6, *d7, *d8,
         *e2, *e3, *e4, *e5, *e6, *e7, *e8,
         *f2, *f3, *f4, *f5, *f6, *f7, *f8,
         *g4, *g5, *g6, *g7, *g8;

    a4 = new Room("Forest");
    a5 = new Room("Forest");
    a6 = new Room("Clearing");
    a7 = new Room("Forest");

    b2 = new Room("Forest");
    b3 = new Room("Forest with River");
    b4 = new Room("Forest");
    b5 = new Room("Clearing");
    b6 = new Room("Forest");
    b7 = new Room("Forest");
    b8 = new Room("Forest");

    c2 = new Room("Crashed Ship");
    c3 = new Room("Planes");
    c4 = new Room("Lake");
    c5 = new Room("Lake");
    c6 = new Room("Forest");
    c7 = new Room("Mountain");
    c8 = new Room("Mountain");

    d2 = new Room("Crashed Ship");
    d3 = new Room("Planes");
    d4 = new Room("Dead Forest");
    d5 = new Room("Dead Forest");
    d6 = new Room("River");
    d7 = new Room("Mountain");
    d8 = new Room("Mountain");

    e2 = new Room("Planes");
    e3 = new Room("Small Mountain");
    e4 = new Room("Dead Forest");
    e5 = new Room("Dead Forest");
    e6 = new Room("Planes");
    e7 = new Room("Mountain With Door");
    e8 = new Room("Mountain");

    f2 = new Room("Forest");
    f3 = new Room("Small Mountain");
    f4 = new Room("Small Mountain");
    f5 = new Room("Planes");
    f6 = new Room("Forest");
    f7 = new Room("Mountain");
    f8 = new Room("Mountain");

    g4 = new Room("Small Mountain");
    g5 = new Room("Planes");
    g6 = new Room("Forest");
    g7 = new Room("Planes");
    g8 = new Room("Mountain");

    //EXITS
    //          (N, E, S, W)
    a4->setExits(NULL, b4, a5, NULL);
    a5->setExits(a4, b5, a6, NULL);
    a6->setExits(a5, b6, a6, NULL);
    a7->setExits(a6, b7, NULL, NULL);

    b2->setExits(NULL, c2, b3, NULL);
    b3->setExits(b2, c3, b4, NULL);
    b4->setExits(b3, c4, b5, a4);
    b5->setExits(b4, c5, b6, a5);
    b6->setExits(b5, c6, b7, a6);
    b7->setExits(b6, c7, b8, a7);
    b8->setExits(b7, c8, NULL, NULL);

    c2->setExits(NULL, d2, c3, b2);
    c3->setExits(c2, d3, c4, b3);
    c4->setExits(c3, d4, c5, b4);
    c5->setExits(c4, d5, c6, b5);
    c6->setExits(c5, d6, c7, b6);
    c7->setExits(c6, d7, c8, b7);
    c8->setExits(c7, d8, NULL, b8);

    d2->setExits(NULL, e2, d3, c2);
    d3->setExits(d2, e3, d4, c3);
    d4->setExits(d3, e4, d5, c4);
    d5->setExits(d4, e5, d6, c5);
    d6->setExits(d5, e6, d7, c6);
    d7->setExits(d6, e7, d8, c7);
    d8->setExits(d7, e8, NULL, c8);

    e2->setExits(NULL, f2, e3, d2);
    e3->setExits(e2, f3, e4, d3);
    e4->setExits(e3, f4, e5, d4);
    e5->setExits(e4, f5, e6, d5);
    e6->setExits(e5, f6, e7, d6);
    e7->setExits(e6, f7, e8, d7);
    e8->setExits(e7, f8, NULL, d8);

    f2->setExits(NULL, NULL, f3, e2);
    f3->setExits(f2, NULL, f4, e3);
    f4->setExits(f3, g4, f5, e4);
    f5->setExits(f4, g5, f6, e5);
    f6->setExits(f5, g6, f7, e6);
    f7->setExits(f6, g7, f8, e7);
    f8->setExits(f7, g8, NULL, e8);

    g4->setExits(NULL, NULL, g5, f4);
    g5->setExits(g4, NULL, g6, f5);
    g6->setExits(g5, NULL, g7, f6);
    g7->setExits(g6, NULL, g8, f7);
    g8->setExits(g7, NULL, NULL, f8);


        currentRoom = e6;
}

/**
 *  Main play routine.  Loops until end of play.
 */
/*
void ZorkUL::play() {
	printWelcome();

	// Enter the main command loop.  Here we repeatedly read commands and
	// execute them until the ZorkUL game is over.

	bool finished = false;
	while (!finished) {
		// Create pointer to command and give it a command.
		Command* command = parser.getCommand();
		// Pass dereferenced command and check for end of game.
		finished = processCommand(*command);
		// Free the memory allocated by "parser.getCommand()"
		//   with ("return new Command(...)")
		delete command;
	}
	cout << endl;
	cout << "end" << endl;
}
*/


/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the ZorkUL game, true is returned, otherwise false is
 * returned.
 */
/*
bool ZorkUL::processCommand(Command command) {
	if (command.isUnknown()) {
		cout << "invalid input"<< endl;
		return false;
	}

    QString commandWord = command.getCommandWord();
	if (commandWord.compare("info") == 0)
		printHelp();

	else if (commandWord.compare("map") == 0)
		{
        cout << "[h] --- [f] --- [g]" << endl;
		cout << "         |         " << endl;
        cout << "         |         " << endl;
		cout << "[c] --- [a] --- [b]" << endl;
		cout << "         |         " << endl;
		cout << "         |         " << endl;
		cout << "[i] --- [d] --- [e]" << endl;
		}

	else if (commandWord.compare("go") == 0)
		goRoom(command);

    else if (commandWord.compare("take") == 0)
    {
       	if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
        }
        else
         if (command.hasSecondWord()) {
        cout << "you're trying to take " + command.getSecondWord() << endl;
        int location = currentRoom->isItemInRoom(command.getSecondWord());
        if (location  < 0 )
            cout << "item is not in room" << endl;
        else
            cout << "item is in room" << endl;
            cout << "index number " << + location << endl;
            cout << endl;
            cout << currentRoom->longDescription() << endl;
        }
    }

    else if (commandWord.compare("put") == 0)
    {

    }
    */
    /*
    {
    if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
        }
        else
            if (command.hasSecondWord()) {
            cout << "you're adding " + command.getSecondWord() << endl;
            itemsInRoom.push_Back;
        }
    }

    else if (commandWord.compare("quit") == 0) {
		if (command.hasSecondWord())
			cout << "overdefined input"<< endl;
		else
            return true; // signal to quit
	}
	return false;
}
*/
/** COMMANDS **/
/*
void ZorkUL::printHelp() {
	cout << "valid inputs are; " << endl;
	parser.showCommands();

}

void ZorkUL::goRoom(Command command) {
	if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
		return;
	}

    QString direction = command.getSecondWord();

	// Try to leave current room.
	Room* nextRoom = currentRoom->nextRoom(direction);

	if (nextRoom == NULL)
		cout << "underdefined input"<< endl;
	else {
		currentRoom = nextRoom;
		cout << currentRoom->longDescription() << endl;
	}
}
*/

/**
 * @brief ZorkUL::go
 * @param direction the QString for direction
 * @return
 */
QString ZorkUL::go(const QString& direction) {
	//Make the direction lowercase
	//transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
	//Move to the next room
	Room* nextRoom = currentRoom->nextRoom(direction);
	if (nextRoom == NULL)
		return("direction null");
	else
	{
		currentRoom = nextRoom;
		return currentRoom->longDescription();
	}
}

