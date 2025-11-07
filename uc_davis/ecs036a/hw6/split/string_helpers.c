#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "string_helpers.h"

void split(char* string, const char* const delimiter, char** *splits, int *len) {
    /*
    Split string on delimiter into an array of strings.
    @param string: the string to split
    @param delimiter: the delimiter to split on
    @output_param splits: The output array to store the strings 
    into. Assume the value at *splits is uninitialized.   
    @output_param len: The number of strings in splits.
    Assume the value at *len is uninitialized.
    */
    *splits = NULL;
    *len = 0;
    int strLen = strlen(string);
    int delimLen = strlen(delimiter);
    int maxIterations = strLen - delimLen + 1;
    int beginningIndex = 0;
    for (int i = 0; i < maxIterations; i++) {
        if (matches(i, string, delimiter)) {
            // if (i > beginningIndex) {
                *len += 1;
                *splits = (char**) realloc(*splits, *len * sizeof(char*));
                (*splits)[*len - 1] = createString(string, beginningIndex, i - 1);
            // }
            i += delimLen - 1;
            beginningIndex = i + 1;
        }
    }
    // if (strLen - 1 >= beginningIndex) {
        *len += 1;
        *splits = (char**) realloc(*splits, *len * sizeof(char*));
        (*splits)[*len - 1] = createString(string, beginningIndex, strLen - 1);
    // }
}

bool matches(int i, char* string, const char* const delimiter) {
    int strIndex = i;
    int delimLen = strlen(delimiter);
    for (int delimIndex = 0; delimIndex < delimLen; delimIndex++) {
        if (string[strIndex] != delimiter[delimIndex]) {
            return false;
        }
        strIndex++;
    }
    return true;
}

char* createString(char* string, int beginningIndex, int endingIndex) {
    char* newString = (char*) malloc((endingIndex - beginningIndex + 2) * sizeof(char));
    int newStrIndex = 0;
    for (int i = beginningIndex; i <= endingIndex; i++) {
        newString[newStrIndex] = string[i];
        newStrIndex++;
    }
    newString[newStrIndex] = '\0';
    return newString;
}

char* read_any_len_line() {
    /*
    Read a line of any length from the user input. 
    @returns: The next line of characters from the input stream.
    The newline character, while read, is not included in the returned string.
    @modifies: stdin
    */
    int i = 0;
    char* line = (char*) malloc(sizeof(char) * (i + 1));
    char curChar = '\0';
    scanf("%c", &curChar);
    while (curChar != '\n') {
        line = (char*) realloc(line, sizeof(char) * ((i + 1) + 1));
        line[i] = curChar;
        i++;
        scanf("%c", &curChar);
    }
    line[i] = '\0';
    return line;
}