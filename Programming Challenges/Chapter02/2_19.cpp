// Chapter 2 - Programming Challenge 19, Annual High Temperatures
// This program calculates the new average high July temperatures in 
// several U.S. cities if current temperatures rise by 2 percent.
#include <iostream>
using namespace std;

int main()
{  
	int NewYorkHighTemp =  85,      // Current average July high Fahrenheit 
		DenverHighTemp  =  88,      // temperatures in several U.S. cities
		PhoenixHighTemp = 106;        
	double pctRise = .02;           // 2% temperature rise

	// Compute and display the new avg high July temperature for each city
	cout << "Here are the new average high July temperatures \n"
	     << "if current temperatures rise by 2 percent: \n\n";
	cout << "New York  " << NewYorkHighTemp * (1 + pctRise) << endl;
	cout << "Denver    " << DenverHighTemp  * (1 + pctRise) << endl;;
	cout << "Phoenix  " << PhoenixHighTemp  * (1 + pctRise) << endl;;
	
	return 0;
}

/* CORRECT RESULTS
Here are the new average high July temperatures
if current temperatures rise by 2 percent:

New York  86.7
Denver    89.76
Phoenix  108.12
*/