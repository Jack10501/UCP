 /**
 * main.c
 * Author: Jack Paull
 * Purpose: Steps through the program
 */
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/*main() begins the program and runs through each section of it,
  taking in a file to check from the command line*/
int main(int argc, char* argv[])
{
    /*Constructs a spellConf struct to store file config information*/
    SpellConf* spellConf = (SpellConf*)malloc(sizeof(SpellConf));
    /*Arrays to store the dictionary and user file*/
    char** dictWordArray;
    char** userWordArray;
    ActionFunc actionFunc;
    int wordArrayLength, errorCheck;
    int dictWordArrayLength;
    spellConf->dictFile = (char*)malloc(MAXFILELENGTH * sizeof(char));

    /*Checks if the user entered a file to be checked*/
    if(commandLineCheck(argc) != 0)
    {
        /*Reads in the config file*/
        readFile(spellConf, &errorCheck);
        if(errorCheck == FALSE)
        {
            /*Reads in the dictionary specified by the user*/
            dictWordArray = readDict(spellConf->dictFile, &dictWordArrayLength,
                                    &errorCheck);
            if(errorCheck == FALSE)
            {
                /*Reads in the user file to be checked*/
                userWordArray = readUser(argv[1], &wordArrayLength,
                                        &errorCheck);
                if(errorCheck == FALSE)
                {
                    /*Sets up the call back function*/
                    actionFunc = actionChoice(spellConf->autoCorrect);
                    printf("\n");
                    /*Compares the users words and the dictionary words*/
                    check(userWordArray, wordArrayLength, dictWordArray,
                        dictWordArrayLength,
                        spellConf->maxDifference, actionFunc);
                    /*Write the result back to the user intial file*/
                    writeFile(userWordArray, argv[1], &wordArrayLength);
                    /*FREE MEMORY*/
                    freeDictArray(dictWordArray, dictWordArrayLength);
                    freeUserArray(userWordArray, wordArrayLength);
                }
                else
                {
                    printf("EXITING PROGRAM AS AN ERROR HAS OCCURED IN "
                            "USERFILE\n");

                    freeDictArray(dictWordArray, dictWordArrayLength);
                }
            }
            else
            {
                printf("EXITING PROGRAM AS AN ERROR HAS OCCURED IN "
                        "DICTFILE\n");
            }
        }
        else
        {
            printf("EXITING PROGRAM AS AN ERROR HAS OCCURED "
                    " SPELLCONF\n");
        }
    }
    else
    {
        printf("Please enter a file name to check\n");
    }
    freeSpellConf(spellConf);

    return 0;
}
