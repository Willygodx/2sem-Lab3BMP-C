#include "functions.h"

Array* splitText(const char inputFileName[])
{
    FILE* pFile = fopen(inputFileName, "r");
    if (pFile == NULL)
        exit(0);
    fseek(pFile, 0, SEEK_END);
    long size = ftell(pFile);
    fseek(pFile, 0, SEEK_SET);

    if(pFile == NULL)
    {
        printf("Can't open the file.\n");
        return 0;
    }
    Array* array = malloc(sizeof(array));
    array->size = 0;
    array->words = NULL;

    char* text = malloc(size);
    char* save;
    fread(text, 1, size, pFile);
    fclose(pFile);
    char* token = strtok_r(text, " ", &save);
    while(token != NULL)
    {
        array->words = realloc(array->words, (array->size + 1) * sizeof(char*));
        array->words[array->size++] = token;
        token = strtok_r(NULL, " ", &save);
    }
    free(text);
    return array;
}

void swapWords(Array* text, char* first, char* second)
{
    for (int i = 0; i < text->size; ++i)
    {
        if(strcmp(text->words[i], first) == 0)
            text->words[i] = second;
        else if(strcmp(text->words[i], second) == 0)
            text->words[i] = first;
    }
}

Array* divideWords(char* text)
{
    Array* array = malloc(sizeof(Array));
    array->size = 0;
    array->words = NULL;
    char* save;
    char* word = strtok_r(text, " ", &save);
    while(word != NULL)
    {
        array->words = realloc(array->words, (array->size + 1) * sizeof(char*));
        array->words[array->size++] = word;
        word = strtok_r(NULL, " ", &save);
    }
    return array;
}

Array* divideString(const char inputNameFile[])
{
    FILE* pFile = fopen(inputNameFile, "r");
    if(pFile == NULL)
    {
        printf("Can't open the file.\n");
        return 0;
    }
    Array* array = malloc(sizeof(Array));
    array->size = 0;
    array->words = NULL;
    fseek(pFile, 0, SEEK_END);
    long length = ftell(pFile);
    fseek(pFile, 0, SEEK_SET);
    char* text = calloc(length, 1);
    char* save;
    fread(text, 1, length, pFile);
    fclose(pFile);
    char* string = strtok_r(text, "\n", &save);
    while(string != NULL)
    {
        array->words = realloc(array->words, (array->size + 1) * sizeof(char*));
        array->words[array->size++] = string;
        string = strtok_r(NULL, "\n", &save);
    }
    free(text);
    return array;
}