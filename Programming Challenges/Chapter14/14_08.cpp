// Chapter 14 - Assignment 8, Palindrome Testing
// This program implements a recursive function for  testing a 
// string to see whether it is a  palindrome.


#include <string>
#include <iostream>

using namespace std;

// index-based palindrome checker
bool isPalindrome(string str, int lower, int upper);


int main()
{   
   while (true)
   {
      cout << "Enter a string, blank line to quit?";
      string str;
      //  Read the input string, quit if empty string is entered.
      if (!getline(cin, str) || str.empty()) return 1;

      // Check if palindrome
      if (isPalindrome(str, 0, str.length()-1))
      {
         cout << str << " is a palindrome\n";
      }
      else
      {
         cout << str << " is not a palindrome\n";
      }    

   }

   return 0;
}

//***************************************************************
//                   isPalindrome                               *
// This function tests a portion of a string between two        *
// indices to see if it is a palindrome.                        *
//***************************************************************/
bool isPalindrome(string str, int lower, int upper)
{
   if (lower >= upper) return true;
   if (str[lower] != str[upper]) return false;

   return isPalindrome(str, lower + 1, upper - 1);
}


