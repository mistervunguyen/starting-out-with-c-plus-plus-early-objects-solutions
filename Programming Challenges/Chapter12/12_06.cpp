//        Chapter 12 -- Assignment 6,  Sum of Digits in a String
// This program reads in an integer (possibly a very large one) as a 
// a string and determines the minimum and maximum digits that occur
// in the integer, as well as the sum of all digits occuring  in the 
// integer.

#include <iostream>
#include <string>
using namespace std;

// Prototype for the function that will do it all.
void getSumMinMax(int &sum, char& min, char& max, string str);

int main()
{
   // Get the string
   cout << "Enter a string of digits: ";
   string str;     
   getline(cin, str);
   
   // Get the required information
   int sumOfDigits;
   char minDigit, maxDigit;
   getSumMinMax(sumOfDigits, minDigit, maxDigit, str);
   
   // Print out the information
   cout << "The sum of digits is " << sumOfDigits << endl;
   cout << "The minimum digit is " << minDigit << endl;
   cout << "The maximum digit is " << maxDigit << endl;    
    
   return 0;    
}

//*********************************************************************
//              getSumMinMax                                          *
// Computes the sum, minimum, and maximum of a string of digits.      *
//*********************************************************************   
void getSumMinMax(int &sum, char& min, char& max, string str)
{
    // Initialize
    sum = 0;
    min = '9';
    max = '0';
    for (int k = 0; k < str.length(); k++)
    {
       char ch = str[k];
       sum = sum  + (ch - '0') ;  
       if (ch < min) min = ch;
       if (ch > max) max = ch;        
    }    
}

