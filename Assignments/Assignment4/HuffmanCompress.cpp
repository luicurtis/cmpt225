/*
 * HuffmanCompress.cpp
 *
 * Description: Application File to compress or decompress an input file
 * 
 * Author: Curtis Lui
 * Modified: March 2019
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include "BitStream.h"
#include "FrequencyCounter.h"

const int NUM_POSSIBILITIES = 256;

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        cout << "ERROR: Not enough command line arguments" << endl;
        cout << "Terminating program." << endl;
        return 1;
    }
    

    if (strcmp(argv[1], "-c")) 
    {
        int i = 0;
        while(argv[2][i] != '.' && i < strlen(argv[2]))
        {
            i++;
        }
        char * extension;

        // need to check if text file ends in .txt and huff file ends in .huff

        FrequencyCounter fC[NUM_POSSIBILITIES];
        ifstream inFile(argv[2]);
        
        while (!inFile.eof())
        {
            char c;
            inFile.get(c);
            if (c == EOF)
            {
                break;
            }
            // Use ASCII representation to keep track of the frequency of the character
            fC[(unsigned char)c].incrementFrequency();  
        }

    }
    else if (strcmp(argv[1], "-d")) 
    {
        // need to check if text file ends in .txt and huff file ends in .huff
    }

    return 0;
} // main()