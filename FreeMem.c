/**
 * FreeMem.c
 * Author: Jack Paull
 * Purpose: Used to free the alloc'd memory
 */

#include <stdio.h>
#include <stdlib.h>
#include "FreeMem.h"

/**
 * freeSpellConf()
 * Frees the SpellConf struct
 * SpellConf: The struct to be freed
 *
 * returns: void
 */
void freeSpellConf(SpellConf* spellConf)
{
    free(spellConf->dictFile);
    spellConf->dictFile = NULL;
    free(spellConf);
    spellConf = NULL;
}

/**
 * freeDictArray()
 * Frees the array of dictionary words
 * dictWordArray: The array to be freed
 * dictWordArrayLength: The length of the array
 *
 * returns: void
 */
void freeDictArray(char** dictWordArray, int dictWordArrayLength)
{
    int ii;
    /*Free each iteration in the array*/
    for(ii = 0; ii < dictWordArrayLength; ii++)
    {
        free(dictWordArray[ii]);
        dictWordArray[ii] = NULL;
    }
    free(dictWordArray);
    dictWordArray = NULL;
}

/**
 * freeUserArray()
 * Frees the array of user words
 * userWordArray: The array to be freed
 * wordArrayLength: The length of the array
 *
 * returns: void
 */
void freeUserArray(char** userWordArray, int wordArrayLength)
{
    int ii;
    /*Free each iteration in the array*/
    for(ii = 0; ii < wordArrayLength; ii++)
    {
        free(userWordArray[ii]);
        userWordArray[ii] = NULL;
    }
    free(userWordArray);
    userWordArray = NULL;
}
