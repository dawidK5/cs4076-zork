#include "human.h"
#include "ZorkUL.h"
#include <QFile>
#include <QTextStream>
#include "weapon.h"
#include <iostream>
#include "food.h"
#define N_OF_ROOMS 45

using std::cout, std::endl;
using droidfrnd::droid;

ZorkUL::ZorkUL() : weapon(new Weapon("blaster", 20)), rooms{
  Room("Facility"),
  Room("Forest"), 		Room("Forest"), 						Room("Clearing"), 		Room("Forest"),
  Room("Forest"), 		Room("Forest with River"), 				Room("Forest"), 		Room("Clearing"), 		Room("Forest"), Room("Forest"), 			Room("Forest"),
  Room("Crashed Ship"), Room("Plains"), 						Room("Lake"), 			Room("Lake"), 			Room("Forest"), Room("Mountain"), 			Room("Mountain"),
  Room("Crashed Ship"), Room("Plains"), 						Room("Dead Forest"), 	Room("Dead Forest"), 	Room("River"), 	Room("Mountain"), 			Room("Mountain"),
  Room("Plains"), 		Room("Small Mountain"), 				Room("Dead Forest"), 	Room("Dead Forest"), 	Room("Plains"), Room("Mountain With Door"), Room("Mountain"),
  Room("Forest"), 		Room("Small Mountain"), 				Room("Small Mountain"), Room("Plains"), 		Room("Walnut Tree"), Room("Mountain"), 			Room("Mountain"),
  Room("Small Mountain"), Room("Plains"), 						Room("Forest"), 		Room("Plains"), 		Room("Mountain")}

{

    QFile places(":/assets/places.txt");
    if(!places.open(QIODevice::ReadOnly)) {
        cout << "error" <<endl;
    }

    QTextStream in(&places);
    int count = 1;
    QMap<QString, QString>& descrMap = Room::getTheMap();
    while(! in.atEnd()) {
        QString line = in.readLine();
        if((count % 3) == 1) {
            QString descr = in.readLine();
            descrMap.insert(line, descr);
            count++;
        }
        count++;
    }
    places.close();
    createRooms();
    resetGame();


}

void ZorkUL::resetGame() {
    delete weapon;
    for(int i = 0; i < N_OF_ROOMS; i++) {
        rooms[i].clear();
    }
    currentRoom = &rooms[30];


    rooms[34].addItem(new Item("Engine Part 2"));   // f3
    rooms[14].addItem(new Item("Engine Part 3"));   // c4
    facility1 = &rooms[0];
    facility1->addItem(new Item("Engine Part 4"));

    facility1->addItem(new Item("Journal Entry 1"));
    facility1->addItem(new Item("Journal Entry 3"));
    facility1->addItem(new Item("Journal Entry 6"));
    facility1->addItem(new Item("Journal Entry 9"));

    e7 = &rooms[31];
    facility1->addNpc(new droid(new Item("Advanced PCB")));
    rooms[19].addNpc(new Human("Advanced PCB", new Item("Engine Part 1")));
    rooms[37].addItem(new Food("Nuts", 60));
    rooms[5].addNpc(new droid(*facility1->getDroid()));
    weapon = new Weapon("blaster", 20);
    weapon->setWeaponCheck(1);
}
#undef N_OF_ROOMS

