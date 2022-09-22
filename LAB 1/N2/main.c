#include <stdio.h>
#include "error.h"
int main() {
   float a, b;
    printf("Put down the first number: ");
   while (scanf("%f", &a) < 1)
       ErrorAndClean ();
    printf("Put down the second number: ");
    while (scanf("%f", &b) < 1)
        ErrorAndClean ();
    if (a == b)
        printf("The first number equal the second number!");
    else printf("These numbers are not equal!");

    return 0;
}
