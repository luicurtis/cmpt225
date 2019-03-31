/*
 * Institution.h
 *
 * Definition: An institution object that contains all relavent informatin
 *             related to the instiution
 *
 * Created on: 	March 2019
 * Author: 		Curtis Lui
 * 
 */

#include <string>
#include "Student.h"
#include "Node.h"

using namespace std;

const int MAX_NUM_STUDENTS = 40000;

class Institution
{
  private:
    string name;
    string mailAddress;
    string regOffEmail;
    string regOffPhonenum;
    
    Node<Student> *TOptr;                           
    Node<Student> *FROMptr;                         
    Node<Student> *studentTable[MAX_NUM_STUDENTS]; 
    
    unsigned int numTransIn;
    unsigned int numTransOut;
}; // End of Institution