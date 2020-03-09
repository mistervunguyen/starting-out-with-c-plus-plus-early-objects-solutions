// Chapter 6 - Programming Challenge 2, Celsius Temperature Table
// This program uses a function to compute Celsius equivalents of
// Fahrenheit temperatures to be displayed in a table.
#include <iostream>
#include <iomanip>
using namespace std;

// Function prototype
double celsius (int);

int main()
{   
  	// Output table headings
	cout << "Temperature Conversion Table\n\n";
	cout << "    Fahrenheit   Celsius\n" 
		 << "    ____________________\n";
		
	// Set output format
	cout << fixed << showpoint << setprecision(1);

	// Create the table
	for (int fahrenheit = 0; fahrenheit <= 20; fahrenheit++)
	{
		// Call the celsius function to get the celsius equivalent
		// of the Fahrenheit temperature to display
		cout << setw(9) << fahrenheit << setw(12) << celsius(fahrenheit) << endl;
	}
	return 0;
}// end of main function

/*************************************************************
 *                       	  celsius                        *
 * This function computes and returns the Celsius equivalent *
 * of the Fahrenheit temperature passed to it.               *
 *************************************************************/
double celsius (int f)
{
	double c = (5.0 / 9.0) * (f - 32);
	
	return c;
	
}// end of celsius function

/* CORRECT RESULTS

Temperature Conversion Table
    Fahrenheit   Celsius
    ____________________
        0       -17.8
		1       -17.2
		2       -16.7
		3       -16.1
		4       -15.6
		5       -15.0
		6       -14.4
		7       -13.9
		8       -13.3
		9       -12.8
       10       -12.2
	   11       -11.7
	   12       -11.1
	   13       -10.6
	   14       -10.0
	   15        -9.4
	   16        -8.9
	   17        -8.3
	   18        -7.8
	   19        -7.2
	   20        -6.7
*/
