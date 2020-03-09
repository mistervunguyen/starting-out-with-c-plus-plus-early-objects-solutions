// Chapter 9 - Programming Challenge 12, Modified Bin Manager Class
// This program uses a class that owns and manages an array of Bin structures.
// It modifies Chapter 8's Programming Challenge 18 to allow inventory bins
// to be referenced by item name as well as by bin number. 
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cctype>
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
	string toString(int) const;          // Converts an int to string form
	string upperCaseIt (string) const;   // Uppercases a string
	int findBin(string) const;           // Finds the index of the bin 
	                                     // associated with an item name
	
public:
	BinManager()                         // Default constructor
	{  numBins = 0; }

	BinManager(int, string[], int[]);    // 3-arg constructor

	string getDescription(int binNum) const      // Returns name of the item in the
	{  return bin[binNum-1].getDescription(); }  // specified bin number

	int getQuantity(int binNum) const    // Returns qty of the item in the
	{  return bin[binNum-1].getQty(); }  // specified bin number
	
	int getQuantity(string item) const;  // Returns qty of the item with the
	                                     // specified name 

	string displayAllBins() const;       // Returns string having one line
                                         // for each item

	bool addParts(int, int);             // Adds parts to a bin by bin #
	bool addParts(string, int);          // Adds parts to a bin by item name
	
	bool removeParts(int, int);          // Removes parts from a bin by bin #
	bool removeParts(string, int);       // Removes parts from a bin by item name
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

/***************************************************************
 *                   BinManager::upperCaseIt                   *
 * This function returns an all uppercase version of the       *
 * string passed to it.                                        *
 ***************************************************************/
string BinManager::upperCaseIt (string s) const
{
	for (unsigned pos = 0; pos < s.length(); pos++)
		s[pos] = toupper(s[pos]);
	
	return s;
}		

/***************************************************************
 *                      BinManager::findBin                    *
 * This function uses the item name passed to it to locate a   *
 * bin. If found, the bin's array subscript is returned. If    *
 * not found, -1 is returned.                                  *
 ***************************************************************/
int BinManager::findBin(string name) const
{
	name = upperCaseIt(name);
	bool found = false;
	int index = 0;
	
	while (index < numBins && !found)
	{
		if ( upperCaseIt(bin[index].getDescription()) == name)
			found = true;
		else
			index++;
	}
	if (found)
		return index;
	else
		return -1;
}

/***************************************************************
 *                  BinManager::displayAllBins                 *
 * "Displays" current inventory status by creating and         *
 * returning a string having one line for each bin.            *
 ***************************************************************/
string BinManager::displayAllBins() const
{
	string binInfo = "";

	for (int binNum = 1; binNum <= numBins; binNum++)
	{
		binInfo += " " + toString(binNum) + "   " + 
			       bin[binNum-1].getDescription() + " " +
				   toString(bin[binNum-1].getQty()) + "\n";
	}
	return binInfo;
}

/***************************************************************
 *                      BinManager::toString                   *
 * Converts an integer to a string object.                     *
 ***************************************************************/
string BinManager::toString(int num) const
{
	ostringstream ss;
	ss << num;
	return ss.str();
}

/***************************************************************
 *                     BinManager::getQuantity                 *
 * This overloaded class functions returns the number of items *
 * in the bin associated with the item name passed to it.      * 
 ***************************************************************/
int BinManager::getQuantity(string item) const
{
	int index = findBin(item);
	
	if (index == -1)     // Item could not be found
		return -1;
	else
		return bin[index].getQty();
}	

/******************************************************************
 *                    BinManager::addParts                        *
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
 *                   BinManager::addParts                         *
 * This overloaded function adds the specified number of parts to *
 * the bin associated with the item name passed to it.            *
 * It returns true if the action was carried out and false if it  *
 * could not be done.                                             *
 ******************************************************************/
