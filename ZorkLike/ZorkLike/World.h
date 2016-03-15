#include <string>
#include "Room.h"
using namespace std;

#ifndef _WORLD_H
#define _WORLD_H


class World
{
	public:
		World();
		~World();

		void inputManagement(const string &input) const;
		
	private:
		Room *currentRoom;
		Room *myRooms[9];
		Exit *myExits[8];
		Player *myPlayer;

};


#endif