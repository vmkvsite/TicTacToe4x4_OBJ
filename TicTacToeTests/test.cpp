#include "pch.h"
#include "Board.h"
#include "Player.h"
#include "Game.h"

namespace TicTacToeTests
{
    class TicTacToeUnitTests : public ::testing::Test {
    public:
    };

    TEST_F(TicTacToeUnitTests, TestValidMove)
    {
        Board board;
        bool result = board.makeMove(1, 1, 'X');
        EXPECT_TRUE(result);
    }

    TEST_F(TicTacToeUnitTests, TestInvalidMove)
    {
        Board board;
        board.makeMove(1, 1, 'X');
        bool result = board.makeMove(1, 1, 'O');
        EXPECT_FALSE(result);
    }

    TEST_F(TicTacToeUnitTests, TestOutOfBoundsMove)
    {
        Board board;
        bool result = board.makeMove(0, 1, 'X');
        EXPECT_FALSE(result);
    }

    TEST_F(TicTacToeUnitTests, TestHorizontalWin)
    {
        Board board;
        board.makeMove(1, 1, 'X');
        board.makeMove(1, 2, 'X');
        board.makeMove(1, 3, 'X');
        board.makeMove(1, 4, 'X');
        bool result = board.checkWin('X');
        EXPECT_TRUE(result);
    }

    TEST_F(TicTacToeUnitTests, TestVerticalWin)
    {
        Board board;
        board.makeMove(1, 1, 'O');
        board.makeMove(2, 1, 'O');
        board.makeMove(3, 1, 'O');
        board.makeMove(4, 1, 'O');
        bool result = board.checkWin('O');
        EXPECT_TRUE(result);
    }

    TEST_F(TicTacToeUnitTests, TestDiagonalWin)
    {
        Board board;
        board.makeMove(1, 1, 'X');
        board.makeMove(2, 2, 'X');
        board.makeMove(3, 3, 'X');
        board.makeMove(4, 4, 'X');
        bool result = board.checkWin('X');
        EXPECT_TRUE(result);
    }

    TEST_F(TicTacToeUnitTests, TestBoardFull)
    {
        Board board;
        for (int row = 1; row <= 4; ++row) {
            for (int col = 1; col <= 4; ++col) {
                char player = ((row + col) % 2 == 0) ? 'X' : 'O';
                board.makeMove(row, col, player);
            }
        }
        bool result = board.isFull();
        EXPECT_TRUE(result);
    }

    TEST_F(TicTacToeUnitTests, TestPlayerSymbol)
    {
        Player player('X');
        char symbol = player.getSymbol();
        EXPECT_EQ(symbol, 'X');
    }
}