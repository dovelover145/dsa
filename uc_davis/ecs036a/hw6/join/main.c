#include <stdio.h>
#include <stdlib.h>

#include "string_helpers.h"

void print_strings(char** strings, int num_strings);
void delete_strings(char** strings, int num_strings);
char** read_in_lines(int num_lines);

void print_strings(char** strings, int num_strings) {
    for (int i = 0; i < num_strings; ++i) {
        printf("%d. %s\n", i + 1, strings[i]);
    }
}

void delete_strings(char** strings, int num_strings) {
    for (int i = 0; i < num_strings; ++i) {
        free(strings[i]);
    }
    free(strings);
}

char** read_in_lines(int num_lines) {
    char** lines = calloc(num_lines, sizeof(char*));

    for (int i = 0; i < num_lines; ++i) {
        printf("Enter line %d: ", i + 1);
        lines[i] = read_any_len_line();
    }
    return lines;
}

int main() {
    char** strings;
    int num_strings;

    char* seperator;
    char* joined_string;

    printf("How many strings will you enter: ");
    scanf("%d", &num_strings);
    // get rid of any extra whitespace on the first line
    joined_string = read_any_len_line();
    free(joined_string);

    strings = read_in_lines(num_strings);

    printf("Enter the string to join on: ");
    seperator = read_any_len_line();

    joined_string = join(strings, num_strings, seperator);

    delete_strings(strings, num_strings);

    printf("Your final string is: %s\n", joined_string);

    free(joined_string);
    free(seperator);
    return 0;
}