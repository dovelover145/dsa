/*
Ibrahim Siddiqui
CS10B
Assignment 5.2
Febraury 16, 2022

This program receives input regarding the names of players and their respective scores in a game. The program then takes those names and scores and puts them into two dynamic arrays, one that stores the names of players and one that stores their scores. The program then goes about sorting the scores of the players from greatest to least, and then displays the winners of the videogame, starting with the player with the highest score.
*/

#include <iostream>
#include <string>
using namespace std;

void readData(string names[], int scores[], int size);
void sortData(string names[], int scores[], int size);
void displayData(const string names[], const int scores[], int size);

int main() {
    
    int numOfScores; // stores the number of scores the user will enter
    string *names = nullptr; // pointer that will point to a dynamic array of player names
    int *scores = nullptr; // pointer that will point to a dynamic array of player scores
    
    cout << "How many scores will you enter?: ";
    cin >> numOfScores;
    cin.ignore();
    names = new string[numOfScores];
    scores = new int[numOfScores];
    
    readData(names, scores, numOfScores);
    sortData(names, scores, numOfScores);
    displayData(names, scores, numOfScores);
    
    delete [] names;
    delete [] scores;
}





// reads data regarding the player name and score from the user and stores it in the dynamic arrays
void readData(string names[], int scores[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Enter the name for score #" << (i + 1) << ": ";
        getline(cin, names[i]);
        cout << "Enter the score for score #" << (i + 1) << ": ";
        cin >> scores[i];
        cin.ignore();
    }
    cout << "" << endl;
}





// sorts the player scores from greatest to least
void sortData(string names[], int scores[], int size) {
    for (int i = 0; i < size; i++) {
        int indexOfLargestScore = i;
        for (int j = i + 1; j < size; j++) {
            if (scores[j] > scores[indexOfLargestScore]) {
                indexOfLargestScore = j;
            }
        }
        if (scores[i] != scores[indexOfLargestScore]) {
            swap(scores[i], scores[indexOfLargestScore]);
            swap(names[i], names[indexOfLargestScore]);
        }
    }
}





// displays the winners of the game starting with the highest score
void displayData(const string names[], const int scores[], int size) {
    cout << "Top scorers:" << endl;
    for (int i = 0; i < size; i++) {
        cout << names[i] << ": " << scores[i] << endl;
    }
}

/*
Output:
How many scores will you enter?: 5
Enter the name for score #1: John
Enter the score for score #1: 4501
Enter the name for score #2: Sid
Enter the score for score #2: 401
Enter the name for score #3: Bob
Enter the score for score #3: 901
Enter the name for score #4: Gary
Enter the score for score #4: 3567
Enter the name for score #5: Liam
Enter the score for score #5: 9

Top scorers:
John: 4501
Gary: 3567
Bob: 901
Sid: 401
Liam: 9
*/