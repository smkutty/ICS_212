/**********************************************************************
 *
 * Name: Sreelakshmi Kutty
 *
 * Course: ICS 212
 *
 * Instructor: Ravi Narayan
 *
 * Due date: 16 Feb 2020
 *
 * File: database.c
 *
 * Description: contains the 5 functions for account
 *
 **********************************************************************/

#include <stdio.h>
#include "database.h"
#include "record.h"

/***************************************
 * 
 * Function: addRecrod
 *
 * Description: adds record to database
 *
 * Parameters: next (struct record **)
 * 	       acountno (int)
 * 	       name (char[])
 * 	       address (char[])
 * Return: 0
 *
 ***************************************/ 

int addRecord (struct record ** next, int accountno, char name[], char address[])
{
    printf("\n This is a temporary message - addRecord successfully called");
    return 0;
}

/***************************************
 * 
 * Function: printRecord
 *
 * Description: prints specified record
 *
 * Parameters: start (struct record * )
 * 	       accountno (int)
 *
 * Return: 0
 *
 ***************************************/ 

int printRecord (struct record * start, int accountno)
{
    printf("\n This is a temporary message - printRecrod successfully called");
    return 0;
}

/***************************************
 *
 * Function: printAllRecords
 *
 * Description: prints all records
 *
 * Parameters: start (struct record *)
 *
 * Return: void
 *
 ***************************************/

void printAllRecords (struct record * start)
{
    printf("\n This is a temporary message - printAllRecords successful");
}

/****************************************
 *
 * Function: modifyRecord
 *
 * Description: modifies specified recor
 * 		with given addressd
 * 
 * Parameters: start (struct record *)
 * 	       accountno (int)
 * 	       address (char [])
 *
 * Return: 0
 *
 *****************************************/

int modifyRecord (struct record * start, int accountno, char address[])
{
    printf("\n This is a temporary message - modifyRecord successfully called");
    return 0;
}

/*****************************************
 *
 * Function: deleteRecord
 *
 * Description: deletes specified record
 *
 * Parameters: next (struct record **)
 * 	       accountno (int)
 *
 * Return: 0
 *
 *****************************************/ 

int deleteRecord (struct record ** next, int accountno)
{
    printf("\n This is a temporary message - deleteRecord successful");
    return 0;
}






