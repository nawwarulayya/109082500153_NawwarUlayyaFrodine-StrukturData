#include <iostream>
using namespace std;

int cariMinimum(int arr[], int n) {
    int minimum = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < minimum) {
            minimum = arr[i];
        }
    }

    return minimum;
}

int cariMaksimum(int arr[], int n) {
    int maksimum = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > maksimum) {
            maksimum = arr[i];
        }
    }

    return maksimum;
}

void hitungRataRata(int arr[], int n) {
    int total = 0;

    for (int i = 0; i < n; i++) {
        total = total + arr[i];
    }

    float rataRata = (float) total / n;

    cout << "Nilai rata-rata = " << rataRata << endl;
}

int main() {

    int arrA[] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    int n = 10;
    int pilihan;

    do {
        cout << "\n--- Menu Program Array ---" << endl;
        cout << "1. Tampilkan isi array" << endl;
        cout << "2. Cari nilai maksimum" << endl;
        cout << "3. Cari nilai minimum" << endl;
        cout << "4. Hitung nilai rata-rata" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu : ";
        cin >> pilihan;

        if (pilihan == 1) {

            cout << "\nIsi Array:" << endl;

            for (int i = 0; i < n; i++) {
                cout << arrA[i] << " ";
            }

            cout << endl;

        } else if (pilihan == 2) {

            cout << "\nNilai maksimum = "
                 << cariMaksimum(arrA, n) << endl;

        } else if (pilihan == 3) {

            cout << "\nNilai minimum = "
                 << cariMinimum(arrA, n) << endl;

        } else if (pilihan == 4) {

            cout << "\n";
            hitungRataRata(arrA, n);

        } else if (pilihan == 5) {

            cout << "\nProgram selesai." << endl;

        } else {

            cout << "\nPilihan tidak tersedia!" << endl;
        }

    } while (pilihan != 5);

    return 0;
}