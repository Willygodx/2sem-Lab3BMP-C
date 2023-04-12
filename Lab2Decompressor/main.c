#include "functions.h"

int main()
{
    Array * compressedData = splitText("/Users/willygodx/CLionProjects/pratcie/cmake-build-debug/compressedData.txt");
    if(compressedData == NULL)
        exit(0);
    FILE* f = fopen("/Users/willygodx/CLionProjects/pratcie/cmake-build-debug/compressedData.txt", "r");
    if (f == NULL)
        exit(0);
    fseek(f, 0, SEEK_END);
    Array* replacedWords = divideString("/Users/willygodx/CLionProjects/pratcie/cmake-build-debug/wordsReplace.txt");
    if(replacedWords == NULL)
        exit(0);
    fclose(f);
    f = fopen("/Users/willygodx/CLionProjects/pratcie/cmake-build-debug/wordsReplace.txt", "r");
    if (f == NULL)
        exit(0);
    fseek(f, 0, SEEK_END);
    for (int i = 0; i < replacedWords->size; ++i)
    {
        Array* clearWord = divideWords(replacedWords->words[i]);
        if(clearWord->size != 2)
        {
            free(clearWord);
            continue;
        }
        swapWords(compressedData, clearWord->words[0], clearWord->words[1]);
        free(clearWord);
    }
    free(replacedWords);
    fclose(f);
    f = fopen("dataDecompressed.txt", "a");
    if(f == NULL)
        exit(0);
    for (int i = 0; i < compressedData->size; ++i)
    {
        fputs(compressedData->words[i], f);
        if(i != compressedData->size - 1)
            fputs(" ", f);
    }
    free(compressedData);
    fseek(f, 0, SEEK_END);
    fclose(f);
    return 0;
}