// Chapter  10 - Assignment 4, Money Money Money #2
// This program shows the donations made to the United Cause
// by the employees of CK Graphics, Inc. It displays
// the donations in order from highest to lowest
// and in the original order they were received.

// Needs to be linked with compiled form of DonList2.cpp

#include <iostream>
#include "donlist.h"
using namespace std;

int main()
{
    double *funds;
    int numberOfDonations;
    
    // Determine number of donations and allocate space
    cout << "Enter number of Donations: ";
    cin >> numberOfDonations;
    funds = new double[numberOfDonations];

    // Get the Donations
    cout << "Enter the donations, separated by spaces:\n";
    for (int k = 0; k < numberOfDonations; k++)
    {
       cin >> funds[k];
    }        
    
    // Create the object to hold donations
    DonationList ckGraphics(numberOfDonations, funds);

    // Process the donations
    cout << "The donations sorted in descending order are:\n";
    ckGraphics.showSorted();
    cout << "The donations in their original order are:\n";
    ckGraphics.show();

     // Clean up and return
    delete [ ] funds;
    return 0;
}
