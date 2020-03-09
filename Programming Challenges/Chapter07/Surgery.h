// File Surgery.h
// This file holds the declaration of the Surgery class.

#include "PatientAccount.h"

#ifndef SURGERY_H
#define SURGERY_H

class Surgery
{
  private:
	double rate1,            // Rates for 5 surgery types
		   rate2,
		   rate3,
		   rate4,
		   rate5,
		   surgeryCharge;    // Charge for whatever surgery patient had
		   
	void setSurgeryCharge(double amt)
	{  surgeryCharge = amt;  }
	
  public:
	Surgery();                                 // Defined in Surgery.cpp
	void updateAccount(PatientAccount&, int);  // Defined in Surgery.cpp
	
	double getSurgeryCharge()
	{  return surgeryCharge;  }
};

#endif