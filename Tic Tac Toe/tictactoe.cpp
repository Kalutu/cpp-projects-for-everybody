#include <iostream>
using namespace std;

// Function to print the current state of the game board
void printBoard(char board[]) {
    cout << "-------------" << endl;
    cout << "| " << board[0] << " | " << board[1] << " | " << board[2] << " |" << endl;
    cout << "-------------" << endl;
    cout << "| " << board[3] << " | " << board[4] << " | " << board[5] << " |" << endl;
    cout << "-------------" << endl;
    cout << "| " << board[6] << " | " << board[7] << " | " << board[8] << " |" << endl;
    cout << "-------------" << endl;
}

// Function to check if the game is over
bool gameOver(char board[], char player) {
    // Check if any row is completely filled by the same player
    for(int i = 0; i < 9; i += 3) {
        if(board[i] == player && board[i+1] == player && board[i+2] == player) {
            return true;
        }
    }
    // Check if any column is completely filled by the same player
    for(int i = 0; i < 3; i++) {
        if(board[i] == player && board[i+3] == player && board[i+6] == player) {
            return true;
        }
    }
    // Check if any diagonal is completely filled by the same player
    if(board[0] == player && board[4] == player && board[8] == player) {
        return true;
    }
    if(board[2] == player && board[4] == player && board[6] == player) {
        return true;
    }
    // Check if the board is completely filled (tie)
    for(int i = 0; i < 9; i++) {
        if(board[i] == ' ') {
            return false;
        }
    }
    return true;
}

// Function to play the game
void playGame() {
    char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}; // Initialize the board
    char player = 'X'; // Player X goes first
    bool isGameOver = false;
    while(!isGameOver) {
        printBoard(board);
        int move;
        cout << "Player " << player << ", enter a move (1-9): ";
        cin >> move;
        move--; // Decrement by 1 to convert to zero-based indexing
        if(move < 0 || move > 8 || board[move] != ' ') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }
        board[move] = player;
        if(gameOver(board, player)) {
            printBoard(board);
            cout << "Player " << player << " wins!" << endl;
            isGameOver = true;
        } else if(player == 'X') {
            player = 'O';
        } else {
            player = 'X';
        }
    }
}

// Main function to start the game
int main() {
    playGame();
    return 0;
}
