#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "FileIO.h"
void readFile(SpellConf* spellConf)
{
    FILE *settings = fopen("spellconf", "r");
    /*The max character size for dictfile, maxdifference & autocorrect
    is 13*/
    char checktype[14];
    char maxDif[2];
    char correct[6];

    if(!(settings = NULL))
    {
        while(feof(settings) == 0)
        {
            /*USE gets to check which one it is, then skip to value and store*/
            /*Use fgets to avoid buffere overflow*/
            fgets(checktype, 14, settings);

            if(strcmp("dictfile", checktype) == 0)
            {
                fscanf(settings, "= %s\n", spellConf->dictFile);
            }
            else if(strcmp("maxdifference", checktype) == 0)
            {
                fscanf(settings, "= %s\n", maxDif);
                spellConf->maxDifference = atoi(maxDif);
            }
            else if(strcmp("autocorrect", checktype) == 0)
            {
                fscanf(settings, "= %s\n", correct);
                if(strcmp("false", correct) == 0)
                {
                    spellConf->autoCorrect = 0;
                }
                else
                {
                    spellConf->autoCorrect = 1;
                }
            }
            else
            {
                /*INVALID ARGUMENT THROW ERROR*/
            }
        }
    }
    else
    {
        perror("Error Openning from Files");
    }
    fclose(settings);
}

void readDict(SpellConf* spellConf)
{

}
