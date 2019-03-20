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
    // Desc: Deafult constructor
    // Post: Initializes one node and weight to 0
    HuffmanTree();

    // Desc: Copy Constructor
    // Post: this will be identical to rhs
    HuffmanTree(const HuffmanTree &rhs);

    // Desc: Constructor
    // Post: Initializes one node with given character and weight = frequency
    HuffmanTree(char character, int frequency); // Initializes one node

    // Desc: Destructor
    // Post: All nodes in the tree are deleted and weight is set to 0
    ~HuffmanTree();

    // Desc: Returns weight of the tree
    int getWeight() const;

    // Desc: Returns the root of the tree
    BinaryNode *getRoot() const;
    
    // Desc: Combines two Huffman trees
    // Post: Heavier subtree will be placed on the left subtree and 
    //       ligheter subtree on the right
    void combine(const HuffmanTree &huff1, const HuffmanTree &huff2);
    
    // Operator overload
    // Desc: Less than or equals operator. Compares "this" BinaryNode object with "rhs" BinaryNode object.
    //       Returns true if frequency of "this" BinaryNode object is < frequency of "rhs" BinaryNode object.
    //       If weights are the same, return true.
    bool operator<=(const HuffmanTree &rhs) const;

    // Helper function for destructor
    void RecursiveDelete(BinaryNode *root);
}; // End of HuffmanTree