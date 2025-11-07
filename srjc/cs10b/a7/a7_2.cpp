/*
Ibrahim Siddiqui
CS10B
Assignment 7.2
March 5, 2022

This program counts the occurrences of letters (not case sensitive) in the user input. It uses an array of Letter structs (where the struct contains a char variable holding the letter and an int variable "count" that holds the number of times that letter of the alphabet occurs in the user input). The array's structs' char variables are initialized with a function that goes through and puts a letter of the alphabet in each struct of the array, starting with 'A' and ending with 'Z' (the array's size is 26, i.e. the size of the alphabet). The user input that is read is terminated by a period. Another function, countLetter, receives a single character from the input stream, finds where that character is stored in the structs of the array, and increments the count of that letter in that struct. This continues until a period is reached, which lets the program know that there is nothing more to be read. Another function sorts the contents of the array with letters occurring more frequently taking the beginning spots of the array. The contents of the sorted array are then displayed via the displayData function. The screen output shows the number of letters that occurred from the greatest frequency to the least. Letters that did not occur are left out.
*/

#include <iostream>
#include <cctype>
using namespace std;

const int ARRAY_SIZE = 26;

struct Letter {
    char letter; // holds a letter of the alphabet
    int count = 0; // holds the number of times the letter occurs in the user input
};

void initializeArray(Letter letters[]);
void countLetter(char letter, Letter letters[]);
void sortArray(Letter letters[]);
void displayData(Letter letters[]);

int main() {

    char ch;
    Letter letters[ARRAY_SIZE];
    
    initializeArray(letters);
    
    cout << "Please enter a sequence of characters terminated with a period ('.'): ";
        cin >> ch;
        while (ch != '.'){
            if (isalpha(ch)) {
                countLetter(ch, letters);
            }
            cin >> ch;
        }
    
    sortArray(letters);
    displayData(letters);
}





// initializes the char member variable "letter" in  all of the structs in the array, starting with 'A' and going to 'Z'
void initializeArray(Letter letters[]) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        letters[i].letter = 'A' + i;
    }
}






// counts the how many of each letter there is and increments it in the right place
void countLetter(char letter, Letter letters[]) {
    letter = toupper(letter);
    int index = letter - 'A';
    letters[index].count++;
}





// sorts the array of structs based on the structs' count variable; if it is higher, then it comes first in the array
void sortArray(Letter letters[]) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        int indexOfLargestCount = i;
        for (int j = i + 1; j < ARRAY_SIZE; j++) {
            if (letters[j].count > letters[indexOfLargestCount].count) {
                indexOfLargestCount = j;
            }
        }
        if (letters[i].count != letters[indexOfLargestCount].count) {
            swap(letters[i], letters[indexOfLargestCount]);
        }
    }
}





// displays the contents of the (sorted) array
void displayData(Letter letters[]) {
    cout << "Letter:    Number of Occurrences" << endl;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (letters[i].count > 0) {
            cout << "     " << letters[i].letter << "     " << letters[i].count << endl;
        } else {
            i = ARRAY_SIZE;
        }
    }
}

/*
Output:
Please enter a sequence of characters terminated with a period ('.'): $ is skipped and there is no caSe sensitivity. Nothing after the period counts
Letter:    Number of Occurrences
    I     6
    S     6
    E     5
    N     3
    T     3
    A     2
    D     2
    P     2
    K     1
    O     1
    H     1
    R     1
    C     1
    V     1
    Y     1
Program ended with exit code: 0
*/