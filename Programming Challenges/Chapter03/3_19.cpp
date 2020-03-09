// Chapter 3 - Programming Challenge 19, Math Tutor 
// This program creates a random addition program, gives the student the
// opportunity to enter an answer. It then displays the correct answer.
#include <iostream>
#include <iomanip>
#include <cstdlib>            // Needed to use rand() and srand()
#include <ctime>              // Needed for system to "seed" the random number generator
using namespace std;

int main()
{
	const int MAX_NUM = 9;    // To allow numbers between 1 and 9

	unsigned seed;            // Seed for the random number generator
	int      number1,         // The two randomly generated numbers to be added
	         number2, 
	         correctAnswer;   // Correct answer to the problem 
	char ready;
	
	seed = time(0);           // Assigns a system-generated seed    
                              // Alternatively, user can be prompted to enter a seed
	srand(seed);

  	// Produce and display a problem
	number1 = 1 + rand() % MAX_NUM;
	number2 = 1 + rand() % MAX_NUM;
	cout << "\n  " << number1 << endl;
	cout << "+ "   << number2 << endl;
	cout << " -- \n ";      

	// Calculate the correct answer
	correctAnswer = number1 + number2;
	
	// Display the answer when the student presses the ENTER key
	cin.get(ready);
   	cout << "     *** Correct answer is " << correctAnswer << " *** \n";

	return 0;
}

/* SAMPLE RUN RESULT

  9
+ 9
 --
 18
      *** Correct answer is 18 ***
*/
