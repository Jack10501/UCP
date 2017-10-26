/**
 * ErrorChecking.c
 * Author: Jack Paull
 * Purpose: Sanity checks user input
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ErrorChecking.h"

/**
 * commandLineCheck()
 * Checks the user entered a file to be checked
 * argc: The number of arguments taken from
 *       the command line
 *
 * returns: Pre defined constants TRUE or FALSE
 */
int commandLineCheck(int argc)
{
    int check;
    if(argc != 2)
    {
        check = FALSE;
    }
    else
    {
        check = TRUE;
    }
    return check;
}

/**
 * userInputCheck()
 * Checks the user only chooses either 1 or 2
 * word: The word to be checked
 * suggestion: A new recommendation for the misspelt word
 *
 * returns: Either 1 or 2 for the users choice
 */
int userInputCheck(char* word, char* suggestion)
{
    int choice;
    char arrayVal[MAXFILELENGTH];
    char* check;
    printf("Would you like to change %s to %s\n", word, suggestion);
    printf("1. Yes, 2. No\n");
    if(fgets(arrayVal, sizeof(arrayVal), stdin) != NULL)
    {
        choice = (int)strtol(arrayVal, &check, 10);
    }
    /*Checks if the user entered an int*/
    while(choice != 1 && choice != 2)
    {
        printf("Please enter a valid choice\n");
        if(fgets(arrayVal, sizeof(arrayVal), stdin) != NULL)
        {
            choice = (int)strtol(arrayVal, &check, 10);
        }
    }
    fflush(stdin);
    return choice;
}
