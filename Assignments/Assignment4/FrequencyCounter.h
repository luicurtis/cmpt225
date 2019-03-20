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
    // Desc: Default constructor
    // Post: count elemnts will be initialized
    FrequencyCounter();

    // Desc: Copy constructor
    // Post: this->count will be identical to toCopy
    FrequencyCounter(FrequencyCounter &toCopy);

    // Desc: Returns the frequency of a given character, 
    //       represented as an index
    int getFrequency(int index) const;

    // Desc: Counts the frequency of the given file
    // Post: Elements in count will contain number of times a 
    //       character appears in the file
    // Return: Returns true if file was failed to opened, else false
    bool countFrequency(string &nameofFile);

    // Desc: Sets the frequency of a given charcter
    // Post: Element in count that corresponds to the given character
    //       has it's frequency set
    void insertFromfile(char c, int frequency);
};