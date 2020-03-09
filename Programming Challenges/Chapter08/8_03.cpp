// Chapter 8 - Programming Challenge 3, Roman Numeral Converter
// This program displays the roman numeral equivalent of a decimal
// number. The roman numerals are stored in an array.
#include<iostream>
#include <string>
#include <iomanip>
using namespace std;

//Function prototype
int getValidNum();

const int MAX_NUM = 20;

const string romanNums[] = {" ",  "I",  "II",  "III",  "IV",  "V",  "VI",  "VII",  "VIII",  "IX",  "X",
                                 "XI", "XII", "XIII", "XIV", "XV", "XVI", "XVII", "XVIII", "XIX", "XX" };
int main()
{
	int decNum;           // The user entered decimal number to be converted

	cout << "Decimal to Roman Numeral Converter \n";
	decNum = getValidNum();

	while (decNum != 0)    // While the end sentinel has not been entered, process the number
	{
		cout << "The roman numeral equivalent of " << decNum << " is " << romanNums[decNum] << "\n";

		decNum = getValidNum();
	}
	return 0;
}

/***************************************************
 *                   getValidNum                   *
 * Inputs, validates, and returns a valid integer. *
 ***************************************************/
 int getValidNum()
 {
	 int num;
	 cout << "\nEnter a decimal number 1-" << MAX_NUM << " (or 0 to quit): ";
	 cin  >> num;

	 while (num < 0 || num > 20)
	 {
		 cout << "That is not a valid number.\n"
			  << "\nEnter a decimal number 1-" << MAX_NUM << ": ";
		 cin  >> num;
	 }
	 return num;
 }

 /* SAMPLE RUN RESULTS
 
 Decimal to Roman Numeral Converter

 Enter a decimal number 1-20 (or 0 to quit): 6
The roman numeral equivalent of 6 is VI

Enter a decimal number 1-20 (or 0 to quit): 9
The roman numeral equivalent of 9 is IX

Enter a decimal number 1-20 (or 0 to quit): 17
The roman numeral equivalent of 17 is XVII

Enter a decimal number 1-20 (or 0 to quit): 20
The roman numeral equivalent of 20 is XX

Enter a decimal number 1-20 (or 0 to quit): 0
 */
