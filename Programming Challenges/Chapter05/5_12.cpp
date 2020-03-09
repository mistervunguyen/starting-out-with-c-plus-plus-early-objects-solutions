// Chapter 5 - Programming Challenge 12, Random Number Guessing Game
// This program uses a loop to let the user make guesses until
// a randomly generated integer between 1 and 100 is correctly guessed.
#include <iostream>
#include <cstdlib>              // Needed to use random numbers
#include <ctime>                // Needed to call the time function
using namespace std;

int main()
{
	const int MAX_NUM = 100;    // The maximum random value used
	unsigned seed;              // "Seed" for the random number generator
	int computerNum,            // The computer's randomly generated number
		guess;                  // The user's current guess

	// Seed the random generator and get a random integer between 1 and MAX_NUM
	seed = time(0);
	srand(seed);
	computerNum = rand() % MAX_NUM + 1;

	// Explain the game and get the user's first guess
	cout << "I am thinking of a number between 1 and " << MAX_NUM << ". \n";
	cout <<	"Can you guess what it is?  Enter your guess. ";
	cin  >> guess;
	cout << endl;
	
	// Loop to accept additional guesses until the right number is entered
	while (guess != computerNum)
	{
		if (guess > computerNum)
			cout << guess << " is too high. Try a smaller number. ";
		else
			cout << guess << " is too low.  Try a larger number.  ";
		
		cin  >> guess;
	}
	// We get here when the loop is exited, which means the user has
	// guessed correctly, so display a congratulatory message.
	cout << "\nCongratulations. You got it. My number was " << computerNum << ".\n";
	return 0;
}

/* SAMPLE RUN RESULTS 

I am thinking of a number between 1 and 100.
Can you guess what it is?  Enter your guess. 50

50 is too high. Try a smaller number. 25
25 is too high. Try a smaller number. 12
12 is too low.  Try a larger number.  19
19 is too high. Try a smaller number. 15
15 is too high. Try a smaller number. 13

Congratulations. You got it. My number was 13.
*/
