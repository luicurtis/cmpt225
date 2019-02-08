/*
 * Node.h
 *
 * Class Definition: Node of a singly linked list 
 *                   in which the data is of "int" data type.
 *                   Designed and implemented as a non-ADT.
 *
 * Created on: 
 * Author: 
 */
 
// #pragma once is shorthand for the 2 #include guards we've seen before:
// #ifndef _NODE and #define _NODE
// and it means: do not include me more than once.
#pragma once

#include <cstdio>  // Needed for NULL

template <class ElementType> class Node
{
	public:
		// Public attributes - Why are the attributes public?
		ElementType data;     // The data in the node
		Node* next;   // Pointer to next node
		
		// Constructors (why no destructor?)
		Node();
		Node(ElementType theData);
		Node(ElementType theData, Node* theNextNode);

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
Node<ElementType>::Node(ElementType theData, Node* theNextNode)
{
	data = theData;
	next = theNextNode;
}
