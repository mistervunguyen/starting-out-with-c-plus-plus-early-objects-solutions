// Chapter 5 - Programming Challenge 24, Sales Bar Chart
// This program creates a bar chart to display daily store sales. 
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int store1,      // Sales (in dollars) for each of 3 stores
	    store2,
	    store3,
		star;        // Loop control variable to print stars

	// Input and validate sales figures
	do
	{	cout << "Enter today's sales for store 1: ";
		cin  >> store1;
		cout << "Enter today's sales for store 2: ";
		cin  >> store2;
		cout << "Enter today's sales for store 3: ";
		cin  >> store3;

		if ((store1 < 0) || (store2 < 0) || (store3 < 0))
			cout << "Sales amounts cannot be less than 0. Please re-enter.\n\n";
	} while ((store1 < 0) || (store2 < 0) || (store3 < 0));
   	
	// Print the bar chart
	cout << endl
		 << "    DAILY SALES\n"
		 << "  (each * = $100)\n";

	cout << "\nStore 1: ";
	for (star = 1; star <= store1/100; star++)
		cout << '*';
	
	cout << "\nStore 2: ";
	for (star = 1; star <= store2/100; star++)
		cout << '*';
	
	cout << "\nStore 3: ";
	for (star = 1; star <= store3/100; star++)
		cout << '*';
	
   cout << endl;
	return 0;
}
