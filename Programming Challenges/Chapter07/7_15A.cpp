// Chapter 7 - Programming Challenge 15, Moving Inchworm--Solution A.
// This program creates a simple animation using Windows functions to
// simulate an inchworm moving across the screen. It implements the 
// solution without using arrays, as they are not introduced until 
// Chapter 8. However, because some instructors introduce arrays before
// classes, a solution that uses arrays can be found in file 7_15B. 

#include <iostream>
#include <string>
#include <windows.h>  // Needed to set cursor positions
using namespace std;

// Function prototype
void drawWorm(string eyes, string body, int startCol);

// Create a HANDLE object and a COORD structure for screen cursor positioning
const HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
const int wormRow = 13;    // The worm will "walk" across screen rows 13-15

int main()
{
	string eyes1 = "        00",
	       eyes2 = "     0  00",
		   eyes3 = "    000 00",
		   eyes4 = "     0  00";
					  
	string body1 = "~000000000",
	       body2 = "~0000 0000",
		   body3 = "~000   000",
		   body4 = "~0000 0000";
		   
    int startCol;		   
	
	for(int cycle = 0; cycle < 16; cycle++)
	{
		startCol = cycle*4;
		
		drawWorm(eyes1, body1, startCol);		
		drawWorm(eyes2, body2, startCol+1);
		drawWorm(eyes3, body3, startCol+2);
		drawWorm(eyes4, body4, startCol+3);
	}

	return 0;
}// end main function

/******************************************************
 *                     drawWorm                       *
 * This function draws the worm in its new position   *
 * Then it holds the screen to view it before erasing *
 * to prepare for the next move.                      *
 ******************************************************/
void drawWorm(string eyes, string body, int startCol)
{
	COORD wormPos = {startCol, wormRow}; 
	string antenna =  "        \\/";
	
	SetConsoleCursorPosition(screen, wormPos);
	cout << antenna << endl; 
		
	wormPos.Y++;
	SetConsoleCursorPosition(screen, wormPos);
	cout << eyes;
	
	wormPos.Y++;
	SetConsoleCursorPosition(screen, wormPos);
	cout << body;
	
	// Pause 1/3 second between moves. Then "erase" previous image.
	Sleep(333);
	for (int offset = 0; offset <=2; offset++)
	{  wormPos.Y = wormRow + offset;
	   SetConsoleCursorPosition(screen, wormPos);
	   cout << "          ";
	}
	
}// end drawWorm function
