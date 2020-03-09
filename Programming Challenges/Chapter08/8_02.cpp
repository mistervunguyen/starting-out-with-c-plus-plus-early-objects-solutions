// Chapter 8 - Programming Challenge 2, Larger Than n
// This program determines how many numbers in an integer array are larger
// than a user-entered value. In this solution we made the array size 25 and
// used the prime numbers between 1 and 100 as our values. However the problem
// did not specify what the array size or the values it holds should be.
// It also did not require the values in the array to be in order.
#include <iostream>
using namespace std;

// Function prototype
int countLarger(int[], int, int);

int main()
{
	const int SIZE = 25;
	int array[] = { 2,  3,  5,  7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 
		           43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
	int	enteredVal,       // User entered value to compare array elements to
		numLarger;        // Accumulator to count how many array values are
	                      // larger than the entered value.
	// Explain the program to the user
	cout << "This program contains an array holding 25 integers between 1 and 100.\n"
		 << "If you enter an integer in this range, the program will tell you how \n"
		 << "many of the numbers are larger than your value \n";

	cout << "\nEnter an integer between 1 and 100: "; 
	cin >> enteredVal;

	// Call a function to count how many larger values there are
	numLarger = countLarger(array, SIZE, enteredVal);

	// Report the results
	cout << numLarger << " of the 25 array values are larger than " << enteredVal << ". \n";
	
	return 0;
}

/********************************************************
 *                     countLarger                      *
 * Counts and returns the number of values in the array *
 * passed to it that are larger than val.               *
 ********************************************************/
int countLarger(int A[], int size, int val)
{
	int total = 0; 

	for (int pos = 0; pos < size; pos++)
	{
		if (A[pos] > val)
			total++;
	}
	return total;
}


/* SAMPLE RUN RESULTS

This program contains an array holding 25 integers between 1 and 100.
If you enter an integer in this range, the program will tell you how
many of the numbers are larger than your value

Enter an integer between 1 and 100: 35
14 of the 25 array values are larger than 35.
*/
