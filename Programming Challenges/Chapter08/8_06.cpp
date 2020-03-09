// Chapter 8 - Programming Challenge 6, Rain or Shine
// This program creates a weather report for the 3 summer months, using data 
// read from the RainOrShine.dat file which is located in the Chapter 8 Programs
// folder, and for faculty is also in the same folder as this solution file. A 
// copy of the data file should be placed in the program's project directory. 
// To simplify the program, there are 30 days of data for each month. 
#include<iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

const int NUM_MONTHS = 3,
          DAYS_IN_MONTH = 30;
		  
const string name[NUM_MONTHS] = {"June", "July", "August"};
		  
// Function prototypes
void readFileData(char[][DAYS_IN_MONTH]);
int  countDays(char[][DAYS_IN_MONTH], int, char);

int main()
{
	char dayType[NUM_MONTHS][DAYS_IN_MONTH];

	int rainy,                  // Counts number of days of each type
		cloudy,                 // during one particular month
		sunny,
		rainyTotal = 0,         // Counts number of days of each type
		cloudyTotal = 0,        // during 3-month period
		sunnyTotal = 0,
		wettestMonth,           // Index of rainiest month
		wettestMonthsRain = -1; // Number of rainy days in rainiest month

	// Call function to read in the weather data and store it in the array
	readFileData(dayType);

	// Print report heading
	cout << "    Summer Weather Report\n\n"
		 << "Month    Rainy  Cloudy  Sunny\n"
		 << "_____________________________\n";

	// Accumulate and display weather statistics 
	for (int month = 0; month < NUM_MONTHS; month++)
	{
		// Call a function to accumulate weather stats for current month 
		for (int day = 0; day < DAYS_IN_MONTH; day ++)
		{
			rainy  = countDays(dayType, month, 'R');
			cloudy = countDays(dayType, month, 'C');
			sunny =  countDays(dayType, month, 'S');
		}
		// Add monthly totals to grand totals
		rainyTotal  += rainy;
		cloudyTotal += cloudy;
		sunnyTotal  += sunny;

		// Determine if this month is the rainiest so far
		if (rainy > wettestMonthsRain)
		{
			wettestMonthsRain = rainy;
			wettestMonth = month;
		}
		// Display this month's results 
		cout << left    << setw(6) << name[month]
		     << right   << setw(6) << rainy << setw(8) << cloudy
			 << setw(7) << sunny << endl;
	}
	// Display summary data
	cout << "_____________________________\n";
	cout << "Totals" << setw(6) << rainyTotal << setw(8) 
		 << cloudyTotal << setw(7) << sunnyTotal << endl << endl;
	cout << "The month with the most rainy days was " 
		 << name[wettestMonth] << ".\n";

	return 0;
}

/************************************************************
 *                    readFileData                          *
 * This function fills the 2D array passed to it with data  *
 * from a file.                                             *
 ************************************************************/
void readFileData(char dayType[][DAYS_IN_MONTH])
{
	ifstream weatherData;
	
	//Open data file
	weatherData.open("RainOrShine.dat");
	if (!weatherData)
	{
		cout << "Error opening data file.\n";
		exit(EXIT_FAILURE);  // Exit program with an error code
	}

	// Else, if file was opened correctly, read weather data into the array
	for (int month = 0; month < NUM_MONTHS; month++)
	{
		for (int day = 0; day < DAYS_IN_MONTH; day ++)
			weatherData >> dayType[month][day];
	}
	// Close the data file
	weatherData.close();
}

/************************************************************
*                        countDays                          *
* This function receives the dayType array, a month number, *
* and a weatherType character. It counts and returns the    *
* number of days in the month with that type of weather.    *                                        *
*************************************************************/
int countDays(char array [][DAYS_IN_MONTH], int mo, char symbol)
{
	int count = 0;

	for (int day = 0; day < DAYS_IN_MONTH; day++)
	{
		if (array[mo][day] == symbol)
			count++;
	}
	return count;
}

/* CORRECT RESULTS USING THE RainOrShine.dat DATA FILE

    Summer Weather Report

Month    Rainy  Cloudy  Sunny
_____________________________
June       9       9     12
July       2      10     18
August     2       8     20
_____________________________
Totals    13      27     50

The month with the most rainy days was June.

*/

