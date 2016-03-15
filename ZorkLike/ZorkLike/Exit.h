#include "Room.h"

#ifndef _EXIT_H
#define _EXIT_H

enum Direction
{
	north = 1,
	south = 2,
	east = 3,
	west = 4,
	special = 5
};
class Exit
{
	public:

		Exit(const Direction exitDirection,Room* roomAt, Room* nextRoom, const char* description, bool bothDir, bool locked);
		~Exit();

		bool checkExit(const Direction dir, Room* roomAt)const;
		void lookAt(const Direction dir, Room* roomAt)const;

	private:
		const char* description;
		Room* roomTo,*roomAt;
		Direction dirTo;
		bool locked,bothDir;

};



#endif