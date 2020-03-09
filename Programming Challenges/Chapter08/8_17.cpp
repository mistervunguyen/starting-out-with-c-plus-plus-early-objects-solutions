// Chapter 8 - Programming Challenge 17, Drink Machine Simulator
// This program uses a BeverageMachine class that owns and manages 
// an array of Drink structures to simulate a soft drink machine.
#include <iostream>
#include <iomanip>
#include <string>
using namespace std; 

//********************* DrinkStruct Structure Declaration ********************
struct DrinkStruct
{
	string name;
	double price;
	int    qty;

	// "Default Constructor will initialize each new instance of a
	// DrinkStruct with the following data.
	DrinkStruct()
	{
		name  = "Cola         ";
		price = 1.00;
		qty   = 20;
	}
};

const int NUM_DRINKS = 5;

//********************* MachineManager Class Declaration ********************
class MachineManager
{
  private:
	// Array of DrinkStructs
	DrinkStruct drink[NUM_DRINKS]; 

	double dailyEarnings;    // Accumulates total daily machine earnings
	double inputMoney(int);  // Private member function called by public
	                         // member function buyDrink 
	void setUpMachine();     // Private member function called by the constructor
	void dailyReport();      // Private member function called by the destructor

public:
   
   MachineManager()          // Default constructor
   {   setUpMachine();
	   dailyEarnings = 0.0;
   }
   ~MachineManager()         // Destructor
   {   dailyReport();
   }
   void displayChoices();
   double buyDrink(int);
};

/*****************************************************************
 *                  MachineManager::setUpMachine                 *
 * Sets up the machine by resetting values that differ from those*
 * set by the DrinkStruct constructor.                           *
 *****************************************************************/
void MachineManager::setUpMachine()
{  
	// Drink[0] retains the name "Cola" set by the default constructor.
	drink[1].name = "Root Beer    ";
    drink[2].name = "Orange Soda  ";
    drink[3].name = "Grape Soda   ";
    drink[4].name = "Bottled Water";
	
    drink[4].price = 1.50;
	// All other drinks retain the price 1.00 set by the default constructor.
}									          

/*****************************************************************
 *                MachineManager::displayChoices                 *
 * Displays the drink choices and their prices.                  *
 *****************************************************************/
void MachineManager::displayChoices()
{
	cout << fixed << showpoint << setprecision(2);
	cout << "**** Machine Beverage Choices **** \n\n";
	for (int item = 0; item < NUM_DRINKS; item++)
	{
		cout << setw(5) << (item + 1) << ") " << drink[item].name
			 << "   $ " << drink[item].price << endl;
	}
}

/*****************************************************************
 *                  MachineManager::buyDrink                     *
 * Handles a beverage sale.                                      *
 * Receives : Patron's beverage choice                           *
 * Returns  : Change due                                         *
 *****************************************************************/
double MachineManager::buyDrink(int choice)
{
	double money;             // Amt of money the user inserted
	double changeDue;         // Change due - may be zero
	int pos = choice - 1;     // Offset because drink 1 is in array pos. 0
   
	money = inputMoney(choice);

	if (money == 0.0)
		changeDue = money;     // Return to user program without selling a drink

	else if (drink[pos].qty == 0)
	{
		cout << "\nSorry, that selection is sold out.\n";
		cout << "Please retrieve your money from the coin return slot.\n";
		changeDue = money;
	}
	else // complete the sale
	{
		dailyEarnings += drink[pos].price;     // Add to machine earnings
		drink[pos].qty--;                      // Reduce qty remaining in machine
		changeDue = money - drink[pos].price;  // Compute change due
		cout << endl;

		if (changeDue > 0)
			cout << "Returned change: " << changeDue << endl;

		cout << "Thump, thump, thump, splat! "  // Give out the beverage
			 << "Enjoy your beverage!\n\n";
	}
	return changeDue;
}

/*****************************************************************
 *                         inputMoney                            *
 * Called by buyDrink to accept and validate money patron puts   *
 * into the machine. Money must be sufficient to purchase the    *
 * selected beverage. The machine only accepts 1.00 bills and    *
 * non-negative multiples of 25 cents.                           *
 *****************************************************************/
