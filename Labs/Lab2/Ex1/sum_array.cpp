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

using namespace std;

int sumArray(int arr[], int arrSize);

int main()
{
    int arrSize = 0;
    string strValue = "\0";
    int value = 0;
    int sum = 0;
    int *arr = NULL;
    
    cout << "Enter the total number of values to be summed:" << endl;
    cin >> arrSize;

    arr = new int[arrSize]; 

    if (arr == NULL)
    {
        cout << "ERROR: NULL not returned when initialzing the Array pointer" << endl;
        return 1;
    }

    cin.clear();
    cin.ignore(100, '\n');

    cout << "Please enter integer values one at a time" << endl;
    
    for (int i = 0; i < arrSize; i++)
    {
        cout << "Enter an integer:";
        getline(cin, strValue);

        if (strValue.empty())
        {
            break;
        }
        else
        {
            value = stoi(strValue);
            arr[i] = value;
            cout << endl;

        }

    }

    sum = sumArray(arr, arrSize);

    delete[] arr;

    return sum;
}
int sumArray(int arr[], int arrSize)
{
    int sum = 0;

    for (int i = 0; i < arrSize; i++)
    {
        sum += arr[i];
    }

    return sum;
}