#include "Board.h"

using std::vector;
using std::cout;

Board::Board() : grid(4, vector<char>(4, ' ')) {}

int Board::convertToIndex(int userInput) {
    return userInput - 1;
}

bool Board::isValidInput(int row, int col) {
    return (row >= 1 && row <= SIZE && col >= 1 && col <= SIZE);
}

int Board::getSize() const {
    return SIZE;
}

bool Board::makeMove(int row, int col, char player) {
    if (!isValidInput(row, col)) {
        return false;
    }

    int arrayRow = convertToIndex(row);
    int arrayCol = convertToIndex(col);

    if (grid[arrayRow][arrayCol] != ' ') {
        return false;
    }

    grid[arrayRow][arrayCol] = player;
    return true;
}

bool Board::checkWin(char player) {
    for (int i = 0; i < SIZE; i++) {
        bool rowWin = true;
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] != player) {
                rowWin = false;
                break;
            }
        }
        if (rowWin) return true;
    }

    for (int j = 0; j < SIZE; j++) {
        bool colWin = true;
        for (int i = 0; i < SIZE; i++) {
            if (grid[i][j] != player) {
                colWin = false;
                break;
            }
        }
        if (colWin) return true;
    }

    bool mainDiagWin = true;
    for (int i = 0; i < SIZE; i++) {
        if (grid[i][i] != player) {
            mainDiagWin = false;
            break;
        }
    }
    if (mainDiagWin) return true;

    bool antiDiagWin = true;
    for (int i = 0; i < SIZE; i++) {
        if (grid[i][SIZE - 1 - i] != player) {
            antiDiagWin = false;
            break;
        }
    }
    if (antiDiagWin) return true;

    return false;
}

bool Board::isFull() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void Board::display() {
    cout << "\n   1   2   3   4\n";
    for (int i = 0; i < SIZE; i++) {
        cout << (i + 1) << "  ";
        for (int j = 0; j < SIZE; j++) {
            cout << grid[i][j];
            if (j < SIZE - 1) cout << " | ";
        }
        cout << "\n";
        if (i < SIZE - 1) {
            cout << "   ---------------\n";
        }
    }
    cout << "\n";
}

void Board::reset() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = ' ';
        }
    }
}