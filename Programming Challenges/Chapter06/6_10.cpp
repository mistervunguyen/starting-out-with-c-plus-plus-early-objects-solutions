// Chapter 6 - Programming Challenge 10, isPrime Function
// This program uses a Boolean function that determines whether or not
// the positive integer passed to it is a prime number. There are more 
// efficient algorithms for determining primeness, but students at this
// level are not yet expected to use them. In fact, any algorithm that 
// works accurately should be considered acceptable at this point.
#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int);

int main()
{
	int number;        // Number input by the user to be tested for primeness

	// Get a number from the user
	cout << "I can tell you whether or not a number is prime.\n";
	cout << "Enter a positive integer: ";
	cin  >> number;

	//Call isPrime to test it for primeness and display the result
	if (isPrime(number))
	{
		cout << number << " is prime. ";
		cout << "It is divisible only by 1 and itself.\n"; // This 2nd stmt
	}                                                      // is optional
	else
		cout << number << " is not prime.\n";

	return 0;
}

/*************************************************************
 *                          isPrime                          *
 * This function returns true if the integer passed to it is *
 * a prime number, and returns false if it is not.           *
 *************************************************************/
bool isPrime(int num)
{
	if (num < 2)      // Integers < 2 cannot be prime
		return false;

	if (num == 2)     // Special case: 2 is the only even prime number
		return true;

	if (num %2 == 0)  // Other even numbers are not prime
		return false;

	// Test odd divisors up to the square root of num
	// If any of them divide evenly into it, then num is not prime
	for (int divisor = 3; divisor <= sqrt(num); divisor +=2)
	{
		if (num % divisor == 0)
			return false;
	}
	// If we got this far without returning, num is prime
	return true;
}

/* SAMPLE RESULTS RUN 1

I can tell you whether or not a number is prime.
Enter a positive integer: 121
121 is not prime.

SAMPLE RESULTS RUN 2

I can tell you whether or not a number is prime.
Enter a positive integer: 67
67 is prime. It is divisible only by 1 and itself.
*/