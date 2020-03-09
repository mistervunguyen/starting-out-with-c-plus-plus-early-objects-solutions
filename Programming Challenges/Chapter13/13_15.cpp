//  Chapter 13 --  Assignment 15:  Inventory Program
// This program processes inventory information.

#include <iostream>
#include <fstream>
using namespace std;

// Declaration of Invtry structure
const int DESC_LEN = 31;
const int DATE_LEN = 11;
struct Invtry
{
    char desc[DESC_LEN];
    int qty;
    double wholeSale;
    double retail;
    char date[DATE_LEN];
};

// Function Prototypes
void addRecord();
void viewRecord();
void changeRecord();

fstream inventory;

int main()
{
    int choice;
   
    do
    {
        // Display menu
        cout << "\n1. Add a new record\n";
        cout << "2. View an existing record\n";
        cout << "3. Change an existing record\n";
        cout << "4. Exit\n\n";

        // Get user's choice
        do
        {
            cout << "Enter your choice (1-4): ";
            cin  >> choice;
            if (choice < 1 || choice > 4)
               cout << "Enter 1, 2, 3, or 4\n";
        } while (choice < 1 || choice > 4);
    
        // Process the user's choice
        switch (choice)
        {
           case 1:  
               addRecord();
               break;
           case 2:    
               viewRecord();
               break;
           case 3:
               changeRecord();
       }
   } while (choice != 4);
   return 0;

}

//********************************
//        addRecord              *
// Add a record.                 *
//********************************
void addRecord()
{
   Invtry record;

   // Open file
   inventory.open("invtry.dat", ios::out | ios::app | ios::binary);
   if (inventory.fail())
   {
      cout << "Error opening file.\n";
      return;
   }
   cin.get();

   // Get description
   cout << "\nEnter the following inventory data:\n";
   cout << "Description: ";
   cin.getline(record.desc, 31);
    
   // Get quantity
   do
   {
      cout << "Quantity: ";
      cin >> record.qty;
      if (record.qty < 0)
           cout << "Enter a positive value, please.\n";
   } while (record.qty < 0);

   // Get wholesale cost
   do
   {
       cout << "Wholesale cost: ";
       cin >> record.wholeSale;
       if (record.wholeSale < 0)
       cout << "Enter a positive value, please.\n";
   } while (record.wholeSale < 0);

   // Get retail price
   do
   {
       cout << "Retail price: ";
       cin >> record.retail;
       if (record.retail < 0)
           cout << "Enter a positive value, please.\n";
   } while (record.retail < 0);
   
   // Get date 
   cout << "Date added to inventory: ";
   cin >> record.date;

   // Write the inventory record to the file
   inventory.write(reinterpret_cast<char *>(&record), sizeof(record));
    
   // Check if successs
   if (inventory.fail())
       cout << "Error writing record to file.\n";
   else
       cout << "record written to file.\n\n";
   inventory.close();
}

// *********************************
//         viewRecord              *
// View a record.                  *
// *********************************
void viewRecord()
{
    Invtry record;
    long recNum;

    // Open file for reading
    inventory.open("invtry.dat", ios::in | ios::binary);
    if (inventory.fail())
    {
         cout << "Error opening file.\n";
         return;
    }

    // Get number of record to view and seek to it
    cout << "\nEnter the record number of the item: ";
    cin >> recNum;
    inventory.seekg(recNum * sizeof(record), ios::beg);
    
    // Check if success when seeking
    if (inventory.fail())
    {
        cout << "\nError locating record.\n";
        inventory.close();
        return;
    }

    // Read the record
    inventory.read(reinterpret_cast<char *>(&record), sizeof(record));
    inventory.close();

    // Display the record read
    cout << "Description: ";
    cout << record.desc << endl;
    cout << "Quantity: ";
    cout << record.qty << endl;
    cout << "Wholesale cost: ";
    cout << record.wholeSale << endl;
    cout << "Retail price: ";
    cout << record.retail << endl << endl;
    cout << "Press any key to continue...\n ";
    cin.get();
}

// *******************************
//         changeRecord.         *
// Change a record               *
// *******************************
void changeRecord()
{
   Invtry record;
   long recNum;

   // Open the file
   inventory.open("invtry.dat", ios::in | ios::out | ios::binary);
   if (inventory.fail())
   {
       cout << "Error opening file.\n";
       return;
   }
   
   //  Find out which record to alter and seek to it
   cout << "Enter the record number of the item: ";
   cin >> recNum;
   inventory.seekg(recNum * sizeof(record), ios::beg);
    
   //  Did we locate the record OK?
   if (inventory.fail())
   {
       cout << "Error locating record.\n";
       inventory.close();
       return;
   }

   // Display the  record
   cout << "Current record contents:\n";
   inventory.read(reinterpret_cast<char *>(&record), sizeof(record));
   cout << "Description: ";
   cout << record.desc << endl;
   cout << "Quantity: ";
   cout << record.qty << endl;
   cout << "Wholesale cost: ";
   cout << record.wholeSale << endl;
   cout << "Retail price: ";
   cout << record.retail << endl << endl;

   // Allow user to edit the record
   cout << "Enter the new data:\n";
   cin.get();
   cout << "Description: ";
   cin.getline(record.desc, 31);
   cout << "Quantity: ";
   cin >> record.qty;
   cout << "Wholesale cost: ";
   cin >> record.wholeSale;
   cout << "Retail price: ";
   cin >> record.retail;
   cout << "Date added to inventory: ";
   cin >> record.date;

   // Write the record back to the file
   inventory.seekp(recNum * sizeof(record), ios::beg);
   inventory.write(reinterpret_cast<char *>(&record), sizeof(record));
   cout << "Press any key to continue... ";
   cin.get();
}


