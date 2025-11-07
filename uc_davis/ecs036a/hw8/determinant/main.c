/*
Calculates the determinant of the matrix defined in the user-specified file. Assumes valid input (i.e. square matrices).
*/

#include <stdio.h>
#include "matrix.h"

int main(int argc, char* argv[]) {
    FILE* inFile = fopen(argv[1], "r");
    if (inFile == NULL) {
        return -1;
    }
    printf("The determinant is %.2lf.\n", calculateDeterminant(inFile));
    return 0;
}