#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"
#include <time.h>
int main()
{
    srand(time(NULL));
    int n, c;
    printf("Type 1 for manual input or 2 for random input: ");
    while (scanf("%d", &c) != 1 || getchar() != '\n'||c >= 3 ||c <= 0) {
        printf("Incorrect input. Try again: ");
        rewind(stdin);
    }
    printf("Enter amount of rows and columns NxN: ");
    while (scanf("%d", &n) != 1 || n <= 0 || n > 100 || getchar() != '\n') {
        printf("Incorrect input. Try again: ");
        rewind(stdin);
    }
    int** a = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        a[i] = (int *) malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            if (c == 1) {
                printf("a[%d][%d] = ", i, j);
                scanf("%d", &a[i][j]);
            } else if (c == 2) {
                a[i][j] = rand() % 100 - 50;
            }
        }
    }
    OutputArray(a, n, n);
    MinNumber(a, n);
    free(a);
    return 0;
}