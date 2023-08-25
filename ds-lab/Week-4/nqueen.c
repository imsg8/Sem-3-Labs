#include <stdio.h>
#include <stdbool.h>
int N;
bool is_safe(int board[N][N], int row, int col) {
    // Check if a queen can be placed in the current position
    // without conflicting with other queens.
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
        if (col - (row - i) >= 0 && board[i][col - (row - i)] == 1) {
            return false;
        }
        if (col + (row - i) < N && board[i][col + (row - i)] == 1) {
            return false;
        }
    }
    return true;
}
int count_n_queen_solutions(int board[N][N], int row) {
    // Base case: If all queens are placed successfully, return 1.
    if (row == N) {
        return 1;
    }
    int count = 0;
    for (int col = 0; col < N; col++) {
        if (is_safe(board, row, col)) {
            // Place the queen and move to the next row.
            board[row][col] = 1;
            count += count_n_queen_solutions(board, row + 1);

            // Backtrack: Remove the queen from the current position.
            board[row][col] = 0;
        }
    }

    return count;
}

int n_queen_solutions() {
    // Create an empty N×N chessboard.
    int board[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }

    // Start with the first row and find solutions recursively.
    return count_n_queen_solutions(board, 0);
}
int main() {
    printf("Write the value of N - ");
    scanf("%d",&N);
    int num_solutions = n_queen_solutions();
    printf("The number of possible solutions for %d-Queens problem is: %d\n", N, num_solutions);

    return 0;
}