// File Pharmacy.cpp
// This file holds the Pharmacy class function definitions.
// Students may set different rates for medicine types.

#include "Pharmacy.h"

/************************************************************
 *                  Pharmacy::Pharmacy()                    *
 * This default constructor sets the prices for each of the *
 * five medicine price categories.  Students may make up    *
 * their own data.
 ************************************************************/
Pharmacy::Pharmacy()
{
	price1 =  10.00;    // Set prices for medicine types 1-5
	price2 =  20.00;
	price3 =  50.00;
	price4 =  75.00;
	price5 = 300.00;
	pharmacyTotal = 0.0;
}

/*****************************************************************
 *                     Pharmacy::updateAccount                   *
 * This class function receives a reference to a PatientAccount  *
 * object and an int indicating a medicine price category. It    *
 * uses this information to call the updateCharges member        *
 * function of the PatientAccount object, passing it the medicine*
 * charge to be added to the account.                            *
 *****************************************************************/
void Pharmacy::updateAccount(PatientAccount& pt, int type)
{
	switch (type)
	{	
		case 1: pt.updateCharges(price1);
		        updatePharmacyTotal(price1);
				break;
				
		case 2: pt.updateCharges(price2);
		        updatePharmacyTotal(price2);
				break;
				
		case 3: pt.updateCharges(price3);
		        updatePharmacyTotal(price3);
				break;
				
		case 4: pt.updateCharges(price4);
				updatePharmacyTotal(price4);
				break;
				
		case 5: pt.updateCharges(price5);
		        updatePharmacyTotal(price5);
				break;
				
		default: ; // Do not add any charge to the account.
	}
}
