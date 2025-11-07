/*
Ibrahim Siddiqui
CS10B
Assignment 7.1
March 5, 2022

This program receives input regarding the names of players and their respective scores in a game. The program then takes those names and scores and puts them into a dynamic array of HighScore structs, where the struct contains two variables, an int to store the score, and a char array called name that stores the name of the player. The program then goes about sorting the scores of the players from greatest to least, and then displays the winners of the videogame, starting with the player with the highest score.
*/

#include <iostream>
using namespace std;

const int ARRAY_SIZE = 24;

struct HighScore {
    int score;
    char name[ARRAY_SIZE];
};

void readData(HighScore scores[], int size);
void sortData(HighScore scores[], int size);
void displayData(const HighScore scores[], int size);

int main() {
    
    int arraySize; // stores the size of the array
    HighScore *scores = nullptr; // will point to a dynamic array of HighScore structs
    
    cout << "How many scores will you enter?: ";
    cin >> arraySize;
    cin.ignore();
    
    scores = new HighScore[arraySize];
    
    readData(scores, arraySize);
    sortData(scores, arraySize);
    displayData(scores, arraySize);
    
    delete [] scores;
}





// reads data regarding the player name and score from the user and stores it in the dynamic arrays
void readData(HighScore scores[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Enter the name for score #" << (i + 1) << ": ";
        cin >> scores[i].name;
        cout << "Enter the score for score #" << (i + 1) << ": ";
        cin >> scores[i].score;
        cin.ignore();
    }
    cout << "" << endl;
}





// sorts the player scores from greatest to least
void sortData(HighScore scores[], int size) {
    for (int i = 0; i < size; i++) {
        int indexOfLargestScore = i;
        for (int j = i + 1; j < size; j++) {
            if (scores[j].score > scores[indexOfLargestScore].score) {
                indexOfLargestScore = j;
            }
        }
        if (scores[i].score != scores[indexOfLargestScore].score) {
            swap(scores[i], scores[indexOfLargestScore]);
        }
    }
}





// displays the winners of the game starting with the highest score
void displayData(const HighScore scores[], int size) {
    cout << "Top scorers:" << endl;
    for (int i = 0; i < size; i++) {
        cout << scores[i].name << ": " << scores[i].score << endl;
    }
}

/*
Output:
How many scores will you enter?: 5
Enter the name for score #1: John
Enter the score for score #1: 12
Enter the name for score #2: Bob
Enter the score for score #2: 200
Enter the name for score #3: Jo
Enter the score for score #3: 908
Enter the name for score #4: Paul
Enter the score for score #4: 5
Enter the name for score #5: Noah
Enter the score for score #5: 76

Top scorers:
Jo: 908
Bob: 200
Noah: 76
John: 12
Paul: 5
Program ended with exit code: 0
*/