double MachineManager::inputMoney(int choice)
{
	bool wantDrink = true;
	double money;
	cout << "\nPlease insert sufficient money for your beverage choice \n"
		 << "(or 0 if you no longer wish to purchase a drink).\n"
		 << "Enter money now: ";
	cin  >> money;
	if (money == 0.0)
		wantDrink = false;

	while(wantDrink && money < drink[choice-1].price)
	{
		cout << "\nInsufficient money was inserted.\n" 
			 << "Please retrieve your money from the coin return slot.\n";

		cout << "Then insert enough money for your chosen beverage.\n"
			 << "(or 0 if you no longer wish to purchase a drink).\n"
			 << "Enter money now: ";
		cin  >> money;
		if (money == 0.0)
			wantDrink = false;
	}
	return money;
}
	
/*****************************************************************
 *                MachineManager::dailyReport                    *
 * Creates an end of day status report.                          *
 *****************************************************************/
void MachineManager::dailyReport()
{
	cout << "\n\n**** End of Day Report **** \n\n";
	cout << "Quantities Remaining in the Machine\n\n";

	for (int item = 0; item < NUM_DRINKS; item++)
	{
		cout << drink[item].name << setw(5) << drink[item].qty << endl;
	}
	cout << "\nDaily earnings: $" << dailyEarnings << endl;
}

// ****************************  User Program **********************
// Function prototype
int getChoice(int);

int main()
{
	MachineManager machine;              // Create a MachineManager object
	int quitChoice = NUM_DRINKS + 1;
	int choice;                          // Patron menu choice
   	
	do
	{	machine.displayChoices();        // Lists choices and prices
		cout << setw(5) << quitChoice << ") Exit \n" ; 
		choice = getChoice(quitChoice);
		if (choice != quitChoice)
			machine.buyDrink(choice);

	} while (choice != quitChoice);                        
   
	return 0;
}

/*****************************************************************
 *                         getChoice                             *
 * Accepts, validates, and returns user's drink choice           *
 *****************************************************************/
int getChoice (int quitChoice)
{
	int choice;

	cin >> choice;
	while (choice < 1 || choice > quitChoice)
	{
		cout << "Valid choices are 1 - " << quitChoice
			 << ". Please re-enter choice: ";
		cin  >> choice;
	}
	return choice;
}

/* SAMPLE RUN RESULTS

**** Machine Beverage Choices ****

1) Cola            $ 1.00
2) Root Beer       $ 1.00
3) Orange Soda     $ 1.00
4) Grape Soda      $ 1.00
5) Bottled Water   $ 1.50
6) Exit
1

Please insert sufficient money for your beverage choice
(or 0 if you no longer wish to purchase a drink).
Enter money now: 1.00

Thump, thump, thump, splat! Enjoy your beverage!

**** Machine Beverage Choices ****

1) Cola            $ 1.00
2) Root Beer       $ 1.00
3) Orange Soda     $ 1.00
4) Grape Soda      $ 1.00
5) Bottled Water   $ 1.50
6) Exit
1

Please insert sufficient money for your beverage choice
(or 0 if you no longer wish to purchase a drink).
Enter money now: 1.00

Thump, thump, thump, splat! Enjoy your beverage!

**** Machine Beverage Choices ****

1) Cola            $ 1.00
2) Root Beer       $ 1.00
3) Orange Soda     $ 1.00
4) Grape Soda      $ 1.00
5) Bottled Water   $ 1.50
6) Exit
4

Please insert sufficient money for your beverage choice
(or 0 if you no longer wish to purchase a drink).
Enter money now: 1.00

Thump, thump, thump, splat! Enjoy your beverage!

**** Machine Beverage Choices ****

1) Cola            $ 1.00
2) Root Beer       $ 1.00
3) Orange Soda     $ 1.00
4) Grape Soda      $ 1.00
5) Bottled Water   $ 1.50
6) Exit
5

Please insert sufficient money for your beverage choice
(or 0 if you no longer wish to purchase a drink).
Enter money now: 2.00

Returned change: 0.50
Thump, thump, thump, splat! Enjoy your beverage!

**** Machine Beverage Choices ****

1) Cola            $ 1.00
2) Root Beer       $ 1.00
3) Orange Soda     $ 1.00
4) Grape Soda      $ 1.00
5) Bottled Water   $ 1.50
6) Exit
6


**** End of Day Report ****

Quantities Remaining in the Machine

Cola            18
Root Beer       20
Orange Soda     20
Grape Soda      19
Bottled Water   19

Daily earnings: $4.50
*/
