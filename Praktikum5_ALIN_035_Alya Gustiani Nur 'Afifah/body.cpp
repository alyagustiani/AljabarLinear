#include "header.h"
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

// Fungsi untuk mencari FPB (Faktor Persekutuan Terbesar)
int fpb(int a, int b) {
    if (b == 0) return a;
    return fpb(b, a % b);
}

// Fungsi untuk mengubah desimal menjadi pecahan
void desimalKePecahan(double desimal, int &pembilang, int &penyebut) {
    double presisi = 1e-6;  // Batas presisi untuk menghindari kesalahan pembulatan
    int penyebut_saat_ini = 1;

    // Mengubah desimal menjadi pecahan sederhana
    while (fabs(desimal - round(desimal)) > presisi) {
        desimal *= 10;
        penyebut_saat_ini *= 10;
    }

    pembilang = (int)round(desimal);
    penyebut = penyebut_saat_ini;

    // Mencari FPB agar pecahan dalam bentuk sederhana
    int fpb_pecahan = fpb(abs(pembilang), abs(penyebut));
    pembilang /= fpb_pecahan;
    penyebut /= fpb_pecahan;
}

// Fungsi untuk menampilkan pecahan di bagian solusi
void cetakPecahanSolusi(double desimal) {
    int pembilang, penyebut;
    desimalKePecahan(desimal, pembilang, penyebut);

    if (penyebut == 1) {
        printf("%.2f", desimal);  // Menampilkan sebagai desimal jika pecahan sederhana
    } else {
        printf("%d/%d", pembilang, penyebut);  // Menampilkan pecahan
    }
}

// Fungsi untuk menampilkan solusi parametrik
void tampilkanSolusiParametrik(double matriks[MAKS][MAKS], int baris, int kolom) {
    bool bebas[MAKS] = {false};  // Menandai variabel bebas

    // Tandai variabel bebas jika tidak ada persamaan yang membatasinya
    for (int i = 0; i < baris; i++) {
        bool semuaNol = true;
        for (int j = 0; j < kolom - 1; j++) {
            if (matriks[i][j] != 0) {
                semuaNol = false;
                break;
            }
        }
        if (semuaNol && matriks[i][kolom - 1] == 0) {
            bebas[i] = true;
        }
    }

    printf("\n=========================================\n");
    printf("                 SOLUSI PARAMETRIK       \n");
    printf("=========================================\n");

    for (int i = 0; i < baris; i++) {
        if (bebas[i]) {
            printf("x[%d] = free\n", i + 1);
        } else {
            printf("x[%d] = ", i + 1);
            bool pertama = true;

            for (int j = i + 1; j < kolom - 1; j++) {
                if (matriks[i][j] != 0) {
                    if (!pertama) {
                        printf(" + ");
                    }
                    printf("-%.2f", matriks[i][j]);  // Menampilkan koefisien dalam desimal
                    printf("x[%d]", j + 1);
                    pertama = false;
                }
            }

            if (!pertama) {
                printf(" + ");
            }
            printf("%.2f", matriks[i][kolom - 1]);  // Solusi dalam desimal
            printf(" (");  // Pecahan di dalam tanda kurung
            cetakPecahanSolusi(matriks[i][kolom - 1]);  // Solusi dalam pecahan
            printf(")\n");
        }
    }
}

// Fungsi untuk melakukan eliminasi Gauss-Jordan
void eliminasiGaussJordan(double matriks[MAKS][MAKS], int baris, int kolom) {
    int i, j, k;
    double rasio;

    printf("\n=========================================\n");
    printf("      METODE ELIMINASI GAUSS-JORDAN      \n");
    printf("=========================================\n");

    printf("\nMatriks awal:\n");
    for (i = 0; i < baris; i++) {
        for (j = 0; j < kolom; j++) {
            printf("%.2f\t", matriks[i][j]);  // Menampilkan elemen matriks dalam desimal
        }
        printf("\n");
    }

    for (i = 0; i < baris; i++) {
        // Membuat diagonal utama menjadi 1
        if (matriks[i][i] == 0) {
            printf("Tidak dapat menyelesaikan karena elemen diagonal 0 pada baris %d\n", i + 1);
            return;
        }

        printf("\nOperasi: R%d / %.2f\n", i + 1, matriks[i][i]);
        double pembagi = matriks[i][i];
        for (j = 0; j < kolom; j++) {
            matriks[i][j] /= pembagi;  // Melakukan pembagian untuk membuat elemen diagonal 1
        }

        // Membuat elemen di atas dan di bawah diagonal menjadi 0
        for (j = 0; j < baris; j++) {
            if (i != j) {
                rasio = matriks[j][i];

                printf("Operasi: R%d - (%.2f) * R%d\n", j + 1, rasio, i + 1);
                for (k = 0; k < kolom; k++) {
                    matriks[j][k] -= rasio * matriks[i][k];  // Operasi pengurangan
                }
            }
        }

        printf("\nMatriks setelah langkah %d:\n", i + 1);
        for (j = 0; j < baris; j++) {
            for (k = 0; k < kolom; k++) {
                printf("%.2f\t", matriks[j][k]);  // Menampilkan matriks setelah langkah dalam desimal
            }
            printf("\n");
        }
    }

    tampilkanSolusiParametrik(matriks, baris, kolom);  // Menampilkan solusi parametrik
}

