// Chapter 7 - Programming Challenge 11, Monthly Budget
// This program uses one MontlyBudget structure to store budget figures and
// a second one to store actual expenditures. After using a screen form to
// obtain the user's actual expenitures, the two sets of figures are compared.
// NOTE: This is a solution for a Windows based system. 

#include <iostream>
#include <iomanip>
#include <windows.h>      // Needed to set cursor positions
using namespace std;

struct MonthlyBudget
{  double housing,
          utilities,
          household,
          transportation,
          food,
          medical,
          insurance,
          entertainment,
          clothing,
          misc,
		  total;
          
   // Constructor with default values when arguments are not provided
   MonthlyBudget(double rent  = 0.0,  double util = 0.0,  double hh    = 0.0, 
                 double trans = 0.0,  double fd   = 0.0,  double med   = 0.0, 
                 double insur = 0.0,  double fun  = 0.0,  double cloth = 0.0,
                 double mis   = 0.0,  double tot  = 0.0)
   {  housing = rent;
      utilities = util;
      household = hh;
      transportation = trans;
      food = fd;
      medical = med;
      insurance = insur;
      entertainment = fun;
      clothing = cloth;
      misc = mis;
	  total = tot;
   }
};

// Function prototypes
void displayBudget(MonthlyBudget&);
void getAmtSpent(HANDLE, MonthlyBudget&);
void compareExpenses(HANDLE, const MonthlyBudget&, const MonthlyBudget&);
      
int main()
{
	// Create a HANDLE object for screen cursor positioning
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
 
	// Create a MonthlyBudget structure initialized with actual budget figures
	MonthlyBudget budget(500, 150, 65, 50, 250, 30, 100, 150, 75, 50);

	// Create a MonthlyBudget structure to hold actual expenditures
	MonthlyBudget spent;
	
	// Call displayBudget function to display the budgeted amount on the screen
	displayBudget(budget);

	// Call getExpenses function to input and store actual expenditures
	getAmtSpent(screen, spent);

	// Call compareExpenses function to compare actual expenditures to budget
	compareExpenses(screen, budget, spent);

	return 0;
}

/**********************************************************
 *                    displayBudget                       *
 * This function displays the monthly budgeted amount in  *
 * each category as well as accumulating and storing the  *
 * total budget amount.                                   *   
 **********************************************************/
void displayBudget(MonthlyBudget &budget)
{
	budget.total = 
		budget.housing + budget.utilities + budget.household + 
		budget.transportation + budget.food + budget.medical +
		budget.insurance + budget.entertainment + budget.clothing +
		budget.misc; 
		
	cout << "  Budgeted Amounts \n";
	cout << "==================== \n\n";
	cout << "Housing        $" << setw(4)  << budget.housing << endl;
	cout << "Utilities      $" << setw(4)  << budget.utilities << endl;
	cout << "Household      $" << setw(4)  << budget.household << endl;
	cout << "Transportation $" << setw(4)  << budget.transportation << endl;
	cout << "Food           $" << setw(4)  << budget.food << endl;
	cout << "Medical        $" << setw(4)  << budget.medical << endl;
	cout << "Insurance      $" << setw(4)  << budget.insurance << endl;
	cout << "Entertainment  $" << setw(4)  << budget.entertainment << endl;
	cout << "Clothing       $" << setw(4)  << budget.clothing << endl;
	cout << "Miscellaneous  $" << setw(4)  << budget.misc << endl;
	cout << "==================== \n";
	cout << "Total          $" << setw(4) << budget.total << endl;
	
}

/**************************************************************
 *                         getAmtSpent                        *
 * This function stores the entered values for actual monthly *
 * expenditures in each budget category. The cursor is        *
 * appropriately positioned before each input is accepted.    *
 **************************************************************/
void getAmtSpent(HANDLE screen, MonthlyBudget &spent)
{
	COORD pos = {24, 0};    
	SetConsoleCursorPosition(screen, pos);
	cout << "Spent" << endl; 
	
	pos.X = 24;          // Reset column to 24
	pos.Y++;             // Move down to the next row 
	SetConsoleCursorPosition(screen, pos);
	cout << "=====" << endl;
	
	pos.X = 25;          // Set column to 25
	(pos.Y)+=2;          // Move down 2 rows 
	SetConsoleCursorPosition(screen, pos);
	cin  >> spent.housing;

	pos.X = 25;          // Reset column to 25
	pos.Y++;             // Move down to the next row 
	SetConsoleCursorPosition(screen, pos);
	cin  >> spent.utilities;

	pos.X = 25;          // Reset column to 25
	pos.Y++;             // Move down to the next row 
	SetConsoleCursorPosition(screen, pos);
	cin  >> spent.household;

	pos.X = 25;          // Reset column to 25
	pos.Y++;             // Move down to the next row 
	SetConsoleCursorPosition(screen, pos);
	cin  >> spent.transportation;

	pos.X = 25;          // Reset column to 25
	pos.Y++;             // Move down to the next row 
	SetConsoleCursorPosition(screen, pos);
	cin  >> spent.food;

	pos.X = 25;          // Reset column to 25
	pos.Y++;             // Move down to the next row 
	SetConsoleCursorPosition(screen, pos);
	cin  >> spent.medical;

	pos.X = 25;          // Reset column to 25
	pos.Y++;             // Move down to the next row 
	SetConsoleCursorPosition(screen, pos);
	cin  >> spent.insurance;

	pos.X = 25;          // Reset column to 25
	pos.Y++;             // Move down to the next row 
	SetConsoleCursorPosition(screen, pos);
	cin  >> spent.entertainment;

	pos.X = 25;          // Reset column to 25
	pos.Y++;             // Move down to the next row 
	SetConsoleCursorPosition(screen, pos);
	cin  >> spent.clothing;

	pos.X = 25;          // Reset column to 25
	pos.Y++;             // Move down to the next row 
	SetConsoleCursorPosition(screen, pos);
	cin  >> spent.misc;
	
	// Compute total amount spent
	spent.total = spent.housing + spent.utilities + spent.household +
		          spent.transportation + spent.food + spent.medical +
				  spent.insurance + spent.entertainment + spent.clothing +
				  spent.misc; 

	pos.X = 24;          // Set column to 24
	pos.Y++;             // Move down to the next row 
	SetConsoleCursorPosition(screen, pos);
	cout << "=====" << endl;

	pos.X = 24;          // Reset column to 24
	pos.Y++;             // Move down to the next row 
	SetConsoleCursorPosition(screen, pos);
	cout << "$" << setw(4) << spent.total << endl;
}          

