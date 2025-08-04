#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Player.h"

class Game {
private:
    Board gameBoard;
    Player player1;
    Player player2;
    Player* currentPlayer;

    void clearScreen();
    void switchPlayer();
    bool getUserInput(int& row, int& col);

public:
    Game();
    void displayInstructions();
    void play();
};

#endif