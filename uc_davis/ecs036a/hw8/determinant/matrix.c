#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrix.h"

void fillMatrix(FILE* inFile, struct Matrix* matrix) {
    int rows;
    int columns;
    fscanf(inFile, "%d", &rows);
    fscanf(inFile, "%d", &columns);
    matrix->rows = rows;
    matrix->columns = columns;
    matrix->matrixArray = (double **) malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++) {
        matrix->matrixArray[i] = (double *) malloc(columns * sizeof(double));
        for (int j = 0; j < columns; j++) {
            fscanf(inFile, "%lf", &(matrix->matrixArray[i][j]));
        }
    }
}

void constructSubMatrix(struct Matrix* matrix, struct Matrix* subMatrix, int excludedRow, int excludedColumn) {
    int rows = matrix->rows;
    int columns = matrix->columns;
    subMatrix->rows = rows - 1;
    subMatrix->columns = columns - 1;
    subMatrix->matrixArray = (double **) malloc((rows - 1) * sizeof(double *));
    int si = 0;
    int sj = 0;
    for (int i = 0; i < rows; i++) {
        if (i == excludedRow) {
            continue;
        }
        subMatrix->matrixArray[si] = (double *) malloc((columns - 1) * sizeof(double));
        for (int j = 0; j < columns; j++) {
            if (j == excludedColumn) {
                continue;
            }
            subMatrix->matrixArray[si][sj] = matrix->matrixArray[i][j];
            sj++;
        }
        sj = 0;
        si++;
    }
}

void clearMatrix(struct Matrix* matrix) {
    int rows = matrix->rows;
    for (int i = 0; i < rows; i++) {
        free(matrix->matrixArray[i]);
    }
    free(matrix->matrixArray);
    matrix->matrixArray = NULL;
    matrix->rows = -1;
    matrix->columns = -1;
}

/*
void printMatrix(const struct Matrix* matrix) {
    int rows = matrix->rows;
    int columns = matrix->columns;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%lf ", (matrix->matrixArray[i][j]));
        }
        printf("\n");
    }
}
*/

double calculateDeterminant(FILE* inFile) {
    struct Matrix matrix;
    fillMatrix(inFile, &matrix);
    return _calculateDeterminant(&matrix);
}

double _calculateDeterminant(struct Matrix* matrix) {
    if (matrix->rows == 1 && matrix->columns == 1) {
        double determinant = matrix->matrixArray[0][0];
        clearMatrix(matrix);
        return determinant;
    } else if (matrix->rows == 2 && matrix->columns == 2) {
        double determinant = matrix->matrixArray[0][0] * matrix->matrixArray[1][1] - matrix->matrixArray[0][1] * matrix->matrixArray[1][0];
        clearMatrix(matrix);
        return determinant;
    } else {
        int rows = matrix->rows;
        double determinant = 0.0;
        struct Matrix subMatrix;
        for (int i = 0; i < rows; i++) {
            constructSubMatrix(matrix, &subMatrix, 0, i);
            determinant += pow(-1, i) * matrix->matrixArray[0][i] * _calculateDeterminant(&subMatrix);
            clearMatrix(&subMatrix);
        }
        return determinant;
    }
}