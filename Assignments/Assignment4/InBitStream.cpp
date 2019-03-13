/*
 * InBitStream.cpp
 *
 * Description: Reads a file one bit at a time from the input stream
 * Class Invariant: 
 *
 * Author: Curtis Lui
 * Modified: March 2019
 *
 */


#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>
#include "InBitStream.h"

using namespace std;

InBitStream::InBitStream() : inFile(), numBytes(0), bitSequence("\0")
{

} // Default Constructor

InBitStream::InBitStream(string& fileName)
{
    inFile.open(fileName, ios::in | ios::binary);
    if (!inFile.is_open())
    {
        cout << "ERROR: File could not be opened" << endl;
        inFile.close();
    }
    else
    {
        char c;
        bool bitValue = false;
        int bitCounter = 0;
        
        this->setNumBytes();

        while(inFile.get(c) && bitCounter < numBytes)
        {
            // Use bitwise operators to shift bits and extract them
            // from the char c
            for (int i = 7; i >= 0; i--)
            {
                bitValue = (c >> i) & 1;
                if (bitValue == 1)
                {
                    bitSequence += '1';
                }
                else
                {
                    bitSequence += '0';
                }
            }
            
            bitCounter++;
        }

        // TODO:
        // - need to import the huff tree from the file
    }
} // Constuctor

InBitStream::~InBitStream()
{
    inFile.close();

} // Destructor

int InBitStream::getNumBytes() const
{
    return numBytes;
} // getNumBits()

string InBitStream::getbitSequence() const
{
    return bitSequence;

} // getbitSequence()

bool InBitStream::isOpen() const
{
    return inFile.is_open();

} // isOpen()

void InBitStream::open(string& fileName)
{
    inFile.open(fileName, ios::in | ios::binary);
    if (!inFile.is_open())
    {
        cout << "ERROR: File could not be open" << endl;
        inFile.close();
    }
} // open()

void InBitStream::close()
{
    inFile.close();
} // close()

void InBitStream::setNumBytes()
{
    char c = '\0';
    inFile.seekg(0);    // 0th char byte in the file is the number of digits for the number of bytes 
    inFile.get(c);
    numDigitsforBytes = c - '0';  // convert char to int

    inFile.seekg(1);    // 1st char byte in the file
    int temp = 0;
    for (int i = 0; i < numDigitsforBytes; i++)
    {
        inFile.get(c);  // Get next char byte
        temp = c - '0';
        temp *= pow(10, (numDigitsforBytes - i - 1));
        numBytes += temp;
    }

} // setNumBits()

// Pre: File must be opened
void InBitStream::setbitSequence()
{
    char c;
    bool bitValue = false;
    int bitCounter = 0;

    // Set the position of the next character to be extracted 
    // from the input stream to the second character
    inFile.seekg(1);    
    while(inFile.get(c) && bitCounter < numBytes)
    {
        // Use bitwise operators to shift bits and extract them
        // from the char c
        for (int i = 7; i >= 0; i--)
        {
            bitValue = (c >> i) & 1;
            if (bitValue == 1)
            {
                bitSequence += '1';
            }
            else
            {
                bitSequence += '0';
            }
        }
        
        bitCounter++;
    }
} // setbitSequence()