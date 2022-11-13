#include "arrays.h"
int main() {
    srand(time(NULL));
    int** arr;
    printf("Enter amount of rows: ");
    int n = checkInput(n);
    printf("Enter amount of columns: ");
    int m = checkInput(m);
    initArray(&arr, n);
    fillArray(arr, n, m);
    outputArray(arr, n, m);
    free(arr);
    return 0;
}