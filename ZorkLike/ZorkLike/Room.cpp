#include <iostream>
#include "Room.h"

using namespace std;

Room::Room(const char* roomName,const char* roomDescription,bool isLocked)
{
	name = roomName;
	description = roomDescription;
	isDoor = isLocked;
}
Room::Room()
{

}
Room::~Room()
{

}

void Room::lookAt()const
{
	cout << "\n\n " << name << " :\n\n" << description;
}

void Room::lookAt(const char* direction)const
{

}