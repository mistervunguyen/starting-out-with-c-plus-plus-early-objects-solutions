// Chapter 8 - Programming Challenge 9, LoShu Magic Square
// Given a 3 x 3 array of integers, this program determines whether or not it
// is a Lo Shu Magic Square. That is a 3x3 grid holding the digits 1-9 exactly, 
// in which all rows, columns, and diagonals add up to the same value. Students
// may assume that the array holds one instance each of the digits 1-9. The
// The problem does not require that the array be displayed or that both tests
// be done in the same run.
#include <iostream>
using namespace std;

const int SIZE = 3;  // Arrays will be 2-D 3x3 arrays

// Function prototype
void showArray (int[][SIZE]);
bool isMagicSquare(int[][SIZE]);

int main()
{	
	int array1[][SIZE] = {{ 5, 4, 6 },  // NOT "magic"
	                      { 3, 2, 1 },  // col & diag sums = 15
	                      { 7, 9, 8 }}; // but row sums don't

	int array2[][SIZE] = {{ 4, 9, 2 },  // "magic"
	                      { 3, 5, 7 },
	                      { 8, 1, 6 }};
		          
	cout << "Here is array 1 \n\n";
	showArray(array1);
	if (isMagicSquare(array1))
		cout << "\nIt is a magic square\n\n";
	else
		cout << "\nIt is not a magic square\n\n";

	cout << "Here is array 2 \n\n";
	showArray(array2);
	if (isMagicSquare(array2))
		cout << "\nIt is a magic square\n\n";
	else
		cout << "\nIt is not a magic square\n\n";
	
	return 0;
}

/*********************************************************************
 *                             showArray                             *
 * This function displays the contents of the 2D array passed to it. *
 *********************************************************************/
void showArray (int A[][SIZE])
{
	for (int row = 0; row < SIZE; row++)
	{
		for (int col = 0; col < SIZE; col++)
			cout << A[row][col] << " ";

		cout << endl;
	}
}

/***************************************************************
 *                           isMagicSquare                     *
 * This Boolean function determines if the 3 x 3 array of      *
 * integers passed to it is a magic square or not. A magic     *
 * square must contain one instance of each digit 1-9 and      *
 * every row, column, and diagonal must sum to the same value. *
 ***************************************************************/
bool isMagicSquare(int A[][SIZE])
{
	int sum1 = 0, sum2 = 0, sum3 = 0;
	
	// Check column sums
	for (int row = 0; row < SIZE; row++)
	{
		sum1 += A[row][0];
		sum2 += A[row][1];
		sum3 += A[row][2];
	}
	if (!(sum1 == sum2 && sum2 == sum3))
		return false;
		
	// If column sums are OK, check row sums
	// But first reinitialize the accumulators
	sum1 = sum2 = sum3 = 0;

	for (int col = 0; col < SIZE; col++)
	{
		sum1 += A[0][col];
		sum2 += A[1][col];
		sum3 += A[2][col];
	}
	if (!(sum1 == sum2 && sum2 == sum3))
		return false;

	// If row sums are also OK, compute the 2 diagonal sums
	// Let sum3 continue to hold the value the diagonal sums should equal
	sum1 = A[0][0] + A[1][1] + A[2][2];  // Right diagonal
	sum2 = A[0][2] + A[1][1] + A[2][0];  // Left diagonal
	if (!(sum1 == sum2 && sum2 == sum3))
		return false;

	// If we got this far. Everthing adds up to the same value.
	return true;
}

/* RUN RESULTS USING THIS PROGRAM'S DATA SETS

Here is array 1

5 4 6
3 2 1
7 9 8

It is not a magic square

Here is array 2

4 9 2
3 5 7
8 1 6

It is a magic square
*/
