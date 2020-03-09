// Chapter 4 - Programming Challenge 13, Running the Race
// This program determines who came in 1st, 2nd, and 3rd  
// in a race. It assumes there are no ties.
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	string runner1, runner2, runner3;   // Names of 3 runners
	double time1, time2, time3;         // Finish times of 3 runners

	// Input name and finishing time for each runner
	cout << "Enter the names of three runners and their finishing times.\n";
	cout << "Then I will tell you who came in first, second, and third.\n\n";

	cout << "Name of Runner 1: ";
	getline(cin, runner1);
	cout << "Runner 1's finishing time: ";
	cin  >> time1;

	cout << "\nName of Runner 2: ";
	cin.ignore();             // skip the \n in the input buffer 
                              // left by the last cin statement
	getline(cin, runner2);
	cout << "Runner 2's finishing time: ";
	cin  >> time2;

	cout << "\nName of Runner 3: ";
	cin.ignore();             // skip the \n in the input buffer 
                              // left by the last cin statement
	getline(cin, runner3);
	cout << "Runner 3's finishing time: ";
	cin  >> time3;
	cout << endl;

	if (time1 < 0 || time2 < 0 || time3 < 0)
		cout << "Runner times cannot be less than 0.\n";
	else
	{
		// Display report heading
		cout << "Race Results \n";
		cout << "------------ \n\n";
		
		cout << fixed << showpoint << setprecision(2);
		// Determine and display first place finisher
		cout << "1st place: ";
		if ((time1 < time2) && (time1 < time3))
			cout << left  << setw(10) << runner1 << " " 
			     << right << setw(5) << time1 << endl;
		else if (time2 < time3)
			cout << left  << setw(10) << runner2 << " " 
			     << right << setw(5) << time2 << endl;
		else
			cout << left  << setw(10) << runner3 << " " 
			     << right << setw(5) << time3 << endl;

		// Determine and display second place finisher
		cout << "2nd place: ";
		if ( ((time1 < time2) && (time1 > time3)) ||
		     ((time1 > time2) && (time1 < time3)) )
			 cout << left  << setw(10) << runner1 << " " 
			      << right << setw(5) << time1 << endl;
		else if ( ((time2 < time1) && (time2 > time3)) ||
		          ((time2 > time1) && (time2 < time3)) )
			 cout << left  << setw(10) << runner2 << " " 
			      << right << setw(5) << time2 << endl;
		else
			cout << left  << setw(10) << runner3 << " " 
			     << right << setw(5) << time3 << endl;

		// Determine and display third place finisher
		cout << "3rd place: ";
		if ((time1 > time2) && (time1 > time3))  
			cout << left  << setw(10) << runner1 << " "
			     << right << setw(5) << time1 << endl;
		else if (time2 > time3) 
			cout << left  << setw(10) << runner2 << " "
			     << right << setw(5) << time2 << endl;
		else
			cout << left  << setw(10) << runner3 << " "
			     << right << setw(5) << time3 << endl;
	}
	return 0;
}

/* SAMPLE RUN OUTPUT

Enter the names of three runners and their finishing times.
Then I will tell you who came in first, second, and third.

Name of Runner 1: Tom
Runner 1's finishing time: 9.45

Name of Runner 2: Dick
Runner 2's finishing time: 8.7

Name of Runner 3: Harry
Runner 3's finishing time: 10.5

Race Results
------------

1st place: Dick        8.70
2nd place: Tom         9.45
3rd place: Harry      10.50
*/