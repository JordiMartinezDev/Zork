#include <iostream>
#include "Player.h"
#include "Room.h"
#include "Exit.h"

using namespace std;
Player::Player()
{
	
}

Player::~Player()
{

}

void Player::moveTo(Direction dir, Room* currentRoom)const
{

	cout << "you moved man!";
}