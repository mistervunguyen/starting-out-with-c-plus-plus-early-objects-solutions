// Chapter 3 - Programming Challenge 2, Stadium Seating 
// This program calculates revenue generated from ticket 
// sales when given the number of each ticket type sold.
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	const double A_PRICE = 15.00,    // Class A seat ticket price
		         B_PRICE = 12.00,    // Class B seat ticket price
				 C_PRICE =  9.00;    // Class C seat ticket price

	int	aSeats,                      // Number of class A seats sold
		bSeats,                      // Number of class B seats sold
		cSeats;                      // Number of class C seats sold

	double income;                   // Total income generated

	// Prompt user for quantity sold of each type of ticket
	cout << "Number of class A tickets sold:  ";
	cin  >> aSeats;
	cout << "Number of class B tickets sold:  ";
	cin  >> bSeats;
	cout << "Number of class C tickets sold:  ";
	cin  >> cSeats;

	// Calculate total income from sale of seats
	income = aSeats * A_PRICE + bSeats * B_PRICE + cSeats * C_PRICE;

	// Output the result
	cout << fixed << showpoint << setprecision(2);
	cout << "\nThe income from the sale of stadium seats is $" << income << endl;

	return 0;
}

/* SAMPLE RUN OUTPUT

Number of class A tickets sold:  210
Number of class B tickets sold:  325
Number of class C tickets sold:  62

The income from the sale of stadium seats is $7608.00
*/
