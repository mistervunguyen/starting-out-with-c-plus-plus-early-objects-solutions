// Chapter  14 - Assignment 4, Recursive Array Sum
// This program computes and prints the sum of 
// an array of numbers.
 
#include <iostream>
using namespace std;

int arraySum(int a[ ], int size); // Prototype

int main( )
{
	const int MAX_SIZE = 50;    // Max size of array
	int arr[MAX_SIZE];
	int size;                   // Actual size of array
	
	//Explain purpose of program
	cout << "This program computes the sum of a list of integer numbers.";

	//Get input from user
	cout << "\n How many numbers are in your list? " ;
	cin >> size;
	if (size > MAX_SIZE)
	{
		cout << "Program can not handle lists of more than " << MAX_SIZE << " numbers.";
		exit(1);
	}
	cout << "Enter the list of numbers, separated by spaces: \n";
	for (int k = 0; k < size; k++)
		cin >> arr[k];
	
	// Print the sum
	cout << "The sum of these numbers is " << arraySum(arr, size);
	
	return 0;
}

//*********************************************************
//                   arraySum                             *
// Computes sum of integer array arr of given size.       *
//*********************************************************
int arraySum(int arr[ ], int size)
{
	if (size == 0)        
       return 0;
    else 
       return arraySum(arr, size-1) + arr[size-1];	
}