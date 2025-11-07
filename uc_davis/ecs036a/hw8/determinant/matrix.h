#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>

/*
Matrix struct.
Holds the number of rows and columns of the matrix, as well as a dynamically-allocated double array representing the matrix.
*/
struct Matrix {
    int rows;
    int columns;
    double** matrixArray;
};

/*
Fills in a Matrix struct with the matrix contained in the file.
@param inFile: pointer to the file structure.
@param matrix: pointer to the Matrix struct.
@return: nothing.
*/
void fillMatrix(FILE* inFile, struct Matrix* matrix);

/*
Constructs a sub-matrix from the given matrix minus the specified row and column.
@param matrix: pointer to the the original matrix.
@param subMatrix: pointer to the sub-matrix.
@param excludedRow: row to exclude in the sub-matrix.
@param excludedColumn: column to exclude in the sub-matrix.
@return: nothing.
*/
void constructSubMatrix(struct Matrix* matrix, struct Matrix* subMatrix, int excludedRow, int excludedColumn);

/*
Frees all dynamically-allocated memory that is a part of the Matrix struct.
@param matrix: pointer to the matrix.
@return: nothing. 
*/
void clearMatrix(struct Matrix* matrix);

// void printMatrix(const struct Matrix* matrix);

/*
Wrapper for actual function that calculates the determinant. Used in the main.c file.
@param inFile: pointer to the file structure.
@return: a real number representing the determinant.
*/
double calculateDeterminant(FILE *inFile);

/*
Calculates the determinant of the Matrix struct.
@param matrix: pointer to the matrix.
@return: a real number representing the determinant.
*/
double _calculateDeterminant(struct Matrix* matrix);

#endif