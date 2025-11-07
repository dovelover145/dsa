#include <iostream>
#include <vector>
using namespace std;

const int MAX_NAME_SIZE = 24;

struct Highscore {
    char name[MAX_NAME_SIZE];
    int score;
};

void getVectorSize(int &size);
void readData(vector<Highscore> &scores);
void sortData(vector<Highscore> &scores);
vector<Highscore>::iterator findLocationOfLargest(const vector<Highscore>::iterator startingLocation, const vector<Highscore>::iterator endingLocation);
void displayData(const vector<Highscore> &scores);

int main() {
    int size;
    
    getVectorSize(size);
    
    vector<Highscore> scores(size);
    
    readData(scores);
    sortData(scores);
    displayData(scores);
}





void getVectorSize(int &size) {
    cout << "How many scores will you enter?: ";
    cin >> size;
    cin.ignore();
}





void readData(vector<Highscore> &scores) {
    int currentScore = 1;
    for (vector<Highscore>::iterator i = scores.begin(); i != scores.end(); i++) {
        cout << "Enter the name for score #" << currentScore << ": ";
        cin.getline(i->name, MAX_NAME_SIZE, '\n');
        
        cout << "Enter the score for score #" << currentScore << ": ";
        cin >> i->score;
        cin.ignore();
        currentScore++;
    }
    cout << endl;
}





void sortData(vector<Highscore> &scores) {
    for (vector<Highscore>::iterator i = scores.begin(); i != scores.end() - 1; i++){
        vector<Highscore>::iterator j = findLocationOfLargest(i, scores.end());
        swap(*i, *j);
    }
}





vector<Highscore>::iterator findLocationOfLargest(const vector<Highscore>::iterator startingLocation, const vector<Highscore>::iterator endingLocation) {
    vector<Highscore>::iterator indexOfLargest = startingLocation;

    for (vector<Highscore>::iterator i = startingLocation + 1; i != endingLocation; i++) {
        if (i->score > indexOfLargest->score) {
            indexOfLargest = i;
        }
    }
    return indexOfLargest;
}





void displayData(const vector<Highscore> &scores) {
    cout << "Top Scorers: " << endl;
    for (vector<Highscore>::const_iterator i = scores.begin(); i != scores.end(); i++) {
        cout << i->name << ": " << i->score << endl;
    }
}

/*
Output:
How many scores will you enter?: 3
Enter the name for score #1: Bobby
Enter the score for score #1: 1200
Enter the name for score #2: Johnny
Enter the score for score #2: 90
Enter the name for score #3: Zack
Enter the score for score #3: 222

Top Scorers:
Bobby: 1200
Zack: 222
Johnny: 90
Program ended with exit code: 0
*/