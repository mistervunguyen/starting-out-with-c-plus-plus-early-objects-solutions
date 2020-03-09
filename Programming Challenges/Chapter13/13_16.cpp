//  Chapter 13 -- Assignment 16:  Inventory Screen Report
// This program prints a sort of summary for the inventory database

#include <iostream>
#include <fstream>
using namespace std;

const int DESC_LEN = 31;
const int DATE_LEN = 11;

// Declaration of Invtry structure
struct Invtry
{
    char desc[DESC_LEN];
    int qty;
    double wholesale;
    double retail;
    char date[DATE_LEN];
};

fstream Inventory;

int main()
{
    Invtry record;
    long recNum = 0;
    double totalWholesale = 0, totalRetail = 0;
    int totalQty = 0;

    // Open the file
    Inventory.open("invtry.dat", ios::in | ios::binary);
    if (Inventory.fail())
    {
        cout << "Error opening file.\n";
        return 1;
    }

    // Look at each record in the fle and compile summary stats
    while (!Inventory.eof())
    {
        Inventory.seekg(recNum * sizeof(record), ios::beg);
        if (Inventory.fail())
        {
            cout << "Error locating record.\n";
            Inventory.close();
            return 2;
        }
        Inventory.read(reinterpret_cast<char *>(&record), sizeof(record));
        totalWholesale += record.wholesale;
        totalRetail += record.retail;
        totalQty += record.qty;
        recNum++;
    }
    
    // Display the summary
    Inventory.close();
    cout << "\n\n* * * * * INVENTORY SCREEN REPORT * * * * *\n\n";
    cout.precision(2);
    cout.setf(ios::fixed | ios::showpoint);
    cout << "  Total wholesale Value:\t $";
    cout << (totalWholesale * totalQty) << endl << endl;
    cout << "  Total retail Value:\t\t $";
    cout << (totalRetail * totalQty) << endl << endl;
    cout << "  Number of Items in Inventory:\t " << totalQty << endl << endl;
    cout << "* * * * * * * * * * * * * * * * * * * * * *\n\n\n\n";

    return 0;
}

