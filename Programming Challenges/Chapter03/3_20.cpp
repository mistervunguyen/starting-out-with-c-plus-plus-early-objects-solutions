/* Chapter 3 - Programming Challenge 20, Interest Earned 
   This program calculates the interest earned on money in a savings
   account based on the annual interest rate, time in the account, and
   the number of times compounded annually. Note: answers may vary by 
   a penny from that shown in the text, due to roundoff error.
*/
#include <iostream>
#include <iomanip>
#include <cmath>                 // Needed for the pow function
using namespace std;

int main()
{
	double interestRate,         // Annual interest rate paid by the institution
		   interestAsPct,        // Interest depicted with a %
		   principal,            // Amount of money initially deposited
		   interestEarned,       // Amount earned over the period 
		   finalBalance;         // Total amount in account at end of the period

	int	timesCompounded;         // Number of times the interest is compounded		

	// Get input from user
	cout << "Starting account balance: $";
	cin  >> principal;

	cout << "Annual account interest rate in the format "
	     << ".05 (for 5%): ";
	cin  >> interestRate;

	cout << "Number of times the interest is compounded annually: ";
	cin  >> timesCompounded;

	// Calculate interest earned and amount in account at end of one year
	finalBalance = principal * 
                   pow((1+(interestRate/timesCompounded)),timesCompounded); 
	interestEarned = finalBalance - principal;
	interestAsPct = interestRate * 100;
	
	// Display results
	cout << "\n - - Earnings Report - -\n\n";
	cout << fixed << showpoint << setprecision(2);
	cout << "Interest Rate:       " << setw(8) << interestAsPct << "%\n";
	cout << "Times Compounded     " << setw(8) << timesCompounded << endl;
	cout << "Principal:          $" << setw(8) << principal << endl;
	cout << "Interest:           $" << setw(8) << interestEarned << endl;
	cout << "Final Balance:      $" << setw(8) << finalBalance <<  endl;

	return 0;
}
