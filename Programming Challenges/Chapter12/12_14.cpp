// Chapter 12, Assignment 14, Dollar Amount Formatter
// This program demonstrates the use of the string find
// and insert member functions.
#include <iostream>
#include <string> 
#include <sstream>
#include <iomanip>
using namespace std;
//Prototypes
string dollarFormat(string );  
string dollarFormat(double );

int main(void)
{
 double input;    // User input

 // Get the dollar amount from the user.
 cout << "Enter a dollar amount in the form nnnnn.nn : ";
 cin >> input;

 // Display the formatted dollar amount.
 cout << "Formatted amount:   " <<  dollarFormat(input) << endl;
 return 0;
}
 
 //****************************************************
 // Returns a $-formatted version of the input string *
 //****************************************************
 string dollarFormat(string original)
 {
     string formatted = original;
     int dp = formatted.find('.');  // Position of decimal point
     int pos = dp;                  // Search for comma position
     while (pos > 3)
     {
        pos = pos - 3;
        formatted.insert(pos, ",");
     }
     formatted.insert(0, "$");
     return formatted;
 }


 //********************************************************
 // Returns a $-formatted version of double dollar amount *
 //********************************************************
 string dollarFormat(double amount)
 {
    // Convert the double to a string first and then fall back
    // on the other funtion.
    ostringstream ostr;
	ostr << fixed << setprecision(2);
	ostr << amount;
	return dollarFormat(ostr.str());     
 }
