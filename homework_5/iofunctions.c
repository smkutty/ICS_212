/*****************************************
 *
 * Name: Sreelakshmi Kutty
 *
 * Course: ICS 212
 *
 * Instructor: Ravi Narayan
 *
 * Due date: 29 Feb 2020
 *
 * File: iofunctions.c
 *
 * Description: defines functions
 *
 ******************************************/

#include <stdio.h>
#include <string.h>
#include "record.h"
#include "iofunctions.h"      

/*************************************************************
 *
 * Function: readfile
 *
 * Description: function reads data from file and stores it 
 *              in array of records
 *
 * Parameters: accarray(struct account[]): array of accounts
 *             numcust(int*): pointer to number of records
 *             filename(char[]): name of file
 *
 * Return values: 0 for success, 1 for error
 *
 *************************************************************/

int readfile(struct record accarray[], int* numcust, char filename[])
{

    FILE * fp;
    int i, val, check, temp;

    i = 0;
    check = 0;

    fp = fopen(filename, "r");

    if(fp == NULL)
    {
        *numcust = i;
        val = 1;
    }
    else
    {
        for(i = 0; (feof(fp) == 0 && check == 0); i++)
        {
            if(fscanf(fp, "%d\n", &temp) != 1)
            {
                check = 1;
                i--;
            }
            else
            {
                accarray[i].accountno = temp;
                fgets(accarray[i].name, 25, fp);
                fgets(accarray[i].address, 80, fp);
            }
        }

     fclose(fp);
     *numcust = i;
     val = 0;
     }

    return val;
}


/*************************************************************
 *
 * Function: writefile
 *
 * Description: writes/updates file with data from an array
 *
 * Parameters: accarrry(struct record) : array of records
 *             numcust (int): number of records
 *             filename(char) : file name
 *
 * Return values: 0 for success, 1 for error
 *
 **************************************************************/

int writefile(struct record accarray[], int numcust, char filename[])
{
    FILE * ofp;
    int i, val;

    ofp = fopen(filename, "w+");

    if(ofp == NULL)
    {
        val = 1;
    }
    else
    {
        for(i = 0; i < numcust; i++)
        {
            fprintf(ofp, "%d\n", accarray[i].accountno);
            fprintf(ofp, "%s", accarray[i].name);
            fprintf(ofp, "%s", accarray[i].address);
            fprintf(ofp, "\n");
        }

        fclose(ofp);
        numcust = i;
        val = 0;
    }

    return val;
}













