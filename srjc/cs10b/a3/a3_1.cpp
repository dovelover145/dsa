/*
Ibrahim Siddiqui
February 7, 2022
CS 10B
Assignment 3.1

This program plays a game with the user: It asks the user to think of a number from 1-100. Then, the program attempts to guess it. If the guess is correct, the user writes 'c'; if it is too low, then 'l', and if it is too high, then 'h'. The program guesses the number by constantly calculating the midpoint between the values until the correct value is reached. The game can be played as many times as the user wishes.
*/

#include <iostream>
using namespace std;

void playOneGame();
int getMidpoint(int low, int high);
void getUserResponseToGuess(int guess, char& result);

int main() {
    char response;
    cout << "Ready to play (y/n)? ";
    cin >> response;
    while (response == 'y') {
        playOneGame();
        cout << "Great! Do you want to play again (y/n)? ";
        cin >> response;
    }
}





// this function "plays" the number guessing game
void playOneGame() {
    int upper = 100;        // upper bound
    int lower = 1;        // lower bound
    int guess;        // this number stores the guessed number
    char result;        // this variable stores whether the guessed number is correct, too low, or too high
    
    cout << "Think of a number between 1 and 100." << endl;
    guess = getMidpoint(upper, lower);
    getUserResponseToGuess(guess, result);
    
    while (result != 'c') {
        if (result == 'l') {
            upper = guess - 1;
        } else if (result == 'h') {
            lower = guess + 1;
        }
        guess = getMidpoint(upper, lower);
        getUserResponseToGuess(guess, result);
    }
}





// this function calculates the midpoint between a lower and upper bound (ex. 1 and 7)
int getMidpoint(int low, int high) {
    return (high + low) / 2;
}





// this function prompts the user to reply whether or not the guessed number is correct
void getUserResponseToGuess(int guess, char& result) {
    cout << "My guess is " << guess << ". Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: ";
    cin >> result;
}






/*
Output:
Ready to play (y/n)? y
Think of a number between 1 and 100.
My guess is 50. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: h
My guess is 75. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: h
My guess is 88. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: l
My guess is 81. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: h
My guess is 84. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: c
Great! Do you want to play again (y/n)? y
Think of a number between 1 and 100.
My guess is 50. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: l
My guess is 25. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: l
My guess is 12. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: l
My guess is 6. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: l
My guess is 3. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: l
My guess is 1. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: c
Great! Do you want to play again (y/n)? y
Think of a number between 1 and 100.
My guess is 50. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: l
My guess is 25. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: h
My guess is 37. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: h
My guess is 43. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: l
My guess is 40. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: h
My guess is 41. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: c
Great! Do you want to play again (y/n)? n
Program ended with exit code: 0
*/