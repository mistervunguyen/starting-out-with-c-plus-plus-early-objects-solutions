// Chapter 5 - Programming Challenge 15, Student Line Up
// This program determines who is at the front and the end of a line 
// when a set of students line up in alphabetical order by their first name.
#include <iostream>
#include <string>
using namespace std;

int main()
{
	const int MAX_NUM = 20;  // Maximum number of students in the class
	string name,             // Holds a name input by the user
		   first,            // Alphabetically "first" (i.e., smallest) name
		   last;             // Alphabetically "last"  (i.e., greatest) name
	int    numStudents;      // Number of students in the class

	// Input and validate the number of students
	cout << "How many students are in the class (1 to " << MAX_NUM << ")? ";
	cin  >> numStudents;
	while (numStudents < 1 || numStudents > MAX_NUM)
	{
		cout << "Class size should be between 1 and " << MAX_NUM << ".\n"
			 << "Please re-enter the number of students in the class: ";
		cin  >> numStudents;
	}

	// Consume the \n in the input buffer
	cin.get();  

	// Input the first student's name
	cout << "\nEnter student 1's first name: ";
	getline(cin, name);	

	// There is now just one person in the line, so initialize
	// both ends of the line to student 1's name
	first = last = name;

	// Input the names of the rest of the students
	for (int student = 2; student <= numStudents; student++)
	{
		cout << "Enter the next student's first name: ";
		getline(cin, name); 

		// If this new student belongs at the front or end 
		// of the line, logically put them there
		if (name < first)
			first = name;
		else if (name > last)
			last = name;
	}
  	// Display results
	cout << endl << first << " is at the head of the line." << endl;
	cout << last << " is at the end of the line." << endl;

	return 0;
}

/* SAMPLE RUN RESULTS

How many students are in the class (1 to 20)? 10

Enter student 1's first name: Sherry
Enter the next student's first name: Tom
Enter the next student's first name: Susan
Enter the next student's first name: Phil
Enter the next student's first name: Rolando
Enter the next student's first name: Connor
Enter the next student's first name: Mary
Enter the next student's first name: Denise
Enter the next student's first name: Sam
Enter the next student's first name: Pete

Connor is at the head of the line.
Sam is at the end of the line.
*/
