#ifndef _ROOM_H
#define _ROOM_H

class Room
{
	public:
		Room(const char* roomName, const char* roomDescription);
		~Room();

		void lookAt() const;
		void lookAt(const char* direction) const;
	    

	private:
		const char* name, *description;
		
		
		
};


#endif