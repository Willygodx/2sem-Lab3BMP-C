#include <stdio.h>

#ifndef N3_ERROR_H
#define N3_ERROR_H
void Clear() {
    rewind(stdin);
}
void ErrorAndClean (){
    printf("\nYou wrote an incorrect symbol! Try again: ");
    Clear();

}
#endif //N3_ERROR_H
