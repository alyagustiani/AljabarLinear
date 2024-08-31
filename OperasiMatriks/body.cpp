#include "header.h"
#include <cstdio>

void inputMatrix(int rows, int cols, int matrix[][100]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Masukkan elemen matriks [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int rows, int cols, int matrix[][100]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int rows, int cols, int matrix1[][100], int matrix2[][100], int result[][100]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void subtractMatrices(int rows, int cols, int matrix1[][100], int matrix2[][100], int result[][100]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void multiplyMatrices(int rows1, int cols1, int matrix1[][100], int rows2, int cols2, int matrix2[][100], int result[][100]) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void scalarMultiply(int rows, int cols, int matrix[][100], int scalar, int result[][100]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix[i][j] * scalar;
        }
    }
}

void transposeMatrix(int rows, int cols, int matrix[][100], int result[][100]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

int traceMatrix(int rows, int cols, int matrix[][100]) {
    int trace = 0;
    for (int i = 0; i < rows && i < cols; i++) {
        trace += matrix[i][i];
    }
    return trace;
}

void initZeroMatrix(int rows, int cols, int matrix[][100]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = 0;
        }
    }
}

void initIdentityMatrix(int size, int matrix[][100]) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = (i == j) ? 1 : 0;
        }
    }
}

