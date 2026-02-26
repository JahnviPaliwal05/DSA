//Given a matrix if an element in the matrix is 0 then you will have to set its entire column and row to 0 and then return the matrix.

#include <stdio.h>
#include <stdlib.h>

void markRow(int **matrix, int n, int m, int i) {
    for (int j = 0; j < m; j++) {
        if (matrix[i][j] != 0) {
            matrix[i][j] = -1;
        }
    }
}

void markCol(int **matrix, int n, int m, int j) {
    for (int i = 0; i < n; i++) {
        if (matrix[i][j] != 0) {
            matrix[i][j] = -1;
        }
    }
}

int **zeroMatrix(int **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                markRow(matrix, n, m, i);
                markCol(matrix, n, m, j);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == -1) {
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}

int main() {
    int matrix_data[3][3] = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int n = 3;
    int m = 3;

    // Allocate memory for the matrix
    int **matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(m * sizeof(int));
        for(int j = 0; j < m; j++){
            matrix[i][j] = matrix_data[i][j];
        }
    }

    int **ans = zeroMatrix(matrix, n, m);

    printf("The Final matrix is:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
