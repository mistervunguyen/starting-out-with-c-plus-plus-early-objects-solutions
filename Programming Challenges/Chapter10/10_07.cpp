//        Chapter 10 -- Assignment 7,  Movie Statistics
// This program collects statistics about the number of movies 
// college students see in a month. The average, median, and mode
// for these statistics are computed. The mode is the statistic that
// occurs with the highest frequency. If all statistics occur with 
// frequency 1, we will say that the mode does not exist.
 
#include <iostream>
#include <algorithm>   // Needed for swap
using namespace std;

// Various function prototypes
double median(int *, int);
int   mode(int *, int);
void  getMovieData(int *, int);
void  sort(int [], int);
double average(int *, int);
void getNumber(int &);

int main()
{
    int *movieData;  // Pointer to dynamically allocated array
                     // that holds movie data
    int num;         // Number of students surveyed
    int mod;         // Mode statistic

    // Get the data
    cout << "How many students were surveyed? ";    
    getNumber(num);
    movieData = new int[num];      
    getMovieData(movieData, num);

    // Sort the data to ease computation of mode
    sort(movieData, num);

    cout << endl;
    for (int k = 0; k < num; k++)
      cout << movieData[k] << "  ";
    cout << endl;

    // Compute and print average
    cout << "The average number of movies seen is ";
    cout << average(movieData, num) << endl;

    // Compute and print median
    cout << "The median of the number of movies seen is ";
    cout << median(movieData, num) << endl;

    // Compute and print mode
    cout << "The mode of the number of movies seen is: ";
    mod = mode(movieData, num);    
    if (mod == -1)
           cout << "The set has no mode.\n";
    else
           cout << "The mode is " << mod << endl;

    // Clean up and go home
    delete [] movieData;
    return 0;
}

/**************************************
*              getMovieData           *
* Read in movie data.                 *
***************************************/
void getMovieData(int arr[], int num)
{
    cout << "Enter the number of movies each student saw.\n";
    for (int count = 0; count < num; count++)
    {
        cout << "Student " << (count + 1) << ": ";        
        getNumber(arr[count]);
    }
}

/**********************************************
*          sort                               *
* Sort an array of n entries.                 *
***********************************************/
void sort(int array[], int n)
{
    int minPos;  //Position of minimum value in a section of the array.   

    for (int k = 0; k < n - 1; k++)
    {
        // The kth iteration finds the value of the minimum element 
        // from among array[k..n-1]and puts that value at array[k]

        minPos = k;     // k is assumed to be the position of the minimum

        // Is there a position in k+1 .. n - 1
        // with a value less than that at k? 
        for(int pos = k + 1; pos < n; pos++)
        {
            if (array[pos] < array[minPos])
            {
                minPos = pos;                
            }
        }
 
        // Swap the value at k with the value at minPos       
        swap(array[k], array[minPos]);
    }
}

/*************************************************
*                median                          *
* Compute median of an array of num entries.     *
**************************************************/
double median(int *arr, int num)
{
    double med;

    if (num % 2 == 0)    // Number of elements even?
    {
        int mid1 = num / 2, mid2 = (num / 2) - 1;
        med = ((*(arr + mid1) + *(arr + mid2)) / 2.0);
    }
    else
        med = *(arr + (num / 2));
    return med;
}


//***********************************************
// Computes the mode of entries in an array.    *
// The array is assumed to have been sorted.    *
// The function returns -1 if there is no mode. *
//***********************************************
int mode(int *arr, int num)
{
   int *p = arr;     // Use to walk through the array
   int mode = -1;      // mode is the array item seen with
                     // the highest frequency so far
   int modeFreq = 0;  
   int currentFreq = 1;
   p++;

   // The idea is to set currentFreq to 1 for each new
   // value that is encountered. The variable currentFreq is 
   // incremented each time we find an array item that is the 
   // same value as the previous one. The variable mode keeps 
   // track of the largest value of currentFreq seen so far.
   while (p < arr + num)
   {
       if (*p == *(p-1))
       {
          currentFreq++;
          if (currentFreq > modeFreq)
          { 
             mode = *p;
             modeFreq = currentFreq;
          }
       }
       else
       {
          currentFreq = 1;
       }
       p++;
   }
   if (modeFreq == 1) 
      return -1; 
   else 
      return mode;    
}

/*********************************************
*           average                          *
* compute average of an array of num entries *
**********************************************/
double average(int arr[], int num)
{
    int total = 0;
    double ave;

    for (int count = 0; count < num; count++)
    {
        total += arr[count];
    }
    ave = total / double(num);
    return ave;
}

/*****************************
*        getNumber           *
* Use for input validation.  *
*****************************/
void getNumber(int &num)
{
   cin >> num;
   while (num < 0)
    {
      cout << "Number cannot be negative: Please enter a nonnegative value: ";
      cin >> num;
    }
}
