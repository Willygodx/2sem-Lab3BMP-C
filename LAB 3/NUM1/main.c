#include <stdio.h>
#include <stdlib.h>
#include "error.h"

int main() {
    double a[100], m = 1,  sum = 0;
    int siz, n, i, mn = 0, mx = 0;
    printf("Type size of array: ");
    while (scanf("%d", &siz) < 1)
        ErrorAndClean();

    printf("Type 1 for random numbers or type 2 for input numbers of array: ");
    while (scanf("%d", &n) < 1)
        ErrorAndClean();

    switch (n) {
        case 1:
            for (int i = 0; i < siz; i++) {
                a[i] = (rand() );
                printf("The %dth number of array is %lf\n", i, a[i]);
                if (a[i] < a[mn]) mn = i;
                if (a[i] > a[mx]) mx = i;
                if (a[i] < 0) {
                    sum += a[i];
                }
            }
            break;
        case 2:
            printf("Type numbers of array: \n");
            for (int i = 0; i < siz; i++) {
                printf("Number - ");
                while (scanf("%lf", &a[i]) < 1)
                    ErrorAndClean();

                if (a[i] < a[mn]) mn = i;
                if (a[i] > a[mx]) mx = i;
                if (a[i] < 0) {
                    sum += a[i];
                }
            }
            break;

        default :
            printf("You typed a wrong number!");
    }

    printf("Sum: %0.2lf\n", sum);
    if (mx > mn) {
        i = mx;
        mx = mn;
        mn = i;
    }

    for (i = mx + 1; i < mn; i++) {
        m *= a[i];
    }
    printf("Multiplication: %0.2lf", m);
    return 0;
}
