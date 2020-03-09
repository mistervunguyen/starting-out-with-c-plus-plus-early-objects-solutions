// Chapter 8 - Programming Challenge 18, Bin Manager Class
// This program uses a BinManager class that owns and manages an array 
// of InvBin objects, where each InvBin object holds information about
// a single inventory bin.

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/****************************** Class InvBin ******************************/
 
class InvBin
{
private:
	string description;                    // Item name
	int qty;                               // Quantity of items in this bin

public:
	InvBin(string d = "empty", int q = 0)  // 2-parameter constructor 
	{  description = d;  qty = q; }        // with default values specified

	void setDescription(string d)
	{  description = d; }

	string getDescription() const
	{  string s = description;
	   return s;
	}

	void setQty(int q)
	{  qty = q; }

	int getQty() const
	{  return qty; }
};

/*************************** Class BinManager ******************************/

const int MAX_BINS = 30;                 // Maximum number of bins (each holding 
                                         // a different inventory item). Not all 
                                         // bins are currently in use.
class BinManager 
{
private:
    InvBin bin[MAX_BINS];                // Array of InvBin objects  
	int numBins;                         // Number of bins currently in use
	
public:
	BinManager()                         // Default constructor
	{  numBins = 0; }

	BinManager(int, string[], int[]);    // 3-arg constructor

	string getDescription(int binNum) const      // Returns name of the item in the
	{  return bin[binNum-1].getDescription(); }  // specified bin number

	int getQuantity(int binNum) const    // Returns qty of the item in the
	{  return bin[binNum-1].getQty(); }  // specified bin number

	bool addParts(int, int);             // Adds parts to a bin
	bool removeParts(int, int);          // Removes parts from a bin
};


/***************************************************************
 *                    BinManager::BinManager                   *
 * This class function sets the number of bins and initializes *
 * their contents using nformation in the arrays passed to it. *
 ***************************************************************/
BinManager::BinManager(int size, string d[], int q[])
{
    numBins = size;

	for (int item = 0; item < numBins; item++)
    {   bin[item].setDescription(d[item]);
        bin[item].setQty(q[item]);
    }
}

/******************************************************************
 *                      BinManager::addParts                      *
 * This function adds the specified number of parts to the        *
 * designated bin. It returns true if the action was carried out  *
 * and false if it could not be done.                             *
 ******************************************************************/
bool BinManager::addParts(int binNum, int numToAdd)
{
	// Note that user bin numbers begin with 1, but BinManager array
	// subscripts begin with 0, so indexes into the array are offset by 1.
	int loc = binNum - 1;
	
	if (numToAdd > 0)
	{
		bin[loc].setQty(bin[loc].getQty() + numToAdd);
		return true;
	}
	else
		return false;
}

/******************************************************************
 *                  BinManager::removeParts                       *
 * This function removes the specified number of parts from the   *
 * designated bin. It returns true if the action was carried out  *
 * and false if it could not be done.                             *
 ******************************************************************/
bool BinManager::removeParts(int binNum, int numToRemove)
{
	// Note that user bin numbers begin with 1, but BinManager array
	// subscripts begin with 0, so indexes into the array are offset by 1.
	int loc = binNum - 1;

	if (numToRemove > 0 && numToRemove <= bin[loc].getQty())
	{
		bin[loc].setQty(bin[loc].getQty() - numToRemove);
		return true;
	}
	else
		return false;
}

//********************* Client Code That Uses the Class ***********************

// Function prototypes
void displayMenu();
int getChoice(int);
void addParts(BinManager &);
void removeParts(BinManager &);
void displayBins(const BinManager &); 

const int BINS_IN_USE = 9,
          MAX_CHOICE  = 4,
		  QUIT        = 4;

int main()
{
	int choice;         // User's menu choice
       
	string itemNames[] = {"regular pliers     ",  "N. nose pliers     ",  "screwdriver        ",
		                  "P. head screwdriver",  "wrench-large       ",  "wrench-small       ",
                          "drill              ",  "cordless drill     ",  "hand saw           "};

	int quantity[] = {25, 5, 25, 6, 7, 18, 51, 16, 12};

	// Create a BinManager object and initialize its data
	BinManager inventory(BINS_IN_USE, itemNames, quantity);   
	                                                
	displayBins(inventory);

	do
	{
		displayMenu();
		choice = getChoice(MAX_CHOICE);

		switch (choice)
		{
			case 1: addParts(inventory);
				    break;

			case 2: removeParts(inventory);
				    break;

			case 3: displayBins(inventory);
				    break;

		}
	} while (choice != QUIT);


   system ("cls");
   cout << "    ********************** \n" 
        << "     End of Day Inventory  \n"
        << "    ********************** \n";
   displayBins(inventory); 
   return 0;
}

