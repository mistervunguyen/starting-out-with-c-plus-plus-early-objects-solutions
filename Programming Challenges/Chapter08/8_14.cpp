// Chapter 8 - Programming Challenge 14, Character Converter Class
// This program creates and uses a CharConverter class 
// to perform operations on strings. 
#include <iostream>
#include <string>
using namespace std;

class CharConverter
{
  public:
    void uppercase(string &);
    void properWords(string &); 
};

// CharConverter Function Implementation Section

/*****************************************************
 *           CharConverter::uppercase                *
 * Uppercases the string passed into its reference   *
 * parameter by utilizing ASCII character codes to   *
 * uppercase each individual character in the string *
 * one by one.                                       *
 *****************************************************/
void CharConverter::uppercase(string &s)
{
	for (unsigned pos = 0; pos < s.length(); pos++)
	{	
		if (s[pos] >= 'a' && s[pos] <= 'z')   // If letter is lowercase, replace
			s[pos] -= 32;                     // it with its uppercase equivalent
	}
}

/*****************************************************
 *    Alternate CharConverter::uppercase function    *
 * If the instructor wishes to allow students to use *
 * the toupper function, this uppercase function can *
 * be used in place of the one defined above.        *
 ***************************************************** 
void CharConverter::uppercase (string& s)
{
	for (int pos = 0; pos < s.length(); pos++)
		s[pos] = toupper(s[pos]);
}
*/

/**********************************************************
 *              CharConverter::properWords                *
 * Uppercases the first letter of each "word" in the      *
 * string passed into its reference parameter.            *
 **********************************************************/
void CharConverter::properWords(string &s)
{
	// If the string is "empty", return
	if (s.length() == 0) 
		return;

	// If the first character is a lowercase character,
	// make it uppercase.
	if (s[0] >= 'a' && s[0] <= 'z')
		s[0] -=32;

	// Check each additional character in the string. If it
	// is the first character in a new word (i.e. was preceded
	// by a blank) and is a lower case letter, uppercase it.
	for (unsigned pos = 1; pos < s.length(); pos++)
	{
		if (s[pos-1] == ' ' && s[pos] >= 'a' && s[pos] <= 'z')
		{
			s[pos] -=32;
		}
	}
}

/*****************************************************
 *   Alternate CharConverter::properWords function   *
 * If the instructor wishes to allow students to use *
 * the toupper function, this properWords function   *
 * can be used in place of the one defined above.    *
 *****************************************************
void CharConverter::properWords(string& s)
{
	// If the string is "empty", return
	if (s.length() == 0) 
		return;

	// Uppercase the first character
	s[0] = toupper(s[0]);

	// Uppercase first letter of the "word" following any blank
	for (int pos = 1; pos < s.length(); pos++)
	{
		if (s[pos-1] == ' ')
			s[pos] = toupper(s[pos]);
	}
}
*/

//******************* Client Code to test the class ***************

int main()
{
	string inputString,                   // User input string to be "translated"
	       clearBuffer;                   // Dummy string used to hold buffer "garbage"
	char answer;
	CharConverter makeString;             // Create a CharConverter object

	do
	{	// Prompt user to enter a sentence
		cout << "\nEnter a sentence in all lowercase letters. \n";
		getline(cin, inputString);
		
		// Use class functions to manipulate the string 
		makeString.properWords(inputString);
		cout << "\nYour sentence with first letters uppercased is: " << inputString;
		
		makeString.uppercase(inputString);
		cout << "\nYour sentence with *ALL* letters uppercased is: " << inputString << endl;
		
		cout << "\nDo another sentence (y/n)? ";
		cin.get(answer);                 // Accept one input character
		getline(cin, clearBuffer);       // Flush the input buffer of any additional characters
	} while (answer == 'y' || answer == 'Y');
 
	return 0;
 }

/* SAMPLE RUN RESULTS

Enter a sentence in all lowercase letters.
how are you today?

Your sentence with first letters uppercased is: How Are You Today?
Your sentence with *ALL* letters uppercased is: HOW ARE YOU TODAY?

Do another sentence (y/n)? n
*/
