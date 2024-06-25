/**************************************************
 * NAME: Sreelakshmi Kutty
 *
 * COURSE: ICS 212
 *
 * INSTRUCTOR: Ravi Narayan
 *
 * DUE DATE: 18 April 2020
 *
 * FILE: llist.h
 *
 * DESCRIPTION: header file for class definition
 ***************************************************/

#ifndef LLIST_H
#define LLIST_H

#include <iostream>
#include "record.h"

using namespace std;

class llist
{
private:
    char filename[16];
    record * start;
    int readfile();
    int writefile();
    record * reverse(record * );
    void cleanup();

public:
    int test;
    llist();
    llist(char[]);
    ~llist();
    int addRecord(int, char[], char[]);
    int printRecord(int);
    friend std::ostream & operator<<(std::ostream&, const llist&);
    int modifyRecord(int, char[]);
    int deleteRecord(int);
    void reverse();
};

#endif
