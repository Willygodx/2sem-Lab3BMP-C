#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
typedef uint16_t UINT;
typedef uint32_t DWORD;
typedef int32_t LONG;
typedef uint8_t BYTE;

typedef struct {
    UINT bfType;
    DWORD bfSize;
    UINT bfReserved1;
    UINT bfReserved2;
    DWORD bfOffBits;
} __attribute__((packed)) BITMAPFILEHEADER;

typedef struct {
    DWORD biSize;
    LONG  biWidth;
    LONG  biHeight;
    UINT biPlanes;
    UINT biBitCount;
    DWORD biCompression;
    DWORD biSizeImage;
    LONG  biXPelsPerMeter;
    LONG  biYPelsPerMeter;
    DWORD biClrUsed;
    DWORD biClrImportant;
} __attribute__((packed)) BITMAPINFOHEADER;


typedef struct {
    BYTE red;
    BYTE green;
    BYTE blue;
} __attribute__((packed)) RGB;

int checkIfBMP(const char *fileName);
void checkValueForMedianFiltering(int* value);
void checkValueForGammaValue(float* value);
void checkValueForMenu(int* value);
FILE* openFileWithChecks(const char* fileName, const char* openMode);
FILE *copyFile(FILE *fileBMP, FILE *editedFile, const char *editedFileName);
void convertToNegative(FILE* fileBMP, FILE* editedFile);
void convertToBlackAndWhite(FILE* fileBMP, FILE* editedFile);
void gammaCorrection(FILE* fileBMP, FILE* editedFile, float gammaValue);
void medianFilter(FILE *fileBMP, FILE *editedFile, int filterSize);
int compare(const int* first, const int* second);
size_t sortAndMedianSize(size_t *pixelValue, const size_t length);
void menu(FILE* fileBMP, FILE* editedFile, const char* editedFileName);
