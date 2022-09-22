#include <stdio.h>

int main() {
    int n = 0;
    float s = 0;
    do {
     n++;
     s = s + (float)1 / (float)n;

    } while (s <= 5);

    printf("Number of terms: %d\n", n);

    return 0;
}
