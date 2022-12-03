#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int checkInput (int a);
int checkInputFillingArray(int a);
int checkRandomOrManualInput(int a);
void initArray(int** arr, int sizeOfArray);
void fillArray(int** arr, int sizeOfArray, int c);
void selectionSort(int** arr, int sizeOfArray);
void bubbleSort(int** arr, int sizeOfArray);
void outputArray(int** arr, int sizeOfArray);
void theWorstCase(int** arr, int sizeOfArray);
int maxNumber(int** arr, int sizeOfArray);
void copyArray(int** arr1, int sizeOfArray, int** arr);