/********************************************
 * NAME: Sreelakshmi Kutty
 *
 * COURSE: ICS 212
 *
 * INSTRUCTOR: Ravi Narayan
 *
 * DUE DATE: 21 March 2020
 *
 * FILE: driver.c
 *
 * DESCRIPTION: driver code for costofpainting
 **********************************************/

#include <stdio.h>
#include "paint.h"

int main(void)
{

    double result;
    result = 0.0;

    /*HARDCODING TEST BEGIN*/
    result = costofpainting(0.0);
    printf("\n Test 1: 0 miles");
    printf("\n Expected: $0.0");
    printf("\n Printing: $%.2f \n", result);

    result = costofpainting(1.0);
    printf("\n Test 2: 1 mile");
    printf("\n Expected: $300.00");
    printf("\n Printing: $%.2f \n", result);

    result = costofpainting(3.0);
    printf("\n Test 3: 3 miles");
    printf("\n Expected: $900.00");
    printf("\n Printing $%.2f \n", result);

    result = costofpainting(4.0);
    printf("\n Test 4: 4 miles");
    printf("\n Expected: $1250.00");
    printf("\n Prinitng: $%.2f \n", result);

    result = costofpainting(13.0);
    printf("\n Test 5: 13 miles");
    printf("\n Expected: $4000.00");
    printf("\n Printing: $%.2f \n", result);

    result = costofpainting(-1.0);
    printf("\n Test 6: -1 miles");
    printf("\n Expected: $0.00");
    printf("\n Printing: $%.2f \n", result);

    /*HARDCODING TEST END*/

    return 0;

}
