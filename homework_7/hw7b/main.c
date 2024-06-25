/*******************************************
 * NAME: Sreelakshmi Kutty
 *
 * COURSE: ICS 212
 *
 * INSTRUCTOR: Ravi Narayan
 *
 * DUE DATE: 31 March 2020
 *
 * FILE: main.c
 *
 * DESCRIPTION: driver for functions
 *******************************************/

#include <stdio.h>
#include "functions.h"

/**********************************
 * Function: main
 *
 * Description: runs functions
 **********************************/

int main(int args, char * argv[])
{
    unsigned char one[4000], two[4000], three[4000];
    int size;
    size = sizeof(one[0]);

    printf("\n *** IMAGE 1 *** 1 *** 1 *** 1 *** 1 *** 1 *** 1 *** \n");
    readfile(one, &size, "image1.gif");
    printinfor(one);
    printf("Modified image1 data ----------- \n");
    modify(one);
    printinfor(one);
    writefile(one, size, "result1.gif");

    printf("\n *** IMAGE 2 *** 2 *** 2 *** 2 *** 2 *** 2 *** 2 *** \n");
    readfile(two, &size, "image2.gif");
    printinfor(two);
    printf("Modified image2 data ----------- \n");
    modify(two);
    printinfor(two);
    writefile(two, size, "result2.gif");

    printf("\n *** IMAGE 3 *** 3 *** 3 *** 3 *** 3 *** 3 *** 3 *** \n");
    readfile(three, &size, "image3.gif");
    printinfor(three);
    printf("Modified image3 data ----------- \n");
    modify(three);
    printinfor(three);
    writefile(three, size, "result3.gif");

    return 1;
}
