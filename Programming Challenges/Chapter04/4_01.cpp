// Chapter 4 - Programming Challenge 1, Minimum/Maximum
// This program uses the conditional operator 
// to determine the relative size of two numbers.
#include <iostream>
using namespace std;

int main()
{
	int num1,     // First user entered number
	    num2,     // Second user entered number
	    min,      // Smaller of the two entered numbers
	    max;      // Larger of the two entered numbers

	// Input the two numbers to be compared
	cout << "Enter two different integers separated by a space: ";
	cin  >> num1 >> num2;

	// Determine min and max numbers
	min = (num1 < num2) ? (num1) : (num2);
	max = (num1 > num2) ? (num1) : (num2);

	// Display results
	cout << "\nThe smaller number is " << min << ".\n";
	cout << "The larger  number is "   << max << ".\n";

	return 0;
}

/* SAMPLE RUN RESULTS

Enter two different integers separated by a space: 12 4

The smaller number is 4.
The larger  number is 12.
*/
