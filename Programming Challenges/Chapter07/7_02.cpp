// Chapter 7 - Programming Challenge 2, Heading
// This program implements and tests a Heading class that produces 
// headings in different formats. Student program may test their
// Heading class with different code.
#include <iostream>
#include <string>
using namespace std;

class Heading
{
private:
	string company;        // Holds the company name
	string report;         // Holds the report name
public:
	// Constructor
	Heading(string c, string r);
  
	// Set functions
	void setCompany(string c);
	void setReport(string r);

	// Heading display functions
	void oneLine();
	void boxed();
};

/*******************************************************
 *                Heading::Heading                     *
 * If arguments are passed to this constructor, these  *
 * values are used to initialize the class variables.  *
 * Otherwise, default values are used.                 *
 *******************************************************/
Heading::Heading(string c = "ABC Industries", string r = "Report")
{
	company = c;
	report = r;
}

/******************************************************************
 *                        Heading::setCompany                     *
 * This member function sets company name to the string passed in.*
 ******************************************************************/
void Heading::setCompany(string c)
{  
	company = c;
}

/****************************************************************
 *                     Heading::setReport                       *
 *This member function sets report name to the string passed in.*
 ****************************************************************/
void Heading::setReport(string r)
{  
	report = r;
}

/**************************************************************
 *                         Heading::oneLine                   *
 * This member function prints a one line heading.            *
 **************************************************************/
void Heading::oneLine()
{
	int printLength = company.length() + 1 + report.length();
	int leadSpaces = (80 - printLength) / 2;

	for (int pos = 1; pos <= leadSpaces; pos++)
		cout << ' ';        // Print leading spaces to center the string
	cout << company << " " << report << endl << endl;
}

/*********************************************************
 *                     Heading::boxed                    *
 * This member function prints a two line boxed heading. *
 *********************************************************/
void Heading::boxed()
{
	int coLeadSpaces  = (80 - company.length()) / 2;
	int rptLeadSpaces = (80 - report.length()) / 2;

	cout << "                    "
		 << "****************************************\n";

	for (int pos = 1; pos <= coLeadSpaces; pos++)   // Center the string
		cout << ' '; 
	cout << company << endl;                        // Print company name

	for (int pos = 1; pos <= rptLeadSpaces; pos++)  // Center the string
		cout << ' ';  
	cout << report  << endl;                        // Print report name

	cout << "                    "
		 << "****************************************\n\n";
}

/*********************************************************
 *                           main                        *
 *********************************************************/

int main()
{
	// Create a Heading object using defaults and display it in 1-line format
	Heading hdg;                    
	hdg.oneLine();
	cout << endl;

	// Call functions to reset hdg values and then display it in boxed format
	hdg.setCompany("Joe's Bakery");  
	hdg.setReport("Inventory");
	hdg.boxed();                     
	cout << endl;

    // Create a second Heading object with values passed to the constructor
	// Display this heading in boxed format                                
	Heading hdg2("Fred's Flea Market", "Sales");    
	hdg2.boxed();                   

	return 0;
}

