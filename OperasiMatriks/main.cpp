#include <cstdio>
#include <cstdlib>
#include "header.h"

int main() {
    int choice;
    int rows, cols, rows2, cols2, scalar, trace;
    int matrix1[100][100], matrix2[100][100], result[100][100];

    do {
        printf("\n=== MENU OPERASI MATRIKS ===\n");
        printf("1. Penjumlahan Matriks\n");
        printf("2. Pengurangan Matriks\n");
        printf("3. Perkalian Matriks\n");
        printf("4. Perkalian Matriks dengan Scalar\n");
        printf("5. Transpose Matriks\n");
        printf("6. Trace Matriks\n");
        printf("7. Inisiasi Matriks Nol\n");
        printf("8. Inisiasi Matriks Identitas\n");
        printf("0. Keluar\n");
        printf("Pilih operasi (0-8): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Masukkan jumlah baris matriks: ");
                scanf("%d", &rows);
                printf("Masukkan jumlah kolom matriks: ");
                scanf("%d", &cols);
                printf("Masukkan elemen-elemen matriks pertama:\n");
                inputMatrix(rows, cols, matrix1);
                printf("Masukkan elemen-elemen matriks kedua:\n");
                inputMatrix(rows, cols, matrix2);
                addMatrices(rows, cols, matrix1, matrix2, result);
                printf("\nHasil penjumlahan matriks:\n");
                printMatrix(rows, cols, result);
                break;

            case 2:
                printf("Masukkan jumlah baris matriks: ");
                scanf("%d", &rows);
                printf("Masukkan jumlah kolom matriks: ");
                scanf("%d", &cols);
                printf("Masukkan elemen-elemen matriks pertama:\n");
                inputMatrix(rows, cols, matrix1);
                printf("Masukkan elemen-elemen matriks kedua:\n");
                inputMatrix(rows, cols, matrix2);
                subtractMatrices(rows, cols, matrix1, matrix2, result);
                printf("\nHasil pengurangan matriks:\n");
                printMatrix(rows, cols, result);
                break;

            case 3:
                printf("Masukkan jumlah baris matriks pertama: ");
                scanf("%d", &rows);
                printf("Masukkan jumlah kolom matriks pertama: ");
                scanf("%d", &cols);
                printf("Masukkan elemen-elemen matriks pertama:\n");
                inputMatrix(rows, cols, matrix1);
                printf("Masukkan jumlah baris matriks kedua: ");
                scanf("%d", &rows2);
                printf("Masukkan jumlah kolom matriks kedua: ");
                scanf("%d", &cols2);
                if (cols == rows2) {
                    printf("Masukkan elemen-elemen matriks kedua:\n");
                    inputMatrix(rows2, cols2, matrix2);
                    multiplyMatrices(rows, cols, matrix1, rows2, cols2, matrix2, result);
                    printf("\nHasil perkalian matriks:\n");
                    printMatrix(rows, cols2, result);
                } else {
                    printf("Perkalian tidak dapat dilakukan, jumlah kolom matriks pertama harus sama dengan jumlah baris matriks kedua.\n");
                }
                break;

            case 4:
                printf("Masukkan jumlah baris matriks: ");
                scanf("%d", &rows);
                printf("Masukkan jumlah kolom matriks: ");
                scanf("%d", &cols);
                printf("Masukkan elemen-elemen matriks:\n");
                inputMatrix(rows, cols, matrix1);
                printf("Masukkan nilai scalar: ");
                scanf("%d", &scalar);
                scalarMultiply(rows, cols, matrix1, scalar, result);
                printf("\nHasil perkalian matriks dengan scalar:\n");
                printMatrix(rows, cols, result);
                break;

            case 5:
                printf("Masukkan jumlah baris matriks: ");
                scanf("%d", &rows);
                printf("Masukkan jumlah kolom matriks: ");
                scanf("%d", &cols);
                printf("Masukkan elemen-elemen matriks:\n");
                inputMatrix(rows, cols, matrix1);
                transposeMatrix(rows, cols, matrix1, result);
                printf("\nHasil transpose matriks:\n");
                printMatrix(cols, rows, result);
                break;

            case 6:
                printf("Masukkan jumlah baris matriks (hanya matriks persegi): ");
                scanf("%d", &rows);
                printf("Masukkan jumlah kolom matriks: ");
                scanf("%d", &cols);
                if (rows == cols) {
                    printf("Masukkan elemen-elemen matriks:\n");
                    inputMatrix(rows, cols, matrix1);
                    trace = traceMatrix(rows, cols, matrix1);
                    printf("\nTrace dari matriks adalah: %d\n", trace);
                } else {
                    printf("Trace hanya dapat dihitung untuk matriks persegi.\n");
                }
                break;

            case 7:
                printf("Masukkan jumlah baris matriks: ");
                scanf("%d", &rows);
                printf("Masukkan jumlah kolom matriks: ");
                scanf("%d", &cols);
                initZeroMatrix(rows, cols, result);
                printf("\nMatriks nol:\n");
                printMatrix(rows, cols, result);
                break;

            case 8:
                printf("Masukkan ukuran matriks persegi (n x n): ");
                scanf("%d", &rows);
                initIdentityMatrix(rows, result);
                printf("\nMatriks identitas:\n");
                printMatrix(rows, rows, result);
                break;

            case 0:
                printf("Keluar dari program.\n");
                break;

            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}

