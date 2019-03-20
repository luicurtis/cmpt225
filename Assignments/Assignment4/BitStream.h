/*
 * BitStream.h
 *
 * Description: Read and writes a binary file
 * Class Invariant: 
 *
 * Author: Curtis Lui
 * Modified: March 2019
 *
 */

#pragma once

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "FrequencyCounter.h"

using namespace std;

class BitStream
{
  private:
    int sizeHuffman;      // # of bytes written in this file representing the Huffman Tree
    string biSequence;    // Binary Sequence to traverse tree from binary file
    FrequencyCounter FC;  // Frequency table from binary file, represents the Huffman tree

  public:
    // Desc: Default constructor
    BitStream();

    // Desc: Returns the Binary sequence stored that is ready to be
    //       written or has been read
    string getSequence() const;

    // Desc: Returns the frequency table
    FrequencyCounter& getFC();
    
    // Desc: Sets the data in the BitStream Object
    // Post: sizeHuffman = numBytes
    //       biSequence = sequence
    //       this->FC = FC
    void setData(int numBytes, string sequence, FrequencyCounter FC); 

    // Desc: Saves the data into the output file given the input stream
    // Pre:  Output stream must be open before calling save
    void save(ofstream& of);
    
    // Desc: Opens the file stream and writes to fileName
    //       Closes the stream after it is done writing.
    void writeData(string fileName);

    // Desc: Extracts data from a file
    // Post: sizeHuffman, biSequence, and FC have their fields filled with data
    void readData(string fileName);
    
}; // End of BitStream