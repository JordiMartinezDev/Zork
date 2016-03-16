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

		Exit(Room* roomAtTmp, const Direction exitDirection, Room* roomToTmp, const char* description, bool locked);
		~Exit();

		bool checkExit(Direction dir, Room *roomAt);
		void lookAt()const;

	private:
		const char* description;
		Room* roomTo,roomAt;
		Direction dirTo;
		bool locked;

};



#endif