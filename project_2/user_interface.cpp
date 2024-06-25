/**********************************************************
 * NAME: Sreelakshmi Kutty
 *
 * COURSE: ICS 212
 *
 * INSTRUCTOR: Ravi Narayan
 *
 * DUE DATE: 18 April 2020
 *
 * FILE: user_interace
 *
 * DESCRIPTION: calls databased functions, gives user menu
 *              option, creates two executables
 **********************************************************/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "llist.h"
#include "record.h"
using namespace std;

/*prototypes*/
void getaddress(char[], int);
int getaccountno();

/*********************************************
 * FUNCTION: main
 *
 * DESCRIPTION: provides menu options to user
 *********************************************/

int main(int argc, char * argv[])
{
    char name[25], address[80];
    int accountno, run, option;
    run = 1;

    llist database;

    #ifdef DEBUGMODE
        cout << "\n===============================================";
        cout << "\n============== DEBUGMODE IS ON ================";
        cout << "\n===============================================";
    #endif
    while(run == 1)
    {
        cout << "\n \n ~~ This is the Bank Database ~~ \n To continue please select an option below by typing a number from 1-6 \n";
        cout << "1. Add a new record in the database \n";
        cout << "2. Print information about a record using the account # key \n";
        cout << "3. Print all records in the database \n";
        cout << "4. Modify the address field of a record specified by account # as key \n";
        cout << "5. Delete an existing record from the database using account # as key \n";
        cout << "6. Quit the program \n \n";
        cout << "Choosing option: ";

        cin >> option;
        
        /*go through 6 options and return corresponding message/function */
        switch(option)
        {
            case 1: /*addRecord*/
                cout << "\n Enter new account number: ";
                accountno = getaccountno();
                cin.ignore(100, '\n');

                cout << "\n Enter new name: ";
                cin.getline(name, 25);
                
                cout << "\n Enter new address (press $ to end address): ";
                getaddress(address, 80);

                database.addRecord(accountno, name, address);

                #ifdef DEBUGMODE
                    cout << "\n==== DEBUGMODE =================";
                    cout << "\nFunction called: addRecord";
                    cout << "\nYour account number is: " << accountno;
                    cout << "\nYour name is: " << name;
                    cout << "\nYour address is: " << address;
                    cout << "\n================================";
                #endif
                break;

            case 2: /*printRecord*/
                cout << "Enter the account number you wish to print: ";
                accountno = getaccountno();
                database.printRecord(accountno);

                #ifdef DEBUGMODE
                    cout << "\n==== DEBUGMODE =================";
                    cout << "\nFunction called: printRecord";
                    cout << "\nAccount number entered: " << accountno << "\n";
                    cout << "\n================================";
                #endif
                break;

            case 3: /*printAllRecords*/
                cout << "\nPrinting all records\n";
                cout << database;

                #ifdef DEBUGMODE
                    cout << "\n==== DEBUGMODE =================";
                    cout << "\nFunction called: printAllRecords";
                    cout << "\n================================";
                #endif
                break;

            case 4: /*modifyRecord*/
                cout << "\n Enter the account number you wish to modify: ";
                accountno = getaccountno();
                cout << "\n Enter new address: ";
                getaddress(address, 80);
                database.modifyRecord(accountno, address);

                #ifdef DEBUGMODE
                    cout << "\n==== DEBUGMODE =================";
                    cout << "\nFunction called: modifyRecord";
                    cout << "\nAccount number entered: " << accountno;
                    cout << "\nAddress entered: " << address << "\n";
                    cout << "\n================================";
                #endif
                break;

            case 5: /*deleteRecord*/
                cout << "\nEnter the account number you wish to delete: ";
                accountno = getaccountno();
                database.deleteRecord(accountno);

                #ifdef DEBUGMODE
                    cout << "\n==== DEBUGMODE =================";
                    cout << "\nFunction called: deleteRecord";
                    cout << "\nAccount number entered " << accountno << "\n";
                    cout << "\n================================";
                #endif
                break;

            case 6: /*exit program*/
                cout << "\n You have exited this program.";
                run = 0;
                break;

            default: /*assume invalid option*/
                cout << "\n You have not entered a valid option. Enter a # from 1 through 6.";
        }
    }

    return 0;
}

/***********************************************
 * Function: getaddress
 *
 * Description: gets address from user with 79
 *              max characters
 *
 * Parameters: address (char[])
 *             max (int)
 *
 * Return: void
 ************************************************/

void getaddress(char address[], int max)
{
    int index = 0;
    char c[1]; //gets characters from input
    c[0] = cin.get();
    //$ indicates end of address
    
    while((c[0] != '$') && (index < max))
    {
        address[index] = c[0];
        c[0] = cin.get();
        index++;
    }
    address[index] = '\0';
}

/*************************************************
 * Function: getaccountno
 *
 * Description: gets accountno number
 *
 * Parameters: int * (accountno address)
 *
 * Return: void
 *************************************************/

int getaccountno()
{
    int n, t;
    t = 0;
    while(t == 0)
    {
        cin >> n;
        if(n < 0)
        {
            cout << "\nAccount number must be positive. Please try again: ";
        }
        else
        {
            t = 1;
        }
    }
    return n;

}


















