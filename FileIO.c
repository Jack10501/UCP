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
void readFile(SpellConf* spellConf)
{
    FILE *settings = fopen(".spellconf", "r");
    char checktype[14]; /*CREATE CONSTANTS FOR THESE*/
    char maxDif[3];
    char correct[7];

    /*Check if file exists*/
    if(settings != NULL)
    {
        /*while NOT end of file*/
        while(feof(settings) == 0)
        {
            /*Retrieves type for fgets to avoid a buffer overflow*/
            fscanf(settings, "%s", checktype);
            printf("%s\n", checktype);

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
                if(strcmp("false", correct) == 0)
                {
                    spellConf->autoCorrect = FALSE;
                }
                else
                {
                    spellConf->autoCorrect = TRUE;
                }
            }
            else
            {
                printf("INVALID/ MISSING FIELD\n");
            }
        }
        fclose(settings);
    }
    else
    {
        perror("Error openning settings file");
    }
    fclose(settings);
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
void readDict(char* dictFile, LinkedList* list, char** wordArray, int* arrayLength)
{
    FILE *file = fopen(dictFile, "r");
    /*Temp char* to store each word*/
    char* word = (char*)malloc(sizeof(char));
    int ii;
    /*Traversal node*/
    LinkedListNode* node;

    /*Check if file exists*/
    if(file != NULL)
    {
        /*While NOT end of file insert each word into the list*/
        while(feof(file) == 0)
        {
            fscanf(file, "%s\n", word);
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
            wordArray[ii] = (char*)(node->data);
            node = node->prev;
            removeLast(list);
        }
        fclose(file);
    }
    else
    {
        perror("Error openning dictionary file");
    }
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
void readUser(char* userFile, LinkedList* list, char** wordArray, int* arrayLength)
{
    FILE *file = fopen(userFile, "r");
    /*Temp char* to store each word*/
    char* word = (char*)malloc(sizeof(char));
    int ii;
    /*Traversal node*/
    LinkedListNode* node;

    /*Check if file exists*/
    if(file != NULL)
    {
        /*While NOT end of file insert each word into the list*/
        while(feof(file) !=EOF)
        {
            fscanf(file, "%s", word);
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
            wordArray[ii] = (char*)(node->data);
            node = node->prev;
            removeLast(list);
        }
        fclose(file);
    }
    else
    {
        perror("Error openning dictionary file");
    }
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
    }
    else
    {
        perror("Error openning outputFile");
    }
}
