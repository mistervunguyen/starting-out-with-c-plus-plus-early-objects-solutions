// Chapter 11-- Assignment 3, Day of the Year Modification.
// This program takes an integer representing a day of the 
// year and translates it to an description of the form
// month- day of month.

// Assumes all years have 365 days
 
#include <iostream>
#include <string>
using namespace std;

// This class represents a day of the year, given a month
// and a day in that month.
class DayOfYear
{
public:
   static const int daysAtEndOfMonth[ ];
   static const string monthName[ ];
   void print();     // Convert to month and day of month and print
   void printDayNumber( ) { cout << day; }
   void setDay(int day){this->day = day;}
   DayOfYear(string nameOfMonth, int dayOfMonth);
   DayOfYear() { };

   DayOfYear  operator++(int);
   DayOfYear  operator++( );
   DayOfYear  operator--(int);
   DayOfYear  operator--();
private:
   int day;       // day of the year
};

const int DayOfYear::daysAtEndOfMonth[ ] = {31, 59, 90, 120, 
                                            151, 181, 212, 243, 273,
                                            304, 334, 365};
const string DayOfYear::monthName[ ]= {"January", "February", "March",
                    "April", "May", "June", "July",
                    "August", "September", "October",
                    "November", "December"};                                 
                                  
                                  
//***************************************************************
//                   Constructor                                *
// The constructor converts the month and day of month          *
// into a canonical representation as the day of the year.      *
//***************************************************************								  
DayOfYear::DayOfYear(string nameOfMonth, int dayOfMonth)
{
    bool error = false;
    // Find month
    for (int m = 0; m < 12; m++)
    {
      if (nameOfMonth == monthName[m])
      {
        if (m  == 0)
        {            
            error = dayOfMonth < 0 || dayOfMonth >= 32 ;
            if (error) break;
            day = dayOfMonth;
        }
        else
        {
           error = dayOfMonth < 0 || 
                   dayOfMonth  > daysAtEndOfMonth[m]  - daysAtEndOfMonth[m-1];
           if (error) break;
           day = dayOfMonth + daysAtEndOfMonth[m-1];           
        }
        return;
      }
      // Try another month		
    }
    // Not a legit month
    cout << "Incorrect  name or day of month";
    exit(1);    
}

//**********************************
//         DayOfYear::print        *
// Convert and print day of year.  *
//**********************************								  
void DayOfYear::print()
{
    int month = 0;
    
    // Find the right month
    while (daysAtEndOfMonth[month] < day)
        month = (month + 1) %12;

    // DaysAtEndOfMonth[month] >= day, so the right month is month-1
    if (month == 0) 
      cout << "January " << day;
    else
      {
           cout << DayOfYear::monthName[month] <<  " " 
                << day - DayOfYear::daysAtEndOfMonth[month-1];
      }    
}

//*************************************
//            Postfix ++              *
//  Go forward one day in the year.   *
//*************************************
DayOfYear DayOfYear::operator++(int)
{
  DayOfYear temp = *this;
  day ++;
  if (day == 366) day = 1;
  return temp;
}

//*************************************
//          Postfix --                *
//  Back up one day in the year.      *
//*************************************
DayOfYear DayOfYear::operator--(int)
{
  DayOfYear temp = *this;
  day --;
  if (day == 0) day = 365;
  return temp;
}

//*************************************
//          Prefix ++                 *
//  Go forward one day in the year.   *
//*************************************
DayOfYear DayOfYear::operator++()
{
  day ++;
  if (day == 366) day = 1;
  return *this;
}

//*************************************
//          Prefix --                 *
// Back up one day in the year.       *
//*************************************
DayOfYear DayOfYear::operator--()
{
  day --;
  if (day == 0) day = 365;
  return *this;
}

int main()
{
    // Tell user what program does
    cout << "This program converts a Month and day of month into "
         << "A day of the year in the range 1..365";

    // Get user input			
    cout << "\nEnter month and day (Example: January 3):  ";
    string month;
    int day;
    cin >>  month >> day;
    
    // Do computation and print result
    DayOfYear dy(month, day);    
    dy.printDayNumber();
 
    --dy;
    cout << "\nThe day before is ";  dy.print();
    dy ++; dy ++;
    cout << "\nThe day after is "; dy.print();
                    
    return 0;
}                             


