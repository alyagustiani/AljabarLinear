#ifndef HEADER_H
#define HEADER_H

void inputMatrix(int rows, int cols, int matrix[][100]);
void printMatrix(int rows, int cols, int matrix[][100]);
void addMatrices(int rows, int cols, int matrix1[][100], int matrix2[][100], int result[][100]);
void subtractMatrices(int rows, int cols, int matrix1[][100], int matrix2[][100], int result[][100]);
void multiplyMatrices(int rows1, int cols1, int matrix1[][100], int rows2, int cols2, int matrix2[][100], int result[][100]);
void scalarMultiply(int rows, int cols, int matrix[][100], int scalar, int result[][100]);
void transposeMatrix(int rows, int cols, int matrix[][100], int result[][100]);
int traceMatrix(int rows, int cols, int matrix[][100]);
void initZeroMatrix(int rows, int cols, int matrix[][100]);
void initIdentityMatrix(int size, int matrix[][100]);

#endif

