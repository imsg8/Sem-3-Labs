#include <stdio.h>
#include <stdlib.h>

// Function to allocate memory for a matrix
int **allocateMatrix(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }
    return matrix;
}

// Function to input matrix elements
void inputMatrix(int **matrix, int rows, int cols) {
    printf("Enter matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display matrix elements
void displayMatrix(int **matrix, int rows, int cols) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to find the product of two matrices
int **multiplyMatrices(int **matrix1, int rows1, int cols1,
                       int **matrix2, int rows2, int cols2) {
    if (cols1 != rows2) {
        printf("Matrix multiplication is not possible.\n");
        return NULL;
    }

    int **result = allocateMatrix(rows1, cols2);

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}

int main() {
    int rows1, cols1, rows2, cols2;

    printf("Enter the number of rows and columns for the first matrix: ");
    scanf("%d %d", &rows1, &cols1);

    printf("Enter the number of rows and columns for the second matrix: ");
    scanf("%d %d", &rows2, &cols2);

    if (cols1 != rows2) {
        printf("Matrix multiplication is not possible.\n");
        return 1;
    }

    int **matrix1 = allocateMatrix(rows1, cols1);
    int **matrix2 = allocateMatrix(rows2, cols2);

    printf("Enter elements for the first matrix:\n");
    inputMatrix(matrix1, rows1, cols1);

    printf("Enter elements for the second matrix:\n");
    inputMatrix(matrix2, rows2, cols2);

    printf("First ");
    displayMatrix(matrix1, rows1, cols1);

    printf("Second ");
    displayMatrix(matrix2, rows2, cols2);

    int **result = multiplyMatrices(matrix1, rows1, cols1, matrix2, rows2, cols2);

    if (result != NULL) {
        printf("Product ");
        displayMatrix(result, rows1, cols2);

        // Free dynamically allocated memory
        for (int i = 0; i < rows1; i++) {
            free(matrix1[i]);
        }
        free(matrix1);

        for (int i = 0; i < rows2; i++) {
            free(matrix2[i]);
        }
        free(matrix2);

        for (int i = 0; i < rows1; i++) {
            free(result[i]);
        }
        free(result);
    }

    return 0;
}