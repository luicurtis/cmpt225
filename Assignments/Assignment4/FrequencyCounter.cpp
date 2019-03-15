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

FrequencyCounter::FrequencyCounter() : frequency(0)
{

} // Default constructor

int FrequencyCounter::getFrequency() const
{
    return frequency;
} // getFrequency()

void FrequencyCounter::incrementFrequency()
{
    frequency++;
} // incrementFrequency()

// TODO
// - add comparison operator