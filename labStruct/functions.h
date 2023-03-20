#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

 enum Color {
    colorBlack = 1,
    colorGreen = 2,
    colorRed = 3,
    colorYellow = 4
};

typedef struct phone
{
    char *name;
    float diagonal;
    int ram;
    enum Color color;

} phoneFunction;

phoneFunction *structureInitialise(int *elements);
void memoryForStruct(struct phone **structure, const int* n);
void enterArrayOfStructures(struct phone structure[], int elements);
void printArrayOfStructures(struct phone structure[], int elements);
void typesOfSorting(struct phone *structure, int elements);
void sortingByTwoParameters(struct phone *structure, int elements, int firstParameter, int const secondParameter);
void sortByOneParameter (struct phone *structure, elements);
void sortByName(struct phone structure[], int elements);
void sortByDiagonal(struct phone structure[], int elements);
void sortByRAM(struct phone structure[], int elements);
void sortByColor(struct phone structure[], int elements);
void deleteStructure(struct phone structure[], int* elements);
void menu(phoneFunction *structure, int elements);
