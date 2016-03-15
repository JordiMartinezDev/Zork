#include <iostream>
#include <string>
#include "World.h"

using namespace std;

int main()
{
	string userInput;
	
	cout << "This is a Zork like game, are you ready for this adventure?\n\n";
	cout << "Type help to see commands available\n\n> ";
	
	World myWorld;
	

	do{
		getline(cin, userInput);
		myWorld.inputManagement(userInput);
		cout << "> ";
	} while (userInput != "quit");
	
	system("PAUSE");

	return 0;
}