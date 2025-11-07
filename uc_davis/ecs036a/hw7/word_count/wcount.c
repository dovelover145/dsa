/*
Prints the number of words in a given file.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

void printNumOfWords(FILE* inFile);

int main(int argc, char* argv[]) {
    FILE* inFile = fopen(argv[1], "r");

    if (inFile == NULL) {
        return -1;
    }

    printNumOfWords(inFile);

    fclose(inFile);

    return 0;
}

/*
Prints the number of words specified in the file entered by the user in the command-line.
@param inFile: The file to read from.
@return: void.
*/
void printNumOfWords(FILE* inFile) {
    int bufferSize = 1; // Initial size of the dynamically-allocated character array that will hold the file contents
    int i = 0; // The current index
    char* buffer = (char *) malloc(bufferSize * sizeof(char)); // Holds the contents of the file
    char curChar = '\0'; // The current character read from the file
    bool prevWasSpace = false;
    int wordCount = 0;

    fscanf(inFile, "%c", &curChar);

    while (!feof(inFile)) {
        if (i == bufferSize) {
            bufferSize *= 2;
            buffer = (char *) realloc(buffer, bufferSize * sizeof(char));
        }
        if (!isspace(curChar) && i == 0) {
            wordCount++;
        } else if (prevWasSpace && !isspace(curChar)) {
            wordCount++;
            prevWasSpace = false;
        } else if (isspace(curChar)) {
            prevWasSpace = true;
        }
        buffer[i] = curChar;
        i++;
        fscanf(inFile, "%c", &curChar);
    }

    // buffer[i] = '\0';

    printf("There are %d word(s).\n", wordCount);

    free(buffer);
    buffer = NULL;
}