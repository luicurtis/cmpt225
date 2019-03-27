/*
* Rectangle.h
*
* Description: This class models a rectangle ...
*
* Author:
* Creation date:
*/

class Rectangle {

private: 

   // Everything that follows is private and cannot be "seen" and 
   // directly accessed from outside the class.
   // To access these private data members, client code needs to use the getters and setters.
  
   int width;
   int height;
   
   // Some classes have private methods like our Temperature class. This one doesn't!

public: 

   // Everything that follows is public and can be "seen" and directly accessed 
   // from outside the class(from client code).
   
   // Default constructor
   // Note that the default constructor has no parameters.
   Rectangle(); 
   
   // Parameterized constructor
   // Description: Create a new rectangle with the given values.
   Rectangle(int w, int h);
      
   // Getters return information about the rectangle. 
   // Note the const at the end of the method.
   // This guarantees that the method cannot alter the member variables.
   int getWidth() const;
   int getHeight() const;

   // Setters change the values of the class' attributes.
   void setWidth(int w);
   void setHeight(int h);
   
   // Description: Compute and return the area of "this" rectangle.
   int computeArea() const;   
   
   // Description: Prints the rectangle's height and width.
   void displayRectangle() const;

}; // Note the ";" - don't forget it!
// End of Rectangle.h