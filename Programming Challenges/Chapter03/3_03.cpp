// Chapter 3 - Programming Challenge 3, Housing Costs 
// This program calculates monthly and annual housing costs. 
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{   
   double rent,           // Monthly cost for rent or mortgage
	      utilities,      // Monthly cost for utilities
		  phones,         // Monthly cost for phones
          cable,          // Monthly cost for cable
          monthlyTotal,   // Total monthly housing costs
          annualTotal;    // Total annual housing costs
          
   // Get monthly costs 
   cout << "Enter your monthly costs for the following: \n\n";
   cout << "Rent or mortgage $";
   cin  >> rent;
   
   cout << "Utilities $";
   cin  >> utilities;
   
   cout << "Phone(s)  $";
   cin  >> phones;
   
   cout << "Cable     $";
   cin  >> cable;
   
   // Calculate total costs
   monthlyTotal = rent + utilities + phones + cable;
   annualTotal = monthlyTotal * 12;
   
   // Display results
   cout << fixed << setprecision(2);
   cout << "\nTotal monthly housing costs $" << setw(8) << monthlyTotal; 
   cout << "\nTotal annual  housing costs $" << setw(8) << annualTotal  << endl;
   
   return 0;
}

/* SAMPLE RUN OUTPUT

Enter your monthly costs for the following:

Rent or mortgage $1348
Utilities $215
Phone(s)  $99
Cable     $69

Total monthly housing costs $ 1731.00
Total annual  housing costs $20772.00
*/