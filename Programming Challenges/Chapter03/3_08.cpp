// Chapter 3 - Programming Challenge 8, Male and Female Percentages
//	This program calculates the percentage of men and women in a class.
#include <iostream>
#include <iomanip> 
using namespace std;

int main()
{
	int numMen,
		numWomen,
		totalStudents;

	double pctMen,
		   pctWomen;
	
	// Prompt the number of males and females in the class.
	cout << "Number of men in the class: ";
	cin  >> numMen;

	cout << "Number of women in the class: ";
	cin >> numWomen;

	totalStudents = numMen + numWomen;
	
	// Compute and display the percentage of each
	cout << fixed << showpoint << setprecision(2);
	cout << "\nClass Make Up by Gender \n";
	cout << "Men    " << 100*numMen/totalStudents   << "% \n";
	cout << "Women  " << 100*numWomen/totalStudents << "% \n";
	
	return 0;
}

/* SAMPLE RUN RESULTS

Number of men in the class: 15
Number of women in the class: 10

Class Make Up by Gender
Men    60%
Women  40%
*/
