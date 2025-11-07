/*
Ibrahim Siddiqui
CS 10B
February 12, 2020
Assignment 4.1

This program starts off with a number of cards (5, for example) that are given by the user from a lower number to a higher number (for example, 2 - 9). The program then goes about checking whether the numbers contain a pair of identical cards (2 and 2 exactly, for example), or multiple pairs, or three identical cards (exactly), or five consecutive cards, or a full house (at least one pair and triplet), or four or more of the same card. If those are not present then the program simply outputs "high card". All those special hands are separate functions. There is also an additional helper function that I added called howManyTimes, which accepts an int representing a number to look for in the array. The function then returns how many times that int occurs in the array.
*/

#include <iostream>
using namespace std;

bool containsPair(const int hand[]);
int howManyTimes(int num, const int hand[]);
bool containsTwoPair(const int hand[]);
bool containsThreeOfAKind(const int hand[]);
bool containsStraight(const int hand[]);
bool containsFullHouse(int hand[]);
bool fourOfAKind(const int hand[]);

const int HAND_SIZE = 5;
const int LOWEST_NUM = 2;
const int HIGHEST_NUM = 9;

int main() {
    
    int hand[HAND_SIZE];
    int num;
    
    cout << "Enter " << HAND_SIZE << " numeric cards, no face cards. Use " << LOWEST_NUM << " - " << HIGHEST_NUM << "." << endl;
    for (int count = 0; count < HAND_SIZE; count++) {
        cout << "Card " << count + 1 << ": ";
        cin >> num;
        hand[count] = num;
    }
    
    if (fourOfAKind(hand)) {
        cout << "Four of a kind!" << endl;
    } else if (containsFullHouse(hand)) {
        cout << "Full house!" << endl;
    } else if (containsStraight(hand)) {
        cout << "Straight!" << endl;
    } else if (containsThreeOfAKind(hand)) {
        cout << "Three of a kind!" << endl;
    } else if (containsTwoPair(hand)) {
        cout << "Two pair!" << endl;
    } else if (containsPair(hand)) {
        cout << "Pair!" << endl;
    } else {
        cout << "High card!" << endl;
    }
}






// returns true if and only if there are one or more pairs in the hand. Note that this function returns false if there are more than two of the same card (and no other pairs).
bool containsPair(const int hand[]) {
    bool isPair = false;
    for (int i = LOWEST_NUM; i <= HIGHEST_NUM; i++) {
        int numOfTimes = howManyTimes(i, hand);
        if (numOfTimes == 2) {
            isPair = true;
            break;
        }
    }
    return isPair;
}

/*
bool containsPair(const int *hand) {
    for (int i = 0; i < HAND_SIZE; i++) {
        int numOfTimes = howManyTimes(hand[i], hand);
        if (numOfTimes == 2) {
            return true;
        }
    }
    return false;
}
*/





// returns true if and only if there are two or more pairs in the hand.
bool containsTwoPair(const int hand[]) {
    int numOfPairs = 0;
    for (int i = LOWEST_NUM; i <= HIGHEST_NUM; i++) {
        int numOfTimes = howManyTimes(i, hand);
        if (numOfTimes == 2) {
            numOfPairs++;
        }
    }
    return numOfPairs >= 2;
}





// returns true if and only if there are one or more three-of-a-kind's in the hand.
bool containsThreeOfAKind(const int hand[]) {
    int numOfThrees = 0;
    for (int i = LOWEST_NUM; i <= HIGHEST_NUM; i++) {
        int numOfTimes = howManyTimes(i, hand);
        if (numOfTimes == 3) {
            numOfThrees++;
        }
    }
    return numOfThrees >= 1;
}





// returns true if there are 5 consecutive cards in the hand.
bool containsStraight(const int hand[]) {
    int conseqNums = 0;
    for (int i = LOWEST_NUM; i <= HIGHEST_NUM; i++) {
        int numOfTimes = howManyTimes(i, hand);
        if (numOfTimes > 0 && i == LOWEST_NUM) {
            conseqNums++;
        } else if (numOfTimes > 0 && howManyTimes(i - 1, hand) > 0) {
            conseqNums++;
        } else if (numOfTimes > 0 && conseqNums == 0) {
            conseqNums++;
        } else {
            conseqNums = 0;
        }
        if (conseqNums == 5) {
            break;
        }
    }
    return conseqNums == 5;
}

/*
bool containsStraight(const int *hand) {
    int conseqNums = 0;
    int numOfTimes = howManyTimes(LOWEST_NUM, hand);
    bool isPrevNumThere = false;
    if (numOfTimes > 0) {
        conseqNums++;
        isPrevNumThere = true;
    }
    for (int i = LOWEST_NUM + 1; i <= HIGHEST_NUM; i++) {
        int numOfTimes = howManyTimes(i, hand);
        if (numOfTimes > 0 && isPrevNumThere) {
            conseqNums++;
        } else if (numOfTimes > 0 && conseqNums == 0) {
            conseqNums++;
            isPrevNumThere = true;
        } else {
            conseqNums = 0;
            isPrevNumThere = false;
        }
        if (conseqNums == 5) {
            return true;
        }
    }
    return false;
}
*/





// returns true if there is are one or more pairs and one or more three-of-a-kind's in the hand.
bool containsFullHouse(int hand[]) {
    int numOfPairs = 0;
    int numOfThrees = 0;
    for (int i = LOWEST_NUM; i <= HIGHEST_NUM; i++) {
        int numOfTimes = howManyTimes(i, hand);
        if (numOfTimes == 2) {
            numOfPairs++;
        } else if (numOfTimes == 3) {
            numOfThrees++;
        }
    }
    return (numOfPairs >= 1) && (numOfThrees >= 1);
}





// returns true if there are one or more four-of-a-kind's in the hand.
bool fourOfAKind(const int hand[]) {
    int numOfFours = 0;
    for (int i = LOWEST_NUM; i <= HIGHEST_NUM; i++) {
        int numOfTimes = howManyTimes(i, hand);
        if (numOfTimes >= 4) {
            numOfFours++;
        }
    }
    return numOfFours >= 1;
}






// helper function that returns the number of occurences of a given number in an array
int howManyTimes(int num, const int hand[]) {
    int times = 0;
    for (int i = 0; i < HAND_SIZE; i++) {
        if (hand[i] == num) {
            times++;
        }
    }
    return times;
}

/*
Output:
Enter 5 numeric cards, no face cards. Use 2 - 9.
Card 1: 7
Card 2: 5
Card 3: 6
Card 4: 4
Card 5: 3
Straight!
Program ended with exit code: 0

Enter 5 numeric cards, no face cards. Use 2 - 9.
Card 1: 2
Card 2: 2
Card 3: 3
Card 4: 4
Card 5: 5
Pair!

Enter 5 numeric cards, no face cards. Use 2 - 9.
Card 1: 2
Card 2: 3
Card 3: 3
Card 4: 2
Card 5: 1
Two pair!

Enter 5 numeric cards, no face cards. Use 2 - 9.
Card 1: 2
Card 2: 3
Card 3: 3
Card 4: 3
Card 5: 2
Full house!

Enter 5 numeric cards, no face cards. Use 2 - 9.
Card 1: 2
Card 2: 2
Card 3: 2
Card 4: 2
Card 5: 2
Four of a kind!
*/