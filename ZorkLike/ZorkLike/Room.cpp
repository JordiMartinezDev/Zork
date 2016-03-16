#include <iostream>
#include "Room.h"

using namespace std;

Room::Room(const char* roomName,const char* roomDescription,bool isLocked)
{
	name = roomName;
	description = roomDescription;
	isDoor = isLocked;
}
Room::Room() //Overloaded constructor needed when we create "empty" rooms
{

}
Room::~Room()
{

}

void Room::lookAt()const
{
	cout << "\n\n " << name << " :\n\n" << description << "\n\n";
}