#include "pch.h"
#include "CppUnitTest.h"
#include "../TicTacToe4x4/Board.h"
#include "../TicTacToe4x4/Player.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TicTacToeTests
{
    TEST_CLASS(TicTacToeUnitTests)
    {
    public:

        TEST_METHOD(TestValidMove)
        {
            Board board;
            bool result = board.makeMove(1, 1, 'X');
            Assert::IsTrue(result);
        }

        TEST_METHOD(TestInvalidMove)
        {
            Board board;
            board.makeMove(1, 1, 'X');
            bool result = board.makeMove(1, 1, 'O');
            Assert::IsFalse(result);
        }

        TEST_METHOD(TestOutOfBoundsMove)
        {
            Board board;
            bool result = board.makeMove(0, 1, 'X');
            Assert::IsFalse(result);
        }

        TEST_METHOD(TestHorizontalWin)
        {
            Board board;
            board.makeMove(1, 1, 'X');
            board.makeMove(1, 2, 'X');
            board.makeMove(1, 3, 'X');
            board.makeMove(1, 4, 'X');
            bool result = board.checkWin('X');
            Assert::IsTrue(result);
        }

        TEST_METHOD(TestVerticalWin)
        {
            Board board;
            board.makeMove(1, 1, 'O');
            board.makeMove(2, 1, 'O');
            board.makeMove(3, 1, 'O');
            board.makeMove(4, 1, 'O');
            bool result = board.checkWin('O');
            Assert::IsTrue(result);
        }

        TEST_METHOD(TestDiagonalWin)
        {
            Board board;
            board.makeMove(1, 1, 'X');
            board.makeMove(2, 2, 'X');
            board.makeMove(3, 3, 'X');
            board.makeMove(4, 4, 'X');
            bool result = board.checkWin('X');
            Assert::IsTrue(result);
        }

        TEST_METHOD(TestBoardFull)
        {
            Board board;
            for (int row = 1; row <= 4; ++row) {
                for (int col = 1; col <= 4; ++col) {
                    char player = ((row + col) % 2 == 0) ? 'X' : 'O';
                    board.makeMove(row, col, player);
                }
            }
            bool result = board.isFull();
            Assert::IsTrue(result);
        }

        TEST_METHOD(TestPlayerSymbol)
        {
            Player player('X');
            char symbol = player.getSymbol();
            Assert::AreEqual('X', symbol);
        }

        TEST_METHOD(TestAntiDiagonalWin)
        {
            Board board;
            board.makeMove(1, 4, 'X');
            board.makeMove(2, 3, 'X');
            board.makeMove(3, 2, 'X');
            board.makeMove(4, 1, 'X');
            bool result = board.checkWin('X');
            Assert::IsTrue(result);
        }
    };
}