// Chapter 19, Assignment 9, Cousins
// This program demonstrates a function that is able to find
// all cousins of a person in genealogy teee.

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
enum Gender{ male, female};
class Person
{
   string name;
   Gender gender;
   vector<Person *> parents;
   vector<Person *> children;
public:
    Person (string name, Gender g)
    {
        this->name = name;
        gender = g;
    }
   string getName(){ return name; };
   Gender getGender(){ return gender; };
   Person *addChild(string name, Gender g);
   Person *addChild(Person *p);

   void addParent(Person *p);
   int getNumberOfParents(){return parents.size();}
   Person *getParent(int k){ return parents[k];}
   int getNumberOfChildren(){ return children.size();}
   Person *getChild(int k) { return children[k]; }

   friend ostream &operator << (ostream &out, Person p);
};

//************************************************************
// Create a child with specified name and gender, and        *
// set one of the parents to be this person.                 *
// Add the new child to the list of childfen for this person *
//************************************************************
Person *Person::addChild(string name, Gender g)
{
    Person *child = new Person(name, g);
    child->addParent(this);     // I am a parent of this child
    children.push_back(child);  // This is one of my children
    return child;               // Returned for the benefit of other parent
}
//************************************************************
// Add a child to the list of children for this person       *
//************************************************************
Person *Person::addChild(Person* child)
{
   child->addParent(this);
   children.push_back(child);
   return child;              // Return for uniformity with other addChild
}
//******************************************
// Add a person as a parent of this Person *
//******************************************
void Person::addParent(Person* p)
{
    parents.push_back(p);
}
//*********************************************************
//  Overloaded stream insertion operator for Person class *
//  uses an XML-type format to output the data            *
//*********************************************************
ostream & operator<<(ostream & out, Person p)
{
    out << "<Person name = " << p.name << ">" << '\n';
    if (p.parents.size() > 0)
        out << "  <parents>" << '\n';
    for (unsigned int k = 0; k < p.parents.size(); k++)
    {
        out << "    " << p.parents[k]->name << '\n';
    }
    if (p.parents.size() > 0)
       out << "  </parent>" << '\n';
    if (p.children.size() > 0)
       out << "  <children>" << '\n';
    for (unsigned int k = 0; k < p.children.size(); k++)
    {
        out << "    " << p.children[k]->name << '\n';
    }
    if (p.children.size() > 0)
         out << "  </children>" << '\n';
    out << "</Person>" << '\n';
    return out;
}

//***********************************************
// Add  siblings of a given person to a vector  *
// (including step siblings)                      *
//***********************************************
void addSiblings(Person *p, vector<Person*>& siblings)
{
  // Look at children of each parent
  for (int k = 0; k < p->getNumberOfParents(); k++)
  {
    Person *parent = p->getParent(k);
    // Get all children of this parent that are not p, and not already added
    for (int j = 0; j < parent->getNumberOfChildren(); j++)
    {
        Person *sibl = parent->getChild(j);
        if (sibl != p && find(siblings.begin(), siblings.end(), sibl) == siblings.end())
            siblings.push_back(sibl);
    }
  }
}

void addCousins(Person *p, vector<Person*>& cousins)
{
	// get siblings of parents
	vector<Person*> unclesAndAunts;
	for (int k = 0; k < p->getNumberOfParents(); k++)
	{       
		addSiblings(p->getParent(k), unclesAndAunts);
	}
	// get children of every uncle and aunt
	
	for (unsigned int k = 0; k < unclesAndAunts.size(); k++)
	{
		// Look at each child of this uncle or aunt
		int nChildren = unclesAndAunts[k]->getNumberOfChildren();
		for (int j = 0; j < nChildren; j++)
		{
		   // Add a cousin to the list of cousins if not already added
           Person *cous = unclesAndAunts[k]->getChild(j);
		   if (find(cousins.begin(), cousins.end(), cous) == cousins.end())
			   cousins.push_back(cous);
		}
	}
}


int main(int argc, char** argv)
{
    Person adam("Adam", male), amelia("Amelia", female),
           alan("Alan", male), anna("Anna", female);
    
    //Children of Adam and Amelia
    Person * pBob = amelia.addChild("Bob", male);
    adam.addChild(pBob);
    Person *pCarol = amelia.addChild("Carol", female);
    adam.addChild(pCarol);

    //Child of Amelia and Alan
    Person  *pDiane = amelia.addChild("Diane", female);
    alan.addChild(pDiane);

    //Child of Alan and Anna
    Person *pElaine = anna.addChild("Elaine", female);
    alan.addChild(pElaine);

    //Add some third generationers so you can have cousins
	Person *pPeter = pBob->addChild("Peter", male);
	Person *pPaul = pCarol->addChild("Paul", male);
	Person *pMary = pCarol->addChild("Mary", female);
	Person *pZoe = pDiane->addChild("Zoe", female);

    //Find the cousins of at least two people
	vector<Person *> v;

    cout << "Peter's cousins are: ";
    addCousins(pPeter, v);
    for (unsigned int k = 0; k < v.size(); k++)
    {
        cout << v[k]->getName() << " ";
    }
    cout << endl;

    cout << "Paul's cousins are:";
    v.clear();
    addCousins(pPaul, v);
    for (unsigned int k = 0; k < v.size(); k++)
    {
        cout << v[k]->getName() << " ";
    }
    cout << endl;
    return 0;
}


