/***********************************************
 * NAME: Sreelakshmi Kutty
 *
 * COURSE: ICS 212
 *
 * INSTRUCTOR: Ravi Narayan
 *
 * DUE DATE: 31 March 2020
 *
 * FILE: functions.c
 *
 * DESCRIPTION: contains function implementation
 ************************************************/

#include <stdio.h>
#include "functions.h"

/*************************************
 * Function: printinfo
 *
 * Parameters: array of hex values
 *
 * Return: void
 *
 * Description: prints out required information
 *************************************/

void printinfor(unsigned char myList[])
{
    int height, width;
    width = (myList[7] << 8) | (myList[6]);
    height = (myList[9] << 8) | (myList[8]);

    printf("Width: %d \n", width);

    printf("Height: %d \n", height);

    printf("\n Color 1 *************** \n");
    printf("R: %x \n", myList[13]);
    printf("G: %x \n", myList[14]);
    printf("B: %x \n", myList[15]);

    printf("\n Color 2 *************** \n");
    printf("R: %x \n", myList[16]);
    printf("G: %x \n", myList[17]);
    printf("B: %x \n", myList[18]);

    printf("\n Color 3 *************** \n");
    printf("R: %x \n", myList[19]);
    printf("G: %x \n", myList[20]);
    printf("B: %x \n", myList[21]);

    printf("\n Color 4 *************** \n");
    printf("R: %x \n", myList[22]);
    printf("G: %x \n", myList[23]);
    printf("B: %x \n", myList[24]);  
}

/**************************************
 * Function: modify
 *
 * Parameters: array of hex values
 *
 * Return: void
 *
 * Description: modify the color palette
 **************************************/

void modify(unsigned char myList[])
{
    int i, num, a, b, c;
    num = 128;

    for(i = 13; i < 25; i += 3)
    {
        if(((myList[i] & num) == num) && ((myList[i+1] & num) == num) && ((myList[i+2] & num) == num))
        {
            /*multiply each RGB value by 4*/
            myList[i] = myList[i] << 2;
            myList[i+1] = myList[i+1] << 2;
            myList[i+2] = myList[i+2] << 2;
        }
        else
        {
            /*R clear lowest 1st and 6th bits*/
            myList[i] = myList[i] & 222;
           
            /*G swap higher 4 bits and lower 4 bits*/
            a = myList[i+1] & 240;
            b = myList[i+1] & 15;
            a = a >> 4;
            b = b << 4;
            myList[i+1] = a | b;
           
            /*B flip 1st and 5th highest bits*/
            a = myList[i+2] & 128;
            b = myList[i+2] & 8;
            c = myList[i+2] & 119;
            a = a >> 4;
            b = b << 4;
            c = c | a;
            myList[i+2] = c | b;
        }
    }

}

/**************************************
 * Function: readfile
 * 
 * Parameters: array of hex values
 *             integer pointer
 *             file to be read
 *
 * Return: 0 for success
 *
 * Description: reads a gif file and stores
 *              data into an array
 **************************************/

int readfile(unsigned char myList[], int * numpoint, char filename[])
{
    FILE * thing;
    int size, result;

    size = * numpoint;
    thing = fopen(filename, "r");
    if(thing != NULL)
    {
        fread(myList, size, 4000, thing);
        fclose(thing);
        result = 0;
    }
    else
    {
        result = -1;
    }

    return result;
}

/**************************************
 * Function: writefile
 *
 * Parameters: array of hex values
 *             integer
 *             file to write
 *
 * Return: 0 for success
 *
 * Description: writes image data from
 *              an array int a file
 **************************************/

int writefile(unsigned char myList[], int num, char filename[])
{
    FILE * thing;
    int result;

    thing = fopen(filename, "w");
    if (thing == 0)
    {
        result = -1;
    }
    else
    {
        result = 0;
        fwrite(myList, num, 4000, thing);
        fclose(thing);
    }

    return result;
}








