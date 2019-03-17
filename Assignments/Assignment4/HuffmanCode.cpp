/*
 * HuffmanCode.cpp
 *
 * Class Definition: Creates a collection of the huffman codes for each leaf
 *                   in the huffman tree
 *
 * Created on: 	March 2019
 * Author: 		Curtis Lui
 * 
 */

#include <iostream>
#include <cstdlib> // NULL
#include <string>
#include "HuffmanCode.h"
#include "BinaryNode.h"

HuffmanCode::HuffmanCode()
{
    for (int i = 0; i < NUM_CHAR_POSSIBILITIES; i++)
    {
        code[i] = "\0";
    }   

} // Default constructor

string* HuffmanCode::getCode()
{
    return code;
} // getCode()

void HuffmanCode::encode(BinaryNode *root, string subCode)
{
    // Depth First Traverse the tree to visit each leaf and get the
    // Corresponding huffman code
    // If unable to traverse left anymore and at a leaf
    if (root->getLeft() == NULL && root->isLeaf())
    {
        code[(unsigned char)root->getChar()] = subCode;
    }
    // Recursively traverse through left and right subtrees
    else
    {
        encode(root->getLeft(), subCode += '0');  // Add 0 to subCode when traversing left
        encode(root->getRight(), subCode += '1'); // Add 1 to subCode when traversing right
    }
}