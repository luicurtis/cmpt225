/*
 * walkIn.cpp
 * 
 * Description: Represents a walk-in patient system.
 * 
 *              The system allows the receptionist to:
 *              - enter a new patient into the system
 *              - remove a patient from the system
 *              - search for an existing patient
 *              - modify a patient's records (adding patient's information or changing)
 *              - Print all of the patients by asending order of care card numbers
 *
 * Author:  Curtis Lui
 * Date:    January 14 2019
 * 
 */

// You can add #include statements if you wish.
#include <iostream>
#include <string>
#include "Patient.h"
#include "List.h"

using namespace std;

const int LENGTH_CARE_CARD = 10;

void printList(List* patientList);
void printMenu();

int main()
{
    // Variable declartion
    bool end = false;
    bool removeEle = false;
    bool insertEle = false;
    bool modifyEle = false;
    int choice = 0;
    int modify = 0;
    string newName = "\0";
    string newAddress = "\0";
    string newPhone = "\0";
    string newEmail = "\0";
    string inputCC = "\0";
    string inputName = "\0";
    string inputAddress = "\0";
    string inputPhone = "\0";
    string inputEmail = "\0";

    List* patients = new List();    // Heap-allocated List object

    do
    {
        // Prompt Receptionist with menu
        printMenu();
        cin >> choice;

        // Enter new patient
        if (choice == 1)
        {
            cout << endl << "Enter a new patient selected ..." << endl;
            cout << "Please insert the patient's 10 digit care card number: ";
            cin >> inputCC;

            Patient newPatient(inputCC);
            insertEle = patients->insert(newPatient);

            if (inputCC.length() != LENGTH_CARE_CARD)
            {
                cout << endl << "ERROR: Care card number is not 10 digits. An empty patient has been created for you to edit." << endl;

            }
            else if (insertEle == false)
            {
                cout << endl << "ERROR: List is full or Patient already exists in the system." << endl;
            }

            printList(patients);

        }// choice 1

        // Remove patient
        else if (choice == 2)
        {
            cout << endl << "Remove a patient from the system selected ..." << endl;
            cout << "Please insert the 10 digit care card number of the patient you want to remove: ";
            cin >> inputCC;

            Patient searchPatient(inputCC);

            if (inputCC.length() != LENGTH_CARE_CARD)
            {
                cout << "ERROR: Care card number is not 10 digits. " << endl;
            }
            else
            {
                removeEle = patients->remove(searchPatient);
                if (removeEle == false)
                {
                    cout << "ERROR: Patient with care card: " << inputCC << " is not in the system." << endl;
                }
                else
                {
                    cout << "Patient removed from the system" << endl;
                }
            }

            printList(patients);

        } // choice 2

        // Search for patient
        else if (choice == 3)
        {
            cout << endl << "Search for a patient selected ..." << endl;
            cout << "Please insert the 10 digit care card number of the patient you want to search for: ";
            cin >> inputCC;

            Patient searchPatient(inputCC);
            Patient* target;
            target = patients->search(searchPatient);

            if (inputCC.length() != LENGTH_CARE_CARD)
            {
                cout << "ERROR: Care card number is not 10 digits. " << endl;
            }

            else if (target == NULL)
            {
                cout << "Patient with care card: " << inputCC << " is not in the system." << endl;
            }

            else
            {
                cout << "Patient with care card: " << inputCC << "is in the system!" << endl;
            }
            
            printList(patients);

        } // choice 3
        
        // Modify patient
        else if (choice == 4)
        {
            cout << endl << "Modify a patient's records selected ..." << endl;
            cout << "Please insert the 10 digit care card number of the patient you want to modify: ";
            cin >> inputCC;

            Patient searchPatient(inputCC);
            Patient* target;
            target = patients->search(searchPatient);
            
            if (inputCC.length() != LENGTH_CARE_CARD)
            {
                cout << "ERROR: Care card number is not 10 digits. " << endl;
            }
            else if (target == NULL)
            {
                cout << "ERROR: Patient with care card: " << inputCC << " is not in the system." << endl;
            }
            else
            {
                cout << "Enter the number for the action needed:" << endl;
                cout << " 1. Change patient's name" << endl;
                cout << " 2. Change patient's address" << endl;
                cout << " 3. Change patient's phone number" << endl;
                cout << " 4. Change patient's e-mail" << endl;
                cout << " 5. Back to main menu" << endl;
                cin >> modify;

                if (modify == 1)
                {
                    cin.clear();
                    cin.ignore(100, '\n');
                    cout << "Change patient's name selected ..." << endl;
                    cout << "Please enter the new name: ";
                    getline(cin, newName);

                    target->setName(newName);
                }

                else if (modify == 2)
                {
                    cin.clear();
                    cin.ignore(100, '\n');
                    cout << "Change patient's address selected ..." << endl;
                    cout << "Please enter the new address: ";
                    getline(cin, newAddress);

                    target->setAddress(newAddress);
                }

                else if (modify == 3)
                {
                    cin.clear();
                    cin.ignore(100, '\n');
                    cout << "Change patient's phone number selected ..." << endl;
                    cout << "Please enter the new phone number: ";
                    getline(cin, newPhone);

                    target->setPhone(newPhone);
                }

                else if (modify == 4)
                {
                    cin.clear();
                    cin.ignore(100, '\n');
                    cout << "Change patient's name e-mail ..." << endl;
                    cout << "Please enter the new e-mail: ";
                    getline(cin, newEmail);

                    target->setEmail(newEmail);
                }

                else if (modify == 5)
                {
                    cout << "Back to main menu selected ..." << endl;
                }

                else
                {
                    cin.clear();
                    cin.ignore(100, '\n');
                    choice = 0;
                    cout << "ERROR: Invalid choice. Please try again." << endl << endl;
                }
            }

            printList(patients);

        }// Choice 4
        
        //Print patients
        else if (choice == 5)
        {
            cout << endl << "Print all of the patients selected ..." << endl;
            printList(patients);

        }

        // Exit program
        else if (choice == 6)
        {
            cout << "Exiting program..." <<endl;
            end = true;
        }

        // Invalid choice made
        else
        {
            cin.clear();
            cin.ignore(100, '\n');
            choice = 0;           
            cout << "ERROR: Invalid choice. Please try again." << endl << endl;
        }

    } // do - while
    while(end == false);

    cout << "Program closed." <<endl;

    return 0;

} // end of main()

// Description: Prints list of patients in that are currently in system
void printList(List* patientList)
{
    cout << endl << "There are currently " << patientList->getElementCount() << " patients in List." << endl;
    cout << "Current patient list:" << endl;
    patientList->printList();
    cout << endl;
}

// Description: Prints main menu for receptionist
void printMenu()
{
    cout << "Enter the number for the action needed:" << endl;
    cout << " 1. Enter a new patient into the system." << endl;
    cout << " 2. Remove a patient from the system." << endl;
    cout << " 3. Search for an existing patient." << endl;
    cout << " 4. Modify a patient's records." << endl;
    cout << " 5. Print all of the patients in asending order or care card numbers." <<endl;
    cout << " 6. Exit program." << endl;
}