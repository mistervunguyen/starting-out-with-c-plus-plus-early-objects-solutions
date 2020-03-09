// Chapter  10 - Assignment 3, Money Money Money #1
// This program shows the donations made to the United Cause
// by the employees of CK Graphics, Inc. It displays
// the donations in order from lowest to highest
// and in the original order they were received.

#include <iostream>
#include "donlist.h"
using namespace std;

int main()
{
    double *funds;              // Will point to dynamically allocated array
                                // of donations
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
    
    // Create object that will hold and process donations
    DonationList ckGraphics(numberOfDonations, funds);

    // Display the desired information
    cout << "The donations sorted in ascending order are:\n";
    ckGraphics.showSorted();
    cout << "The donations in their original order are:\n";
    ckGraphics.show();

    // Clean up and return
    delete [ ] funds;
    return 0;
}
