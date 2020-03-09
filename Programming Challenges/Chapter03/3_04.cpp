// Chapter 3 - Programming Challenge 4, How Much Insurance? 
// This program calculates the minimum amount of insurance
// owners should carry on their home or building. 
// It uses a named constant.
#include <iostream>
using namespace std;

int main()
{   
   const double INSURANCE_PCT = .80;  // Min. % of building replacement cost
                                      // insurance should cover
   double replacementCost;            // Cost to replace the building
   
   // Get replacement cost of the building from the user
   cout << "This program will compute the minimum amount of \n"
        << "insurance you should carry on your home or building.\n\n";
        
   cout << "Enter the replacement cost of this structure: $";
   cin  >> replacementCost;
   
   // Compute and display the recommended minimum insurance amount
   cout << "You should insure this structure for at least $" 
        << INSURANCE_PCT * replacementCost << endl;
    
   return 0;
}

/* SAMPLE RUN RESULTS

This program will compute the minimum amount of
insurance you should carry on your home or building.

Enter the replacement cost of this structure: $180000
You should insure this structure for at least $144000
*/
