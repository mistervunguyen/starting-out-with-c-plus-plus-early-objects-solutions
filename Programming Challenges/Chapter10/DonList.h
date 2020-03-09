#ifndef DONLIST_H
#define DONLIST_H
 
// Class to represent donations
class DonationList
{
private:
    int numDonations;
    double *donations;   // Points to dynamically allocated array 
                         // holding donations in original order
    double **arrPtr;     // Points to dynamically allocated array 
                         // of pointers to double that will point to 
                         // donations in sorted order
    void sort();         // Used to sort list of donations
public:
    DonationList(int num, double gifts[]);  // Constructor
    ~DonationList();     // Destructor
    void show();         // Show donations in order entered
    void showSorted();   // Show donations in sorted order
};
#endif
