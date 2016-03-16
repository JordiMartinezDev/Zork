#include "Exit.h"

#ifndef _PLAYER_H
#define _PLAYER_H

class Player
{
	public:
		Player();
		~Player();

		void moveTo(Direction dir,Room* currentRoom)const;
	private:
		
};


#endif