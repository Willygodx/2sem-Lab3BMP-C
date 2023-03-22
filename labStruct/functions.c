#include "functions.h"
#define SWAP_CHAR(x, y) { char temp[100]; strcpy(temp, x); strcpy(x, y); strcpy(y, temp); }
#define SWAP_INTEGER(x, y) { int temp = x; x = y; y = temp; }
#define SWAP_FLOAT(x, y) { float temp = x; x = y; y = temp; }

void checkInputForInitialise (int *n)
{
    while (scanf("%d", n) == 0 || getchar() !='\n' || *n < 0 || *n > 50)
    {
        printf("Incorrect input!\n>");
        rewind(stdin);
    }
    rewind(stdin);
}

phoneFunction *structureInitialise(int *elements)
{
    int n;
    printf("Enter amount of objects:\n>");
    checkInputForInitialise(&n);
    phoneFunction *phones = (phoneFunction *) calloc(n, sizeof(phoneFunction));
    *elements = n;
    return phones;
}

void checkInput(int *n)
{
    while (scanf("%d", n) == 0 || getchar() !='\n' || *n > 4)
    {
        printf("Incorrect input!\n>");
        rewind(stdin);
    }
}

void checkInputForSingleSort (int *n)
{
    while (scanf("%d", n) == 0 || getchar() !='\n' || *n > 6 || *n < 0)
    {
        printf("Incorrect input!\n>");
        rewind(stdin);
    }
}

void checkInputForRAM(int *n)
{
    while (scanf("%d", n) == 0 || getchar() !='\n' || *n < 0 || *n > 64)
    {
        printf("Incorrect input!\n>");
        rewind(stdin);
    }
}

void checkInputForDiagonal(float *n)
{
    while (scanf("%f", n) == 0 || getchar() !='\n' || *n < 0 || *n > 7)
    {
        printf("Incorrect input!\n>");
        rewind(stdin);
    }
}
void enterArrayOfStructures(struct phone structure[], int elements)
{
    char copyBuffer[256];
    for (int i = 0; i < elements; i++)
    {
        printf("\nEnter Name:\n>");
        fgets (copyBuffer, 256, stdin);
        structure[i].name = (char *) calloc(256, sizeof(char));
        strcpy(structure[i].name, copyBuffer);
        rewind(stdin);
        printf("Enter RAM (Random Access Memory):\n>");
        checkInputForRAM(&structure[i].ram);
        printf("Enter Diagonal:\n>");
        checkInputForDiagonal(&structure[i].diagonal);
        printf("Enter color(1. Black || 2. Green || 3. Red || 4. Yellow):\n>");
        checkInputForSingleSort((int *) &structure[i].color);

    }
}

void printArrayOfStructures(struct phone structure[], int elements)
{
    rewind(stdin);
    for (int i = 0; i < elements; i++)
    {
        printf("\nName: %s", structure[i].name);
        printf("RAM (Random Access Memory): %d", structure[i].ram);
        printf("\nDiagonal: %1.1f", structure[i].diagonal);
        switch (structure[i].color)
        {
            case colorBlack:
                printf("\nColor: Black");
                break;
            case colorGreen:
                printf("\nColor: Green");
                break;
            case colorRed:
                printf("\nColor: Red");
                break;
            case colorYellow:
                printf("\nColor: Yellow");
                break;
        }
        printf("\n");
    }
}

void rangeCheck(int *value, int leftBorder, int rightBorder)
{
    while (scanf("%d", value) == 0 || getchar() !='\n' || *value < leftBorder || *value > rightBorder)
    {
        printf("Wrong input");
        rewind(stdin);
    }
}

void deletePhone(phoneFunction **structure, int index, int *size) {
    if (index < 0  || index >= *size) {
        printf("Error: index is out of bounds.\n");
        return;
    }
    free((*structure)[index].name);
    *size -= 1;
    if(*size == 0){
        free(*structure);
        *structure = NULL;
    }
    else {
        phoneFunction *newPhoneFunction = (phoneFunction *) realloc(*structure, *size * sizeof(phoneFunction));
        if (newPhoneFunction == NULL) {
            printf("Error: memory reallocation failed.\n");
            return;
        }
        *structure = newPhoneFunction;
    }

}

