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

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include "BitStream.h"

using namespace std;

const int SIZEOFBYTE = 8;

// TODO
// - Need to add huffman tree into all functions

BitStream::BitStream() : sizeHuffman("\0"), biSequence("\0")
{

} // Constructor

string BitStream::getSequence() const
{
    return biSequence;

} // getSequence

void BitStream::setData(int numBytes, string sequence)
{
    sprintf(sizeHuffman, "%d", numBytes);
    biSequence = sequence;

} // setData(int, string)

void BitStream::save(ofstream& of)
{
    // Write number of bytes for the huffman tree
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
    }
} // save(ofstream)

void BitStream::writeData(string fileName)
{
    ofstream fs;
    fs.open(fileName, ios::out | ios::binary);
    if (!(fs.is_open()))
    {
        cout << "ERROR: Cannot open the file to write to." << endl;
    }
    else
    {
        this->save(fs);
    }

    fs.close();

}// writeData(string)

void BitStream::readData(string fileName)
{
    ifstream binaryFile;
    int sizeFile = 0;

    binaryFile.open(fileName, ios::in | ios::binary);

    binaryFile.seekg(0, ios::end); // Read file from beginning to end
    sizeFile = (int) binaryFile.tellg(); // get the size of the binary file because it is at the last char in the input
    binaryFile.seekg(0, ios::beg); // Set the the pointer to the beg of file

    // Ready get the size of the huffman tree
    binaryFile.read((char*) sizeHuffman, sizeof(sizeHuffman));

    int sizeHuffInt = stoi(sizeHuffman);

    // read the huffman tree
    // while(binaryFile.tellg() < sizeHuffInt)
    // {
    //     binaryFile.read()
    // }
    
    // Read the binary sequence
    bool bitValue = false;
    char c;
    while(binaryFile.tellg() < sizeFile)
    {
        binaryFile.get(c);

        // Use bitwise operators to shift bits and extract them
        // from the char c
        for (int i = 7; i >= 0; i--)
        {
            bitValue = (c >> i) & 1;
            if (bitValue == 1)
            {
                biSequence += '1';
            }
            else
            {
                biSequence += '0';
            }
        }
    }

} // readData(string)



