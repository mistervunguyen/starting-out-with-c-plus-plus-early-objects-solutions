// Chapter 16 --  Assignment 7:  SimpleVector modification
// See SimpleVector.h for details.
 
#include <iostream>
#include "SimpleVector.h"
using namespace std;

int main()
{
	SimpleVector<int> intTable(10);
	SimpleVector<double> NumberTable(10);

	// Store values in the two data structures
	for (int x = 0; x < 10; x++)
	{
		intTable[x] = x;
		NumberTable[x] = (x + .5);
	}

	// Display the values 
	cout << "These values are in intTable:\n";
	for (int x = 0; x < intTable.size(); x++)
		cout << intTable[x] << " ";
	cout << endl;
	cout << "These values are in NumberTable:\n";
	for (int x = 0; x < NumberTable.size(); x++)
		cout << NumberTable[x] << " ";
	cout << endl;
	
	// Use push_back
	intTable.push_back(100);
	NumberTable.push_back(0.78);

	// Display the values in the array
	cout << "These values are in intTable:\n";
	for (int x = 0; x < intTable.size(); x++)
		cout << intTable[x] << " ";
	cout << endl;
	cout << "These values are in NumberTable:\n";
	for (int x = 0; x < NumberTable.size(); x++)
		cout << NumberTable[x] << " ";
	cout << endl;

	// Use pop_back, catching the exception, if thrown
	try
	{
		cout << "popping " << intTable.pop_back() << endl;
	}
	catch (char *exceptionString)
	{
		cout << exceptionString;
	}
	try
	{
		cout << "popping " << NumberTable.pop_back() << endl;
	}
	catch (char *exceptionString)
	{
		cout << exceptionString;
	}

	// Display the values 
	cout << "These values are in intTable:\n";
	for (int x = 0; x < intTable.size(); x++)
		cout << intTable[x] << " ";
	cout << endl;
	cout << "These values are in NumberTable:\n";
	for (int x = 0; x < NumberTable.size(); x++)
		cout << NumberTable[x] << " ";
	cout << endl;

	return 0;
}
