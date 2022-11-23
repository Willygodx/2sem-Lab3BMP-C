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
void initArray(int*** arr, int N, int M){
    *arr = (int**)malloc(N * sizeof(int*));
    for(int i = 0; i < N; i++){
        (*arr)[i] = (int*)calloc(M,sizeof(int));
    }
}
void randomInitArray(int*** arr, int N, int M){
    srand(time(NULL));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            (*arr)[i][j] = rand() % (100 - 50 + 1);
        }
    }
}
void manualInitArray(int*** table, int N, int M){
    for(int i = 0;i<N;i++){
        printf("Enter [%d] row of matrix:\n ",i+1);
        for(int j = 0; j<M;j++){
            printf("Element [%d][%d] = ", i+1,j+1);
            (*table)[i][j] = checkInput((*table)[i][j]);
            printf("\n");
        }
    }
}
void fillArray(int*** table, int N, int M){
    printf("Enter 1 for manual input or 2 for random input: ");
    int var = checkRandomOrManualInput(var);
    int flag = 1;
    while(flag){
        switch (var) {
            case 2:
                initArray(table,N,M);
                randomInitArray(table,N,M);
                flag = 0;
                break;
            case 1:
                initArray(table,N,M);
                manualInitArray(table,N,M);
                flag = 0;
                break;
            default:
                printf("You wrote an incorrect variant, try again!\n>");
                var = checkInput(var);
        }
    }
}
int sumRows(const int* row, int M){
    int sum = 0;
    for(int i = 0;i<M;i++){
        sum += row[i];
    }
    return sum;
}
void outputArray(int** table, int N, int M){
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            printf("%5d ",table[i][j]);
            if(j == M-1){
                printf("   (sum of array = %d)", sumRows(table[i],M));
            }
        }
        printf("\n");
    }
}
void freeArray(int** table, int N){
    for(int i = 0;i<N;i++){
        free(table[i]);
    }
    free(table);
}
void swapPointers(int** pointer1, int** pointer2){
    int* temp_pointer = *pointer1;
    *pointer1 = *pointer2;
    *pointer2 = temp_pointer;
}
void ShellSortTable(int*** table, int N, int M){
    int i, j, gap;
    for(gap = N / 2; gap > 0; gap /= 2){
        for(i = gap; i < N; i++){
            for(j = i; j >= gap; j -= gap){
                if( sumRows((*table)[j],M) > sumRows((*table)[j-gap],M) ){
                    swapPointers(&(*table)[j],&(*table)[j-gap]);
                }
            }
        }
    }
}
