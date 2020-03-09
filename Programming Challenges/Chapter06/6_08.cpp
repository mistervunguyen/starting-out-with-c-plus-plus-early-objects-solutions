// Chapter 6 - Programming Challenge 8, Lowest Score Drop
// This program averages a set of test scores after dropping the lowest one.
// Because students have not yet learned about arrays, each test score will
// need to be stored in a separate variable.
#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
void getScore(int &);	
void calcAverage(int, int, int, int, int);			
int  findLowest (int, int, int, int, int);			

int main()
{
	int test1, test2, test3, test4, test5;    // 5 user input test scores

	// Inform the user what the program does
	cout << "When you enter 5 test scores, I will drop the lowest \n"
		<< "one and find the average of the four highest ones. \n\n";
	
	// Call getScore once for each test score to be input
	getScore(test1);
	getScore(test2);
	getScore(test3);
	getScore(test4);
	getScore(test5);

	// Call calcAverage to calculate and display the average
	calcAverage(test1, test2, test3, test4, test5);

	return 0;
}// end of main function

/*********************************************************************
 *                         getScore                                  *
 * This function is called by main once for each test score to be    *
 * input and validated. The score is stored in a reference parameter.*
 *********************************************************************/
void getScore(int &score)
{
	cout << "Enter a test score between 0 and 100: ";
	cin  >> score;
	while (score < 0 || score > 100) 
	{
		cout << "Score must be in the range 0 - 100. "
			 << "Please re-enter score: ";
		cin  >> score;
	}
}// end of function getScore

/*****************************************************************
 *                         calcAverage                           *
 * This function is called by main to find and print the average *
 * of the best 4 out of the 5 scores passed to it as arguments.  *
 *****************************************************************/
 void calcAverage(int s1, int s2, int s3, int s4, int s5)
{
	int sum,                     // Sum of the 4 highest scores
		lowScore;                // Low score that will be dropped
	double average;

	// Call function findLowest, passing it the 5 scores.  When the
	// lowest score is returned, store it in the variable lowScore.
	lowScore = findLowest(s1, s2, s3, s4, s5);

	sum = s1 + s2 + s3 + s4 + s5 - lowScore;
	average = sum / 4.0;         // Prevent an integer divide

	cout << "\nAfter dropping the lowest score, the test average is " 
	     << average << endl;
}// end of function calcAverage

/**************************************************************
 *                          findLowest                        *
 * This function is called by calcAverage to determine which  *
 * of the 5 scores passed to it as arguments is the lowest.   *
 * The lowest score is returned.                              *
 **************************************************************/
int findLowest(int s1, int s2, int s3, int s4, int s5)
{
	int lowest = s1;

	if (s2 < lowest)
		lowest = s2;
	if (s3 < lowest)
		lowest = s3;
	if (s4 < lowest)
		lowest = s4;
	if (s5 < lowest)
		lowest = s5;
	return lowest;
}// end of function findLowest

/* SAMPLE RUN RESULTS

When you enter 5 test scores, I will drop the lowest
one and find the average of the four highest ones.

Enter a test score between 0 and 100: 82
Enter a test score between 0 and 100: 77
Enter a test score between 0 and 100: 70
Enter a test score between 0 and 100: 90
Enter a test score between 0 and 100: 81

After dropping the lowest score, the test average is 82.5
*/