#ifndef _ROOM_H
#define _ROOM_H

class Room
{
	public:
		Room(const char* roomName,const char* roomDescription);
		~Room();

		void lookAt();
		void lookAt(const char* direction);
	    
	private:
		char name, description;
		
		
		
};


#endif