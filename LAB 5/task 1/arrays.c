#include "arrays.h"
int checkInput (int a) {
    while (scanf("%d", &a) != 1 || getchar() != '\n' || a <= 1 || a > 98) {
        printf("Incorrect input. Try again: ");
        rewind(stdin);
    }
    return a;
}
void initArray (int** arr, int n) {
    *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < 49; i++)
    {
        (*arr)[i] = (i+1) * 2;
    }
}
void printArray (int* arr) {
    for (int i = 0; i < 49; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nEnter the line segment: ");
}
int* deleteOddElements(int* arr,int a,int b) {
    if (a % 2 == 1 && b % 2 == 1)
        b -= 1;
    for (int i = 0; i <= ((b - a) / 2) + 1; i++) {
        arr[i] = a + i * 2;
        if (arr[i] % 2 == 1)
            arr[i] += 1;
    }
    return arr;
}
void resizeArray(int** arr, int b,int a){
    *arr = (int*)realloc(*arr, (b - a) * sizeof(int));
    for (int i = 0; i < (b - a)/2+1; i++)
        printf("%d ", (*arr)[i]);
}