void deleteStructure(phoneFunction **structure, int *size)
{
    if (structure == NULL || *structure == NULL) {
        printf("Structure doesn't exist!");
        return;
    }
    int dell;
    int index = *size;
    printf("\nChoose TV that you want to delete.\n");
    for (int k = 0; k < index; k++)
    {
        printf("%d: %s\n", k, (*structure)[k].name);
    }
    rangeCheck(&dell, 0, index - 1);
    deletePhone(structure, dell, size);
}

void sortByName(struct phone structure[], int elements)
{
    for (int i = 1; i < elements; i++)
    {
        for (int j = 0; j < elements - 1; j++)
        {
            if(strcmp(structure[j].name, structure[j + 1].name) > 0)
            {
                SWAP_CHAR(structure[j].name, structure[j + 1].name)
                SWAP_INTEGER(structure[j].ram, structure[j + 1].ram)
                SWAP_FLOAT(structure[j].diagonal, structure[j + 1].diagonal)
                SWAP_INTEGER(structure[j].color, structure[j + 1].color)
            }
        }
    }
}

void sortByRAM(struct phone structure[], int elements)
{
    for (int i = 1; i < elements; i++)
    {
        for (int j = 0; j < elements - 1; j++)
        {
            if(structure[j].ram > structure[j + 1].ram)
            {
                SWAP_CHAR(structure[j].name, structure[j + 1].name)
                SWAP_INTEGER(structure[j].ram, structure[j + 1].ram)
                SWAP_FLOAT(structure[j].diagonal, structure[j + 1].diagonal)
                SWAP_INTEGER(structure[j].color, structure[j + 1].color)
            }
        }
    }
}

void sortByDiagonal(struct phone structure[], int elements)
{
    for (int i = 1; i < elements; i++)
    {
        for (int j = 0; j < elements - 1; j++)
        {
            if(structure[j].diagonal > structure[j + 1].diagonal)
            {
                SWAP_CHAR(structure[j].name, structure[j + 1].name)
                SWAP_INTEGER(structure[j].ram, structure[j + 1].ram)
                SWAP_FLOAT(structure[j].diagonal, structure[j + 1].diagonal)
                SWAP_INTEGER(structure[j].color, structure[j + 1].color)
            }
        }
    }
}

void sortByColor(struct phone structure[], int elements)
{
    for (int i = 1; i < elements; i++)
    {
        for (int j = 0; j < elements - 1; j++)
        {
            if(structure[j].color > structure[j + 1].color)
            {
                SWAP_CHAR(structure[j].name, structure[j + 1].name)
                SWAP_INTEGER(structure[j].ram, structure[j + 1].ram)
                SWAP_FLOAT(structure[j].diagonal, structure[j + 1].diagonal)
                SWAP_INTEGER(structure[j].color, structure[j + 1].color)

            }
        }
    }
}

void sortingByTwoParameters(struct phone *structure, int elements, int const secondParameter)
{
    int arr[10];
    int ram;
    float diagonal;
    int color;
    for (int i = 1; i < elements; i++)
    {
        for (int j = 0; j < elements - 1; j++)
        {
            if (structure[j].ram > structure[j + 1].ram)
            {
                ram = 1;
            } else
            {
                ram = 0;
            }
            if (structure[j].diagonal > structure[j + 1].diagonal)
            {
                diagonal = 1;
            } else
            {
                diagonal = 0;
            }
            if (structure[j].color > structure[j + 1].color)
            {
                color = 1;
            } else
            {
                color = 0;
            }
            arr[1] = strcmp(structure[j].name, structure[j + 1].name);
            arr[2] = (int) diagonal;
            arr[3] = ram;
            arr[4] = color;
            if(arr[secondParameter] > 0)
            {
                SWAP_CHAR(structure[j].name, structure[j + 1].name)
                SWAP_INTEGER(structure[j].ram, structure[j + 1].ram)
                SWAP_FLOAT(structure[j].diagonal, structure[j + 1].diagonal)
                SWAP_INTEGER(structure[j].color, structure[j + 1].color)
            }
        }
    }
}

