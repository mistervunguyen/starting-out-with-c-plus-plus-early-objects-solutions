// Chapter 11 - Assignment 5, Palindrome Testing
// This program uses a class derived from string to 
// to test a strings to see if they are palindromes.

#include <iostream>
#include <string>
using namespace std;

// This class represents a string that
// Is can be tested to see if it is a palindrome
class PString : public string
{
  public:
    bool isPalindrome();   
  PString(string s) : string(s)
  {
  }
};

//****************************************************
//             PString.isPalindrome                  *
// Determines whether this string is a  palindrome.  *
//****************************************************
bool PString::isPalindrome()
{
    int lower = 0;           // Start at beginning of string
    int upper = length()-1;  // Start at end of string
    while (lower < upper)
    {
        if ((*this)[lower] != (*this)[upper])
        {
            // Found a mismatch
            return false;
        }
        lower++; upper--;
    }
    // No mismatch found, so is palindrome
    return true;    
}
 
int main ()
{
  // Request input from user
  string str;
  cout << "This is a palindrome-testing program. Enter a string to test:\n";
  cin >> str;

  // Create a PString object that will check strings
  PString s(str);

  // Check string and print output
  if (s.isPalindrome())
      cout << s << " is a palindrome";
  else
      cout << s << " is not a palindrome";
  return 0;
}