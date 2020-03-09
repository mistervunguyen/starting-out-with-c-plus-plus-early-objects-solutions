// Chapter 6 - Programming Challenge 16, Overloaded Hospital
// This program computes and displays patient hospital charges.
// It uses a generalized function to validate all numeric data
// values, as well as a pair of overloaded functions.
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Function prototypes
double validateData (double, string);
double patientCharges(int, double, double, double);  // In-patient
double patientCharges(double, double);			   	 // Out-patient

int main()
{
	char patientType;             // I=in-patient, O=out-patient
	int  days;                    // Number of days of hospital stay
	double roomRate,              // Daily room rate
		   medication,            // Total medication charges
		   services,              // Total for tests and other services
		   totalCharges;          // Total of all charges

	// Input and validate patient type
	cout << "This program will compute patient hospital charges.\n";
	cout << "Enter I for in-patient or O for out-patient: ";
	cin  >> patientType;
	if (patientType == 'i')        // Make  i or o uppercase
		patientType = 'I';
	else if (patientType == 'o')
		patientType = 'O';

	while (patientType != 'I' && patientType != 'O') 
	{
		cout << "Please enter I or O: ";
		cin  >> patientType;
		if (patientType == 'i')     // Make  i or o uppercase
			patientType = 'I';
		else if (patientType == 'o')
			patientType = 'O';
  	} 
	cout << endl;

	// Input and validate data relevant to in-patients
	if (patientType == 'I') 
  	{
		cout << "Number of days in the hospital: ";
     	cin  >> days;
		days = static_cast<int>(validateData(days, "days in hospital"));
		
		cout << "Daily room rate: $";
		cin  >> roomRate;
		roomRate = validateData(roomRate, "daily room rate");
	}
   
	// Input and validate data relevant to all patients
	cout << "Lab fees and other service charges: $";
	cin  >> services;
	services = validateData(services, "lab fees and other service charges");

	cout << "Medication charges: $";
	cin  >> medication;
	medication = validateData(medication, "medication charges");

  	// Call correct patientCharges function to return total charges
	if (patientType == 'I')
		totalCharges = patientCharges(days, roomRate, medication, services);
	else
		totalCharges = patientCharges(medication, services);

	// Display the billing statment
	cout << fixed << showpoint << setprecision(2) << endl;
	cout << "************************** \n";
	cout << "Hospital Billing Statement \n";
	cout << "************************** \n";
	if (patientType == 'I')
		cout << "Room charges    $" << setw(8) << days*roomRate << endl;
	if (services > 0.0)
		cout << "Lab & Services  $" << setw(8) << services << endl;
	if (medication > 0.0)
		cout << "Medication      $" << setw(8) << medication << endl;
	cout    << "Total charges   $" << setw(8) << totalCharges << endl;
	cout << "**************************\n";
   
	return 0;
}// end main function

/******************************************************
 *                     validateData                   *
 * This function is called by main to ensure that no  *
 * negative values are input                          *
 ******************************************************/
 double validateData (double input, string prompt)
 {
	 while (input < 0.0)
	 {
		 cout << "This value cannot be less than 0. \n";
		 cout << "Please re-enter " << prompt << ": ";
		 cin  >> input;
	 }
	 return input;
	 
 }// end validateData Function

/*************************************************************
 *                        patientCharge                      *
 * This function is called by main to calculate and return   *
 * total patient charges for in-patients                     *
 *************************************************************/
double patientCharges(int days, double rate, double med, double serv)
{
	double charges = days * rate + med + serv;
	return charges;
	
}// end overload function patientCharges

/*************************************************************
 *                        patientCharge                      *
 * This function is called by main to calculate and return   *
 * total patient charges for out-patients                    *
 *************************************************************/
double patientCharges(double med, double serv)
{
	double charges = med + serv;
	return charges;
	
}// end overload function patientCharges

/* SAMPLE RUN RESULTS 

This program will compute patient hospital charges.
Enter I for in-patient or O for out-patient: i

Number of days in the hospital: 2
Daily room rate: $640
Lab fees and other service charges: $720
Medication charges: $210

**************************
Hospital Billing Statement
**************************
Room charges    $ 1280.00
Lab & Services  $  720.00
Medication      $  210.00
Total charges   $ 2210.00
**************************
*/