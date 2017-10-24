/**
 * FileIO.h
 * Author: Jack Paull
 * Purpose: Defines TRUE and FALSE 
 */
#ifndef FILEIO_H
#define FILEIO_H

#define FALSE 0
#define TRUE !FALSE

#ifndef SPELLCONF_H
#include "SpellConf.h"
#endif

#ifndef LINKEDLIST_H
#include "LinkedList.h"
#endif

void readFile(SpellConf*);
void readDict(char*, LinkedList*, char**, int*);
void readUser(char*, LinkedList*, char**, int*);
void writeFile(char**, char*, int*);
#endif
