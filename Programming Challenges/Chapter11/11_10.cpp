// Chapter 11 - Assignment 10, HTML Table of Names and Scores
// This program features a class that is a vector of student objects.
// The class has an overloaded stream insertion operator that prints the 
// contents of the class as an HTML table.
#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Student
{
   string name;
   int score;
public:
   Student(string name, int score)
   {
	   this->name = name;
	   this->score = score;
   }
   string getName() { return name; }
   int getScore() { return score; }
};


class HtmlStudentTable
{
   vector<Student> students;
public:
   HtmlStudentTable(vector<Student> vec)
   {
      for (unsigned int k = 0; k < vec.size(); k++)
		  students.push_back(vec[k]);
   }
   friend ostream &operator<<(ostream & out, HtmlStudentTable stdTable);
};

/**********************************************************
 *            stream insertion operator                   *
 **********************************************************/
ostream &operator<<(ostream &out, HtmlStudentTable stdTable)
{
   out << "<table border = '1'>" << endl;
   out << "\t<tr> <th> Student </th> <th> Score </th> </tr>" << endl;
   for (unsigned int k = 0; k < stdTable.students.size(); k++)
   {
     out << "\t<tr> <td> " << stdTable.students[k].getName() <<  " </td> <td> " 
		  <<  stdTable.students[k].getScore() <<  " </td></tr>" << endl;
   }
   out << "</table>" << endl;
   return out;
}

int main()
{
	// Create a vector of studens
	vector<Student> students;
	students.push_back(Student("Ann Bowmann", 79));
	students.push_back(Student("Alfred Lopez", 80));
	students.push_back(Student("Latoya Brown", 77));

	// Create the HTML student table class and print it out
	HtmlStudentTable htmlStdTable(students);
	cout << htmlStdTable;

	return 0;
}