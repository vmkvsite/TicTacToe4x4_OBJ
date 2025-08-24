#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <iostream>

class Board {
private:
    std::vector<std::vector<char>> grid;

    int convertToIndex(int userInput) const;
    bool isValidInput(int row, int col) const;

public:
    static const int SIZE = 4;

    Board();
    int getSize() const;
    bool makeMove(int row, int col, char player);
    bool checkWin(char player) const;
    bool isFull() const;
    void display() const;
    void reset();
};

#endif