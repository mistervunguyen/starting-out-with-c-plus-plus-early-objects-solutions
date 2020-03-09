// Chapter 7 - Programming Challenge 15, Moving Inchworm--Solution B.
// This program creates a simple animation using Windows functions to
// simulate an inchworm moving across the screen. It uses arrays of
// strings to hold the shapes even though arrays are not introduced 
// until Chapter 8 because some instructors introduce arrays before
// classes. The file 7_15A provides a solution that does NOT use arrays.
#include <iostream>
#include <string>
#include <windows.h>  // Needed to set cursor positions
using namespace std;

int main()
{
	// Create a HANDLE object and a COORD structure for screen cursor positioning
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	int wormRow = 13;
	COORD wormPos = {0, wormRow};      // The worm will "walk" across rows 13-15
	
	string antenna =  "        \\/";
	
	string eyes[4] = {"        00",
	                  "     0  00",
					  "    000 00",
					  "     0  00"};
					  
	string body[4] = {"~000000000",
                      "~0000 0000",
                      "~000   000",	
                      "~0000 0000"};					  
		  
	for(int drawWorm = 1; drawWorm <= 64; drawWorm += 4)
	{
		for (int shape = 0; shape < 4; shape++)
		{
			// Set start column for this worm position
			wormPos.X = drawWorm + shape;
			
			wormPos.Y = wormRow;
			SetConsoleCursorPosition(screen, wormPos);
			cout << antenna << endl; 
	
			wormPos.Y = wormRow + 1;
			SetConsoleCursorPosition(screen, wormPos);
			cout << eyes[shape];
			
			wormPos.Y = wormRow + 2;
			SetConsoleCursorPosition(screen, wormPos);
			cout << body[shape];
	
			// Pause 1/3 second between moves. Then "erase" previous image.
			Sleep(333);
			for (int offset = 0; offset <=2; offset++)
			{  wormPos.Y = wormRow + offset;
			   SetConsoleCursorPosition(screen, wormPos);
			   cout << "          ";
			}
		}
	}

	return 0;
}
