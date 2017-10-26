/**
 * ErrorChecking.h
 * Author: Jack Paull
 * Purpose: Defines TRUE and FALSE
 */
#ifndef ERRORCHECK_H
#define ERRORCHECK_H

#define FALSE 0
#define TRUE !FALSE

/*Based off the max file length in Linux OS: Ubuntu*/
#ifndef MAXFILELENGTH
#define MAXFILELENGTH 256
#endif


int commandLineCheck(int);
int userInputCheck(char*, char*);
#endif
