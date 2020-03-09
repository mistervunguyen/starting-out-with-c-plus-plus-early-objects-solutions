// Chapter 2 - Programming Challege 2, Sales Prediction 
// This program predicts East Coast Division sales based on total sales.
// Because students have not yet learned how to format output, the
// result will be in E notation. 
#include <iostream>
using namespace std;

int main()
{
	// Define and initialize variables
	double eastCoastSalesPct = .58,    // % sales from East coast
	       totalSales = 8600000.00,    // Total sales amount  
	       predictedSales;             // Predicted East coast sales
	
	// Calculate and display predicted East coast sales
	predictedSales = eastCoastSalesPct * totalSales;
	cout << "Predicted East Coast Sales = $" << predictedSales << endl;

	return 0;
 }

/* CORRECT RESULTS

Predicted East Coast Sales = $4.988e+006

*/