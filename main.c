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
    SpellConf* spellConf = (SpellConf*)malloc(sizeof(MAXFILELENGTH));
    LinkedList* list;
    /*Arrays to store the dictionary and user file*/
    char** dictWordArray = NULL;
    char** userWordArray = NULL;
    ActionFunc actionFunc;
    int wordArrayLength;
    int dictWordArrayLength;
    spellConf->dictFile = (char*)malloc(sizeof(MAXFILELENGTH));

    /*Creates a new Linked List struct to use*/
    list = construct();

    /*Checks if the user entered a file to be checked*/
    if(commandLineCheck(argc) != 0)
    {
        /*Reads in the config file*/
        readFile(spellConf);
        /*Reads in the dictionary specified by the user*/
        readDict(spellConf->dictFile, list, dictWordArray, &dictWordArrayLength);
        /*Reads in the user file to be checked*/
        readUser(argv[1], list, userWordArray, &wordArrayLength);
        /*Sets up the call back function*/
        actionFunc = actionChoice(spellConf->autoCorrect);
        /*Compares the users words and the dictionary words*/
        check(userWordArray, wordArrayLength, dictWordArray, dictWordArrayLength,
              spellConf->maxDifference, actionFunc);
        /*Write the result back to the user intial file*/
        writeFile(userWordArray, argv[1], &wordArrayLength);

        /*FREE MEMORY*/
    }
    else
    {
        printf("Please enter a file name to check\n");
    }
    return 0;
}
