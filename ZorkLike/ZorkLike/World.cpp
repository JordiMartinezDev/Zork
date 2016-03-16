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

	Room* hall = new Room("Hall", "Hall in the prison",LOCKED);
	Room* wardensOffice = new Room("Warden's office", "Here is the warden of the prison",LOCKED);

	Room* sickRoom = new Room("Sick Room", "Patients are healed here",UNLOCKED);
	Room* yard = new Room("Yard", "This is the yard of the prison",UNLOCKED);
	Room* cell = new Room("Player's cell", "this is my cell",LOCKED);

	Room* entrance = new Room("Entrance", "Entrance of the prison ",LOCKED);

	Room* forest = new Room("Forest", "Forest of the prison",UNLOCKED);
	Room* lake = new Room("Lake", "Lake outside",UNLOCKED);
	Room* house = new Room("House", "House here",UNLOCKED);
	Room* emptyRoom = new Room("Entrance", "entrance of the prison", LOCKED);

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
	myRooms[9] = emptyRoom;
	


	//         ------- Exits creation -------

	Exit* hallToWardensOffice = new Exit(hall,north,wardensOffice, "this is to wardens", LOCKED);
	Exit* wardensOfficeToHall = new Exit(wardensOffice, south, hall, "thi is to hall", LOCKED);

	Exit* cellToHall = new Exit(cell,north,hall, "This way to hall", UNLOCKED);
	Exit* hallToCell = new Exit(hall, south, cell,"This is to cell", UNLOCKED);
	Exit* cellToSickRoom = new Exit(cell,west,sickRoom, "This is to sickroom", UNLOCKED);
	Exit* sickRoomToCell = new Exit(sickRoom, east, cell, "this is to cell", UNLOCKED);
	Exit* cellToYard = new Exit(cell,east,yard, "this is to yard", UNLOCKED);
	Exit* yardToCell = new Exit(yard, west, cell, "this is to cell", UNLOCKED);
	Exit* emptyRoomToCell = new Exit(emptyRoom, north, cell, "This is to cell", UNLOCKED);

	Exit* entranceToCell = new Exit(entrance,north,cell, "This way takes you to your cell", UNLOCKED);
	Exit* cellToEntrance = new Exit(cell, south, entrance, "this is to entrance", UNLOCKED);
	Exit* entranceToForest = new Exit(entrance,south,forest, "this is to get out of prison", LOCKED);
	Exit* forestToEntrance = new Exit(forest, north, entrance, "this is to enter the prison", LOCKED);
	Exit* forestToHouse = new Exit(forest,west,house, "This gets to house", UNLOCKED);
	Exit* houseToForest = new Exit(house, east, forest, "this is to forest", UNLOCKED);
	Exit* forestToLake = new Exit(forest,east,lake,"This gets to lake", UNLOCKED);
	Exit* lakeToForest = new Exit(lake, west, forest, "this is to forest", UNLOCKED);

	Exit* cellToLake = new Exit(cell,special,lake, "scape from prison", LOCKED);

	// myExits will free dyn memory used
	
	myExits[0] = hallToWardensOffice;
	myExits[1] = wardensOfficeToHall;

	myExits[2] = cellToHall;
	myExits[3] = hallToCell;
	myExits[4] = cellToSickRoom;
	myExits[5] = sickRoomToCell;
	myExits[6] = cellToYard;
	myExits[7] = yardToCell;

	myExits[8] = entranceToCell;
	myExits[9] = cellToEntrance;
	myExits[10] = entranceToForest;
	myExits[11] = forestToEntrance;
	myExits[12] = forestToHouse;
	myExits[13] = houseToForest;
	myExits[14] = forestToLake;
	myExits[15] = lakeToForest;
	myExits[16] = cellToLake;

	//         ------- Player creation -------

	Player* myPlayer = new Player();

	currentRoom = myRooms[9];// cell
}

World::~World()
{
	//         ------- Free dyn memory -------

	for (int i = 0; i < 10; i++) delete myRooms[i];
	for (int i = 0; i < 17; i++) delete myExits[i];
	delete myPlayer;
	
}

bool World::inputManagement(char* input)const
{
	char* tmp2Word;
	char* tmpWord = strtok_s(input, " ",&tmp2Word);
	string firstWord = tmpWord;
	string secondWord = tmp2Word;
	//			--- 1 word input ---

	if (secondWord == "")
	{
		if (firstWord == "help") cout << "\n Commands :\n\n quit\n look\n go\n open\n close\n quit\n help\n go\n north,south,east,west or n,s,e,w\n\n ";
		else if (firstWord == "open") cout << "\n Type open door/gate to open it \n";
		else if (firstWord == "close") cout << "\n Type close door/gate to close it\n";
		else if (firstWord == "quit") return false;  // Player wants to quit
		else if (firstWord == "look") currentRoom->lookAt();
		else if (firstWord == "exits");
		else if (firstWord == "n" || firstWord == "north") checkExit(north);
		else if (firstWord == "s" || firstWord == "south") checkExit(south);
		else if (firstWord == "w" || firstWord == "west") checkExit(west);
		else if (firstWord == "e" || firstWord == "east") checkExit(east);
	}

	//			---- 2 Words input ----

	//		---- look ----
	else if (firstWord == "look")
	{
		if (secondWord == "north") currentRoom->lookAt();
		if (secondWord == "south") currentRoom->lookAt();
		if (secondWord == "east") currentRoom->lookAt();
		if (secondWord == "west") currentRoom->lookAt();
	}

	//		---- go ----
	else if (firstWord == "go")
	{
		if (secondWord == "north" || secondWord == "n") checkExit(north);
		if (secondWord == "south" || secondWord == "s") checkExit(south);
		if (secondWord == "east" || secondWord == "e") checkExit(east);
		if (secondWord == "west" || secondWord == "w") checkExit(west);
	}
	//		---- open ----
	else if (firstWord == "open")
	{
		if (secondWord == "door" || secondWord == "gate") currentRoom->isDoor = false;
	}
	//		---- close ----
	else if (firstWord == "close")
	{
		if (secondWord == "door" || secondWord == "gate") currentRoom->isDoor = true;
	}
	

	return true;
}

bool World::checkExit( Direction dir)const
{
	for (int i = 0; i < 17; i++)
	{
		if (myExits[i]->checkExit(dir, currentRoom) == true) 
		{
			currentRoom->lookAt();
			return true; // Player can move
		}
	}

	cout << "\n There is nothing there, maybe another way\n\n";
	return false; // Player can't move
}