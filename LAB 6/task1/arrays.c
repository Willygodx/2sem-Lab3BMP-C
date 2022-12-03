#include "arrays.h"
int checkRandomOrManualInput(int a) {
    while (scanf("%d", &a) != 1 || getchar() != '\n' || a >= 3 || a <= 0) {
        printf("Incorrect input. Try again: ");
        rewind(stdin);
    }
    return a;
}
int checkInput(int a) {
    while (scanf("%d", &a) != 1 || getchar() != '\n' || a < 1) {
        printf("Incorrect input. Try again: ");
        rewind(stdin);
    }
    return a;
}
int checkInputFillingArray(int a) {
    while (scanf("%d", &a) != 1 || getchar() != '\n') {
        printf("Incorrect input. Try again: ");
        rewind(stdin);
    }
    return a;
}
void initArray(int** arr, int sizeOfArray) {
    *arr = (int*) malloc(sizeOfArray * sizeof(int*));
}
void fillArray(int** arr, int sizeOfArray, int c) {
    for (int i = 0; i < sizeOfArray; i++) {
        if (c == 1) {
            int n = checkInputFillingArray(n);
            (*arr)[i] = n;
        } else if (c == 2) {
            (*arr)[i] = (rand() % 100 - 50 + 1);
        }
    }
    for (int i = 0; i < sizeOfArray; i++) {
        printf("%d ", (*arr)[i]);
    }
}
void copyArray(int** arr1, int sizeOfArray, int** arr) {
    *arr1 = (int*) malloc(sizeOfArray * sizeof(int*));
    for (int i = 0; i < sizeOfArray; i++) {
        (*arr1)[i] = (*arr)[i];
    }
}
void selectionSort(int** arr, int sizeOfArray) {
    int temp = 0, min = 0, max = maxNumber(arr, sizeOfArray);
    printf("\nMax index is %d", max);
    clock_t start = clock();
    for (int i = max + 1; i < sizeOfArray; i++) {
            if ((*arr)[i] % 2 == 0) {
                min = i;
                for (int j = i + 1; j < sizeOfArray; j++)
                    if ((*arr)[min] > (*arr)[j] && (*arr)[j] % 2 == 0)
                        min = j;
                temp = (*arr)[min];
                (*arr)[min] = (*arr)[i];
                (*arr)[i] = temp;
            }
    }
    clock_t end = clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;
    printf("\nTime of sort(selection): %f seconds", seconds);
}
void bubbleSort(int** arr1, int sizeOfArray) {
    int temp, max = maxNumber(arr1, sizeOfArray);
    clock_t start = clock();
    for (int i = max + 1; i < sizeOfArray - 1; i++) {
        if ((*arr1)[i] % 2 == 0 ) {
            for (int j = max + 1; j < sizeOfArray - 1 - i; j++) {
                if ((*arr1)[j] > (*arr1)[i] && (*arr1)[j] % 2 == 0) {
                    temp = (*arr1)[j];
                    (*arr1)[j] = (*arr1)[i];
                    (*arr1)[i] = temp;
                }
            }
        }
    }
    clock_t end = clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;
    printf("\nTime of sort(bubble): %f seconds", seconds);
}
void theWorstCase(int** arr, int sizeOfArray) {
    int k = 0;
    for (int i = sizeOfArray; i > 0; i--) {
        (*arr)[k] = i;
        k++;
    }
}
void outputArray(int** arr, int sizeOfArray) {
    printf("\nSorted array: \n");
    for (int i = 0; i < sizeOfArray; i++) {
        printf("%d ", (*arr)[i]);
    }
}
int maxNumber(int** arr, int sizeOfArray) {
    int max = -99999, count = 0;
    for (int i = 0; i < sizeOfArray; i++) {
        if ((*arr)[i] > max) {
            max = (*arr)[i];
        }
    }
    for (int i = 0; i < sizeOfArray; i++) {
        if ((*arr)[i] == max) {
            break;
        }
        count++;
    }
    return count;
}


