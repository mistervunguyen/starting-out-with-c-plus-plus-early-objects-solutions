// Chapter 14 --  Assignment 2, Recursive Conversion
// Simple example of recursion to display  a string a given number of times.
 
#include <iostream>
using namespace std;

// Function prototype
void sign(int);

int main()
{
      // Read in a number
	cout << "Enter an integer value and I will display a sign:  ";
      int number;
	cin >> number;

      // Call sign to display a message the given number of times
	sign(number);
	return 0;
}

//********************************************************
//                 sign                                  *
// A recursive function to  display No Parking num times.*
//********************************************************
void sign(int num)
{
    if (num > 0)
   {
      cout << "No Parking." << endl;
      num--;
      sign(num);
   }
}
