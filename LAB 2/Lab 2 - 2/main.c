#include <stdio.h>
#include "error.h"

int main() {
    int amount = 0, n, j, i;
    printf("Enter the number: ");
    while (scanf("%d", &n) < 1)
        ErrorAndClean();
    for (i = 0; i * i * i <= n; i++)
        for (j = i; j * j * j <= n; j++)
            if ((i * i * i) + (j * j * j) == n)
                amount++;
    printf("Amount of terms: %d", amount);







    return 0;
}
