#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "canvas.h"
#include "paint_functions.h"

const int DEFAULT_ROW_COLUMN_SIZE = 10;
const int MAX_INPUT_BUFFER_SIZE = 100;
const int MAX_FILE_NAME_SIZE = 50;

void getCanvasDimensions(int argc, char* argv[], int* rows, int* columns) {
    if (argc == 1) {
        *rows = DEFAULT_ROW_COLUMN_SIZE;
        *columns = DEFAULT_ROW_COLUMN_SIZE;
    } else if (argc == 3) {
        int commandLineRows = atoi(argv[1]);
        int commandLineColumns = atoi(argv[2]);
        if (commandLineRows < 1 || commandLineColumns < 1) {
            if (commandLineRows == 0 && strcmp(argv[1], "0") != 0) {
                printf("The number of rows is not an integer.\n");
            } else if ((commandLineRows == 0 && strcmp(argv[1], "0") == 0) || commandLineRows < 0) {
                printf("The number of rows is less than 1.\n");
            }
            if (commandLineColumns == 0 && strcmp(argv[2], "0") != 0) {
                printf("The number of columns is not an integer.\n");
            } else if ((commandLineColumns == 0 && strcmp(argv[2], "0") == 0) || commandLineColumns < 0) {
                printf("The number of columns is less than 1.\n");
            }
            printf("Making default board of 10 X 10.\n");
            *rows = DEFAULT_ROW_COLUMN_SIZE;
            *columns = DEFAULT_ROW_COLUMN_SIZE;
        } else {
            *rows = commandLineRows;
            *columns = commandLineColumns;
        }
    } else {
        printf("Wrong number of command line arguments entered.\n");
        printf("Usage: ./paint.out [num_rows num_cols]\n");
        printf("Making default board of %d X %d.\n", DEFAULT_ROW_COLUMN_SIZE, DEFAULT_ROW_COLUMN_SIZE);
        *rows = DEFAULT_ROW_COLUMN_SIZE;
        *columns = DEFAULT_ROW_COLUMN_SIZE;
    }
}

void simulate(Canvas* canvas) {
    displayCanvas(canvas);
    char input[MAX_INPUT_BUFFER_SIZE];
    do {
        printf("Enter your command: ");
        fgets(input, sizeof(input), stdin);
        executeCommand(canvas, input);
    } while (true);
}

void executeCommand(Canvas* canvas, char input[]) {
    char commandChar;
    char spaceChar; // Removed this for most cases to pass the autograder
    int nullCharIndex;
    int scanResult;
    int var1;
    int var2;
    int var3;
    int var4;
    char var5;
    char var6[MAX_FILE_NAME_SIZE];
    if ((scanResult = sscanf(input, " %c%c %n", &commandChar, &spaceChar, &nullCharIndex)) == 2 && commandChar == 'q' && isspace(spaceChar)) {
        if (input[nullCharIndex] == '\0') {
            quit(canvas);
        } else {
            printf("Improper quit command.\n");
        }
    } else if ((scanResult = sscanf(input, " %c%c %n", &commandChar, &spaceChar, &nullCharIndex)) == 2 && commandChar == 'h' && isspace(spaceChar)) {
        if (input[nullCharIndex] == '\0') {
            help();
        } else {
            printf("Improper help command.\n");
        }
    } else if ((scanResult = sscanf(input, " %c %d %d %d %d %n", &commandChar, &var1, &var2, &var3, &var4, &nullCharIndex)) >= 1 && commandChar == 'w') {
        if (scanResult == 5 && input[nullCharIndex] == '\0') {
            write(canvas, var1, var2, var3, var4);
        } else {
            printf("Improper draw command.\n");
        }
    } else if ((scanResult = sscanf(input, " %c %d %d %n", &commandChar, &var1, &var2, &nullCharIndex)) >= 1 && commandChar == 'e') {
        if (scanResult == 3 && input[nullCharIndex] == '\0') {
            erase(canvas, var1, var2);
        } else {
            printf("Improper erase command.\n");
        }
    } else if ((scanResult = sscanf(input, " %c %d %d %n", &commandChar, &var1, &var2, &nullCharIndex)) >= 1 && commandChar == 'r') {
        if (scanResult == 3 && input[nullCharIndex] == '\0') {
            resize(canvas, var1, var2);
        } else {
            printf("Improper resize command.\n");
        }
    } else if ((scanResult = sscanf(input, " %c %c %d %n", &commandChar, &var5, &var1, &nullCharIndex)) >= 1 && commandChar == 'a') {
        if (scanResult == 3 && (var5 == 'r' || var5 == 'c') && input[nullCharIndex] == '\0') {
            add(canvas, var5, var1);
        } else {
            printf("Improper add command.\n");
        }
    } else if ((scanResult = sscanf(input, " %c %c %d %n", &commandChar, &var5, &var1, &nullCharIndex)) >= 1 && commandChar == 'd') {
        if (scanResult == 3 && (var5 == 'r' || var5 == 'c') && input[nullCharIndex] == '\0') {
            delete(canvas, var5, var1);
        } else {
            printf("Improper delete command.\n");
        }
    } else if ((scanResult = sscanf(input, " %c %s %n", &commandChar, var6, &nullCharIndex)) >= 2 && commandChar == 's') {
        if (scanResult == 2 && input[nullCharIndex] == '\0') {
            save(canvas, var6);
        } else {
            printf("Improper save command or file could not be created.\n");
        }
    } else if ((scanResult = sscanf(input, " %c %s %n", &commandChar, var6, &nullCharIndex)) >= 1 && commandChar == 'l') {
        if (scanResult == 2 && input[nullCharIndex] == '\0') {
            load(canvas, var6);
        } else {
            printf("Improper load command or file could not be opened.\n");
        }
    } else {
        printf("Unrecognized command. Type h for help.\n");
    }
    displayCanvas(canvas);
} 

