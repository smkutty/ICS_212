/******************************************
 *
 * Name: Sreelakshmi Kutty
 *
 * Course: ICS 212
 *
 * Insstructor: Ravi Narayan
 *
 * Due date: 29 Feb 2020
 *
 * File: driver.c
 *
 * Description: driver code for functions
 *
 ********************************************/

#include <stdio.h>
#include <string.h>
#include "record.h"
#include "iofunctions.h"

int main(int argc, char * argv[])
{
    struct record bankone[5];
    int numcustomers;
    char filename[20];

    strcpy(filename, argv[1]);

    /* begin hardcodoing records *********************/

    bankone[0].accountno = 1000;
    strcpy(bankone[0].name, "name1\n");
    strcpy(bankone[0].address, "1111 Dole St \n");

    bankone[1].accountno = 1015;
    strcpy(bankone[1].name, "name2\n");
    strcpy(bankone[1].address, "2222 Dole St \n");

    bankone[2].accountno = 1030;
    strcpy(bankone[2].name, "name3\n");
    strcpy(bankone[2].address, "3333 Dole St \n");

    bankone[3].accountno = 1045;
    strcpy(bankone[3].name, "name4\n");
    strcpy(bankone[3].address, "4444 Dole St \n");

    bankone[4].accountno = 1060;
    strcpy(bankone[4].name, "name5\n");
    strcpy(bankone[4].address, "5555 Dole St \n");

    /* begin code for tests **************************/

    numcustomers = (sizeof(bankone))/(sizeof(bankone[0]));

    printf("\n **** Current number of customers: %d \n \n", numcustomers);

    printf("TEST 1 READING INPUT ----------------- \n");
    readfile(bankone, &numcustomers, filename);
    printf("Application has read file: %s \n \n", filename);

    printf("TEST 2 WRITING OUT ----------------\n");
    writefile(bankone, numcustomers, "example_out.txt");
    printf("Application wrote file: %s \n \n", "example_out.txt");

    printf("TEST 3 READING CREATED FILE ---------------- \n");
    readfile(bankone, &numcustomers, "example_out.txt");
    printf("Application has read new file: %s  \n \n", "example_out.txt");

    return 0;
}









