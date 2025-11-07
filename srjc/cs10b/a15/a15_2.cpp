/*
Ibrahim Siddiqui
CS10B
Assignment 15.2
Instructor David Harden

This program has a recursive function isAPalindrome that checks whether a MyString object is a palindrome. 
*/

#include <iostream>
#include "mystring.h"
using namespace std;
using namespace cs_mystring;

bool isAPalindrome(MyString string, int lowerBound, int upperBound);

int main() {
    MyString string;
    cout << "Enter a string: ";
    cin >> string;
    while (string != "quit") {
        if (isAPalindrome(string, 0, string.length() - 1)) {
            cout << string << " is a palindrome." << endl;
        } else {
            cout << string << " is not a palindrome." << endl;
        }
        cout << "Enter a string: ";
        cin >> string;
    }
}




// determines whether c-string is palindrome
bool isAPalindrome(MyString string, int lowerBound, int upperBound) {
    if (lowerBound > upperBound) {
        return true;
    } else {
        while (isspace(string[lowerBound]) || ispunct(string[lowerBound]) || isspace(string[upperBound]) || ispunct(string[upperBound])) {
            if (isspace(string[lowerBound]) || ispunct(string[lowerBound])) {
                lowerBound++;
            }
            if (isspace(string[upperBound]) || ispunct(string[upperBound])) {
                upperBound--;
            }
        }
        if (toupper(string[lowerBound]) != toupper(string[upperBound])) {
            return false;
        }
        bool result = isAPalindrome(string, lowerBound + 1, upperBound - 1);
        return result;
    }
}

/*
Output:
Enter a string: Able was I, ere I saw Elba
Able was I, ere I saw Elba is a palindrome.
Enter a string: peanut butter
peanut butter is not a palindrome.
Enter a string: l.o o $$ ool
l.o o $$ ool is a palindrome.
Enter a string: biob
biob is not a palindrome.
Enter a string: Hannah
Hannah is a palindrome.
Enter a string: lol
lol is a palindrome.
Enter a string: quit
Program ended with exit code: 0
*/