// Chapter 16, Assignment 11, Word Transformers Modification
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
 
// Prototype
void sort(char str[], int size, vector<string>& intermediates);

int main()
{
    // The two words and a copy of the first word
    char str1[] = "spot";
    char str1Copy[] = "spot";
    char str2[] = "stop";
    char str2Copy[] = "stop";

    // These vectors hold the list of transpositions
    vector<string> intermediates;
    vector<string> reverse_intermediates;

    // Sort the two words
    cout << "The first word is " << str1 <<  endl
         << "The second word is " << str2 << endl;
    sort(str1, 4, intermediates);
    sort(str2, 4, reverse_intermediates);

    // Display the list of intermediates
    cout << "The transformation steps are: " << endl;
    cout << str1Copy <<  " ";
    for (int k = 0; k < intermediates.size(); k++)
    {
      cout << intermediates[k] << "  ";
    }
    // Display the list of reverse intermediates
    for (int k = reverse_intermediates.size()-2; k >=0 ; k--)
    {
        cout << reverse_intermediates[k] << " ";
    }
    cout << str2Copy; 
    cout << endl;
    return 0;
}

//********************************************************************
// This is a version of Bubblesort that saves a list of all          *
// intermediate words generated in the process of sorting the list.  *
//********************************************************************
void sort(char str[], int size, vector<string>& intermediates)
{
    int upperBound = size-1; // last index of subarray remaining to be sorted

    while (upperBound  > 0)
    {
        for (int k = 0; k < upperBound; k++ )
        {
            if (str[k] > str[k+1])
            {
                swap(str[k], str[k+1]);
                intermediates.push_back(str);               
            }
        }
        upperBound--;
    }
}



