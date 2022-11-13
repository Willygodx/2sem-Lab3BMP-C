#include "arrays.h"
int checkInput(int a) {
    while (scanf("%d", &a) != 1 || a <= 0 || getchar() != '\n' || a > 100) {
        printf("Incorrect input. Try again: ");
        rewind(stdin);
    }
    return a;
}
void initArray(int*** arr, int n) {
    *arr = (int**)calloc(n, sizeof(int*));
}
void fillArray (int** arr, int n, int m) {
    int i = 0;
    for (i = 0; i < n; i++) {
        arr[i] = (int*)calloc(m, sizeof(int));
        int b = rand() % m;
        for (int j = 0; j < b - 1; j++) {
            arr[i][j] = j + 1;
        }
    }
}
void outputArray(int** arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%5d ", arr[i][j]);
            if (arr[i][j] == 0) {
                break;
            }
        }
        printf("\n");
    }
}
