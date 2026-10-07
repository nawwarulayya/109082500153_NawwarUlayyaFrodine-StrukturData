#include <iostream>
using namespace std;

int main() {
    int A[3][3], B[3][3], hasil[3][3];
    int pilihan;

    cout << "=== INPUT MATRIKS A ===" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
    }

    cout << "\n=== INPUT MATRIKS B ===" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "B[" << i << "][" << j << "] = ";
            cin >> B[i][j];
        }
    }

    cout << "\n=== MENU OPERASI MATRIKS ===" << endl;
    cout << "1. Penjumlahan" << endl;
    cout << "2. Pengurangan" << endl;
    cout << "3. Perkalian" << endl;
    cout << "Pilih menu : ";
    cin >> pilihan;

    if (pilihan == 1) {

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                hasil[i][j] = A[i][j] + B[i][j];
            }
        }

        cout << "\nHasil Penjumlahan:" << endl;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << hasil[i][j] << "\t";
            }
            cout << endl;
        }

    } else if (pilihan == 2) {

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                hasil[i][j] = A[i][j] - B[i][j];
            }
        }

        cout << "\nHasil Pengurangan:" << endl;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << hasil[i][j] << "\t";
            }
            cout << endl;
        }

    } else if (pilihan == 3) {

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                hasil[i][j] = 0;

                for (int k = 0; k < 3; k++) {
                    hasil[i][j] += A[i][k] * B[k][j];
                }
            }
        }

        cout << "\nHasil Perkalian:" << endl;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << hasil[i][j] << "\t";
            }
            cout << endl;
        }

    } else {
        cout << "Pilihan tidak tersedia!" << endl;
    }

    return 0;
}