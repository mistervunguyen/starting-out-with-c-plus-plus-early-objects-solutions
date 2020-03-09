// Chapter 7 - Programming Challenge 12, Ups and Downs
// This program illustrates screen control by moving the word UP
// up the screen and the word DOWN down the screen.
#include <iostream>
#include <windows.h>            // Needed to set cursor positions
using namespace std;

int main()
{
	// Create a HANDLE object and a twp COORD structures for screen cursor positioning
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD upPos   = {35,0},     // "UP" will print in column 35
		  downPos = {42,0};     // "DOWN" will print in column 42

	int upLine, downLine;
		  
	for (upLine = 23, downLine = 0; downLine < 23; upLine--, downLine++)
	{
		//Set UP row and print "UP"
		upPos.Y = upLine;
		SetConsoleCursorPosition(screen, upPos);
		cout << "UP" << endl; 

		// Set DOWN row and print "DOWN"
		downPos.Y = downLine; 
		SetConsoleCursorPosition(screen, downPos);
		cout << "DOWN" << endl; 

		// Pause between moves
		Sleep(400);
		
		// Erase previous UP/DOWN labels before looping again
		SetConsoleCursorPosition(screen, upPos);
		cout << "    " << endl; 
		SetConsoleCursorPosition(screen, downPos);
		cout << "    " << endl; 
	}
	// Display final configuration 
	upPos.Y = upLine;
	SetConsoleCursorPosition(screen, upPos);
	cout << "UP" << endl; 

	downPos.Y = downLine; 
	SetConsoleCursorPosition(screen, downPos);
	cout << "DOWN" << endl; 

	// Pause to view final configuration before erasing it
	Sleep(2000);
	SetConsoleCursorPosition(screen, upPos);
	cout << "    " << endl; 
	SetConsoleCursorPosition(screen, downPos);
	cout << "    " << endl; 
	return 0;
}
