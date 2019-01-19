/*
 * List.h
 * 
 * Class Description: List data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                  - Each element is unique (no duplicates)
 * 					- Elements are stored in asending order
 * 					- Specified maximum number of Patients to be stored
 *
 * Author:	Curtis Lui
 * Date:	14 Jan 2019
 */

#pragma once

#include <string>
#include "Patient.h"

using namespace std;

class List
{
	private:
		static const int MAX_ELEMENTS = 5; // Small capacity so can test when data collection becomes full
		Patient elements[MAX_ELEMENTS];    // Data structure with capacity of MAX_ELEMENTS
		int elementCount;                  // Current element count in element array
		int capacity;                      // Actual maximum capacity of element array   

	public:

		// Default constructor
		// Description: Creates a list of patients
		// Postcondition: elementCount is set to 0 and capacity is set to MAX_ELEMENTS
		List();

		// Description: Returns the total element count currently stored in List.
		int getElementCount() const;

		// Description: Insert an element.
		//				Returns false if insertion was not successful.
		//				Returns true is insertion was successful
		// Precondition: newElement must not already be in data collection and list is not full.  
		// Postcondition: newElement inserted and elementCount has been incremented.   
		bool insert(const Patient& newElement);

		// Description: Remove an element. 
		// 				Returns false if patient could not be removed
		//				Returns true if patient was removed succesfully
		// Postcondition: toBeRemoved is removed and elementCount has been decremented.	
		bool remove(const Patient& toBeRemoved);
		
		// Description: Remove all elements.
		// Postcondition: 	elementCount decremented to 0
		//					All patients will be overwritten withthe Default patient:
		//                  - All data member set to "To be entered"
		//                  - Care card number set to "0000000000"
		void removeAll();

		// Description: Prints the lists of patients in ascending order of care card numbers
		void printList() const;
	
		// Description: Search for target element.
		//              Returns a pointer to the element if found,
		//              otherwise, returns NULL.
		Patient* search(const Patient& target);

}; // end List.h