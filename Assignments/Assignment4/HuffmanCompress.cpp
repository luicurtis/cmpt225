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
#include <cstdlib>
#include <cstdio>
#include "BitStream.h"
#include "FrequencyCounter.h"

const string COMPRESS = "-c";
const string DECOMPRESS = "-d";
const string EXTENSION_HUFF = "huff";

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        cout << "ERROR: Not enough command line arguments" << endl;
        cout << "Terminating program." << endl;
        return 1;
    }

    string operation = argv[1];

    // If user wants to compress a file
    if (operation == COMPRESS)
    {
        string nameFiletoCompress = argv[2];
        string nameCompressedfile = argv[3];

        // Need if output file ends in .huff
        // Find the postition where the start of the file extension is
        int i = 0;
        int k = 0;
        int extensionLength = nameCompressedfile.length() - 1 - 4;
        string extension = nameCompressedfile.substr(extensionLength, nameCompressedfile.length() - 1);

        if (extension != EXTENSION_HUFF)
        {
            cout << "ERROR: The output file must have the file extension .huff" << endl;
            cout << "Terminating program." << endl;
            return 2;
        }

        // Create frequency table utilizing extended ASCII representation       ** CONVERT THIS INTO A CLASS **
        FrequencyCounter freqCount;
        bool error = false;
        error = freqCount.countFrequency(nameFiletoCompress);
        if (error)
        {
            return 3;
        }
    }
    else if (strcmp(argv[1], "-d"))
    {
        // need to check if text file ends in .txt and huff file ends in .huff
    }

    return 0;
} // main()