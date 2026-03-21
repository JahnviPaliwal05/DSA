#include <stdio.h>

#define N 8

int board[N][N];

// Function to check if placing queen at (row, col) is safe
int isSafe(int row, int col) {
    int i, j;

    // Check row on left side
    for(i = 0; i < col; i++)
        if(board[row][i])
            return 0;

    // Check upper diagonal on left side
    for(i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if(board[i][j])
            return 0;

    // Check lower diagonal on left side
    for(i = row, j = col; i < N && j >= 0; i++, j--)
        if(board[i][j])
            return 0;

    return 1;
}

// Backtracking function to solve N-Queens
int solveNQueen(int col) {
    if(col >= N)
        return 1;  // Found a solution

    int res = 0;
    for(int i = 0; i < N; i++) {
        if(isSafe(i, col)) {
            board[i][col] = 1;           // Place queen
            res += solveNQueen(col + 1); // Recurse
            board[i][col] = 0;           // Backtrack
        }
    }
    return res;
}

int main() {
    // Initialize board with 0
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            board[i][j] = 0;

    int totalSolutions = solveNQueen(0);

    printf("Total solutions for N=%d: %d\n", N, totalSolutions);

    return 0;
}