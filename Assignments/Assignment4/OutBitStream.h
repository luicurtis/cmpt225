/*
 * OutBitStream.h
 *
 * Description: Writes to a file one bit at a time to the output stream
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

class OutBitStream
{
  private:
    ofstream outFile;
    int numBytes;
    // Maybe a huff tree object or something

  public:
    OutBitStream();
    OutBitStream(int bytes, string& fileName);
    ~OutBitStream();

    int getNumBytes() const;
    bool isOpen() const;

    void open(string& fileName);
    void close();
    void setNumBytes(int num);
    bool writeBitSequence(string& sequence);
};