// Chapter 5 - Programming Challenge 14, The Greatest and Least of These
// This program uses a sentinel controlled loop to finds the greatest 
// and smallest values in a set of user entered numbers.
#include <iostream>
using namespace std;

int main()
{
	int num,                  // Holds each number input by the user
		greatest,             // Largest value
		least,                // Smallest value
		sentinel = -99;       // End sentinel to terminate the loop

	// Input the first number
	cout << "Enter an integer (or " << sentinel << " to quit): ";
	cin  >> num;

	// Initialize largest and smallest variables to the first number
	greatest = least = num;	 

	// So long as the previous number entered was not -99, process it
	while (num != sentinel) 
	{ 
		if (num > greatest)
			greatest = num;
		else if (num < least)
			least = num;

		// Get the next number
		cout << "Enter another integer (or " << sentinel << " to quit): ";
		cin  >> num;
	}
  	// Display the results
	cout << "\nThe  largest number you entered was " << greatest << ".\n";
	cout << "The smallest number you entered was " << least << ".\n";

	return 0;
}

/* SAMPLE RUN RESULTS

Enter an integer (or -99 to quit): 5
Enter another integer (or -99 to quit): 10
Enter another integer (or -99 to quit): 22
Enter another integer (or -99 to quit): 3
Enter another integer (or -99 to quit): 19
Enter another integer (or -99 to quit): -99

The  largest number you entered was 22.
The smallest number you entered was 3.
*/
