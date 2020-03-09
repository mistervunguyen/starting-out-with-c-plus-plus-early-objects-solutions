// Chapter 3 - Programming Challenge 10, Box Office 
// This program calculates a theater's gross and net profit.
#include <iostream>
#include <iomanip>
#include <string>                        // Needed by most compilers to use strings
using namespace std;

int main()
{
	const double THEATER_PCT =     .80,   // Percent of gross kept by theater
		         DISTRIBUTOR_PCT = .20,   // Percent of gross paid to distributor
		         ADULT_PRICE = 10.00,     // Price of an adult ticket
				 CHILD_PRICE = 6.00;      // Price of a child ticket

	string movieName;                     // Name of the movie

	double grossRevenue,                  // Total ticket sales amount
		   netRevenue,                    // Theater's net revenue
		   distributorAmt;                // Amount paid to distributor

	int	adultTickets,                     // Number of adult tickets sold
		childTickets;                     // Number of child tickets sold
	
	// Get input from user
	cout << "Name of the movie: ";
	getline(cin, movieName);

	cout << "Number of adult tickets sold: ";
	cin  >> adultTickets;

	cout << "Number of child tickets sold: ";
	cin  >> childTickets;
   
	// Calculate gross and net profits and distributor payment
	grossRevenue = (adultTickets * ADULT_PRICE) + (childTickets * CHILD_PRICE);
	netRevenue = THEATER_PCT * grossRevenue;
	distributorAmt = DISTRIBUTOR_PCT * grossRevenue;

	// Display results
	cout << "\nRevenue Report\n\n";
	cout << "Movie Name:                    " << "\"" << movieName << "\"" << endl;
	cout << "Adult Tickets Sold:            " << setw(4) << adultTickets << endl;
	cout << "Child Tickets Sold:            " << setw(4) << childTickets << endl;
	cout << fixed << setprecision(2);
	cout << "Gross Box Office Revenue:       $" << setw(8) << grossRevenue << endl;
	cout << "Amount Paid to Distributor:   - $" << setw(8) << distributorAmt << endl;
	cout << "Net Box Office Revenue:         $" << setw(8) << netRevenue << endl;
	
	return 0;
}

