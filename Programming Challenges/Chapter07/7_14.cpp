// Chapter 7 - Programming Challenge 14, Left and Right
// This program modifies Programming Challenge 12 so that the word LEFT
// moves leftward across the screen and the word RIGHT moves rightward
// across the screen. 
#include <iostream>
#include <windows.h>      // Needed to set cursor positions
using namespace std;

int main()
{
	// Create a HANDLE object and a twp COORD structures for screen cursor positioning
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD rightPos = {0, 10},       // "RIGHT" will print on row 10
		  leftPos  = {0, 13};       // "LEFT"  will print on row 13

	int rightCol, leftCol;
		  
	for (rightCol = 0, leftCol = 75; rightCol < 75; rightCol+=5, leftCol-=5)
	{
		//Set RIGHT column and print "RIGHT"
		rightPos.X = rightCol;
		SetConsoleCursorPosition(screen, rightPos);
		cout << "RIGHT" << endl; 

		// Set LEFT column and print "LEFT"
		leftPos.X = leftCol; 
		SetConsoleCursorPosition(screen, leftPos);
		cout << "LEFT " << endl; 

		// Pause 1/6 second between moves
		// This is what the program specs. requested, but actually the
		// movement can be better viewed with 3 moves per second Sleep(333).
		Sleep(167);
		
		// Erase previous UP/DOWN labels before looping again
		SetConsoleCursorPosition(screen, rightPos);
		cout << "     " << endl; 
		SetConsoleCursorPosition(screen, leftPos);
		cout << "     " << endl; 
	}
	// Display final configuration 
	rightPos.X = rightCol;
	SetConsoleCursorPosition(screen, rightPos);
	cout << "RIGHT" << endl; 

	leftPos.X = leftCol; 
	SetConsoleCursorPosition(screen, leftPos);
	cout << "LEFT" << endl; 
	
	// Pause to view final configuration 
	Sleep(2000);

	return 0;
}
