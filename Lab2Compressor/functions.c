#include "functions.h"

Stack* getTop(Stack* top)
{
    if(top == NULL)
        return NULL;
    while(top->next)
        top = (Stack *) top->next;
    return top;
}

void pushStack(Stack** top, char* clearWord, int frequency)
{
    Stack* end = getTop(*top);
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->word = clearWord;
    stack->frequency = frequency;
    stack->flag = 0;
    stack->size = (int)strlen(clearWord);
    stack->next = NULL;
    if(*top == NULL)
    {
        *top = stack;
        return;
    }
    end->next = (struct Stack *) stack;
}

void createStack(Stack** top, const Array* dividedText)
{
    for (int i = 0; i < dividedText->size; i++)
    {
        if (compareWords(*top, dividedText->words[i]))
            continue;
        if (strstr(dividedText->words[i], "\n") != NULL)
            continue;
        int frequency = 0;
        for (int j = 0; j < dividedText->size; j++)
            if (strcmp(dividedText->words[i], dividedText->words[j]) == 0)
                frequency++;
        pushStack(top, dividedText->words[i], frequency);
    }
    mergeSort(top);
}

int compareWords(Stack* head, const char* word)
{
    while(head)
    {
        if(strcmp(head->word, word) == 0)
            return 1;

        head = (Stack *) head->next;
    }
    return 0;
}

void mergeSort(Stack** top)
{
    Stack* first = NULL;
    Stack* last = NULL;
    if((*top == NULL) || ((*top)->next == NULL))
        return;
    divideStackForMerge(*top, &first, &last);
    mergeSort(&first);
    mergeSort(&last);
    merge(first, last, top);
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

int selectionWordOption(const Stack* first, const Stack* second)
{
    if(first->frequency <= second->frequency)
        return 0;
    else if(first->flag || second->flag)
        return -1;
    else
        return (first->frequency * first->size + second->frequency * second->size) -
               (first->frequency * second->size + second->frequency * first->size) -
               (first->size + second->size + 2);
}

void setFlag(Stack* top, const char* word)
{
    while(top)
    {
        if(strcmp(top->word, word) == 0)
        {
            top->flag = 1;
            return;
        }
        top = (Stack *) top->next;
    }
}

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
    fread(text, 1, size, pFile);
    fclose(pFile);
    char* save;
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

void divideStackForMerge(Stack* top, Stack** first, Stack** last)
{
    Stack* tmp1 = NULL;
    Stack* tmp2 = NULL;
    if(top == NULL || top->next == NULL)
    {
        (*first) = top;
        (*last)  = NULL;
        return;
    }
    tmp2 = top;
    tmp1 = (Stack *) top->next;
    while (tmp1 != NULL)
    {
        tmp1 = (Stack *) tmp1->next;
        if(tmp1 != NULL)
        {
            tmp1 = (Stack *) tmp1->next;
            tmp2 = (Stack *) tmp2->next;
        }
    }
    (*first) = top;
    (*last) = (Stack *) tmp2->next;
    tmp2->next = NULL;
}

void merge(Stack *first, Stack *second, Stack **third)
{
    Stack tmp;
    *third = NULL;
    if (first == NULL)
    {
        *third = second;
        return;
    }
    if (second == NULL)
    {
        *third = first;
        return;
    }
    if (first->frequency * first->size > second->frequency * second->size)
    {
        *third = first;
        first = (Stack *) first->next;
    }
    else
    {
        *third = second;
        second = (Stack *) second->next;
    }
    tmp.next = (struct Stack *) *third;
    while (first && second)
    {
        if (first->frequency * first->size > second->frequency * second->size)
        {
            (*third)->next = (struct Stack *) first;
            first = (Stack *) first->next;
        }
        else
        {
            (*third)->next = (struct Stack *) second;
            second = (Stack *) second->next;
        }
        (*third) = (Stack *) (*third)->next;
    }
    if (first)
    {
        while (first)
        {
            (*third)->next = (struct Stack *) first;
            (*third) = (Stack *) (*third)->next;
            first = (Stack *) first->next;
        }
    }
    if (second)
    {
        while (second)
        {
            (*third)->next = (struct Stack *) second;
            (*third) = (Stack *) (*third)->next;
            second = (Stack *) second->next;
        }
    }
    *third = (Stack *) tmp.next;
}

void replaceWords(Stack* top, Array* dividedText)
{
    Stack* first = top;
    FILE* fp = fopen("wordsReplace.txt", "w");
    if (fp == NULL)
        exit(0);
    fclose(fp);
    while(first)
    {
        int maxLength = 0;
        char* word;
        Stack* second = top;
        while(second)
        {
            int chooseWord = selectionWordOption(first, second);
            if(chooseWord > maxLength)
            {
                maxLength = chooseWord;
                word = second->word;
            }
            second = (Stack *) second->next;
        }
        if(maxLength > 0)
        {
            setFlag(top, first->word);
            setFlag(top, word);
            if(strlen(word) == 0 || strlen(first->word) == 0)
                continue;
            swapWords(dividedText, first->word, word);
            FILE* pFile = fopen("wordsReplace.txt", "ab");
            if(pFile == NULL)
                exit(0);
            fputs(first->word, pFile);
            fputs(" ", pFile);
            fputs(word, pFile);
            fputs("\n", pFile);
            fclose(pFile);
        }
        first = (Stack *) first->next;
    }
}