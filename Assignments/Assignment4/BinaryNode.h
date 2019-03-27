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
    // Desc: Default Constructor
    // Post: left and right is set to NULL
    BinaryNode();
    
    // Desc: Constructor
    // Post: Sets this->c to c and left and right to NULL
    BinaryNode(char c);

    // Desc: Constructor
    // Post: Sets this->c to c and this->left to left and this->right to right
    BinaryNode(char c, BinaryNode *left, BinaryNode *right);

    // Getters
    // Desc: Returns the c at the node
    int getChar() const;

    // Desc: Returns the root of the left subtree
    BinaryNode *getLeft() const;

    // Desc: Returns the root of the right subtree
    BinaryNode *getRight() const;

    // Setters
    // Desc: Sets the c at the node
    // Post: this->c = c
    void setChar(char c);

    // Desc: Sets the left BinaryNode pointer to point at a BinaryNode
    // Post: this->left = left
    void setLeft(BinaryNode *left);

    // Desc: Sets the right BinaryNode pointer to point at a BinaryNode
    // Post: this->right = right
    void setRight(BinaryNode *right);

    // Boolean helper functions
    // Desc: Returns true if the node has no children, else false
    bool isLeaf() const;

    // Desc: Returns true if the node has a left subtree, else false
    bool hasLeft() const;

    // Desc: Returns true if the node has a right subtree, else false
    bool hasRight() const;

}; // End of BinaryNode