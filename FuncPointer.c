/**
 * FuncPointer.c
 * Author: Jack Paull
 * Purpose: Sets the action function pointer
 */
#include <stdio.h>
#include "FuncPointer.h"

/**
 * autoYes()
 * Returns true for values to be autoCorrected
 * word: Word to be corrected
 * suggestion: Replaces word with autoCorrect
 *
 * returns predefined TRUE
 */
int autoYes(char* word, char* suggestion)
{
    return TRUE;
}

/**
 * autoNo()
 * checks if the user wishes to correct the selected word
 * word: Word to be corrected
 * suggestion: Word to replace
 *
 * returns TRUE or FALSE depending on user input
 */
int autoNo(char* word, char* suggestion)
{
    int check;
    int choice;

    /*Retrieves user input from another file*/
    choice = userInputCheck(word, suggestion);
    if(choice == TRUE)
    {
        check = TRUE;
    }
    else
    {
        check = FALSE;
    }

    return check;
}

/**
 * actionChoice()
 * Selects wether the fucntion points towards autoOn or
 * autoOff
 * Sets up the callback fucntion
 * autoCorrect: The value from the config file
 *
 * returns wether the user wishes to use
 * autoCorrect or not
 */
ActionFunc actionChoice(int autoCorrect)
{
    ActionFunc action;
    if(autoCorrect == TRUE)
    {
        action = &autoYes;
    }
    else
    {
        action = &autoNo;
    }

    return action;
}
