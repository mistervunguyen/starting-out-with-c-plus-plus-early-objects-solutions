// Chapter 6 - Programming Challenge 19, Using Files--Hospital Report
// This program, which computes and displays patient hospital charges,
// modifies Programming Challenge 16 to write its report to a file.

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

// Function prototypes
double validateData (double, string);
double patientCharges(int, double, double, double);  // In-patient
double patientCharges(double, double);			   	 // Out-patient

int main()
{
	ofstream report;           // Create ofstream object to use an output file
	char patientType;          // I=in-patient, O=out-patient
	int  days;                 // Number of days of hospital stay
	double roomRate,           // Daily room rate
		   medication,         // Total medication charges
		   services,           // Total for tests and other services
		   totalCharges;       // Total of all charges

	// Input and validate patient type
	cout << "This program will compute patient hospital charges.\n";
	cout << "Enter I for in-patient or O for out-patient: ";
	cin  >> patientType;
	if (patientType == 'i')     // Make  i or o uppercase
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

	// Open an output file and write the billing statement to it.
	report.open("hospital.rpt");
   
	report << fixed << showpoint << setprecision(2);
	report  << "************************** \n";
	report  << "Hospital Billing Statement \n";
	report  << "************************** \n";
	if (patientType == 'I')
		report << "Room charges    $" << setw(8) << days*roomRate << endl;
	if (services > 0.0)
		report << "Lab & Services  $" << setw(8) << services << endl;
	if (medication > 0.0)
		report << "Medication      $" << setw(8) << medication << endl;
	report    << "Total charges   $" << setw(8) << totalCharges << endl;
	report << "**************************";
   
	report.close();

	// Print a message on the screen
	cout << "\nThe billing report has been written to the hospital.rpt file.\n";
   
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
	
}// end overloaded function patientCharges

/*************************************************************
 *                        patientCharge                      *
 * This function is called by main to calculate and return   *
 * total patient charges for out-patients                    *
 *************************************************************/
double patientCharges(double med, double serv)
{
	double charges = med + serv;
	return charges;
	
}// end overloaded function patientCharges
