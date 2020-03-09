// Chapter 8 - Programming Challenge 10, bASEBALL cHAMPIONS
// This program reads in the names of Major League baseball teams that have won
// the World Series at least once from the Teams.txt file. It reads in a list
// of the team that won each year from 1950-2014 from the WorldSeriesWinners.txt
// file. Both of these files are located in the Chapter 8 Programs folder, and
// for faculty are also in the same folder as this solution file. A copy of these
// data files should be placed in the program's project directory. The Teams file
// has 29 records and the Winners file has 64 records, but student programs should 
// read these files until the EOF is reached and count the number of records they
// copy into the arrays that will hold them. Once the data has been read in, the 
// program allows the user to select a team from the list of teams it displays and
// reports how many times that team has won.

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

// Function prototypes
int getInput(string array[], ifstream&);
void displayTeams(string array[], int size);
int getChoice(int, int);
int countTimesWon(string array[], int size, string name);

int main()
{
	ifstream inputFile;
	int numTeams = 0,
		numGames = 0,
		teamWanted = 0,
		timesWon = 0;
		
	string teams[35];
	string winners[75];
	string teamName;

	// Get the data from the two data files and store it in the arrays.
	inputFile.open("Teams.txt");
	if (inputFile.fail())
	{
		cout << "Error opening file Teams.txt \n";
	}
	else
	{   numTeams = getInput(teams, inputFile);
		inputFile.close();
	}

	inputFile.open("WorldSeriesWinners.txt");
	if (inputFile.fail())
	{
		cout << "Error opening file WorldSeriesWinners.txt \n";
	}
	else
	{
		numGames = getInput(winners, inputFile);
		inputFile.close();
	}

	// Display the teams to choose from
	displayTeams(teams, numTeams);
	cout << "\nEnter the number of a team to learn how many"
		 << "\nWorld Series they have won between 1950 and 2014: ";
	teamWanted = getChoice(1, numTeams) - 1;
	teamName = teams[teamWanted];
	
	// Get and report the results
	timesWon = countTimesWon(winners, numGames, teamName);
	cout << "\nThe " << teamName << " have won the World Series "
		 << timesWon << " times. \n";
	
	return 0;
}

/*********************************************************
 *                         getInput                      *
 * This function reads strings from the file whose name  *
 * is passed to it into the array that is also passed to *
 * and returns number of records read and stored.        *
 *********************************************************/
int getInput(string A[], ifstream &inputFile)
{   
	int pos = 0;

	while (getline(inputFile, A[pos]))  // While a record was read in
	{   pos++;                          // Go to the next array position & 
	}                                   // loop to read the next record
	
	// When we get here we have reached the EOF
	// Return the number of records read
	return pos;
}

/*************************************************************
 *                         displayTeams                      *
 * This function displays the strings in the array passed to *
 * it, creating a "menu" of teams the user can select from.  *                                                *
 *************************************************************/
void displayTeams(string A[], int numRecs)
{
	cout << "Major League Baseball Teams \n\n";
	for (int pos = 0; pos < numRecs; pos++)
		cout << setw(2) << pos+1 << ". " << A[pos] << endl;
}

/*******************************************************
 *                       getChoice                     *
 * This function inputs, validates, and return the     *
 * number of the team the user has chosen.             *
 *******************************************************/
int getChoice(int min, int max)
{
	int choice;

	cin >> choice;
	while (choice < min || choice > max)
	{
		cout << "Valid choices are " << min << "-" << max << endl;
		cout << "Please re-enter your team choice: ";
		cin >> choice;
	}
	return choice;
}

/*******************************************************
 *                    countTimesWon                    *
 * this function counts the number of times the array  *
 * passed to it contains the name passed to it.        *
 *******************************************************/
int countTimesWon(string A[], int numRecs, string name)
{
	int count = 0;

	for (int pos = 0; pos < numRecs; pos++)
	{
		if (A[pos] == name)
			count++;
	}
	return count;
}

/* SAMPLE RUN RESULTS

Major League Baseball Teams

 1. Anaheim Angels
 2. Arizona Diamondbacks
 3. Atlanta Braves
 4. Baltimore Orioles
 5. Boston Americans
 6. Boston Braves
 7. Boston Red Sox
 8. Brooklyn Dodgers
 9. Chicago Cubs
10. Chicago White Sox
11. Cincinnati Reds
12. Cleveland Indians
13. Detroit Tigers
14. Florida Marlins
15. Kansas City Royals
16. Los Angeles Dodgers
17. Milwaukee Braves
18. Minnesota Twins
19. New York Giants
20. New York Mets
21. New York Yankees
22. Oakland Athletics
23. Philadelphia Athletics
24. Philadelphia Phillies
25. Pittsburgh Pirates
26. San Francisco Giants
27. St. Louis Cardinals
28. Toronto Blue Jays
29. Washington Senators

Enter the number of a team to learn how many
World Series they have won between 1950 and 2014: 21

The New York Yankees have won the World Series 15 times.
*/
