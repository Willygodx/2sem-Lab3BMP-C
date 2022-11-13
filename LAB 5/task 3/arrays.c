#include "arrays.h"
int checkRandomOrManualInput (int a) {
    while (scanf("%d", &a) != 1 || getchar() != '\n' || a >= 3 || a <= 0) {
        printf("Incorrect input. Try again: ");
        rewind(stdin);
    }
    return a;
}
int checkInput (int b) {
    while (scanf("%d", &b) != 1 || b <= 0 || b > 100 || getchar() != '\n') {
        printf("Incorrect input. Try again: ");
        rewind(stdin);
    }
    return b;
}
void initArray(int*** arr, int n) {
    *arr = (int**)malloc(n * sizeof(int*));
}
void fillArray(int** arr, int n, int c) {
    for (int i = 0; i < n; i++) {
        arr[i] = (int *) malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            if (c == 1) {
                printf("a[%d][%d] = ", i, j);
                scanf("%d", &arr[i][j]);
            } else if (c == 2) {
                arr[i][j] = rand() % 100 - 50;
            }
        }
    }
}
void outputArray(int** arr, int n, int m) {
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%5d ", arr[i][j]);
        }
        printf("\n");
    }
}
int minNumber(int** arr, int n) {
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
