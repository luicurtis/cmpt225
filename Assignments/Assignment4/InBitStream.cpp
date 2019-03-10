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
#include "InBitStream.h"

using namespace std;

InBitStream::InBitStream() : inFile(), numBits(0), bitSequence("\0")
{

} // Default Constructor

InBitStream::InBitStream(string& fileName)
{
    inFile.open(fileName, ios::in | ios::binary);
    if (!inFile.is_open())
    {
        cout << "ERROR: File could not be open" << endl;
        inFile.close();
    }
    else
    {
        char c;
        bool bitValue;

        while(inFile.get(c))
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
        }
    }
} // Constuctor

InBitStream::~InBitStream()
{
    inFile.close();

} // Destructor

int InBitStream::getNumBits()
{
    return numBits;
} // getNumBits()

string InBitStream::getbitSequence()
{
    return bitSequence;
} // getbitSequence()

bool InBitStream::isOpen()
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

void InBitStream::setNumBits()
{
    char c = '\0';
    inFile.seekg(0);    // First char in the file is the number of bits 
    inFile.get(c);
    numBits = c - '0';  // convert char to int


} // setNumBits()

// Pre: File must be opened
void InBitStream::setbitSequence()
{
    char c;
    bool bitValue;

    // Set the position of the next character to be extracted 
    // from the input stream to the second character
    inFile.seekg(1);    
    while(inFile.get(c))
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
    }
} // setbitSequence()