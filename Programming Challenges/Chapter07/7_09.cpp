// Chapter 7 - Programming Challenge 9, Movie Profit
// This program modifies Programming Challenge 8 in two ways. 
// First, it passes the structure holding the movie information 
// to the displayData function as a constant reference. Second, 
// in addition to displaying the data, it computes and displays 
// the amount of the first year's profit or loss.
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct MovieData
{
	string title,
		   director;
	int    year,        // Year released
		   length;      // Running time in minutes
   double  costs,       // Production costs (courtesy of IMDB)
	       revenues;    // Estimated first year revenues

   // Default constructor (not used)
   MovieData()
   {
	   title = director = "new";
	   year = length = 0;
	   costs = revenues = 0.0;
  }
  // Constructor
  MovieData(string t, string d, int yr, int len, double c, double r)
  {
	  title = t;
	  director = d;
	  year = yr;
	  length = len;
	  costs = c;
	  revenues = r;
  }
};

// Function prototype
void displayMovie(const MovieData &);

int main()
{
	MovieData  movie1("War of the Worlds", "Byron Haskin", 
		               1953,  88,  2000000,  3800000),
			   movie2("War of the Worlds", "Stephen Spielberg",
			           2005, 118, 132000000, 250000000);

	displayMovie(movie1);
	displayMovie(movie2);
   
	return 0;
}

/***********************************************************
 *                      displayMovie                       *
 * This function displays the data in the member variables *
 * of the MovieData structure passed to it, as well as the *
 * amount of the first year's profit or loss.              *
 ***********************************************************/
void displayMovie(const MovieData &m)
{
	cout << fixed << showpoint << setprecision(1);
	cout << "\nTitle            : " << m.title;
	cout << "\nDirector         : " << m.director;
	cout << "\nReleased         : " << m.year;
	cout << "\nRunning Time     : " << m.length << " minutes";

	if (m.revenues >= m.costs)
		cout << "\nFirst year profit: $" 
		     << ((m.revenues - m.costs)/1E6) << " million\n";
	else
		cout << "\nFirst year loss  : $"
		     << ((m.costs - m.revenues)/1E6) << " million\n";
}

/* OUTPUT CREATED BY THIS PROGRAM

Title            : War of the Worlds
Director         : Byron Haskin
Released         : 1953
Running Time     : 88 minutes
First year profit: $1.8 million

Title            : War of the Worlds
Director         : Stephen Spielberg
Released         : 2005
Running Time     : 118 minutes
First year profit: $118.0 million
*/
