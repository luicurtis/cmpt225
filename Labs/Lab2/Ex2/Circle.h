/*
* Circle.h
*
* Description: This class models a circle ...
*
* Author:   Curtis Lui
* Creation date: Jan 13 2019
*/

class Circle
{
    private:
        int xCord;
        int yCord;
        double radius;
    
    public:
        // A default constructor that creates a circle of radius 10 at position 0,0
        Circle();

        // A constructor with parameters for x, y, and radius
        Circle(int x, int y, double rad);

        // returns the circle's x coordinate
        int getX() const;

        // returns the circle's y coordinate
        int getY() const;

        // returns the circle's radius
        double getRadius() const;

        // moves the circle the given horizontal and vertical distances (therefore changing its x and y attributes)
        void move(int horiz, int vert);

        // changes the circle's radius to r, or to 10.0 if r is invalid
        void setRadius(double r);

        // computes and returns the circle's area
        double computeArea() const;

        //displays the circle's attributes like this: "radius 10.0 at point x = 12, y = 17"
        void displayCircle() const;

        // returns true if c intersects the calling circle 
        bool intersect(Circle c) const;
};
// End of Circle.h