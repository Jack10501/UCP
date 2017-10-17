typedef struct
{
    char* dictFile;
    int  maxDifference;
    int autoCorrect;
} Spellconf

#ifndef MAXFILELENGTH
#define MAXFILELENGTH 255
#endif

#ifndef MAXWORDSIZE
#define MAXWORDSIZE 45
#endif

/*ASSUME dictFile max size is 255 as that is the max linux filesize
ASSUME MAX WORD SIZE IS 45 as it is the longest english word in the
oxford dictionary*/
