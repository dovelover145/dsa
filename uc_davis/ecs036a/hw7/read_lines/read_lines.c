#include "read_lines.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void read_lines(FILE* fp, char*** lines, int* num_lines) {
    /*
    read all of the lines in fp into lines and set num_lines to be the total
    number of lines in the file.
    @fp: a file pointer opened in read mode
    @lines: a pointer indicating where the lines should be placed. If there
    are no lines in a fill, lines will be set to NULL
    @num_lines: a pointer to the number of lines. set to the number of lines
    contained within lines
    @modifies: lines, num_lines
    */

    *lines = NULL;
    int lineSize = 0;
    *num_lines = 0;
    bool newLine = true;
    bool first = true;
    char curChar;

    while ((curChar = fgetc(fp)) != EOF) {
        // printf("Char: %c\n", curChar);
        if (newLine && first) {
            lineSize = 0;
            (*num_lines)++;
            newLine = false;
            first = false;
            *lines = (char**)malloc(*num_lines * sizeof(char*));
            lineSize++;
            (*lines)[*num_lines - 1] = (char*)malloc(lineSize * sizeof(char));
        } else if (newLine) {
            lineSize = 0;
            newLine = false;
            (*num_lines)++;
            *lines = (char**)realloc(*lines, (*num_lines) * sizeof(char*));
            lineSize++;
            (*lines)[*num_lines - 1] = (char*)malloc(lineSize * sizeof(char));
        } else {
            lineSize++;
            (*lines)[*num_lines - 1] = (char*)realloc((*lines)[*num_lines - 1],
                                                      lineSize * sizeof(char));
        }
        if (curChar == '\n') {
            (*lines)[*num_lines - 1][lineSize - 1] = curChar;
            lineSize++;
            // printf("Here\n");
            (*lines)[*num_lines - 1] = (char*)realloc((*lines)[*num_lines - 1],
                                                      lineSize * sizeof(char));
            (*lines)[*num_lines - 1][lineSize - 1] = '\0';
            // printf("Char: %c\n", (*lines)[*num_lines - 1][lineSize - 1]);
            newLine = true;
            // lineSize = 0;
        } else {
            (*lines)[*num_lines - 1][lineSize - 1] = curChar;
        }
        // printf("Done\n");
    }

    if (*lines != NULL && (*lines)[*num_lines - 1][lineSize - 1] != '\0') {
        // printf("WA\n");
        lineSize++;
        (*lines)[*num_lines - 1] =
            (char*)realloc((*lines)[*num_lines - 1], lineSize * sizeof(char));
        (*lines)[*num_lines - 1][lineSize - 1] = '\0';
    }
}