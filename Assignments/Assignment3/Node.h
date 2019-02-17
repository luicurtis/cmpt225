/*
 * Node.h
 *
 * Class Definition: Node of a singly linked list 
 *                   in which the data is of ElementType data type.
 *                   Designed and implemented as a non-ADT.
 *
 * Created on: 	February 16 2019
 * Author: 		Inspired from Lab4 source files and modified by Curtis Lui. 
 * 
 */

#pragma once

#include <cstdio> // Needed for NULL

template <class ElementType>
class Node
{
  public:
	// Public attributes
	ElementType data; // The data in the node
	Node *next;		  // Pointer to next node

	// Constructors
	Node();
	Node(ElementType theData);
	Node(ElementType theData, Node *theNextNode);

}; // end Node

// Implementation

template <class ElementType>
Node<ElementType>::Node()
{
	next = NULL;
}

template <class ElementType>
Node<ElementType>::Node(ElementType theData)
{
	data = theData;
	next = NULL;
}

template <class ElementType>
Node<ElementType>::Node(ElementType theData, Node *theNextNode)
{
	data = theData;
	next = theNextNode;
}
