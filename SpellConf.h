/**
 * SpellConf.h
 * Author: Jack Paull
 * Purpose: The config struct
 */
#ifndef SPELLCONF_H
#define SPELLCONF_H

 /*Struct to store config settings
  Stores the reference to the dictionary file, the max difference
  allowed between words and if autoCorrect is turned on or not.
  Used by the readFile and readDict to setup for check*/
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
