#include <stdio.h>
#ifndef N4_ERROR_H
#define N4_ERROR_H
void Clear() {
    rewind(stdin);
}
void ErrorAndClean (){
    printf("\nYou wrote an incorrect symbol! Try again: ");
    Clear();

}


#endif //N4_ERROR_H
