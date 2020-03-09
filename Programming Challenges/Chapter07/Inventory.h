// This is the inventory.h file.
// It contains the Inventory class declaration.

#ifndef INVENTORY_H
#define INVENTORY_H

class Inventory
{
private:
	int itemNumber;
	int quantity;
	double cost;

public:
	// Default constructor
	Inventory()
	{  itemNumber = quantity = 0; 
	   cost = 0.0;
	}
	
	// Overloaded constructor
	Inventory(int, int, double);	// Defined in Inventory.cpp

	// Mutators (i.e., "set" functions) defined in Inventory.cpp
	void setItemNumber(int);
	void setQuantity(int);
	void setCost(double);

	// Accessors (i.e., "get" functions)
	int getItemNumber()
		{ return itemNumber; }
		
	int getQuantity()
		{ return quantity; }
		
	double getCost()
		{ return cost; }

	double getTotalCost()
	    { return quantity * cost; } 

	// Input validation functions defined in Inventory.cpp
	bool validInt(int);
	bool validFloat(double);
};

#endif
