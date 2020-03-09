// Chapter 12, Assignment 18, User name
// This program greets the user by their login name
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
	// Gain access to the enviroment.
    extern char **environ;
    
	// Search for an entry that starts with "USERNAME" and then takes
	// the substring that starts right after the = to be the user's login name.
    for (int k = 0; environ[k] != 0; k++)
    {
		string entry = environ[k];
		size_t pos = entry.find("USERNAME");
        if (pos != 0) continue;
	    pos = entry.find("=");
		cout << "Hello " << entry.substr(pos+1) << endl;        
    }
    return 0;
}
