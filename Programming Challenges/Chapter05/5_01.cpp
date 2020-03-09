// Chapter 5 - Programming Challenge 1, Characters for the ASCII Codes
// This program uses a while loop to display the printable characters 
// corresponding to ASCII codes 32 - 127. Students might also choose
// to use a for loop. Note that ASCII 32 is a blank space, so the first
// "character" printed on the first output line is a blank.

#include <iostream>
using namespace std;

int main()
{
	int code = 32;
	while (code <= 127)
	{
		// Print the character corresponding to this code
		cout << static_cast<char>(code) << "   ";

		// Go to the next code
		code++;

		// After 16 chars have printed, start a new line
		if (code % 16 == 0)
			cout << endl;
	}
	return 0;
}
