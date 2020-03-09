// Chapter 8 - Programming Challenge 16, Array of Payroll Objects
// This program uses a PayRoll class to handle company payroll functions, using
// data read from the payroll.dat file which is located in the Chapter 8 Programs
// folder, and for faculty is also in the same folder as this solution file. A 
// copy of the data file should be placed in the program's project directory. 
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class PayRoll               // Each PayRoll object handles 1 employee
{
  private:
	double hours;
	double payRate;
	
  public:
	// Default constructor
	PayRoll()
	{ payRate = hours = 0.0;}  

	// Mutators
	void  setHours(double h)
	{ hours = h;}

	void setPayRate(double p)
	{ payRate = p;}

	// Accessor
	double getGrossPay()
	{ return (hours * payRate);}
};

//********************* Client Program ************************

const int NUM_EMPLOYEES = 7;

/**************************************************************
 *                         main                               *
 * Main user function to test and use the PayRoll class       *
 **************************************************************/
int main()
{
	PayRoll employee[NUM_EMPLOYEES]; // Create an array of PayRoll objects

	double hrs,                      // Hours worked during 1 week pay period  
		   rate;                     // Hourly pay rate
	int empNum;                      // Loop control variable and array index
	ifstream data;
   
	// Open data file
	data.open("payroll.dat");
	if (!data)
		cout << "Error opening data file\n";
	else
	{
		// Input and store work information for each employee
		for (empNum = 0; empNum < NUM_EMPLOYEES; empNum++)
		{
			data >> hrs >> rate;
			employee[empNum].setHours(hrs);
			employee[empNum].setPayRate(rate);
		}
		// Close the data file
		data.close();

		// Print out gross pay for each employee
		cout << "Employee  Gross pay\n";
		cout << "========  =========\n";
		cout << fixed << showpoint << setprecision(2);

		for (empNum = 0; empNum < NUM_EMPLOYEES; empNum++)
		{
			cout << "   " << (empNum + 1) << ":     $";
			cout << setw(7) << employee[empNum].getGrossPay() << endl;
		}
	}
	return 0;
}

/* CORRECT RESULTS USING THE payroll.dat FILE

Employee  Gross pay
========  =========
   1:     $ 400.00
   2:     $ 365.75
   3:     $ 120.00
   4:     $ 213.75
   5:     $ 320.00
   6:     $ 304.00
   7:     $ 360.00
*/
