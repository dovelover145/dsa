/*
A text-based version of paint, with various commands that the user can input to do various tasks.
*/

#include <stdio.h>
#include <stdlib.h>
#include "canvas.h"
#include "paint_functions.h"

// void canvasFunctionsTest();

int main(int argc, char* argv[]) {
    int rows;
    int columns;
    getCanvasDimensions(argc, argv, &rows, &columns);
    // printf("Rows: %d; Columns: %d\n", rows, columns);
    Canvas canvas;
    createCanvas(&canvas, rows, columns);
    simulate(&canvas);
    return 0;
}

/*
void canvasFunctionsTest() {
    Canvas canvas;
    
    printf("Creating a 9x9 canvas...\n");
    createCanvas(&canvas, 9, 9);
    displayCanvas(&canvas);
    printf("Rows: %d; Columns: %d\n", canvas.rows, canvas.columns);
    printf("\n");

    printf("Erasing the canvas...");
    eraseCanvas(&canvas);
    displayCanvas(&canvas);
    printf("Rows: %d; Columns: %d\n", canvas.rows, canvas.columns);
    printf("\n");

    printf("Creating a 5x5 canvas...\n");
    createCanvas(&canvas, 5, 5);
    displayCanvas(&canvas);
    printf("Rows: %d; Columns: %d\n", canvas.rows, canvas.columns);
    printf("\n");

    printf("Filling elements with 'X'...\n");
    writeChar(&canvas, 0, 0, 'X');
    writeChar(&canvas, 1, 1, 'X');
    writeChar(&canvas, 2, 2, 'X');
    writeChar(&canvas, 3, 3, 'X');
    writeChar(&canvas, 4, 4, 'X');
    displayCanvas(&canvas);
    printf("Rows: %d; Columns: %d\n", canvas.rows, canvas.columns);
    printf("\n");

    printf("Resizing the canvas to a 9x9 canvas...\n");
    resizeCanvas(&canvas, 9, 9);
    displayCanvas(&canvas);
    printf("Rows: %d; Columns: %d\n", canvas.rows, canvas.columns);
    printf("\n");

    printf("Resizing the canvas to a 4x4 canvas...\n");
    resizeCanvas(&canvas, 4, 4);
    displayCanvas(&canvas);
    printf("Rows: %d; Columns: %d\n", canvas.rows, canvas.columns);
    printf("\n");

    printf("Adding a row in the place of row 1...\n");
    addRow(&canvas, 1);
    displayCanvas(&canvas);
    printf("Rows: %d; Columns: %d\n", canvas.rows, canvas.columns);
    printf("\n");

    printf("Adding a new row (row 5)...\n");
    addRow(&canvas, 5);
    displayCanvas(&canvas);
    printf("Rows: %d; Columns: %d\n", canvas.rows, canvas.columns);
    printf("\n");

    printf("Deleting row 1...\n");
    deleteRow(&canvas, 1);
    displayCanvas(&canvas);
    printf("Rows: %d; Columns: %d\n", canvas.rows, canvas.columns);
    printf("\n");

    printf("Deleting row 4...\n");
    deleteRow(&canvas, 4);
    displayCanvas(&canvas);
    printf("Rows: %d; Columns: %d\n", canvas.rows, canvas.columns);
    printf("\n");

    printf("Adding a column in the place of column 1...\n");
    addColumn(&canvas, 1);
    displayCanvas(&canvas);
    printf("Rows: %d; Columns: %d\n", canvas.rows, canvas.columns);
    printf("\n");

    printf("Adding a new column (column 5)...\n");
    addColumn(&canvas, 5);
    displayCanvas(&canvas);
    printf("Rows: %d; Columns: %d\n", canvas.rows, canvas.columns);
    printf("\n");

    printf("Deleting column 1...\n");
    deleteColumn(&canvas, 1);
    displayCanvas(&canvas);
    printf("Rows: %d; Columns: %d\n", canvas.rows, canvas.columns);
    printf("\n");

    printf("Deleting column 4...\n");
    deleteColumn(&canvas, 4);
    displayCanvas(&canvas);
    printf("Rows: %d; Columns: %d\n", canvas.rows, canvas.columns);
    printf("\n");

    printf("Erasing all the 'X' characters...\n");
    eraseChar(&canvas, 0, 0);
    eraseChar(&canvas, 1, 1);
    eraseChar(&canvas, 2, 2);
    eraseChar(&canvas, 3, 3);
    eraseChar(&canvas, 4, 4);
    displayCanvas(&canvas);
    printf("Rows: %d; Columns: %d\n", canvas.rows, canvas.columns);
    printf("\n");

    printf("Erasing the canvas...");
    eraseCanvas(&canvas);
    displayCanvas(&canvas);
    printf("Rows: %d; Columns: %d\n", canvas.rows, canvas.columns);
}
*/