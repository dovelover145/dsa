/*
Ibrahim Siddiqui
CS 10B
Assignment 6.1
February 25, 2022

This program contains a number of functions that recieve a c-string argument and perform various tasks. The lastIndexOf function finds the last index of a specific character in the c-string, while the reverse function reverses the order of the elements in the c-string. The replace function finds a specific character in the c-string and swaps it with a different character. The isPalindrome function checks whether a c-string is a palindrome or not (no sensitivity to case) and the toUpper function changes the c-string to all caps. The last function, numLetters, returns the number of letters in the c-string. All these functions are tested through the main function, and the output writes the results of the tests.
*/

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std; 

int lastIndexOf(const char *inString, char target);
void reverse(char *inString);
int replace(char *inString, char target, char replacementChar);
bool isPalindrome(const char *inString);
void toUpper(char *inString);
int numLetters(const char *inString);

int main() {
    
    char ch[] = "Flower";
    char ch2[] = "Louisiana";
    char ch3[] = "Supercalifragilisticexpialidocious";
    
    // this code tests the lastIndexOf function
    cout << "This code checks whether the lastIndexOf function works or not." << endl;
    int a = lastIndexOf(ch, 'F');
    cout << "Index of 'F' in " << ch << ": " << a << endl;
    int b = lastIndexOf(ch2, 'i');
    cout << "Index of 'i' in " << ch2 << ": " << b << endl;
    int c = lastIndexOf(ch3,'Q');
    cout << "Index of 'Q' in " << ch3 << ": " << c << endl << endl;
    
    // this code tests the reverse function
    cout << "This code checks whether the reverse function works or not." << endl;
    cout << "Word: " << ch << endl;
    reverse(ch);
    cout << "Reversed: " << ch << endl;
    cout << "Word: " << ch2 << endl;
    reverse(ch2);
    cout << "Reversed: " << ch2 << endl;
    cout << "Word: " << ch3 << endl;
    reverse(ch3);
    cout << "Reversed: " << ch3 << endl << endl;
    
    // this code tests the replace function
    cout << "This code checks whether the reverse function works or not." << endl;
    cout << "Replace 'i' in " << ch2 << " with '$': ";
    int num = replace(ch2, 'i', '$');
    cout << ch2 << ". Replacements: " << num << "." << endl;
    cout << "Replace 'a' in " << ch2 << " with '%': ";
    int num1 = replace(ch2, 'a', '%');
    cout << ch2 << ". Replacements: " << num1 << "." << endl;
    cout << "Replace '@' in " << ch2 << " with 'Q': ";
    int num2 = replace(ch2, '@', 'Q');
    cout << ch2 << ". Replacements: " << num2 << "." << endl << endl;
    
    // this code tests the isPalindrome function
    cout << "This code checks whether the isPalindome function works or not." << endl;
    cout << "1AbbA1 (0 = false): ";
    bool bo = isPalindrome("1AbbA1");
    cout << bool(bo) << endl;
    cout << "Bobby (0 = false): ";
    bool bo1 = isPalindrome("Bobby");
    cout << bool(bo1) << endl;
    cout << "quiooiuQ (0 = false): ";
    bool bo2 = isPalindrome("quiooiuQ");
    cout << bool(bo2) << endl << endl;
    
    // this code tests the toUpper function
    cout << "This code checks whether the toUpper function works or not." << endl;
    cout << "Make " << ch3 << " uppercase: ";
    toUpper(ch3);
    cout << ch3 << endl;
    cout << "Make " << ch << " uppercase: ";
    toUpper(ch);
    cout << ch << endl << endl;
    
    // this code tests the numLetters function
    cout << "This code checks whether the numLetters function works or not." << endl;
    cout << "Number of letters in " << ch << ": ";
    int num3 = numLetters(ch);
    cout << num3 << endl;
    cout << "Number of letters in " << ch2 << ": ";
    int num4 = numLetters(ch2);
    cout << num4 << endl;
    cout << "Number of letters in " << ch3 << ": ";
    int num5 = numLetters(ch3);
    cout << num5 << endl;
}





// this function finds the last index of the target character in the string
int lastIndexOf(const char *inString, char target) {
    
    int indexOfChar = -1;  // variable that holds the target char's index
    int count = 0;
    
    while (inString[count] != '\0') {
        if (inString[count] == target) {
            indexOfChar = count;
        }
        count++;
    }
    return indexOfChar;
}





// this function reverses the string
void reverse(char *inString) {
    
    int n = 0; // variable that holds the index of the null terminator
    
    while (inString[n] != '\0') {
        n++;
    }
    
    for (int i = 0; i < n / 2; i++) {
        swap(inString[i], inString[(n - 1) - i]);
    }
}





// this function replaces a specific character in a string with another character
int replace(char *inString, char target, char replacementChar) {
    
    int numOfRep = 0;
    int count = 0;
    
    while (inString[count] != '\0') {
        if (inString[count] == target) {
            inString[count] = replacementChar;
            numOfRep++;
        }
        count++;
    }
    return numOfRep;
}





// this function determines whether the string is a palindrome
bool isPalindrome(const char *inString) {
    
    int l = strlen(inString); // holds length of the string
    
    for (int i = 0; i < l / 2; i++) {
        if (tolower(inString[i]) != tolower(inString[(l - 1) - i])) {
            return false;
        }
    }
    return true;
}





// this function changes the string to all caps
void toUpper(char *inString) {
    
    int count = 0;
    
    while (inString[count] != '\0') {
        inString[count] = toupper(inString[count]);
        count++;
    }
}





// this function returns the number of letters in the string
int numLetters(const char *inString) {
    
    int count = 0;
    int letters = 0;
    
    while (inString[count] != '\0') {
        if (isalpha(inString[count])) {
            letters++;
        }
        count++;
    }
    return letters;
}

/*
Output:
This code checks whether the lastIndexOf function works or not.
Index of 'F' in Flower: 0
Index of 'i' in Louisiana: 5
Index of 'Q' in Supercalifragilisticexpialidocious: -1

This code checks whether the reverse function works or not.
Word: Flower
Reversed: rewolF
Word: Louisiana
Reversed: anaisiuoL
Word: Supercalifragilisticexpialidocious
Reversed: suoicodilaipxecitsiligarfilacrepuS

This code checks whether the reverse function works or not.
Replace 'i' in anaisiuoL with '$': ana$s$uoL. Replacements: 2.
Replace 'a' in ana$s$uoL with '%': %n%$s$uoL. Replacements: 2.
Replace '@' in %n%$s$uoL with 'Q': %n%$s$uoL. Replacements: 0.

This code checks whether the isPalindome function works or not.
1AbbA1 (0 = false): 1
Bobby (0 = false): 0
quiooiuQ (0 = false): 1

This code checks whether the toUpper function works or not.
Make suoicodilaipxecitsiligarfilacrepuS uppercase: SUOICODILAIPXECITSILIGARFILACREPUS
Make rewolF uppercase: REWOLF

This code checks whether the numLetters function works or not.
Number of letters in REWOLF: 6
Number of letters in %n%$s$uoL: 5
Number of letters in SUOICODILAIPXECITSILIGARFILACREPUS: 34
Program ended with exit code: 0
*/