#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int checkInput(int a);
int checkRandomOrManualInput(int a);
void fillArray(int*** table, int N, int M);
int sumRows(const int* row, int M);
void outputArray(int** table, int N, int M);
void freeArray(int** table, int N);
void ShellSortTable(int*** table, int N, int M);