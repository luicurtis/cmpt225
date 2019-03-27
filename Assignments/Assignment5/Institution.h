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

using namespace std;

class Institution
{
  private:
    string name;
    string mailAddress;
    string officeEmail;
    string officePhonenum;
    // a listing of all students information transferring to this institution,
    // a listing of all students information transferring from this institution.

    unsigned int numTransIn;
    unsigned int numTransOut;
}; // End of Institution