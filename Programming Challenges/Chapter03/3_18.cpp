// Chapter 3 - Programming Challenge 18, Senior Citizen Property Tax
// This program computes the assessed value and property tax 
// on a senior citizen's property.
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	const double 
		ASSESS_FACTOR = .60,        // Factor to figure assessment value
		SENIOR_EXEMPTION = 5000.00; // Senior citizen homeowner exemption 

	const int
		NUM_QTRS = 4;               // Number of annual (quarterly) payments

	double actualValue,             // Actual value of property
		   assessedValue,           // Assessed value of property
		   taxRate,                 // County tax amount per $100
		   propertyTax,             // Amount of tax on property
		   quarterlyPmt;            // Amount due per payment

	// Get user input
	cout << "Enter the actual property value: $ ";
	cin  >> actualValue;
	cout << "Enter the amount of tax per $100 of assessed value: $";
	cin  >> taxRate;

	// Perform computations
	assessedValue = actualValue * ASSESS_FACTOR - SENIOR_EXEMPTION;
	propertyTax = (assessedValue / 100) * taxRate;
	quarterlyPmt = propertyTax / NUM_QTRS;
   
	// Display results
	cout << fixed << showpoint << setprecision(2) << endl;
	cout << "Property Value:    $" << setw(10) << actualValue << endl;
	cout << "Assessed Value:    $" << setw(10) << assessedValue << endl;
	cout << "Property Tax:      $" << setw(10) << propertyTax << endl;
	cout << "Quarterly Payment: $" << setw(10) << quarterlyPmt << endl;

	return 0;
}

/* SAMPLE RUN RESULTS

Enter the actual property value: $ 158000
Enter the amount of tax per $100 of assessed value: $2.64

Property Value:    $ 158000.00
Assessed Value:    $  89800.00
Property Tax:      $   2370.72
Quarterly Payment: $    592.68
*/
