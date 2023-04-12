#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char* word;
    int frequency;
    int flag;
    int size;
    struct Stack* next;
} Stack;

typedef struct
{
    char** words;
    int size;
} Array;

Stack* getTop(Stack* top);
void divideStackForMerge(Stack* top, Stack** first, Stack** last);
void merge(Stack *first, Stack *second, Stack **third);
void mergeSort(Stack** top);
void setFlag(Stack* top, const char* word);
void swapWords(Array* text, char* first, char* second);
int selectionWordOption(const Stack* first, const Stack* second);
void replaceWords(Stack* top, Array* dividedText);
void pushStack(Stack** top, char* clearWord, int frequency);
void createStack(Stack** top, const Array* dividedText);
Array* splitText(const char inputFileName[]);
int compareWords(Stack* top, const char* clearWord);