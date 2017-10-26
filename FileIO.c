/**
 * FileIO.c
 * Author: Jack Paull
 * Purpose: Provides all the IO for the program
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "FileIO.h"

/**
 * readFile()
 * Reads in and constructs the intial config file
 * spellConf: A pointer to a config struct
 *
 * returns: void
 */
void readFile(SpellConf* spellConf, int* errorCheck)
{
    FILE *settings = fopen(".spellconf", "r");
    char checktype[14]; /*CREATE CONSTANTS FOR THESE*/
    char maxDif[3];
    char correct[7];

    printf("\nSTARTED READFILE\n");

    /*Check if file exists*/
    if(settings != NULL)
    {
        *errorCheck = FALSE;
        /*while NOT end of file*/
        while(feof(settings) == 0)
        {
            /*Retrieves type for fgets to avoid a buffer overflow*/
            fscanf(settings, "%s", checktype);
            /*printf("%s\n", checktype);*/
            /*fflush(stdout);*/

            if(strcmp("dictfile", checktype) == 0)
            {
                fscanf(settings, " = %s\n", spellConf->dictFile);

            }
            else if(strcmp("maxdifference", checktype) == 0)
            {
                fscanf(settings, " = %s\n", maxDif);
                spellConf->maxDifference = atoi(maxDif);
            }
            else if(strcmp("autocorrect", checktype) == 0)
            {
                fscanf(settings, " = %s\n", correct);
                /*Changes string "true" or "false" to constants*/
                if(strcmp("no", correct) == 0)
                {
                    spellConf->autoCorrect = FALSE;
                }
                else if(strcmp("yes", correct) == 0)
                {
                    spellConf->autoCorrect = TRUE;
                }
                else
                {
                    spellConf->autoCorrect = -1;
                }

            }
            else
            {
                printf("INVALID/ MISSING FIELD\n");
                *errorCheck = TRUE;
            }
        }
        fclose(settings);
        printf("-READFILE COMPLETE ...\n");
    }
    else
    {
        perror("Error openning settings file");
        *errorCheck = TRUE;
    }
}

/**
 * readDict()
 * Reads in the dictionary file and stores it in a LinkedList
 * then stores it into an array
 * dictFile: File to be read in
 * list: LinkedList to store words in
 * wordArray: Array to store words in
 * arrayLength: Stores the length of the dictFile
 *
 * returns: void
 */
char** readDict(char* dictFile, int* arrayLength, int* errorCheck)
{
    LinkedList* list;
    FILE *file = fopen(dictFile, "r");
    /*Temp char* to store each word*/
    char* word;
    char** wordArray;
    char tempWord[MAXWORDSIZE];
    int ii;
    /*Traversal node*/
    LinkedListNode* node;
    /*Creates a new Linked List struct to use*/
    list = construct();

    printf("\nSTARTING READDICT\n");

    /*Check if file exists*/
    if(file != NULL)
    {
        *errorCheck = FALSE;
        /*While NOT end of file insert each word into the list*/
        while(feof(file) == 0)
        {
            word = (char*)malloc(MAXWORDSIZE * sizeof(char));
            fscanf(file, "%s\n", tempWord);
            strncpy(word, tempWord, MAXWORDSIZE);
            insertFirst(list, word);
        }
        /*Store the length for later use*/
        *arrayLength = list ->size;
        /*Allocates memory*/
        wordArray = (char**)malloc(*arrayLength * sizeof(char*));
        for(ii = 0; ii < *arrayLength; ii++)
        {
            wordArray[ii] = (char*)malloc(MAXWORDSIZE * sizeof(char));
        }
        /*Starts at the tail to attempt to preserve formatting*/
        node = list->tail;
        for(ii = 0; ii< *arrayLength; ii++)
        {
            strncpy(wordArray[ii], (char*)(node->data), MAXWORDSIZE);
            node = node->prev;
            removeLast(list);

        }
        fclose(file);
        freeLinkedList(list);
        list = NULL;
        printf("-READDICTIONARY COMPLETE ...\n");

    }
    else
    {
        perror("Error openning dictionary file");
        *errorCheck = TRUE;
        freeLinkedList(list);
    }
    return wordArray;
}

/**
 * readUser()
 * Reads in the user file and stores it in a LinkedList
 * then stores it into an array
 * userFile: File to be read in
 * list: LinkedList to store words in
 * wordArray: Array to store words in
 * arrayLength: Stores the length of the userFile
 *
 * returns: void
 */
char** readUser(char* userFile, int* arrayLength, int* errorCheck)
{
    LinkedList* list;
    FILE *file = fopen(userFile, "r");
    /*Temp char* to store each word*/
    char* word;
    char** wordArray;
    char tempWord[MAXWORDSIZE];
    int ii;
    /*Traversal node*/
    LinkedListNode* node;
    /*Creates a new Linked List struct to use*/
    list = construct();

    printf("\nSTARTING READUSER\n");

    /*Check if file exists*/
    if(file != NULL)
    {
        *errorCheck = FALSE;
        /*While NOT end of file insert each word into the list*/
        while(feof(file) == 0)
        {
            word = (char*)malloc(MAXWORDSIZE * sizeof(char));
            fscanf(file, "%s\n", tempWord);
            strncpy(word, tempWord, MAXWORDSIZE);
            insertFirst(list, word);
        }
        /*Store the length for later use*/
        *arrayLength = list ->size;
        /*Allocates memory*/
        wordArray = (char**)malloc(*arrayLength * sizeof(char*));
        for(ii =0; ii < *arrayLength; ii++)
        {
            wordArray[ii] = (char*)malloc(MAXWORDSIZE * sizeof(char));
        }
        /*Starts at the tail to attempt to preserve formatting*/
        node = list->tail;
        for(ii =0; ii< *arrayLength; ii++)
        {
            /*Copying so free the list won't break the array*/
            strncpy(wordArray[ii], (char*)(node->data), MAXWORDSIZE);
            node = node->prev;
            removeLast(list);
        }
        fclose(file);
        freeLinkedList(list);
        list = NULL;
        printf("-READUSER COMPLETE ...\n");

    }
    else
    {
        perror("Error openning userFile file");
        *errorCheck = TRUE;
        freeLinkedList(list);

    }
    return wordArray;

}

/**
 * writeFile()
 * Writes of the corrects contents of the user array
 * to a file
 * array: Array of corrected words to be written
 * userFile: The file to be written to
 * arrayLength: Length of array
 *
 * returns: void
 */
void writeFile(char** array, char* userFile, int* arrayLength)
{
    int ii;
    FILE* f1 = fopen(userFile, "w");

    if(f1 != NULL)
    {
        for(ii =0; ii < *arrayLength; ii++)
        {
            fprintf(f1, "%s\n", array[ii]);
        }

        fclose(f1);
        printf("\nFinished WRITING TO FILE ...\n");
    }
    else
    {
        perror("Error openning outputFile");
        fclose(f1);
    }
}
