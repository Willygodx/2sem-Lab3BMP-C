#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef uint16_t UINT;
typedef uint32_t DWORD;
typedef int32_t LONG;
typedef uint16_t WORD;
typedef uint8_t BYTE;

typedef struct BITMAPFILEHEADER
{
    UINT bfType;
    DWORD bfSize;
    UINT bfReserved1;
    UINT bfReserved2;
    DWORD bfOffBits;
} BITMAPFILEHEADER;

typedef struct BITMAPINFOHEADER
{
    DWORD biSize;
    LONG biWidth;
    LONG biHeight;
    WORD biPlanes;
    WORD biBitCount;
    DWORD biCompression;
    DWORD biSizeImage;
    LONG biXPelsPerMeter;
    LONG biYPelsPerMeter;
    DWORD biClrUsed;
    DWORD biClrImportant;
} BITMAPINFOHEADER;

typedef struct RGB
{
    BYTE Red;
    BYTE Green;
    BYTE Blue;
} RGB;