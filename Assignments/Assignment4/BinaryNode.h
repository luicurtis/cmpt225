/*
 * BinaryNode.h
 *
 * Class Definition: Binary Node class in which the data is of ElementType data type.
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
    BinaryNode *left;
    BinaryNode *right;

  public:
    // Constructors
    BinaryNode();
    BinaryNode(char c);
    BinaryNode(char c, BinaryNode *left, BinaryNode *right);

    // Getters
    int getChar() const;
    BinaryNode *getLeft() const;
    BinaryNode *getRight() const;

    // Setters
    void setChar(char c);
    void setLeft(BinaryNode *left);
    void setRight(BinaryNode *right);

    // Boolean helper functions
    bool isLeaf() const;
    bool hasLeft() const;
    bool hasRight() const;

}; // End of BinaryNode