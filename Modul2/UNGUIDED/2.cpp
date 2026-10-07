#include <iostream>
using namespace std;

void tukarPointer(int *a, int *b, int *c) {
    int temp;

    temp = *a;
    *a = *b;
    *b = *c;
    *c = temp;
}

void tukarReference(int &a, int &b, int &c) {
    int temp;

    temp = a;
    a = b;
    b = c;
    c = temp;
}

int main() {
    int a, b, c;
    int pilihan;

    cout << "Masukkan nilai a : ";
    cin >> a;

    cout << "Masukkan nilai b : ";
    cin >> b;

    cout << "Masukkan nilai c : ";
    cin >> c;

    cout << "\nNilai sebelum ditukar:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    cout << "\n=== MENU ===" << endl;
    cout << "1. Menggunakan Pointer" << endl;
    cout << "2. Menggunakan Reference" << endl;
    cout << "Pilih : ";
    cin >> pilihan;

    if (pilihan == 1) {

        tukarPointer(&a, &b, &c);

    } else if (pilihan == 2) {

        tukarReference(a, b, c);

    } else {

        cout << "Pilihan tidak tersedia!" << endl;
        return 0;
    }

    cout << "\nNilai setelah ditukar:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    return 0;
}