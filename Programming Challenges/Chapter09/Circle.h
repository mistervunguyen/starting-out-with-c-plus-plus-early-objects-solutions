// This header file contains the Circle class declaration.
#ifndef CIRCLE_H
#define CIRCLE_H
#include <cmath>

class Circle
{	private:
		double radius;                  // Circle radius
		int centerX, centerY;           // Center coordinates  
		
	public:
		Circle()                        // Default constructor 
		{  radius = 1.0;                // accepts no arguments
		   centerX = centerY = 0;
		}
		
		Circle(double r)                // 1-arg Constructor
		{  radius = r;                  
		   centerX = centerY = 0;
		}

		Circle(double r, int x, int y)   // 3-arg Constructor 
		{  radius = r;                   
		   centerX = x;
		   centerY = y;
	    }
		
		void setRadius(double r)
		{  radius = r;
		}
		
		int getXcoord()
		{  return centerX;
		}
		
		int getYcoord()
		{  return centerY;
		}

		double getRadius()                // Added to the Chapter 8         
		{   return radius;                // Circle.h file for use with      
		}                                 // Programming Challenge 9_11
		
		double findArea()
		{  return 3.14 * pow(radius, 2);
		}
}; // End Circle class declaration
#endif
