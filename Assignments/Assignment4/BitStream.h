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

using namespace std;

class BitStream
{
  private:
    char* sizeHuffman;    // # of bytes written in this file representing the Huffman Tree
    string biSequence;
    // Maybe a huff tree object or something


  public:
    BitStream();
    // ~BitStream(); // Is destructor necessary??

    string getSequence() const;
    // TODO
    // - getter for huffman tree
    // - Need to add huffman tree object to setData
    
    void setData(int numBytes, string sequence); 
    void save(ofstream& of);
    void writeData(string fileName);
    void readData(string fileName);
};