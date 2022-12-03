#include "str.h"

int checkMenuInput(int a) {
    while (scanf("%d", &a) != 1 || a >= 3 || a <= 0 || getchar()!='\n') {
        printf("Incorrect input. Try again: ");
        rewind(stdin);
    }
    return a;
}
int checkInput(int a) {
    while (scanf("%d", &a) != 1 || getchar() != '\n' || a <= 0) {
        printf("Incorrect input. Try again: ");
        rewind(stdin);
    }
    return a;
}
typedef struct info {
    int size;
    int flag;
} infoTemp;

infoTemp getStringError(char** str){
    char c;
    int strSize = 1;
    infoTemp info;
    info.flag = 1;
    *str = (char*)calloc(1,1);
    while((c = getchar())!= '\n'){
        (*str) = (char*)realloc(*str,strSize + 1);
        (*str)[strSize - 1] = c;
        strSize++;
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == ' ') {
            continue;
        } else {
            info.flag = 0;
            *str = (char*)realloc(*str,1);
            rewind(stdin);
            break;
        }
    }
    (*str)[strSize-1] = '\n';
    info.size = strSize;
    return info;
}
int getString(char** str) {
    infoTemp info;
    while((info = getStringError(str)).flag == 0) {
        printf("Incorrect input. Try again: ");
    }
    return info.size;
}
int stringLength(const char* str) {
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}
void* task1(void) {
    int n = 100, strLength, i = 0;
    char* str = (char*)malloc(sizeof(char) * n);
    printf("Enter your string:\n>");
    getString(&str);
    strLength = stringLength(str);
    fillNewStringOne(i, strLength, str);
    printf("New string: %s", str);
    free(str);
    return 0;
}
void fillNewStringOne(int i, int strLength, char *str) {
    for (i = 0; i <= strLength; i++) {
        if (islower(str[i])) {
            str[i] = toupper(str[i]);
        }
        else
            str[i] = tolower(str[i]);
    }
}
void* task2(void) {
    int n = 100, strLength, N = 0;
    char* str = (char*)malloc(sizeof(char) * n);
    char* newStr = (char*)malloc(sizeof(char) * n);
    printf("Enter your string:\n>");
    getString(&str);
    strLength = stringLength(str);
    printf("Enter any number to remake string:\n>");
    N = checkInput(N);
    fillNewStringTwo(strLength, N, newStr, str);
    printf("New string: %s", newStr);
    free(str);
    free(newStr);
    return task2;
}
void fillNewStringTwo(int strLength, int N, char *newStr, char *str) {
    if (strLength > N + 1) {
        int temp = strLength - N - 1;
        for (int i = 0; i < strLength; i++) {
            newStr[i] = str[temp];
            temp++;
        }
    } else if (strLength < N + 1) {
        int temp = N + 1 - strLength;
        for (int i = 0; i < N + 1 - strLength; i++) {
            newStr[i] = '.';
        }
        for (int i = 0; i < strLength; i++) {
            newStr[temp] = str[i];
            temp++;
        }
        newStr[N] = '\0';
    } else if (strLength == N + 1) {
        for (int i = 0; i < strLength; i++) {
            newStr[i] = str[i];
        }
    }
}
