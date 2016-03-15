
#include "Exit.h"

Exit::Exit(const Direction exitDirection,Room* roomAt ,Room* nextRoom, const char* description,bool bothDir, bool locked)
{
	this->roomAt = roomAt;
	roomTo = nextRoom;
	dirTo = exitDirection;
	this->description = description;
	this->locked = locked;
	this->bothDir = bothDir;
}

Exit::~Exit()
{
}

bool Exit::checkExit(Direction dir,Room* roomAt) const // continue here, look at world's call to this funcion...
{
	if (roomAt == this->roomAt && dir == dirTo);

	return true;
}
void Exit::lookAt(const Direction dir, Room* roomAt)const
{

}