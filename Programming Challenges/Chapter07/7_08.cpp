// Chapter 7 - Programming Challenge 8, Movie Data
// This program stores movie information in a structure, which 
// is passed (by value) to a function to display the data. 
#include <iostream>
#include <string>
using namespace std;

struct MovieData
{
	string title,
		   director;
	int    year,        // Year released
		   length;      // Running time in minutes

	// Default constructor (not used)
	MovieData()
	{	title = director = "new";
		year = length = 0;
	}

	// Constructor
	MovieData(string t, string d, int yr, int len)
	{
		title = t;
		director = d;
		year = yr;
		length = len;
	}
};

// Function prototype
void displayMovie(MovieData);

int main()
{
	MovieData movie1("War of the Worlds", "Byron Haskin", 1953, 88),
		      movie2("War of the Worlds", "Stephen Spielberg", 2005, 118);

	displayMovie(movie1);
	displayMovie(movie2);
   
	return 0;
}

/***********************************************************
 *                      displayMovie                       *
 * This function displays the data in the member variables *
 * of the MovieData structure passed to it.                *
 ***********************************************************/
void displayMovie(MovieData m)
{
	cout << "\nTitle       : " << m.title;
	cout << "\nDirector    : " << m.director;
	cout << "\nReleased    : " << m.year;
	cout << "\nRunning Time: " << m.length << " minutes" << endl;
}

/* OUTPUT CREATED BY THIS PROGRAM

Title       : War of the Worlds
Director    : Byron Haskin
Released    : 1953
Running Time: 88 minutes

Title       : War of the Worlds
Director    : Stephen Spielberg
Released    : 2005
Running Time: 118 minutes
*/
