/**********************************************
 * Name: Sreelakshmi Kutty
 *
 * Course: ICS 212
 *
 * Instructor: Ravi Narayan
 *
 * Due date: 16 February 2020
 *
 * File: record.h
 *
 * Description: defines the struct record
 *
 **********************************************/


#ifndef RECORD
#define RECORD

struct record
{
    int accountno;
    char name[25];
    char address[80];
    struct record * next;
};

#endif

