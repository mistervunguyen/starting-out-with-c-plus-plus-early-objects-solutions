// Chapter 5 - Programming Challenge 28, Using Files--Student Line Up
// This program determines who is at the front and the end of a line when a set of
// people line up in order by their first name. It modifies Programming Challenge 13
// to read the names from the LineUp.txt file, which is located in the Chapter 5 
// Programs folder, and for faculty also in the same folder as this solution file.
// A copy of the data file should be placed in the program's project directory. 
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	string name,            // Holds a student first name read from a file
		   first,           // Alphabetically "first" (i.e., smallest) name
		   last;            // Alphabetically "last"  (i.e., greatest) name
	ifstream nameFile;

	// Open the file and check that it was found and correctly opened
	nameFile.open("LineUp.txt");
	if (!nameFile)
	{	cout << "Error finding and opening the file.\n";
		exit(1);
	}
   
	// If the file opened correctly continue on to read in the first name
	nameFile >> name;

	// There is now just one person in the line, so initialize 
	// both ends of the line the first person's name
	first = last = name;

	// While another name is successfully read in, process it
	while (nameFile >> name) 
	{
		if (name < first)
			first = name;
		else if (name > last)
			last = name;
	}

	// Display results
	cout << first << " is at the head of the line." << endl;
	cout << last  << " is at the end of the line." << endl;

	// Close the file
	nameFile.close();

	return 0;
}

/* CORRECT RESULTS

Barb is at the head of the line.
Zev is at the end of the line.
*/