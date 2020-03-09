// Chapter 8 - Programming Challenge 19, Tic-Tac-Toe Game
// This program allows two players to play a game of tic-tac-toe.
// The game continues until the program detects and announces
// either a winner or a tie.

#include <iostream>
#include <string>
using namespace std;

const int PLAYER_ROWS = 3,
          PLAYER_COLS = 3,
          DISPLAY_ROWS = 9,
		  DISPLAY_COLS = 11;
		  
// Function prototypes
void displayBoard(char[][11]);
void makeMove(char[][11], char[][PLAYER_COLS], bool);
bool boardFull(char[][PLAYER_COLS]);
bool isaWinner(char[][PLAYER_COLS], char);

int main()
{
	bool xTurn = true;        // X goes first. When xTurn = false, it is 0's turn.
	bool xWins = false,       // No one has won yet
		 oWins = false;

	// Set up an array to hold the game board
	char gameBoard[DISPLAY_ROWS][DISPLAY_COLS] =
		{{' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' '},  // Line type 1
		 {' ', '*', ' ', '|', ' ', '*', ' ', '|', ' ', '*', ' '},  // "Move line
		 {'_', '_', '_', '|', '_', '_', '_', '|', '_', '_', '_'},  // Line type 2
		 {' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' '},  // Line type 1
		 {' ', '*', ' ', '|', ' ', '*', ' ', '|', ' ', '*', ' '},  // "Move line
		 {'_', '_', '_', '|', '_', '_', '_', '|', '_', '_', '_'},  // Line type 2
		 {' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' '},  // Line type 1
		 {' ', '*', ' ', '|', ' ', '*', ' ', '|', ' ', '*', ' '},  // "Move line
		 {' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' '}}; // Line type 1

	// Set up an array to hold just the moves
	char moves[PLAYER_ROWS][PLAYER_COLS] = {'*', '*', '*',
                                            '*', '*', '*',
                                            '*', '*', '*'};

	// Continue playing as long as there is NOT yet a winner or a tie
	while ( !(xWins || oWins || boardFull(moves)) )
	{
		// Display the board
		displayBoard(gameBoard);

		// Allow player whose turn it is to move
		makeMove(gameBoard, moves, xTurn);

		// See if there is a winner yet
		if (xTurn && isaWinner(moves, 'X'))
			xWins = true;
		else if (!xTurn && isaWinner(moves, 'O'))
			oWins = true;

		// Make it the other player's turn next
		xTurn = !xTurn;
	}
	// Announce the winner & display the final board
	if (xWins)
		cout << "\n**** GAME OVER -- X WINS! ****\n";
	else if (oWins)
		cout << "\n**** GAME OVER -- O WINS! ****\n";
	else
		cout << "\n**** GAME OVER -- It's a TIE. ****\n";

	displayBoard(gameBoard);
   
	return 0;
}

/************************************************************
 *                      displayBoard                        *
 * This function displays the current game board.           *
 ************************************************************/
void displayBoard(char gameBoard[][DISPLAY_COLS])
{
	string spaces = "          ";

	for (int row = 0; row < DISPLAY_ROWS; row++)
	{
		cout << endl << spaces;
		for (int col = 0; col < 11; col++)
			cout << gameBoard[row][col];
	}
	cout << endl << endl;
}

/************************************************************
 *                        boardFull                         *
 * This function returns true if the board is full,         *
 * and false otherwise.                                     *
 ************************************************************/
bool boardFull(char moves[][PLAYER_COLS])
{
	// If any '*' is found, return false
	// Game board is not full
	for (int row = 0; row < PLAYER_ROWS; row++)
	{
		for (int col = 0; col < PLAYER_COLS; col++)
		{
			if (moves[row][col] == '*')
				return false;
		}
	}
	// If we got this far without returning, the board is full
	return true;
}
         
/************************************************************
 *                          makeMove                        *
 * This function allows a player to make a legal move and   *
 * updates the moves array and the gameBoard with the new   *
 * game configuration.                                      *
 ************************************************************/
void makeMove(char gameBoard[][DISPLAY_COLS], char moves[][PLAYER_COLS], bool xTurn)
{
	int row,          // Row & column player chose
		col,
		moveRow,      // Actual array row & column of the move
		moveCol;
	char sign;        // X or O

	if (xTurn)
	{	cout << "\nX's turn - Enter your move \n";
		sign = 'X';
	}
	else
	{	cout << "\nO's turn - Enter your move \n";
		sign = 'O';
	}

	cout << "Row (1-3) and column (1-3) separated by a space: ";
	cin  >> row >> col;

	// Validate that move is a legal, untaken space
	while (row < 1 || col < 1 || row > PLAYER_ROWS || 
		   col > PLAYER_COLS  || moves[row-1][col-1] != '*')
	{
		cout << "\nRow and column must be a \"free\" space between 1 and 3.\n";
		cout << "Re-enter row (1-3) and column (1-3) separated by a space: ";
		cin  >> row >> col;
	}

	// Record move in the moves array
	moveRow = row-1;                   // Actual move rows are 0, 1, 2
	moveCol = col-1;                   // Actual move cols are 0, 1, 2
	moves[moveRow][moveCol] = sign;

	// Record move in the gameBoard array
	moveRow = moveRow * 3 + 1;        // gameBoard display rows are 1, 4, 7
	moveCol = moveCol * 4 + 1;        // gameBoard display cols are 1, 5, 9
	gameBoard[moveRow][moveCol] = sign;   
}
 
/************************************************************
 *                        isaWinner                         *
 * This function returns true if a player has "won"         *
 * (i.e., 3 X's or O's in a row, column or diagonal)        *
 * and false otherwise.                                     *
 ************************************************************/
bool isaWinner(char moves[][PLAYER_COLS], char sign)
{
	// Check rows
	for (int row = 0; row < PLAYER_ROWS; row++)
	{	if (moves[row][0] == sign && moves[row][1] == sign && moves[row][2] == sign)
			return true;
	}

	// Check columns
	for (int col = 0; col < PLAYER_COLS; col++)
	{	if (moves[0][col] == sign && moves[1][col] == sign && moves[2][col] == sign)
			return true;
	}

	// Check right and left diagonals
	if (moves[0][0] == sign && moves[1][1] == sign && moves[2][2] == sign)
		return true;
	if (moves[0][2] == sign && moves[1][1] == sign && moves[2][0] == sign)
		return true;

	// If we got this far, there is no winner yet
	return false;
}
