#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "binreader.h"

FILE *input;
FILE *output;

int main(int argc, char *argv[])
{
    if( (argc < 2) || (argc > 3) )
    {
        printf("Incorrect amount of parameters!\n");
        printf("Usage: %s filename [base sprite name]", argv[0]);
        return 0;
    }

    char spritename[4] = "MDL";
    if(argc == 3)
    {
        if(strlen(argv[2]) == 3)
            strcpy(spritename, argv[2]);
        else
            printf("Base sprite name must be 3 characters long!");
    }

    input = fopen(argv[1], "rb");

    reader_JumpTo(104);
    int size = reader_ReadInt(input);

    if(size != reader_GetFilesize(input))
    {
        printf("ERROR: Corrupted MD3 file!");
        return 0;
    }

    reader_JumpTo(76);
    int frames = reader_ReadInt(input);

    if(frames <= 0)
    {
        printf("ERROR: No frames in MD3!");
        return 0;
    }

    short spritenum = 0;
    char frameletter = 'A';

    char *outfilename = malloc(strlen(argv[1] + 5));
    strcpy(outfilename, argv[1]);
    strcat(outfilename, ".txt");

    output = fopen(outfilename, "w+");

    for(int i = 0; i < frames; i++)
    {
        fprintf(output, "   FrameIndex %s%i %c 0 %i\n", spritename, spritenum, frameletter, i);

        if(frameletter >= 'Z')
        {
            frameletter = 'A';
            spritenum++;
        }
        else
        {
            frameletter++;
        }
    }

    return 0;
}
