#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <cctype>

using std::cout;
using std::cin;
using std::string;
using std::getline;
using std::stoi;
using std::istringstream;

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

bool Game::isValidNumber(const string& str) {
    if (str.empty()) return false;

    for (char c : str) {
        if (!std::isdigit(c)) {
            return false;
        }
    }
    return true;
}

bool Game::getUserInput(int& row, int& col) {
    cout << "Enter row (1-4) and column (1-4) separated by space\n";
    cout << "Or type 'restart' to restart game, 'exit' to quit: ";

    string input;
    getline(cin, input);

    if (input == "exit" || input == "quit") {
        cout << "Thanks for playing! Goodbye!\n";
        exit(0);
    }

    if (input == "restart") {
        resetGame();
        return getUserInput(row, col);
    }

    istringstream iss(input);
    string rowStr, colStr, extra;

    if (!(iss >> rowStr >> colStr)) {
        return false; 
    }

    if (iss >> extra) {
        return false; 
    }

    if (!isValidNumber(rowStr) || !isValidNumber(colStr)) {
        return false;
    }

    try {
        row = stoi(rowStr);
        col = stoi(colStr);
        return true;
    }
    catch (...) {
        return false;
    }
}

void Game::displayInstructions() {
    cout << "Welcome to 4x4 Tic Tac Toe!\n";
    cout << "Players take turns placing " << player1.getSymbol()
        << " and " << player2.getSymbol() << " on the board.\n";
    cout << "First to get 4 in a row (horizontal, vertical, or diagonal) wins!\n";
    cout << "Enter coordinates as: row column (both from 1 to 4)\n";
    cout << "Special commands:\n";
    cout << "  - Type 'restart' to restart the game\n";
    cout << "  - Type 'exit' or 'quit' to exit the game\n\n";
}

void Game::play() {
    displayInstructions();
    cout << "Press Enter to start the game...";
    cin.get();

    while (true) {
        clearScreen();
        gameBoard.display();
        cout << "Player " << currentPlayer->getSymbol() << "'s turn.\n";

        int row, col;

        if (!getUserInput(row, col)) {
            cout << "Invalid input! Please enter exactly two numbers (1-4) separated by a space.\n";
            cout << "Examples: '1 2' or '3 4'\n";
            cout << "Press Enter to continue...";
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
            cin.get();
        }
    }
}

void Game::resetGame() {
    gameBoard.reset();
    currentPlayer = &player1;
    clearScreen();
    cout << "Game has been restarted!\n";
    gameBoard.display();
    cout << "Press Enter to continue...";
    cin.get();
}