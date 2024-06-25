/*******************************************************
 * NAME: Sreelakshmi Kutty
 *
 * COURSE: ICS 212
 *
 * INSTRUCTOR: Ravi Narayan
 *
 * DUE DATE: 18 APril 2020
 *
 * FILE: llist.cpp
 *
 * DESCRIPTION: function definitions for llist.h
 *******************************************************/

#include <iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include "record.h"
#include "llist.h"

/***********************************************
 * FUNCTION: readfile
 *
 * DESCRIPTION: Reads struct record data from a
 *              file, stores data into an array
 *
 * Return: 0-success, 1-error
 ***********************************************/

int llist :: readfile()
{

    #ifdef DEBUGMODE
        cout << "\nInternal Debug********************* \n";
        cout << "Executing readfile \n";
        cout << "************************************* \n";
    #endif

    int accountno, val, count;
    char name[25], address[80], buffer;
    val = 1;

    ifstream myfile;
    myfile.open(filename);

    if(!myfile)
    {
        cout << "File does not exist";
        val = 0;
    }
    while(!myfile.eof() && val == 1)
    {
        myfile >> accountno;
        myfile.get(buffer);

        myfile.getline(name, 25);
        
        count = 0;
        while(((buffer = myfile.get()) != '$') && count<79)
        {
            address[count] = buffer;
            count++;
        }
        address[count] = '\0';

        addRecord(accountno, name, address);
    }


    return val;
}

/***********************************************
 * FUNCTION: writefile
 *
 * DESCRIPTION: writes/updates a file with data
 *
 * Return: 0-success, 1-error
 ***********************************************/

int llist :: writefile()
{
    #ifdef DEBUGMODE
        cout << "\nInternal Debug********************* \n";
        cout << "Executing writefile\n";
        cout << "************************************* \n";
    #endif

    strcpy(filename, "output.txt");
    ofstream myfile;
    int val;
    struct record * hold;

    hold = start;
    myfile.open(filename);

    if(myfile == NULL)
    {
        val = 1;
    }
    else
    {
        while(hold != NULL)
        {
            myfile << hold->accountno << endl;
            myfile << hold->name << endl;
            myfile << hold->address << endl;
            myfile << "\n\n";

            hold = hold->next;
        }

        myfile.close();
        val = 0;
    }

    return val;
}

/***********************************************
 * FUNCTION: reverse
 *
 * DESCRIPTION: reverses linked list
 *
 * PARAMETERS: reocrd * data - points to list
 *
 * RETURN: reverse linked list
 ***********************************************/

record* llist :: reverse(record* data)
{

    struct record * hold;

    if((data->next) == NULL)
    {
        start = data;
    }
    else
    {
        reverse(data->next);
        hold = data->next;
        hold->next = data;
        data->next = NULL;
    }

    return data;
}

/***********************************************
 * FUNCITON: cleanup
 *
 * DESCRIPTION: deallocates space when exiting
 ***********************************************/

void llist :: cleanup()
{
    struct record * next, * previous;

    next = start;

    while(next != NULL)
    {
        previous = next;
        next = next->next;
        delete(previous);
    }
}

/***********************************************
 * FUNCTION: llist::llist()
 *
 * DESCRIPTION: Constructor, initializes start
 *              and calls readfile
 ***********************************************/

llist :: llist()
{
    start = NULL;
    strcpy(filename, "input.txt");
    readfile();
}

/***********************************************
 * FUNCTION: llist::llist(char)
 * 
 * DESCRIPTION: Constructor, initializes start
 *              and calls readfile
 ***********************************************/

llist :: llist(char input[])
{
    start = NULL;
    strcpy(filename, input);
    readfile();
}

/***********************************************
 * FUNCTION: llist::~llist()
 *
 * DESCRIPTION: Destructor, calls writefile and
 *              cleans up memory
 ***********************************************/

llist :: ~llist()
{
    writefile();
    cleanup();
}

/***********************************************
 * FUNCTION: llist::addRecord
 *
 * DESCRIPTION: adds record to linked list
 *
 * PARAMETERS: start (struct record **)
 *             uaccountno-accountno
 *             uname-user name
 *             uaddress-user address
 *
 * Return: 0-success, -1-not added
 ***********************************************/

