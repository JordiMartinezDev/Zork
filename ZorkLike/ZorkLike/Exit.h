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
		Exit(const Direction exitDirection,Room* nextRoom,const Direction returnDirection,Room* returnRoom,const char* description,bool locked);

		~Exit();
	private:
};



#endif