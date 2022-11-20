#include "arrays.h"
int main() {
    printf("Input amount of rows for table: ");
    int size_of_table = checkInput(size_of_table);
    int **table;
    int *rows;
    initArray(size_of_table, &table, &rows);
    fillArray(size_of_table, table, rows);
    outputArray(size_of_table, table, rows);
    return 0;
}
