// Chapter 16 -- Assignment 3:  Min/Max Templates
// Simple template functions
 
#include<iostream>
#include <string>
using namespace std;

//*****************************************************
//          T min1(T number1, T number2)              *
// Template function for minimum of two data types.   *
//*****************************************************
template <class T>
T min1(T number1, T number2)
{
      return (number1 < number2)? number1 : number2;
}

//*****************************************************
//          T max1(T number1, T number2)              *
// Template function for maximum of two data types.   *
//*****************************************************
template <class T>
T max1(T number1, T number2)
{
      return (number1 > number2)? number1 : number2;
}

int main()
{
      // Try it out with numbers
      int num1 = 5;
      int num2 = 3;
      cout << "minimum of 5, 3 is:  " ;
      cout << min1(num1, num2) << endl;

      // Try it out with strings
      string hello = "hello";
      string hi = "hi";
      cout << "maximum of \"hello\" and \"hi\" is: ";
      cout << max1(hello, hi) << endl;

      return 0;
}
