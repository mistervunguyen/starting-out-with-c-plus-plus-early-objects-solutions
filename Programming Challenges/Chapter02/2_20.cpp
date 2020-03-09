// Chapter 2 - Programming Challenge 20, How Much Paint
// This program calculates how much paint is needed to paint a fence.
// Because students have not yet learned to perform typecasts, some
// of the variables have been made doubles to avoid integer division.
#include <iostream>
using namespace std;

int main()
{  
	int length = 100,              // Fence length in ft. 
		height = 6,                // Fence height in ft.
		areaToPaint,               // SqFt of fence to be painted
		numCoats = 2;              // Number of coats of paint

	double	sqFtPerGal = 340.0,    // Number of sq. ft. a gallon can cover 
	        gallons;               // Number of gallons needed
	                                 
	// Compute the total sq. ft. of fence to be painted
	// and the number of gallons of paint needed
	areaToPaint = length * height * numCoats;
	gallons = areaToPaint / sqFtPerGal;
	
	// Display the results
	cout << gallons << " gallons of paint are needed to paint "
		 << numCoats << " coats on a " << length << " x " << height 
		 << " foot fence. \n";
	
	return 0;
}

/* CORRECT RESULTS
3.52941 gallons of paint are needed to paint 2 coats on a 100 x 6 foot fence.
*/