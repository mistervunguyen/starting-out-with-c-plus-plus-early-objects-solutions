// Chapter 6 - Programming Challenge 6, Shipping Charges
// Given the weight of a package and the distance it is to be shipped,
// this program uses a function to determine the shipping charge. The main
// function contains a sentinel-controlled loop that allows multiple 
// packages to be handled. 
#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
double calculateCharge(double, int); 

const double    // Rates per 500 miles shipped
RATE1 = 3.10,   // For pkgs weighing <= 2 kg    
RATE2 = 4.20,   // For pkgs > 2 kg but <= 6 kg
RATE3 = 5.30,   // For pkgs > 6 kg but <= 10 kg
RATE4 = 6.40;   // For pkgs > 10 kg

int main()
{
	double weight,
		   cost;
	int miles;

	cout << fixed << showpoint << setprecision(2);

	cout << "   Fast Freight Shipping Company \n"
		 << "Package Shipping Charges Calculator\n\n";

	cout << "Enter Package weight in kg (or 0 to exit): ";
	cin  >> weight;

	while (weight > 0)
	{
		cout << "Enter shipping distance in miles: ";
		cin  >> miles;

		cost = calculateCharge(weight, miles);
		cout << "\nShipping cost: $" << cost << endl << endl;

		cout << "Enter Package weight in kg (or 0 to exit): ";
		cin  >> weight;
	}
	return 0;
}// end of main function

/******************************************************
 *                    calculateCharge                 *
 * This function is passed a package weight (kg) and  * 
 * a shipping distance (mi). It uses these to compute *
 * and return the shipping charge.                    *
 ******************************************************/
double calculateCharge(double wt, int mi)
{
	double RatePer500 = 0,    // Rate per 500 mi. shipped
		shippingCharge;
	
	if (wt <= 2.0)
		RatePer500 = RATE1;
	else if (wt <= 6.0)
		RatePer500 = RATE2;
	else if (wt <= 10.0)
		RatePer500 = RATE3;
	else
		RatePer500 = RATE4;

	shippingCharge = RatePer500 * (mi / 500.0);
	return shippingCharge;

}// end of calculateCharge function 

/* SAMPLE RUN RESULTS

Fast Freight Shipping Company
Package Shipping Charges Calculator

Enter Package weight in kg (or 0 to exit): 3.5
Enter shipping distance in miles: 1000

Shipping cost: $8.40

Enter Package weight in kg (or 0 to exit): 7.2
Enter shipping distance in miles: 1200

Shipping cost: $12.72

Enter Package weight in kg (or 0 to exit): 0
*/