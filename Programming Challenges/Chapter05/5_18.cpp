// Chapter 5 - Programming Challenge 18, Math Tutor Version 3
// This menu-driven program creates a random arithmetic problem for a student. 
// It is an enhanced version of the Math Tutor Programming Challenge in Chapter 4.
// The problem statement did not specify the allowable range for numbers in
// each problem, so students may have used different ranges.
#include <iostream>
#include <iomanip>
#include <cstdlib>            // Needed to use random numbers
#include <ctime>              // Needed to call the time function
#include <string>
using namespace std;

int main()
{
	const int MAX_NUM = 50;   // Problem values will be between 1 and 50
	int choice,               // Menu choice for problem type
		number1,              // The two randomly generated numbers to be
		number2,              //   used in the problem
		correctAnswer,        // Correct answer to the problem 
		studentAnswer;        // Student's entered answer
	string sign = "  ";       // Will be assigned +, -, or *

	unsigned seed = time(0);  // Gets a system-generated seed
	                          // Alternatively, user could be prompted to enter 
	srand(seed);              // a seed to initialize the random number generator

	do
	{	// Display Menu and get user's menu choice
		cout << "\n\n        Menu\n";
		cout << "1. Addition problem\n";
		cout << "2. Subtraction problem\n";
		cout << "3. Multiplication problem\n";
		cout << "4. Quit this program\n";
		cin  >> choice;

		// Carry out the user's choice
		switch (choice)
		{
         case 1:  // Addition problem
            number1 = 1 + rand() % MAX_NUM;
            number2 = 1 + rand() % MAX_NUM;
			sign = " + ";
            correctAnswer = number1 + number2;
            break;

         case 2:  // Subtraction problem
            number1 = 1 + rand() % MAX_NUM;	
            number2 = 1 + rand() % number1;     // num2 will be <= num1
			sign = " - ";
            correctAnswer = number1 - number2;              
            break;

		 case 3:  // Multiplication problem
            number1 = 1 + rand() % MAX_NUM;	
            number2 = 1 + rand() % 9;          // Single digit multiplier
			sign = " * ";
            correctAnswer = number1 * number2;            
            break;

		 case 4:  // Exit
			 cout << "\nThank you for using Math Tutor.\n";
			 break;
	
         default:  // Invalid menu selection
			 cout << "Invalid input. You must enter 1-4.\n";
		}

		// If student chose to do a problem
		if (choice >= 1 && choice <= 3)
		{
			// Display it
			cout << "\n\n";
            cout << setw(6) << number1 << endl;
            cout << sign << setw(3) << number2 << endl;
            cout << "   ---"  << endl;
            
			// Position the cursor for the user's input
			if (correctAnswer < 100)
				cout << "    ";
			else
				cout << "   ";
						
			// Get and evaluate student answer
			cin  >> studentAnswer;
			if (studentAnswer == correctAnswer)
				cout << "\nCongratulations! That's right.\n";
			else
				cout << "\nSorry, the correct answer is " << correctAnswer << ".\n";
		}
	} while (choice != 4);  // Loop again if student did not choose to quit

	return 0;
}

/* SAMPLE RUN RESULTS


      Menu
1. Addition problem
2. Subtraction problem
3. Multiplication problem
4. Quit this program
1


    10
 +  24
   ---
    34

Congratulations! That's right.


      Menu
1. Addition problem
2. Subtraction problem
3. Multiplication problem
4. Quit this program
2


    11
 -   9
   ---
     2

Congratulations! That's right.


      Menu
1. Addition problem
2. Subtraction problem
3. Multiplication problem
4. Quit this program
3


    33
 *   4
   ---
   122

Sorry, the correct answer is 132.


      Menu
1. Addition problem
2. Subtraction problem
3. Multiplication problem
4. Quit this program
4

Thank you for using Math Tutor.
*/
