#include <stdio.h>
#include <string.h>
#include <ctype.h>

void printAll(char binString[], int strlen, int index);

int main(int argc, char* argv[]) {
    printAll(argv[1], strlen(argv[1]), 0);
    return 0;
}

void printAll(char binString[], int strlen, int index) {
    if (index == strlen) {
        printf("%s\n", binString);
    } else {
        if (tolower(binString[index]) == 'x') {
            binString[index] = '0';
            printAll(binString, strlen, index + 1);
            binString[index] = 'x';

            binString[index] = '1';
            printAll(binString, strlen, index + 1);
            binString[index] = 'x';
        } else {
            printAll(binString, strlen, index + 1);
        }
    }
}