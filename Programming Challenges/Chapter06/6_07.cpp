// Chapter 6 - Programming Challenge 7, String Compare
// This program determines whether or not two user entered
// names are the same, ignoring case. It uses two functions,
// one to uppercase each string, and one to compare them.
#include <iostream>
#include <string>	
#include <cctype>
using namespace std;

// Function prototypes
string upperCaseIt(string);
bool sameString(string, string);

void findLowest(int, int, int, int, int);

int main()
{
	string name1, name2;  // The two names to be compared

	cout << "This program will determine if two names "
	     << "you enter are the same, ignoring case. \n";
		 
    cout << "Please enter name 1: ";
	getline(cin, name1);
	cout << "Please enter name 2: ";
	getline(cin, name2);
	
	name1 = upperCaseIt(name1);
	name2 = upperCaseIt(name2);
	
	if(sameString (name1, name2))
		cout << "\nThe two names are the same. \n";
	else
		cout << "\nThe two names are not the same. \n";
	
	return 0;
}// end of main function


/***************************************************
 *                      upperCaseIt                *
 * This function returns an all uppercase version  *
 * of the string passed to it.                     *
 ***************************************************/
string upperCaseIt(string s)
{
	for (int pos = 0; pos < s.length(); pos++)
		s[pos] = toupper(s[pos]);

	return s;
}// end of function upperCaseIt


/****************************************************************
 *                         sameString                           *
 * This boolean function returns true if the two strings passed *
 * to ita re the same, and returns false if they are not.       *
 ****************************************************************/
bool sameString(string s1, string s2)
{
	return (s1 == s2);
   
}// end of function sameString 

/* SAMPLE RUN RESULTS

This program will determine if two names you enter are the same, ignoring case.

Please enter name 1: Jack Smith
Please enter name 2: JACK SMITH

The two names are the same.
*/
