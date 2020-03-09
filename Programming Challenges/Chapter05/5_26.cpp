// Chapter 5 - Programming Challenge 26, Using Files--Total and Average Rainfall
// This program reads in from a file two month names, followed by the rainfall
// amounts for each month in that span of months. These rain amounts are totaled
// and then an average for each month in the span of months is calculated. Because
// the program does not know how many months of rainfall data there is, it must
// read and process data values until the end of file is encountered. The data for
// this program can be found in the Rainfall.txt file located in the Chapter 5 
// Programs folder, and for faculty also in the same folder as this solution file.
// A copy of the data file should be placed in the program's project directory. 
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	string startMonth, endMonth;
	
	double rainAmt,
		   totalRain = 0.0;
			   
	int numRainValues = 0;
	
	ifstream dataIn;     // File stream variable
	
	// Open the file and check that it was found and correctly opened
	dataIn.open("Rainfall.txt");
	if (!dataIn)
	{
		cout << "Error finding and opening the data input file.\n";
		exit(1);
	}
		   
	// Read in the starting and ending month names
	dataIn >> startMonth;
	dataIn >> endMonth;
	
	// While there is a rain amount to be read in,
	// read it and add it to the total.
	while (dataIn >> rainAmt)  
    {
		totalRain += rainAmt;
		numRainValues++;
	}
	
	// Display the rainfall report
	cout << "During the months of " << startMonth << "-" << endMonth  << endl
 	     << "the total rainfall was " << totalRain << " inches and \n"
         << "the average monthly rainfall was " << totalRain/numRainValues
         << " inches. \n";		 
	
	// Close the data file.
	dataIn.close();
		
 	return 0;
}

/* CORRECT RESULTS

During the months of April-August
the total rainfall was 6.33 inches and
the average monthly rainfall was 1.266 inches.
*/