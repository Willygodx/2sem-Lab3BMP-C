#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    srand(time(NULL));
    int n = 0, p = 0;
    int a[100][100];
    printf("Matrix size is NxN.\n");
    printf("Enter size of the array: ");
    while (scanf("%d", &n) != 1 || n < 1 || n > 100 || getchar() != '\n') {
        printf("Incorrect input. Try again: ");
        rewind(stdin);
    }
    printf("Type 1 for random input or 2 for manual: ");
    while (scanf("%i", &p) != 1 || p == 0 || p < 1 || p > 2 || getchar() != '\n') {
        printf("Incorrect input. Try again: ");
        rewind(stdin);
    }
    switch (p) {
        case 2:
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++){
                    printf("arr[%d][%d]= ", i, j);
                    while (scanf("%d", &a[i][j]) != 1 || a[i][j] > 100 || a[i][j] < -100 || getchar() != '\n') {
                        printf("Incorrect input. Try again: ");
                        rewind(stdin);
                    }
                }
                printf("\n");
            }
            break;
        case 1:
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++){
                    printf("arr[%d][%d]= ", i, j);
                    a[i][j] = (rand() % 100 - 50);
                    printf("%d  ", a[i][j]);
                }
                printf("\n");
            }
            break;
    }
    int sum = 0;
    int q=0;
    int w=n;
    for (int j = 0; j < n / 2 + 1; j++) {
        for (; q < w; q++) {
            sum += a[j][q];
        }
        q = 0;
        q += j + 1;
        w -= 1;
    }
    printf("Sum of elements in the first area of the matrix is %d.", sum);
    return 0;

}
