/*
 * FrequencyCounter.cpp
 *
 * Description: Counts the frequncy of characters that appear in a file
 * Class Invariant: 
 *
 * Author: Curtis Lui
 * Modified: March 2019
 *
 */

#include <iostream>
#include <fstream>
#include "FrequencyCounter.h"

using namespace std;

FrequencyCounter::FrequencyCounter()
{
    for (int i = 0; i < NUM_CHAR_POSSIBILITIES; i++)
    {
        count[i] = 0;
    }

} // Default constructor

FrequencyCounter::FrequencyCounter(FrequencyCounter &toCopy)
{
    for (int i = 0; i < NUM_CHAR_POSSIBILITIES; i++)
    {
        count[i] = toCopy.getFrequency(i);
    }
} // Copy constructor

int FrequencyCounter::getFrequency(int index) const
{
    return count[index];

} // getTable()

bool FrequencyCounter::countFrequency(string &nameofFile)
{
    ifstream inFile(nameofFile, ios::in);

    if (!(inFile.is_open()))
    {
        cout << "ERROR: Cannot open the file to read from." << endl;
        return true;
    }
        
    while (!inFile.eof())
    {
        char c;
        inFile.get(c);
        if (c == EOF)
        {
            break;
        }
        // Use extended ASCII representation to keep track of the frequency of the character
        // unsigned char cast becuase we want numbers from 0 to 255
        count[(unsigned char)c]++;  // Increment counter of that character represented in ASCII
    }

    inFile.close();

    return false;
    
} // countFrequency(string&)

void FrequencyCounter::insertFromfile(char c, int frequency)
{
    count[(unsigned char)c] = frequency; 

} // insertFromfile(char, int)
