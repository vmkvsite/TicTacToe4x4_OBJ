#include "Game.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Game::Game() : player1('X'), player2('O'), currentPlayer(&player1) {}

void Game::clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void Game::switchPlayer() {
    if (currentPlayer == &player1) {
        currentPlayer = &player2;
    }
    else {
        currentPlayer = &player1;
    }
}

bool Game::getUserInput(int& row, int& col) {
    cout << "Enter row (1-4) and column (1-4) separated by space: ";
    if (cin >> row >> col) {
        return true;
    }
    else {
        cin.clear();
        cin.ignore(1000, '\n');
        return false;
    }
}

void Game::displayInstructions() {
    cout << "Welcome to 4x4 Tic Tac Toe!\n";
    cout << "Players take turns placing " << player1.getSymbol()
        << " and " << player2.getSymbol() << " on the board.\n";
    cout << "First to get 4 in a row (horizontal, vertical, or diagonal) wins!\n";
    cout << "Enter coordinates as: row column (both from 1 to 4)\n\n";
}

void Game::play() {
    displayInstructions();
    cout << "Press Enter to start the game...";
    cin.ignore();
    cin.get();

    while (true) {
        clearScreen();
        gameBoard.display();
        cout << "Player " << currentPlayer->getSymbol() << "'s turn.\n";

        int row, col;

        if (!getUserInput(row, col)) {
            cout << "Invalid input! Please enter two numbers.\n";
            cout << "Press Enter to continue...";
            cin.ignore();
            cin.get();
            continue;
        }

        if (gameBoard.makeMove(row, col, currentPlayer->getSymbol())) {
            if (gameBoard.checkWin(currentPlayer->getSymbol())) {
                clearScreen();
                gameBoard.display();
                cout << "Congratulations! Player " << currentPlayer->getSymbol()
                    << " wins!\n";
                break;
            }

            if (gameBoard.isFull()) {
                clearScreen();
                gameBoard.display();
                cout << "It's a draw! Good game!\n";
                break;
            }

            switchPlayer();
        }
        else {
            cout << "Invalid move! Position must be between 1-4 and not already taken.\n";
            cout << "Press Enter to try again...";
            cin.ignore();
            cin.get();
        }
    }
}