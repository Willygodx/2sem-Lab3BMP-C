#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"
int main()
{
    int n = 10, m = 10, i = 0;
    printf("Enter amount of rows: ");
    while (scanf("%d", &n) != 1 || n <= 0 || getchar() != '\n') {
        printf("Incorrect input. Try again: ");
        rewind(stdin);
    }
    printf("Enter amount of columns: ");
    while (scanf("%d", &m) != 1 || m <= 0 || getchar() != '\n') {
        printf("Incorrect input. Try again: ");
        rewind(stdin);
    }
    int** a = (int**)calloc(n, sizeof(int*));
    for (i = 0; i < n; i++)
    {
        a[i] = (int*)calloc(m, sizeof(int));
        int b = m;

        for (int j = 0; j < b - 1; j++)
        {
            a[i][j] = j + 1;
        }
    }
    OutputArrayZero(a, n, m);
    free(a);
    return 0;
}