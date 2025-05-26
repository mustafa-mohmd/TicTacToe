#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

// Function to initialize the Tic-Tac-Toe board
void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            board[i][j] = ' ';
        }
    }
}

// Function to print the Tic-Tac-Toe board
void printBoard(char board[SIZE][SIZE]) {
    printf("\n   1   2   3\n");
    for (int i = 0; i < SIZE; ++i) {
        printf("%d ", i + 1);
        for (int j = 0; j < SIZE; ++j) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) {
                printf("|");
            }
        }
        printf("\n");
        if (i < SIZE - 1) {
            printf("  -----------\n");
        }
    }
    printf("\n");
}

// Function to check if a player has won
int checkWin(char board[SIZE][SIZE], char player) {
    // Check rows and columns
    for (int i = 0; i < SIZE; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return 1;  // Player wins
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return 1;  // Player wins
    }

    return 0;  // No winner yet
}

// Function to check if the board is full (game ends in a draw)
int checkDraw(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == ' ') {
                return 0;  // The board is not full
            }
        }
    }
    return 1;  // The board is full (draw)
}

int main() {
    char board[SIZE][SIZE];
    int row, col;
    char currentPlayer = 'X';

    initializeBoard(board);

    do {
        printBoard(board);

        // Player's move
        printf("Player %c, enter your move (row and column, range: 1 to 3): ", currentPlayer);
        scanf("%d %d", &row, &col);

        // Check if the move is valid
        if (row >= 1 && row <= SIZE && col >= 1 && col <= SIZE && board[row - 1][col - 1] == ' ') {
            board[row - 1][col - 1] = currentPlayer;

            // Check if the player has won
            if (checkWin(board, currentPlayer)) {
                printBoard(board);
                printf("Player %c wins!\n", currentPlayer);
                break;
            }

            // Check if the game is a draw
            if (checkDraw(board)) {
                printBoard(board);
                printf("The game is a draw!\n");
                break;
            }

            // Switch to the other player
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            printf("Invalid move. Try again.\n");
        }
    } while (1);

    return 0;
}