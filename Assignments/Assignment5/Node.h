/*
 * Node.h
 *
 * Class Definition: Node class in which the data is of ElementType data type.
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
	// Desc:	Default Constructor
	// Post:	Sets next to NULL
	Node();

	// Desc:	Constructor
	// Post:	Sets next to NULL and data to theData
	Node(ElementType theData);

	// Desc:	Constructor
	// Post:	Sets next to NULL, data to theData and
	//			next to theNextNode
	Node(ElementType theData, Node *theNextNode);

}; // end Node

// Implementation
// Desc:	Default Constructor
// Post:	Sets next to NULL
template <class ElementType>
Node<ElementType>::Node()
{
	next = NULL;
	
} // End of Node()

// Desc:	Constructor
// Post:	Sets next to NULL and data to theData
template <class ElementType>
Node<ElementType>::Node(ElementType theData)
{
	data = theData;
	next = NULL;

} // End of Node(ElementType)

// Desc:	Constructor
// Post:	Sets next to NULL, data to theData and
//			next to theNextNode
template <class ElementType>
Node<ElementType>::Node(ElementType theData, Node *theNextNode)
{
	data = theData;
	next = theNextNode;

} // End of Node(ElementType, Node*)
