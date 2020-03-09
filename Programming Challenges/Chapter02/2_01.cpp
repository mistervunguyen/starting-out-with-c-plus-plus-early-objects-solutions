// Chapter 2 - Programming Challenge 1, Sum of Two Numbers
// This program calculates the sum of two numbers.
#include <iostream>
using namespace std;

int main()
{
	int firstNum  =  50;          // Define and initialize firstNum
	int secondNum = 100;          // Define and initialize secondNum
	int total;                    // total will hold the sum of the two numbers
										
	// Compute and display total
	total = firstNum + secondNum;
	cout << "The total of " << firstNum << " and " << secondNum << " is " << total << endl;

	return 0;
}

/* CORRECT RESULTS

The total of 50 and 100 is 150

*/