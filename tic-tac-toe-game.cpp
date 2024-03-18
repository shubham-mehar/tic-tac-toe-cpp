#include <iostream>
#include <vector>

using namespace std;

// Function to print the TicTacToe board
void printBoard(const vector<vector<char> >& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

// Function to check if there's a winner
char checkWinner(const vector<vector<char> >& board) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return board[i][0];
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return board[0][i];
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return board[0][2];

    // If no winner yet
    return ' ';
}

int main() {
    vector<vector<char> > board(3, vector<char>(3, ' '));
    int row, col;
    char currentPlayer = 'X';
    int moves = 0;

    // Game loop
    while (true) {
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        // Check if the cell is empty and the input is valid
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;
            ++moves;
        } else {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        printBoard(board);

        // Check for a winner or a draw
        char winner = checkWinner(board);
        if (winner != ' ') {
            cout << "Player " << winner << " wins!\n";
            break;
        } else if (moves == 9) {
            cout << "It's a draw!\n";
            break;
        }

        // Switch player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
