/*
 * HuffmanTree.cpp
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

#include <iostream>
#include <cstdlib> // NULL
#include <string>
#include "HuffmanTree.h"
#include "BinaryNode.h"

using namespace std;

HuffmanTree::HuffmanTree()
{
    weight = 0;
    BinaryNode *newNode = new BinaryNode;
    root = newNode;

} // Default constructor

HuffmanTree::HuffmanTree(const HuffmanTree &rhs)
{
    this->weight = rhs.getWeight();
    this->root = rhs.getRoot();
    
} // Copy constructor

HuffmanTree::HuffmanTree(char character, int frequency)
{
    BinaryNode *newNode = new BinaryNode;
    newNode->setChar(character);
    root = newNode;
    weight = frequency;

} // HuffmanTree(char, int)

HuffmanTree::~HuffmanTree()
{
    this->RecursiveDelete(root);
    
} // Destructor

void HuffmanTree::RecursiveDelete(BinaryNode *node)
{
    if(node)
    {
        RecursiveDelete(node->getLeft());
        RecursiveDelete(node->getRight());
        delete node;
    }
} // RecursiveDelete(BinaryNode*)

int HuffmanTree::getWeight() const
{
    return weight;

} // getWeight()

BinaryNode *HuffmanTree::getRoot() const
{
    return root;

} // getRoot()

void HuffmanTree::combine(const HuffmanTree &huff1, const HuffmanTree &huff2)
{
    // place the heavier subtree on the left
    if (huff1 <= huff2)
    {
        root->setLeft(huff2.getRoot());
        root->setRight(huff1.getRoot());

    }
    else
    {
        root->setLeft(huff1.getRoot());
        root->setRight(huff2.getRoot());
    }

    // Set new weight of the tree
    int weight1 = huff1.getWeight();
    int weight2 = huff2.getWeight();
    weight = weight1 + weight2;

} // combine(const HuffmanTree, const HuffmanTree)

// Operator overload
// Description: Less than or equals operator. Compares "this" BinaryNode object with "rhs" BinaryNode object.
//              Returns true if frequency of "this" BinaryNode object is <= frequency of "rhs" BinaryNode object.
//              Else return false.
bool HuffmanTree::operator<=(const HuffmanTree &rhs) const
{
    if (this->weight <= rhs.getWeight())
    {
        return true;
    }
    else
    {
        return false;
    }

} // operator<=(const HuffmanTree)