int llist::addRecord(int uaccountno, char uname[], char uaddress[])
{
    struct record *temp, *hold;
    int result;
    result = -1;
    hold = start;

    /*DEBUG FEATURE CODE START*/
    #ifdef DEBUGMODE
        cout << "\nInternal Debug********************* \n";
        cout << "Function called: addRecord \n";
        cout << "Parameters passed: \n";
        cout << "Account number: " << uaccountno << "\n";
        cout << "Name: " << uname << "\n";
        cout << "Address: " << uaddress << "\n";
        cout << "************************************* \n";
    #endif
    /*DEBUG FEATURE CODE END*/

    if(hold == NULL)
    {
        hold = new struct record;
        hold->accountno = uaccountno;
        strcpy(hold->name, uname);
        strcpy(hold->address, uaddress);
        hold->next = NULL;
        start = hold;
        result = 0;
    }
    else
    {
        while(hold->next != NULL)
        {
            hold = hold->next;
        }
        temp = new struct record;
        temp->accountno = uaccountno;
        strcpy(temp->name, uname);
        strcpy(temp->address, uaddress);

        temp->next= NULL;
        hold->next = temp;
        result = 0;
    }

    return result;
}

/***********************************************
 * FUNCTION: llist::printRecord
 *
 * DESCRIPTION: prints record by given number
 *
 * PARAMETERS: start (struct record *)
 *             uaccountno-account to print
 *
 * RETURN: 0-success, -1-record not found
 ***********************************************/

int llist :: printRecord(int uaccountno)
{
    struct record * current;
    int result;
    current = start;
    result = -1;

    /*DEBUG FEATURE CODE START*/
    #ifdef DEBUGMODE
        cout << "\nInternal Debug********************* \n";
        cout << "Function called: printRecord \n";
        cout << "Parameters passed: \n";
        cout << "Account number: " << uaccountno << "\n";
        cout << "************************************* \n";
    #endif
    /*DEBUG FEATURE CODE END*/
    

    while(current != NULL)
    {
        if(uaccountno == current->accountno)
        {
            cout << "Account number: " << current->accountno << "\n";
            cout << "Name: " << current->name << "\n";
            cout << "Address: " << current->address << "\n \n";

            result = 0;
        }
        current = current->next;
    }

    if(result == -1)
    {
        cout << "No such record found \n";
    }

    return result;
}

/***********************************************
 * Function: ostream& operator <<
 *
 * Description: overload operator to
 *              printAllRecords
 * *********************************************/

ostream & operator<<(ostream &out, const llist &mylist)
{
    struct record * current;
    current = mylist.start;

    while(current != NULL)
    {
        cout << "\nAccount number: " << current->accountno;
        cout << "\nName: " << current->name;
        cout << "\nAddress: " << current->address << endl;

        current = current->next;
    }

    return out;   
}

/***********************************************
 * FUNCTION: llist::modifyRecord
 *
 * DESCRIPTION: modifies record address
 *
 * PARAMETERS: start (struct record *)
 *             uaccountno-account to modify
 *             uaddress-new address
 *
 * RETURN: 0-success, -1-record not found
 ************************************************/

int llist::modifyRecord(int uaccountno, char uaddress[])
{
    struct record * current;
    int result;
    current = start;
    result = -1;

    /*DEBUG FEATURE CODE START*/
    #ifdef DEBUGMODE
        cout << "\nInternal Debug********************* \n";
        cout << "Function called: modifyRecord \n";
        cout << "Parameters passed: \n";
        cout << "Account number: " << uaccountno << "\n";
        cout << "Address: " << uaddress << "\n";
        cout << "************************************* \n";
    #endif

    while(current != NULL)
    {
        if(current->accountno == uaccountno)
        {
            strcpy(current->address, uaddress);
            result = 0;
        }
        current = current->next;
    }

    if(result == -1)
    {
        cout << "No such record found \n";
    }

    return result;
       
}

/************************************************
 * FUNCTION: llist::deleteRecord
 *
 * DESCRIPTION: delets record based on accountno
 *
 * PARAMETERS: start (struct record **) 
 *             uaccountno-account to be deleted
 *
 * RETURN: 0-success, -1-record not found
 ************************************************/

int llist :: deleteRecord(int uaccountno)
{
    struct record * current, * previous;
    int result;

    current = start;
    previous = start;
    result = -1;

    /*DEBUG FEATURE CODE START*/
    #ifdef DEBUGMODE
        cout << "\nInternal Debug********************** \n";
        cout << "Function called: deleteRecord \n";
        cout << "Parameters passed: \n";
        cout << "Account number: " << uaccountno << "\n";
        cout << "************************************** \n";
    #endif

    while(current != NULL)
    {
        if((current->accountno) == uaccountno)
        {
            if(current == start)
            {
                start = current->next;
                free(current);
                current = start;
                result = 0;
            }
            else
            {
                previous->next = current->next;
                free(current);
                current = previous->next;
                result = 0;
            }
        }
        else
        {
            previous = current;
            current = current->next;
        }
    }

    return result;
}

/************************************************
 * FUNCTION: llist:reverse
 *
 * DESCRIPTION: reverses linked list
 ************************************************/

void llist :: reverse()
{
    if(start != NULL)
    {
        reverse(start);
    }
    else
    {
        cout << "Empty list";
    }
}




//END OF SOURCE CODE
//
//
//














