/*
 * BinaryNode.h
 *
 * Class Definition: Binary BinaryNode class in which the data is of ElementType data type.
 *                   Designed and implemented as a non-ADT.
 *
 * Created on: 	March 2019
 * Author: 		Inspired from Lecture 19 source files and modified by Curtis Lui. 
 * 
 */

#pragma once

#include <cstdlib> // NULL

using namespace std;

class BinaryNode
{
  private: // Data members
    char c;
    int weight;
    BinaryNode *left;
    BinaryNode *right;

  public:
    // Constructors
    BinaryNode();
    BinaryNode(int weight, char c);
    BinaryNode(int weight, char c, BinaryNode *left, BinaryNode *right);

    // Getters
    int getChar() const;
    int getWeight() const;
    BinaryNode *getLeft() const;
    BinaryNode *getRight() const;

    // Setters
    void setChar(char c);
    void setWeight(int weight);
    void setLeft(BinaryNode *left);
    void setRight(BinaryNode *right);

    // Boolean helper functions
    bool isLeaf() const;
    bool hasLeft() const;
    bool hasRight() const;

    // Operator overload
    // Description: Less than or equals operator. Compares "this" BinaryNode object with "rhs" BinaryNode object.
	  //              Returns true if weight of "this" BinaryNode object is < weight of "rhs" BinaryNode object.
    //              If weights are the same, return true.
    bool operator<=(const BinaryNode &rhs) const;

}; // End of BinaryNode