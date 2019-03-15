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

#pragma once

#include <iostream>
#include "FrequencyCounter.h"

using namespace std;

FrequencyCounter::FrequencyCounter()
{
    for (int i = 0; i < NUM_CHAR_POSSIBILITIES; i++)
    {
        count[i] = 0;
    }
    
} // Default constructor

int* FrequencyCounter::getTable()
{
    return count;
} // getTable()

void FrequencyCounter::countFrequency(string &nameofFile)
{
    // TODO 
} // incrementFrequency()
