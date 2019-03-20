/*
 * BinaryNode.cpp
 *
 * Class Definition: Binary Node class in which the data is of ElementType data type.
 *                   Designed and implemented as a non-ADT.
 *
 * Created on: 	March 2019
 * Author: 		Inspired from Lecture 19 source files and modified by Curtis Lui. 
 * 
 */

#include <iostream>
#include <cstdlib> // NULL
#include "BinaryNode.h"

using namespace std;

 // Constructors
// Desc: Default Constructor
// Post: left and right is set to NULL
BinaryNode::BinaryNode()
{
    c = '\0';
    left = NULL;
    right = NULL;

} // Default Constructor

// Desc: Constructor
// Post: Sets this->c to c and left and right to NULL
BinaryNode::BinaryNode(char c)
{
    this->c = c;
    this->left = NULL;
    this->right = NULL;

} // BinaryNode(int, char)

// Desc: Constructor
// Post: Sets this->c to c and this->left to left and this->right to right
BinaryNode::BinaryNode(char c, BinaryNode *left, BinaryNode *right)
{
    this->c = c;
    this->left = left;
    this->right = right;
    
} // BinaryNode(int, char, BinaryNode, BinaryNode)

// Getters
// Desc: Returns the c at the node
int BinaryNode::getChar() const
{
    return c;

} // getChar()

// Desc: Returns the root of the left subtree
BinaryNode *BinaryNode::getLeft() const
{
    return left;

} // getLeft() 

// Desc: Returns the root of the right subtree
BinaryNode *BinaryNode::getRight() const
{
    return right;

} // getRight() 


// Desc: Sets the c at the node
// Post: this->c = c
void BinaryNode::setChar(char c)
{
    this->c = c;

} // setChar()


// Desc: Sets the left BinaryNode pointer to point at a BinaryNode
// Post: this->left = left
void BinaryNode::setLeft(BinaryNode *left)
{
    this->left = left;

} // setLeft(BinaryNode)

// Desc: Sets the right BinaryNode pointer to point at a BinaryNode
// Post: this->right = right
void BinaryNode::setRight(BinaryNode *right)
{
    this->right = right;

} // setRight(BinaryNode)

// Boolean helper functions
// Boolean helper functions
// Desc: Returns true if the node has no children, else false
bool BinaryNode::isLeaf() const
{
    return (left == NULL && right == NULL);

} // isLeaf()

// Desc: Returns true if the node has a left subtree, else false
bool BinaryNode::hasLeft() const
{
    return (left != NULL);

} // hasLeft()

// Desc: Returns true if the node has a right subtree, else false
bool BinaryNode::hasRight() const
{
    return (right != NULL);

} // hasRight()