/*
 * List.cpp
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

#include <string>
#include <cstddef>
#include <iostream>
#include "Patient.h"
#include "List.h"

// Default constructor
// Description: Creates a list of patients
// Postcondition: elementCount is set to 0 and capacity is set to MAX_ELEMENTS
List::List() : elementCount(0), capacity(MAX_ELEMENTS)
{
    
} // end of List()

// Description: Returns the total element count currently stored in List.
int List::getElementCount() const
{
    return elementCount;

} // end of getElementCount()

// Description: Insert an element.
//			    Returns false if insertion was not successful.
//				Returns true is insertion was successful
// Precondition: newElement must not already be in data collection and list is not full.  
// Postcondition: newElement inserted and elementCount has been incremented. 
bool List::insert(const Patient& newElement)
{
    // Check if list is full
    if (elementCount == capacity)
    {
        return false;
    }

    Patient* target;
    target = search(newElement);

    // If target returned NULL, then newElement is not in the list yet
    if (target == NULL)
    {
        // Insert element at last spot
        elements[elementCount] = newElement;
        elementCount++;
        
        // Sort patients by Care Card in asending order
        Patient temp;
        for (int i = 0; i < elementCount; i++)
        {
            // Check if element to the right is smaller
            for (int j = i + 1; j < elementCount; j++)
            {
                // Swap elements if smaller element on the right
                if (elements[j].getCareCard() < elements[i].getCareCard())
                {
                    temp = elements[i];
                    elements[i] = elements[j];
                    elements[j] = temp;
                }
            }
        }

        return true;
    }
    // If target was found return false
    else
    {
        return false;
    }
} // end of insert()

// Description: Remove an element. 
// 				Returns false if patient could not be removed
//				Returns true if patient was removed succesfully
// Postcondition: toBeRemoved is removed and elementCount has been decremented.		
bool List::remove(const Patient& toBeRemoved)
{
    Patient* target;
    target = search(toBeRemoved);

    // If target returns NULL, then element is not in the list yet
    if (target == NULL)
    {
        return false;
    }

    // If element returns an pointer, then element exists
    else
    {
        ptrdiff_t index = target - &elements[0];    // Find indexing of toBeRemoved based on it's address

        // Overwrite Patient at index by shifting elements over
        for (int i = index; i < elementCount; ++i)
        {
            elements[i] = elements[i + 1];  // Copy the next element
        }

        Patient emptyPatient;
        elements[elementCount] = emptyPatient;  // Place default patient in the last place of the list since you cannot delete the entry in static arrays
        elementCount--;

        return true;
    }

} // end of remove()

// Description: Remove all elements.
// Postcondition: 	elementCount decremented to 0
//					All patients will be overwritten withthe Default patient:
//                  - All data member set to "To be entered"
//                  - Care card number set to "0000000000"
void List::removeAll()
{
    Patient emptyPatient;

    for (int i = 0; i < elementCount; i++)
    {
        elements[i] = emptyPatient;
    }
    elementCount = 0;

} // end of removeAll()

// Description: Prints the lists of patients in ascending order of care card numbers
void List::printList() const
{
    for (int i = 0; i < elementCount; i++)
    {
        cout << elements[i];
    }
    
} // end of printList

// Description: Search for target element.
//              Returns a pointer to the element if found,
//              otherwise, returns NULL.
Patient* List::search(const Patient& target)
{
    for (int i = 0; i < elementCount; i++)
    {
        if (elements[i].getCareCard() == target.getCareCard())
        {
            return &elements[i];
        }
    }

    // If target was not found
    return NULL;

} // end of search()













