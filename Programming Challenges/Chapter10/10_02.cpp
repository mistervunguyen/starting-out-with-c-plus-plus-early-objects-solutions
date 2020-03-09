// Chapter 10 - Assignment 2, Test Scores #2
// This program sorts an array of names and test scores, and 
// prints both the sorted array and the average score.

#include <iostream>
#include <algorithm>  // For STL sort algorithm function
using namespace std;

// Structure for name score pair
struct DATA
{
   string name;
   double score;
};

// Function prototypes
double average(DATA a[ ], int size);
void sort(DATA a[ ], int size);

int main()
{
    int numberOfStudents;
    DATA *studentData;    // Pointer to dynamically allocated array of DATA
    double ave;    
    
    // Determine number of scores and allocate array
    cout << "Enter number of Students: ";
    cin >> numberOfStudents;
    studentData = new DATA[numberOfStudents];

    // Get scores from the user
    cout <<  "Enter the " << numberOfStudents 
         << " name-score pairs separated by spaces:\n";
    DATA *p = studentData;      // Points to "current" student
    for (int k = 0; k < numberOfStudents; k++)
    {
        cout << "Enter name and score: ";
        cin >> p->name; 
        cin >> p->score;
        // Input validation
        if (p->score < 0) 
        {
           cout << "You may not use negative scores. Please restart the program.";
           exit(0);
        }
        p++;
    }

    // Echo scores back to user
    cout << "Data entered:\n";
    p = studentData;
    for (int j = 0; j < numberOfStudents; j++)
    {
        cout << "\n" << p->name << "  " << p->score; p++;
    }
    
    // Sort scores using STL algorithm sort library function
    sort(studentData, numberOfStudents);
    
    // Compute average
    ave = average(studentData, numberOfStudents);
    
    // Print the output
    cout << "\nThe list of students sorted by  scores is:\n";
    p = studentData;
    for (int m = 0; m < numberOfStudents; m++)
    {
        cout << p->name << "  " << p->score << endl;  p++;
    }
    cout << "\nThe average is: " << ave;    
    return 0;
}

//************************************************************
//                   average                                 *
// Compute and return average of array a[ ] of given size.   *
//************************************************************
double average(DATA a[ ], int size)
{    
    double  sum = 0;
    DATA *p = a;  // Pointer to next array entry to be summed
    for (int k = 0; k < size; k++)
    {
        sum = sum + p->score;
        p ++;
    }
    return sum / size;    
}

//***************************************************************
//                     sort                                     *
// Sort an array  of DATA according to scores.                  *
//***************************************************************
void sort(DATA a[ ], int number)
{
  for (int k = number-1; k >= 1; k--)
  {
     // Find maximum of a[0..k]
     DATA *maxPointer = a;
     for (DATA *p = a+1; p != a+k+1; p++)
     {
       if (p->score > maxPointer->score)
           maxPointer = p;
     }
     // Swap *maxPointer with a[k]
     swap(*maxPointer, *(a + k));
  }
}

    