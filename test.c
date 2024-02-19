#include <iostream>
#include <vector>

class TicTacToe {
private:
    std::vector<std::vector<char>> board;
    char currentPlayer;

public:
    TicTacToe() : board(3, std::vector<char>(3, ' ')), currentPlayer('X') {}

    void printBoard() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                std::cout << board[i][j];
                if (j < 2) std::cout << " | ";
            }
            std::cout << std::endl;
            if (i < 2) std::cout << "---------" << std::endl;
        }
    }

    bool makeMove(int row, int col) {
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            std::cout << "Invalid move. Try again." << std::endl;
            return false;
        }

        board[row][col] = currentPlayer;
        switchPlayer();
        return true;
    }

    bool checkWin() {
        // Check rows and columns
        for (int i = 0; i < 3; ++i) {
            if ((board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') ||
                (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')) {
                return true;
            }
        }

        // Check diagonals
        if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') ||
            (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')) {
            return true;
        }

        return false;
    }

    bool isBoardFull() {
        for (const auto &row : board) {
            for (char cell : row) {
                if (cell == ' ') {
                    return false;
                }
            }
        }
        return true;
    }

private:
    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
};

int main() {
    TicTacToe game;

    do {
        game.printBoard();

        int row, col;
        std::cout << "Player " << game.getCurrentPlayer() << ", enter your move (row and column): ";
        std::cin >> row >> col;

        if (game.makeMove(row, col)) {
            if (game.checkWin()) {
                game.printBoard();
                std::cout << "Player " << game.getCurrentPlayer() << " wins! Congratulations!" << std::endl;
                break;
            } else if (game.isBoardFull()) {
                game.printBoard();
                std::cout << "It's a tie! The board is full." << std::endl;
                break;
            }
        }

    } while (true);

    return 0;
}
