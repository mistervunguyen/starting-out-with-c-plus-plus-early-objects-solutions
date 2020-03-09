// Chapter 8 - Programming Challenge 5, Monkey Business 
// This program uses a 2-dimensional array to store data on monkey
// food consumption. The array is passed to functions that find the
// total, least, and greatest food consumption. 
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int NUM_MONKEYS = 3;    
const int NUM_DAYS = 7;

// Function prototypes
void   getData(double[][NUM_DAYS]);
double findGroupTotal(double[][NUM_DAYS]);
double findOneTotal (double[][NUM_DAYS], int);
double findLeastTotal(double[][NUM_DAYS]);
double findGreatestTotal(double[][NUM_DAYS]);

int main()
{
	// Create a 2-D array to hold the pounds of food consumed 
	// by each monkey on each day of the week
	double food[NUM_MONKEYS][NUM_DAYS];

	// Call the getData function to input the data into the array
	getData(food);

	// Display the average amount of food the monkeys ate per day, and the 
	// least amount and greatest amount eaten all week by any one monkey.
	cout << fixed << showpoint << setprecision(2);

	cout << "\n\nAverage amount of food eaten per day \n"
		 << "by the entire family of monkeys = "
		 << (findGroupTotal(food) / NUM_DAYS) << " pounds. \n\n";

	cout << "Least amount of food eaten during the week \n"
		 << "by any one monkey = " << findLeastTotal(food) << " pounds. \n\n"; 

	cout << "Greatest amount of food eaten during the week \n"
		 << "by any one monkey = " << findGreatestTotal(food) << " pounds. \n"; 

	return 0;
}

/*****************************************************
 *                   getData                         *
 * Fills the array with data.                        *
 *****************************************************/
void getData(double food[][NUM_DAYS])
{
	for (int monkey = 0; monkey < NUM_MONKEYS; monkey++)
	{
		cout << "\nEnter pounds of food eaten by monkey #"
			 << (monkey+1) << " on \n";
		for (int day = 0; day < NUM_DAYS; day++)
		{
			cout << "day " << (day+1) << ": ";
			cin  >> food[monkey][day];
			while (food[monkey][day] < 0.0)
			{
				cout << "food eaten cannot be less than 0. Please re-enter\n";
				cout << "day " << (day+1) << ": ";
				cin  >> food[monkey][day];
			}
		}
	}
}

/*****************************************************
 *                  findGroupTotal                   *
 * Returns the total of all values in the array.     *
 *****************************************************/
double findGroupTotal(double food[][NUM_DAYS])
{
	double total = 0.0;

	for (int monkey = 0; monkey < NUM_MONKEYS; monkey++)
	{
		for (int day = 0; day < NUM_DAYS; day++)
			total += food[monkey][day];
	}
	return total;
}


/*****************************************************
 *                    findOneTotal                   *
 * Finds and returns the amount of food eaten during *
 * the week by one particular monkey. It does this by*
 * totaling and returning the values in the one row  *
 * of the array representing the desired monkey.     *
 *****************************************************/
double findOneTotal (double food[][NUM_DAYS], int thisMonkey)
{
	double total = 0.0;

	for (int day = 0; day < NUM_DAYS; day++)
		total += food[thisMonkey][day];

	return total;
}
   
/*****************************************************
 *                   findLeastTotal                  *
 * Finds and returns the smallest row total.         *
 *****************************************************/  
double findLeastTotal (double food[][NUM_DAYS])
{
	double thisMonkeyTotal;
	double leastTotal;
   
    // Set leastTotal to the first monkey's total food consumption
	leastTotal= findOneTotal(food, 0);

	// Check if any other monkey consumed less food
	for (int thisMonkey = 1; thisMonkey < NUM_MONKEYS; thisMonkey++)
	{
		thisMonkeyTotal = findOneTotal(food, thisMonkey);
		if (thisMonkeyTotal < leastTotal)
			leastTotal = thisMonkeyTotal;
	}
	return leastTotal;
}

/*****************************************************
 *                findGreatestTotal                  *
 * Finds and returns the largest row total.          *
 *****************************************************/  
double findGreatestTotal (double food[][NUM_DAYS])
{
	double thisMonkeyTotal;
	double greatestTotal;

	// Set greatestTotal to the first monkey's total food consumption
	greatestTotal= findOneTotal(food, 0);

	// Check if any other monkey consumed more food
	for (int thisMonkey = 1; thisMonkey < NUM_MONKEYS; thisMonkey++)
	{
		thisMonkeyTotal = findOneTotal(food, thisMonkey);
		if (thisMonkeyTotal > greatestTotal)
			greatestTotal = thisMonkeyTotal;
	}
	return greatestTotal;
}

/* SAMPLE RUN RESULTS


Enter pounds of food eaten by monkey #1 on
day 1: 3.4
day 2: 3.7
day 3: 3.1
day 4: 3.2
day 5: 3.5
day 6: 3.1
day 7: 3.2

Enter pounds of food eaten by monkey #2 on
day 1: 2.6
day 2: 2.5
day 3: 2.5
day 4: 2.4
day 5: 2.6
day 6: 2.5
day 7: 2.5

Enter pounds of food eaten by monkey #3 on
day 1: 3.9
day 2: 4.0
day 3: 4.1
day 4: 4.0
day 5: 3.8
day 6: 3.7
day 7: 4.0


Average amount of food eaten per day
by the entire family of monkeys = 9.76 pounds.

Least amount of food eaten during the week
by any one monkey = 17.6 pounds.

Greatest amount of food eaten during the week
by any one monkey = 27.5 pounds.
*/
