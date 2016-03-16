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

	Room* hall = new Room("Hall", "\n\n This is the hall, i can see a door in the NORTH of here\n it says : Warden's office\n\n Will he be there..?",LOCKED);
	Room* wardensOffice = new Room("Warden's office", "\n\n Here is the warden of the prison, SOUTH from here is the HALL ",LOCKED);

	Room* sickRoom = new Room("Sick Room", "\n\n Patients are healed here... EAST from here is my CELL",UNLOCKED);
	Room* yard = new Room("Yard", "\n\n This is the yard of the prison, WEST from here is my CELL",UNLOCKED);
	Room* cell = new Room("Player's cell", " This is my cell\n\n NORTH from here is the HALL\n EAST from here is the YARD\n WEST from here is the SICK ROOM",LOCKED);

	Room* entrance = new Room("Entrance", " Entrance of the prison\n\n SOUTH from here i can see a FOREST, the doors are closed.\n NORTH from here leads to my CELL ",LOCKED);

	Room* forest = new Room("Forest", " Forest of the prison\n\n EAST from here is a LAKE",UNLOCKED);
	Room* lake = new Room("Lake", " Lake outside\n\n WEST from here is a FOREST",UNLOCKED);
	Room* house = new Room("House", " House here\n\n EAST from here is a FOREST",UNLOCKED);
	Room* emptyRoom = new Room("Entrance", " Entrance of the prison\n\n SOUTH from here i can see a FOREST, the doors are closed.\n NORTH from here leads to my CELL ", LOCKED); 
	
	// emptyRoom was created to solve a problem with movement, this needs to be fixed in the future


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

	Exit* hallToWardensOffice = new Exit(hall,north,wardensOffice, "\n\n There is the WARDEN'S OFFICE, will that door be locked?", LOCKED);
	Exit* wardensOfficeToHall = new Exit(wardensOffice, south, hall, "\n\n There is the HALL", LOCKED);

	Exit* cellToHall = new Exit(cell,north,hall, "\n\n There is the HALL", UNLOCKED);
	Exit* hallToCell = new Exit(hall, south, cell,"\n\n There is your CELL", UNLOCKED);
	Exit* cellToSickRoom = new Exit(cell,west,sickRoom, "\n\n There is the SICK ROOM, it may be opened now, doctor is there", UNLOCKED);
	Exit* sickRoomToCell = new Exit(sickRoom, east, cell, "\n\n There is the way back to your CELL", UNLOCKED);
	Exit* cellToYard = new Exit(cell,east,yard, "\n\n That way leads us to the YARD, may be dangerous if i find any mad prisoner there ", UNLOCKED);
	Exit* yardToCell = new Exit(yard, west, cell, "\n\n Way back to your CELL", UNLOCKED);
	Exit* emptyRoomToCell = new Exit(emptyRoom, north, cell, "\n\n That way takes you to your CELL", UNLOCKED); //

	Exit* entranceToCell = new Exit(entrance,north,cell, "\n\n That way takes you to your CELL", UNLOCKED);
	Exit* cellToEntrance = new Exit(cell, south, entrance, "\n\n Way to the freedom? There is the ENTRANCE of the prison", UNLOCKED);
	Exit* entranceToForest = new Exit(entrance,south,forest, "\n\n If that door wasn't there... i could scape through that FOREST", LOCKED);
	Exit* forestToEntrance = new Exit(forest, north, entrance, "\n\n That's the ENTANCE of the prison", LOCKED);
	Exit* forestToHouse = new Exit(forest,west,house, "\n\n Far from here, there is a HOUSE", UNLOCKED);
	Exit* houseToForest = new Exit(house, east, forest, "\n\n Way back to FOREST", UNLOCKED);
	Exit* forestToLake = new Exit(forest,east,lake,"\n\n There seems to be a LAKE", UNLOCKED);
	Exit* lakeToForest = new Exit(lake, west, forest, "\n\n Way back to FOREST", UNLOCKED);

	Exit* cellToLake = new Exit(cell,special,lake, "\n\n Scape from prison", LOCKED);

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

	//	 ---- 2 Words input ----

	//		---- look ----

	else if (firstWord == "look")
	{
		if (secondWord == "north") lookAt(north);
		if (secondWord == "south") lookAt(south);
		if (secondWord == "east") lookAt(east);
		if (secondWord == "west") lookAt(west);
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
		if (secondWord == "door" || secondWord == "gate")
		{
			currentRoom->isDoor = false; //Doors don't stay opened until they are closed, they are just 
			cout << "\n Door/Gate is now OPEN";
		}
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
			return true; // Exit exists on that direction
		}
	}

	cout << "\n There is nothing there, maybe another way\n\n";
	return false; // Exit doesn't exist on that direction
}

void World::lookAt(const Direction dir)const
{
	for (int i = 0; i < 17; i++)
	{
		if (myExits[i]->checkExit(dir, currentRoom) == true)
		{
			myExits[i]->lookAt();
			return; // Exit exists , description printed already
		}
	}

	cout << "\n\n There is NOTHING that way\n\n"; // Exit doesn't exist
}