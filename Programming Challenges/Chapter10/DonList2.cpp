#include <iostream>   
#include <algorithm>  // Needed for swap
#include "donlist.h"
using namespace std;
 
//****************************************************************
//                   Constructor.                                * 
// The argument passed to num indicates the number of elements   * 
// in array passed to gifts. The gifts array holds the list of   *
// donation values. The constructor allocates the donations      *
// and arrPtr arrays. The gifts array is copied to the           *
// donations array. The elements of the arrPtr array are made    *
// to point to the elements of the donations array, and then     *
// sorted in ascending order by th selectSort function.          *
//****************************************************************
DonationList::DonationList(int num, double gifts[])
{
    numDonations = num;
    if (num > 0)
    {
        // Allocate an array of doubles
        donations = new double[num]; 

        // Allocate an array of pointers-to-doubles
        arrPtr = new double*[num];

        // Initialize the arrays
        for (int count = 0; count < numDonations; count++)
        {
            donations[count] = gifts[count];
            arrPtr[count] = &donations[count];
        }

        // Now, sort the array of pointers.
        sort();
    }
}

//************************************************************
// Destructor frees the memory allocated by the constructor. *
//************************************************************
DonationList::~DonationList()
{
   if (numDonations > 0)
   {
     delete [ ] donations;
     delete [ ] arrPtr;
   }  
}

//*************************************************************
//                   sort.                                    *
// The selecSort function performs a selection sort on the    *
// arrPtr array of pointers. The array is sorted in descending* 
// order on the values its elements point to.                 *
//*************************************************************
void DonationList::sort()
{    
    int maxPos;  //Position of pointer to maximum value in a section of the array.   

    for (int k = 0; k < (numDonations - 1); k++)
    {
        // The kth iteration finds the pointer to the maximum element 
        // from among arrPtr[k..numDonations-1]and puts that pointer at 
        // arrPtr[k]

        maxPos = k;     // k is assumed to be the position of the maximum

        // Is there a position in k+1 .. numDonations - 1
        // with a value greater than that at k? 
        for(int pos = k + 1; pos < numDonations; pos++)
        {
            if (*arrPtr[pos] > *arrPtr[maxPos])
            {
                maxPos = pos;                
            }
        }
 
        // Swap the pointer at maxPos with the pointer at k
        // to make arrPtr[k] point to the maximum element in k..numDonations -1
        swap(arrPtr[k], arrPtr[maxPos]);
    }
}

//********************************************************
//                     show                              *
// The show function uses cout to display the donations  *
// array in sequential order.                            *
//********************************************************
void DonationList::show()
{
    for (int count = 0; count < numDonations; count++)
        cout << donations[count] << " ";
    cout << endl;
}

//**********************************************************
//                   showSorted                            *
// The showSorted function uses cout to display the values *
// pointed to by the elements of the arrPtr array. Since   *
// arrPtr is sorted, this function displays the elements   *
// of the donations array in descending order.             *
//**********************************************************
void DonationList::showSorted()
{
    for (int count = 0; count < numDonations; count++)
        cout << *(arrPtr[count]) << " ";
    cout << endl;
}
