#ifndef STRING_HELPERS_H
#define STRING_HELPERS_H

#include <stdbool.h>

void split(char* string, const char* const delimiter, char** *splits, int *len);
bool matches(int i, char* string, const char* const delimiter);
char* createString(char* string, int beginningIndex, int endingIndex);
char* read_any_len_line();

#endif