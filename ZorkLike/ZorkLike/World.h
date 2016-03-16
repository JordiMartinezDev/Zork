#include <string>
#include "Room.h"
#include "Exit.h"
#include "Player.h"

using namespace std;

#ifndef _WORLD_H
#define _WORLD_H


class World
{
	public:
		World();
		~World();

		bool inputManagement(char* input) const;
		bool checkExit(Direction dir) const;
	private:

		Room* currentRoom;
		Room* myRooms[10];
		Exit* myExits[17];
		Player* myPlayer;

};


#endif