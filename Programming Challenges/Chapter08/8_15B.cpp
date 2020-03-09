// Chapter 8 - Programming Challenge 15, Driver's License Exam - SOLUTION 'B'
// This program utilizes a TestGrader class to grade the written portion of a 
// driver's license exam. The class grade function compares the applicant's 
// answers, stored in one array, to the correct answers, stored in another array,
// and reports the results.  

// NOTE: THIS CHALLENGE ASKED STUDENTS TO DO SOMETHING NOT YET COVERED IN CHAPTER 8.
// It asked them to create and return a string that contains numeric values. 
// The instructor can either tell students to just have the grade function display
// the results, as shown in Solution A (See file 8_15A.cpp), or can give students
// either of the numToString functions included in THIS solution. 

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>     // Needed for ostringstream object in numToString Version 1 
#include <cstdlib>     // Needed for itoa function in numToString Version 2 
using namespace std;

const unsigned SIZE = 20;
class TestGrader
{
  private:
    char answers[SIZE];        // Holds the correct answers
    int  getNumWrong(char *);
    string missedQuestions(char *);
	string numToString(int) const;
    
  public:
    void setKey(string);
    string grade(char *);
};

// Class Function Implementation Section

/************************************************************************
 *                          TestGrader::setKey                          *
 * Stores the correct data passed to the function in the answers array. *
 ***********************************************************************/ 
void TestGrader::setKey(string key)
{
	if (key.length() != SIZE)
	{	cout << "Error in key data!\n";
		return;
	}
	for (unsigned pos = 0; pos < SIZE; pos++) 
        answers[pos] = key[pos];
}

/************************************************************************
 *                          TestGrader::grade                           *
 * Controls the grading of the test answers passed to the function.     *
 ************************************************************************/ 
string TestGrader::grade(char *test)
{
    int numWrong = getNumWrong(test);
		
	string resultMessage;
	
	if (numWrong <= 5)
		resultMessage = "Congratulations. You passed the exam. \n";
	else
		resultMessage = "You did not pass the exam. \n";
	
	resultMessage += "You got " + numToString(SIZE-numWrong)  + " questions correct. \n";
	
	if (numWrong > 0)
	{	resultMessage += "You missed the following " + numToString(numWrong) + " questions: ";
	    resultMessage += missedQuestions(test) + "\n";
	}
	
	return resultMessage;
}

/**********************************************************************
 *                      TestGrader::getNumWrong                       *
 * Compares student answers to correct answers and returns the number *
 * of wrong answers.                                                  *
 **********************************************************************/
int TestGrader::getNumWrong(char *test)
{
	int numWrong = 0;

	for (unsigned question = 0; question < SIZE; question++)
	{
		if (answers[question] != test[question])
			numWrong++;
	}
	return numWrong;
}

/***********************************************************
 *                  TestGrader::missedQuestions            *
 * Compares student answers to correct answers and creates *
 * a string holding the numbers of the missed questions.   *
 ***********************************************************/
string TestGrader::missedQuestions(char *test)
{
	string missed = "";
	for (unsigned question = 0; question < SIZE; question++)
	{
		if (answers[question] != test[question])
			missed += numToString(question+1) + "  ";
	}
	return missed;
}

/***********************************************************
 *          TestGrader::numToString Version 1              *
 * Converts and returns an integer in its string form.     *
 * This version requires the sstream header file.          *
 ***********************************************************/
string TestGrader::numToString(int num) const
{
	ostringstream ss;
	ss << num;
	return ss.str();
}

/***********************************************************
 *            TestGrader::numToString Version 2            *
 * Converts and returns an integer in its string form.     *
 * This version requires the cstdlib header file.          *
 ***********************************************************/
/*string TestGrader::numToString (int num) const
{ 
	char cString[3];           // Holds 1 and 2 digit numbers
	itoa(num, cString, 10);
	string numString(cString);
	return numString;	
}
*/

// ***************** Client program that uses the class ***************

int main()
{ 
	const int NUM_QUESTIONS = 20;

	string name,                 // Test taker's name
	       testResult;           // Result returned by DMVexam grade function
	char doAnother;              // Control variable for main processing loop
	char testTakerAnswers[20];   // Array to hold test taker's answers
	TestGrader DMVexam;          // Create a TestGrader object 
	
	DMVexam.setKey("BDAACABACDBCDADCCBDA");  // Set the test key just once

	do
	{   // Get applicant name (not required by the program specs)
		cout << "\nApplicant name: ";
		getline(cin, name);

		// Get and validate applicant answers
		cout << "Enter answers for " << name << ".\n";
		cout << "Use only letters A, B, C, and D.\n\n";
		for (int q = 0; q < NUM_QUESTIONS; q++)
		{
			cout << "Q" << setw(2) << q+1 << ": ";
			cin  >> testTakerAnswers[q];
			testTakerAnswers[q] = toupper(testTakerAnswers[q]);

			while (testTakerAnswers[q] < 'A' || testTakerAnswers[q] > 'D')
			{
				cout << "\nAnswer must be A, B, C, or D -- re-enter answer " 
				     << (q+1) << ": ";
				cin  >> testTakerAnswers[q];
				testTakerAnswers[q] = toupper(testTakerAnswers[q]);
			}
		}
        // Call class function to grade the exam
		cout << "\nResults for " << name << endl << endl;
		testResult = DMVexam.grade(testTakerAnswers);
		cout << testResult;

		cout << "\nGrade another exam (Y/N)? ";
		cin  >> doAnother;
		cout << endl;
		cin.ignore();       // Clear the \n out of the input buffer 
                            // before doing the next getline
	} while (toupper(doAnother) == 'Y');

	return 0;
}
  
/* SAMPLE RUN RESULTS

Applicant name: Huck Finn
Enter answers for Huck Finn.
Use only letters A, B, C, and D.

Q 1: B
Q 2: D
Q 3: A
Q 4: A
Q 5: C
Q 6: A
Q 7: B
Q 8: A
Q 9: C
Q10: D
Q11: B
Q12: B
Q13: D
Q14: A
Q15: D
Q16: C
Q17: C
Q18: B
Q19: D
Q20: D

Results for Huck Finn

Congratulations. You passed the exam.
You got 18 questions correct.
You missed the following 2 questions: 12  20

Grade another exam (Y/N)? N
*/