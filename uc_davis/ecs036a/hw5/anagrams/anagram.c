/*
Prints whether two strings are anagrams of each other (case-insensitive).
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void printResult(const char w1[], const char w2[]);

int main() {
    char w1[21]; // 20 characters, and 1 null character
    char w2[21];
    
    printf("Please enter the first word: ");
    scanf("%s", w1);

    printf("Please enter the second word: ");
    scanf("%s", w2);

    printResult(w1, w2);

    return 0;
}

/*
Prints whether the strings are anagrams of each other (case-insensitive).
@param w1: The first string.
@param w2: The second string.
*/
void printResult(const char w1[], const char w2[]) {
    if (strlen(w1) == strlen(w2)) {
        char wl1[21];
        char wl2[21];
        char curChar;
        int count1 = 0;
        int count2 = 0;

        int i = 0;
        for (i = 0; w1[i] != '\0'; i++) {
            wl1[i] = tolower(w1[i]);
            wl2[i] = tolower(w2[i]);
        }

        wl1[i] = '\0';
        wl2[i] = '\0';

        for (i = 0; wl1[i] != '\0'; i++) {
            curChar = wl1[i];
            for (int j = 0; wl1[j] != '\0'; j++) {
                if (wl1[j] == curChar) {
                    count1++;
                }
                if (wl2[j] == curChar) {
                    count2++;
                }
            }
            if (count1 != count2) {
                printf("%s is NOT an anagram of %s\n", w1, w2);
                break;
            }

            count1 = 0;
            count2 = 0;
        }

        if (count1 == count2) {
            printf("%s is an anagram of %s\n", w1, w2);
        }
    } else {
        printf("%s is NOT an anagram of %s\n", w1, w2);
    }
}