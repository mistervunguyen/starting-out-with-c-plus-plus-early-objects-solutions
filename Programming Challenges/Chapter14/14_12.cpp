// Chapter 14- Assignment 12, Ancestral Trees
#include <cstdlib>
#include <iostream>
using namespace std;
 
const string people[] = {"Al", "Beth", "Bob", "Carol", "Chuck", 
                         "Candy", "Cain", "Debbie", "Doug", 
                         "Diane", "Dwayne", "Delores", "Dwight"  
                        };
const string mother[] = {"Beth", "Carol", "Charity", "Debbie", 
                         "Diane", "", "Delores"
                        };
const string father[] = {"Bob", "Charley", "Cain", "Douglas", 
                         "Dwayne", "", "Dwight"
                        };
const int mom[] = {1, 3, 5, 7, 9, -1, 11, -1, -1, -1, -1, -1, -1};
const int pop[] = {2, 4, 6, 8, 10, -1, 12, -1, -1, -1, -1, -1, -1};


void ancestors(int person);

//********************************************************
// Prints out all the ancestors of a person.             *
// A Person is considered to be his or her own ancestor. *
//********************************************************
void ancestors(int p)
{
   // Print out the person 
   cout << people[p] << "   " ;
   // If the person's mother is known, print out all the ancestors of the mother
   if (mom[p] != -1)  ancestors(mom[p]);
   // If the person's father is known, print out all the ancestors of the father
   if (pop[p] != -1)  ancestors(pop[p]);    
}


int main(int argc, char** argv) 
{
  // Demonstrate correctness by printing out ancestors of some people
  cout << "The ancestors of " << people[0] << " are ";
  ancestors(0);
  cout << endl;
  cout << "The ancestors of " << people[6] << " are ";
  ancestors(6);
  return 0;
}

