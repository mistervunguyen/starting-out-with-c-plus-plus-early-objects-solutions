//Chapter 14 - Assignment 6, Recursive Array Member Test
//This program uses recursion to test a value to see if 
//it is a member of an aray.
  
#include <iostream>
using namespace std;

bool isMember(int arr[ ], int size, int item); // Prototype

int main()
{
	
	const int MAX_SIZE = 50;  // Max size of array
	int arr[MAX_SIZE];
	int size;                 // Actual size of array
	
	//Explain purpose of program
	cout << "This program tests membership of an integer in  a list of integer numbers.";

	//Get input number of array elements
	cout << "\n How many numbers are in your list? " ;
	cin >> size;
	if (size > MAX_SIZE)
	{
		cout << "Program can not handle lists of more than " << MAX_SIZE << " numbers.";
		exit(1);
	}

      // Get the array elements
	cout << "Enter the list of numbers, separated by spaces: \n";
	for (int k = 0; k < size; k++)
		cin >> arr[k];
	
	// Get the value to search for
      cout << "Enter the value to test membership for: ";
	int item;
	cin >> item;

	// Print the result of the test
	if (isMember(arr, size, item))
		cout << "The number " << item << " is on the list.";
	else
		cout << "The number " << item << " is not on the list.";
	
	return 0;
}


//**************************************************************************
//                        isMember                                         *
//Recursively tests an array of given size for the presence of an item.    *
//**************************************************************************
bool isMember(int arr[ ], int size, int item)
{
	if (size == 0) 
      return false;
   else
	  return arr[size-1] == item || isMember(arr, size-1, item);	
}

