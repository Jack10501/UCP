#include <stdio.h>

void readFile(char* argv)
{
    FILE *settings = fopen("spellconf", "r");

    if(!(ferror(settings)))
    {
        
    }
    else
    {
        perror("Error Openning from Files");
    }



    fclose(settings);
}
