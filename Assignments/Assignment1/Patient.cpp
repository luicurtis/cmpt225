/*
 * Patient.cpp
 * 
 * Class Description: Models a walk-in clinic patient.
 * Class Invariant: Each patient has a unique care card number.
 *                  This care card number must have 10 digits.
 *                  This care card number cannot be modified. 
 *
 * Author: 	Curtis Lui
 * Date:	January 14 2019
 */

#include <iostream>
#include <string>
#include "Patient.h"

const int LENGTH_CARE_CARD = 10;

// Default Constructor
// Description: Create a patient with a care card number of "0000000000". 
// Postcondition: All data members set to "To be entered", 
//                except the care card number which is set to "0000000000".       
Patient::Patient() : name("To be entered"), address("To be entered"), phoneNum("To be entered"), email("To be entered"), careCard("0000000000")
{

}// end of Patients()

// Parameterized Constructor
// Description: Create a patient with the given care card number.
// Postcondition: If aCareCard does not have 10 digits, then care card is set to "0000000000".
//                All other data members set to "To be entered".
Patient::Patient(string aCareCard)
{
	// Check if aCareCard consists of 10 digits
	if (aCareCard.length() != LENGTH_CARE_CARD)
	{
		careCard = "0000000000";
	}
	else
	{
		careCard = aCareCard;
	}

	name = "To be entered";
	address = "To be entered";
	phoneNum = "To be entered";
	email = "To be entered";

} // end of Patient(string)

// Getters and setters
// Description: Returns patient's name.
string Patient::getName() const
{
	return name;

} // end of getName()

// Description: Returns patient's address.
string Patient::getAddress() const
{
	return address;

} // end of getAddress()

// Description: Returns patient's phone.
string Patient::getPhone() const
{
	return phoneNum;

} // end of getPhone()

// Description: Returns patient's email.
string Patient::getEmail() const
{
	return email;

} // end of getEmail()

// Description: Returns patient's care card.
string Patient::getCareCard() const
{
	return careCard;

} // end of getCareCard()

// Description: Sets the patient's name.
// Postcondition: Patient's name is set to aName
void Patient::setName(const string aName)
{
	name = aName;

} // end of setName()

// Description: Sets the patient's address.
// Postcondition: Patient's address is set to anAddress.
void Patient::setAddress(const string anAddress)
{
	address = anAddress;

} // end of setAddress()

// Description: Sets the patient's phone.
// Postcondition: Patient's phone number is set to aPhone.
void Patient::setPhone(const string aPhone)
{
	phoneNum = aPhone;

} // end of setPhone()

// Description: Sets the patient's email.
// Postcondition: Patient's email is set to anEmail.
void Patient::setEmail(const string anEmail)
{
	email = anEmail;

} // end of setEmail()

// Overloaded Operators
// Description: Comparison operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if both Patient objects have the same care card number.
bool Patient::operator == (const Patient & rhs)
{
	
	// Compare both Patient objects
	if (this->careCard == rhs.getCareCard()) 
		return true;
	else 
		return false;
	
} // end of operator ==

// Description: Greater than operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if the care card number of "this" Patient object is > the care card 
//              number of "rhs" Patient object
bool Patient::operator > (const Patient & rhs)
{
	
	// Compare both Patient objects
	if (this->careCard > rhs.getCareCard()) 
		return true;
	else 
		return false;
	
} // end of operator >


// Description: Prints the content of "this".
ostream & operator<<(ostream & os, const Patient & p)
{
	return os << p.careCard << " - Patient: " << p.name << ", " << p.address << ", " << p.phoneNum << ", " << p.email << endl;

} // end of operator<<

// end of Patient.cpp