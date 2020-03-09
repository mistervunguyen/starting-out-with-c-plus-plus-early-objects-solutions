// Chapter 18, Assignment 7, Queue Exceptions
// This program features queues that can throw exceptions.
#include <iostream>
#include "IntQueue.h"
using namespace std;
 
int main()
{
	IntQueue iQueue(5);

	cout << "Enqueuing 5 items...\n";
	
	// Enqueue 5 items.
	try
	{
		for (int k = 1; k <= 5; k++)
			iQueue.enqueue(k*k); 	
			
		// Deqeue and retrieve all items in the queue.
		cout << "The values in the queue were: ";
		while (!iQueue.isEmpty())
		{
			int value;
			iQueue.dequeue(value);
			cout << value << "  ";
		}
		cout << endl;

		// Allow user option to overflow the queue
		cout << "Enter  integers  as prompted to add to  queue, add -1 as the last number." << endl;
		int number;
		do
		{
			cout << "Enter a number: ";
			cin >> number;
			iQueue.enqueue(number);
		}
		while (number >= 0);
        
		// Empty the queue while printing its contents
		cout << "The numbers added to the queue are: " << endl;
		while (!iQueue.isEmpty())
		{
			int value;
			iQueue.dequeue(value);
			cout << value << "  ";
		}
        cout << endl;
		return 0;
	}
	catch (IntQueue::Overflow)
	{
		cout << "Error: Queue Overflow";
	}
}