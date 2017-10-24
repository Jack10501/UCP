/**
 * ErrorChecking.c
 * Author: Jack Paull
 * Purpose: Sanity checks user input
 */
#include <stdio.h>
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
    if(argc < 2)
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
    printf("Would you like to change %s to %s\n", word, suggestion);
    printf("1. Yes, 2. No\n");
    scanf("%d\n", &choice);
    while(choice != 1 && choice != 0)
    {
        printf("Please enter a valid choice\n");
        scanf("%d\n", &choice);
    }
    return choice;
}
