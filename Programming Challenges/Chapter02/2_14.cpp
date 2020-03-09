// Chapter 2 - Programming Challenge 14, Basketball Player Height
// This program displays a person's height in feet/inches form.
// It utilizes the int divide and mod operators. 
#include <iostream>
using namespace std;

int main()
{   
	int heightInInches = 74,   // A person's height in inches
	    feet,                  // Number of feet high
	    inches;                // Number of additional inches high
		
	// Calculate number of feet and inches
	feet = heightInInches / 12;
	inches = heightInInches % 12;
	
	// Display results
	cout << "A " << heightInInches << " inch tall basketball player is ";
	cout << feet << " feet " << inches << " inches tall. \n";
	
	return 0;
}

/* CORRECT RESULTS
A 74 inch tall basketball player is 6 feet 2 inches tall.
*/