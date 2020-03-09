//  Chapter 13 --  Assignment 17:  Customer Accounts 
//  This group project for maintaining customer records.

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
using namespace std;

fstream custFile;
fstream tempFile;      // For deletion swap


const int NAME_LEN = 45;
const int ADDR_LEN = 45;
const int CITY_LEN = 20;
const int STATE_LEN = 4;
const int ZIP_LEN = 11;
const int PHONE_LEN = 14;
const int ARRAY_SIZE = 11;

// Structure used to represent customer data
struct Customer
{
    char name[NAME_LEN];
    char address[ADDR_LEN];
    char city[CITY_LEN];
    char state[STATE_LEN];
    char zip[ZIP_LEN];
    char phone[PHONE_LEN];
    double balance;
    char lastPay[ARRAY_SIZE];
};

// Prototypes
void setInfo(long);       // Write record to file
void display(long);       // Display one record
long search();            // Find a record & return file position
void deleteRec(long);     // Delete one record
void showAll();           // Display all records

                          // Flags to signal setInfo()
bool rnew = 0;            // ...if record is rnew	
bool mod = 0;             // ...if record is being modified

int main()
{
    long fpos;            // File position
    int choice = 6;
    char YorN;
    do
    {
        cout << "\n * * * * M A I N   M E N U * * * * * * * \n\n";
        cout << "1. Enter a new Customer Account\n";
        cout << "2. Display a Customer Account\n";
        cout << "3. Delete a Customer Account\n";
        cout << "4. Change a Customer Account\n";
        cout << "5. Display All Customer Accounts\n";
        cout << "6. Exit the program\n\n";
        
        // Determine user's choice
        do
        {
            cout << "Enter your choice (1-6): ";
            cin >> choice;
        }     while (choice < 1 || choice > 6);
        
        // Process user's choice
        switch (choice)
        {
          case 1:  
            cin.get();
            cout << "\nYou selected Enter a new Customer Account.\n\n";
            rnew = 1;
            setInfo(0);  
            rnew = 0;
            break;
        case 2: 
            cout << "\nYou selected Display a Customer Account.\n\n";
            fpos = search();
            if (fpos != -1)
            {
                display(fpos); 
            }
            else
                cout << "\nRecord not found.";
            break;
        case 3: 
            cout << "\nYou selected Delete a Customer Account.\n\n";
            fpos = search();
            if (fpos != -1)
            {
                display(fpos);
                cout << "\nARE YOU SURE YOU WANT TO DELETE THIS RECORD? (Y/N) ";
                cin >> YorN;
                YorN = toupper(YorN);
                if (YorN == 'Y')
                {
                    deleteRec(fpos);
                    break;
                }
                else
                {
                    cout << "\nRecord was not deleted.\n";
                    break;
                }
            }
            else
                cout << "\nRecord not found.\n";
            break;
        case 4: 
            cout << "\nYou selected Change a Customer Account.\n\n";
            fpos = search();
            mod = 1;
            if (fpos != -1)
            {    
                cout << "\nRECORD CONTENTS: \n";
                display(fpos);
                cout << "\nENTER NEW CONTENTS: \n";
                setInfo(fpos);
                mod = 0;
            }
            else
                cout << "\nRecord not found.\n";
                break;
        case 5: 
            cout << "\nYou selected Display All Customer Account.\n\n";
            showAll();
            break;
        case 6:
            exit(0);
            break;
        default:  // Anything not between 1-5
            break;
        } // End switch

    } while (choice != 6);
    return 0;
}// End main

// Function definitions

//**************************************************
//                 setInfo                         *
// Get info for customer record and write to file. *
//**************************************************
void setInfo(long fp)  
{
    Customer c;
    int valid;

    do
    {
       valid = 1;
       cout << "\nPlease enter the following information:\n";
       cout << "\nCustomer name: ";
       cin.getline(c.name, 45);
       cout << "Customer address: ";
       cin.getline(c.address, 45);
       cout << "City: ";
       cin.getline(c.city, 20);
       cout << "State: ";
       cin.getline(c.state, 4);
       cout << "Zip: ";
       cin.getline(c.zip, 11);
       cout << "Telephone: ";
       cin.getline(c.phone, 14);
       cout << "Account balance: ";
       cin >> c.balance;
       cin.get();
       cout << "Date of last payment: ";
       cin.getline(c.lastPay, 11);

       if (strlen(c.name) ==0 || strlen(c.address) == 0 || strlen(c.city) ==0 ||
          strlen(c.state) == 0 || strlen(c.zip) == 0 || strlen(c.lastPay) == 0)
       {
          cout << "You must enter information for each field.\n";
          valid = 0;
       }
       if (c.balance < 0)
       {
           cout << "Please enter 0 or geater for account balance.\n";
           valid = 0;
       }
    } while (!valid);

    if (rnew)
    {
        custFile.open("cust.dat", ios::out | ios::app | ios::binary );
    }
    else if (mod)
    {
       custFile.open("cust.dat", ios::in | ios::out | ios::binary);
       custFile.seekp(fp, ios::beg);
    }

    if (custFile.fail())
    {
        cout << "\nError opening file.\n";
        return;
    }
    
    custFile.write(reinterpret_cast<char*>(&c), sizeof(c));
    if (custFile.fail())
    {
        cout << "\nError writing record to file.\n";
        custFile.clear();
        custFile.close();
        return;
    }
    else
    {
        cout << "\nRecord written to file.\n\n";
        custFile.clear();
        custFile.close();
        cout << "\nPress Enter to continue...";
        cin.get();
        return;
    }
} 

