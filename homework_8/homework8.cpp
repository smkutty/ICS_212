/**********************************************
 * NAME: Sreelakshmi Kutty
 *
 * COURSE: ICS 212
 *
 * INSTRUCTOR: Ravi Narayan
 *
 * DUE DATE: 4 April 2020
 *
 * FILE: homework8.cpp
 *
 * DESCRIPTION: homework 1 redo in C++
 **********************************************/

#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <math.h>
using namespace std;

/**Protoypes**/
int user_interface();
void convert(double, double &);
void print_table(int);

/*****************************************
 * Function: main
 *
 * Description: runs the user_input
 *              and print_table
 *
 * Parameters: none
 *
 * Return values: 0
 *****************************************/

int main()
{
    int max;
    max = user_interface();
    print_table(max);
    return 0;
}

/******************************************
 * Function: user_interface
 *
 * Description: takes an integer and sends
 *              back the same integer and
 *              ad description
 *
 * Parameters: none
 *
 * Return: given number
 ******************************************/

int user_interface()
{
    int num, result, t;
    t = 0;

    cout << "\n *******This program converts inches to centimeters.******** \n";
    cout << "Please enter maximum integers to show: ";

    cin >> num;

    while(t == 0)
    {
        if(num <= 0)
        {
            cout << "Must be a positive integer: ";
            cin >> num;
        }
        else
        {
            result = num;
            t = 1;
        }
    }

    return result;
}

/******************************************
 * Function: convert
 *
 * Description: takes value of inches and
 *              gives conversion into cm
 *
 * Parameter: in (double) : num to convert
 *            cent (double &) : pointer cm
 *
 * Return: val (double) : converted num
 ******************************************/

void convert(double inches, double & cent)
{
    cent = inches * 2.54;   
}

/******************************************
 * Function: print_table
 *
 * Description: prints list of ics to cm
 *              starting from 0 to given
 *              num at 0.5 intervals
 *
 * Paratmers: num (int) : max to convert
 *
 * Return: none
 ******************************************/

void print_table(int num)
{
    int c;
    double i, cm;
    i = 0.00;
    cout << "inch          cm \n";
    for(c = 0; c <= num * 2; c++)
    {
        convert(i, cm);
        cout << setprecision(2) << fixed << setw(4) << i << setw(12) << cm << "\n";
        i += 0.5;
    }
}










