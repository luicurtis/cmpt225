/*
 * Institution.h
 *
 * Class Definition: 
 *
 * Created on: 	March 2019
 * Author: 		Curtis Lui
 * 
 */

#include <string>
#include "Student.h"

using namespace std;

const int MAX_NUM_STUDENTS = 4000000;

class Institution
{
  private:
    string name;
    string mailAddress;
    string regOffEmail;
    string regOffPhonenum;
    
    AVLNode *TOptr;  // AVL tree pointer to root of listing of all students information transferring to this institution,
    AVLNode *FROMptr;   // AVL Heap tree pointer to root of a listing of all students information transferring from this institution.
    AVLNode TOTable[MAX_NUM_STUDENTS];
    AVLNode FROMTable[MAX_NUM_STUDENTS];
    
    unsigned int numTransIn;
    unsigned int numTransOut;
}; // End of Institution