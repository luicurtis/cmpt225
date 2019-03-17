/*
 * HuffmanTree.h
 *
 * Class Definition: Huffman tree class where all the data is stored at the leaves 
 *                   of the tree. The tree is traversed through a binary string.
 *                   0 represents traversing the left subtree, and 1 representing 
 *                   the right.
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

using namespace std;

class HuffmanTree
{
  private:
    int weight;
    BinaryNode *root;

  public:
    HuffmanTree();
    // Initializes one node
    HuffmanTree(char character, int frequency);
    ~HuffmanTree();
    void RecursiveDelete(BinaryNode *root);

    int getWeight() const;
    BinaryNode *getRoot() const;
    
    void combine(const HuffmanTree &huff1, const HuffmanTree &huff2);
    
    // Operator overload
    // Description: Less than or equals operator. Compares "this" BinaryNode object with "rhs" BinaryNode object.
    //              Returns true if frequency of "this" BinaryNode object is < frequency of "rhs" BinaryNode object.
    //              If weights are the same, return true.
    bool operator<=(const HuffmanTree &rhs) const;

}; // End of HuffmanTree