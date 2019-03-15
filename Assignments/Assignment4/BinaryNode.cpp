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
BinaryNode::BinaryNode()
{
    c = '\0';
    weight = 0;
    left = NULL;
    right = NULL;

} // Default Constructor

BinaryNode::BinaryNode(int weight, char c)
{
    this->weight = weight;
    this->c = c;

} // BinaryNode(int, char)

BinaryNode::BinaryNode(int weight, char c, BinaryNode *left, BinaryNode *right)
{
    this->weight = weight;
    this->c = c;
    this->left = left;
    this->right = right;
    
} // BinaryNode(int, char, BinaryNode, BinaryNode)

// Getters
int BinaryNode::getChar() const
{
    return c;

} // getChar()

int BinaryNode::getWeight() const
{
    return weight;

} // getFrequency()

BinaryNode *BinaryNode::getLeft() const
{
    return left;

} // getLeft() 

BinaryNode *BinaryNode::getRight() const
{
    return right;

} // getRight() 

// Setters
void BinaryNode::setChar(char c)
{
    this->c = c;

} // setChar()

void BinaryNode::setWeight(int weight)
{
    this->weight = weight;

} // setFrequency()
void BinaryNode::setLeft(BinaryNode *left)
{
    this->left = left;

} // setLeft(BinaryNode)

void BinaryNode::setRight(BinaryNode *right)
{
    this->right = right;

} // setRight(BinaryNode)

// Boolean helper functions
bool BinaryNode::isLeaf() const
{
    return (left == NULL && right == NULL);

} // isLeaf()

bool BinaryNode::hasLeft() const
{
    return (left != NULL);

} // hasLeft()

bool BinaryNode::hasRight() const
{
    return (right != NULL);

} // hasRight()

// Operator overload
// Description: Less than or equals operator. Compares "this" BinaryNode object with "rhs" BinaryNode object.
//              Returns true if weight of "this" BinaryNode object is < weight of "rhs" BinaryNode object.
//              If weights are the same, return true. Else return false.
bool BinaryNode::operator<=(const BinaryNode &rhs) const
{
    if (this->weight < rhs.getWeight())
    {
        return true;
    }
    else if(this->weight == rhs.getWeight())
    {
        return true;
    }
    else
    {
        return false;
    }

}