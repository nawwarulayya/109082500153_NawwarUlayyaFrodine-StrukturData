#ifndef OPERASI_H_INCLUDED
#define OPERASI_H_INCLUDED

const int BARIS = 3;
const int KOLOM = 3;

void tampilArray(int arr[BARIS][KOLOM]);

void tukarArray(int A[BARIS][KOLOM], int B[BARIS][KOLOM], int baris, int kolom);

void tukarPointer(int *p1, int *p2);

#endif // OPERASI_H_INCLUDED