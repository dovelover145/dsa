/*
Finds out whether a string exists within another string and gives the index of the first letter of where it occurs.
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool startsAtIndex(char searchString[], char searchTerm[], int searchStringIndex);

int main() {
    char searchString[101];
    char searchTerm[101];

    printf("Enter the string to search: ");
    fgets(searchString, 101, stdin);
    searchString[strlen(searchString) - 1] = '\0';

    printf("Enter the substring to search for: ");
    fgets(searchTerm, 101, stdin);
    searchTerm[strlen(searchTerm) - 1] = '\0';

    if (strlen(searchTerm) == 0) {
        printf("\"\" first appears at index 0 in \"%s\".\n", searchString);
        return 0;
    }

    int index = -1;
    for (int i = 0; searchString[i] != '\0'; i++) {
        if (startsAtIndex(searchString, searchTerm, i)) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("\"%s\" does not appear in \"%s\".\n", searchTerm, searchString);
    } else {
        printf("\"%s\" first appears at index %d in \"%s\".\n", searchTerm, index, searchString);
    }
}

/*
Finds out if searchStringIndex is the first element in searchString containing searchTerm.
@param searchString: string of characters to search in.
@param searchTerm: string of characters to search for.
@param searchStringIndex: starting index to search from in searchString.
@return: bool; true if found, and false otherwise.
*/
bool startsAtIndex(char searchString[], char searchTerm[], int searchStringIndex) {
    int searchTermIndex = 0;
    for (int i = searchStringIndex; searchString[i] != '\0'; i++) {
        if (searchTerm[searchTermIndex] == '\0') {
            return true;
        }
        if (searchString[i] != searchTerm[searchTermIndex]) {
            return false;
        }
        searchTermIndex++;
    }
    return searchTerm[searchTermIndex] == '\0';
}