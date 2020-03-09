//  Chapter 13 --  Assignment 14:  Corporate Sales Data Input
// This program reads in coorporate data from a file.

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;

// Structure for division information
const int NAME_LEN = 7;
struct DivInfo
{
    char divName[NAME_LEN];
    int quarter;
    double sales;
};

fstream file("corp.dat", ios::in | ios::binary);
DivInfo corp;
double totalQ1 = 0, totalQ2 = 0, totalQ3 = 0, totalQ4 = 0;
double eastYear = 0, westYear = 0, northYear = 0, southYear = 0;
double totalCorp = 0, highest, lowest;

// Function prototypes
void findHighandLow();
void displayResults();

int main()
{

   while(!file.eof())
   {
      file.read((char *)&corp, sizeof(corp));
      if (file.fail())
          break;

      // Keep total of all sales
      totalCorp += corp.sales;

      // Divisional sales data
      if (strcmp(corp.divName, "East") == 0)
          eastYear += corp.sales;
      else if (strcmp(corp.divName, "West") == 0)
          westYear += corp.sales;
      else if (strcmp(corp.divName, "North") == 0)
          northYear += corp.sales;
      else if (strcmp(corp.divName, "South") == 0)
          southYear += corp.sales;

      // Quarterly sales data
      if (corp.quarter == 1)
          totalQ1 += corp.sales;
      else if (corp.quarter == 2)
          totalQ2 += corp.sales;
      else if (corp.quarter == 3)
          totalQ3 += corp.sales;
      else if (corp.quarter == 4)
          totalQ4 += corp.sales;
   }
   file.close();
   findHighandLow();
   displayResults();
   return 0;
}

//*************************************************************************
//                    FindHIghandLow                                      *
// The following function finds the highest and lowest quarterly sales.   *
//*************************************************************************
void findHighandLow()
{
   // Find highest quarterly sales
   highest = lowest = totalQ1;
   if (totalQ2 > highest)
       highest = totalQ2;
   if (totalQ3 > highest)
       highest = totalQ3;
   if (totalQ4 > highest)
       highest = totalQ4;

    // Find lowest quarterly sales
   if (totalQ2 < lowest)
       lowest = totalQ2;
   if (totalQ3 < lowest)
       lowest = totalQ3;
   if (totalQ4 < lowest)
       lowest = totalQ4;
}

//*************************************************************
//                  displayResults                            *
// The following function displays the financial report.      *
//*************************************************************
void displayResults()
{
   cout << setprecision(2);
   cout << fixed << showpoint;

   // Total corporate quarterly sales
   cout << "Corporate sales for 1st quarter: $" << totalQ1 << endl;
   cout << "Corporate sales for 2nd quarter: $" << totalQ2 << endl;
   cout << "Corporate sales for 3rd quarter: $" << totalQ3 << endl;
   cout << "Corporate sales for 4th quarter: $" << totalQ4 << endl;

   // Total yearly sales for each division
   cout << "Total yearly sales for each division:\n";
   cout << "\tEast: $" << eastYear << endl;
   cout << "\tWest: $" << westYear << endl;
   cout << "\tNorth: $" << northYear << endl;
   cout << "\tSouth: $" << southYear << endl;

   // Total yearly corporate sales
   cout << "Total yearly corporate sales: $" << totalCorp << endl;

   // Average quarterly sales for each division
   cout << "Average quarterly sales for each division:\n";
   cout << "\tEast: $" << (eastYear/4) << endl;
   cout << "\tWest: $" << (westYear/4) << endl;
   cout << "\tNorth: $" << (northYear/4) << endl;
   cout << "\tSouth: $" << (southYear/4) << endl;

   // Highest and Lowest quarters:
   cout << "Highest quarterly sales: $" << highest << endl;
   cout << "Lowest quarterly sales: $" << lowest << endl;
}

