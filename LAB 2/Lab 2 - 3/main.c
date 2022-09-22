#include <stdio.h>
#include "error.h"
int main()
{
    int Q, P;
    printf("Enter the first number Q: ");
    while (scanf("%d", &Q) < 1)
        ErrorAndClean();
    printf("Enter the second number P: ");
    while (scanf("%d", &P) < 1)
        ErrorAndClean();

    while ((Q != 0) && (P != 0)) {
        if (Q > P)
            Q = Q % P;
        else
            P = P % Q;
    }
    if (Q + P == 1)
        printf("Q is coprime with P.");
    else
        printf("Q is not coprime with P.");
    return 0;
}



