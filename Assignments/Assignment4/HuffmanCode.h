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

const int NUM_CHAR_POSSIBILITIES = 256;

class HuffmanCode
{
  private:
    string code[NUM_CHAR_POSSIBILITIES];

  public:
    HuffmanCode();

    string *getCode();
    void encode(BinaryNode *root, string subCode);
};