void ZorkUL::createRooms()  {

    rooms[0].setExits(NULL, NULL, NULL, NULL);
    rooms[1].setExits(NULL, &rooms[7], &rooms[2], NULL);
    rooms[2].setExits(&rooms[1], &rooms[8], &rooms[3], NULL);
    rooms[3].setExits(&rooms[2], &rooms[9], &rooms[4], NULL);
    rooms[4].setExits(&rooms[3], &rooms[10], NULL, NULL);

    rooms[5].setExits(NULL, &rooms[12], &rooms[6], NULL);
    rooms[6].setExits(&rooms[5], &rooms[13], &rooms[7], NULL);
    rooms[7].setExits(&rooms[6], &rooms[14], &rooms[8], &rooms[1]);
    rooms[8].setExits(&rooms[7], &rooms[15], &rooms[9], &rooms[2]);
    rooms[9].setExits(&rooms[8], &rooms[16], &rooms[10], &rooms[3]);
    rooms[10].setExits(&rooms[9], &rooms[17], &rooms[11], &rooms[4]);
    rooms[11].setExits(&rooms[10], &rooms[18], NULL, NULL);

    rooms[12].setExits(NULL, &rooms[19], &rooms[13], &rooms[5]);
    rooms[13].setExits(&rooms[12], &rooms[20], &rooms[14], &rooms[6]);
    rooms[14].setExits(&rooms[13], &rooms[21], &rooms[15], &rooms[7]);
    rooms[15].setExits(&rooms[14], &rooms[22], &rooms[16], &rooms[8]);
    rooms[16].setExits(&rooms[15], &rooms[23], &rooms[17], &rooms[9]);
    rooms[17].setExits(&rooms[16], &rooms[24], &rooms[18], &rooms[10]);
    rooms[18].setExits(&rooms[17], &rooms[25], NULL, &rooms[11]);

    rooms[19].setExits(NULL, &rooms[26], &rooms[20], &rooms[12]);
    rooms[20].setExits(&rooms[19], &rooms[27], &rooms[21], &rooms[13]);
    rooms[21].setExits(&rooms[20], &rooms[28], &rooms[22], &rooms[14]);
    rooms[22].setExits(&rooms[21], &rooms[29], &rooms[23], &rooms[15]);
    rooms[23].setExits(&rooms[22], &rooms[30], &rooms[24], &rooms[16]);
    rooms[24].setExits(&rooms[23], &rooms[31], &rooms[25], &rooms[17]);
    rooms[25].setExits(&rooms[24], &rooms[32], NULL, &rooms[18]);

    rooms[26].setExits(NULL, &rooms[33], &rooms[27], &rooms[19]);
    rooms[27].setExits(&rooms[26], &rooms[34], &rooms[28], &rooms[20]);
    rooms[28].setExits(&rooms[27], &rooms[35], &rooms[29], &rooms[21]);
    rooms[29].setExits(&rooms[28], &rooms[36], &rooms[30], &rooms[22]);
    rooms[30].setExits(&rooms[29], &rooms[37], &rooms[31], &rooms[23]);
    rooms[31].setExits(&rooms[30], &rooms[38], &rooms[32], &rooms[24]);
    rooms[32].setExits(&rooms[31], &rooms[39], NULL, &rooms[25]);

    rooms[33].setExits(NULL, NULL, &rooms[34], &rooms[26]);
    rooms[34].setExits(&rooms[33], NULL, &rooms[35], &rooms[27]);
    rooms[35].setExits(&rooms[34], &rooms[40], &rooms[36], &rooms[28]);
    rooms[36].setExits(&rooms[35], &rooms[41], &rooms[37], &rooms[29]);
    rooms[37].setExits(&rooms[36], &rooms[42], &rooms[38], &rooms[30]);
    rooms[38].setExits(&rooms[37], &rooms[43], &rooms[39], &rooms[31]);
    rooms[39].setExits(&rooms[38], &rooms[44], NULL, &rooms[32]);

    rooms[40].setExits(NULL, NULL, &rooms[41], &rooms[35]);
    rooms[41].setExits(&rooms[40], NULL, &rooms[42], &rooms[36]);
    rooms[42].setExits(&rooms[41], NULL, &rooms[43], &rooms[37]);
    rooms[43].setExits(&rooms[42], NULL, &rooms[44], &rooms[38]);
    rooms[44].setExits(&rooms[43], NULL, NULL, &rooms[39]);

/*
    Room *a4, *a5, *a6, *a7,
         *b2, *b3, *b4, *b5, *b6, *b7, *b8,
         *c2, *c3, *c4, *c5, *c6, *c7, *c8,
         *d2, *d3, *d4, *d5, *d6, *d7, *d8,
         *e2, *e3, *e4, *e5, *e6,      *e8,
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
    c3 = new Room("Plains");
    c4 = new Room("Lake");
    c5 = new Room("Lake");
    c6 = new Room("Forest");
    c7 = new Room("Mountain");
    c8 = new Room("Mountain");

    d2 = new Room("Crashed Ship");
    d3 = new Room("Plains");
    d4 = new Room("Dead Forest");
    d5 = new Room("Dead Forest");
    d6 = new Room("River");
    d7 = new Room("Mountain");
    d8 = new Room("Mountain");

    e2 = new Room("Plains");
    e3 = new Room("Small Mountain");
    e4 = new Room("Dead Forest");
    e5 = new Room("Dead Forest");
    e6 = new Room("Plains");
    e7 = new Room("Mountain With Door");
    e8 = new Room("Mountain");

    f2 = new Room("Forest");
    f3 = new Room("Small Mountain");
    f4 = new Room("Small Mountain");
    f5 = new Room("Plains");
    f6 = new Room("Forest");
    f7 = new Room("Mountain");
    f8 = new Room("Mountain");

    g4 = new Room("Small Mountain");
    g5 = new Room("Plains");
    g6 = new Room("Forest");
    g7 = new Room("Plains");
    g8 = new Room("Mountain");
*/
    //EXITS
    //          (N, E, S, W)
    /*
    a4->setExits(NULL, b4, a5, NULL);
    a5->setExits(a4, b5, a6, NULL);
    a6->setExits(a5, b6, a7, NULL);
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
*/
/*
    currentRoom = e6;


    facility1 = new Room("Facility");
    facility1->setExits(NULL, NULL, NULL, NULL);


    ITEMS
    // d2->addItem(new Item("Engine Part 1"));
    b6->addItem(new Item("rope"));
    b6->addItem(new Item("planks"));
    e5->addItem(new Item("sail"));
    f3->addItem(new Item("Engine Part 2"));
    c4->addItem(new Item("Engine Part 3"));
    facility1->addItem(new Item("Engine Part 4"));
    facility1->addItem(new Item("Journal Entry 1"));
    facility1->addItem(new Item("Journal Entry 3"));
    facility1->addItem(new Item("Journal Entry 6"));
    facility1->addItem(new Item("Journal Entry 9"));

    facility1->addNpc(new droid(new Item("Advanced PCB")));
    d2->addNpc(new Human("Advanced PCB", new Item("Engine Part 1")));
    */


}

QString ZorkUL::setCurRoom() {
    if(currentRoom != facility1){
        currentRoom = facility1;
    }else{
        currentRoom = e7;
    }
    return currentRoom->longDescription();
}


/**
 * @brief ZorkUL::go
 * @param direction the QString for direction
 * @return
 */
QString ZorkUL::go(const QString& direction) {
    // Make the direction lowercase
    // transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
    // Move to the next room
	Room* nextRoom = currentRoom->nextRoom(direction);
	if (nextRoom == NULL)
		return("direction null");
	else
	{
		currentRoom = nextRoom;
		return currentRoom->longDescription();
	}
}

ZorkUL::~ZorkUL() {
    currentRoom = facility1 = e7 = nullptr;

}
