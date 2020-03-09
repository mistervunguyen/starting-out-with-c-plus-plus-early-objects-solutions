// Chapter 2 - Programming Challenge 17, Past Ocean Levels 
// This program calculates, in both centimeters and inches,  
// how much the oceans have risen over the past 100 years.
#include <iostream>
using namespace std;

int main()
{  
	double annualRise = 1.8;    // Average number of millimeters the oceans 
	                            // have risen per year over the past century
	double cmPer_mm = .1;       // Number of centimeters in a millimeter
	double inPer_cm = .3937;    // Number of inches in a centimeter
	double riseInCentimeters;   // Number of centimeters the oceans have risen 
	double riseInInches;        // Number of inches the oceans have risen 
	
	// Compute the number of centimeters and the number of inches 
	// the oceans have risen in the past century.
	riseInCentimeters = annualRise * cmPer_mm * 100;
	riseInInches = riseInCentimeters * inPer_cm;
	
	// Display the results
	cout << "Over the past century, the oceans have risen an average of " << annualRise << " mm per year. \n";
	cout << "This is a total rise of " << riseInCentimeters << " centimeters and "
	     << riseInInches << " inches in 100 years. \n"; 

	return 0;
}

/* CORRECT RESULTS
Over the past century, the oceans have risen an average of 1.8 mm per year.
This is a total rise of 18 centimeters and 7.0866 inches in 100 years.
*/
