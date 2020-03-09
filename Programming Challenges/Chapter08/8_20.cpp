// Chapter 8 - Programming Challenge 20, Theatre Ticket Sales
// This program creates and uses a TicketManager class to handle ticket sales
// for a small theater with a single one-night show. It uses data read from the
// SeatAvailability.dat and SeatPrices.dat files, which are located in the 
// Chapter 8 Programs folder, and for faculty are also in the same folder as this
// solution file. A copy of the data files should be placed in the program's 
// project directory. 

// NOTE: THIS CHALLENGE ASKED STUDENTS TO DO SOMETHING NOT YET COVERED IN CHAPTER 8.
// It asked them to create and return a string that contains numeric values. 
// Students should be given the numToString function included in this solution and
// shown how to use it. 

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

const int NUM_ROWS = 15,
          ROW_SIZE = 30;
                    
class TicketManager
{
  private:
	struct SeatStructure
	{	char   status;               // '#' = available; '*' = sold
		double price;

		SeatStructure()              // Default constructor
		{	status = '#';
			price = 0.0;
		}
	};
	SeatStructure seat[NUM_ROWS][ROW_SIZE];

	int seatsSold;
	double totalRevenue;

	string printTickets(int, int, int);
   
  public:
	TicketManager();             // Constructor
	~TicketManager();            // Destructor
	string displaySeats();
	string requestTickets (int, int, int, bool&);
	string purchaseTickets(int, int, int);
	string displaySalesReport();
	string numToString(double num) const;
};

// TicketManager Class Function Implementation Section

/***************************************************************
 *                        TicketManager                        *
 * Class constructor that reads seat information in from files.*
 * and uses it to initialize the elements of the seat array.   *
 * It also computes the number of seats sold so far and the    *
 * total revenue to date.                                      *
 ***************************************************************/
TicketManager::TicketManager()
{
	double rowPrice;
	ifstream availFile, priceFile;
	
	// Open the data files for input
	availFile.open("SeatAvailability.dat");
	if (!availFile)
		cout << "ERROR OPENING SEAT AVAILABILLITY DATA FILE \n";
    
	priceFile.open("SeatPrices.dat");
	if (!priceFile)
		cout << "ERROR OPENING PRICES DATA FILE \n"; 

	seatsSold = 0;
	totalRevenue = 0.0;

	for (int row = 0; row < NUM_ROWS; row++)
	{
		// Read in the price for this row
		priceFile >> rowPrice;

		// For each seat in the row                Do the following:
		for (int col = 0; col < ROW_SIZE; col++)
		{
			availFile >> seat[row][col].status;    // Read in the seat's status
			seat[row][col].price = rowPrice;       // Set the seat's price
			if (seat[row][col].status == '*')      // If seat has been sold,
			{
				seatsSold++;                       // add to seatsSold and totalRevenue
				totalRevenue += rowPrice;
			}
		}
	}
	// Close the files
	availFile.close(); 
	priceFile.close();
}
/***************************************************************
 *                       ~TicketManager                        *
 * Class destructor that writes seat availability information  *
 * back out to the file.                                       *
 ***************************************************************/
TicketManager::~TicketManager()
{
	ofstream availFile;

	// Open the "avail" data file for output
	availFile.open("SeatAvailability.dat");
	if (!availFile)
		cout << "ERROR OPENING SEAT AVAILABILLITY DATA FILE \n";   

	// Write each seat's status (available or taken) out to the file
	for (int row = 0; row < NUM_ROWS; row++)
	{	for (int col = 0; col < ROW_SIZE; col++)
			availFile << seat[row][col].status;
		availFile << endl;
	}
	// Close the file
	availFile.close();
}

/******************************************************
 *                        displaySeats                *
 * Creates and returns a string that displays a chart *
 * showing sold and available seats                   *
 ******************************************************/
string TicketManager::displaySeats()
{
	string chart = "\n\n                   Seats \n\n";
	chart +=  "        123456789012345678901234567890\n";

	for(int row = 0; row < NUM_ROWS; row++)
	{
		chart += "\nRow ";
		if (row < 9)
		{
			chart += static_cast<char>('1' + row);
			chart += "   ";
		}
		else
		{
			chart += "1";
			chart += static_cast<char>('1' + row - 10);
			chart += "  ";
		}	
	
		for (int col = 0; col < ROW_SIZE; col++)
		{	
			chart += seat[row][col].status;
		}
	}
        
	// Add the legend
	chart += "\n\n\n\tLegend:     *  =  Sold";
	chart += "\n                    #  =  Available";

    return chart;
} // end displaySeats

