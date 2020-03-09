// File Pharmacy.h
// This file holds the declaration for the Pharmacy class.

#include "PatientAccount.h"

#ifndef PHARMACY_H
#define PHARMACY_H

class Pharmacy
{
  private:
	double price1,          // These hold the prices of the 5 
		   price2,          // medicine price categories.
		   price3,
		   price4,
		   price5,
		   pharmacyTotal;   // Total pharmacy charges
		   
	void updatePharmacyTotal(double amt)
	{   pharmacyTotal += amt;  }
	
  public:
	Pharmacy();                                // Defined in Pharmacy.cpp
	void updateAccount(PatientAccount&, int);  // Defined in Pharmacy.cpp
	
	double getPharmacyCharge()
	{   return pharmacyTotal;   }
};

#endif