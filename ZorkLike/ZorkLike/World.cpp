#include <iostream>
#include "World.h"
#include "Room.h"
#include "Exit.h"
#include "Player.h"

#define LOCKED true
#define UNLOCKED false

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

	Exit* hallToWardensOfiice = new Exit(north, wardensOffice,south,hall, "this is to wardens", LOCKED);

	Exit* cellToHall = new Exit(north, hall,south,cell, "This way to hall",UNLOCKED);
	Exit* cellToSickRoom = new Exit(west, sickRoom,east,cell, "This is to sickroom",UNLOCKED);
	Exit* cellToYard = new Exit(east, yard,west,cell, "this is to yard", UNLOCKED);

	Exit* entranceToCell = new Exit(north, cell,south,entrance, "This way takes you to your cell", UNLOCKED);

	Exit* entranceToForest = new Exit(south, forest,north,entrance, "this is to get out of prison", LOCKED);
	
	Exit* forestToHouse = new Exit(west, house,east,forest, "This gets to house", UNLOCKED);
	Exit* forestToLake = new Exit(east, lake,west,forest, "This gets to lake", UNLOCKED);

	Exit* cellToLake = new Exit(special, lake, special, cell, "scape from prison", LOCKED);

	// myExits will free dyn memory used

	myExits[0] = hallToWardensOfiice;
	myExits[1] = cellToHall;
	myExits[1] = cellToSickRoom;
	myExits[1] = cellToYard;
	myExits[1] = entranceToCell;
	myExits[1] = entranceToForest;
	myExits[1] = forestToHouse;
	myExits[1] = forestToLake;
	myExits[1] = cellToLake;

	//         ------- Player creation -------

	Player* player = new Player();
	myPlayer = player; //to free dyn mem

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

void World::inputManagement(const string &input)const
{
	
	if (input == "help") cout << "\n Commands :\n\n exit\n look\n go\n open\n close\n quit\n help\n go\n north,south,east,west or n,s,e,w\n\n ";
	else if (input == "look") currentRoom->lookAt();
	else if (input == "look north") currentRoom->lookAt();
	else if (input == "look sout") currentRoom->lookAt();
	else if (input == "look east") currentRoom->lookAt();
	else if (input == "look west") currentRoom->lookAt();
	else if (input == "go");
	else if (input == "open");
	else if (input == "close");
	else if (input == "quit");
	else if (input == "go north" || input == "north" || input == "n");
	else if (input == "go south" || input == "south" || input == "s");
	else if (input == "go east" || input == "east" || input == "e");
	else if (input == "go west" || input == "west" || input == "w");

	
}
