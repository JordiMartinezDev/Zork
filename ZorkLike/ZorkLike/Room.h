#ifndef _ROOM_H
#define _ROOM_H

class Room
{
	public:
		Room(const char* roomName, const char* roomDescription, bool isLocked);
		Room(); 
		~Room();

		void lookAt() const;
		const char* name, *description;
		bool isDoor;

	private:
		
		
		
		
};


#endif