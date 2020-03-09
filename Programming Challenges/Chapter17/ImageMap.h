#include <iostream>
#include <list>
#include <windows.h>
using namespace std;
 
const HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

class ImageMap:list<COORD>{
  
public:
    // Add an array of coordinates to the image map
    void add(COORD coordArray[]);
    // Convenience method for adding an array of coordinates
    void add(short *coordAsShorts);
    // Display a given character at a specified position
    void displayAt(char ch, int col, int row);
    // Display an asterisk at a given position
    void displayAt(int col, int row)
    {
        displayAt('*', col, row);
    }
    // Erase whatever character is at a given position
    void eraseAt(int col, int row)
    {
        displayAt(' ', col, row);
    }
	// Reflect the image about a vertical line though the center of the screen
	// All x coordinates become 80 - x
	void aboutFace();

	// Debugging aid
	void dump();	

};
