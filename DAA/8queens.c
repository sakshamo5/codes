#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isSafe(int *board, int row, int col, int n) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return false;
    }
    return true;
}

void solve(int *board, int row, int n, int *solutionCount) {
    if (row == n) {
        (*solutionCount)++;
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row] = col;
            solve(board, row + 1, n, solutionCount);
        }
    }
}

int main() {
    int n = 8;
    int *board = (int *)malloc(n * sizeof(int));
    int solutionCount = 0;

    solve(board, 0, n, &solutionCount);

    printf("Number of solutions for %d-Queens: %d\n", n, solutionCount);

    free(board);
    return 0;
}
