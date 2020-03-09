// Chapter 4 - Programming Challenge 4, Areas of Rectangles
// This program calculates and compares the area of two rectangles.
#include <iostream>
using namespace std;

int main()
{
	double length1, width1, area1,  // Length, width, and area of rectangle 1
		   length2, width2, area2;  // Length, width, and area of rectangle 2

	// Get inputs
	cout << "Enter the length and width of rectangle 1, separated by a space: ";
	cin  >> length1 >> width1;

	cout << "Enter the length and width of rectangle 2, separated by a space: ";
	cin  >> length2 >> width2;

	// Compute the areas of the two rectangles
	area1 = length1 * width1;
	area2 = length2 * width2;

	// Report which rectangle has the larger area
	if (area1 > area2)
		cout << "Rectangle 1's area is larger. \n";
	else if (area1 < area2)
		cout << "Rectangle 2's area is larger. \n";
	else
		cout << "Both rectangles have the same area. \n";

	return 0;
}

/* SAMPLE RUN RESULTS

Enter the length and width of rectangle 1, separated by a space: 10 6
Enter the length and width of rectangle 2, separated by a space: 12 4
Rectangle 1's area is larger.
*/
