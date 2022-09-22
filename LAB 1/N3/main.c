#include <stdio.h>
#include "error.h"

int main() {
    int a, b, c;
    printf("Put down the first number: ");
    while (scanf("%d", &a) < 1)
        ErrorAndClean();
    printf("Put down the second number: ");
    while (scanf("%d", &b) < 1)
        ErrorAndClean();
    printf("Put down the third number: ");
    while (scanf("%d", &c) < 1)
        ErrorAndClean();
    if (a + b == 0) {
        printf("The remaining number that is not included in a pair of mutually apposite numbers: %d", c);
    }
    else if (a + c == 0) {
        printf("The remaining number that is not included in a pair of mutually apposite numbers: %d", b);
    }
    else if (b + c == 0) {
        printf("The remaining number that is not included in a pair of mutually apposite numbers: %d", a);
    }
    else if (a + b != 0 && a + c != 0 && b + c != 0) {
        printf("No, there is no pair of mutually opposite numbers.");
    }
    return 0;
}
