#include "arrays.h"
int main() {
    int** arr;
    printf("Input amount of rows: ");
    int N = checkInput(N);
    printf("Input amount of columns: ");
    int M = checkInput(M);
    fillArray(&arr, N, M);
    outputArray(arr, N, M);
    ShellSortTable(&arr, N, M);
    printf("\n");
    outputArray(arr, N, M);
    freeArray(arr, N);
}
