// Chapter 18 - Assignment 18, Ordered By Name, Ordered By Age
// This program sorts data that consits of name, age pairs, 
// first by name, and then by age.

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


struct PersonData
{
   string name; 
   int age;
   PersonData(const string& name1, int age1) : name(name1), age(age1)
   {

   }
};



int main()
{
   string name; 
   int age;

   string filename = "person_data.txt";
   ifstream input_file(filename);

   if (!input_file)
   {
      cout << "Could not open the file.";
      return 1;      
   }

   string filename2 = "output_data.txt";
   ofstream output_file(filename2);

   if (!output_file)
   {
      cout << "Could not open the file.";
      return 1;
   }

   vector<PersonData>  person_data;

   // Read the file into a vector.
   while (input_file >> name >> age)
   {
      person_data.push_back(PersonData(name, age));
   }
   input_file.close();

   // Sort by name alphabetically.
   // This assumes you have read the section on
   // Function Objects and Lambda Expressions. You can also
   // use a regular function for the compare predicate
   sort(begin(person_data), end(person_data), [](auto a, auto b) { return a.name < b.name;});

   // Print the sorted data.
   cout << "Here is the data in alphabetic order:" << endl;
   for (auto p : person_data)
   {
      cout << p.name << " " << p.age << endl;
      output_file << p.name << " " << p.age << endl;
   }

   // Sort by age.
   sort(begin(person_data), end(person_data), [](auto a, auto b) { return a.age < b.age;});

   cout << endl << endl;
   output_file << endl << endl;

   // Print the sorted data.
   cout << "Here is the data in numeric order:" << endl;
   for (auto p : person_data)
   {
      cout << p.name << " " << p.age << endl;
      output_file << p.name << " " << p.age << endl;
   }

   cout << endl;
   output_file.close();

   return 0;
}