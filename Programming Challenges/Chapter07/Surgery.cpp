// File Surgery.cpp
// This file holds the Surgery class function definitions.
// Students may set different rates for surgery types.

#include "Surgery.h"

/******************************************************************
 *                          Surgery::Surgery                      *
 * This default constructor sets the rates for each surgery type. * 
 * Students may make up their own data.                          *
 ******************************************************************/
Surgery::Surgery()
{
	rate1 =   600.00;    // Set rates for surgery types 1-5
	rate2 =  1250.00;
	rate3 =  6000.00;
	rate4 = 12000.00;
	rate5 = 28000.00;
}

/*****************************************************************
 *                     Surgery::updateAccount                    *
 * This class function receives a reference to a PatientAccount  *
 * object and an int indicating the type of surgery. It uses this*
 * information to call the updateCharges member function of the  *
 * PatientAccount object, passing it the surgery charge to be    *
 * added to the account.                                         *
 *****************************************************************/
void Surgery::updateAccount(PatientAccount& pt, int type)
{
	switch (type)
	{	
		case 1: pt.updateCharges(rate1);
		        setSurgeryCharge(rate1);
				break;
				
		case 2: pt.updateCharges(rate2);
				setSurgeryCharge(rate2);
				break;
				
		case 3: pt.updateCharges(rate3);
		        setSurgeryCharge(rate3);
				break;
				
		case 4: pt.updateCharges(rate4);
		        setSurgeryCharge(rate4);
				break;
				
		case 5: pt.updateCharges(rate5);
		        setSurgeryCharge(rate5);
				break;
				
		default:      ; // Do not add any charge to the account.
	}
}
