// Chapter  16 - Assignment 4, Sequence Accumulation
// This program uses a template function to ``accumulate"
// the ``sum" of all entries of a vector.
 
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/********************************************
 *      T accum(vector <T> v)               *
 * Accumulates by adding or concatenating   *
 * all elements of the vector v.            *
 ********************************************/
template <class T>
T accum(vector<T> v)
{
	//initialize
	T result = T();
	//loop to accumulate into result
	for (unsigned int k = 0; k < v.size(); k++)
		result = result + v[k];
	return result;
}		

int main()
{
	// Explain program
	cout << "This program demonstrates accumulation using templates.\n";

	// Get numeric types from the user
	vector<double> dvec;
	double dvalue;
	cout << "Enter 3 numbers: ";
	for (int k = 0; k < 3; k++)
	{
		cin >> dvalue;
		dvec.push_back(dvalue);
	}

	// Process and output results
	double sum = accum(dvec);
	cout << "The sum of the numbers is " << sum << endl;	
	
	// Get string inputs from user
	vector<string> svec;
	string svalue;
	cout << "Enter 3 strings: ";
	for (int k = 0; k < 3; k++)
	{
		cin >> svalue;
		svec.push_back(svalue);
	}

	// Process and output results
	string str_sum = accum(svec);
	cout << "The sum of the strings  is " << str_sum << endl;
	
	return 0;	
}