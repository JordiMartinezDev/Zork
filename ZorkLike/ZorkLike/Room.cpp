#include <iostream>
#include "Room.h"

using namespace std;

Room::Room(const char* roomName,const char* roomDescription)
{
	name = (*roomName);
	description = (*roomDescription);
}

void Room::lookAt()
{
	cout << "\n\n " << name << " :\n\n" << description;
	
}

void Room::lookAt(const char* direction)
{

}