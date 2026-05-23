#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print the Tic-Tac-Toe board with row and column numbers
void printBoard(char board[3][3]) {
    printf("\n");
    printf("    1   2   3\n"); // Column numbers
    for (int i = 0; i < 3; i++) {
        printf("%d   ", i + 1); // Row numbers
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("   -----------\n");
    }
    printf("\n");
}

// Function to check if a player has won
int checkWin(char board[3][3], char player) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return 1; // Player wins
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return 1; // Player wins
    }

    return 0; // No winner yet
}

// Function to check if the board is full
int isBoardFull(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0; // Board is not full
            }
        }
    }
    return 1; // Board is full
}

// Function for user vs user game
void playUserVsUser(char board[3][3]) {
    char player = 'X';
    int row, col;

    do {
        printBoard(board);

        // Get user move
        printf("Player %c, enter your move (row and column): ", player);
        scanf("%d %d", &row, &col);

        // Check if the move is valid
        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            printf("Invalid move. Try again.\n");
            continue;
        }

        // Make the move
        board[row - 1][col - 1] = player;

        // Check for a win
        if (checkWin(board, player)) {
            printBoard(board);
            printf("Player %c wins!\n", player);
            return;
        }

        // Check for a tie
        if (isBoardFull(board)) {
            printBoard(board);
            printf("It's a tie!\n");
            return;
        }

        // Switch player for the next turn
        player = (player == 'X') ? 'O' : 'X';

    } while (1);
}

// Function for user vs computer game
void playUserVsComputer(char board[3][3]) {
    char player = 'X';
    int row, col;

    do {
        printBoard(board);

        // Get user move
        if (player == 'X') {
            printf("Player X, enter your move (row and column): ");
            scanf("%d %d", &row, &col);
        } else {
            // Computer's move (randomly selected)
            row = rand() % 3 + 1;
            col = rand() % 3 + 1;
            printf("Computer (Player O) chooses: %d %d\n", row, col);
        }

        // Check if the move is valid
        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            printf("Invalid move. Try again.\n");
            continue;
        }

        // Make the move
        board[row - 1][col - 1] = player;

        // Check for a win
        if (checkWin(board, player)) {
            printBoard(board);
            if (player == 'X') {
                printf("Player X wins!\n");
            } else {
                printf("Computer (Player O) wins!\n");
            }
            return;
        }

        // Check for a tie
        if (isBoardFull(board)) {
            printBoard(board);
            printf("It's a tie!\n");
            return;
        }

        // Switch player for the next turn
        player = (player == 'X') ? 'O' : 'X';

    } while (1);
}

int main() {
    char board[3][3] = { { ' ', ' ', ' ' }, { ' ', ' ', ' ' }, { ' ', ' ', ' ' } };
    int choice;

    // Seed for random number generation in playUserVsComputer
    srand(time(NULL));

    printf("Tic-Tac-Toe Game\n");
    printf("1. User vs User\n");
    printf("2. User vs Computer\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            playUserVsUser(board);
            break;
        case 2:
            playUserVsComputer(board);
            break;
        default:
            printf("Invalid choice. Exiting.\n");
            return 1;
    }

    return 0;
}
