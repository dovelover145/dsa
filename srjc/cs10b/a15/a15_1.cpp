/*
Ibrahim Siddiqui
CS10B
Assignment 15.1
Instructor David Harden

This program has a recursive function reverseWithinBounds that takes a c-string and reverses the order of it within the bounds provided.
*/

#include <iostream>
#include <cstring>
using namespace std;

void reverseWithinBounds(char ch[], int lowerBound, int upperBound);
void reverseCstring(char ch[]);

int main() {
    char ch[] = "Switch this c-string.";
    char ch2[] = "Now switch this one.";
    char ch3[] = "One last time.";
    cout << "Now testing the reverseWithinBounds function with indices 2 and 7." << endl << endl;
    cout << ch << ": ";
    reverseWithinBounds(ch, 2, 7);
    cout << ch << endl;
    cout << ch2 << ": ";
    reverseWithinBounds(ch2, 2, 7);
    cout << ch2 << endl;
    cout << ch3 << ": ";
    reverseWithinBounds(ch3, 2, 7);
    cout << ch3 << endl << endl;
    
    char ch4[] = "Switch this!";
    cout << "Now testing the reverseCstring function." << endl;
    cout << ch4 << ": ";
    reverseCstring(ch4);
    cout << ch4 << endl;
}




// reverses c-string within the bounds
void reverseWithinBounds(char ch[], int lowerBound, int upperBound) {
    if (lowerBound < upperBound) {
        swap(ch[lowerBound], ch[upperBound]);
        reverseWithinBounds(ch, lowerBound + 1, upperBound - 1);
    }
}

/*
if (lowerBound >= upperBound) {
    ;
} else if {
*/



// reverses entire c-string
void reverseCstring(char ch[]) {
    reverseWithinBounds(ch, 0, ((int) strlen(ch)) - 1);
}

/*
Output:
Now testing the reverseWithinBounds function with indices 2 and 7.

Switch this c-string.: Swt hctihis c-string.
Now switch this one.: Notiws wch this one.
One last time.: Ontsal e time.

Now testing the reverseCstring function.
Switch this!: !siht hctiwS
Program ended with exit code: 0
*/