// Chapter 10 - Assignment 8, Days in Current Mondth
// This program determines the number of days in any given month, and also
// the number of days in the current month.
 
#include <iostream>
#include <string>
#include <ctime>
using namespace std;
// Mnemonic names for months of the year
enum MONTH {JAN, FEB, MARCH, APRIL, MAY,  JUNE, JULY, AUG, SEPT, OCT, NOV, DEC};
// Use arrays to associate each month with number of days and a string name
const int DAYS_IN_MONTH [] = {31,  28,  31,    30,    31,   30,   31,   31,  30,   31,  30,  31};
const string NAME_OF_MONTH [] = {"January", "February", "March", "April", "May", "June", "July", "August",
                                 "September", "October", "November", "December" };

// Prototypes
int numberOfDaysInMonth(int month, int year);
void getCurrentMonthAndYear(int &month, int &year);
bool isLeapYear(int year);

int main()
{
   //Let the user enter month, year data
   
   int month, year;   

   cout << "Enter month and year as prompted, and enter 0 0 to quit.\n";
   cin >> month >> year;
   while (month != 0)
   {   
	   month--;    // Values for month entered by user start at 1 instead of 0
	   // Input validation
	   if (month < 0 || month > 11)
	   {
           cout << "Incorrect value for month on input.";
		   return 1;
	   }
       // Compute and print output for this line of input
	   cout << numberOfDaysInMonth(month, year) << " days" << endl;
	   cout << "Enter month and year: ";
	   cin >> month >> year;
   }
   cout << endl;
   getCurrentMonthAndYear(month, year);
   cout << "The current month, " << NAME_OF_MONTH[month] << " " << year << "," 
	   << " has " << numberOfDaysInMonth(month, year) << " days." << endl; 

   return 0;  
}

/***********************************************************
 *                numberOfDaysInMonth                      *
 *   Determines the number of days in a given month of     *
 *   a given year.                                         *
 ***********************************************************/
int numberOfDaysInMonth(int month, int year)
{
   // Look up the standard number of days in the given month
   int numberOfDays = DAYS_IN_MONTH[month];
   // Adjust for leap year
   if (isLeapYear(year) && month == FEB)
	   numberOfDays ++;
   // Done
   return numberOfDays;
}

/*************************************************************
 *                 getCurrentMonthAndYear                    *
 *   Determines the current month and year and stores those  *
 *   values in two reference parameters                      *
 *************************************************************/
void getCurrentMonthAndYear(int &month, int &year)
{
   // Get current time in seconds since the epoch
   time_t epochSeconds = time(NULL);
   // Convert to local time stored in the structure *tm
   tm* tm_ptr =  localtime(&epochSeconds);
   // Get the current month and year from the structure *tm
   month = tm_ptr->tm_mon;
   year =  tm_ptr->tm_year + 1900;
}

/******************************************
 *       isLeapYear                       *
 ******************************************/
bool isLeapYear(int year)
{
   if (year % 100 == 0)
	   return year % 400 == 0;
   else
	   return year % 4 == 0;
}