/***********************************************************
 *                   compareExpenses                       *
 * This function compares actual expenditures to budgeted  *
 * amounts in each budget category.                        *
 ***********************************************************/
void compareExpenses(HANDLE screen, const MonthlyBudget &budget, const MonthlyBudget &spent)
{
	COORD pos = {32, 0};    
	SetConsoleCursorPosition(screen, pos);
	cout << "Diff." << endl; 
	
	pos.X = 32;          // Reset column to 32
	pos.Y++;             // Move down to the next row 
	SetConsoleCursorPosition(screen, pos);
	cout << "=====" << endl;
	
	pos.X = 32;          // Reset column to 32
	(pos.Y)+=2;          // Move down 2 rows 
	SetConsoleCursorPosition(screen, pos);
	cout << "$" << setw(4) << (spent.housing - budget.housing) << endl;

	pos.X = 32;          // Reset column to 32
	(pos.Y)++;           // Move down a row
	SetConsoleCursorPosition(screen, pos);
	cout << "$" << setw(4) << (spent.utilities - budget.utilities) << endl;

    pos.X = 32;          // Reset column to 32
	(pos.Y)++;           // Move down a row
	SetConsoleCursorPosition(screen, pos);
	cout << "$" << setw(4) << (spent.household - budget.household) << endl;

    pos.X = 32;          // Reset column to 32
	(pos.Y)++;           // Move down a row
	SetConsoleCursorPosition(screen, pos);
	cout << "$" << setw(4) << (spent.transportation - budget.transportation) << endl;

    pos.X = 32;          // Reset column to 32
	(pos.Y)++;           // Move down a row
	SetConsoleCursorPosition(screen, pos);
	cout << "$" << setw(4) << (spent.food - budget.food) << endl;

    pos.X = 32;          // Reset column to 32
	(pos.Y)++;           // Move down a row
	SetConsoleCursorPosition(screen, pos);
	cout << "$" << setw(4) << (spent.medical - budget.medical) << endl;

    pos.X = 32;          // Reset column to 32
	(pos.Y)++;           // Move down a row
	SetConsoleCursorPosition(screen, pos);
	cout << "$" << setw(4) << (spent.insurance - budget.insurance) << endl;

    pos.X = 32;          // Reset column to 32
	(pos.Y)++;           // Move down a row
	SetConsoleCursorPosition(screen, pos);
	cout << "$" << setw(4) << (spent.entertainment - budget.entertainment) << endl;

    pos.X = 32;          // Reset column to 32
	(pos.Y)++;           // Move down a row
	SetConsoleCursorPosition(screen, pos);
	cout << "$" << setw(4) << (spent.clothing - budget.clothing) << endl;

    pos.X = 32;          // Reset column to 32
	(pos.Y)++;           // Move down a row
	SetConsoleCursorPosition(screen, pos);
	cout << "$" << setw(4) << (spent.misc - budget.misc) << endl;

    pos.X = 32;          // Reset column to 32
	(pos.Y)++;           // Move down a row
	SetConsoleCursorPosition(screen, pos);
	cout << "=====" << endl; 
	
    pos.X = 32;          // Reset column to 32
	(pos.Y)++;           // Move down a row
	SetConsoleCursorPosition(screen, pos);
	cout << "$" << setw(4) << (spent.total - budget.total) << endl;

	pos.X = 0;           // Set column to 0
	(pos.Y)++;           // Move down 2 rows
	SetConsoleCursorPosition(screen, pos);
	if (budget.total > spent.total)
		cout << "\nCongratulations! You were $" << (budget.total - spent.total)
		     << " under budget this month.\n";
	else
		cout << "\nYou went $" << (spent.total - budget.total) << " over your budget this month.\n"; 
}

/* SAMPLE RUN RESULTS

Budgeted Amounts        Spent   Diff.
====================    =====   =====

Housing        $ 500     500    $   0
Utilities      $ 150     117    $ -33
Household      $  65     88     $  23
Transportation $  50     70     $  20
Food           $ 250     230    $ -20
Medical        $  30     0      $ -30
Insurance      $ 100     100    $   0
Entertainment  $ 150     125    $ -25
Clothing       $  75     110    $  35
Miscellaneous  $  50     65     $  15
====================    =====   =====
Total          $1420    $1405   $ -15

Congratulations! You were $15 under budget this month.
*/