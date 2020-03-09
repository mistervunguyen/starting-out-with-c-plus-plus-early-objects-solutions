//Chapter 16 -- Assignment 2, Arithmetic Exceptions
//This program demonstrates Numeric Exceptions
 
#include <iostream>
using namespace std;

// This exception is thrown by the square root function
class SqrtException
{
};

//************************************************
//             mySqrt                            *
//  Computes the integer square root of          *
//  its integer parameter. Throws an exception   *
//  if a square root cannot be computed.         *
//************************************************
int mySqrt(int number)
{
   if (number < 0) throw SqrtException();

   // Check all integers less or equal to number to see if one of 
   // is a square root
   for (int r = 0; r*r <= number; r++)
   {
     if (r*r == number) 
         return r;           
   }

   //no square root, so throw an exception
   throw SqrtException();
}

int main()
{
   // Read a number
   int number;
   cout << "Enter an integer:";
   cin >> number;

   // Try to find its square root and catch the thrown exception if
   // the number has none
   try
   {
     int root = mySqrt(number);
     cout << "Square root is " << root;

   }
   catch(SqrtException)
   {
     cout << "The number " << number << " has no square root.";
   }

   return 0;
}
