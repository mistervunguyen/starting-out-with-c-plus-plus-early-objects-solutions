#include "ImageMap.h"
 
//**************************************************
// Adds an array of coordinates to the image map   *
//**************************************************
void ImageMap::add(COORD coordArray[])
 {
    for(int k = 0; coordArray[k].X != -1; k++)
    {
       push_back(coordArray[k]);
    }
}

//***************************************************
// Allows an array of shorts to be converted to     *
// an array of of COORD. That simplifies the        *
// initialization process for an image              *
//***************************************************
 void ImageMap::add(short *coordAsShorts)
 {
    COORD *pCoord = reinterpret_cast<COORD *>(coordAsShorts);
    add(pCoord);
 }

 //******************************************************
 // Shows an image at a given position. The image is    *
 // is drawn using the character ch                     *
 //******************************************************
 void ImageMap::displayAt(char ch, int col, int row)
 {
    list<COORD>::iterator iter = this->begin();
    for (; iter != this->end(); iter++)
    {
        COORD currentPos;
        currentPos.Y = row + iter->Y;
        currentPos.X = col + iter->X;
        SetConsoleCursorPosition(console, currentPos);
        cout << ch << endl;
    }
 }

 //********************************************************
 //   Flips the person image around to face the other way *
 //********************************************************
 void ImageMap::aboutFace()
 {
	 list<COORD>::iterator iter = this->begin();
	 for (; iter != this->end(); iter ++)
	 {
        iter->X = 11 - iter->X;		
	 }
 }

//**************************************************
//          Useful debugging tool                  *   
//**************************************************

 void ImageMap::dump()
 {
	for (ImageMap::iterator iter = this->begin(); iter != this->end(); iter ++)
	{
      cout << "(" << iter->X << "," << iter->Y << ")" << "  ";
	}
 }

 