#include <stdio.h>
#include "spellconf.h"

void readFile(char* argv)
{
    FILE *settings = fopen(argv[1], "r");
    Spellconf* spellConf = (Spellconf*)malloc(sizeof(MAXFILELENGTH));
    spellConf->dictFile = (char*)malloc(sizeof(MAXWORDSIZE));
    /*The max character size for dictfile, maxdifference & autocorrect
    is 13*/
    char checktype[14];
    char maxDif[2];
    char correct[6];

    if(!(settings = NULL))
    {
        do
        {
            /*USE gets to check which one it is, then skip to value and store*/
            /*Use fgets to avoid buffere overflow*/
            fgets(checktype, 14, settings);

            if(strcmp("dictfile", checktype) = 0)
            {
                fscanf(settings, "= %s", spellConf->dictFile);
            }
            else if(strcmp("maxdifference", checktype) = 0)
            {
                fscanf(settings, "= %s", maxDif)
                spellConf->maxdifference = atoi(maxDif);
            }
            else if(strcmp("autocorrect", checktype) = 0)
            {
                fscanf(settings, "= %s", correct);
                if(strcmp("false", correct == 0)
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
        } while(fgetc(settings) != NULL);
    }
    else
    {
        perror("Error Openning from Files");
    }
    fclose(settings);
}
