/* 
 * BinaryHeap.cpp
 *
 * Description: Minimum binary heap data collection ADT class. Array-based implementation.
 * 
 * Author: 
 *
 * Last Modification: March 2019
 *
 */  

#include "BinaryHeap.h"  // Header file

  
// Default Constructor
BinaryHeap::BinaryHeap() {
	
   elementCount = 0;
   
   // what else?
   
} // end of default constructor

	
// Description: Returns the number of elements in the Binary Heap.
// Time Efficiency: O(1)
int BinaryHeap::getElementCount() const {
	
   return elementCount;
   
}  // end getElementCount


// Description: Inserts newElement into the Binary Heap.
//              It returns "true" if successful, otherwise "false".        
// Postcondition: Remains a Binary Heap after the insertion.
bool BinaryHeap::insert(const Event& newElement) {
	// This is the insert operation into a min binary heap

    bool ableToInsert = false;
  
    // If there is space ...
	if (elementCount < capacity) {

		// Insert newElement at end of array.
		elements[elementCount] = newElement;

		elementCount++;

		// Recursively put the array back into a heap
		reHeapUp(elementCount-1);

		ableToInsert = true;
	} 

	// Modify/add code if necessary

    return ableToInsert;

} // end insert


// Utility method - Recursively put the array back into a minimum binary heap.
void BinaryHeap::reHeapUp(int indexOfBottom) {

   // To do

	return;
	
} // end reHeapUp


// Description: Deletes the root of the Binary Heap.
//              It returns "true" if successful, otherwise "false".
// Precondition: This Binary Heap is not empty.
// Postcondition: Remains a Binary Heap after the deletion.
bool BinaryHeap::remove() {
	
	// This is the remove operation

	bool ableToRemove = false;
	  
	// To do
	// This version of remove does not retrieve.


	return ableToRemove;
	
}  // end remove


// Utility method - Recursively put the array back into a minimum binary heap.
void BinaryHeap::reHeapDown(int indexOfRoot) {

	int indexOfMinChild = indexOfRoot;

	// Find indices of children.
	int indexOfLeftChild = 2*indexOfRoot+1;
	int indexOfRightChild = 2*indexOfRoot+2;

	// Base case: elements[indexOfRoot] is a leaf as it has no children
	if (indexOfLeftChild > elementCount-1) return;

	// If we need to swap, select the smallest child
	if (elements[indexOfRoot] > elements[indexOfLeftChild])
		indexOfMinChild = indexOfLeftChild;

	// Check if there is a right child, is it the smallest?
	if (indexOfRightChild < elementCount) {
		if (elements[indexOfMinChild] > elements[indexOfRightChild])
			indexOfMinChild = indexOfRightChild;
		}

	// Swap parent with smallest of children.
	if (indexOfMinChild != indexOfRoot) {

		Event temp = elements[indexOfRoot];
		elements[indexOfRoot] = elements[indexOfMinChild];
		elements[indexOfMinChild]  = temp;

		// Recursively put the array back into a heap
		reHeapDown(indexOfMinChild);
	}

	return;
	
} // end reHeapDown


// Description: Retrieves (but does not remove) the root.
// Precondition: This Binary Heap is not empty.
// Postcondition: This Binary Heap is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this Priority Queue is empty.
// Time Efficiency: O(1) 
Event BinaryHeap::retrieve() const throw(EmptyDataCollectionException) {
	
   // This is the retrieve operation
   
   // Enforce precondition
   if ( elementCount > 0 )
      return elements[0];
   else
      throw(EmptyDataCollectionException("peek() called with an empty BinaryHeap.")); 

}  // end retrieve


// For Testing Purposes
// Description: Prints the content of "rhs".
ostream& operator<<(ostream & os, const BinaryHeap& rhs) {

	for ( unsigned int index = 0; index < rhs.elementCount; index++ )
		os << rhs.elements[index]; // Print data

	return os;
} // end of operator <<


//  End of implementation file.