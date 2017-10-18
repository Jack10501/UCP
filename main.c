#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/*TAKING IN THE FILE TO CHECK FROM COMMAND LINE*/
int main(int argc, char* argv[])
{
    SpellConf* spellConf = (SpellConf*)malloc(sizeof(MAXFILELENGTH));
    spellConf->dictFile = (char*)malloc(sizeof(MAXWORDSIZE));
    LinkedList* list = construct();

    if(commandLineCheck(argc) != 0)
    {
        readFile(spellConf);
        readDict(spellConf->dictFile, list);

    }
    else
    {
        printf("Please enter a file name to check\n");
    }
    return 0;
}