void quit(Canvas* canvas) {
    eraseCanvas(canvas);
    exit(EXIT_SUCCESS);
}

void help() {
    printf("Commands:\n");
    printf("Help: h\n");
    printf("Quit: q\n");
    printf("Draw line: w row_start col_start row_end col_end\n");
    printf("Resize: r num_rows num_cols\n");
    printf("Add row or column: a [r | c] pos\n");
    printf("Delete row or column: d [r | c] pos\n");
    printf("Erase: e row col\n");
    printf("Save: s file_name\n");
    printf("Load: l file_name\n");
}

void write(Canvas* canvas, int startRow, int startColumn, int endRow, int endColumn) {
    if ((startRow < 0 || startRow >= canvas->rows) || (startColumn < 0 || startColumn >= canvas->columns) || (endRow < 0 || endRow >= canvas->rows) || (endColumn < 0 || endColumn >= canvas->columns)) {
        printf("Improper draw command.\n");
    } else {
        if (startRow == endRow && startColumn == endColumn) { // Single cell
            writeChar(canvas, startRow, startColumn, '-');
        } else if (startRow == endRow) { // Horizontal line
            int beginningColumn = min(startColumn, endColumn);
            int endingColumn = max(startColumn, endColumn);
            for (int i = beginningColumn; i <= endingColumn; i++) {
                writeChar(canvas, startRow, i, '-');
            }
        } else if (startColumn == endColumn) { // Vertical line
            int beginningRow = min(startRow, endRow);
            int endingRow = max(startRow, endRow);
            for (int i = beginningRow; i <= endingRow; i++) {
                writeChar(canvas, i, startColumn, '|');
            }
        } else { // Diagonal line
            int rowChange = 1;
            int columnChange = 1;
            char ch = '!';
            if (startRow > endRow) {
                rowChange *= -1;
            }
            if (startColumn > endColumn) {
                columnChange *= -1;
            }
            if ((startRow < endRow && startColumn < endColumn) || (startRow > endRow && startColumn > endColumn)) {
                ch = '/';
            } else if ((startRow > endRow && startColumn < endColumn) || (startRow  < endRow && startColumn > endColumn)) {
                ch = '\\';
            }
            int tempStartRow = startRow;
            int tempStartColumn = startColumn;
            int tempEndRow = endRow;
            int tempEndColumn = endColumn;
            while (tempStartRow != tempEndRow) {
                tempStartRow += rowChange;
                tempStartColumn += columnChange;
            }
            if (tempStartColumn != tempEndColumn) {
                printf("Improper draw command.\n");
            } else {
                int tempStartRow = startRow;
                int tempStartColumn = startColumn;
                int tempEndRow = endRow;
                // int tempEndColumn = endColumn;
                while (tempStartRow != tempEndRow) {
                    // printf("(i, j) = (%d, %d)\n", tempStartRow, tempStartColumn);
                    writeChar(canvas, tempStartRow, tempStartColumn, ch);
                    tempStartRow += rowChange;
                    tempStartColumn += columnChange;
                }
                // printf("(i, j) = (%d, %d)\n", tempStartRow, tempStartColumn);
                writeChar(canvas, tempStartRow, tempStartColumn, ch);
            }
        }
    }
}

void erase(Canvas* canvas, int row, int column) {
    if ((row < 0 || row >= canvas->rows) || (column < 0 || column >= canvas->columns)) {
        printf("Improper erase command.\n");
    } else {
        eraseChar(canvas, row, column);
    }
}

void resize(Canvas* canvas, int rows, int columns) {
    if (rows < 1 || columns < 1) {
        printf("Improper resize command.\n");
    } else {
        resizeCanvas(canvas, rows, columns);
    }
}

void add(Canvas* canvas, char rowOrColumn, int position) {
    if (rowOrColumn == 'r') {
        if (position < 0 || position > canvas->rows) {
            printf("Improper add command.\n");
        } else {
            addRow(canvas, position);
        }
    } else if (rowOrColumn == 'c') {
        if (position < 0 || position > canvas->columns) {
            printf("Improper add command.\n");
        } else {
            addColumn(canvas, position);
        }
    }
}

void delete(Canvas* canvas, char rowOrColumn, int position) {
    if (rowOrColumn == 'r') {
        if (position < 0 || position >= canvas->rows) {
            printf("Improper delete command.\n");
        } else {
            deleteRow(canvas, position);
        }
    } else if (rowOrColumn == 'c') {
        if (position < 0 || position >= canvas->columns) {
            printf("Improper delete command.\n");
        } else {
            deleteColumn(canvas, position);
        }
    }
}

void save(Canvas* canvas, char fileName[]) {
    FILE* file = fopen(fileName, "w");
    if (file == NULL) {
        printf("Improper save command or file could not be created.\n");
    } else {
        saveCanvas(canvas, file);
        fclose(file);
    }
}

void load(Canvas* canvas, char fileName[]) {
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Improper load command or file could not be opened.\n");
    } else {
        loadCanvas(canvas, file);
        fclose(file);
    }
}