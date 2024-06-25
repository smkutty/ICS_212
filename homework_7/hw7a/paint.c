/******************************************************
 * NAME: Sreelakshmi Kutty
 *
 * COURSE: ICS 212
 *
 * INSTRUCTOR: Ravi Narayan
 *
 * DUE DATE: 21 March 2020
 *
 * FILE: paint.c
 *
 * DESCRIPTION: provides code for costofpainting function
 *
 ******************************************************/

#include <stdio.h>
#include "paint.h"


double costofpainting(double length)
{
    double cost;
    cost = 0.0;

    if(length <= 0)
    {
        cost += 0;
    }
    else if(length > 0 && length <= 3)
    {
        cost += length * 300;
    }
    else if(length > 3)
    {
        cost += 50;
        length -= 3;
        cost += 900;
        cost += costofpainting(length * 0.7) + costofpainting(length * 0.3);
    }

    return cost;


}



