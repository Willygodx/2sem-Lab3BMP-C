#include <stdio.h>
#include <stdlib.h>
#include "error.h"
int main() {
    int a[100], siz, b[100], n;
    printf("Type size of array: ");
    while (scanf("%d", &siz) < 1)
        ErrorAndClean();
    printf("Type 1 for random numbers or type 2 for input numbers of array: ");
    while (scanf("%d", &n) < 1)
        ErrorAndClean();
    switch (n) {
        case 1:
            for (int i = 0; i < siz; i++) {
                a[i] = (rand());
                printf("The %dth element of array - %d\n", i, a[i]);
            }
            break;
        case 2:
            printf("Type elements of array: \n");
            for (int j = 0; j < siz; j++) {
                printf("Number - ");
                while (scanf("%d", &a[j]) < 1)
                    ErrorAndClean();
            }
            break;
        default:
            printf("You typed a wrong symbol!");
    }
    printf("Second array: ");
    for (int j = 0, v = 0; j < siz; j++) {
        if (a[j] % 2 == 1) {
            b[v]=a[j];
            printf("%d ",b[v]);
            v++;
        }
    }
    return 0;
}
