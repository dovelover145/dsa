#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
    int card1;    // one of the two initial cards
    int card2;    // one of the two initial cards
    int card3;    // holds the number of the random card in the loop
    int total;    // holds the total count of the cards
    char cardCh;  // this keeps track of whether the user wants a new card
    char gameCh;  // this keeps track of whether the user wants to play again

    do {
        card1 = rand() % 10 + 1;
        card2 = rand() % 10 + 1;
        total = card1 + card2;

        cout << "First cards: " << card1 << ", " << card2 << endl;
        cout << "Total: " << total << endl;
        cout << "Do you want another card? (y/n): ";
        cin >> cardCh;

        while (cardCh != 'n') {
            card3 = rand() % 10 + 1;
            cout << "Card: " << card3 << endl;
            total += card3;
            cout << "Total: " << total << endl;
            if (total > 21) {
                cout << "Bust." << endl;
                cardCh = 'n';
                total = 0;
            } else if (total == 21) {
                cout << "Congratulations." << endl;
                cardCh = 'n';
                total = 0;
            } else {
                cout << "Do you want another card? (y/n): ";
                cin >> cardCh;
            }
        }

        cout << "Would you like to play again? (y/n): ";
        cin >> gameCh;
        cout << "" << endl;

    } while (gameCh != 'n');
}

/*
Output:
First cards: 8, 10
Total: 18
Do you want another card? (y/n): y
Card: 4
Total: 22
Bust.
Would you like to play again? (y/n): y

First cards: 9, 1
Total: 10
Do you want another card? (y/n): y
Card: 3
Total: 13
Do you want another card? (y/n): y
Card: 5
Total: 18
Do you want another card? (y/n): y
Card: 9
Total: 27
Bust.
Would you like to play again? (y/n): y

First cards: 4, 10
Total: 14
Do you want another card? (y/n): y
Card: 1
Total: 15
Do you want another card? (y/n): y
Card: 6
Total: 21
Congratulations.
Would you like to play again? (y/n): y

First cards: 3, 3
Total: 6
Do you want another card? (y/n): y
Card: 8
Total: 14
Do you want another card? (y/n): y
Card: 4
Total: 18
Do you want another card? (y/n): y
Card: 8
Total: 26
Bust.
Would you like to play again? (y/n): n

Program ended with exit code: 0
*/