#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int n = 0, p;
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
                    a[i][j] = (rand() % 10);
                    printf("%d  ", a[i][j]);
                }
                printf("\n");
            }
            break;
    }
    int summROW[100], summCOL[100], summDIAG[2];
    for (int i = 0; i < n; i++){
        summDIAG[0] += a[i][i];
        summDIAG[1] += a[(n - 1) - i][(n - 1) - i];
        for (int j = 0; j < n; j++){
            summROW[i] += a[i][j];
            summCOL[i] += a[j][i];
        }
        if (summCOL[i] != summROW[i]){
            printf("Matrix is not a magic square.");
            break;
        }
        else if ((i > 0) && (summROW[i] != summROW[i - 1])){
            printf("Matrix is not a magic square.");
            break;
        }
        else if ((i > 0) && (summCOL[i] != summCOL[i - 1]))    {
            printf("Matrix is not a magic square.");
            break;
        }
    }
    if ((summDIAG[0] == summDIAG[1]) && (summCOL[0] == summDIAG[0]))
        printf("Matrix is a magic square!");
    return 0;
}
