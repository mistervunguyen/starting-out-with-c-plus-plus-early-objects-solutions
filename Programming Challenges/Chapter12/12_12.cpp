//  Chapter 12--  Assignment 12:  Check Writer
// This program can convert a dollar and cents amount given in 
// numerical form to a word description of the amount.
#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>
#include <stdio.h>
#include <cstdlib>
#include <cmath>
using namespace std;

// Assume a maximum amount of $10,000
const char onesWords[10][6] = {
   "",
    "One",
   "Two",
   "Three",
   "Four",
   "Five",
   "Six",
   "Seven",
   "Eight",
   "Nine" };

const char teensWords[20][10] = { "","","","","","","","","","",
    "Ten",
   "Eleven",
   "Twelve",
   "Thirteen",
   "Fourteen",
   "Fifteen",
   "Sixteen",
   "Seventeen",
   "Eighteen",
   "Nineteen" };

const char tensWords[10][8] = {
    "",
   "Ten",
   "Twenty",
   "Thirty",
   "Forty",
   "Fifty",
   "Sixty",
   "Seventy",
   "Eighty",
   "Ninety" };

// Function Prototypes
void englishNum(double, char[]);

int main()
{
  
   double value;
   char wordString[81];
   string date, payee;

   cout << "\nEnter the date: ";
   getline(cin, date);
      
   cout << "\nEnter the payee: ";
   getline(cin, payee);
   cout << "\nEnter the amount: ";
   cin >> value;
   if (value < 0 || value > 10000)
     {
        cout << "Invalid amount: amount cannot be negative or over 10000.";
        exit(0);
     }
   cout << fixed << showpoint;
   cout << setprecision(2);
   // Display date
   cout << setw(60) << right;
   cout << "Date: " << date << endl;
   cout << "Pay to the order of:  " << payee << "\t\t\t";
   cout << "$" << value << endl;
   englishNum(value, wordString);
   cout << wordString << endl;
   return 0;
}

//*********************************************************************
//                 englishNum                                         *
// The following function reads the number in num and builds          *
// An english word version of the number, which is stored in str.     *
//*********************************************************************
void englishNum(double num, char str[])
{
   int ks, huns, tens, teens, ones, cents;
   char fracString[10];

   // Determine the number of cents
   cents = int(round (num * 100)) % 100;

   // Determine the word description for the integer part
   *str = 0;
   if (num == 10000)
    {
       strcpy(str, "Ten Thousand and 0 cents");
       return;
    }

    // How many thousands are there?
    ks = int(num / 1000);
    if (ks > 0)
    {
        strcat(str, onesWords[ks]);
        strcat(str, " thousand ");
        num -= (ks * 1000);
    }

    // How many hundreds are there?
    huns = int(num / 100);
    if (huns > 0)
    {
        strcat(str, onesWords[huns]);
        strcat(str, " hundred ");
        num -= (huns * 100);
    }

    // How many tens are there?
    tens = int(num / 10);
    if (tens > 1)
    {
         strcat(str, tensWords[tens]);
         strcat(str, " ");
         num -= (tens * 10);
         ones = int(num);
         if (ones > 0)
         {
            strcat(str, onesWords[ones]);
            num -= ones;
         }
    }
    else if (tens == 1)
    {
      teens = int(num);
      strcat(str, teensWords[teens]);
      num -= int(num);
    }
    strcat(str, " and ");    
    // The following is commented out because it is a nonstandard
    // function that is not supported by some compilers. 
    // An equivalent call is sprintf(fracString, "%d", cents);
    // itoa(cents, fracString, 10);
    sprintf(fracString, "%d", cents);
    strcat(str, fracString);
    strcat(str, " cents");
}

