#ifndef CANVAS_H
#define CANVAS_H

/*
rows: holds the number of rows.
columns: holds the number of columns.
canvasArray: stores the canvas as a double array.
*/
typedef struct Canvas_struct {
    int rows;
    int columns;
    char** canvasArray;
} Canvas;

/*
Finds the minimum of two integers.
@param a: the first integer.
@param b: the second integer.
@return: the smaller integer.
*/
int min(int a, int b);

/*
Finds the maximum of two integers.
@param a: the first integer.
@param b: the second integer.
@return: the larger integer.
*/
int max(int a, int b);

/*
Creates a canvas in the specified Canvas object with the given dimensions.
@param canvas: a pointer to a Canvas object.
@param rows: the number of rows in the canvas.
@param columns: the number of columns in the canvas.
@return: void.
*/
void createCanvas(Canvas* canvas, int rows, int columns);

/*
A helper function that creates a canvas array using the given pointer.
@param canvasArray: a pointer to a pointer to what will be the canvas array.
@param rows: the number of rows in the canvas.
@param columns: the number of columns in the canvas.
@return: void.
*/
void _createCanvasArray(char*** canvasArray, int rows, int columns);

/*
Displays the Canvas object.
@param canvas: a pointer to the Canvas object to display.
@return: void.
*/
void displayCanvas(Canvas* canvas);

/*
Erases the Canvas object.
@param canvas: a pointer to the Canvas object to erase.
@return: void.
*/
void eraseCanvas(Canvas *canvas);

/*
A helper function that frees the canvas array using the given pointer.
@param canvasArray: a pointer to the pointer to the canvas array.
@param rows: the number of rows in the canvas.
@return: void.
*/
void _freeCanvasArray(char*** canvasArray, int rows);

/*
Resizes the Canvas object.
@param canvas: a pointer to the Canvas object.
@param rows: the number of new rows in the canvas.
@param columns: the number of new columns in the canvas.
@return: void.
*/
void resizeCanvas(Canvas *canvas, int rows, int columns);

/*
Writes a character to the Canvas object at the specified location.
@param canvas: a pointer to the Canvas object.
@param rows: the row number to write the character to.
@param columns: the column number to write the character to.
@return: void.
*/
void writeChar(Canvas *canvas, int row, int column, char ch);

/*
Erases a character in the Canvas object at the specified location.
@param canvas: a pointer to the Canvas object.
@param rows: the row number to erase the character from.
@param columns: the column number to erase the character from.
@return: void.
*/
void eraseChar(Canvas *canvas, int row, int column);

/*
Adds a row to the Canvas object.
@param canvas: a pointer to the Canvas object.
@param newRow: the new row number to insert the row at.
@return: void.
*/
void addRow(Canvas* canvas, int newRow);

/*
Deletes a row from the Canvas object.
@param canvas: a pointer to the Canvas object.
@param oldRow: the row number specifying the row to delete.
@return: void.
*/
void deleteRow(Canvas* canvas, int oldRow);

/*
Adds a column to the Canvas object.
@param canvas: a pointer to the Canvas object.
@param newColumn: the new column number to insert the column at.
@return: void.
*/
void addColumn(Canvas *canvas, int newColumn);

/*
Deletes a column from the Canvas object.
@param canvas: a pointer to the Canvas object.
@param oldColumn: the column number specifying the column to delete.
@return: void.
*/
void deleteColumn(Canvas *canvas, int oldColumn);

/*
Saves the Canvas object to a file.
@param canvas: a pointer to the Canvas object.
@param file: a pointer to a FILE object representing the file to write to.
@return: void.
*/
void saveCanvas(Canvas* canvas, FILE* file);

/*
Loads the necessary data into the Canvas object from a file.
@param canvas: a pointer to the Canvas object to read into.
@param file: a pointer to a FILE object representing the file to read from.
@return: void.
*/
void loadCanvas(Canvas* canvas, FILE* file);

#endif