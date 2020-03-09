// Chapter 11-- Assignment 2, Day of the year.
// This program takes an integer representing a day of the 
// year and translates it to an description of the form
// month - day of month.

// Assumes all years have 365 days

#include <iostream>
#include <string>
using namespace std;

// This class encapsulates the strategy for solving the problem.
class DayOfYear
{
public:
   static const int daysAtEndOfMonth[ ];
   static const string monthName[ ];
   void print();
   void setDay(int day){this->day = day;}
private:
   int day;       
};

// These are self-explanatory, eh?
const int DayOfYear::daysAtEndOfMonth[ ] = {31, 59, 90, 120, 
                                       151, 181, 212, 243, 273,
                                       304, 334, 365};
const string DayOfYear::monthName[ ]= {"January", "February", "March",
                 "April", "May", "June", "July",
                 "August", "September", "October",
                 "November", "December"};


//***************************************
//          DayOfYear::print            *
// Convert and print day of year.       * 
//***************************************                                 
void DayOfYear::print()
{
    int month = 0;
    
    while (daysAtEndOfMonth[month] < day)
         month = (month + 1) %12;
    // DaysAtEndOfMonth >= day
    if (month == 0) 
      cout << "January " << day;
    else
      {
           cout << DayOfYear::monthName[month] <<  " " 
                << day - DayOfYear::daysAtEndOfMonth[month-1];
      }    
}

int main()
{
    // Tell user what program does
    cout << "This program converts a day given by a number 1 through 365" << 
            "\ninto a month and a day.";

    // Get user input			
    cout << "\nEnter a number: ";
    int day;
    cin >> day;
    if (day < 0 || day > 365)
    {
        cout << "Invalid range for a day.";
        exit(1);
    }

    // Do computation and print result
    DayOfYear dy;
    dy.setDay(day);
    dy.print();    
        
    return 0;
}
                                  


