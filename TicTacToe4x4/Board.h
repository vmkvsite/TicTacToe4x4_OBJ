#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <iostream>

class Board {
private:
    std::vector<std::vector<char>> grid;

    int convertToIndex(int userInput);
    bool isValidInput(int row, int col);

public:
    static const int SIZE = 4;

    Board();
    int getSize() const;
    bool makeMove(int row, int col, char player);
    bool checkWin(char player);
    bool isFull();
    void display();
    void reset();
};

#endif