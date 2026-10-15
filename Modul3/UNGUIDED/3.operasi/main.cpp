#include <iostream>
#include "operasi.h"
using namespace std;

int main() {
    int A[BARIS][KOLOM] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int B[BARIS][KOLOM] = {{10, 20, 30}, {40, 50, 60}, {70, 80, 90}};

    int x = 100, y = 200;
    int *p1 = &x;
    int *p2 = &y;

    cout << "=== Array A (awal) ===" << endl;
    tampilArray(A);
    cout << "\n=== Array B (awal) ===" << endl;
    tampilArray(B);

    int baris = 1, kolom = 1;
    tukarArray(A, B, baris, kolom);

    cout << "\n=== Setelah tukar posisi [" << baris << "][" << kolom << "] ===" << endl;
    cout << "Array A:" << endl;
    tampilArray(A);
    cout << "Array B:" << endl;
    tampilArray(B);

    cout << "\n=== Pointer (awal) ===" << endl;
    cout << "*p1 = " << *p1 << ", *p2 = " << *p2 << endl;

    tukarPointer(p1, p2);

    cout << "=== Pointer (setelah tukar) ===" << endl;
    cout << "*p1 = " << *p1 << ", *p2 = " << *p2 << endl;

    return 0;
}