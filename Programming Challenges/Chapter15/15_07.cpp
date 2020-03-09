// Chapter 15, Assignment 7, Bumper Shapes
// Simple graphics program displays two rectangular shapes repeatedly 
// bumping into each other.
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
using namespace std;
 
const HANDLE outHandle = GetStdHandle(STD_OUTPUT_HANDLE);

// A shape has a direction and is able to move in that direction.
// The move is a virtual member function.
class Shape
{
public:
    void setDirection(int drow, int dcol){dRow = drow; dCol = dcol;}
    void getDirection(int &drow, int &dcol){drow = dRow; dcol = dCol;}
    virtual void move()= 0;
private:
    int dCol, dRow; // Direction of motion
};

// A SimpleShape can be drawn at a given position in a specified color.
class SimpleShape : public Shape
{
public:
    virtual void draw() = 0;
    void getPosition(int &row, int &col)
    {
        row = rowPos; col = colPos;
    }
    void setPosition(int row, int col)
    {
        rowPos = row; colPos = col;
    }
    void setColor(int c){ color = c; }
    int getColor() {return color; }
    virtual void move();
private:
    int color;
    int rowPos, colPos;
};

// A Box is a rectangular type of shape.
class Box : public SimpleShape
{
public:
    virtual void draw();
    Box(int rowPos, int colPos, int width, int height);
private:
    int width, height;
};

// A Tent is an isosceles triangle whose horizontal base has a
// given length and whose height is half the length of the base.
// The position of the triangle is the left endpoint of the base.
class Tent : public SimpleShape
{
public:
    virtual void draw();
    Tent(int baseRowPos, int baseColPos, int length);
private:
    int length;
};

// A ComplexShape is made up of simpler shapes. It is represented
// as a vector of pointers to the simpler shapes that make it up.
class ComplexShape : public Shape
{
public:
    ComplexShape(Shape ** shapeCollection, int shapesCount);
    virtual void move();
private:
    vector<Shape *> shapes;
};

int main()
{
    Box b(7, 0, 10, 10);
    Box c(7, 70, 10, 10);
    b.setDirection(0, 1);
    c.setDirection(0, -1);
    c.setColor(5);
    int count = 0;
    while (count <= 20)
    {
		// Move the two boxes toward each other, or away from each other
        for (int k = 10; k < 40; k++)
        {
            Sleep(85);
            b.move();
            c.move();           
        }
        // Swap direction of motion of the two boxes
        int dRow, dCol, dRow1, dCol1;
        b.getDirection(dRow, dCol);
        c.getDirection(dRow1, dCol1);
        b.setDirection(dRow1, dCol1);
        c.setDirection(dRow, dCol);
        count ++;
    }
    return 0;
}

//*************************************************************
// Moves a simple shape one step by erasing the shape         *
// at its current position, changing its position, and then   *
// redrawing the shape at its new position.                   *
//*************************************************************
void SimpleShape::move()
{
    int dRow, dCol; // Direction of motion
    int savedColor = color;
    color = 0;      // Drawing in color 0 erases the shape
    draw();
    // Compute the new postion for the shape by adding a step in
    // the proper direction to the current position
    getDirection(dRow, dCol);
    rowPos += dRow;
    colPos += dCol;
    // Draw the shape at its new position in its specified color
    color = savedColor;
    draw();
}

//***********************************
// Draws a tent at its position     *
//***********************************
void Tent:: draw()
{
    int rowPos, colPos;
    COORD pos;
    int currentLength = length;
    // Set the color attribute
    SetConsoleTextAttribute(outHandle, getColor());
    getPosition(rowPos, colPos);
    pos.Y = rowPos; pos.X = colPos;

    // Draw the lines that form the tent beginning with
    // the base and moving up toward the point.
    for (int r = 0; r < length/2; r++)
    {
        SetConsoleCursorPosition(outHandle,pos);
        for (int k = 0; k < currentLength; k++)
        {
            cout << "*";
        }
        cout << endl;
        pos.Y--;
        pos.X ++;
        currentLength -= 2;
    }
    // Restore normal attribute
    SetConsoleTextAttribute(outHandle, 7);
}

//**********************************
// Draws a box shape               *
//**********************************
void Box::draw()
{
    int rowPos, colPos;
    COORD pos;

    // Set the color attribute for the box
    SetConsoleTextAttribute(outHandle, getColor());
    getPosition(rowPos, colPos);
    pos.X = colPos; pos.Y = rowPos;

    // Draw the lines that make up the  box
    for (int r = 0; r < height; r++)
    {
        SetConsoleCursorPosition(outHandle, pos);
        for (int c = 0; c < width; c++)
        {
            cout << "*";
        }
        cout << endl;
        pos.Y++;
    }
    // Restore normal text attribute
    SetConsoleTextAttribute(outHandle, 7);
}

//***********************************************
// Constructor sets the color, position, and    *
// dimensions for a box shape, and draws        *
// the box at its initial position              *
//***********************************************
Box::Box(int rowPos, int colPos, int width, int height)
{
    setColor(4);
    setPosition(rowPos, colPos);
    this->width = width;
    this->height = height;
    draw();
}
//***********************************************
// Constructor sets the color for a Tent shape, *
// sets the position of the tent as well as the *
// length of its base and draws it at its       *
// initial position                             *
//***********************************************
Tent::Tent(int baseRowPos, int baseColPos, int length)
{
    setColor(2);
    setPosition(baseRowPos, baseColPos);
    this->length = length;
    draw();
}

//*********************************************************************
// Constructor builds a complex shape by assembling a vector of       *
// constituent shapes                                                 *
//*********************************************************************
ComplexShape::ComplexShape(Shape ** shapeCollection, int shapesCount)
{
    Shape *p;
    for (int k = 0; k < shapesCount; k++)
    {
        p = shapeCollection[k];
        shapes.push_back(p);
    }
}

//**************************************
// Moves a complex shape by moving the *
// constituent shapes                  *
//**************************************
void ComplexShape::move()
{
    for (int k = 0; k < shapes.size(); k++)
        shapes[k]->move();
}
     
