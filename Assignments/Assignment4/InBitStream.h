/*
 * InBitStream.h
 *
 * Description: Reads a file one bit at a time from the input stream
 * Class Invariant: 
 *
 * Author: Curtis Lui
 * Modified: March 2019
 *
 */

#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class InBitStream
{
  private:
    ifstream inFile;
    int numBits;
    string bitSequence;
    // Maybe a huff tree object or something

  public:
    InBitStream();
    InBitStream(string& fileName);
    ~InBitStream(); // Close the file
    
    int getNumBits();
    string getbitSequence();
    bool isOpen();
    
    void open(string& fileName);
    void close();
    void setNumBits();
    void setbitSequence();
};