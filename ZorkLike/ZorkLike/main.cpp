#include <iostream>
#include <string>
#include "World.h"

using namespace std;

int main()
{
	char userInput[30];
	bool playing;
	cout << "This is a Zork like game, are you ready for this adventure?\n\n";
	cout << "Type help to see commands available\n\n> ";
	
	World* myWorld = new World();
	do{
		
		cin.getline(userInput, 30);
		if (*userInput != NULL) playing = myWorld->inputManagement(userInput);
		
		cout << "> ";
	} while (playing);
	
	system("PAUSE");

	delete myWorld;
	return 0;
}