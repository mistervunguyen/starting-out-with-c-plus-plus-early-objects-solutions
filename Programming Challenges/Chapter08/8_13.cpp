// Chapter 8 - Programming Challenge 13, Stats class and Track Statistics
// This program uses the Stats class created in Programming Challenge 12 
// to manage and report track statistics on 100-yard dash times.
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Stats 
{
  private:
	double data[30];   // Array holding up to 30 double values
	int size;          // Actual number of values in the array.

  public:
	Stats()            // Constructor 
	{   size = 0;
	}

	bool storeValue(double);     // Mutator member function
	
	double total()     const;    // Accessor member functions
	double average()   const;    // These are declared to be const
	double lowest()    const;    // functions to ensure they cannot
	double highest()   const;    // alter any class member data and
	int lowestIndex()  const;    // to allow Stats objects to be passed
	int highestIndex() const;    // to functions as constant references.
};

/*************************************************************
 *                    Stats::storeValue                      *
 * Stores a value in the next available data array position. *
 *************************************************************/
bool Stats::storeValue(double value)
{
	if (size < 30)
	{	data[size] = value;
		size++;
		return true;
	}
	else // The array is full
		return false;
}

/************************************************************
 *                     Stats::total                         *
 * Calculates and returns the total of the values stored in *
 * the array.                                               *
 ************************************************************/
double Stats::total() const
{
	double total = 0.0;

	for (int pos = 0; pos < size; pos++)
		total += data[pos];

	return total;
}
                    
/************************************************************
 *                     Stats::average                       *
 * Calculates and returns the average of the values stored  *
 * in the array.                                            *
 ************************************************************/
double Stats::average() const
{
	return (total() / size);
}

/************************************************************
 *                   Stats::lowestIndex                     *
 * Finds and returns the subscript of the smallest value    *
 * stored in the array.                                     *
 ************************************************************/
int Stats::lowestIndex() const
{
	int lowest = 0;   // Index of the smallest value found so far
   
	for (int pos = 1; pos < size; pos++)
	{
		if (data[pos] < data[lowest])
			lowest = pos;
	}		
	return lowest;
} 

/*************************************************************
 *                       Stats::lowest                       *
 * Finds and returns the smallest value stored in the array. *
 *************************************************************/
double Stats::lowest() const
{
	return data[lowestIndex()];
}

/************************************************************
 *                   Stats::highestIndex                    *
 * Finds and returns the subscript of the smallest value    *
 * stored in the array.                                     *
 ************************************************************/
int Stats::highestIndex() const
{
	int highest = 0;   // Index of the highest value found so far
   
	for (int pos = 1; pos < size; pos++)
	{
		if (data[pos] > data[highest])
			highest = pos;
	}		
	return highest;
} 

/************************************************************
 *                    Stats::highest                        *
 * Finds and returns the largest value stored in the array. *
 ************************************************************/
double Stats::highest() const
{
	return data[highestIndex()];
}

//*************************** user program *****************************

const int NUM_RUNNERS = 15;
const string name[] = {"Aaron ", "Ben   ", "Connor",  "David ", "Elton ",
                       "Fred  ", "Gus   ", "Hal   ",  "Igor  ", "Juan  ",
					   "Kim   ", "Luis  ", "Morgan",  "Nils  ", "Omar  "}; 

// Function prototypes
void getData(Stats &);
void createReport(const Stats &);

int main()
{
	Stats dashTimes;        // Create an instance of the Stats class
                            // to store and manage the race times
	getData(dashTimes);
	createReport(dashTimes);

	return 0;
}

/***************************************************************
 *                           getData                           *
 * Accepts inputs and sends them to the Stats object to store. *
 ***************************************************************/
void getData(Stats &dashtimes)
{
	double seconds;
	
	for (int runner = 0; runner < NUM_RUNNERS; runner++)
	{	// Input and validate the time for each runner
		cout << "Enter the 100-yard dash time for " << name[runner] << ": ";
		cin  >> seconds;
      
		while (seconds < 0)
		{	cout << "Time must be 0 or more seconds. Please re-enter: ";
			cin  >> seconds;
		}
		
		// Send it to the Stats object to store
		dashtimes.storeValue(seconds);
	}
}
  
/************************************************************
 *                        createReport                      *
 * Displays a report of 100-yard dash time statistics.      *
 ************************************************************/
void createReport(const Stats &dashTimes)
{
	// Print a report heading
	cout << fixed << showpoint << setprecision(2); 
	cout << "\n        Tulsa Tigers Track Team \n";
	
	// Display the average 100-yard dash time
	cout << "\nAverage 100-yard dash time: " 
	     << dashTimes.average() << " seconds\n";

	// Display the slowest & fastest times
	string slowName = name[dashTimes.highestIndex()];
	string fastName = name[dashTimes.lowestIndex()];
	
	cout << "Slowest runner: " << left << setw(12) << slowName
	     <<  dashTimes.highest() << " seconds \n"; 
	cout << "Fastest runner: " << left << setw(12) << fastName
	     <<  dashTimes.lowest() << " seconds \n"; 
}

/* SAMPLE RUN RESULTS

Enter the 100-yard dash time for Aaron : 11.1
Enter the 100-yard dash time for Ben   : 10.8
Enter the 100-yard dash time for Connor: 10.5
Enter the 100-yard dash time for David : 10.6
Enter the 100-yard dash time for Elton : 10.6
Enter the 100-yard dash time for Fred  : 11.2
Enter the 100-yard dash time for Gus   : 10.4
Enter the 100-yard dash time for Hal   : 10.7
Enter the 100-yard dash time for Igor  : 10.6
Enter the 100-yard dash time for Juan  : 10.5
Enter the 100-yard dash time for Kim   : 10.8
Enter the 100-yard dash time for Luis  : 11.1
Enter the 100-yard dash time for Morgan: 10.8
Enter the 100-yard dash time for Nils  : 10.6
Enter the 100-yard dash time for Omar  : 10.5

Tulsa Tigers Track Team

Average 100-yard dash time: 10.72 seconds
Slowest runner: Fred        11.20 seconds
Fastest runner: Gus         10.40 seconds
*/
