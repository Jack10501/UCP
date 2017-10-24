/**
 * SpellConf.h
 * Author: Jack Paull
 * Purpose: The config struct
 */
#ifndef SPELLCONF_H
#define SPELLCONF_H

 /*Struct to store config settings*/
typedef struct
{
    char* dictFile;
    int  maxDifference;
    int autoCorrect;
} SpellConf;

/*Based off the max file length in Linux OS: Ubuntu*/
#ifndef MAXFILELENGTH
#define MAXFILELENGTH 256
#endif

/*Based off the largest word in the Oxford dictionary*/
#ifndef MAXWORDSIZE
#define MAXWORDSIZE 46
#endif

#endif
