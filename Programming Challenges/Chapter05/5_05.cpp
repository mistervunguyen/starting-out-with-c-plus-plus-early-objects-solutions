// Chapter 5 - Programming Challenge 5, Speed Conversion Chart
// This program uses a for loop to display a table from 40 kph 
// to 120 kph (in 10 kph increments) of kilometers-per-hour 
// speeds with their miles-per-hour equivalents. Students may
// choose to use a different type of loop.
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	const double KILO_TO_MILES = .6214;   // 1 kilometer = .6214 miles
   
	// Display table heading
	cout << "   KPH         MPH  \n";
	cout << "--------------------\n";

	// Create and display the table
	for (int kph = 40; kph <= 120; kph += 10)
		cout << setw(5) << kph << setw(12) 
		     << static_cast<int>(kph * KILO_TO_MILES) << endl;
   
	return 0;
}

/* CORRECT RESULTS

   KPH         MPH
--------------------
   40          24
   50          31
   60          37
   70          43
   80          49
   90          55
  100          62
  110          68
  120          74
*/
