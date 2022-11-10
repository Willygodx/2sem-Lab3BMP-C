#include "arrays.h"
#include <stdio.h>
void OutputArray(int** arr, int n, int m) {
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%5d ", arr[i][j]);
        }
        printf("\n");
    }
}
void OutputArrayZero(int** arr, int n, int m) {
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%5d ", arr[i][j]);
            if (arr[i][j] == 0) {
                break;
            }
        }
        printf("\n");
    }
}
int* DeleteOddElements(int* arr,int a,int b) {
    for (int i = 0; i <= ((b - a) / 2) + 1; i++) {
        arr[i] = a + i * 2;
        if (arr[i] % 2 == 1)
            arr[i] += 1;
    }
    return arr;
}
int MinNumber(int** arr, int n) {
    int min = 999;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x <= y; x++)
        {
            if (arr[y][x] < min)
                min = arr[y][x];
        }
    }
    printf("\nMinimal element: ");
    printf("%d \n", min);
    return min;
}
