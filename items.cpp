in ZorkUL.cpp
rooms:
	*facility1/**, *facility2, *facility3, *facility4*/

	facility1 = new Room("Facility");
    /*facility2 = new Room("Facility");
    facility3 = new Room("Facility");
    facility4 = new Room("Facility");*/

    //ITEMS
    d2->addItem(new Item("Engine Part 1", 1, 11));
    b6->addItem(new Item("rope", 2, 22));
    b6->addItem(new Item("planks", 3, 33));
    e5->addItem(new Item("sail", 4, 44));
    f3->addItem(new Item("Engine Part 2", 5, 55));
    c4->addItem(new Item("Engine Part 3", 6, 66));
    facility1->addItem(new Item("Engine Part 4", 7, 77));
    facility1->addItem(new Item("Journal Entry 1", 8, 88));
    facility1->addItem(new Item("Journal Entry 2", 9, 99));
    facility1->addItem(new Item("Journal Entry 3", 10, 1010));
	
	
item.cpp:
	#include "item.h"

	Item::Item (string inDescription, int inWeightGrams, float inValue/**, int weaponCheck*/) {
		description = inDescription;
		setWeight(inWeightGrams);
		value = inValue;
		//weaponCheck(isWeapon);
	}

	Item::Item(string inDescription) {
		description = inDescription;
	}

	void Item::setWeight(int inWeightGrams)
	{
		if (inWeightGrams > 9999 || inWeightGrams < 0)
			cout << "weight invalid, must be 0<weight<9999" ;
		else
			weightGrams = inWeightGrams;
	}

	void Item::setValue(float inValue)
	{
		if (inValue > 9999 || inValue < 0)
			cout << "value invalid, must be 0<value<9999" ;
		else
			value = inValue;
		}

	void Item::setWeaponCheck(int isWeapon)
	{
		if(isWeapon > 0 || isWeapon < 0)
			cout << "Item not a weapon" ;
		else
			cout << "Item is a weapon" ;
	}

	string Item::getShortDescription()
	{
		return description;
	}
	
	string Item::getLongDescription()
	{
		return " item(s), " + description + ".\n";
	}

item.h:
	#ifndef ITEM_H_
	#define ITEM_H_

	#include <map>
	#include <string>
	#include <iostream>
	using namespace std;

	class Item {
	private:
		string description;
		string longDescription;
		int weightGrams;
		float value;
		bool weaponCheck;

	public:
		Item (string description, int inWeight, float inValue);
		Item (string description);
		string getShortDescription();
		string getLongDescription();
		int getWeight();
		void setWeight(int weightGrams);
		float getValue();
		void setValue(float value);
		int getWeaponCheck();
		void setWeaponCheck(int weaponCheck);
	};

	#endif /*ITEM_H_*/

//UNCOMMENT THE ITEM CODE IN Room.cpp

code for adding items to the inventory (not complete but general idea):
QVector<QString> invVect { command.getSecondWord() };
    for (auto& itr : invVect)
	myUi->invListView->append(itr);