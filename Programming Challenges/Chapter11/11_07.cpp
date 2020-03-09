//  Chapter 11 --  Assignment 7,  Corporate Sales

#include <iostream>
#include <iomanip>
using namespace std;

const int NUM_DIV = 6;   // Number of divisions

class DivSales
{
private:
    double sales[4];        // There are 4 quarters
    static double totalSales;
public:
    void setSales(double, double, double, double);
    double getQSales(int q)
       { return sales[q]; }
    double getCorpSales()
       { return totalSales; }
};

// Static member variable definition
double DivSales::totalSales;

//****************************************************************
//                      setSales                                 *
// Sets the sales from each division and computes total sales.   *
//****************************************************************
void DivSales::setSales(double q1, double q2, double q3, double q4)
{
    if (q1 < 0 || q2 < 0 || q3 < 0 || q4 < 0)
    {
        cout << "ERROR: Only provide positive values for sales.\n";
        return;
    }
    sales[0] = q1;
    sales[1] = q2;
    sales[2] = q3;
    sales[3] = q4;
    for (int count = 0; count < 4; count++)
        totalSales += sales[count];
}

// Function prototype
void salesByDiv(DivSales []);

int main()
{    
    DivSales divisions[NUM_DIV];
    double qtrs[4];

    for (int div = 0; div < NUM_DIV; div++)
    {
        cout << "Enter sales data for Division ";
        cout << (div + 1) << endl;
        for (int q = 0; q < 4; q++)
        {
            cout << "\tQuarter " << (q + 1) << ": ";
            do
            {
                cin >> qtrs[q];
                if (qtrs[q] < 0)
                    cout << "Please enter 0 or greater.\n";
            } while (qtrs[q] < 0);
        }
        divisions[div].setSales(qtrs[0], qtrs[1], qtrs[2], qtrs[3]);
    }
    cout << setprecision(2);
    cout << fixed << showpoint;
    salesByDiv(divisions);
    cout << "\nTotal Corporate Sales: $" << divisions[0].getCorpSales() << endl;
    return 0;
}

//*****************************************************************
//                       salesByDiv                               *
// The following function displays a list of sales figures        *
// by division.                                                   *
//*****************************************************************
void salesByDiv(DivSales d[])
{
    for (int div = 0; div < NUM_DIV; div++)
    {
        cout << "Sales for Division ";
        cout << (div + 1) << endl;
        for (int qtr = 0; qtr < 4; qtr++)
        {
            cout << "\tQuarter " << (qtr + 1) << ": $";
            cout << d[div].getQSales(qtr) << endl;
        }
    }
    cout << "Press Enter to Continue.";
    cin.get();
}
