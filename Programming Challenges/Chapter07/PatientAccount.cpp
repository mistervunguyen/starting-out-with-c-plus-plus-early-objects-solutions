// File patientAccount.cpp
// This file holds the PatientAccount class function definitions.
// Students may set a different daily rate for hospital rooms.

#include "PatientAccount.h"
#include <iostream>
using namespace std;

const double DAILY_RATE = 700.00;  // Cost per day in hospital

/********************************************************
 *            PatientAccount::PatientAccount            *
 * This default constructor sets the days and charges   *
 * member variables to default values.                  *
 ********************************************************/
PatientAccount::PatientAccount()
{
	days = 0;
	totalCharges = 0.00;
}

/************************************************************
 *                  PatientAccount::setDays                 *
 * This member function sets the number of days the patient *
 * was in the hospital and then adds the room charge for    *
 * those days onto the charges accumulator member variable. *
 ************************************************************/
void PatientAccount::setDays()
{
	cout << "How many days was the patient in the hospital? ";
	cin >> days;
	while (days < 0)
	{
		cout << "Days must be 0 or more. Please re-enter: ";
		cin  >> days;
	}
	totalCharges += days * DAILY_RATE;
}

/***********************************************************
 *             PatientAccount::getDailyRate               *
 * This member function returns the hospital cost per day *
 ***********************************************************/
double PatientAccount::getDailyRate() 
{  
	return DAILY_RATE;
}

/***********************************************************
 *             PatientAccount::updateCharges               *
 * This member function adds the new charge passed to it   *
 * onto the charges accumulator member variable.           *
 ***********************************************************/
void PatientAccount::updateCharges(double newCharge)
{   
	totalCharges += newCharge;
}