/**************************************************************
 *                       requestTickets                       *
 * Returns a string holding an invoice if the requested seats *
 * are available. Returns an appropriate message if the       *
 * request is invalid or the seats are not available.         *
 **************************************************************/
string TicketManager::requestTickets (int numSeatsRequested, int requestedRow, int startSeat, bool & allOK)
{
	int row = requestedRow -1,             // Offset user request because array rows 
		firstSeatWanted = startSeat - 1,   // and columns begin with 0, rather than 1.
		lastSeatWanted = firstSeatWanted + numSeatsRequested -1;
		
	allOK = true;
		
	string returnString;
	double pricePerSeat, totalPrice;

	if (row < 0 || row >= NUM_ROWS )
	{ 
		returnString = "\nIllegal row request. Rows are numbered 1 to 15.";
		allOK = false;
	}
	else if (firstSeatWanted < 0 || lastSeatWanted >= ROW_SIZE)
	{
		returnString = strcat("\nOne or more of the seats you have requested do not exist.\n",
			                 "Seats in each row are numbered 1 - 30.\n\n");
		allOK = false;
	}
	else
	{
		for (int seatWanted = firstSeatWanted; seatWanted <= lastSeatWanted; seatWanted++)
		{
			if (seat[row][seatWanted].status == '*')
			{
				returnString = "\nOne or more of the seats you have requested are already sold.\n";
				allOK = false;
			}
		}
	}

	// If we got this far with allOK still true, all requested seats exist and are available for purchase.
	if (allOK)
	{   
		//pricePerSeat = static_cast<int>(seat[row][firstSeatWanted].price);
		pricePerSeat = seat[row][firstSeatWanted].price;
		totalPrice = pricePerSeat * numSeatsRequested;
				
		returnString = "\nThe seats you have requested are available for purchase.\n";
		returnString += "The total purchase price is ";
		
		returnString += numToString(numSeatsRequested);
		returnString += " seats X $";
		returnString += numToString(pricePerSeat);
		returnString += " = $";
		returnString += numToString(totalPrice);
	}
	return returnString;
}

/************************************************************************
 *                               purchaseTickets                        *
 * Handles ticket purchases for a previousy validated ticket request.   *  
 ************************************************************************/
string TicketManager::purchaseTickets(int numSeats, int requestedRow, int startSeat)
{
	int row = requestedRow -1,             // Offset user request because array rows 
		firstSeat = startSeat - 1,         // and columns begin with 0, rather than 1.
		lastSeat = firstSeat + numSeats -1;

	double pricePerSeat = seat[row][firstSeat].price;
	double totalPrice = pricePerSeat * numSeats;
	double amtPaid,
		   changeDue;
	
	string tickets;

	// Collect money
	cout << "\nThe price for the requested tickets is $ " << totalPrice << endl
		 << "Please input amount paid: $";
	cin  >> amtPaid;

	if (amtPaid >= totalPrice)   // If payment is sufficient, sell the tickets
	{
		// Mark these seats taken
		for (int purchase = firstSeat; purchase <= lastSeat; purchase++)
			seat[row][purchase].status = '*';

		// Add to seats sold and revenue accumulators
		seatsSold += numSeats;
		totalRevenue += numSeats * pricePerSeat;

		// Call printTickets to create a string holding the actual tickets 
		// Starting row and seat numbering should be from 1 (not 0)
		tickets = printTickets(requestedRow, firstSeat+1, lastSeat+1);

		// Display a purchase summary for the patron
		changeDue = amtPaid - totalPrice;
		cout << "\n\nTickets purchased : "  << numSeats    << endl 
			 <<     "Payment           : $" << setw(6) << amtPaid     << endl
			 <<     "Total ticket price: $" << setw(6) << totalPrice  << endl 
			 <<     "Change due        : $" << setw(6) << changeDue   << endl << endl;
	}   
	else
	{
		tickets = "Insufficient payment. \n";
		tickets += "The sale has been cancelled and your money is being returned.\n\n";
	}
	return tickets;
}

/**************************************************************
 *                       printTickets                         *
 * Creates a string holding one ticket for each seat sold.    *
 **************************************************************/
