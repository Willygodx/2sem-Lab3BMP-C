#include "arrays.h"
int main() {
    int n = 49;
    int* arr;
    initArray(&arr, n);
    printArray(arr);
    int a = checkInput(a);
    int b = checkInput(b);
    deleteOddElements(arr, a, b);
    resizeArray(&arr,b,a);
    free(arr);
    return 0;
}