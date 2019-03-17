/*
 * FrequencyCounter.h
 *
 * Description: Counts the frequncy of characters that appear in a file
 * Class Invariant: 
 *
 * Author: Curtis Lui
 * Modified: March 2019
 *
 */

#pragma once

#include <string>

using namespace std;

const int NUM_CHAR_POSSIBILITIES = 256;

class FrequencyCounter
{
  private:
    int count[NUM_CHAR_POSSIBILITIES];

  public:
    FrequencyCounter();

    int* getTable();
    bool countFrequency(string &nameofFile);
};