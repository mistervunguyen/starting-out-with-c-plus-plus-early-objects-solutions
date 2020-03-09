// Chapter 5 - Programming Challenge 27, Using Files--Population Bar Chart
// This program creates a bar chart displaying a town's population growth over 
// each 20 year period between 1910 and 2010. Data to test the program is in the
// People.txt file located in the Chapter 5 Programs folder, and for faculty also
// in the same folder as this solution file. A copy of the data file should be 
// placed in the program's project directory. 

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	long population;     // Population of a town read in from a file
	ifstream dataIn;     // File stream variable

	// Open the file and check that it was found and correctly opened
	dataIn.open("people.txt");
	if (!dataIn)
	{
		cout << "Error finding and opening the file.\n";
		exit(1);
	}
	        
	// Print the bar chart heading
	cout << "PRAIRIEVILLE POPULATION GROWTH\n";
	cout << "(each * represents 1000 people)\n\n";

	// Read each decade's population from the file and 
	// display it with an appropriate bar chart line
	for (int year = 1910; year <= 2010; year += 20)
	{
		dataIn >> population;
		cout << year << "  ";

		for (int star = 1; star <= population /1000; star++)
			cout << '*';
		cout << endl;
	}
	// Close the file
	dataIn.close();
	return 0;
}

/* CORRECT RESULTS

PRAIRIEVILLE POPULATION GROWTH
(each * represents 1000 people)

1910  **
1930  ****
1950  *****
1970  *********
1990  **************
2010  ******************
*/
