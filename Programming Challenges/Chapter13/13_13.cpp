// Chapter 13 -- Assignment 13, Corporate Sales Data Output
// This program outputs some data to a file.
#include <iostream>
#include <fstream>
using namespace std;

const int NAME_LEN = 7;

// Structure for representing data
struct DivInfo
{
   char divName[NAME_LEN];
   int quarter;
   double sales;
};

int main()
{
   fstream file("corp.dat", ios::out | ios::binary);
   DivInfo east, west, north, south;
   int qtr;

   // Store names of divisions
   strcpy(east.divName, "East");
   strcpy(west.divName, "West");
   strcpy(north.divName, "North");
   strcpy(south.divName, "South");

   // Get sales data for East division
   cout << "Enter the quarterly sales for the East Divison:\n";
   for (qtr = 1; qtr <= 4; qtr++)
   {
        east.quarter = qtr;
        cout << "\tQuarter " << qtr << ": ";
        cin >> east.sales;
        file.write(reinterpret_cast<char *>(&east), sizeof(east));
   }

   // Get sales data for West division
   cout << "Enter the quarterly sales for the West Divison:\n";
   for (qtr = 1; qtr <= 4; qtr++)
   {
        west.quarter = qtr;
        cout << "\tQuarter " << qtr << ": ";
        cin >> west.sales;
        file.write(reinterpret_cast<char *>(&west), sizeof(west));
   }

   // Get sales data for North division
   cout << "Enter the quarterly sales for the North Divison:\n";
   for (qtr = 1; qtr <= 4; qtr++)
   {
        north.quarter = qtr;
        cout << "\tQuarter " << qtr << ": ";
        cin >> north.sales;
        file.write(reinterpret_cast<char *>(&north), sizeof(north));
   }

   // Get sales data for South division
   cout << "Enter the quarterly sales for the South Divison:\n";
   for (qtr = 1; qtr <= 4; qtr++)
   {
        south.quarter = qtr;
        cout << "\tQuarter " << qtr << ": ";
        cin >> south.sales;
        file.write(reinterpret_cast<char *>(&south), sizeof(south));
   }
   file.close();

   return 0;
}

