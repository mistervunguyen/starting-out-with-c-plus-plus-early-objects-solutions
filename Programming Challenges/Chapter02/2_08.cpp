// Chapter 2 - Programming Challenge 8, Land Calculation 
// This program calculates the number of square feet and 
// number of square meters in 1/2 acre of land.
#include <iostream>
using namespace std;

int main()
{
   // Define and initialize variables  
	double sqFtPerAcre = 43560.0;       // Number of sq. ft. per acre                  
	double sqFtPerSqMeter  = 10.7639;   // Number of sq. ft. per sq. meter             
	double halfAcre_sqFt;               // Number of sq. ft. in 1/2 acre
	double halfAcre_sqMeters;           // Number of sq. meters in 1/2 acre
	
	// Calculate number of sq. ft and sq. meters in 1/2 acre of land
	halfAcre_sqFt = sqFtPerAcre / 2; 
	halfAcre_sqMeters = halfAcre_sqFt / sqFtPerSqMeter;
	
	// Display the results
	cout << "A half acre of land contains " << halfAcre_sqFt << " sq. ft. and "
	     << halfAcre_sqMeters << " sq. meters. \n";

	return 0;
}

/* CORRECT RESULTS
A half acre of land contains 21780 sq. ft. and 2023.43 sq. meters.
*/