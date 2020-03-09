// Chapter 16, Assignment 10, Two Dimensional Data
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
 
using namespace std;

/****************************************************************
 *                 getData                                      *
 *  Retrieves data from the file and stores it into two vectors *
 ****************************************************************/
void getData(ifstream & inFile, vector<string> &tourists,
              vector<vector<string> > &destinations)
{
    
    // read and store the list of people that are tourists
    int number;
    inFile >> number;
    tourists.resize(number);
    destinations.resize(number);    
    for (int k = 0; k < number; k++)
    {
       int index;
       string name;
       inFile >> index >> name;
       tourists[index] = name;       
    }

    // read and sotre the list of favourite destination for each person
    for (int k = 0; k < number; k++)
    {
        int index;
        int numberDestinations;
        vector<string> destVector;
        inFile >> index >> numberDestinations;

        for (int j = 0; j < numberDestinations; j++)
        {
            string dest;
            inFile >> dest;
            destVector.push_back(dest);
        }
        destinations[index] = destVector;
    }
}

/*****************************************************************
 *  Returns the index of a string in a vector of strings, or     *
 * -1 if the searched for string is not found.                   *
 *****************************************************************/
int indexOf(vector<string> vec, string name)
{
    for (int k = 0; k < vec.size(); k++ )
    {
        if (name == vec[k]) return k;
    }
    return -1;
}


int main(int argc, char** argv)
{
    
    ifstream inFile("tourists.txt");
    if (!inFile)
    {
        cout << "Cannot open the file tourists.txt";
        return 1;
    }
   
    vector <string> tourists;
    vector<vector<string> > destinations;
    getData(inFile, tourists, destinations);

    // Print names of tourists
    cout << "Names of tourists are:\n";
    for (int k = 0; k < tourists.size(); k++)
    {
        cout << tourists[k] << endl;
    }

    // Interact with the user
    cout << "Enter name of tourists as prompted, type 'quit' to end.\n";
    string name;
    while (true)
    {
        cout << "tourist ?: ";
        cin >> name;
        if (name == "quit") break;
        int index = indexOf(tourists, name);
        if (index == -1) 
        {
            cout << "There is no such tourist." << endl;
            continue;
        }
        // print the list of destinations
        vector<string>::iterator iter = destinations[index].begin();
        while (iter != destinations[index].end())
        {
            cout << *iter << "  ";
            iter ++;
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}

