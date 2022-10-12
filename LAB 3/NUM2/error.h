#include <stdio.h>
void Clear() {
    rewind(stdin);
}
void ErrorAndClean (){
    printf("\nYou wrote an incorrect symbol! Try again: ");
    Clear();

}