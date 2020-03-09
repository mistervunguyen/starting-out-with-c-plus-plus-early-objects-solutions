// Chapter 8 - Programming Challenge 12, Stats Class and Rainfall Statistics
// This program revises Programming Challenge 8 to create and use a Stats class
// that contains general statistical functions. It will use it to store monthly
// rainfall data and to report rainfall statistics. The Stats class is defined
// in this same file as the client program that uses it. You may wish to have
// students use a separate file for the Stats class. 
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
	{	size = 0;
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

// Function prototype
void storeData(Stats &);
void rainReport(const Stats &);

const int NUM_MONTHS = 12;         // The number of months of data 
                                   // being input and analyzed

const string monthName[] = {"January",   "February",  "March",     "April", 
                            "May",       "June",      "July",      "August",
						    "September", "October",   "November ", "December "};
int main()
{
	Stats rainfall;              // Create an instance of the Stats class
                                 // to store and manage the rainfall data
	storeData(rainfall);
	rainReport(rainfall);

	return 0;
}

/***************************************************************
 *                          storeData                          *
 * Accepts inputs and sends them to the Stats object to store. *
 ***************************************************************/
void storeData(Stats &rainfall)
{
	double rain;
	
	for (int month = 0; month < NUM_MONTHS; month++)
	{	// Input and validate the montly rain amount
		cout << "Enter the rainfall (in inches) for " << monthName[month] << ": ";
		cin  >> rain;
      
		while (rain < 0)
		{	cout << "Rainfall must be 0 or more. Please re-enter: ";
			cin  >> rain;
		}
		
		// Send it to the Stats object to store
		rainfall.storeValue(rain);
	}
}
  
/*************************************************************
 *                        	rainReport                       *
 * Displays a report of rainfall statistics.                 *
 *************************************************************/
void rainReport(const Stats &rainfall)
{
	// Print a report heading
	cout << "\n    2015 Rain Report for NeverSnows County \n";
	
	// Display the total rainfall
	cout << fixed << showpoint << setprecision(2) << endl;
	cout << "Total rainfall: ";
	cout << rainfall.total() << " inches \n";
	
	// Display the average rainfall
	cout << "Average monthly rainfall: ";
	cout << rainfall.average() << " inches \n";

	// Display the smallest & largest amounts of monthly rain
	string lowMonth  = monthName[rainfall.lowestIndex()];
	string highMonth = monthName[rainfall.highestIndex()];
	
	cout << "The least rain fell in " << lowMonth << " with "
	     <<  rainfall.lowest() << " inches. \n"; 
	cout << "The most rain fell in " << highMonth << " with "
	     << rainfall.highest() << " inches. \n";
}

/* SAMPLE RUN RESULTS

Enter the rainfall (in inches) for January: .78
Enter the rainfall (in inches) for February: .50
Enter the rainfall (in inches) for March: 2.6
Enter the rainfall (in inches) for April: 4.8
Enter the rainfall (in inches) for May: 4.5
Enter the rainfall (in inches) for June: 3.2
Enter the rainfall (in inches) for July: 1.1
Enter the rainfall (in inches) for August: .75
Enter the rainfall (in inches) for September: 1.7
Enter the rainfall (in inches) for October: 1.4
Enter the rainfall (in inches) for November: 2.1
Enter the rainfall (in inches) for December: .83

    2015 Rain Report for NeverSnows County

Total rainfall: 24.26 inches
Average monthly rainfall: 2.02 inches
The least rain fell in February with 0.50 inches.
The most rain fell in April with 4.80 inches.
*/
