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
    BitStream();
    // ~BitStream(); // Is destructor necessary??

    string getSequence() const;
    
    void setData(int numBytes, string sequence, FrequencyCounter FC); 
    void save(ofstream& of);
    void writeData(string fileName);
    void readData(string fileName);

}; // End of BitStream