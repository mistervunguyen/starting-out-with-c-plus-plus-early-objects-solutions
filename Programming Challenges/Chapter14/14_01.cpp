//Chapter  14 - Assignment 1, Iterative Factorial
//This program computes and prints the factorial
//of a number entered by the user.
 
#include <iostream>
using namespace std;

int factorial(int number);  //prototype

int main()
{
	//Explain purpose of program to user
	cout << "This program computes factorials.";

	//Ask for user input
	cout << "\nEnter an integer: ";
	int number;
	cin >> number;

	//compute and print result
	cout << "Factorial of " << number << " is " << factorial(number);

	return 0;
}

//******************************************
//        factorial                        *
// Computes the factorial of a number.     *
//******************************************
int factorial(int number)
{
   int result = 1;
   for (int factor = 2; factor <= number; factor++)
	   result = result * factor;
   
   return result;
}


