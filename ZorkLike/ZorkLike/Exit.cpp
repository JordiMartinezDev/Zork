#include "Exit.h"
#include <iostream>
using namespace std;

Exit::Exit(Room* roomAtTmp, const Direction exitDirection, Room* roomToTmp, const char* description, bool locked)
{
	roomAt = *roomAtTmp;
	roomTo = roomToTmp;
	dirTo = exitDirection;
	this->description = description;
	roomAt.isDoor = locked;
	this->locked = locked;
}

Exit::~Exit()
{
}

bool Exit::checkExit(Direction dir,Room *roomAt) // continue here, look at world's call to this funcion...
{
	
		if (roomAt->name == this->roomAt.name && dir == dirTo)
		{
			if (roomAt->isDoor && locked) //Check if door 
			{
				cout << "\n This way is locked";
				return true;
			}
			else
			{
				*roomAt = *roomTo; // Here is when player MOVES
				return true;
			}
		}
	return false;
}
void Exit::lookAt()const
{
	cout <<  description << "\n\n";
}