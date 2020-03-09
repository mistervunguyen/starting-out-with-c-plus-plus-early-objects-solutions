// Chapter 6 - Programming Challenge 20, Using Files--Travel Expenses
// This program creates a business travel expense report, which it
// writes to a file.
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

// Function prototypes	
int    daysSpent();
void   times(double &, double &);
bool   isValidTime(double);	
double airFare();
double carRental();
double vehicle();
void   parking(int, double&, double&);
void   taxi(int, double&, double&);
double registration();
void   hotel(int, double&, double&);
void   meals(int, double, double, double&, double&);
double getMealCost(string);
double min(double, double);

const double 
	/* Transportation allowances */
	MILAGE_ALLOWANCE = .58,         // Per mile driven
	MAX_DAILY_PKG_FEE = 12.00,
	MAX_DAILY_TAXI_FEE = 40.00,
	
	/* Hotel allowance */
	MAX_HOTEL_RATE = 90.00,         // Per night max
	
	/* Meal allowances */
	BRK_MAX =    18.00,
	LUNCH_MAX =  12.00,
	DINNER_MAX = 20.00;

int main()
{
	ofstream report;           // Create ofstream object that will point
	                           // to the output file for the expense report
	string name;
	double /*Expenses*/
		spentAir = 0.0,
		spentCarRental = 0.0,
		spentMilage = 0.0,
		spentParking = 0.0,
		allowedParking = 0.0,
		spentTaxis = 0.0,
		allowedTaxis = 0.0,
		spentRegistration = 0.0,
		spentHotels = 0.0,
		allowedHotels = 0.0,
		spentMeals = 0.0,
		allowedMeals = 0.0,
		spentTotal = 0.0,
		allowedTotal = 0.0,
		time1,                 // Departure time on first trip day
		time2;                 // Arrival home time on last day of trip
	int days;                  // Number of days spent on the trip

	// Open the report file
	report.open("Expense.rpt");

	// Write screen and report headings
	cout << "\tEmployee Expense report\n\n";
	cout << "\nEmployee name: ";       // Not required by program specs
	getline (cin, name);
	days = daysSpent();
	times(time1, time2);

	report << fixed << showpoint << setprecision(2);
	report << "\tEmployee Expense Report for " << name << endl << endl;
	report << "Total Days: " << days << endl;
	report << "Departure time: " << time1 << "     ";
	report << "Return time: " << time2    << endl << endl;
	report << "                  Spent      Allowed\n"
		   << "                  _____      _______\n\n";

	// Call functions to calculate specific expenses
	spentAir = airFare();
	spentCarRental = carRental();
	spentMilage = vehicle();
	parking(days, spentParking, allowedParking);
	taxi(days, spentTaxis, allowedTaxis);
	spentRegistration = registration();

	if (days > 1)
		hotel(days, spentHotels, allowedHotels);

	meals(days, time1, time2, spentMeals, allowedMeals);

	spentTotal = spentAir + spentCarRental + spentMilage
		       + spentParking + spentTaxis + spentRegistration
			   + spentHotels + spentMeals;

	 allowedTotal = spentAir + spentCarRental + spentMilage 
		          + allowedParking + allowedTaxis + spentRegistration
				  + allowedHotels + allowedMeals;

	 // Write the report to the file
	 report << "Airfare        "  << setw(8) << spentAir << "     "
		                          << setw(8) << spentAir << endl;
	 report << "Car rental     "  << setw(8) << spentCarRental << "     "
                                  << setw(8) << spentCarRental << endl;
	 report << "Milage         "  << setw(8) << spentMilage << "     "
		                          << setw(8) << spentMilage << endl;
	 report << "Parking        "  << setw(8) << spentParking << "     "
                                  << setw(8) << allowedParking << endl;
	 report << "Taxis          "  << setw(8) << spentTaxis << "     "
                                  << setw(8) <<allowedTaxis << endl;
	 report << "Registration   "  << setw(8) << spentRegistration << "     "
                                  << setw(8) << spentRegistration << endl;
	 report << "Hotels         "  << setw(8) << spentHotels << "     "
                                  << setw(8) <<allowedHotels << endl;
	 report << "Meals          "  << setw(8) << spentMeals << "     "
                                  << setw(8) << allowedMeals << endl;
	 report << "               ________    __________\n";
	 report << "TOTALS         " << setw(8) << spentTotal << "     "
	                             << setw(8) << allowedTotal << endl;

	 report.close();
	 
	 // Display a message on the screen
	 cout << "\nThe expense report has been written to the Expense.rpt file.\n";
	 return 0;

}// end of main function

/***************************************************************
 *                        daysSpent                            *
 * Called by: main                                             *
 * This function inputs, validates, and returns the number     *
*  of days spent on trip.                                      *
 ***************************************************************/
int daysSpent()
{
	int days;

	cout << "How many days were spent on the trip? ";
	cin  >> days;
	while (days < 1)
	{
		cout << "Days must be one or more.  Please re-enter days: ";
		cin  >> days;
   } 
   return days;

}// end of function daysSpent

