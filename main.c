#include <stdio.h>
#include "main.h"

int main(int argc, char* argv[])
{
    if(commandLineCheck() != 0)
    {
        readFile(argv);
    }
    else
    {
        printf("Please enter a file name to check\n");
    }
    return 0;
}
