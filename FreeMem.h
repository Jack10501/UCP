/**
 * FreeMem.h
 * Author: Jack Paull
 * Purpose: Frees the memory through
            the program
 */
#ifndef FREEMEM_H
#define FREEMEM_H

#ifndef SPELLCONF_H
#include "SpellConf.h"
#endif

void freeSpellConf(SpellConf*);
void freeDictArray(char**, int);
void freeUserArray(char**, int);


#endif
