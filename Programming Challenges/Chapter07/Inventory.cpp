// This is the inventory.cpp file.
// It contains the Inventory class function definitions. 
#include "Inventory.h"
#include <iostream>
using namespace std;

/**********************************************************
 *                   Inventory::Inventory                 *                   
 * This overloaded constructor initializes all member     *
 * variables with the values passed to it                 *
 **********************************************************/
Inventory::Inventory(int i, int q, double c)
{ 
	setItemNumber(i);
	setQuantity(q);
	setCost(c);	
}

/**********************************************************
 *                  Inventory::setItemNumber              *
 * This mutator function stores the value passed to it in *
 * the itemNumber member variable.                        *
 **********************************************************/
void Inventory::setItemNumber(int itemNum)
{
	while (!validInt(itemNum))
	{
		cout << "Item Number must be 0 or greater. Please re-enter: ";
		cin  >> itemNum;
	}
	itemNumber = itemNum; 
}

/**********************************************************
 *                   Inventory::setQuantity               *
 * This mutator function stores the value passed to it in *
 * the quantity member variable.                          *
 *********************************************************/
void Inventory::setQuantity(int q)
{
	while (!validInt(q))
	{
		cout << "Quantity must be 0 or greater. Please re-enter: ";
		cin  >> q;
	}
	quantity = q; 
}

/**********************************************************
 *                    Inventory::setCost                  *
 * This mutator function stores the value passed to it in *
 * the cost member variable.                              *
 **********************************************************/
void Inventory::setCost(double c)
{
	while (!validFloat(c))
	{
		cout << "Cost must be 0 or greater. Please re-enter: ";
		cin  >> c;
	}
	cost = c; 
}

/***********************************************************
 *                     Inventory::validInt                 *
 * This function returns true if its integer argument is   *
 * valid (i.e. non-negative), and returns false otherwise. *
 ***********************************************************/
bool Inventory::validInt(int value)
{
	if (value >= 0)     // The integer value is valid
		return true;
	else                // The value is negative, so it is NOT valid
		return false;  
}

/*************************************************************
 *                   Inventory::validFloat                   *
 * This function returns true if its floating-point argument * 
 * is valid (i.e. non-negative), and returns false otherwise.*
 *************************************************************/
bool Inventory::validFloat(double value)
{
	if (value >= 0.0)     // The floating-point value is valid
		return true;
	else                  // The value is negative, so it is NOT valid
		return false;  
}