/* 
Calculates the probability of drawing a card in a game given a deck, some copies of a card, initial hand size, 
mulligan size, and number of draws after.
*/

#include <stdio.h>

double probNotInitialHand(int totalCards, int cardCopies, int initialHandSize);
double probNotMulligan(int totalCards, int cardCopies, int mulliganSize);
double probNotTurns(int totalCards, int cardCopies, int numTurns); 
double probNotDrawn(int totalCards, int cardCopies, int initialHandSize, int mulliganSize, int numTurns);

int main() {
    int totalCards;
    int cardCopies;
    int initialHandSize;
    int mulliganSize;
    int numTurns;
    
    printf("Enter how many total cards there are in the deck: ");
    scanf("%d", &totalCards);
    
    printf("Enter how many copies of the card that you are looking for are in the deck: ");
    scanf("%d", &cardCopies);
    
    printf("Enter your initial hand size: ");
    scanf("%d", &initialHandSize);
    
    printf("Enter how many cards you are mulliganing: ");
    scanf("%d", &mulliganSize); 
    
    printf("Enter what turn you want to draw the card by: ");
    scanf("%d", &numTurns);

    double pNotDrawing = probNotDrawn(totalCards, cardCopies, initialHandSize, mulliganSize, numTurns);
    double drawing = 1 - pNotDrawing;

    printf("The probability of drawing at least one of the cards by turn %d given you mulliganed %d cards is %.2lf\n", numTurns, mulliganSize, drawing);

    return 0;
}

/*
Calculates prob of not getting the card in initial hand
param totalCards is deck size, cardCopies is number of wanted card in deck, initialHandSize is number of cards
to initially draw
returns a double which probability of not having the card in initial hand
*/
double probNotInitialHand(int totalCards, int cardCopies, int initialHandSize) {
    double pNotInitialHand = 1;

    for (int i = 0; i < initialHandSize; i++) {
        pNotInitialHand *=  (double) (totalCards - i - cardCopies) / (totalCards - i);
    }

    return pNotInitialHand;
}

/*
Calculates prob of not getting the card in mulligan stage
param totalCards is deck size, cardCopies is number of wanted card in deck, mulliganSize is number of cards
to put aside and then draw more of the same amount from deck
returns a double which is probability of not having the card in mulligan stage
*/
double probNotMulligan(int totalCards, int cardCopies, int mulliganSize) {
    double pNotMulligan = 1;

    for (int i = 0; i < mulliganSize; i++) {
        pNotMulligan *= (double) (totalCards - i - cardCopies) / (totalCards - i);
    }

    return pNotMulligan;
}

/*
Calculates prob of not getting the card in the turns
param totalCards is deck size, cardCopies is number of wanted card in deck, numTurns is number of cards to draw
one by one from deck
returns a double which is probability of not having the card after taking all the turns
*/
double probNotTurns(int totalCards, int cardCopies, int numTurns) {
    double pNotTurns = 1;

    for (int i = 0; i < numTurns; i++) {
        pNotTurns *= (double) (totalCards - i - cardCopies) / (totalCards - i);
    }

    return pNotTurns;
}

/*
Calculates the probability of not drawing a card in a deck.
param totalCards is the size of the deck, cardCopies is the amount of the wanted card in the deck, initialHandSize
is the size of the initial amount of cards to draw, mulliganSize is the cards to put aside after and then draw from the 
remaining deck and put back the "sided" cards back in the deck, numTurns is the amount of card draws you will have after this
returns the probability of not drawing the wanted card given the info in the form of a decimal number (double)
*/
double probNotDrawn(int totalCards, int cardCopies, int initialHandSize, int mulliganSize, int numTurns) {
    double pNotInitialHand = probNotInitialHand(totalCards, cardCopies, initialHandSize);

    totalCards -= initialHandSize;

    double pNotMulligan = probNotMulligan(totalCards, cardCopies, mulliganSize);

    double pNotTurns = probNotTurns(totalCards, cardCopies, numTurns);

    double pNotDrawing = pNotInitialHand * pNotMulligan * pNotTurns;
    return pNotDrawing;
}