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

// Desc: Default constructor
// Post: count elemnts will be initialized
FrequencyCounter::FrequencyCounter()
{
    for (int i = 0; i < NUM_CHAR_POSSIBILITIES; i++)
    {
        count[i] = 0;
    }

} // Default constructor

// Desc: Copy constructor
// Post: this->count will be identical to toCopy
FrequencyCounter::FrequencyCounter(FrequencyCounter &toCopy)
{
    for (int i = 0; i < NUM_CHAR_POSSIBILITIES; i++)
    {
        count[i] = toCopy.getFrequency(i);
    }
} // Copy constructor

// Desc: Returns the frequency of a given character, 
//       represented as an index
int FrequencyCounter::getFrequency(int index) const
{
    return count[index];

} // getTable()

// Desc: Counts the frequency of the given file
// Post: Elements in count will contain number of times a 
//       character appears in the file
// Return: Returns true if file was failed to opened, else false
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

// Desc: Sets the frequency of a given charcter
// Post: Element in count that corresponds to the given character
//       has it's frequency set
void FrequencyCounter::insertFromfile(char c, int frequency)
{
    count[(unsigned char)c] = frequency; 

} // insertFromfile(char, int)
