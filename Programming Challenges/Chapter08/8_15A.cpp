// Chapter 8 - Programming Challenge 15, Driver's License Exam - SOLUTION 'A'
// This program utilizes a TestGrader class to grade the written portion of a 
// driver's license exam. The class grade function compares the applicant's 
// answers, stored in one array, to the correct answers, stored in another array,
// and reports the results. 

// NOTE: THIS CHALLENGE ASKS STUDENTS TO DO SOMETHING NOT YET COVERED IN CHAPTER 8.
// It asks them to create and return a string that contains integer values. The
// instructor can either tell students to just have the grade function display the
// results rather than return them, as this solutin does, or can give students one
// of the numToString functions included in Solution B to use. (See file 8_15B.cpp)
 
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const unsigned SIZE = 20;
class TestGrader
{
  private:
    char answers[SIZE];        // Holds the correct answers
    int  getNumWrong(char *);
    void missedQuestions(char *);
    
  public:
    void setKey(string);
    void grade(char *);
};

// Class Function Implementation Section

/**************************************
 *          TestGrader::setKey        *
 * Stores the correct data passed to  *
 * the function in the answers array. *
 *************************************/ 
void TestGrader::setKey(string key)
{
	if (key.length() != SIZE)
	{	cout << "Error in key data.\n";
		return;
	}
	for (unsigned pos = 0; pos < SIZE; pos++) 
        answers[pos] = key[pos];
}

/************************************
 *        TestGrader::grade         *
 * Controls the grading of the test *
 * answers passed to the function.  *
 ************************************/ 
void TestGrader::grade(char *test)
{
    int numWrong = getNumWrong(test);

    if (numWrong <= 5)
		cout << "Congratulations. You passed the exam. \n";
    else
		cout << "You did not pass the exam. \n";

    cout << "You got " << (SIZE-numWrong)  << " questions correct. \n";
	
	if (numWrong > 0)
	{	cout << "You missed the following " << numWrong << " questions: ";
		missedQuestions(test);
	}
}

/************************************************
 *          TestGrader::getNumWrong             *
 * Compares student answers to correct answers  *
* and returns the number of wrong answers.      *
 ************************************************/
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

/*****************************************************
 *             TestGrader::missedQuestions           *
 * Compares student answers to correct answers and   *
 * displays the question numbers of wrong answers.   *
 *****************************************************/
void TestGrader::missedQuestions(char *test)      
{
	for (unsigned question = 0; question < SIZE; question++)
	{
		if (answers[question] != test[question])
			cout << (question+1) << "  ";
	}
	cout << endl;
}

// **************** Client program that uses the class ***************

int main()
{ 
	const int NUM_QUESTIONS = 20;

	string name;                 // Test taker's name
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
				cout << "\nAnswer must be A, B, C, or D -- re-enter answer: "
				     << (q+1) << ": ";
				cin  >> testTakerAnswers[q];
				testTakerAnswers[q] = toupper(testTakerAnswers[q]);
			}
		}
        // Call class function to grade the exam
		cout << "\nResults for " << name << endl;
		DMVexam.grade(testTakerAnswers);

		cout << "\nGrade another exam (Y/N)? ";
		cin >> doAnother;
		cout << endl;
		cin.ignore();       // Clear the \n out of the input buffer 
                            // before doing the next getline
	} while (toupper(doAnother) == 'Y');

	return 0;
}

/* SAMPLE RUN RESULTS

Applicant name: Tom Sawyer
Enter answers for Tom Sawyer.
Use only letters A, B, C, and D.

Q 1: C
Q 2: D
Q 3: A
Q 4: A
Q 5: C
Q 6: A
Q 7: B
Q 8: A
Q 9: C
Q10: D
Q11: D
Q12: C
Q13: D
Q14: A
Q15: D
Q16: C
Q17: D
Q18: B
Q19: D
Q20: A

Results for Tom Sawyer
Congratulations. You passed the exam.
You got 17 questions correct.
You missed the following 3 questions: 1  11  17

Grade another exam (Y/N)? N
*/  
