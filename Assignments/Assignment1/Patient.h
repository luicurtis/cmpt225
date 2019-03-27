/*
 * Patient.h
 * 
 * Class Description: Models a walk-in clinic patient.
 * Class Invariant: Each patient has a unique care card number.
 *                  This care card number must have 10 digits.
 *                  This care card number cannot be modified. 
 *
 * Author:	Curtis Lui
 * Date:	January 14 2019
 */

#pragma once	// Preprocessor directive designed to cause the current source file
				// to be included only once in a single compilation.

#include <string>

using namespace std;

class Patient
{
	private:

		string name;		// Patient's name.
		string address;		// Patient's address.
		string phoneNum;	// Patient's phone number.
		string email;		// Patient's email.
		string careCard;	// Patient's care card number.

	public:
		// Default Constructor
		// Description: Create a patient with a care card number of "0000000000". 
		// Postcondition: All data members set to "To be entered", 
		//                except the care card number which is set to "0000000000".       
		Patient();

		// Parameterized Constructor
		// Description: Create a patient with the given care card number.
		// Postcondition: If aCareCard does not have 10 digits, then care card is set to "0000000000".
		//                All other data members set to "To be entered".
		Patient(string aCareCard);

		// Getters and setters
		// Description: Returns patient's name.
		string getName() const;

		// Description: Returns patient's address.
		string getAddress() const;

		// Description: Returns patient's phone.
		string getPhone() const;

		// Description: Returns patient's email.
		string getEmail() const;
		
		// Description: Returns patient's care card.
		string getCareCard() const;

		// Description: Sets the patient's name.
		// Postcondition: Patient's name is set to aName
		void setName(const string aName);

		// Description: Sets the patient's address.
		// Postcondition: Patient's address is set to anAddress.
		void setAddress(const string anAddress);

		// Description: Sets the patient's phone.
		// Postcondition: Patient's phone number is set to aPhone.
		void setPhone(const string aPhone);

		// Description: Sets the patient's email.
		// Postcondition: Patient's email is set to anEmail.
		void setEmail(const string anEmail);

		// Overloaded Operators
		// Description: Comparison operator. Compares "this" Patient object with "rhs" Patient object.
		//              Returns true if both Patient objects have the same care card number.
		bool operator == (const Patient & rhs);

		// Description: Greater than operator. Compares "this" Patient object with "rhs" Patient object.
		//              Returns true if the care card number of "this" Patient object is > the care card 
		//              number of "rhs" Patient object.
		bool operator > (const Patient & rhs);
		
		// Description: Prints the content of "this".
		friend ostream & operator<<(ostream & os, const Patient & p);

}; // end of Patient.h