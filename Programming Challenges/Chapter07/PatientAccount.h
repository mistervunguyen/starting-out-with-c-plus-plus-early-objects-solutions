// File PatientAccount.h
// This file holds the PatientAccount class declaration. Because students
// have not yet learned to create friend functions, updateCharges has been
// made a public function so that functions within the Pharmacy and Surgery
// classes can update the patient charges.

#ifndef PATIENT_ACCOUNT_H
#define PATIENT_ACCOUNT_H

class PatientAccount
{
  private:
	int   days;           // Days in hospital
	double totalCharges;  // Total of ALL charges for hospital, surgery & medicine

  public:
	PatientAccount();
	void  setDays();
	void  updateCharges(double);

	int getDays() const
	{  return days; }
	
	double getDailyRate();    // Defined in PatientAccount.cpp
	
	double getTotalCharges() const
	{  return totalCharges;  }
};

#endif