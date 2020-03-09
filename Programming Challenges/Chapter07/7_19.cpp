// Chapter 7 - Programming Challenge 19, Patient Fees
// This is the application program that uses the Patient,
// Surgery, and Pharmacy classes.

// Files needed for this project:
// 7_19.cpp (this file)
// PatientAccount.h   -- contains the PatientAccount class declaration
// PatientAccount.cpp -- contains the PatientAccount function definitions
// Surgery.h          -- contains the Surgery class declaration
// Surgery.cpp        -- contains the Surgery function definitions
// Pharmacy.h         -- contains the Pharmacy class declaration
// Pharmacy.cpp       -- contains the Pharmacy function definitions
#include <iostream>
#include <iomanip>
#include <string>
#include "PatientAccount.h"
#include "Surgery.h"
#include "Pharmacy.h"
using namespace std;

// Function prototypes
void displaySurgeryTypes();
void displayMedicationTypes();
void displayCharges(PatientAccount, Surgery, Pharmacy);

int main()
{
	PatientAccount patient1;       // Create a PatientAccount object
	Surgery  surgery;              // Create a Surgery object
	Pharmacy pharmacy;             // Create a Pharmacy object
	int surtype, medtype;
	char hadSurgery,               // Did patient have surgery (Y/N)? 
		 hadMedicine;              // Did patient receive medicine (Y/N)? 

	cout << "*** Patient Release Statement ***\n\n";
	
	patient1.setDays();            // Sets length of patient stay and
	                               // adds daily room rate onto charges

	// Get and validate surgery data
	cout << "\nDid the patient have surgery (Y/N)? ";
	cin  >> hadSurgery;
	if (toupper(hadSurgery) == 'Y')
	{   
		displaySurgeryTypes();
		cin  >> surtype;
		
		while (surtype < 1 || surtype > 5)
		{	cout << "Legal values are 1-5.  Please re-enter surgery type: ";
			cin  >> surtype;
		}
		surgery.updateAccount(patient1, surtype);
	}

	// Get and validate medication data
	cout << "\nDid the patient receive medication (Y/N)? ";
	cin  >> hadMedicine;

	while (toupper(hadMedicine) == 'Y')
	{ 
		displayMedicationTypes();
		cin >> medtype;
		
		while (medtype < 1 || medtype > 5)
		{	cout << "Legal values are 1-5.  Please re-enter medicine type: ";
			cin  >> medtype;
		}
		pharmacy.updateAccount(patient1, medtype);

		cout << "\nDid the patient receive other medication (Y/N)? ";
		cin  >> hadMedicine;
	}

	// Display the charges
	displayCharges(patient1, surgery, pharmacy);

	return 0;
	
}// End main function

/*******************************************************************
 *                       displaySurgeryTypes                       *
 * This function displays a menu of surgery types and costs.       * 
 * Students may make up their own data.                            *
 *******************************************************************/
void displaySurgeryTypes()
{ 
	string sTypes;
	
	sTypes = "\nPlease enter surgery type \n\n";
	sTypes += "     1 - Minor surgery    $   600 \n";
    sTypes += "     2 - Eye surgery      $ 1,250 \n";
	sTypes += "     3 - Knee replacement $ 6,000 \n";
	sTypes += "     4 - Heart surgery    $12,000 \n";
	sTypes += "     5 - Brain surgery    $28,000 \n\n";
		 
    cout << sTypes;
	
}// end displaySurgeryTypes function

/*******************************************************************
 *                     displayMedicationTypes                      *
 * This function displays a menu of medication types and costs.    *
 * Students may make up their own data.                            *
 *******************************************************************/
void displayMedicationTypes()
{ 
	string medTypes;
	
	medTypes = "\nPlease enter medication type \n\n";
	medTypes += "     1 - Asprin             $ 10 \n";
    medTypes += "     2 - Sleeping pills     $ 20 \n";
	medTypes += "     3 - Pain pills         $ 50 \n";
	medTypes += "     4 - Local anesthetic   $ 75 \n";
	medTypes += "     5 - General anesthetic $300 \n\n";
		 
    cout << medTypes;
	
}// end displayMedicationTypes function

/***************************************************************
 *                       displayCharges                        *
 ***************************************************************/
void displayCharges(PatientAccount patient, Surgery surgery, Pharmacy pharmacy)
{
	int days = patient.getDays();
	double hospitalRate = patient.getDailyRate();
	double surgeryCharge = surgery.getSurgeryCharge();
	double pharmacyCharge = pharmacy.getPharmacyCharge();
	
	cout << fixed << showpoint << setprecision(2);
	cout << "\n        Patient Charges \n\n";
	
	if(days > 0)
	    cout << "Hospital: " << days << " days @ $" << hospitalRate  
		     << " = $" << setw(8) << days * hospitalRate << endl;
	
	if(surgeryCharge > 0.0)
		cout << "Surgery charge :             $" 
		<< setw(8) << surgeryCharge << endl;
	
	if(pharmacyCharge > 0.0)
		cout << "Pharmacy charge:             $" 
		<< setw(8) << pharmacyCharge << endl;
	
	cout << "                             _________ \n"
	     << "Total charges  :             $"  
		 << setw(8) << patient.getTotalCharges() << endl;
	
}// end displayCharges function

/* SAMPLE RUN RESULTS

*** Patient Release Statement ***

How many days was the patient in the hospital?  3

Did the patient have surgery (Y/N)? y

Please enter surgery type

1 - Minor surgery    $   600
2 - Eye surgery      $ 1,250
3 - Knee replacement $ 6,000
4 - Heart surgery    $12,000
5 - Brain surgery    $28,000

3

Did the patient receive medication (Y/N)? y

Please enter medication type

1 - Asprin             $ 10
2 - Sleeping pills     $ 20
3 - Pain pills         $ 50
4 - Local anesthetic   $ 75
5 - General anesthetic $300

3

Did the patient receive other medication (Y/N)? y

Please enter medication type

1 - Asprin             $ 10
2 - Sleeping pills     $ 20
3 - Pain pills         $ 50
4 - Local anesthetic   $ 75
5 - General anesthetic $300

5

Did the patient receive other medication (Y/N)? n

        Patient Charges

Hospital: 3 days @ $700.00 = $ 2100.00
Surgery charge :             $ 6000.00
Pharmacy charge:             $  350.00
                             _________
Total charges  :             $ 8450.00
*/