//**********************************************
//              display                        *
//  display record at a given file position.   *
//**********************************************
void display(long fp)
{
    Customer c;
    custFile.open("cust.dat", ios::in | ios::binary);
    if (custFile.fail())
    {
        cout << "\nError opening file.\n";
        return;
    }
    if (custFile.peek() == EOF)
    {
        cout << "\nFile is empty.\n";
        custFile.clear();
        custFile.close();
        return;
    }
    custFile.seekg(fp, ios::beg);
    custFile.read(reinterpret_cast<char*>(&c), sizeof(Customer));
    
    cout.precision(2);
    cout.setf(ios::fixed | ios::showpoint);
    cout << "Customer name: " << c.name << endl;
    cout << "Customer address: " << c.address << endl;
    cout << "City: " << c.city << endl;
    cout << "State: " << c.state << endl;
    cout << "Zip: " << c.zip << endl;
    cout << "Telephone: " << c.phone << endl;
    cout << "Account balance: $" << c.balance << endl;
    cout << "Date of last payment: " << c.lastPay << endl;
    custFile.clear();
    custFile.close();
    cout << "\nPress Enter to continue.";
    cin.get();
}

//************************************
//         search                    *
// Returns file pointer position     *  
// of a customer record.             *
//************************************

long search()  
{
    char name[45];
    Customer c;
    long fp;
    cout << "\nEnter all or part of the customer name: ";
    cin.ignore();
    cin.getline(name, 45);
    if (name[0] == '\0') // If nothing is entered, do nothing
    {
        return -1;
    }
    custFile.open("cust.dat", ios::in | ios::binary);
    if (custFile.fail())
    {
        cout << "\nError opening file.\n";
        return -1;
    }

    while (true)
    {
        custFile.read(reinterpret_cast<char*>(&c), sizeof(Customer));  // Read one record
        if (custFile.fail())
           break;
        if (strstr(c.name, name) != NULL) // If search value matches customer name...
        {
            fp = custFile.tellg();
            custFile.clear();
            custFile.close();
            return (fp - sizeof(c));
        }
    }
    cout << "Record not found\n";
    custFile.clear();
    custFile.close();
    return -1;
}


//**************************************
//         showAll                     *
//  Show records in file.              *
//**************************************
void showAll()
{    
    cin.ignore();
    Customer c;
    int count= 0;
    custFile.open("cust.dat", ios::in | ios::binary);
    if (custFile.fail())
    {
        cout << "\nError opening file.\n";
        return;
    }
    cout << "\n***Begin Customer Record Listing***\n\n";

    while (custFile.peek()!=EOF)
    {
        custFile.read(reinterpret_cast<char*>(&c), sizeof(Customer));
        cout << setprecision(2);
        cout << fixed  << showpoint;
        cout << "\nRECORD NUMBER " << ++count << ":" << endl;
        cout << "\nCustomer name: " << c.name << endl;
        cout << "Customer Address: " << c.address << endl;
        cout << "City: " << c.city << endl;
        cout << "State: " << c.state << endl;
        cout << "Zip: " << c.zip << endl;
        cout << "Telephone: " << c.phone << endl;
        cout << "Account Balance: $" << c.balance << endl;
        cout << "Date of Last Payment: " << c.lastPay << endl;
        cout << endl;
        cout << "\nPress Enter to Continue...";
        cin.get();
    }
    if (count == 0)
    {
        cout << "\nFile is empty." << endl;
    }
    cout << "\n***End of Customer Record Listing***\n\n";
    custFile.clear();
    custFile.close();

}

//******************************************************************
//               deleteRec                                         *
// This function marks a record for deletion by placing            *
// the null terminator at the beginning of the name member.        *
// The contents of the file are then copied to a temporary file,   *
// then the temporary file is copied back to the Customer file     *
// without the deleted record.                                     *
// Ideally, this function would be expanded to allow multiple      *
// record deletions before the final file swap takes place.        *
//******************************************************************
void deleteRec(long fp)
{
    Customer c;
    int Rec = 0;
    custFile.open("cust.dat", ios::in | ios::out | ios::binary);
    if (custFile.fail())
    {
        cout << "\nError opening file.\n";
        return;
    }

    // Mark the file at offset fp for deletion
    strcpy(c.name, "\0");          // Indicates deletion of record
    custFile.seekp(fp, ios::beg);
    custFile.write(reinterpret_cast<char*>(&c), sizeof(c));
    custFile.clear();
    custFile.close();

    // Copy customer file to temporary file
    custFile.open("cust.dat", ios::in | ios::binary);
    tempFile.open("temp.dat", ios::out | ios::binary);    
    while (custFile.peek() != EOF)
    {
        custFile.read(reinterpret_cast<char*>(&c), sizeof(c));
        tempFile.write(reinterpret_cast<char*>(&c),sizeof(c));
    }
    custFile.clear();
    tempFile.clear();
    custFile.close();
    tempFile.close();

    // Copy  temporary file to customer file, skipping 
    // the records that are marked for deletion
    tempFile.open("temp.dat", ios::in | ios::binary);
    custFile.open("cust.dat", ios::out | ios::binary);
    while (true)
    {
        tempFile.read(reinterpret_cast<char*>(&c), sizeof(c));
        if (tempFile.fail())
              break;
        if (c.name[0] != '\0')
        {
            custFile.write(reinterpret_cast<char*>(&c), sizeof(c));
        }
    }
    tempFile.clear();
    tempFile.close();
    custFile.clear();
    custFile.close();
    cout << "\nDeletion successful.\n";
}
