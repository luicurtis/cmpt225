/*
 * HuffmanCode.h
 *
 * Class Definition: Creates a collection of the huffman codes for each leaf
 *                   in the huffman tree
 *
 * Created on: 	March 2019
 * Author: 		Curtis Lui
 * 
 */

#pragma once

#include <iostream>
#include <cstdlib> // NULL
#include <string>
#include "BinaryNode.h"
#include "FrequencyCounter.h"

class HuffmanCode
{
  private:
    string code[NUM_CHAR_POSSIBILITIES];

  public:
    // Desc: Default constructor
    // Post: Initialized code elements
    HuffmanCode();

    // Desc: Returns the huffman code for the given character
    string getCode(char c);

    // Desc: Creates the Huffman code for all elements of the tree
    // Post: Code elements are set to the binary string that represents the 
    //       huffman code for that specific character
    void encode(BinaryNode *root, string subCode);

};  // End of HuffmanCode