/*****************************************************************
 *                          times                                *
 * Called by: main                                               *
 * This function inputs departure and return times. Validated    *
 * times are stored in reference parameters start and end.       *
 *****************************************************************/
void times(double &start, double &end)
{
	cout << "Enter the departure time (using 24-hour HH.MM format): ";
	cin >> start;
	while (!isValidTime(start))
	{	cout << "Departure time must be between 0.00 and 23.59. "
	         << "Please re-enter: ";
		cin  >> start;
	}
	cout << "Enter the return time (using 24-hour HH.MM format): ";
	cin  >> end;
	while (!isValidTime(end))
	{	cout << "Return time must be between 0.00 and 23.59. "
	         << "Please re-enter: ";
		cin  >> end;
	}
}// end of function times

/****************************************************************
 *                      isValidTime                             *
 * Called by: times                                             *
 * Argument received: double time in the 24 hour format HH.MM   *
 * This function returns true/false based on whether or not the *
 * time passed to it is valid.                                  *
 ****************************************************************/
bool isValidTime(double t)
{
	if (t < 0.00 || t > 23.59 || t - static_cast<int>(t) > .59)
		return false;	
	else
		return true;

}// end of function isValidTime

/***************************************************************
 *                        airFare                              *
 * Called by: main                                             *
 * This function inputs, validates, and returns air fare.      *
 ***************************************************************/
double airFare()
{  
	double fare;

	cout << "Enter the amount of airfare: ";
	cin  >> fare;
	while (fare < 0)
	{	cout << "This expense must be 0 or greater. Please re-enter: ";
		cin  >> fare;
	}
	return fare;     

}// end of function airFare

/********************************************************************
 *                      carRental                                   *
 * Called by: main                                                  *
 * This function inputs, validates, and returns car rental expenses.*
 ********************************************************************/
double carRental()
{
	double rental;

	cout << "Enter the amount spent for car rental: ";
	cin  >> rental;
	while (rental < 0)
	{	cout << "This expense must be 0 or greater. Please re-enter: ";
		cin  >> rental;
	} 

	return rental; 

}// end of function carRental

/****************************************************************
 *                        vehicle                               *
 * Called by: main                                              *
 * This function inputs, validates, and returns private vehicle *
 * expenses.                                                    *
 ****************************************************************/
double vehicle()
{
	int   miles;
	    
	cout << "Enter the number of miles driven by private vehicle: ";
	cin >> miles;
	while (miles < 0)
	{
		cout << "Miles driven must be 0 or greater.  Please re-enter: ";
		cin  >> miles;
	}

	return miles * MILAGE_ALLOWANCE;

}// end of function vehicle

/***************************************************************
 *                        parking                              *
 * Called by: main                                             *
 * This function inputs, validates, and stores both spent and  *
 * allowed parking fees in reference parameters.               *
 ***************************************************************/
void parking(int days, double &spent, double &allowed)
{
	double maxAllowed = days * MAX_DAILY_PKG_FEE;

	cout << "Enter the amount of parking fees: ";
	cin  >> spent;
	while (spent < 0)
	{
		cout << "Parking fees must be 0 or greater.  Please re-enter: ";
		cin  >> spent;
	} 

	if (spent <= maxAllowed)
		allowed = spent;        // Entire amt. spent is allowed
	else
		allowed = maxAllowed;   // Only the max. amt. is allowed

}// end of function parking

/***************************************************************
 *                        taxi                                 *
 * Called by: main                                             *
 * This function inputs, validates, and stores both spent and  *
 * allowed taxi fees in reference parameters.                  *
 ***************************************************************/
void taxi(int days, double &spent, double &allowed)
{
	double maxAllowed = days * MAX_DAILY_TAXI_FEE;

	cout << "Enter the amount of taxi fees: ";
	cin  >> spent;
	while (spent < 0)
	{
		cout << "Taxi fees must be 0 or greater.  Please re-enter: ";
		cin  >> spent;
	} 

	if (spent <= maxAllowed)
		allowed = spent;        // Entire amt. spent is allowed
	else
		allowed = maxAllowed;   // Only the max. amt. is allowed

}// end of function taxi

/***************************************************************
 *                      registration                           *
 * Called by: main                                             *
 * This function inputs, validates, and returns conference     *
 * registration fees.                                          *
 ***************************************************************/
double registration()
{
	double reg;

	cout << "Enter the amount of conference registration: ";
	cin  >> reg;
	while (reg < 0)
	{
		cout << "This expense must be 0 or greater. Please re-enter: ";
		cin  >> reg;
	} 
	return reg;     

}// end of function registration

/***************************************************************
 *                        hotel                                *
 * Called by: main                                             *
 * This function inputs, validates, and stores both spent and  *
 * allowed hotel costs in reference parameters.                *
 * It assumes all nights were at the same rate.                *
 ***************************************************************/
