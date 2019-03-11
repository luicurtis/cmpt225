/*
 * OutBitStream.cpp
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
#include "OutBitStream.h"

using namespace std;

OutBitStream::OutBitStream() : outFile(), numBytes(0)
{

} // Default Constructor

OutBitStream::OutBitStream(int bytes, string& fileName)
{
    outFile.open(fileName, ios::out | ios::binary);
    if (!outFile.is_open())
    {
        cout << "ERROR: File could not be opened" << endl;
        outFile.close();
    }
    else
    {
        numBytes = bytes;
    }

} // OutBitStream(int, string&)

OutBitStream::~OutBitStream()
{
    outFile.close();
} // Destructor

int OutBitStream::getNumBytes() const
{
    return numBytes;
} // getNumBytes()

bool OutBitStream::isOpen() const
{
    return outFile.is_open();

} // isOpen()

void OutBitStream::open(string& fileName)
{
    outFile.open(fileName, ios::out | ios::binary);
    if (!outFile.is_open())
    {
        cout << "ERROR: File could not be opened" << endl;
        outFile.close();
    }
} // open(string&)

void OutBitStream::close()
{
    outFile.close();

} // close()

void OutBitStream::setNumBytes(int num)
{
    numBytes = num;

} // setNumBytes(int)

bool OutBitStream::writeBitSequence(string& sequence)
{
    // Write number of bytes of the binary sequence
    outFile << numBytes;
    

    // TODO:
    // - need to figure out how to compress the huffman tree

}



