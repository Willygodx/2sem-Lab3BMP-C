#include <stdio.h>
#include "arrays.h"
#include <mm_malloc.h>

int main() {
    int n = 99, a = 100, b = 100;
    int* arr;
    arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < 50; i++)
    {
        arr[i] = i * 2;
        printf("%d ", arr[i]);
    }
    while (a > b || a > 99 || b > 99 || a < 0 || b < 0 || a == b || getchar() != '\n')
    {
        rewind(stdin);
        printf("\nEnter line segment from a to b: ");
        scanf("%d", &a);
        scanf("%d", &b);
    }
    if (a % 2 == 1 && b % 2 == 1)
        b -= 1;

    DeleteOddElements(arr, a, b);
    arr=(int*)realloc(arr, (b - a)*sizeof(int));
    for (int i = 0; i < (b - a)/2 + 1; i++)
        printf("%d ", arr[i]);

    free(arr);
    return 0;
}
