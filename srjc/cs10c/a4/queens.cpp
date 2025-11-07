/*

Ibrahim Siddiqui
CS 10C
Dave Harden
Assignment 4.1
13 September 2022

*/


#include <iostream>
#include <vector>
using namespace std;

class Queen {
    public:
        void setRow(int inRow);
        int getRow() const;
    private:
        int row;
};





int Queen::getRow() const {
    return row;
}





void Queen::setRow(int inRow) {
    row = inRow;
}





class Board {
    public:
        static const int BOARD_SIZE = 8;
        Board();
        void doQueens();
        void display() const;
    private:
        bool placeQueens(int row, int col);
        bool findNextSafeSquare(int& row, int col);
        bool isUnderAttack(int row, int col);
        vector<Queen> queens;
};





Board::Board() {
    queens.resize(BOARD_SIZE);
}





void Board::doQueens() {
    if (placeQueens(0, 0)) {
        display();
    } else {
        cout << "No solution found." << endl;
    }
}

/*

pre: row < BOARD_SIZE && col < BOARD_SIZE
post: places a queen in each column of the calling object, beginning with the column "col", and
    considering rows in that column beginning with row "row", in such a way that none of them are
    under attack by any others.  Returns true if successful, false if no such configuration can be
    found

placeQueens(row: integer, col: integer): boolean {

    Beginning with row "row", find the next square in column "col" that is safe;
    while (such a square exists) {
        Set the location of the Queen in column "col" to that square;
        if (this was the final Queen to be placed OR placeQueens(0, col + 1)) {
            return true;
        } else {
            // placing the queen in column "col" into row "row" didn't work, so:
            Move the queen in column "col" to the next square in that column
            row = queens[col].getRow();
        }
        Beginning with row "row", find the next square in column "col" that is safe;
    }
    
    // exited the while loop, which means that all rows in this column have been considered.
    return false;
            
}

*/

bool Board::placeQueens(int row, int col) {
    bool isSquareSafe = findNextSafeSquare(row, col);
    while (isSquareSafe == true) {
        queens[col].setRow(row);
        if ((col == (BOARD_SIZE - 1)) || placeQueens(0, col + 1)) {
            return true;
        } else {
            queens[col].setRow(row + 1);
            row = queens[col].getRow();
        }
        isSquareSafe = findNextSafeSquare(row, col);
    }
    return false;
}

/*

bool Board::placeQueens(int row, int col) {
    bool isSquareSafe = findNextSafeSquare(int row, int col);
    while (isSquareSafe) {
        queens[col].setRow(row);
        
    }
}

*/

                    



bool Board::isUnderAttack(int testRow, int testCol) {
    bool isSquareSafe = true;
    for (vector<Queen>::size_type i = 0; i < testCol; i++) {
        // checks for a horizontal attack on the row
        if (queens[i].getRow() == testRow) {
            isSquareSafe = false;
        }
        // checks for a diagonal attack on the row
        int rowPrevQueen = queens[i].getRow();
        int rowPrevQueen2 = queens[i].getRow();
        int colPrevQueen = (int) i;
        for (int j = (int) i; j <= testCol; j++) {
            if ((rowPrevQueen == testRow && colPrevQueen == testCol) || (rowPrevQueen2 == testRow && colPrevQueen == testCol) ) {
                isSquareSafe = false;
            }
            rowPrevQueen++;
            rowPrevQueen2--;
            colPrevQueen++;
        }
    }
    return !isSquareSafe;
}

/*

bool Board::isUnderAttack(int testRow, int testCol) {
    bool isUnderAttack = false;
    for (vector<Queen>::size_type = 0; i < testCol; i++) {
        // check for any attacks on the queen along the horizontal
        if (queens[i].getRow() == testRow) {
            isUnderAttack = true;
        }
        // check for any attacks on the queen along the diagonals
        int diagonallyUp = queens[i].getRow();
        int diagonallyDown = queens[i].getRow();
        for (int j = (int) i; j <= testCol; j++) {
            diagonallyUp--;
            diagonallyDown++;
        }
        if ((diagonallyUp == testRow) || (diagonallyDown = testRow)) {
            isUnderAttack = true;
        }
    }
    return isUnderAttack;
}
 
*/



// Sets "row" to the row of the next safe square in column col.  Important note:
// Starts with the given row and col.  In other words, the given row and col may
// be the "next safe square".
// returns true if a safe square is found, false if no safe square is found.  If
// return value is false, row is undefined.

bool Board::findNextSafeSquare(int& row, int col) {
    int currentRow = row;
    bool isSquareAttacked = true;
    while (currentRow < BOARD_SIZE && isSquareAttacked == true) {

        isSquareAttacked = false;
        isSquareAttacked = isUnderAttack(currentRow, col);
        //cout << "square" << isSquareAttacked << " row" << currentRow << endl;
        if (isSquareAttacked == true) {
            currentRow++;
        }
    }
    if (isSquareAttacked == false) {
        row = currentRow;
        return true;
    } else {
        return false;
    }
}

/*

bool Board::findNextSafeSquare(int &row, int col) {
    int currentRow = row;
    bool isSquareUnderAttack == true;
    while (currentRow < BOARD_SIZE && isSquareUnderAttack == true) {
        isSquareUnderAttack = isUnderAttack(currentRow, col);
        if (isSquareUnderAttack == true) {
            currentRow++;
        }
    }
    if (isSquareUnderAttack == false) {
        row = currentRow;
        return true;
    } else {
        return false;
    }
}

*/

        


// Displays a visual representation of the current state of the board.  For each position
// on the board, displays "X" if a queen is located at that position, otherwise displays
// "_" (underscore).

void Board::display() const {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (vector<Queen>::size_type j = 0; j < queens.size(); j++) {
            if (queens[j].getRow() == i) {
                cout << "X ";
            } else {
                cout << "_ ";
            }
        }
        cout << endl;
    }
}





int main() {
    Board board;
    board.doQueens();
}

/*
Output:
X _ _ _ _ _ _ _
_ _ _ _ _ _ X _
_ _ _ _ X _ _ _
_ _ _ _ _ _ _ X
_ X _ _ _ _ _ _
_ _ _ X _ _ _ _
_ _ _ _ _ X _ _
_ _ X _ _ _ _ _
*/


