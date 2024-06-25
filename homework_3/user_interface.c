/*********************************************************************
 * 
 * Name: Sreelakshmi Kutty
 *
 * Course: ICS 212
 *
 * Instructor: Ravi Narayan
 *
 * Due date: 16 Feb 2020
 *
 * File: user_interface.c
 *
 * Description: calls database functions, gives user menu option for
 * 		functions, takes debug argument when executed
 * 		
 **********************************************************************/

#include <stdio.h>
#include <string.h>
#include "database.h"
#include "record.h"

/* prototypes */
void getaddress(char[], int); 
void  getaccountno(int *);
void getname(char[], int);

int debugmode = 0; /*turns on debug features*/

/**********************************************
 *
 * Function: main
 * 
 * Description: provides menu options to user
 *
 **********************************************/

int main (int argc, char * argv[])
{


    if((argc == 1) || (argc == 2 && strcmp(argv[1],"debug") == 0))
    {
        struct record * start =  NULL;
        char name[25], address[80];
        int * n, accountno, run = 1, option;
        n = &accountno;

        if(argc == 2 && strcmp(argv[1],"debug") == 0)
        {
            debugmode = 1;
        }

        while(run == 1)
        {
            printf("\n \n ~~ This is the Bank Databse ~~ \n To continue please select an option below by typing a number from 1-6. \n");
            printf("1. Add a new record in the database \n");
            printf("2. Print information about a record using the account # as a key \n");
            printf("3. Print all records in the databse \n");
            printf("4. Modify the address field of a record specified by account number \n");
            printf("5. Delete an existing record from the databse using the account # as a ke \n");
            printf("6. Quit the program \n \n");
            printf("Choosing option:  ");
             
            scanf("%d", &option); /* gets option from user*/
            getchar(); /*take out new line*/

            /* go through 6 options and return corresponding message/function */
            switch(option)
            {
                case 1: /*addRecord*/
                    printf("Enter new account number:  ");
                    getaccountno(n);
                    printf("Enter new name:  ");
                    getchar();
                    getname(name, 25);
                    printf("Enter new address (press $ to end address):   ");
                    getaddress(address, 80);
                    addRecord(&start, accountno, name, address);

                    if(debugmode == 1)
                    {
                        printf("\n Your account numer is: %d", accountno);
                        printf("\n Your name is: %s", name);
                        printf("\n Your address is: %s", address);
                    }
                    break;
                
                case 2: /*printRecord*/
                    printf("\n Enter the account number you wish to print:  ");
                    getaccountno(n);
                    getchar();
                    printRecord(start, accountno);

                    if(debugmode == 1)
                    {
                        printf("\n Printing account: %d", accountno);
                    }
                    break;                

                case 3: /*printAllRecords*/
                    printf("Printing all records");
                    printAllRecords(start);

                    if(debugmode == 1)
                    {
                        printf("\n Printing all records");
                    }
                    break;                

                case 4: /*modifyRecord*/
                    printf("\n Enter the the account number you wish to modify:  ");
                    getaccountno(n);
                    getchar();
                    printf("Please enter new address: ");
                    getaddress(address, 80);
                    modifyRecord(start, accountno, address);

                    if(debugmode == 1)
                    {
                        printf("\n Modifying account: %d", accountno);
                        printf("\n New address: %s", address);
                    }
                    break;

                case 5: /*deleteRecord*/
                    printf("\n Enter the account number you wish to delete:  ");
                    getaccountno(n);
                    getchar();
                    deleteRecord(&start, accountno);

                    if(debugmode == 1)
                    {
                        printf("\n Deleting record: %d", accountno);
                    }
                    break;

                case 6: /*exit program*/
                    printf("\nYou have exited this program.");
                    run = 0;
                    break;

                default: /*assume invalid option */
                    printf("You have not entered a valid option. Please enter a number from 1 through 6 \n");

            }

        }

    }
    else
    {
        printf("%s insufficient arguments \n", argv[0]);
    }


    return 0;
}

/**********************************************
 *
 * Function: getaddress
 *
 * Description: gets address from user with 79
 * 		max characters
 *
 * Parameters: address (char[])
 * 	       max (int)
 *
 * Return: void
 *
 **********************************************/ 

void getaddress(char address[], int max)
{
    int index = 0;
    char c[1]; /*gets characters from input*/
    c[0] = getchar();
    /* $ indicates end of address */

    while((c[0] != '$') && (index < max))
    {
        address[index] = c[0];
        c[0] = getchar();
        index++;
    }
    address[index] = '\0';
}


/**********************************************
 *
 * Function: getaccountno
 *
 * Description: gets account number (number
 * 		must be positive)
 *
 * Parameters: int * (accountno address)
 *
 * Return: void
 *
 **********************************************/

void getaccountno(int * n)
{
    int t = 0;
    while(t == 0)
    {
        scanf("%d", n);
        if(* n < 0)
        {
            printf("Account number must be positive. Please try again:  ");
        }
        else
        {
            t = 1;
        }
    }
}



/**********************************************
 *
 * Function: getname
 *
 * Description: gets name (cannot have any
 * 		non-letter characters, can have
 * 		spaces)
 *
 * Parameters: string, max characters
 *
 * Return: void
 *
 **********************************************/

void getname(char name[], int max)
{
    int index = 0;
    char hold[25];
    fgets(hold, max, stdin);
    while(index < max && hold[index] != '\n')
    {
        name[index] = hold[index];
        index++;
    }
    name[index] = '\0';
}
 





