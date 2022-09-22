#include <stdio.h>

#ifndef N2_ERROR_H
#define N2_ERROR_H
void Clear() {
    rewind(stdin);
}
void ErrorAndClean (){
    printf("\nYou wrote an incorrect symbol! Try again: ");
    Clear();

}

#endif //N2_ERROR_H
