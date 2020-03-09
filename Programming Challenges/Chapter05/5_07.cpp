// Chapter 5 - Programming Challenge 7, Circle Areas
// The program uses a for loop to display a table of circle areas.
// The area quadruples each time the radius doubles. 
// Students may choose to use a different type of loop.
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	const double PI = 3.14;

	// Display table heading
	cout << "   Circles     \n"
	     << "Radius   Area  \n"
		 << "-------------- \n";

	// Create and display the table
	cout << fixed << setprecision(1);
	for (int radius = 1; radius <= 8; radius*=2)
		cout << setw(4) << radius << setw(9) << (PI*radius*radius) << endl;

	return 0;
}

/* CORRECT RESULTS

   Circles
Radius   Area
--------------
1      3.1
2     12.6
4     50.2
8    201.0
*/
