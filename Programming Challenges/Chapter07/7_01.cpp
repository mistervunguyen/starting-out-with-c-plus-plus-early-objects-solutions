// Chapter 7 - Programming Challenge 1, Date
// This program implements and tests a Date class that 
// stores dates and displays them in various formats.
#include <iostream>
#include <string>
using namespace std;

class Date
{
  private:
	int month;        // Holds the month number
	int day;          // Holds the day 
	int year;         // Holds the 4 digit year
	string name;      // Holds the month name

	void setName();   // Private mutator sets month name

  public:
	// Constructors
	Date();
	Date(int, int, int);

	// Mutators that set member data values
	void setMonth(int m);
	void setDay(int d);
	void setYear(int y);

	// Accessors that use member data to display dates
	void showDate1();
	void showDate2();
	void showDate3();
};

/*********************************************************
 *                    Date::Date                         *
 * This default constructor sets date to Jan. 1, 2001.   *
 *********************************************************/
Date::Date()
{
	month = day = 1;   
	year  = 2001;
	setName();
}

/**************************************************************
 *                         Date::Date                         *
 * This overloaded constructor calls the class "set" function *
 * to set the date to the month/day/year passed to it.        *
 **************************************************************/
Date::Date(int m, int d, int y)
{
	setMonth(m);
	setDay(d);
	setYear(y);	
}

/***************************************************************
 *                       Date::setMonth                        *
 * This member function validates that the month number        *
 * passed in is 1-12 and, if so, sets the month to that number.*
 * Otherwise a default value of 1 is used.                     *
 ***************************************************************/
void Date::setMonth(int m)
{
	if (m >= 1 && m <= 12)
		month = m;
	else
	{	cout << m << " is not a valid value for the month.\n"
	              << "Using a default value of 1 (January). \n";
		month = 1;    
	}
	setName();
}

/********************************************************
 *                 Date::setDay                         *
 * This member function validates that the day number   *
 * passed in is valid for the selected month. If so,    *
 * it sets the day to that number. Otherwise, a default *
 * value of 1 is used.                                  *
 ********************************************************/
void Date::setDay(int d)
{
	int daysInMonth;
	
	switch (month)
	{
		case 4: case 6: case 9: case 11:  // Apr., June, Sept. & Nov.
			daysInMonth = 30;
		    break;
		case 2:                           // Feb.
			daysInMonth = 29;             // Usually 28, but 29 is the max
			break;
		default:
			daysInMonth = 31;             // The rest of the months
	}
										 
	if (d >= 1 && d <= daysInMonth)
		day = d;
	else
	{	cout << d << " is not a valid day in " << name <<". \n"
		          << "Using a default value of 1). \n";
		day = 1;      
	}
}

/***************************************************************
 *                        Date::setYear                        *
 * This member function validates that the year number passed  *
 * in is valid, if so, it sets the year to that number.        *
 * Otherwise, a default value of 2001 is used.                 *
 * NOTE: The programming specs did not specify which dates     *
 *       were valid.                                           *
 ***************************************************************/
void Date::setYear(int y)
{
	if (y >= 1900 && year <= 2020)
		year = y;
	else
	{
		cout << y << " is not a valid value for the year.\n"
		          << "Using a default value of 2001. \n";
		year = 2001;   // Use default value
   }
}

/*********************************************************
 *                     Date::setName                     *
 * This member function sets the month name to match the *
 * month number.                                         *
 *********************************************************/
void Date::setName()
{
	switch (month)
	{ 
		case  1: name = "January";  break;
		case  2: name = "Febraury"; break;
		case  3: name = "March";    break;
		case  4: name = "April";    break;
		case  5: name = "May";      break;
		case  6: name = "June";     break;
		case  7: name = "July";     break;
		case  8: name = "August";   break;
		case  9: name = "September";break;
		case 10: name = "October";  break;
		case 11: name = "November"; break;
		case 12: name = "December"; 
	}
}

/*************************************************************
 *                        Date::showDate1                    *
 * This member function displays the date in 3/15/13 format. *
 *************************************************************/
void Date::showDate1()
{
   int twoDigitYear;

   if (year >= 2000)
      twoDigitYear = year - 2000;
   else
      twoDigitYear = year - 1900;
   
	cout << month << '/' << day << '/' ;

	if (twoDigitYear < 10)
		cout << '0';
	cout << twoDigitYear << endl;
}

/********************************************************************
 *                          Date::showDate2                         *
 * This member function displays the date in March 15, 2013 format. *
 ********************************************************************/
void Date::showDate2()
{
	cout << name << " " << day << ", " << year << endl;
}

/********************************************************************
 *                          Date::showDate3                         *
 * This member function displays the date in 15 March 2013 format.  *
 ********************************************************************/
void Date::showDate3()
{
	cout << day << " " << name << " " << year << endl;
}

/********************************************************
 *                        main                          *
 * The program specs. asked students to demonstrate     *
 * the class by writing a program that uses it. Here is *
 * one possible such program. The student code for main *
 * may be different.                                    *
 ********************************************************/
int main()
{
	Date today;           // Create a date object using default constructor

	today.showDate2();    // Show the date set by the default constructor
	cout << endl;         // using format 2.

	today.setMonth(3);    // Call class functions to set the date
	today.setDay(15);
	today.setYear(2016);

	today.showDate1();    // Display date using format 1
	today.showDate2();    // Display date using format 2
	today.showDate3();    // Display date using format 3
	
	// Students may wish to add code to allow the user to  
	// enter a date and display it in their preferred format.
	return 0;
}

