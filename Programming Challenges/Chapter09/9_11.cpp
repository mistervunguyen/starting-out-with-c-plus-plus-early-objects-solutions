// Chapter 9 - Programming Challenge 11, Ascending Circles
// This modifies Program 8-31 from Chapter 8 to create an array of 7 Circle
// objects, use a Bubble Sort to arrange them in ascending order of radius 
// size, and then compute and display their areas. Displaying the circle radii
// along with their areas is optional. The Circle.h file that defines the class
// used by this program is located in the Chapter 9 Programs folder, and for
// faculty is also in the same folder as this solution file. A copy of the 
// Circle.h file should be placed in the program's project directory. 
#include <iostream>
#include <iomanip>
#include "Circle.h"    // Needed to create Circle objects
using namespace std;

// Function prototypes
// These functions each receive an array of Circle objects
void bubbleSort(Circle[]);
void displayAreas(Circle[]); 

const int NUM_CIRCLES = 7;

int main()
{
	// Define an array of 8 Circle objects. Use an initialization list
	// to call the 1-argument constructor that sets their radii.
	Circle circle[NUM_CIRCLES] = {2.5, 4.0, 1.0, 3.0, 6.0, 5.5, 2.0};       
	              
	// Call a function to sort the object according to radius size
	bubbleSort(circle);

	// Now call a function to display the area of each object
	cout << fixed << showpoint;
	cout << "Here are the areas of the " << NUM_CIRCLES 
         << " circles.\n\n";
	displayAreas(circle);	  

	return 0;
} // End main

/*************************************************************
 *                       bubbleSort                          *
 * Called by: main                                           *
 * Passed   : The array of Circle objects to be sorted       *
 * Purpose  : Sorts the objects into ascending radius order  *
 *************************************************************/
void bubbleSort(Circle circle[])
{
	bool swap;
	Circle temp;
	
	do
	{	swap = false;           // There have been no swaps yet on this pass
		for (int count = 0; count < (NUM_CIRCLES - 1); count++)
		{
			if (circle[count].getRadius() > circle[count + 1].getRadius())
			{
				// The 2 array elements are out of order, so swap them 
				temp = circle[count];
				circle[count] = circle[count + 1];
				circle[count + 1] = temp;
				swap = true;
			}
		}
	} while (swap);            // While there was a swap on the previous pass
}// End function bubbleSort

/*************************************************************
 *                       displayAreas                        *
 * Called by: main                                           *
 * Passed   : The array of Circle objects                    *
 * Purpose  : Displays the radius and area of each circle    *
 *************************************************************/
void displayAreas(Circle circle[])
{
	for (int index = 0; index < NUM_CIRCLES; index++)
	{
		cout << "circle " << (index+1) << " with radius " 
			 << setprecision(1) << circle[index].getRadius() << " has area = "
			 << setw(6) << setprecision(2) << circle[index].findArea() << endl;
	}
}// End function displayAreas

/* CORRECT RESULTS

Here are the areas of the 7 circles.

circle 1 with radius 1.0 has area =   3.14
circle 2 with radius 2.0 has area =  12.56
circle 3 with radius 2.5 has area =  19.63
circle 4 with radius 3.0 has area =  28.26
circle 5 with radius 4.0 has area =  50.24
circle 6 with radius 5.5 has area =  94.98
circle 7 with radius 6.0 has area = 113.04

*/
