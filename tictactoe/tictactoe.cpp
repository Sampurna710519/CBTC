#include <iostream>
#include <vector>

class TicTacToe {
private:
    char currentPlayer;
    std::vector<std::vector<char>> board;

public:
    TicTacToe() : currentPlayer('X'), board(3, std::vector<char>(3, ' ')) {}

    char getCurrentPlayer() const {
        return currentPlayer;
    }

    void printBoard() const {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                std::cout << board[i][j];
                if (j < 2) std::cout << " | ";
            }
            std::cout << std::endl;
            if (i < 2) std::cout << "---------" << std::endl;
        }
        std::cout << std::endl;
    }

    bool makeMove(int row, int col) {
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            return false;
        }
        board[row][col] = currentPlayer;
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        return true;
    }

    char checkWinner() const {
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                return board[i][0];
            }
            if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
                return board[0][i];
            }
        }
        if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            return board[0][0];
        }
        if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            return board[0][2];
        }
        return ' ';
    }
};

int main() {
    TicTacToe game;
    int row, col;

    std::cout << "Welcome to Tic-Tac-Toe!" << std::endl;

    while (true) {
        game.printBoard();

        std::cout << "Player " << game.getCurrentPlayer() << ", enter your move (row column): ";
        std::cin >> row >> col;

        if (game.makeMove(row, col)) {
            char winner = game.checkWinner();
            if (winner != ' ') {
                game.printBoard();
                std::cout << "Player " << winner << " wins!" << std::endl;
                break;
            }
        } else {
            std::cout << "Invalid move. Try again." << std::endl;
        }
    }

    return 0;
}
