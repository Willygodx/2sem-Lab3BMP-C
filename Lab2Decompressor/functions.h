#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char** words;
    int size;
} Array;

Array* splitText(const char inputFileName[]);
void swapWords(Array* text, char* first, char* second);
Array* divideWords(char* text);
Array* divideString(const char inputNameFile[]);