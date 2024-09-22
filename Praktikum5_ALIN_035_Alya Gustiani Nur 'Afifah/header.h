#ifndef HEADER_H
#define HEADER_H

#define MAKS 10

// Fungsi untuk mencari FPB (Faktor Persekutuan Terbesar)
int fpb(int a, int b);

// Fungsi untuk mengubah desimal menjadi pecahan
void desimalKePecahan(double desimal, int &pembilang, int &penyebut);

// Fungsi untuk menampilkan pecahan di bagian solusi
void cetakPecahanSolusi(double desimal);

// Fungsi untuk menampilkan solusi parametrik
void tampilkanSolusiParametrik(double matriks[MAKS][MAKS], int baris, int kolom);

// Fungsi untuk melakukan eliminasi Gauss-Jordan
void eliminasiGaussJordan(double matriks[MAKS][MAKS], int baris, int kolom);

#endif

