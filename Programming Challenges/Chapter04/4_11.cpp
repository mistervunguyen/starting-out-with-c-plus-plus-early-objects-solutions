// Chapter 4 - Programming Challenge 11, Geometry Calculator
// This menu-driven program computes the area of various geometric figures.
#include <iostream>
using namespace std;

int main()
{
    const double PI = 3.14159;

    int    choice;         // User's shape choice
    double radius,         // Circle radius
           length,         // Rectangle length
           width,          // Rectangle width
           base,           // Triangle base
           height,         // Triangle height
           area;           // Area of the selected shape

	// Display selections and request user input
	cout << "Geometry Calculator\n\n";
	cout << "1. Calculate the area of a Circle\n";
	cout << "2. Calculate the area of a Rectangle\n";
	cout << "3. Calculate the area of a Triangle\n";
	cout << "4. Quit\n";
	cout << "Enter your choice (1-4): ";
	cin >> choice;

	// Calculate and display the area of the selected shape
	switch (choice)
	{
		case 1:  // Area of a circle
			     cout << "\nEnter the circle's radius: ";
				 cin  >> radius;

				 if (radius < 0)
					 cout << "The radius can not be less than zero.\n";
				 else
				 {	 area = PI * radius * radius;
				     cout << "The area is " << area << endl;
				 }
				 break;

		case 2:  // Area of a rectangle
			     cout << "\nEnter the rectangle's length: ";
				 cin  >> length;
				 cout << "Enter the rectangle's width: ";
				 cin  >> width;

				 if (length < 0 || width < 0)
					 cout << "Length and width should both be greater than zero.\n";
				 else
				 {	 area = length * width;
					 cout << "The area is " << area << endl;
				 }
				 break;

		case 3:  // Area of a triangle
			     cout << "\nEnter the length of the triangle's base: ";
				 cin  >> base;
				 cout << "Enter the triangle's height: "; 
				 cin  >> height;

				 if (base < 0 || height < 0)
					 cout << "Base and height should both be greater than zero.\n";
				 else
				 {	 area = base * height * 0.5;
					 cout << "The area is " << area << endl;
				 }
				 break;

		case 4:	 cout << "\nBye!\n";
			     break;

		default:  cout << "\nYou may only enter 1, 2, 3, or 4.\n";
	}
	return 0;
}

/* SAMPLE RESULT - RUN 1
Geometry Calculator

1. Calculate the area of a Circle
2. Calculate the area of a Rectangle
3. Calculate the area of a Triangle
4. Quit
Enter your choice (1-4): 1

Enter the circle's radius: 3
The area is 28.2743

SAMPLE RESULT - RUN 2
Geometry Calculator

1. Calculate the area of a Circle
2. Calculate the area of a Rectangle
3. Calculate the area of a Triangle
4. Quit
Enter your choice (1-4): 3

Enter the length of the triangle's base: 7
Enter the triangle's height: 8
The area is 28
*/