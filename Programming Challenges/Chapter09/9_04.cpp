// Chapter 9 - Programming Challenge 4, Batting Averages
// This program creates a report of baseball players and their batting averages
// displayed from highest to lowest. The instructor should let students know 
// whether to use an array of structures or of objects to hold the data. This 
// solution uses structures.
#include<iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Player
{
	string  name;                          // Name of a player
	double  avg;                           // Batting average

	Player(string n ="", double a = 0.0)   // Constructor that uses default 
	{ name = n; avg = a;}                  // values if fewer than 2  
};                                         // arguments are passed to it

// Function prototypes
void getData(Player[]);
void sortData(Player[]);
void displayReport(const Player[]);

const int TEAM_SIZE = 12;

int main()
{                               
	Player team[TEAM_SIZE]; 

	// Call function to input data for each player
	getData (team);

	// Sort the structures by batting average
	sortData (team);

	// Display the data in the ordered structures
	displayReport (team);
	
	return 0;
}

/*****************************************************************
 *                       	   getData                           *
 * Called by: main()                                             *
 * Receives : the team array                                     *
 * Purpose  : Inputs and stores data for each player on the team.*
 *****************************************************************/
void getData(Player team[])
{
	string clearBuffer;

	for (int i = 0; i < TEAM_SIZE; i++)
	{
		cout << "\nEnter the name of player " << i + 1 << ": ";
		getline(cin, team[i].name);

		cout << "Enter this player's batting average in decimal form: ";
		cin >> team[i].avg;

		getline(cin, clearBuffer);   // Flush the input buffer
	}
}

/************************************************************
 *                         sortData                         *
 * Called by: main()                                        *
 * Receives : the team array                                * 
 * Purpose  : Sorts the array elements in descending order  *
 *            by the avg field.                             *
 ************************************************************/
void sortData(Player array[])
{
	int startScan,
		maxIndex;
	double maxValue;
	Player temp;
		 
	for (startScan = 0; startScan < (TEAM_SIZE - 1); startScan++)
	{
		maxIndex = startScan;
		maxValue = array[startScan].avg;
		for (int index = startScan + 1; index < TEAM_SIZE; index++)
		{
			if (array[index].avg > maxValue)
			{
				maxValue = array[index].avg;
				maxIndex = index;
			}
		}
		// Swap records in array[startScan] and array[maxIndex]
		temp = array[maxIndex];
		array[maxIndex] = array[startScan];
		array[startScan] = temp;
	}   
}

/************************************************************
 *                      displayReport                       *
 * Called by: main()                                        *
 * Receives : the team array                                *
 * Purpose  : Displays the data in the teaam structures.    *
 ************************************************************/
void displayReport(const Player array[])
{
	cout << "\nTeam Batting Averages\n\n";
	for (int i = 0; i < TEAM_SIZE; i++)
	{
		cout << left << setw(12) << array[i].name 
			 << right << setw(5) << 1000 * array[i].avg << endl;
	}
	cout << endl;
}

/* SAMPLE RUN RESULTS

Enter the name of player 1: Joe
Enter this player's batting average in decimal form: .294

Enter the name of player 2: Doug
Enter this player's batting average in decimal form: .319

Enter the name of player 3: Tim
Enter this player's batting average in decimal form: .322

Enter the name of player 4: Kurt
Enter this player's batting average in decimal form: .198

Enter the name of player 5: Steve
Enter this player's batting average in decimal form: .258

Enter the name of player 6: Jerry
Enter this player's batting average in decimal form: .302

Enter the name of player 7: Karl
Enter this player's batting average in decimal form: .271

Enter the name of player 8: Billy
Enter this player's batting average in decimal form: .304

Enter the name of player 9: Sammy
Enter this player's batting average in decimal form: .298

Enter the name of player 10: Phil
Enter this player's batting average in decimal form: .312

Enter the name of player 11: Zak
Enter this player's batting average in decimal form: .309

Enter the name of player 12: Raul
Enter this player's batting average in decimal form: .381

Team Batting Averages

Raul          381
Tim           322
Doug          319
Phil          312
Zak           309
Billy         304
Jerry         302
Sammy         298
Joe           294
Karl          271
Steve         258
Kurt          198
*/
