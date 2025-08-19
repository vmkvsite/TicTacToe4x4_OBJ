#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <iostream>
using namespace std;

class Board {
private:
    vector<vector<char>> grid;
    const int SIZE = 4;

    int convertToIndex(int userInput);
    bool isValidInput(int row, int col);

public:
    Board();
    int getSize() const;
    bool makeMove(int row, int col, char player);
    bool checkWin(char player);
    bool isFull();
    void display();
    void reset();
};

#endif