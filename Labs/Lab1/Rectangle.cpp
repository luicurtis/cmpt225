/*
* Rectangle.cpp
*
* Description: This class models a rectangle ...
*
* Author:
* Creation date:
*/

#include <iostream> // As we need to print data
#include "Rectangle.h"    // The header file for the class - we need this!

using namespace std;

// Now, read each of the method implementations. 
// The <class>:: thatcmethod indicates that the method belongs to the class. 
// If it is omitted, the compiler will attempt to create a separate function 
// (not belonging to the class). This is not what we want.

// Default constructor
// Note: This part of the construction's header " : width(1), height(1)"
// is called the "initialiation list". 
// Check what our textbook and online resources have to say about it!
Rectangle::Rectangle() : width(1), height(1) {

}//Rectangle()

// Parameterized constructor
// Description: Create a new rectangle with the given values.
Rectangle::Rectangle(int w, int h)
{
   if (w > 0)
      width = w; // Don't need {}s if there is only one line in the body.
   else
      width = 1;

   if (h > 0){
      height = h; // But you can use them if you want.
   }else{
      height = 1;
   }
   
}//Rectangle(int, int)

// Getters return information about the rectangle. 
// Note the const at the end of the method.
// This guarantees that the method cannot alter the member variables.
int Rectangle::getWidth() const
{
   return width;
   
}//getWidth

int Rectangle::getHeight() const
{
   return height;
   
}//getHeight

// Setters change the values of the class' attributes.
void Rectangle::setWidth(int w)
{
   if (w > 0)
      width = w;
   else
      width = 1;
	  
}//setWidth

void Rectangle::setHeight(int h)
{
   if (h > 0)
      height = h;
   else
      height = 1;
}//setHeight 
   
// Description: Compute and return the area of "this" rectangle.
int Rectangle::computeArea() const   
{
   return width * height;
   
}//computeArea

// Description: Prints the rectangle's height and width.
void Rectangle::displayRectangle() const
{
   cout << endl << "width = " << getWidth();
   cout << ", height = " << getHeight() << endl;
   
}//displayRectangle

// End of the implementation file