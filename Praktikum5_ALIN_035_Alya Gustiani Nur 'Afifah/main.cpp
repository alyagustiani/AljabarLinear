#include "header.h"
#include <iostream>

using namespace std;

int main() {
    int baris, kolom, i, j;
    double matriks[MAKS][MAKS];
    char ulang;

    do {
        printf("=========================================\n");
        printf("      KALKULATOR ELIMINASI GAUSS-JORDAN  \n");
        printf("=========================================\n\n");

        // Input ukuran matriks
        printf("Masukkan ukuran matriks:\n");
        printf("Jumlah baris: ");
        scanf("%d", &baris);
        printf("Jumlah kolom: ");
        scanf("%d", &kolom);
        printf("\nMatriks augmented memiliki ukuran %dx%d\n", baris, kolom);

        // Input elemen-elemen matriks augmented
        printf("\nMasukkan elemen augmented matriks:\n");
        for (i = 0; i < baris; i++) {
            for (j = 0; j < kolom; j++) {
                printf("Masukkan elemen matriks [%d][%d]: ", i + 1, j + 1);
                scanf("%lf", &matriks[i][j]);
            }
        }

        eliminasiGaussJordan(matriks, baris, kolom);

        // Menanyakan apakah ingin melakukan perhitungan lagi
        printf("\nApakah Anda ingin melakukan perhitungan lagi? (y/n): ");
        scanf(" %c", &ulang);  // Mengambil input untuk mengulang atau tidak
    } while (ulang == 'y' || ulang == 'Y');

    printf("Program selesai.\n");

    return 0;
}

