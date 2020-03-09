// Chapter 6 - Programming Challenge 9, Star Search
// This program awards a score to a talent show contestant by
// averaging the three middle scores assigned by five judges.
// Because student have not yet learned about arrays, each score
// must be kept in a separate variable.
#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
void getJudgeData(double &);	
double calcScore(double, double, double, double, double);			
double findLowest(double, double, double, double, double);			
double findHighest(double, double, double, double, double);		
int main()
{
	double score1, score2, score3, score4, score5,   // 5 judge's scores
		   finalScore;
   
	// Inform the user what the program does
	cout << "After you enter 5 judge scores for this contestant, \n"
		<< "this program will drop the highest and lowest score \n"
		<< "and then average the remaining three scores.\n\n";
	
	// Call getJudgeData once for each score to be input
	getJudgeData(score1);
	getJudgeData(score2);
	getJudgeData(score3);
	getJudgeData(score4);
	getJudgeData(score5);

	// Call calcScore to calculate the contestant's final score
	finalScore = calcScore(score1, score2, score3, score4, score5);
	
	cout << fixed << showpoint << setprecision(2);
	cout << "\nThis contestant's talent score is " << finalScore << endl;

	return 0;
}// end of main function

/*********************************************************************
 *                         getJudgeData                              *
 * This function is called by main once for each judge's score to be *
 * input and validated. The score is stored in a reference parameter.*
 *********************************************************************/
void getJudgeData(double &score)
{
	cout << "Enter score between 0 and 10: ";
	cin  >> score;
	while (score < 0 || score > 10) 
	{
		cout << "Score must be in the range 0 - 10. "
			 << "Please re-enter score: ";
		cin  >> score;
	}
}// end of function getJudgeData

/********************************************************
 *                       calcScore                      *
 * This function is called by main to find and return   *
 * the average of the scores passed to it as arguments, *
 * after dropping the lowest and highest score.         *  
 ********************************************************/
double calcScore(double s1, double s2, double s3, double s4, double s5)
{
	double middleSum,          // Sum of the middle three scores
		   lowScore,           // Low score that will be dropped
		   hiScore,            // High score that will be dropped
		   finalScore;

	// Call function findLowest, passing it the 5 scores.  When the
	// lowest score is returned, store it in the variable lowScore.
	lowScore = findLowest(s1, s2, s3, s4, s5);

	// Call function findHighest, passing it the 5 scores.  When the
	// highest score is returned, store it in the variable hiScore.
	hiScore = findHighest(s1, s2, s3, s4, s5);

	// Calculate the sum and average of the middle 3 scores
	middleSum = s1 + s2 + s3 + s4 + s5 - lowScore - hiScore;
	finalScore = middleSum / 3.0;         // prevent an integer divide
	
	return finalScore;
}// end of function calcScore

/***************************************************************
 *                          findLowest                         *
 * This function determines which of the 5 scores passed to it * 
 * as arguments is the lowest, and returns this score.         *
 **************************************************************/
double findLowest(double s1, double s2, double s3, double s4, double s5)
{
	double lowest = s1;

	if (s2 < lowest) 
		lowest = s2;
	if (s3 < lowest)
		lowest = s3;
	if (s4 < lowest)
		lowest = s4;
	if (s5 < lowest)
		lowest = s5;
	return lowest;
}// end of function findLowest

/***************************************************************
 *                          findHighest                        *
 * This function determines which of the 5 scores passed to it *
 * as arguments is the highest, and returns this score.        *
 ***************************************************************/
double findHighest (double s1, double s2, double s3, double s4, double s5)
{
	double highest = s1;

	if (s2 > highest)
		highest = s2;
	if (s3 > highest)
		highest = s3;
	if (s4 > highest)
		highest = s4;
	if (s5 > highest)
		highest = s5;
	return highest;
}// end of function findHighest

/* SAMPLE RUN RESULTS

After you enter 5 judge scores for this contestant,
this program will drop the highest and lowest score
and then average the remaining three scores.

Enter score between 0 and 10: 9
Enter score between 0 and 10: 8
Enter score between 0 and 10: 8
Enter score between 0 and 10: 7
Enter score between 0 and 10: 9

This contestant's talent score is 8.33
*/