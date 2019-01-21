/*
* Circle.cpp
*
* Description: This class models a circle ...
*
* Author:   Curtis Lui
* Creation date:    Jan 13 2019
*/

#include <iostream>
#include <cmath>
#include "Circle.h"

using namespace std;

// Default constructor
Circle::Circle() : xCord(0), yCord(0), radius(10.0)
{

}// Circle()

// Parameterized constructor
Circle::Circle(int x, int y, double rad)
{
    xCord = x;
    yCord = y;

    if (rad > 0.0)
    {
        radius = rad;
    }
    else
    {
        radius = 10.0;
    }
}// Circle(int, int, double)

// Getter returns x-coordinate
int Circle::getX() const
{
    return xCord;
}// getX

// Getter returns y-coordinate
int Circle::getY() const
{
    return yCord;
}// getY

// Getter returns circle's radius
double Circle::getRadius() const
{
    return radius;
}// getRadius

void Circle::move(int horiz, int vert)
{
    xCord = xCord + horiz;
    yCord = yCord + vert;
}// move

void Circle::setRadius(double r)
{
    if (r < 0.0)
    {
        radius = 10.0;
    }
    else
    {
        radius = r;
    }
}// setRadius

double Circle::computeArea() const
{
    double area = M_PI * pow(radius,2);
    return area;
}// computeArea

void Circle::displayCircle() const
{
    cout << "radius " << radius << "  at point x = " << xCord << ", y = " << yCord;
}// displayCircle

// Two circles intersect if, and only if, the distance between their centers is between the sum and the difference of their radii.
// Given two circles (x0, y0, R0) and (x1, y1, R1)


bool Circle::intersect(Circle c) const
{  
    double radiusDiff = abs(radius - c.radius);
    double radiusSum = radius + c.radius;
    double disBetweenCenter = sqrt(pow(xCord - c.xCord, 2) + pow(yCord - c.yCord, 2));

    if (radiusDiff <= disBetweenCenter && radiusSum >= disBetweenCenter)
    {
        return true;
    }
    else
    {
        return false;
    }
}// intersect