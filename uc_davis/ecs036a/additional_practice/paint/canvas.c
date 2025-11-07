#include <stdio.h>
#include <stdlib.h>
#include "canvas.h"

int min(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

void createCanvas(Canvas* canvas, int rows, int columns) {
    canvas->rows = rows;
    canvas->columns = columns;
    canvas->canvasArray = NULL;
    _createCanvasArray(&(canvas->canvasArray), rows, columns);
}

void _createCanvasArray(char*** canvasArray, int rows, int columns) {
    *canvasArray = (char**) malloc(rows * sizeof(char*));
    for (int i = 0; i < rows; i++) {
        (*canvasArray)[i] = (char*) malloc(columns * sizeof(char));
        for (int j = 0; j < columns; j++) {
            (*canvasArray)[i][j] = '*';
        }
    }
}

void displayCanvas(Canvas* canvas) {
    for (int i = canvas->rows - 1; i >= 0; i--) {
        printf("%d ", i);
        for (int j = 0; j < canvas->columns; j++) {
            printf("%c ", canvas->canvasArray[i][j]);
        }
        printf("\n");
    }
    printf("  ");
    for (int i = 0; i < canvas->columns; i++) {
        printf("%d ", i);
    }
    printf("\n");
}

void eraseCanvas(Canvas *canvas) {
    _freeCanvasArray(&(canvas->canvasArray), canvas->rows);
    canvas->rows = 0;
    canvas->columns = 0;
}

void _freeCanvasArray(char*** canvasArray, int rows) {
    for (int i = 0; i < rows; i++) {
        free((*canvasArray)[i]);
    }
    free(*canvasArray);
    *canvasArray = NULL;
}

void resizeCanvas(Canvas *canvas, int newRows, int newColumns) {
    char** newCanvasArray = NULL;
    _createCanvasArray(&newCanvasArray, newRows, newColumns);
    int loopRows = min(newRows, canvas->rows);
    int loopColumns = min(newColumns, canvas->columns);
    for (int i = 0; i < loopRows; i++) {
        for (int j = 0; j < loopColumns; j++) {
            newCanvasArray[i][j] = canvas->canvasArray[i][j];
        }
    }
    _freeCanvasArray(&(canvas->canvasArray), canvas->rows);
    canvas->rows = newRows;
    canvas->columns = newColumns;
    canvas->canvasArray = newCanvasArray;
}

void writeChar(Canvas *canvas, int row, int column, char ch) {
    if (canvas->canvasArray[row][column] == '*') {
        canvas->canvasArray[row][column] = ch;
    } else if (ch != canvas->canvasArray[row][column]) {
        canvas->canvasArray[row][column] = '+';
    }    
}

void eraseChar(Canvas *canvas, int row, int column) {
    canvas->canvasArray[row][column] = '*';
}

void addRow(Canvas* canvas, int newRow) {
    canvas->rows++;
    canvas->canvasArray = (char**) realloc(canvas->canvasArray, canvas->rows * sizeof(char*));
    canvas->canvasArray[canvas->rows - 1] = (char*) malloc(canvas->columns * sizeof(char*));
    for (int i = canvas->rows - 1; i > newRow; i--) {
        for (int j = 0; j < canvas->columns; j++) {
            canvas->canvasArray[i][j] = canvas->canvasArray[i - 1][j];
        }
    }
    for (int i = 0; i < canvas->columns; i++) {
        canvas->canvasArray[newRow][i] = '*';
    }
}

void deleteRow(Canvas* canvas, int oldRow) {
    for (int i = oldRow; i < canvas->rows - 1; i++) {
        for (int j = 0; j < canvas->columns; j++) {
            canvas->canvasArray[i][j] = canvas->canvasArray[i + 1][j];
        }
    }
    free(canvas->canvasArray[canvas->rows - 1]);
    canvas->rows--;
    canvas->canvasArray = (char**) realloc(canvas->canvasArray, canvas->rows * sizeof(char*));
}

void addColumn(Canvas *canvas, int newColumn) {
    canvas->columns++;
    for (int i = 0; i < canvas->rows; i++) {
        canvas->canvasArray[i] = (char*) realloc(canvas->canvasArray[i], canvas->columns * sizeof(char));
        for (int j = canvas->columns - 1; j > newColumn; j--) {
            canvas->canvasArray[i][j] = canvas->canvasArray[i][j - 1];
        }
        canvas->canvasArray[i][newColumn] = '*';
    }
}

void deleteColumn(Canvas *canvas, int oldColumn) {
    for (int i = 0; i < canvas->rows; i++) {
        for (int j = oldColumn; j < canvas->columns - 1; j++) {
            canvas->canvasArray[i][j] = canvas->canvasArray[i][j + 1];
        }
        canvas->canvasArray[i] = (char*) realloc(canvas->canvasArray[i], (canvas->columns - 1) * sizeof(char));
    }
    canvas->columns--;
}

void saveCanvas(Canvas* canvas, FILE* file) {
    fprintf(file, "%d %d\n", canvas->rows, canvas->columns);
    for (int i = 0; i < canvas->rows; i++) {
        for (int j = 0; j < canvas->columns; j++) {
            fprintf(file, "%c ", canvas->canvasArray[i][j]);
        }
        fprintf(file, "\n");
    }
}

void loadCanvas(Canvas* canvas, FILE* file) {
    _freeCanvasArray(&(canvas->canvasArray), canvas->rows);
    fscanf(file, "%d %d", &(canvas->rows), &(canvas->columns));
    _createCanvasArray(&(canvas->canvasArray), canvas->rows, canvas->columns);
    for (int i = 0; i < canvas->rows; i++) {
        for (int j = 0; j < canvas->columns; j++) {
            fscanf(file, " %c", &(canvas->canvasArray[i][j]));
        }
    }
}