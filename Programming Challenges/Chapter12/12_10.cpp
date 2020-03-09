// Chapter 12 - Assignment 10, Password Verifier
// This program checks input strings to see if they qualify
// for consideration as secure passowords.
// A secure password be at least 6 characters long,
// and contain letters, digits, and both lowercase and uppercase 
// letters.

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Prototypes
bool isLongEnough(string s);
bool hasDigit(string s);
bool hasUpperAndLowerCase(string s);

const int LENGTH = 6;  // Minimum length for a safe password

int main()
{
  // Explain program to user and request a password
  cout << "This program checks passwords to see if they are secure.";
  cout << "\nEnter a password to check: ";

  // Read user's input
  string password;
  cin >> password;

  // Check the password
  if (!isLongEnough(password))
  {
      cout << "Password must be at least six characters long.";
      exit(0);
  }
  if (!hasDigit(password))
  {
      cout << "Password must have at least one digit.";
      exit(0);
  }
  if (!hasUpperAndLowerCase(password))
  {
     cout << "Password must have both lower case and upper case letters.";
     exit(0);
  }
  cout << "The password " << password << " is OK.";
  return 0;    
}

//****************************************************
//               isLongEnough                        *
// Check is string has a minimum length.             *
//****************************************************
bool isLongEnough(string s)
{
   return s.length() >= LENGTH;
}

//****************************************************
//             hasDigit                              *
// Check if string has at least one digit.           *
//****************************************************

bool hasDigit(string s)
{
    for (int k = 0; k < s.length(); k++)
    {
       if (isdigit(s[k])) return true;
    }
    return false;
}

//**************************************************************
//               hasUppperAndLowerCase                         *
// Check if a string has at least one upper case and at least  * 
// One lower case letter.                                      *
//**************************************************************
bool hasUpperAndLowerCase(string s)
{
   bool hasUpperCase = false;
   bool hasLowerCase = false;
   for (int k = 0; k < s.length(); k++)
   {
       hasUpperCase = hasUpperCase || isupper(s[k]);
       hasLowerCase = hasLowerCase || islower(s[k]);
       if (hasUpperCase && hasLowerCase) return true;        
   }
   return false;
}
