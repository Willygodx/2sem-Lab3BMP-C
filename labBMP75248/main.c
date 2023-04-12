#include "functions.h"

int main()
{
    FILE *fileBMP;
    FILE *editedFile;
    char *fileBMPName = NULL;
    char *editedFileName = NULL;
    fileBMPName = (char*) malloc(256 * sizeof(char));
    editedFileName = (char*) malloc(4 * sizeof (char));
    strcpy(editedFileName, "NEW");
    printf("Enter name of the BMP file you want to edit!\n");
    scanf("%256s", fileBMPName);
    fileBMPName = realloc(fileBMPName, (strlen(fileBMPName) + 1) * sizeof(char));
    editedFileName = realloc(editedFileName, (strlen(fileBMPName) + strlen(editedFileName) + 1) * sizeof(char));
    strcat(editedFileName, fileBMPName);
    fileBMP = openFileWithChecks(fileBMPName, "rb");
    editedFile = openFileWithChecks(editedFileName, "wb");
    editedFile = copyFile(fileBMP, editedFile, editedFileName);
    menu(fileBMP, editedFile, editedFileName);
    fclose(fileBMP);
    fclose(editedFile);
    free(fileBMPName);
    free(editedFileName);
    return 0;
}




