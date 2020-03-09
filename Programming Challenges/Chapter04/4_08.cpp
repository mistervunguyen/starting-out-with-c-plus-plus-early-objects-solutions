// Chapter 4 - Programming Challenge 8, Math Tutor Version 2
// This program creates a random addition problem and allows an answer
// to be entered. It then reports whether or not the entered answer is correct.
// It is an enhanced version of the Chapter 3 Math Tutor Programming Challenge.
#include <iostream>
#include <iomanip>
#include <cstdlib>            // Needed to use rand() and srand()
#include <ctime>              // Needed to "seed" the random number generator
using namespace std;

int main()
{
	const int MIN_NUM = 10,   // Valid numbers are between 10 and 50
		      MAX_NUM = 50;   

	unsigned seed;            // Seed for the random number generator
	int      rangeSize,       // The size of the range of valid numbers
		     number1,         // The two randomly generated numbers to be added
	         number2, 
	         correctAnswer,   // Correct answer to the problem 
			 studentAnswer;   // Student's entered answer

	seed = time(0);           // Assigns a system-generated seed    
                              // Alternatively, student can be prompted to enter a seed
	srand(seed);

	// Produce and display a problem
	rangeSize = MAX_NUM - MIN_NUM + 1;
	
  	number1 = rand() % rangeSize + MIN_NUM;
	number2 = rand() % rangeSize + MIN_NUM;
	
	cout << "\n  " << setw(2) << number1 << endl;
	cout << "+ "   << setw(2) << number2 << endl;
	cout << "  -- \n  ";
     
	// Calculate the correct answer
   correctAnswer = number1 + number2;
   
   // Input student answer
	cin >> studentAnswer;
	
	// Display whether it is right or wrong
	if (studentAnswer == correctAnswer)
		cout << "\n\nCongratulations! That's right.\n";
	else
		cout << "\n\nSorry, the correct answer is " 
	         << correctAnswer << endl;
	return 0;
}

/* SAMPLE RESULTS - RUN 1
  33
+ 30
  --
  63
  
Congratulations! That's right.

SAMPLE RESULTS - RUN 2
  11
+ 32
  --
  33

Sorry, the correct answer is 43
*/
