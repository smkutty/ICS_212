/*****************************************
 * NAME: Sreelakshmi Kutty
 *
 * COURSE: ICS 212
 *
 * INSTRUCTOR: Ravi Narayan
 *
 * DUE DATE: 18 April 2020
 *
 * File name: record.h
 *
 * Description: creates record struct
 ******************************************/

#ifndef RECORD_H
#define RECORD_H

struct record
{
    int              accountno;
    char             name[25];
    char             address[80];
    struct record *  next;
};


#endif
