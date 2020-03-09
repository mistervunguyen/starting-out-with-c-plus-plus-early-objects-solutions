// Chapter 5 - Programming Challenge 2, Sum of Numbers
// This program sums the integers from 1 through a number entered 
// by the user. A while loop is used to validate the user input. 
// A for loop is used to sum the numbers. Students may choose to use
// a while loop for both tasks.
#include <iostream>
using namespace std;

int main()
{
	int maxValue,        // Number the user enters
		total = 0;       // Accumulator to total the integers 1 through num

	// Accept and validate user input
	cout << "Enter a positive integer: ";
	cin  >> maxValue;
   
	while (maxValue < 1) 
	{
		cout << "The number cannot be less than one. Re-enter a positive integer: " ;
		cin  >> maxValue;
	}

	// Use a loop to accumulate the total
	for (int num = 1; num <= maxValue; num++) 
		total += num;                           
		
	// Display the total
	cout << "The total of all the integers from 1 to " << maxValue
		 << " is " << total << ".\n";		
	
	return 0;
}
/* SAMPLE RUN RESULTS 

Enter a positive integer: -5
The number cannot be less than one. Re-enter a positive integer: 0
The number cannot be less than one. Re-enter a positive integer: 8
The total of all the integers from 1 to 8 is 36. 
*/