void typesOfSorting(struct phone *structure, int elements)
{
    int count = 0;
    int switchButton;
    int firstParameter = 0;
    int secondParameter = 0;

    while(count != 2) {
        printf("\nChoose sorting type!\n 1.Sort by name.\n 2.Sort by diagonal.\n 3.Sort by RAM (Random Access Memory)\n 4.Sort by color\n>");
        if(count == 1)
        {
            checkInput(&secondParameter);
            switchButton = secondParameter;
        }
        else
        {
            checkInput(&firstParameter);
            switchButton = firstParameter;
        }
        switch (switchButton) {
            case 1:
                sortByName(structure, elements);
                break;
            case 2:
                sortByDiagonal(structure, elements);
                break;
            case 3:
                sortByRAM(structure, elements);
                break;
            case 4:
                sortByColor(structure, elements);
                break;
            default:
                break;
        }
        count++;
    }
    sortingByTwoParameters(structure, elements, secondParameter);
}

void sortByOneParameter (struct phone *structure, int elements)
{
    int tmp = 0;
    while (tmp != -1)
    {
        printf("\nChoose sorting type!\n 1.Sort by name.\n 2.Sort by diagonal.\n 3.Sort by RAM (Random Access Memory).\n 4.Sort by color.\n 5.Exit from the option.\n>");
        checkInputForSingleSort (&tmp);
        switch (tmp)
        {
            case 1:
                sortByName(structure, elements);
                break;
            case 2:
                sortByDiagonal(structure, elements);
                break;
            case 3:
                sortByRAM(structure, elements);
                break;
            case 4:
                sortByColor(structure, elements);
                break;
            case 5:
                tmp = -1;
                break;
            default:
                printf("Incorrect input!\n>");
                break;

        }
    }


}

phoneFunction* menu(phoneFunction *structure, int elements)
{
    int tmp = 0;
    int chooseButton = 0;
    while(tmp != -1)
    {
        printf("\n1.Enter amount of objects in an array.\n"
               "2.Enter an array of objects.\n"
               "3.Print an objects.\n"
               "4.Sort an array of objects by ONE parameters.\n"
               "5.Sort an array of objects by TWO parameters.\n"
               "6.Delete an object from array.\n"
               "7.Exit.\n>");
        fflush(stdin);
        scanf ("%d", &chooseButton);
        rewind(stdin);
        switch (chooseButton)
        {
            case 1:
                structure = structureInitialise(&elements);
                tmp = 1;
                break;
            case 2:
                if(tmp != 1)
                {
                    printf("First of all you should initialise an array!\n");
                    break;
                }
                enterArrayOfStructures(structure, elements);
                tmp = 2;
                break;
            case 3:
                if(tmp != 2)
                {
                    printf("First of all you should fill/initialise an array!\n");
                    break;
                }
                printArrayOfStructures(structure, elements);
                break;
            case 4:
                if (tmp != 2)
                {
                    printf("First of all you should fill/initialise an array!\n");
                    break;
                }
                sortByOneParameter(structure, elements);
                break;
            case 5:
                if(tmp != 2)
                {
                    printf("First of all you should fill/initialise an array!\n");
                    break;
                }
                typesOfSorting(structure, elements);
                break;
            case 6:
            {
                if(tmp != 2)
                {
                    printf("First of all you should fill/initialise an array!\n");
                    break;
                }
                deleteStructure((phoneFunction **) structure, &elements);
                break;
            }
            case 7:
                tmp = -1;
                break;
            default:
                printf("Incorrect input!\n>");
                break;
        }
    }
    return structure;
}
