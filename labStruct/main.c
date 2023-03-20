#include "functions.h"

int main() {
    int n = 0;
    struct phone* phoneFunction = NULL;
    menu(phoneFunction, n);
    free(phoneFunction);
    return 0;
}
