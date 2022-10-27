#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main() {
    srand(time(NULL));
    int n = 0, m = 0, p;
    int a[100][100];
    printf("SIZE OF MATRIX NxM.\n");
    printf("Enter number of rows: ");
    while (scanf("%d", &n) != 1 || n < 1 || n > 100 || getchar() != '\n') {
        printf("Incorrect input. Try again: ");
        rewind(stdin);
    }
    printf("Enter number of columns: ");
    while (scanf("%d", &m) != 1 || m < 1 || m > 100 || getchar() != '\n') {
        printf("Incorrect input. Try again: ");
        rewind(stdin);
    }
    printf("Type 1 for random input or 2 for manual: ");
    while (scanf("%i", &p) != 1 || p < 1 || p > 2 || getchar() != '\n') {
        printf("Incorrect input. Try again: ");
        rewind(stdin);
    }
    switch (p) {
        case 2:
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++){
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
                for (int j = 0; j < m; j++){
                    printf("arr[%d][%d]= ", i, j);
                    a[i][j] = (rand() % 100 - 30);
                    printf("%d  ", a[i][j]);
                }
                printf("\n");
            }
            break;
        }
    bool flag = false;
    int sum = 0;
    int index = 0;
    for (int i = 0; i < n; i++) {
        flag = true;
        for (int j = 0; j < m; j++){
            if (a[i][j] <= 0) { flag = false; }
            else index = i;}
        if (flag == true){
            for (int o = 0; o < m; o++){
                sum += a[index][o];
            }
            break;
        }
    }
    printf("SUM = %d\n", sum);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
            a[i][j] -= sum;}}
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < m; k++) {
            printf("arr[%d][%d]= %d ", j,k,a[j][k]);}
        printf("\n");}
    return 0;}

