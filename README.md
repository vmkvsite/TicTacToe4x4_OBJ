# Tic Tac Toe 4x4
## Project for C++ object oriented class.
---------------------------------------------------------------
## How to play:
- Run 'TicTacToe4x4.exe', no additional libraries are needed. Press enter and each player will take turns until the game ends, type "restart" to reset the game board, type "exit" to exit the program.
---------------------------------------------------------------
# Project class structure is as follows:
---------------------------------------------------------------
## Game class (Game.cpp/.h) - controls main game logic, game state and handles user input
---------------------------------------------------------------
**Private members/methods:**
- **gameBoard** - game board instance
- **player1** - First player, X symbol
- **player2** - second player, O symbol
- **Player* currentPlayer** - pointer that points to the currently active player
- **clearScreen()** - clears console screen after each move to make the game experience uniform, uses cls for windows (tested, working) or clear (unix, untested)
- **switchPlayer()** - update function that alternates between player1 and player2
- **getUserInput()** - boolean function that returns true if input was successful or false if invalid
- **resetGame()** - resets the game board to empty state and sets currentPlayer back to player1
---------------------------------------------------------------
**Public members/methods:**
- **Game()** - initializes player1 with X and player2 with O and sets currentPlayer pointer to point to player1, also calls Board() and initializes the grid
- **displayInstructions()** - shows welcome message, game objective, etc
- **play()** - main game loop
---------------------------------------------------------------
## Board class (Board.cpp/.h) - controls the board and operations on the board
---------------------------------------------------------------
**Private members/methods:**
- **vector<vector<char>> grid** - 2D vector with assigned size of 4 to represent the 4x4 game board
- **convertToIndex** - conversion function to convert 0-1-2-3 to 1-2-3-4 for ease of play
- **isValidInput** - validation function to check if user's input is in valid range, returns true or false (boolean)
---------------------------------------------------------------
**Public members/methods:**
- **Board()** - constructor that initializes 4x4 grid with empty spaces
- **getSize()** - getter function to return board size
- **makeMove()** - validation function that returns true or false depending on the validity of the move (checks the validity of input using isValidInput(), converts coords to convertToIndex(), checks if the position is empty and places player symbol if valid)
- **checkWin()** - returns true if player has won, false if otherwise (iterates through each row and column checking for 4 in a row, also checks diagonal and anti diagonal)
- **isFull()** - returns true or false if board is full or not
- **display()** - renders board with coords - shows column and row numbers and creates visual separation
- **reset()** - clears all board positions back to empty spaces for game restart functionality
---------------------------------------------------------------
## Player class (Player.cpp/.h) - manages player1/player2 symbols
---------------------------------------------------------------
**Private members/methods:**
- **char symbol** - initialization function that stores either X or O
---------------------------------------------------------------
**Public members/methods:**
- **Player (char playerSymbol)** - a constructor which takes player's symbol and initializes given player with given symbol
- **char getSymbol() const** - getter method to return player's symbol
- **void setSymbol(char newSymbol)** - setter function to assign new symbol char for the player
---------------------------------------------------------------
