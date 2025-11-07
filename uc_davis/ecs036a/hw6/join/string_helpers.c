#include "string_helpers.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* join(char** strings, int num_strings, char* seperator) {
    /*
    Create a new string by joining all of the strings in strings together
    with seperator between each string. If num_strings is <= 0
    returns the empty string.

    @param strings: The strings to join together
    @param num_strings: The number of strings to join together
    @param seperator: The string to place between each string
    @returns: a new string with seperator between each string in strings
    */
    if (num_strings <= 0) {
        return "";
    }
    int sepStrLen = strlen(seperator);
    int curStrLen = 0;
    int joinedStrIndex = 0;
    char* joinedStr = (char*)malloc(sizeof(char) * (joinedStrIndex + 1));
    for (int i = 0; i < num_strings - 1; i++) {
        curStrLen = strlen(strings[i]);
        joinedStr = (char*)realloc(
            joinedStr,
            sizeof(char) * ((joinedStrIndex + 1) + curStrLen + sepStrLen));
        for (int j = 0; j < curStrLen; j++) {
            joinedStr[joinedStrIndex] = strings[i][j];
            joinedStrIndex++;
        }
        for (int j = 0; j < sepStrLen; j++) {
            joinedStr[joinedStrIndex] = seperator[j];
            joinedStrIndex++;
        }
    }
    curStrLen = strlen(strings[num_strings - 1]);
    joinedStr = (char*)realloc(
        joinedStr, sizeof(char) * ((joinedStrIndex + 1) + curStrLen));
    for (int i = 0; i < curStrLen; i++) {
        joinedStr[joinedStrIndex] = strings[num_strings - 1][i];
        joinedStrIndex++;
    }
    joinedStr[joinedStrIndex] = '\0';
    return joinedStr;
}

char* read_any_len_line() {
    /*
    Read a line of any length from the user input.
    The newline character, while read, is not included in the returned string.
    @returns: The next line of characters from the input stream
    @modifies: stdin
    */
    int i = 0;
    char* line = (char*)malloc(sizeof(char) * (i + 1));
    char curChar = '\0';
    scanf("%c", &curChar);
    while (curChar != '\n') {
        line = (char*)realloc(line, sizeof(char) * ((i + 1) + 1));
        line[i] = curChar;
        i++;
        scanf("%c", &curChar);
    }
    line[i] = '\0';
    return line;
}