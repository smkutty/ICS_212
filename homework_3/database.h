/*********************************************************
 *
 * Name: Sreelakshmi Kutty
 *
 * Course: ICS 212
 *
 * Instructor: Ravi Narayan
 *
 * Due date: 16 FEb 2020
 *
 * File: database.h
 *
 * Description: contains headers for functions
 *
 *********************************************************/

#include "record.h"

int addRecord (struct record **, int, char [], char []);
int printRecord (struct record *, int);
void printAllRecords (struct record *);
int modifyRecord (struct record *, int, char []);
int deleteRecord (struct record **, int);
