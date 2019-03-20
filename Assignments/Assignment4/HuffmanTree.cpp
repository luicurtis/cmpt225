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

// Desc: Deafult constructor
// Post: Initializes one node and weight to 0
HuffmanTree::HuffmanTree()
{
    weight = 0;
    BinaryNode *newNode = new BinaryNode;
    root = newNode;

} // Default constructor

// Desc: Copy Constructor
// Post: this will be identical to rhs
HuffmanTree::HuffmanTree(const HuffmanTree &rhs)
{
    this->weight = rhs.getWeight();
    this->root = rhs.getRoot();
    
} // Copy constructor

// Desc: Constructor
// Post: Initializes one node with given character and weight = frequency
HuffmanTree::HuffmanTree(char character, int frequency)
{
    BinaryNode *newNode = new BinaryNode;
    newNode->setChar(character);
    root = newNode;
    weight = frequency;

} // HuffmanTree(char, int)

// Desc: Destructor
// Post: All nodes in the tree are deleted and weight is set to 0
HuffmanTree::~HuffmanTree()
{
    this->RecursiveDelete(root);
    root = NULL;
    weight = 0;
    
} // Destructor

// Desc: Returns the root of the tree
int HuffmanTree::getWeight() const
{
    return weight;

} // getWeight()

// Desc: Returns the root of the tree
BinaryNode *HuffmanTree::getRoot() const
{
    return root;

} // getRoot()


// Desc: Combines two Huffman trees
// Post: Heavier subtree will be placed on the left subtree and 
//       ligheter subtree on the right
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
// Desc: Less than or equals operator. Compares "this" BinaryNode object with "rhs" BinaryNode object.
//       Returns true if frequency of "this" BinaryNode object is < frequency of "rhs" BinaryNode object.
//       If weights are the same, return true.
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

// Helper function for destructor
void HuffmanTree::RecursiveDelete(BinaryNode *node)
{
    if(node)
    {
        RecursiveDelete(node->getLeft());
        RecursiveDelete(node->getRight());
        delete node;
    }
} // RecursiveDelete(BinaryNode*)