// Chapter 16 - Assignment 1, String Bound Exceptions
// This program creates a subclas of string that
// performs bounds-checking and throws an exception
// if an attempt is made to index outside the bounds of 
// string.
 
#include <iostream>
#include <string>

using namespace std;

class StrExcept { };   //String Out of Bounds Exception

// This is child of the string class that 
// performs bounds checking and throws an exception
class BCheckString : public string
{
  public: 
   // This convert  constructor just calls the base class
   // constructor using its constructor initialization list
   BCheckString(string  s) : string(s)
   {
   }
   // The overloaded [] operator throws an exception if
   // if its parameter is out bounds, otherwise it calls
   // operator [] in the string base class
   char operator[ ](int k)
   {
     if (k < 0 || k >= length())
       throw StrExcept();
     return string::operator[](k);  
   }
};

int main()
{
  //Explain program to user
  cout << "This program demonstrates bounds checking on string object.";

  //Get string from user and create boundCheck string object
  cout << "\nEnter a string: ";
  string str;
  getline(cin, str);
  BCheckString h(str);

  //Let user access characters at specified positions in the string
  try
  {
	 cout << "Legitimate string positions are: " << 0 << ".." << h.length() -1 << endl;
	 for (int k = 1; k <= 5; k++)
	 {
		 cout << "Enter an integer describing a position inside or outside the string: ";
		 int pos;
		 cin >> pos;
		 cout << "The character at position " << pos << " is " <<  h[pos] << endl;		 
	 }	
  }
  catch(StrExcept )
  {
     cout << "\nAccess violation in string." << endl; 
  }
  return 0;
}

