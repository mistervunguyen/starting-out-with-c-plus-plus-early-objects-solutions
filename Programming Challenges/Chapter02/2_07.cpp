// Chapter 2 - Programming Challenge 7, Number of Acres
// This program calculates the number of acres in a tract of land.
#include <iostream>
using namespace std;

int main()
{
	double sqFtPerAcre = 43450;  // Gas tank capacity in gallons
	double length = 869;         // Tract length in feet
	double width  = 360;         // Tract width in feet
	double area;                 // Tract area in sq. ft.
	double acres;                // Number of acres in the tract area
	

	// Compute tract area and total acres
	area = length * width;
	acres = area / sqFtPerAcre;

   
	// Display results
	cout << "A " << length << " x " << width << " feet tract of land contains "
		<< acres << " acres. \n";
	    
	return 0;
}

/* CORRECT RESULTS
A 869 x 360 feet tract of land contains 7.2 acres.
*/

