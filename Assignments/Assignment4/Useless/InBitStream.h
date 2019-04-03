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
    int numDigitsforBytes;
    int numBytes;
    string bitSequence;
    // Maybe a huff tree object or something

  public:
    InBitStream();
    InBitStream(string& fileName);
    ~InBitStream(); // Close the file
    
    int getNumBytes() const;
    string getbitSequence() const;
    bool isOpen() const;
    
    void open(string& fileName);
    void close();
    void setNumBytes();
    void setbitSequence();
};