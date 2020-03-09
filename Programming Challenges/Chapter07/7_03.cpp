// Chapter 7 - Programming Challenge 3, Widget Factory
// This program uses a Widget class to calculate the 
// time required to produce a given number of widgets.
#include <iostream>
using namespace std;

class Widget
{
  private:
	int shiftLength;         // Number of hours per factory shift
	int shiftsPerDay;        // Number of factory shifts per day
	int widgetsPerHour;      // Number of widgets factory produces per hour

  public:
	// Constructor with default values
	Widget(int numShifts = 2, int perHr = 10, int numHrs = 8)  
	{ shiftsPerDay = numShifts; widgetsPerHour = perHr; shiftLength = numHrs;}
   
	double daysToProduce(int);
};

/*********************************************************
 *                Widget::daysToProduce                  *
 *********************************************************/
double Widget::daysToProduce(int numWidgets)
{
	double numDays = static_cast<double>(numWidgets) / 
                    (shiftLength * shiftsPerDay * widgetsPerHour);
	return numDays;
}

//************************* Client Program *****************
int main()
{
	int    howMany;      // Number of widgets to be produced
	double days;         // Number of days needed to produce the widgets
	Widget factory;      // Create a Widget object named factory

	cout << "This program will calculate widget production time.\n";

	// Input and validate the number of widgets
	cout << "How many widgets are on order? ";
	cin  >> howMany;
	while (howMany < 0)
	{	cout << "Number must be 0 or greater.  Please re-enter: ";
		cin  >> howMany;
	}

	// Call the Widget object's daysToProduce function to find out how
	// long it will take to produce the desired number of widgets
	days = factory.daysToProduce(howMany);

	// Display the results
	cout << "\nIt will take " << days << " days to produce ";
	cout << howMany << " widgets.\n";
	return 0;
}

/* SAMPLE RUN RESULTS

This program will calculate widget production time.
How many widgets are on order? 300

It will take 1.875 days to produce 300 widgets.
*/
