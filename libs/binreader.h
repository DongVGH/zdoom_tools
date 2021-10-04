//#include <stdio.h>
//#include <stdlib.h>
#define BR_BUFFERSIZE 256
unsigned char br_buffer[BR_BUFFERSIZE];
int br_offset;
//FILE *br_file;

enum
{
    TYPE_INT,
    TYPE_SHORT,
    TYPE_BYTE,
    TYPE_STR
};

int reader_GetFilesize (FILE *br_file)
{
    fseek(br_file, 0L, SEEK_END);
    return ftell(br_file);
}

void reader_ClearBuffer ()
{
    for(int i = 0; i < BR_BUFFERSIZE; i++)
    {
        br_buffer[i] = 0;
    }
}

void reader_JumpTo (int offset) {br_offset = offset;}
void reader_SkipAhead (int offset) {br_offset += offset;}

#define READER_SEEKTO fseek(br_file, br_offset, SEEK_SET);

long reader_ReadLong (FILE *br_file)
{
    READER_SEEKTO;

    long ret;
    if(fread(&ret, sizeof(long), 1, br_file) != 1)
        assert(0);

    br_offset += sizeof(long);
    return ret;
}

double reader_ReadDouble (FILE *br_file)
{
    READER_SEEKTO;

    double ret;
    if(fread(&ret, sizeof(double), 1, br_file) != 1)
        assert(0);

    br_offset += sizeof(double);
    return ret;
}

float reader_ReadFloat (FILE *br_file)
{
    READER_SEEKTO;

    float ret;
    if(fread(&ret, sizeof(float), 1, br_file) != 1)
        assert(0);

    br_offset += sizeof(float);
    return ret;
}

int reader_ReadInt (FILE *br_file)
{
    READER_SEEKTO;

    int ret;
    if(fread(&ret, sizeof(int), 1, br_file) != 1)
        assert(0);

    br_offset += sizeof(int);
    return ret;
}

short reader_ReadShort (FILE *br_file)
{
    READER_SEEKTO;

    short ret;

    if(fread(&ret, sizeof(short), 1, br_file) != 1)
        assert(0);

    br_offset += sizeof(short);
    return ret;
}

char reader_ReadByte (FILE *br_file)
{
    READER_SEEKTO;

    char ret;
    fread(&ret, 1, 1, br_file);
    br_offset++;
    return ret;
}

short swap_Short(unsigned short us)
{
    return us = (us >> 8) |
                (us << 8);
}

int swap_Int(unsigned int ui)
{
    return ui = (ui >> 24) |
         ((ui<<8) & 0x00FF0000) |
         ((ui>>8) & 0x0000FF00) |
         (ui << 24);
}
