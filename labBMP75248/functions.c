#include "functions.h"

int checkIfBMP(const char* fileName)
{
    unsigned long length = strlen(fileName);
    if (length < 4) return 0;
    const char* extension = &fileName[length - 4];
    if (strcmp(extension, ".bmp") == 0)
    {
        return 1;
    } else
    {
        return 0;
    }
}

void checkValueForMedianFiltering(int* value)
{
    while (scanf("%d", value) == 0 || *value < 0 || *value > 11 || *value % 2 == 0 || getchar() != '\n')
    {
        printf("Error input! Try again\n>");
        rewind(stdin);
    }
}

void checkValueForGammaValue(float* value)
{
    while (scanf("%f", value) == 0 || *value < 0 || *value > 5.5f || getchar() != '\n')
    {
        printf("Error input! Try again\n>");
        rewind(stdin);
    }
}

void checkValueForMenu(int* value)
{
    while(scanf("%d", value) == 0 || *value < 0 || *value > 7 || getchar() != '\n')
    {
        printf("Error input! Try again\n>");
        rewind(stdin);
    }
}


FILE* openFileWithChecks(const char* fileName, const char* openMode)
{
    FILE* fileBMP;
    BITMAPINFOHEADER bitmapInfoHeader;
    if (checkIfBMP(fileName) == 0)
    {
        fprintf(stderr, "Error: it's not a BMP file!\n");
        exit(EXIT_FAILURE);
    } else
    {
        fileBMP = fopen(fileName, openMode);
        if (fileBMP == NULL)
        {
            fprintf(stderr, "Error: unable to open this file!\n");
            exit(EXIT_FAILURE);
        }
        fseek(fileBMP, 14, SEEK_SET);
        fread(&bitmapInfoHeader, sizeof(BITMAPINFOHEADER), 1, fileBMP);
        if (bitmapInfoHeader.biBitCount != 24)
        {
            fprintf(stderr, "Error: it's not a 24-bit BMP file!\n");
            exit(EXIT_FAILURE);
        }
        return fileBMP;
    }
}

FILE* copyFile(FILE* fileBMP, FILE* editedFile, const char* editedFileName)
{
    unsigned char* buffer;
    size_t bytes;
    fseek(fileBMP, 0, SEEK_END);
    bytes = ftell(fileBMP);
    buffer = (unsigned char*) malloc(bytes * sizeof(unsigned char));
    fseek(fileBMP, 0, SEEK_SET);
    fread(buffer, sizeof(unsigned char), bytes, fileBMP);
    fseek(editedFile, 0, SEEK_SET);
    fwrite(buffer, sizeof(unsigned char), bytes, editedFile);
    fclose(editedFile);
    editedFile = openFileWithChecks(editedFileName, "rb+");
    return editedFile;
}

void convertToNegative(FILE* fileBMP, FILE* editedFile)
{
    checkFiles(fileBMP, editedFile);
    BITMAPINFOHEADER bitmapInfoHeader;
    BITMAPFILEHEADER bitmapFileHeader;
    fseek(fileBMP, 0, SEEK_SET);
    fread(&bitmapFileHeader, sizeof(BITMAPFILEHEADER), 1, fileBMP);
    fread(&bitmapInfoHeader, sizeof(BITMAPINFOHEADER), 1, fileBMP);
    RGB* pixelBuffer = (RGB*) malloc(bitmapInfoHeader.biWidth * bitmapInfoHeader.biHeight * sizeof(RGB));
    fseek(fileBMP, bitmapFileHeader.bfOffBits, SEEK_SET);
    fread(pixelBuffer, sizeof(RGB), bitmapInfoHeader.biWidth * bitmapInfoHeader.biHeight, fileBMP);
    for (size_t i = 0; i < bitmapInfoHeader.biWidth * bitmapInfoHeader.biHeight; i++)
    {
        RGB* tempPixel = &pixelBuffer[i];
        tempPixel->red = 255 - tempPixel->red;
        tempPixel->green = 255 - tempPixel->green;
        tempPixel->blue = 255 - tempPixel->blue;
    }
    fwrite(&bitmapFileHeader, sizeof(BITMAPFILEHEADER), 1, editedFile);
    fwrite(&bitmapInfoHeader, sizeof(BITMAPINFOHEADER), 1, editedFile);
    fseek(editedFile, bitmapFileHeader.bfOffBits, SEEK_SET);
    fwrite(pixelBuffer, sizeof(RGB), bitmapInfoHeader.biWidth * bitmapInfoHeader.biHeight, editedFile);
    free(pixelBuffer);
}

