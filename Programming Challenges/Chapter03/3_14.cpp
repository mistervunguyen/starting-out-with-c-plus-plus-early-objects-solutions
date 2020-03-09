// Chapter 3 - Programming Challege 14, Celsius to Fahrenheit 
//	This program converts a Celsius temperature to Fahrenheit.
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
   double tempCelsius,        // Temperature in Celsius
          tempFahrenheit;     // Temperature in Fahrenheit

   // Request input from user
   cout << "Enter a Celsius temperature: ";
   cin  >> tempCelsius;

   // Perform conversion
   tempFahrenheit = ((9.0/5.0) * tempCelsius) + 32;

   // Display result
   cout << tempCelsius << " degrees Celsius is equal to ";
   cout << fixed << showpoint << setprecision(1);
   cout << tempFahrenheit << " degrees Fahrenheit.\n";
   
   return 0;
}

/* SAMPLE RUN RESULTS

Enter a Celsius temperature: 21
21 degrees Celsius is equal to 69.8 degrees Fahrenheit.
*/