// Chapter 12 - Assignment 20, Palindromic Numbers
// This program lists all  numbers less than 10000
// that are palindromes and have squares that are 
// also palindromes.

#include <iostream>
#include <string>
#include <algorithm>
using namespace  std;

//**************************************************
//              palindromic                        *
// This function tests a number to see if it       *
// reads the same backwards and forwards           *
//**************************************************/
bool palindromic(long number)
{
   string str_number = to_string(number);
   string str_number_copy = str_number;
   reverse(str_number_copy.begin(), str_number_copy.end());
   return to_string(number) == str_number_copy;
}


int main()
{

   // List all palindromic numbers less than 10000
   // whose squares are also palindromes.
   for (long k = 1; k <= 10000; k++)
   {
      if (!palindromic(k)) { continue; }
      long square = k * k;
      if (!palindromic(square)) { continue; }

      cout << k << " has square " << square << endl;
   }
   return 0;
}