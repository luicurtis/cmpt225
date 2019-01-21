/*
* sum_array.cpp
*
* Description: Program will calculate the sum of array values
*
* Author:   Curtis Lui
* Creation date:    Jan 21 2019
*
*/

#include <iostream>
#include <string>
#include "Circle.h"

using namespace std;

int main()
{
    int arrSize = 0;
    int elementCount = 0;
    int xCoord = 0;
    int yCoord = 0;
    double radius = 0;
    int choice = 0;
    bool end = false;
    string strValue = "\0";
    Circle *arr = NULL;
    
    
    cout << "Enter the total number of values to be summed:" << endl;
    cin >> arrSize;

    arr = new Circle();

    if (arr == NULL)
    {
        cout << "ERROR: NULL not returned when initialzing the Array pointer" << endl;
        return 1;
    }

    do
    {
        cout << "Press 1 to enter a circle object or press 2 to exit: " << endl;
        cin >> choice;

        if (choice == 1 && elementCount != arrSize)
        {
            cout << "Enter the x coordinate of the " << elementCount << "st circle" << endl;
            cin >> xCoord;

            cout << "Enter the y coordinate of the " << elementCount << "st circle" << endl;
            cin >> yCoord;

            cout << "Enter the radius of the " << elementCount << "st circle" << endl;
            cin >> radius;

            arr[elementCount] = Circle(xCoord, yCoord, radius);
            elementCount++;
        }
        else if (choice == 2 && elementCount != arrSize)
        {
            cout << "Exiting and printing out circle information" << endl << endl;
            end = true;
        }
        else if (elementCount == arrSize)
        {
            cout << "Array full. Printing out circle information" << endl << endl;
            end = true;
        }
        else
        {
            cin.clear();
            cin.ignore(100, '\n');
            choice = 0;
            cout << "ERROR: Invalid choice. Please try again." << endl << endl;
        }

    } // do-while
    while (end == false);

    cout << "The size of the Array is: " << arrSize << endl;
    cout << "The number of Circle objects entered into the array is: " << elementCount << endl;
    cout << "The number of empty cell(s) in the array is: " << arrSize - elementCount << endl << endl;
    cout << "Printing content of each Circle object in the Array:" << endl;
    // Print content of each Circle object in the Array
    for (int i = 0; i < arrSize; i++)
    {
        cout << endl << "   Array index " << i << ":" << endl;
        if (i < elementCount)
        {
            cout << "   ";
            arr[i].displayCircle();
            cout << endl;
            cout << "   Area of the Circle: " << arr[i].computeArea() << endl;
        }
        else
        {
            cout << "This cell is empty" << endl;
        }
    }
    delete arr;

    return 0;
}