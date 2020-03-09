// Chapter 11, Assignment 4: Number of Days Worked
#include <cstdlib>
#include <iostream>
using namespace std;

class NumDays
{
private:
    int hoursWorked;
public:
    NumDays(int hW)
    {
        setHours(hW);
    }
    NumDays(){ setHours(0);}
    // Getters
    double getDays(){ return hoursWorked / 8.0;}
    int getHours() { return hoursWorked;}
    
    // Setters
    void setHours(int hW){ hoursWorked  = hW;}
    void setDays(double d) { setHours(8*d);}
    
    friend NumDays operator + (NumDays, NumDays);
    friend NumDays operator - (NumDays, NumDays);
    // Prefix operators
    NumDays  operator++()
    {
       ++ hoursWorked;
       return *this;
    }
    NumDays operator--()
    {
        -- hoursWorked;
        return *this;
    }
    // Postfix operators
     NumDays  operator++(int)
    {
         NumDays temp = *this;
         hoursWorked ++;
         return temp;
    }
    NumDays operator--(int)
    {
         NumDays temp = *this;
         hoursWorked --;
         return temp;
    }
};

/***********************************************
 *              operator +                     *
 ***********************************************/
NumDays operator+(NumDays a, NumDays b)
{
    return NumDays(a.hoursWorked + b.hoursWorked);
}

/***********************************************
 *              operator -                     *
 ***********************************************/
NumDays operator-(NumDays a, NumDays b)
{
    return NumDays(a.hoursWorked - b.hoursWorked);
}

int main() 
{
    NumDays a, b;
    int hours;
    
    cout << "Enter number of hours for the first NumDays object: ";
    cin >> hours;
    a.setHours(hours);
    
    cout << "Number of days is " << a.getDays() << endl;
    
    cout << "Enter number of hours for the second NumDays object: ";
    cin >> hours;
    b.setHours(hours);
    
    cout << "Number of days is " << b.getDays() << endl;
    
    NumDays sum = a + b;
    NumDays diff = a - b;
    
    cout << "The sum is " << sum.getDays() << " days or " << sum.getHours() 
         << " hours." << endl;
    
    cout << "The difference is " << diff.getDays() << " days or " << diff.getHours() 
         << " hours." << endl;  
    
    cout << "Enter number of hours for a NumDays object: ";
    cin >> hours;
    a.setHours(hours);
    a ++;
    cout << "One more hour is " << a.getHours() << " hours or " << a.getDays()
         << " days." << endl;
    
    return 0;
}

