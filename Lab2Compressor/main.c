#include "functions.h"

int main()
{
    char input[10] = "data2.txt";
    Array* text = splitText(input);
    if(text == NULL)
        exit(1);
    FILE* pFile = fopen(input, "r");
    if (pFile == NULL)
        exit(0);
    Stack* top = NULL;
    createStack(&top, text);
    replaceWords(top, text);
    free(top);
    fclose(pFile);
    pFile = fopen("compressedData.txt", "a");
    if(pFile == NULL)
        exit(0);
    for (int i = 0; i < text->size; ++i)
    {
        fputs(text->words[i], pFile);
        if(i != text->size - 1)
            fputs(" ", pFile);
    }
    fclose(pFile);
    pFile = fopen("wordsReplace.txt", "r");
    if (pFile == NULL)
        exit(0);
    fclose(pFile);
    free(text->words);
    free(text);
    return 0;
}