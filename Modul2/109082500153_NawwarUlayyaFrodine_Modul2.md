# <h1 align="center">Laporan Praktikum Modul 2 - Pengenalan Bahas C++ (Bagian Kedua)</h1>
<p align="center">Nawwar Ulayya Frodine - 109082500153</p>

## Dasar Teori

### A. Array
Array merupakan kumpulan data yang memiliki nama yang sama dan setiap elemennya memiliki tipe data yang sama. Setiap elemen array dapat diakses menggunakan indeks. Pada array satu dimensi, indeks dimulai dari 0, sedangkan array dua dimensi memiliki dua indeks sehingga dapat digunakan untuk menyimpan data dalam bentuk tabel atau matriks.

### B. Pointer
Pointer adalah variabel yang digunakan untuk menyimpan alamat memori dari variabel lain. Pointer dapat digunakan untuk mengakses atau mengubah nilai dari variabel yang alamatnya ditunjuk. Operator & digunakan untuk mendapatkan alamat suatu variabel, sedangkan * digunakan untuk mengakses nilai yang ditunjuk oleh pointer.

### C. Fungsi
Fungsi merupakan blok kode yang dibuat untuk menjalankan tugas tertentu. Penggunaan fungsi membuat program lebih terstruktur, mudah dipahami, dan dapat mengurangi pengulangan kode. Fungsi dapat menerima parameter dan biasanya mengembalikan suatu nilai menggunakan return.

### D. Prosedur
Prosedur pada C++ dapat dibuat menggunakan fungsi void. Berbeda dengan fungsi yang mengembalikan nilai, prosedur digunakan untuk melakukan suatu tugas tanpa memberikan nilai balik kepada pemanggilnya.

### E. Parameter Pointer dan Reference
Pemanggilan dengan pointer dilakukan dengan mengirimkan alamat variabel ke dalam fungsi, sehingga nilai variabel asli dapat diubah. Sementara itu, reference juga memungkinkan fungsi mengubah nilai variabel asli, tetapi parameter ditulis menggunakan tanda & dan saat pemanggilan tidak perlu mengirimkan alamat menggunakan &.


## Guided 

### 1. ...

```C++
source code guided 1
```
penjelasan singkat guided 1

### 2. ...

```C++
source code guided 2
```
penjelasan singkat guided 2

### 3. ...

```C++
source code guided 3
```
penjelasan singkat guided 3

## Unguided 

### 1. Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3

```C++
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
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

Penjelasan unguided 1 :
Program ini digunakan untuk melakukan operasi penjumlahan, pengurangan, dan perkalian pada dua matriks berukuran 3×3. Pengguna memasukkan nilai matriks A dan B, kemudian memilih operasi yang ingin dilakukan menggunakan if-else. Hasil operasi akan ditampilkan dalam bentuk matriks.

### 2. Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat menukar nilai dari 3 variabel

```C++
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
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

Penjelasan unguided 2 :
Program ini digunakan untuk menukar nilai dari tiga variabel. Pertukaran dilakukan dengan dua metode, yaitu menggunakan pointer dan reference. Pointer menggunakan alamat memori dengan simbol * dan &, sedangkan reference menggunakan tanda & pada parameter fungsi.

### 3. Diketahui sebuah array 1 dimensi sebagai berikut : arrA = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55} Buatlah program yang dapat mencari nilai minimum, maksimum, dan rata – rata dari array tersebut! Gunakan function cariMinimum() untuk mencari nilai minimum dan function cariMaksimum() untuk mencari nilai maksimum, serta gunakan prosedur hitungRataRata() untuk menghitung nilai rata – rata! Buat program menggunakan menu switch-case seperti berikut ini : Menu Program Array ; • Tampilkan isi array • Cari nilai maksimum • Cari nilai minimum • Hitung nilai rata - rata

```C++
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
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 3_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided3-1.png)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

Penjelasan unguided 3 :
Program ini digunakan untuk mengolah array yang berisi 10 data. Program menyediakan menu untuk menampilkan isi array, mencari nilai maksimum, mencari nilai minimum, dan menghitung nilai rata-rata. Pencarian maksimum dan minimum menggunakan function, sedangkan perhitungan rata-rata menggunakan procedure void. Menu dibuat menggunakan if-else dan perulangan do-while.

## Kesimpulan
Dapat disimpulkan bahwa array dapat digunakan untuk menyimpan dan mengolah sekumpulan data, termasuk data dalam bentuk matriks. Pointer dan reference dapat digunakan untuk mengakses serta mengubah nilai variabel melalui fungsi. Selain itu, penggunaan fungsi dan prosedur membuat program menjadi lebih terstruktur dan mengurangi pengulangan kode. Dengan memahami konsep tersebut, pengolahan data dalam program C++ menjadi lebih mudah dan terorganisir.

## Referensi
[1] Modul 2 Struktur Data 21 – Pengenalan Bahasa C++ (Bagian Kedua), materi Praktikum Struktur Data, Universitas Telkom.
<br>[2] Materi Array, Pointer, Fungsi, Prosedur, dan Parameter Fungsi pada Modul 2 Struktur Data.