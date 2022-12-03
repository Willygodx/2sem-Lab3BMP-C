#include "arrays.h"

int main() {
    srand(time(NULL));
    int* arr;
    int* arr1;
    printf("Input size of array: ");
    int sizeOfArray = checkInput(sizeOfArray);
    printf("Type 1 for manual input or 2 for random input: ");
    int c = checkRandomOrManualInput(c);
    initArray(&arr, sizeOfArray);
    fillArray(&arr, sizeOfArray, c);
    copyArray(&arr1, sizeOfArray, &arr);
    //theWorstCase(&arr, sizeOfArray);
    selectionSort(&arr, sizeOfArray);
    outputArray(&arr, sizeOfArray);
    bubbleSort(&arr1, sizeOfArray);
    outputArray(&arr1, sizeOfArray);

}
