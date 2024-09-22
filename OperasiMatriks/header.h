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
void kombinasiLinearMatriks(int baris, int kolom, int jumlahMatriks, int matriks[][100][100], int skalar[], int hasil[][100]);
bool inversMatriks2x2(int matriks[2][2], float hasil[2][2]);
void printMatrixFloat(int rows, int cols, float matrix[100][100]);
void inputMatrix2x2(int matrix[2][2]);
void printMatrixFloat2x2(float matrix[2][2]);


#endif

