#include <iostream>
#include "World.h"
#include "Room.h"
#include "Exit.h"
#include "Player.h"

#define LOCKED true
#define UNLOCKED false
#define BOTHSIDES true
#define ONESIDE false

World::World()
{
	//         ------- Rooms creation -------

	Room* hall = new Room("Hall", "Hall in the prison");
	Room* wardensOffice = new Room("Warden's office", "Here is the warden of the prison");

	Room* sickRoom = new Room("Sick Room", "Patients are healed here");
	Room* yard = new Room("Yard", "This is the yard of the prison");
	Room* cell = new Room("Player's cell", "this is my cell");

	Room* entrance = new Room("Entrance", "Entrance of the prison ");

	Room* forest = new Room("Forest", "Forest of the prison");
	Room* lake = new Room("Lake", "Lake outside");
	Room* house = new Room("House", "House here");


	// myRooms will free dyn memory used

	myRooms[0] = hall;
	myRooms[1] = wardensOffice;
	myRooms[2] = sickRoom;
	myRooms[3] = yard;
	myRooms[4] = cell;
	myRooms[5] = entrance;
	myRooms[6] = forest;
	myRooms[7] = lake;
	myRooms[8] = house;
	
	

	//         ------- Exits creation -------

	Exit* hallToWardensOffice = new Exit(north,hall,wardensOffice, "this is to wardens", BOTHSIDES, LOCKED);

	Exit* cellToHall = new Exit(north,cell, hall, "This way to hall", BOTHSIDES, UNLOCKED);
	Exit* cellToSickRoom = new Exit(west,cell ,sickRoom, "This is to sickroom", BOTHSIDES, UNLOCKED);
	Exit* cellToYard = new Exit(east,cell,yard, "this is to yard",BOTHSIDES, UNLOCKED);

	Exit* entranceToCell = new Exit(north,entrance,cell, "This way takes you to your cell", BOTHSIDES, UNLOCKED);

	Exit* entranceToForest = new Exit(south,entrance,forest, "this is to get out of prison", BOTHSIDES, LOCKED);
	
	Exit* forestToHouse = new Exit(west,forest,house, "This gets to house", BOTHSIDES, UNLOCKED);
	Exit* forestToLake = new Exit(east,forest,lake, "This gets to lake",BOTHSIDES, UNLOCKED);

	Exit* cellToLake = new Exit(special,cell,lake, "scape from prison", ONESIDE, LOCKED);

	// myExits will free dyn memory used
	
	myExits[0] = hallToWardensOffice;
	myExits[1] = cellToHall;
	myExits[2] = cellToSickRoom;
	myExits[3] = cellToYard;
	myExits[4] = entranceToCell;
	myExits[5] = entranceToForest;
	myExits[6] = forestToHouse;
	myExits[7] = forestToLake;
	myExits[8] = cellToLake;

	//         ------- Player creation -------

	Player* myPlayer = new Player(entrance);

	currentRoom = entrance;
}

World::~World()
{
	//         ------- Free dyn memory -------

	for (int i = 0; i < 9; i++)
	{
		delete myRooms[i];
		delete myExits[i];
	}
	
	delete myPlayer;
	
}

void World::inputManagement(char* input)const
{
	char* secondWord;
	char* firstWord = strtok_s(input, " ",&secondWord);

	//			--- 1 word input ---

	if (*secondWord == *"")
	{
		if (*firstWord == *"help") cout << "\n Commands :\n\n quit\n look\n go\n open\n close\n quit\n help\n go\n north,south,east,west or n,s,e,w\n\n ";
		else if (*firstWord == *"open") cout << "this wants to open something";
		else if (*firstWord == *"close");
		else if (*firstWord == *"quit");
		else if (*firstWord == *"look");
		else if (*firstWord == *"exits");
		else if (*firstWord == *"n" || *firstWord == *"north") checkExit(north);
		else if (*firstWord == *"s" || *firstWord == *"south") checkExit(south);
		else if (*firstWord == *"w" || *firstWord == *"west") checkExit(west);
		else if (*firstWord == *"e" || *firstWord == *"east") checkExit(east);
	}

	//			---- 2 Words input ----

	//		---- look ----
	else if (*firstWord == *"look")
	{
		if (*secondWord == *"north") currentRoom->lookAt();
		if (*secondWord == *"south") currentRoom->lookAt();
		if (*secondWord == *"east") currentRoom->lookAt();
		if (*secondWord == *"west") currentRoom->lookAt();
	}

	//		---- go ----
	else if (*firstWord == *"go")
	{
		if (*secondWord == *"north" || *secondWord == *"n") checkExit(north);
		if (*secondWord == *"south" || *secondWord == *"s") checkExit(south);
		if (*secondWord == *"east" || *secondWord == *"e") checkExit(east);
		if (*secondWord == *"west" || *secondWord == *"w") checkExit(west);
	}
	

	
}

bool World::checkExit( Direction dir)const
{
	for (int i = 0; i < 9; i++)
	{
		if (myExits[i]->checkExit(dir, currentRoom) == true)
		{
			myPlayer->moveTo(dir, currentRoom);
			return true; // Player can move
		}
	}
	return false; // Player can't move
}