void convertToBlackAndWhite(FILE* fileBMP, FILE* editedFile)
{
    checkFiles(fileBMP, editedFile);
    BITMAPINFOHEADER bitmapInfoHeader;
    BITMAPFILEHEADER bitmapFileHeader;
    fseek(fileBMP, 0, SEEK_SET);
    fread(&bitmapFileHeader, sizeof(BITMAPFILEHEADER), 1, fileBMP);
    fread(&bitmapInfoHeader, sizeof(BITMAPINFOHEADER), 1, fileBMP);
    RGB* pixelBuffer = (RGB*) malloc(bitmapInfoHeader.biWidth * bitmapInfoHeader.biHeight * sizeof(RGB));
    fseek(fileBMP, bitmapFileHeader.bfOffBits, SEEK_SET);
    fread(pixelBuffer, sizeof(RGB), bitmapInfoHeader.biWidth * bitmapInfoHeader.biHeight, fileBMP);
    for (size_t i = 0; i < bitmapInfoHeader.biWidth * bitmapInfoHeader.biHeight; i++) {
        RGB* tempPixel = &pixelBuffer[i];
        BYTE black = (tempPixel->red + tempPixel->green + tempPixel->blue) / 3;
        tempPixel->red = black;
        tempPixel->green = black;
        tempPixel->blue = black;
    }
    fwrite(&bitmapFileHeader, sizeof(BITMAPFILEHEADER), 1, editedFile);
    fwrite(&bitmapInfoHeader, sizeof(BITMAPINFOHEADER), 1, editedFile);
    fseek(editedFile, bitmapFileHeader.bfOffBits, SEEK_SET);
    fwrite(pixelBuffer, sizeof(RGB), bitmapInfoHeader.biWidth * bitmapInfoHeader.biHeight, editedFile);
    free(pixelBuffer);
}

void gammaCorrection(FILE* fileBMP, FILE* editedFile, float gammaValue)
{
    checkFiles(fileBMP, editedFile);
    BITMAPINFOHEADER bitmapInfoHeader;
    BITMAPFILEHEADER bitmapFileHeader;
    fseek(fileBMP, 0, SEEK_SET);
    fread(&bitmapFileHeader, sizeof(BITMAPFILEHEADER), 1, fileBMP);
    fread(&bitmapInfoHeader, sizeof(BITMAPINFOHEADER), 1, fileBMP);
    RGB* pixelBuffer = (RGB*) malloc(bitmapInfoHeader.biWidth * bitmapInfoHeader.biHeight * sizeof(RGB));
    fseek(fileBMP, bitmapFileHeader.bfOffBits, SEEK_SET);
    fread(pixelBuffer, sizeof(RGB), bitmapInfoHeader.biWidth * bitmapInfoHeader.biHeight, fileBMP);
    for (size_t i = 0; i < bitmapInfoHeader.biWidth * bitmapInfoHeader.biHeight; i++)
    {
        RGB* tempPixel = &pixelBuffer[i];
        tempPixel->red = (BYTE)(255 * pow(tempPixel->red / 255.0, gammaValue));
        tempPixel->green = (BYTE)(255 * pow(tempPixel->green / 255.0, gammaValue));
        tempPixel->blue = (BYTE)(255 * pow(tempPixel->blue / 255.0, gammaValue));
    }
    fwrite(&bitmapFileHeader, sizeof(BITMAPFILEHEADER), 1, editedFile);
    fwrite(&bitmapInfoHeader, sizeof(BITMAPINFOHEADER), 1, editedFile);
    fseek(editedFile, bitmapFileHeader.bfOffBits, SEEK_SET);
    fwrite(pixelBuffer, sizeof(RGB), bitmapInfoHeader.biWidth * bitmapInfoHeader.biHeight, editedFile);
    free(pixelBuffer);
}

