#ifndef PAINT_FUNCTIONS_H
#define PAINT_FUNCTIONS_H

/*
Gets the dimensions for the Canvas object.
@param argc: the number of arguments entered on the command line.
@param argv: an array of c-strings representing the arguments.
@param rows: will contain the number of rows of the Canvas object.
@param columns: will contain the number of columns of the Canvas object.
@return: void.
*/
void getCanvasDimensions(int argc, char* argv[], int* rows, int* columns);

/*
Asks for user input and executes commands until told not to.
@param canvas: a pointer to the Canvas object.
@return: void.
*/
void simulate(Canvas* canvas);

/*
Executes a command from the user.
@param canvas: a pointer to the Canvas object.
@param file: an input string representing the command line contents.
@return: void.
*/
void executeCommand(Canvas* canvas, char input[]);

/*
Quits the program.
@param canvas: a pointer to the Canvas object.
@return: void.
*/
void quit(Canvas* canvas);

/*
Displays help information.
@return: void.
*/
void help();

/*
Writes a line to the Canvas object.
@param canvas: a pointer to the Canvas object.
@param startRow: the row to start drawing from.
@param startColumn: the column to start drawing from.
@param endRow: the row to stop drawing at.
@param endColumn: the column to stop drawing at.
@return: void.
*/
void write(Canvas* canvas, int startRow, int startColumn, int endRow, int endColumn);

/*
Erases the character at the specified position in the Canvas object.
@param canvas: a pointer to the Canvas object.
@param row: the row number to erase from.
@param column: the column number to erase from.
@return: void.
*/
void erase(Canvas* canvas, int row, int column);

/*
Resizes the Canvas object to new dimensions.
@param canvas: a pointer to the Canvas object.
@param rows: the new number of rows of the Canvas object.
@param columns: the new number of columns of the Canvas object.
@return: void.
*/
void resize(Canvas* canvas, int rows, int columns);

/*
Adds a row or column to the Canvas object.
@param canvas: a pointer to the Canvas object.
@param rowOrColumn: specifies whether a row ('r') or column ('c') needs to be added.
@param position: the position of the new row or column.
@return: void.
*/
void add(Canvas* canvas, char rowOrColumn, int position);

/*
Deletes a row or column from the Canvas object.
@param canvas: a pointer to the Canvas object.
@param rowOrColumn: specifies whether a row ('r') or column ('c') needs to be deleted.
@param position: the position of the row or column to delete.
@return: void.
*/
void delete(Canvas* canvas, char rowOrColumn, int position);

/*
Saves a Canvas object to the specified file.
@param canvas: a pointer to the Canvas object.
@param fileName: a string representing the file name.
@return: void.
*/
void save(Canvas* canvas, char fileName[]);

/*
Loads from the specified file into the Canvas object.
@param canvas: a pointer to the Canvas object.
@param fileName: a string representing the file name to load the data from.
@return: void.
*/
void load(Canvas* canvas, char fileName[]);

#endif