/********************************************************
 *                      displayMenu                     *
 * Displays a menu of bin management choices.           *
 ********************************************************/
void displayMenu()
{
	cout << "\n       Inventory Control Menu \n\n";
	cout << "1 - Add parts to a bin \n";
	cout << "2 - Remove parts from a bin \n";
	cout << "3 - Display bin status report \n";
	cout << "4 - Quit \n";
}

/********************************************************
 *                        getChoice                     *
 * Inputs, validates, and returns user's choice.        *
 ********************************************************/
int getChoice(int maxChoice)
{
	int choice;
	cin >> choice;

	while (choice < 1 || choice > maxChoice)
	{
		cout << "Choice must be between 1 and " << maxChoice 
		     << ". Re-enter choice: ";
		cin  >> choice;
	}
	return choice;
}

/********************************************************
 *                        addParts                      *
 * Allows user to add parts to an inventory bin.        *
 ********************************************************/
void addParts(BinManager &inventory)
{
	int binNum,
		numToAdd;

	cout << "Enter bin number (1 - )" << BINS_IN_USE << "): ";
	binNum = getChoice(BINS_IN_USE);

	cout << "\nCurrent status of bin #" << binNum << ": "
		 << inventory.getDescription(binNum)    << "   "
		 << inventory.getQuantity(binNum)       << "\n";

	cout << "Enter number of parts to be added: ";
	cin  >> numToAdd;

	if(inventory.addParts(binNum, numToAdd))
		cout << "New status of bin #" << binNum << ":     "
		     << inventory.getDescription(binNum)    << "   "
		     << inventory.getQuantity(binNum)       << "\n";
	else
		cout << "Invalid quantity. Add was not performed.\n";
}

/********************************************************
 *                     removeParts                      *
 * Allows user to remove parts from an inventory bin.   *
 ********************************************************/
void removeParts(BinManager &inventory)
{
	int binNum,
	numToRemove;

	cout << "Enter bin number (1 - )" << BINS_IN_USE << "): ";
	binNum = getChoice(BINS_IN_USE);

	cout << "\nCurrent status of bin #" << binNum << ": "
		 << inventory.getDescription(binNum)    << "   "
		 << inventory.getQuantity(binNum)       << "\n";

	cout << "Enter number of parts to be removed: ";
	cin  >> numToRemove;

	if(inventory.removeParts(binNum, numToRemove))
		cout << "New status of bin #" << binNum << ":     "
		     << inventory.getDescription(binNum)    << "   "
		     << inventory.getQuantity(binNum)       << "\n";
	else
		cout << "Invalid quantity. Remove was not performed.\n";
}

/********************************************************
 *                       displayBins                    *
 * Displays a report on the contents of each bin.       *
 ********************************************************/
void displayBins(const BinManager &inventory)
{
	cout << "______________________________ \n"
		 << "Bin        Part          Qty \n"
		 << "______________________________ \n";

	for (int bin = 1; bin <= BINS_IN_USE; bin++)
	{
		cout << bin << "   " << inventory.getDescription(bin)
                    << "   " << inventory.getQuantity(bin) << endl;
	}
}

/* SAMPLE RUN RESULTS
______________________________
Bin        Part          Qty
______________________________
1   regular pliers        25
2   N. nose pliers        5
3   screwdriver           25
4   P. head screwdriver   6
5   wrench-large          7
6   wrench-small          18
7   drill                 51
8   cordless drill        16
9   hand saw              12

Inventory Control Menu

1 - Add parts to a bin
2 - Remove parts from a bin
3 - Display bin status report
4 - Quit
1
Enter bin number (1 - )9): 4

Current status of bin #4: P. head screwdriver   6
Enter number of parts to be added: 10
New status of bin #4:     P. head screwdriver   16

Inventory Control Menu

1 - Add parts to a bin
2 - Remove parts from a bin
3 - Display bin status report
4 - Quit
1
Enter bin number (1 - )9): 5

Current status of bin #5: wrench-large          7
Enter number of parts to be added: 10
New status of bin #5:     wrench-large          17

Inventory Control Menu

1 - Add parts to a bin
2 - Remove parts from a bin
3 - Display bin status report
4 - Quit
2
Enter bin number (1 - )9): 7

Current status of bin #7: drill                 51
Enter number of parts to be removed: 3
New status of bin #7:     drill                 48

Inventory Control Menu

1 - Add parts to a bin
2 - Remove parts from a bin
3 - Display bin status report
4 - Quit
4

   **********************
    End of Day Inventory
   **********************
______________________________
Bin        Part          Qty
______________________________
1   regular pliers        25
2   N. nose pliers        5
3   screwdriver           25
4   P. head screwdriver   16
5   wrench-large          17
6   wrench-small          18
7   drill                 48
8   cordless drill        16
9   hand saw              12
*/