void medianFilter(FILE* fileBMP, FILE* editedFile, int filterSize)
{
    checkFiles(fileBMP, editedFile);
    BITMAPINFOHEADER bitmapInfoHeader;
    BITMAPFILEHEADER bitmapFileHeader;
    fseek(fileBMP, 0, SEEK_SET);
    fread(&bitmapFileHeader, sizeof(BITMAPFILEHEADER), 1, fileBMP);
    fread(&bitmapInfoHeader, sizeof(BITMAPINFOHEADER), 1, fileBMP);
    RGB* pixelBuffer = (RGB*) malloc(bitmapInfoHeader.biWidth * bitmapInfoHeader.biHeight * sizeof(RGB));
    fseek(fileBMP, bitmapFileHeader.bfOffBits, SEEK_SET);
    fread(pixelBuffer, sizeof(RGB), bitmapInfoHeader.biWidth * bitmapInfoHeader.biHeight, fileBMP);
    size_t* redPixelValue = malloc(filterSize * filterSize * sizeof(size_t));
    size_t* greenPixelValue = malloc(filterSize * filterSize * sizeof(size_t));
    size_t* bluePixelValue = malloc(filterSize * filterSize * sizeof(size_t));
    for (size_t i = filterSize / 2; i < bitmapInfoHeader.biHeight - filterSize / 2; i++) {
        for (size_t j = filterSize / 2; j < bitmapInfoHeader.biWidth - filterSize / 2; j++) {
            size_t row = i - filterSize / 2;
            size_t col = j - filterSize / 2;
            for (size_t m = 0; m < filterSize * filterSize; m++) {
                size_t rowIndex = m / filterSize;
                size_t colIndex = m % filterSize;
                redPixelValue[m] = pixelBuffer[(row + rowIndex) * bitmapInfoHeader.biWidth + col + colIndex].red;
                greenPixelValue[m] = pixelBuffer[(row + rowIndex) * bitmapInfoHeader.biWidth + col + colIndex].green;
                bluePixelValue[m] = pixelBuffer[(row + rowIndex) * bitmapInfoHeader.biWidth + col + colIndex].blue;
            }
            pixelBuffer[i * bitmapInfoHeader.biWidth + j].red = (uint8_t) sortAndMedianSize(redPixelValue, filterSize * filterSize);
            pixelBuffer[i * bitmapInfoHeader.biWidth + j].green = (uint8_t) sortAndMedianSize(greenPixelValue, filterSize * filterSize);
            pixelBuffer[i * bitmapInfoHeader.biWidth + j].blue = (uint8_t) sortAndMedianSize(bluePixelValue, filterSize * filterSize);
        }
    }
    free(redPixelValue);
    free(greenPixelValue);
    free(bluePixelValue);
    fwrite(&bitmapFileHeader, sizeof(BITMAPFILEHEADER), 1, editedFile);
    fwrite(&bitmapInfoHeader, sizeof(BITMAPINFOHEADER), 1, editedFile);
    fseek(editedFile, bitmapFileHeader.bfOffBits, SEEK_SET);
    fwrite(pixelBuffer, sizeof(RGB), bitmapInfoHeader.biWidth * bitmapInfoHeader.biHeight, editedFile);
    free(pixelBuffer);
}

int compare(const int* first, const int* second)
{
    return *first - *second;
}

size_t sortAndMedianSize(size_t *pixelValue, const size_t length) {
    size_t medianValue;
    if (length == 0 || pixelValue == NULL) {
        return 0;
    }
    qsort(pixelValue, length, sizeof(size_t), (int(*) (const void*, const void*)) compare);
    if (length % 2 == 0) {
        medianValue = (pixelValue[length / 2 - 1] + pixelValue[length / 2]) / 2;
    } else {
        medianValue = pixelValue[length / 2];
    }
    return medianValue;
}

void menu(FILE* fileBMP, FILE* editedFile, const char* editedFileName)
{
    float gammaValue = 0;
    int medianFilterValue = 0;
    int chooseButton;
    while(1)
    {
        printf("\n1.Open the bmp image.\n"
               "2.Reset filters.\n"
               "3.Convert to negative filter.\n"
               "4.Convert to black and white filter.\n"
               "5.Gamma correction filter.\n"
               "6.Median filtering.\n"
               "7.Exit.\n>");
        fflush(stdin);
        checkValueForMenu(&chooseButton);
        rewind(stdin);
        switch (chooseButton)
        {
            case 1:
                fclose(editedFile);
                char terminal[60];
                strcpy(terminal, "open ");
                strcat(terminal, editedFileName);
                system(terminal);
                editedFile = openFileWithChecks(editedFileName, "rb+");
                break;
            case 2:
                editedFile = copyFile(fileBMP, editedFile, editedFileName);
                break;
            case 3:
                convertToNegative(fileBMP, editedFile);
                break;
            case 4:
                convertToBlackAndWhite(fileBMP, editedFile);
                break;
            case 5:
                printf("Enter gamma value level. Maximum value is 5.5!\n>");
                checkValueForGammaValue(&gammaValue);
                gammaCorrection(fileBMP, editedFile, gammaValue);
                break;
            case 6:
                printf("Enter median filtering window size. Maximum value is 11. This value cannot be even!!!\n");
                checkValueForMedianFiltering(&medianFilterValue);
                medianFilter(fileBMP, editedFile, medianFilterValue);
                break;
            case 7:
                fclose(editedFile);
                return;
            default:
                printf("Error input! Try again.\n>");
                break;
        }
    }
}

void checkFiles(const FILE* fileBMP, const FILE* editedFile)
{
    if (!fileBMP) {
        fprintf(stderr, "Error: unable to open this file!\n");
        exit(EXIT_FAILURE);
    }

    if (!editedFile) {
        fprintf(stderr, "Error: unable to open this file!\n");
        exit(EXIT_FAILURE);
    }
}