// Chapter 4 - Programming Challenge 14, Personal Best
// This program displays information on a pole vaulter's 3 
// best vaults. It lists the height (in meters) and date of  
// each vault in order of height, with the best first.
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	string name,
	       date1, date2, date3;       // Dates of 3 best vaults
	double vault1, vault2, vault3;    // Heights of 3 best vaults 
	
	// Input the althlete's name and vault information
	cout << "Athlete's first name: ";
	getline(cin, name);

	cout << "Enter the dates and heights of your 3 best vaults "
		 << "this season.\n";

	cout << "\nDate 1 (mm/dd/yy): ";
	cin  >> date1;
	cout << "Vault height (in meters): ";
	cin  >> vault1;

	cout << "\nDate 2 (mm/dd/yy): ";
	cin  >> date2;
	cout << "Vault height (in meters): ";
	cin  >> vault2;

	cout << "\nDate 3 (mm/dd/yy): ";
	cin  >> date3;
	cout << "Vault height (in meters): ";
	cin  >> vault3;

	// List vaults in order of height (best first)
	cout << fixed << showpoint << setprecision(2);
	cout << "\n-------------------------------------------";
	cout << "\nBest vaults for " << name << " in order of height";
	cout << "\n-------------------------------------------\n";

	// Find and display best vault
	if (vault1 > vault2 && vault1 > vault3)  
		cout << vault1 << " meters on " << date1 << endl;
	else if (vault2 > vault3) 
		cout << vault2 << " meters on " << date2 << endl;
	else
		cout << vault3 << " meters on " << date3 << endl;
      
	// Find and display second best vault
	if ((vault1 < vault2 && vault1 > vault3) || 
		(vault1 > vault2 && vault1 < vault3))
		cout << vault1 << " meters on " << date1 << endl;
	else if ((vault2 < vault1 && vault2 > vault3) || 
		     (vault2 > vault1 && vault2 < vault3))
		cout << vault2 << " meters on " << date2 << endl;
	else
		cout << vault3 << " meters on " << date3 << endl;

	// Find and display third best vault
	if (vault1 < vault2 && vault1 < vault3)
		cout << vault1 << " meters on " << date1 << endl;
	else if (vault2 < vault3)
		cout << vault2 << " meters on " << date2 << endl;
	else
		cout << vault3 << " meters on " << date3 << endl;
	
	return 0;
}

/* SAMPLE RUN RESULTS

Athlete's first name: Sandy
Enter the dates and heights of your 3 best vaults this season.

Date 1 (mm/dd/yy): 05/01/16
Vault height (in meters): 4.2

Date 2 (mm/dd/yy): 05/08/16
Vault height (in meters): 4.1

Date 3 (mm/dd/yy): 05/15/16
Vault height (in meters): 4.3

-------------------------------------------
Best vaults for Sandy in order of height
-------------------------------------------
4.30 meters on 05/15/16
4.20 meters on 05/01/16
4.10 meters on 05/08/16
*/