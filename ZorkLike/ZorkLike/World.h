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

		void inputManagement(char* input) const;
		bool checkExit(Direction dir) const;
	private:

		Room* currentRoom;
		Room* myRooms[9];
		Exit* myExits[9];
		Player* myPlayer;

};


#endif