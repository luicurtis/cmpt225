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
#include "PriorityQueue.h"
#include "HuffmanCode.h"
#include "HuffmanTree.h"
#include "BinaryNode.h"

const string COMPRESS = "-c";
const string DECOMPRESS = "-d";
const string EXTENSION_HUFF = "huff";

string generateSequence(string &nameofFile, HuffmanCode code);
int sizeofFile(string &fileName);

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

        // Create frequency table utilizing extended ASCII representation 
        FrequencyCounter freqCount;
        bool error = false;
        error = freqCount.countFrequency(nameFiletoCompress);
        if (error)
        {
            return 3;
        }

        // Create single node trees of characters with corresponding frequency
        // that appear in the file and insert into the Priority Queue
        PriorityQueue<HuffmanTree> treeList;
        int numLeaves = 0;
        for (int i = 0; i < NUM_CHAR_POSSIBILITIES; i++)
        {
            if (freqCount.getFrequency(i) > 0)
            {
                numLeaves++;

                // Create a signle node tree and insert into the PQueue
                HuffmanTree newTree((char)i, freqCount.getFrequency(i));
                treeList.enqueue(newTree);
            }
        }

        // Deqeue two trees from the PQueue and combine them.
        // Reinsert them into the PQueue until PQueue has 1 element.
        while (treeList.getElementCount() > 1)
        {
            HuffmanTree combinedTree;

            HuffmanTree tree1(treeList.peek());
            treeList.dequeue();
            HuffmanTree tree2(treeList.peek());
            treeList.dequeue();

            combinedTree.combine(tree1, tree2);
            treeList.enqueue(combinedTree);
        }

        // Genereate Huffman's code for each leaf
        HuffmanCode huffCode;
        string subCode = "\0";
        huffCode.encode(treeList.peek().getRoot(), subCode);

        // Genereate encoded binary sequence for the file
        string binarySequence = generateSequence(nameFiletoCompress, huffCode);
        
        // Write to a file
        BitStream stream;
        int numBytesFTable = numLeaves*sizeof(int) + numLeaves*sizeof(unsigned char);
        stream.setData(numBytesFTable, binarySequence, freqCount);
        stream.writeData(nameCompressedfile);

        // Calculate size of input file and compressed file
        int inFileSize = sizeofFile(nameFiletoCompress);
        int compFileSize = sizeofFile(nameCompressedfile);

        cout << nameFiletoCompress << " -> " << inFileSize << " bytes" << endl;
        cout << nameCompressedfile << " -> " << compFileSize << " bytes" << endl;

        if (compFileSize > inFileSize)
        {
            cout << "*** Size of compressed file > size of source file ***" << endl;
        }
    }
    else if (operation == DECOMPRESS)
    {
        string nameCompressedfile = argv[2];
        string nameFiletoDecompress = argv[3];

        // need to check if compressed file ends in .huff
        // Find the postition where the start of the file extension is
        int i = 0;
        int k = 0;
        int extensionLength = nameCompressedfile.length() - 1 - 4;
        string extension = nameCompressedfile.substr(extensionLength, nameCompressedfile.length() - 1);

        if (extension != EXTENSION_HUFF)
        {
            cout << "ERROR: The output file must have the file extension .huff" << endl;
            cout << "Terminating program." << endl;
            return 4;
        }

        BitStream stream;
        stream.readData(nameCompressedfile);

        // Get the frequency table
        FrequencyCounter freqCount(stream.getFC());

        // Rebuild the huffman's tree with Frequency Counter
        // Create single node trees of characters with corresponding frequency
        // that appear in the file and insert into the Priority Queue
        PriorityQueue<HuffmanTree> treeList;
        int numLeaves = 0;
        for (int i = 0; i < NUM_CHAR_POSSIBILITIES; i++)
        {
            if (freqCount.getFrequency(i) > 0)
            {
                numLeaves++;

                // Create a signle node tree and insert into the PQueue
                HuffmanTree newTree((char)i, freqCount.getFrequency(i));
                treeList.enqueue(newTree);
            }
        }

        // Deqeue two trees from the PQueue and combine them.
        // Reinsert them into the PQueue until PQueue has 1 element.
        while (treeList.getElementCount() > 1)
        {
            HuffmanTree combinedTree;

            HuffmanTree tree1(treeList.peek());
            treeList.dequeue();
            HuffmanTree tree2(treeList.peek());
            treeList.dequeue();

            combinedTree.combine(tree1, tree2);
            treeList.enqueue(combinedTree);
        }

        HuffmanTree huffTree(treeList.peek());
        BinaryNode* treePtr;
        treePtr = huffTree.getRoot();

        // Decode the huffman code
        string huffCode = stream.getSequence();
        string message;
        
        for (int i = 0; i < huffCode.length(); i++)
        {
            if (treePtr->isLeaf())
            {
                message += treePtr->getChar();
            }
            if (huffCode[i] == '0')
            {
                treePtr = treePtr->getLeft();
            }
            else
            {
                treePtr = treePtr->getRight();
            }
        }

        // Write message to file
        ofstream fs;
        fs.open(nameFiletoDecompress, ios::out);
        fs << message;

    }
    else
    {
        cout << "ERROR: Not a valid input" << endl;
        cout << "Terminating program." << endl;
        return 5;
    }

    return 0;
} // main()

string generateSequence(string &nameofFile, HuffmanCode code)
{
    string biSequence = "\0";
    ifstream inFile(nameofFile, ios::in);

    if (!(inFile.is_open()))
    {
        cout << "ERROR: Cannot open the file to read from." << endl;
    }

    inFile.seekg(0, ios::beg);

    while (!inFile.eof())
    {
        char c;
        inFile.get(c);
        if (c == EOF)
        {
            break;
        }

        biSequence += code.getCode(c);
    }

    inFile.close();
    
    return biSequence;
}

int sizeofFile(string &fileName)
{
    ifstream file;
    int beg = 0;
    int end = 0;

    file.open(fileName, ios::binary);

    beg = (int) file.tellg();
    file.seekg(0, ios::end);
    end = (int) file.tellg();
    file.close();

    return (end - beg);
}