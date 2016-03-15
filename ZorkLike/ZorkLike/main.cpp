#include <iostream>
#include <string>
#include "World.h"

using namespace std;

int main()
{
	char userInput[30];
	
	cout << "This is a Zork like game, are you ready for this adventure?\n\n";
	cout << "Type help to see commands available\n\n> ";
	
	World myWorld;
	

	do{
		
		cin.getline(userInput, 30);
		
		myWorld.inputManagement(userInput);
		cout << "> ";
	} while (userInput != "quit");
	
	system("PAUSE");

	return 0;
}