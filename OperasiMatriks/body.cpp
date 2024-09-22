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

void kombinasiLinearMatriks(int baris, int kolom, int jumlahMatriks, int matriks[10][100][100], int skalar[], int hasil[100][100]) {
    // Inisialisasi hasil dengan matriks nol
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            hasil[i][j] = 0;
        }
    }

    // Lakukan kombinasi linear
    for (int m = 0; m < jumlahMatriks; m++) {
        for (int i = 0; i < baris; i++) {
            for (int j = 0; j < kolom; j++) {
                hasil[i][j] += skalar[m] * matriks[m][i][j];
            }
        }
    }
}

bool inversMatriks2x2(int matriks[2][2], float hasil[2][2]) {
    int determinan = matriks[0][0] * matriks[1][1] - matriks[0][1] * matriks[1][0];
    
    if (determinan == 0) {
        printf("Matriks tidak memiliki invers.\n");
        return false;
    }

    float inversDeterminan = 1.0 / determinan;
    
    hasil[0][0] =  matriks[1][1] * inversDeterminan;
    hasil[0][1] = -matriks[0][1] * inversDeterminan;
    hasil[1][0] = -matriks[1][0] * inversDeterminan;
    hasil[1][1] =  matriks[0][0] * inversDeterminan;

    return true;
}

void printMatrixFloat(int rows, int cols, float matrix[100][100]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

void inputMatrix2x2(int matrix[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("Masukkan elemen matriks [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrixFloat2x2(float matrix[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}



