// Chapter 12, Assignment 13, Digit Sum of Squares and Cubes
// This program prints all positive integers less than 100 the 
// sum of whose digits in the integer, its square, and cube are
// all the same.
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

// Prototype
int sumOfDigits(long number);    

int main()
{
   cout << setw(10) << left << "Number"; 
   cout << setw(12) << left << "Square";
   cout << setw(12) << left << "Cube" << endl;
   cout << setfill('_');
   cout << setw(34) << right << " " << endl;
   cout << setfill(' ');
   for (int number = 1; number < 1000; number++)
   {
      long square = number*number;
	  long cube = square*number;
	  int numberDigitSum = sumOfDigits(number);
	  
	  if (numberDigitSum == sumOfDigits(square) && numberDigitSum == sumOfDigits(cube))
	  {
		  cout << setw(10) << left << number;  
		  cout << setw(12) << left << square;
		  cout << setw(12) << left << cube << endl;
	  }
   }
   cout << endl << endl;
}

/*************************************************************************
 *                          sumOfDigits                                  *
 *  Computes the sum of digits in a long integer. Internally, it does    *
 *  this by converting its argument to string form by writing it to      *
 *  an ostring object.                                                   *
 *************************************************************************/
int  sumOfDigits(long number)
{
  string numberString; // Will hold the converted string version of number
  ostringstream ostr;  // ostream object used to effect the conversion
  int digitSum = 0;    // Will hold the sum of all digits in the number
  // Convert the number to a string and retrieve the string
  ostr << number;
  numberString = ostr.str();
  // Add up all the digits in the string
  // A digit is converted to its corresponding integer by subtracting '0'
  for(unsigned int k = 0; k < numberString.length(); k++)
	  digitSum += (numberString[k] - '0');

  return digitSum;
}




