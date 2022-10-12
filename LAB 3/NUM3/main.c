#include <stdio.h>
#include <stdlib.h>
#include "error.h"
int main()
{
    int a[100], i, n, j, temp = 0, siz;
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


    for (j = 0; j < siz; j++){
        for (i = 0; i < siz - 1; i++) {
            if (a[i] < a[i + 1]){
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
    }
    printf("New array: ");
    for (i = 0; i < siz; i++) {
        printf("%d", a[i]);
    }
    return(0);
}
