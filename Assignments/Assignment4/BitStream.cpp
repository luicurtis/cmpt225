/*
 * BitStream.cpp
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
#include <string>
#include <cstdlib>
#include <cmath>
#include "BitStream.h"

using namespace std;

const int SIZEOFBYTE = 8;

// TODO
// - Need to add huffman tree into all functions

BitStream::BitStream() : sizeHuffman(0), biSequence("\0")
{

} // Constructor

string BitStream::getSequence() const
{
    return biSequence;

} // getSequence

void BitStream::setData(int numBytes, string sequence)
{
    sizeHuffman = numBytes;
    biSequence = sequence;

} // setData(int, string)

void BitStream::save(ofstream of)
{
    of.write((char*) &sizeHuffman, sizeof(sizeHuffman));
    // write the huffman tree into  binary file

    // Write the binary sequence into binary file
    int i = 0;
    while (i < biSequence.length())
    {
        int j = 0;
        bool bits[SIZEOFBYTE];
        while (j < SIZEOFBYTE)
        {
            if (biSequence[i] == '1' && i < biSequence.length())
            {
                bits[j] = 1;
            }
            else
            {
                bits[j] = 0;
            }
            j++;
            i++;
        }
        unsigned char byte = 0;
        for (int k = 0; i < 8; i++)
        {
            if (bits[k])
            {
                byte |= 1 << i;
            }
        }
        of.write((char*) &byte, sizeof(byte));
        // DOUBLE CHECK LOGIC
    }


}