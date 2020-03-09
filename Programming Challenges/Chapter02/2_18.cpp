// Chapter 2 - Programming Challenge 18, Future Ocean Levels
// This program calculates, in both centimeters and inches, how 
// much the oceans are predicted to rise over the next 20 years.
#include <iostream>
using namespace std;

int main()
{  
	double annualRise = 3.1;          // Average number of millimeters the oceans 
	                                  // have risen per year over the past decade
	double cmPer_mm = .1;             // Number of centimeters in a millimeter
	double inPer_cm = .3937;          // Number of inches in a centimeter
	double riseInCentimeters;         // 20-year expected ocean rise in centimeters
	double riseInInches;              // 20-year expected ocean rise in inches
	                               	
	// Compute the number of centimeters and number of inches
	// the oceans are predicted to rise over the next 20 years
	riseInCentimeters = annualRise * cmPer_mm * 20;
	riseInInches = riseInCentimeters * inPer_cm;
	
	// Display the results
	cout << "If the oceans continue rising " << annualRise << " mm per year, \n"
	     << "they will rise a total of " << riseInCentimeters << " centimeters and \n" 
		 << riseInInches << " inches over the next 20 years. \n";
	
	return 0;
}

/* CORRECT RESULTS
If the oceans continue rising 3.1 mm per year,
they will rise a total of 6.2 centimeters and
2.44094 inches over the next 20 years.
*/