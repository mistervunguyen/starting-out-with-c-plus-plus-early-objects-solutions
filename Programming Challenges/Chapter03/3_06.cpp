// Chapter 3 - Programming Challenge 6, Test Average 
// This program calculates the average of a set of test scores.
// It uses a type cast.
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	const int NUM_TESTS = 5;

	int test1,          // Variables to hold the test scores
		test2,
		test3,		
	    test4,		
	    test5,
		testSum;        // Sum of the test scores

	double testAvg;     // Average of the test scores

	// Prompt user to enter the test scores
	cout << "Enter the " << NUM_TESTS << " test scores separated by "
		 << "one or more spaces." << endl;
	cin  >> test1 >> test2 >> test3 >> test4 >> test5 ;
												
	// Calculate the average score
	testSum = test1 + test2 + test3 + test4 + test5;
	testAvg = static_cast<double>(testSum) / NUM_TESTS ;

	// Display results
	cout << "The average of the " << NUM_TESTS << " scores is ";
	cout << fixed << showpoint << setprecision(1);
	cout << testAvg << endl;

	return 0;
}

/* SAMPLE RUN OUTPUT

Enter the 5 test scores separated by one or more spaces.
88 91 73 80 92
The average of the 5 scores is 84.8
*/
