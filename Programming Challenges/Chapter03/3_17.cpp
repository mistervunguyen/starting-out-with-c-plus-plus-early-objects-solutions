// Chapter 3 - Programming Challenge 17, Property Tax 
// This program computes a property's assessed value and property tax.
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	const double ASSESS_FACTOR = .60;  // Factor to figure assessment value

	double actualValue,                // Actual value of property
		   assessedValue,              // Assessed value of property
		   taxRate,                    // County tax amount per $100
		   propertyTax;                // Aamount of tax on property

	// Get user input
	cout << "Enter the actual property value: $ ";
	cin  >> actualValue;
	cout << "Enter the amount of tax per $100 of assessed value: $";
	cin  >> taxRate;

	// Perform computations
	assessedValue = actualValue * ASSESS_FACTOR;
	propertyTax = (assessedValue / 100) * taxRate;

	// Display results
	cout << fixed << showpoint << setprecision(2) << endl;
	cout << "Property Value:  $ " << setw(10) << actualValue << endl;
	cout << "Assessed Value:  $ " << setw(10) << assessedValue << endl;
	cout << "Property Tax:    $ " << setw(10) << propertyTax << endl;

	return 0;
}

/* SAMPLE RUN RESULTS

Enter the actual property value: $ 158000
Enter the amount of tax per $100 of assessed value: $2.64

Property Value:  $  158000.00
Assessed Value:  $   94800.00
Property Tax:    $    2502.72
*/