string TicketManager::printTickets(int rowNum, int firstSeatNum, int lastSeatNum)
{
	double seatPrice = seat[rowNum-1][firstSeatNum-1].price;
	string price = numToString(seatPrice);
	
	string tickets = "";

	for (int seat = firstSeatNum; seat <= lastSeatNum; seat++)
	{
		tickets += "\n\n\n***********************************************\n";
		tickets += "          Little Theater Production            \n\n";
		tickets += "          Row ";
		tickets += numToString(rowNum);
		tickets += " ~ Seat ";
		tickets += numToString(seat);
		tickets += "\n\n          Price: $ "; 
		tickets += numToString(seatPrice);
		tickets += "\n***********************************************\n";
	}
	return tickets;
}

/**************************************************************
 *                    displaySalesReport                      *
 * Creates and returns a string holding a ticket sales report.*                                 *
 **************************************************************/
string TicketManager::displaySalesReport()
{
	string report = "\n\nLittle Theater Sales Report\n";
    report += "___________________________\n\n";
    report += "Seats sold:            " ;
	report += numToString(seatsSold);
	report += "\nSeats available:       ";
	report += numToString(NUM_ROWS * ROW_SIZE - seatsSold);
	report += "\nTotal revenue to date: $" ;
	report += numToString(totalRevenue);
	report += "\n\n\n";
	
	return report;
}

/*********************************************************
 *                         numToString                   *
 * This function, which converts and returns a number in *
 * string form, works for both integer and floating-point*
 * value. It uses an ostringstream object, which requires*
 * the sstream header file.                              *
 ********************************************************/
string TicketManager::numToString(double num) const
{
	ostringstream ss;
	ss << num;
	return ss.str();
}


// ****************** Client Program That Uses the Class ***************

// Function prototypes
void displayMenu();
int  getChoice(int);
void getUserRequest(int&, int&, int&);

const int MAX_MENU_CHOICE = 4;
int main()
{
	TicketManager boxOffice;     // Create a TicketManager object.
                                 // The constructor will correctly initialize each
                                 // seat with its price and availability status.

	int  choice,                 // User's menu choice           
         numSeats,               // Number of seats wanted
         row,                    // Desired row
         startSeat;              // Desired starting seat number

	string message;
	bool  ticketRequestOK = true; // Are all requested tickets available for sale?
	char  buy;                    // Buy these tickets? Y or N.

	// Set print formats
	cout << fixed << showpoint << setprecision(2);  

	do
	{
		displayMenu();
		choice = getChoice(MAX_MENU_CHOICE);
		
		switch(choice)
		{
		case 1:
			cout << boxOffice.displaySeats();                                  // Class function call
			break;
		case 2:
			getUserRequest(numSeats, row, startSeat);                          // Client module to get user input
				
			cout << boxOffice.requestTickets(numSeats, row, startSeat, ticketRequestOK);  // Class function call
				
			if (ticketRequestOK)
			{
				cout << "\nDo you wish to purchase these tickets (Y/N)? ";
				cin  >> buy;
				if (toupper(buy) == 'Y')
					cout << boxOffice.purchaseTickets(numSeats, row, startSeat);       // Class function call
			}
			break;
		case 3:
			cout << boxOffice.displaySalesReport();                                    // Class function call
	
		}// end switch
	} while (choice != MAX_MENU_CHOICE); 

	return 0;
}// end main

/*************************************************************
 *                      displayMenu                          *
 * Displays the menu of program options                      *
 *************************************************************/
void displayMenu()
{
	// Display menu of choices
	cout << "\n\n\n\t\tC++ Theatre" << endl << endl;
	cout << "\n\t1.  View Available Seats";
	cout << "\n\t2.  Request Tickets";
	cout << "\n\t3.  Display Theater Sales Report";
	cout << "\n\t4.  Exit the Program\n";
}

/**************************************************************
 *                          getChoice                         *
 * Accepts, validates, and returns a user choice.             *
 **************************************************************/
int getChoice(int max)
{
	int choice;

	// Get and validate user's choice
	cin  >> choice;
	while (choice < 1 || choice > max)
	{	cout << "Choice must be between 1 and " <<  max
			 << ". Please re-enter: ";
		cin  >> choice;
	}
	//Return the choice
	return choice;
}

/**************************************************************
 *                      getUserRequest                        *
 * Accepts, validates, and returns user's seat selection.     *
 **************************************************************/
void getUserRequest(int &numSeats, int &row, int &startSeat)
{
	cout << "Number of seats desired (1 - 30): ";
	numSeats = getChoice(30);

	cout << "Desired row (1-15): ";
	row = getChoice(15);

	cout << "Desired starting seat number in the row (1 - 30): ";
	startSeat = getChoice(30);
}
