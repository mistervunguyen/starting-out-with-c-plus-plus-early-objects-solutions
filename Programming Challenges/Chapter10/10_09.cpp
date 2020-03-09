// Programming Challenge 10-9
// How Old Are You Now?  Given a user's birthday, this program determines the that person's current age
#include <iostream>
#include <ctime>
#include <string>
using namespace std;
 
int main()
{
  time_t epoch;
  int birthYear;   // User's year of birth
  string name;     // Name of user
  tm *time_info;   // Pointer to time info structure to use with localtime

  // Interact with the user
  cout << "Tell me your name: ";
  cin >> name;
  cout << "What year were you born? (Format 18XX, 19XX or 20XX)";
  cin >> birthYear;

  // Determine the current time so we can determine the current time
  time(&epoch); 
  time_info = localtime(&epoch);
  
  // Declare the user's age
  cout << "Hello, " << name << " You are " << time_info->tm_year + 1900 - birthYear << " years old" 
	   << endl;;

  return 0;
}