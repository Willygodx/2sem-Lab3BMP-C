#include <stdio.h>

#ifndef LAB_2___2_ERROR_H
#define LAB_2___2_ERROR_H
void Clear() {
    rewind(stdin);
}
void ErrorAndClean (){
    printf("\nYou wrote an incorrect symbol! Try again: ");
    Clear();

}

#endif //LAB_2___2_ERROR_H
