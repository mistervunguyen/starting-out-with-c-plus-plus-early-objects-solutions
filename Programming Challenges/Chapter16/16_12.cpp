// Chapter 16 - Assignment 12, Pascal's Triangle
// This program  prints Pascal's triangle of a size given by the user.
#include <iostream>
#include <vector>
   using namespace std;


//*************************************************************
//               pascalTriangleNextRow                        *
//  Given a vector representing Pascal's triangle, this       *
//  functions returns a vector representing the successor     *
//  row.                                                      *
//*************************************************************
vector<int> pascalTriangleNextRow(vector<int> row)
{
   vector<int> p;
   p.push_back(1);
   if (row.empty()) return p;

   for (int k = 0; k < row.size() - 1; k++)
   {
      p.push_back(row[k] + row[k + 1]);
   }
   p.push_back(1);
   return p;
}


//*******************************************
//          print                           *
//    prints a vector                       *
//*******************************************
void print(vector<int> v)
{
   for (int value : v)
   {
      cout << value << " ";
   }
   cout << endl;
}



int main()
{
   vector<int> row;
   cout << "Enter a positive integer for the number of rows in Pascal's triangle:";
   int number;

   cin >> number;
   for (int k = 1; k <= number; k++)
   {
      row = pascalTriangleNextRow(row);
      print(row);
   }

   return 0;
}
