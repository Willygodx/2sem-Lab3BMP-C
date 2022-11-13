#include "arrays.h"
int main() {
    srand(time(NULL));
    int** arr;
    printf("Type 1 for manual input or 2 for random input: ");
    int c = checkRandomOrManualInput(c);
    printf("Enter amount of rows and columns NxN: ");
    int n = checkInput(n);
    initArray(&arr, n);
    fillArray(arr, n, c);
    outputArray(arr, n, n);
    minNumber(arr, n);
    free(arr);
    return 0;
}