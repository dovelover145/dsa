/*
Prints the result of the addition between two matrices, A and B, with a variable number of rows and columns.
*/

#include <stdio.h>

void fillMatrices(int n, int m, int matrixA[][m], int matrixB[][m]);
void printResultAddition(int n, int m, int matrixA[][m], int matrixB[][m]);

int main() {
    int n; // Number of rows in matrices
    int m; // Number of columns in matrices
    
    printf("Please enter the number of rows: ");
    scanf("%d", &n);

    printf("Please enter the number of columns: ");
    scanf("%d", &m);

    int matrixA[n][m];
    int matrixB[n][m];

    fillMatrices(n, m, matrixA, matrixB);

    printResultAddition(n, m, matrixA, matrixB);

    return 0;
}

/*
Fills the contents of two matrices.
@param n: The number of rows in the matrices.
@param m: The number of columns in the matrices.
@param matrixA: The first matrix to fill.
@param matrixB: The second matrix to fill.
@return: void.
*/
void fillMatrices(int n, int m, int matrixA[][m], int matrixB[][m]) {
    printf("Enter Matrix A\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &(matrixA[i][j]));
        }
    }

    printf("Enter Matrix B\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &(matrixB[i][j]));
        }
    }
}

/*
Prints the result of the addition of two matrices.
@param n: The number of rows in the matrices.
@param m: The number of columns in the matrices.
@param matrixA: The first matrix.
@param matrixB: The second matrix.
@return: void.
*/
void printResultAddition(int n, int m, int matrixA[][m], int matrixB[][m]) {    
    printf("A + B =\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrixA[i][j] + matrixB[i][j]);
        }
        printf("\n");
    }
}