bool BinManager::addParts(string itemName, int numToAdd)
{
	int index = findBin(itemName);
	int binNum = index + 1;
	
	if (index == -1)     // Item could not be found
		return false;
	else
	{   // Call the other addParts function to do the add and
		// then send its return value back to the user. 
		return addParts(binNum, numToAdd);
	}
	
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

/******************************************************************
 *                  BinManager::removeParts                       *
 * This overloaded function removes the specified number of parts *
 * from the bin associated with the item name passed to it.       *
 * It returns true if the action was carried out and false if it  *
 * could not be done.                                             *
 ******************************************************************/
bool BinManager::removeParts(string itemName, int numToRemove)
{
	int index = findBin(itemName);
	int binNum = index + 1;
	
	if (index == -1)     // Item could not be found
		return false;
	else
	{   // Call the other removeParts function to do the remove 
		// and then send its return value back to the user. 
		return removeParts(binNum, numToRemove);
	}
}
///////////////////////////////////////////////////////////////////////////////
//********************* Client Code That Uses the Class ***********************
///////////////////////////////////////////////////////////////////////////////

// Function prototypes
void displayMenu();
int  getChoice(int);
int  getAccessMethod();
void displayQty(const BinManager &);
void addParts(BinManager &, int);
void addParts(BinManager &, string);
void removeParts(BinManager &, int);
void removeParts(BinManager &, string);
void displayBins(const BinManager &); 

const int BINS_IN_USE = 9,
          MAX_CHOICE  = 5,
		  QUIT        = 5;

int main()
{
	int choice,           // User's menu choice
		binNum;           // Bin number

	string name;          // Name of a single inventory item
       
	string itemNames[] = {"regular pliers",       "N. nose pliers",  "screwdriver",
		                  "P. head screwdriver",  "wrench-large",    "wrench-small",
                          "drill",                "cordless drill",  "hand saw"};

	int quantity[] = {25, 5, 25, 6, 7, 18, 51, 16, 12};

	BinManager inventory(9, itemNames, quantity);   // Create a BinManager object 
	                                                // & initialize its data
	displayBins(inventory);

	do
	{
		displayMenu();
		choice = getChoice(MAX_CHOICE);

		switch (choice)
		{
			case 1: displayQty(inventory); 
				    break;

			case 2: if (getAccessMethod() == 1)   // Add parts by bin number
					{
						cout << "Enter bin number (1 - )" << BINS_IN_USE << "): ";
						binNum = getChoice(BINS_IN_USE);
						addParts(inventory, binNum);
					}
					else                          // Add parts by item name
					{	cout << "\nEnter item name: ";
						cin.ignore();
						getline(cin, name);
						addParts(inventory, name);
					}
				    break;

			case 3: if (getAccessMethod() == 1)   // Remove parts by bin number
					{
						cout << "Enter bin number (1 - )" << BINS_IN_USE << "): ";
						binNum = getChoice(BINS_IN_USE);
						removeParts(inventory, binNum);
					}
					else                          // Remove parts by item name
					{	cout << "Enter item name: ";
						cin.ignore();
						getline(cin, name);
						removeParts(inventory, name);
					}
				    break;

			case 4: displayBins(inventory);
				    break;
		}
	} while (choice != QUIT);

   system ("cls");
   cout << "\n********************** \n" 
        << " End of Day Inventory  \n"
        << "**********************   ";
   displayBins(inventory); 
   return 0;
}

/********************************************************
 *                      displayMenu                     *
 * Displays a menu of bin management choices.           *
 ********************************************************/
void displayMenu()
{
	cout << "\n\n       Inventory Control Menu \n\n";
	cout << "1 - Get quantity in a bin     \n";
	cout << "2 - Add parts to a bin        \n";
	cout << "3 - Remove parts from a bin   \n";
	cout << "4 - Display bin status report \n";
	cout << "5 - Quit \n";
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
 *                    getAccessMethod                   *
 * Inputs, validates, and returns user's selected       *
 * access method: 1 = by bin number & 2 = by item name  *
 ********************************************************/
int getAccessMethod()
{
	cout << "\n Select bin access method \n\n"
	     << "1 - Find bin by bin number \n"
		 << "2 - Find bin by item name \n";

	return getChoice(2);
}

/********************************************************
 *                      DisplayQty                      *
 * Allows user to add parts to an inventory bin.        *
 ********************************************************/
void displayQty(const BinManager &inventory)
{
	string name;
	int binNum = 0,
		quantity = 0;

	if (getAccessMethod() == 1)   // Find bin by number
	{
		cout << "\nEnter bin number (1 - " << BINS_IN_USE << "): ";
		binNum = getChoice(BINS_IN_USE);
		cout << "\n" << inventory.getDescription(binNum)    << "   "
		     << inventory.getQuantity(binNum)       << "\n";
	}
	else                           // Find bin by item name
	{
		cout << "\nEnter item name: ";
		cin.ignore();
		getline(cin, name);
		quantity = inventory.getQuantity(name);

		if (quantity == -1)   // Signal that item was not found
			cout << "Item " << name << " was not found. \n";
		else
			cout << name << "   "  << quantity << "\n";
	}
}

/********************************************************
 *                       addParts                       *
 * Allows user to add parts to an inventory bin.        *
 * The bin is accessed by its bin number.               *
 ********************************************************/
void addParts(BinManager &inventory, int binNum)
{
	int numToAdd = 0;

	cout << "\nCurrent status of bin #" << binNum << ": "
		 << inventory.getDescription(binNum)    << "   "
		 << inventory.getQuantity(binNum)       << "\n";

	cout << "Enter number of parts to be added: (1 - 1000): ";
	numToAdd = getChoice(1000);

	if (inventory.addParts(binNum, numToAdd))      // Add was successful
		cout << "\nNew status of bin #" << binNum << ":     "
		<< inventory.getDescription(binNum) << "   "
		<< inventory.getQuantity(binNum) << "\n";
	else
		cout << "Problem encountered. Add was not performed.\n";
}

/********************************************************
 *                       addParts                       *
 * Allows user to add parts to an inventory bin.        *
 * The bin is accessed by name of item it holds.        *
 ********************************************************/
void addParts(BinManager &inventory, string name)
{
	int quantity,
	    numToAdd = 0;

	quantity = inventory.getQuantity(name);

	if (quantity == -1)   // Signal that item was not found
		cout << "Item " << name << " was not found. \n";

	else                  // Item was found, so proceed
	{
		cout << "\nCurrent inventory: " << name << "   " << quantity << "\n";

		cout << "Enter number of parts to be added: (1 - 1000): ";
		numToAdd = getChoice(1000);

		if(inventory.addParts(name, numToAdd))      // Add was successful
			cout << "\nNew inventory:     " << name << "   "
			     << inventory.getQuantity(name)     << "\n";
		else
			cout << "Problem encountered. Add was not performed.\n";
	}
}

/********************************************************
 *                     removeParts                      *
 * Allows user to remove parts from an inventory bin.   *
 * The bin is accessed by its bin number.               *
 ********************************************************/
void removeParts(BinManager &inventory, int binNum)
{
	int quantity,
		numToRemove;

	quantity = inventory.getQuantity(binNum); 

	cout << "\nCurrent status of bin #" << binNum << ": "
		 << inventory.getDescription(binNum)      << "   "
		 << quantity  << "\n\n";

	cout << "Enter number of parts to be removed: (1 - " << quantity << "): ";
	numToRemove = getChoice(quantity);

	if(inventory.removeParts(binNum, numToRemove))      // Remove was successful
		cout << "\nNew status of bin #" << binNum << ":     "
		     << inventory.getDescription(binNum)    << "   "
		     << inventory.getQuantity(binNum)       << "\n";
	else
		cout << "Problem encountered. Remove was not performed.\n";
}

/********************************************************
 *                     removeParts                      *
 * Allows user to remove parts from an inventory bin.   *
 * The bin is accessed by name of item it holds.        *
 ********************************************************/
void removeParts(BinManager &inventory, string name)
{
	int quantity,
		numToRemove;
	
	quantity = inventory.getQuantity(name);

	if (quantity == -1)   // Signal that item was not found
		cout << "Item " << name << " was not found. \n";

	else                  // Item was found, so proceed
	{
		cout << "\nCurrent inventory: " << name << "   " << quantity << "\n";

		cout << "Enter number of parts to be removed: (1 - " << quantity << "): ";
		numToRemove = getChoice(quantity);

		if(inventory.removeParts(name, numToRemove))      // Remove was successful
			cout << "\nNew inventory:     " << name << "   "
			     << inventory.getQuantity(name)     << "\n";
		else
			cout << "Problem encountered. Remove was not performed.\n";
	}
}

/********************************************************
 *                       displayBins                    *
 * Displays a report on the contents of each bin.       *
 ********************************************************/
void displayBins(const BinManager &inventory)
{
	cout << "\nBin        Part & Qty \n"
		 << "_____________________ \n\n";

	cout << inventory.displayAllBins();
}

/* SAMPLE RUN RESULTS


Bin        Part & Qty
_____________________

1   regular pliers 25
2   N. nose pliers 5
3   screwdriver 25
4   P. head screwdriver 6
5   wrench-large 7
6   wrench-small 18
7   drill 51
8   cordless drill 16
9   hand saw 12


Inventory Control Menu

1 - Get quantity in a bin
2 - Add parts to a bin
3 - Remove parts from a bin
4 - Display bin status report
5 - Quit
1

Select bin access method

1 - Find bin by bin number
2 - Find bin by item name
2

Enter item name: drill
drill   51


Inventory Control Menu

1 - Get quantity in a bin
2 - Add parts to a bin
3 - Remove parts from a bin
4 - Display bin status report
5 - Quit
2

Select bin access method

1 - Find bin by bin number
2 - Find bin by item name
1

Enter bin number (1 - )9): 4

Current status of bin #4: P. head screwdriver   6
Enter number of parts to be added: (1 - 1000): 6

New status of bin #4:     P. head screwdriver   12


Inventory Control Menu

1 - Get quantity in a bin
2 - Add parts to a bin
3 - Remove parts from a bin
4 - Display bin status report
5 - Quit
3

Select bin access method

1 - Find bin by bin number
2 - Find bin by item name
2

Enter item name: hand saw

Current inventory: hand saw   12
Enter number of parts to be removed: (1 - 12): 2

New inventory:     hand saw   10


Inventory Control Menu

1 - Get quantity in a bin
2 - Add parts to a bin
3 - Remove parts from a bin
4 - Display bin status report
5 - Quit
5

<SCREEN CLEARS HERE>
**********************
End of Day Inventory
**********************
Bin        Part & Qty
_____________________

1   regular pliers 25
2   N. nose pliers 5
3   screwdriver 25
4   P. head screwdriver 12
5   wrench-large 7
6   wrench-small 18
7   drill 51
8   cordless drill 16
9   hand saw 10
*/