/**
 * FuncPointer.h
 * Author: Jack Paull
 * Purpose: Defines TRUE and FALSE
 */
#ifndef FUNCPOINTER_H
#define FUNCPOINTER_H

#ifndef CHECK_H
#include "check.h"
#endif

#ifndef ERRORCHECK_H
#include "ErrorChecking.h"
#endif

#define FALSE 0
#define TRUE !FALSE

int autoYes(char*, char*);
int autoNo(char*, char*);
ActionFunc actionChoice(int);
#endif
