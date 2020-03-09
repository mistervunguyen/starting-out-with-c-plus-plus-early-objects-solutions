// Chapter 5 - Programming Challenge 6, Ocean Levels
// The program uses a for loop to display a table of projected 
// cumulative ocean level increases for each year over the next
// 25 years. Students may choose to use a different type of loop.
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	const double RISE_PER_YR = 3.1;  // Predicted annual rise in ocean level (in mm)

	// Display table heading
	cout << "         Predicted  \n"
	     << "         Cumulative \n"
		 << "  Year   Ocean Rise \n"
		 << "------------------- \n";

	// Create and display the table
	cout << fixed << setprecision(1);
	for (int year = 1; year <= 25; year++)
		cout << setw(5) << year << setw(9) << year * RISE_PER_YR << " mm \n";

	return 0;
}

/* CORRECT RESULTS

         Predicted
         Cumulative
  Year   Ocean Rise
-------------------
    1      3.1 mm
    2      6.2 mm
    3      9.3 mm
    4     12.4 mm
    5     15.5 mm
    6     18.6 mm
    7     21.7 mm
    8     24.8 mm
    9     27.9 mm
   10     31.0 mm
   11     34.1 mm
   12     37.2 mm
   13     40.3 mm
   14     43.4 mm
   15     46.5 mm
   16     49.6 mm
   17     52.7 mm
   18     55.8 mm
   19     58.9 mm
   20     62.0 mm
   21     65.1 mm
   22     68.2 mm
   23     71.3 mm
   24     74.4 mm
   25     77.5 mm
*/
