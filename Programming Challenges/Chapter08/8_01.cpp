// Chapter 8 - Programming Challenge 1, Perfect Scores
// This program counts the number of perfect scores stored in an integer array. 
#include <iostream>
using namespace std;

// Function prototypes
int getScores(int[]);
int countPerfect(int[], int);

int main()
{
	const int SIZE = 20;
	int array[SIZE],
		numScores;

	// Explain the program to the user
	cout << "This program will allow you to enter up to 20 scores \n"
		 << "and will then report how many perfect scores were entered. \n\n";

	// Call a function to input the scores into array.
	numScores = getScores(array);  

	// Report the results
	cout << "\nThe " << numScores << " scores you entered include " 
		 << countPerfect(array, numScores) << " perfect scores. \n";

	return 0;
}

/*******************************************************
 *                     getScores                       *
 * Accepts scores input by the user, stores them in an *
 * array, and counts them.                             *
 *******************************************************/
int getScores (int array[])
{
   int num,
	   pos = 0;
   
   do
   {   cout << "Enter a score 0 - 100 (or -1 to quit): ";
	   cin  >> num;

	   if (num >= 0 && num <= 100)  // If num is valid,
	   {   array[pos] = num;        // store it and go
		   pos++;                   // to the next array position.
	   }
	   else if (num > 100)          // If num is invalid, display an error message.
	   {   cout << "\nInvalid score. Scores many not be greater than 100. \n\n";
	   }
	   // else the end sentinel was entered, so do nothing.

   } while (num >= 0 && pos < 20);  // Loop again as long as the end sentinel
	                                // has not yet been entered and the number
								    // of array locations has not been exceeded.
  
   return pos;   // The current value of pos equals the number of scores.
}

/*******************************************************
 *                  countPerfect                       *
 * Counts the number of "perfect" (i.e., 100) scores   *
 * in the array of integers passed to it.              *
 *******************************************************/
int countPerfect(int array[], int numElts)
{
	int numPerfect = 0;

	for (int i = 0; i < numElts; i++)
	{
		if (array[i] == 100)
			numPerfect++;
	}
    return numPerfect;
}

/* SAMPLE RUN RESULTS

This program will allow you to enter up to 20 scores
and will then report how many perfect scores were entered.

Enter a score 0 - 100 (or -1 to quit): 88
Enter a score 0 - 100 (or -1 to quit): 93
Enter a score 0 - 100 (or -1 to quit): 100
Enter a score 0 - 100 (or -1 to quit): 79
Enter a score 0 - 100 (or -1 to quit): 82
Enter a score 0 - 100 (or -1 to quit): 96
Enter a score 0 - 100 (or -1 to quit): 100
Enter a score 0 - 100 (or -1 to quit): 93
Enter a score 0 - 100 (or -1 to quit): 86
Enter a score 0 - 100 (or -1 to quit): 91
Enter a score 0 - 100 (or -1 to quit): -1

The 10 scores you entered include 2 perfect scores.
*/