void hotel(int days, double &spent, double &allowed)
{
	double maxAllowed = (days - 1) * MAX_HOTEL_RATE, // No hotel used on return day
	       rate;                                     // Actual nightly room rate

	cout << "Enter the nightly hotel rate: ";
	cin  >> rate;
	while(rate < 0)
	{	cout << "Room rate must be 0 or greater.  Please re-enter: ";
		cin  >> rate;
	} 
	spent = rate * (days - 1);

	if (spent <= maxAllowed)
		allowed = spent;        // Entire amt. spent is allowed
	else
		allowed = maxAllowed;   // Only the max. amt. is allowed

}// end of function hotel

/****************************************************************
 *                        meals                                 *
 * Called by: main                                              *
 * This function calculates total spent and total allowed meal  *
 * amounts by making a series of calls to the getMealCost       *
 * function. The amounts are stored in reference parameters.    *
 ****************************************************************/
void meals(int days, double depart, double arrive, 
                     double &totAmtSpent, double &totAmtAllowed)
{
	double brkCost = 0.0,           // Cone breakfast
		   lunchCost = 0.0,         // Cost of one lunch
		   dinnerCost = 0.0;        // Cost of one dinner

	// Handle special case of a 1 day trip 
	if (days == 1)
	{
		if (depart < 7.0 && arrive >= 8.0)
			brkCost = getMealCost("breakfast");

		if (depart < 12.0 && arrive >= 13.0)
			lunchCost = getMealCost("lunch");

     	if (depart < 18.0 && arrive >= 19.0)
			dinnerCost = getMealCost("dinner");

		totAmtSpent = brkCost + lunchCost + dinnerCost;
		totAmtAllowed = min(brkCost, BRK_MAX) + min(lunchCost, LUNCH_MAX)
                      + min(dinnerCost, DINNER_MAX);

		return;
	}
	// else normal case, days > 1

	// Get meal amounts allowed for day 1
  	cout << "Day 1:\n";
	if (depart < 7.0)	          // Depart before 7 a.m.?
  		brkCost = getMealCost("breakfast");

  	if (depart < 12.0)	       // Depart before noon?
		lunchCost = getMealCost("lunch");

	if (depart < 18.0)
      dinnerCost = getMealCost("dinner");

	totAmtSpent = brkCost + lunchCost + dinnerCost;
	totAmtAllowed = min(brkCost, BRK_MAX) + min(lunchCost, LUNCH_MAX)
                  + min(dinnerCost, DINNER_MAX);

	// Get meal amounts for days 2 thru the next-to-last day
	for (int count = 2; count < days; count++)
	{
		cout << "Day " << count << ":\n";
		brkCost = getMealCost("breakfast");
		lunchCost = getMealCost("lunch");
		dinnerCost = getMealCost("dinner");
		totAmtSpent += (brkCost + lunchCost + dinnerCost);
		totAmtAllowed += ( min(brkCost, BRK_MAX) + min(lunchCost, LUNCH_MAX)
                         + min(dinnerCost, DINNER_MAX) );
	}

	// Get meal amounts for last day of trip
	brkCost = lunchCost = dinnerCost = 0.0;
	cout << "Day " << days << ": \n";
	if (arrive < 8.0) 
		cout << "No meals allowed due to return before 8:00 a.m.\n";
	else
	{	brkCost = getMealCost("breakfast");

		if (arrive >= 13.0)	       // Arrive home 1 pm or later?
  			lunchCost += getMealCost("lunch");

		if (arrive >= 19.0)	       // Arrive home 7 pm or later?
  			dinnerCost += getMealCost("dinner");

		totAmtSpent += (brkCost + lunchCost + dinnerCost);
		totAmtAllowed += ( min(brkCost, BRK_MAX) + min(lunchCost, LUNCH_MAX)
                         + min(dinnerCost, DINNER_MAX) );
	}
}// end of function meals


/***************************************************************
 *                       getMealCost                           *
 * Called by: meals                                            *
 * This function gets, validates, and returns a meal cost.     *
 ***************************************************************/
double getMealCost(string mealName)
{
	double foodCost;
   
	cout << fixed << showpoint << setprecision(2);
	cout << "Enter the amount for " << mealName << ": ";
	cin  >> foodCost;
	while(foodCost < 0)
	{	cout << "Food cost must be 0 or greater.  Please re-enter: ";
		cin  >> foodCost;
	}
	return foodCost;

}// end of function getMealCost

/***************************************************************
 *                           min                               *
 * Called by: meals                                            *
 * This function returns the lesser of two amounts.            *
 ***************************************************************/
double min(double spent, double allowed)
{
	if (spent <= allowed)
		return spent;
	else
		return allowed;

}// end of function min

/* SAMPLE REPORT WRITTEN TO THE FILE WHEN THIS PROGRAM IS RUN

Employee Expense Report for Sam Spade

Total Days: 3
Departure time: 6.00     Return time: 19.30

                 Spent       Allowed
                 _____       _______

Airfare          572.00       572.00
Car rental       130.00       130.00
Milage             0.00         0.00
Parking           22.00        22.00
Taxis              0.00         0.00
Registration     100.00       100.00
Hotels           260.00       180.00
Meals             55.50        54.00
               ________    __________
TOTALS          1139.50      1058.00
*/