# <h1 align="center">Laporan Praktikum Modul 3 - ABSTRACT DATA TYPE (ADT)</h1>
<p align="center">Nawwar Ulayya Frodine - 109082500153</p>

## Dasar Teori

### A. Abstract Data Type (ADT)
Abstract Data Type (ADT) adalah model matematika yang mendefinisikan suatu tipe data beserta sekumpulan operasi dasar (primitif) yang berlaku pada tipe tersebut. ADT bersifat statik dan memisahkan antara spesifikasi logika tipe data dari detail implementasinya di dalam kode pemrograman. Pada bahasa pemrograman C++, tipe data ADT umumnya didefinisikan menggunakan struktur (struct), sedangkan operasi-operasinya diimplementasikan dalam bentuk fungsi dan prosedur yang mencakup konstruktor, selector, pengubah nilai, hingga operasi relasional.

### B. Implementasi dan Modularisasi ADT
Penerapan konsep ADT dilakukan melalui pemisahan kode ke dalam modul-modul terpisah untuk menjaga struktur program tetap rapi dan terorganisir. File header (.h) digunakan untuk menyimpan deklarasi spesifikasi tipe data serta prototipe fungsi/prosedur. Sementara itu, file realisasi (.cpp) berisi kode implementasi dari fungsi/prosedur tersebut, dan file program utama (main.cpp) bertindak sebagai driver yang mengintansiasi tipe data serta memanggil operasi primitif yang telah didefinisikan.


## Guided 

### 1. Mahasiswa

```C++
#include <iostream>
#include "mahasiswa.h"

using namespace std;

void inputMhs(mahasiswa &m) {
    cout << "input nim = ";
    cin >> (m).nim;
    cout << "input nilai = ";
    cin >> (m).nilai1;
    cout << "input nilai2 = ";
    cin >> (m).nilai2;
}

float rata2 (mahasiswa m) {
    return float(m.nilai1+m.nilai2)/2;
}
```

Penjelasan singkat guided mahasiswa.cpp:
Berisi implementasi kode dari fungsi dan prosedur yang telah direncanakan, yaitu prosedur inputMhs untuk menginput NIM dan nilai mahasiswa, serta fungsi rata2 untuk menghitung rata-rata dari nilai1 dan nilai2.

```C++
#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INLCLUDED

struct mahasiswa {
    char nim[10];
    int nilai1, nilai2;
};

void inputMhs(mahasiswa &m) ;
float rata2(mahasiswa m) ;
#endif // MAHASISWA_H_INCLUDED
```

Penjelasan singkat guided mahasiswa.h:
Definisi struktur data struct mahasiswa (yang memiliki atribut nim, nilai1, dan nilai2), deklarasi prototipe fungsi/prosedur, serta penggunaan include guard (#ifndef, #define, #endif) untuk mencegah duplikasi pemanggilan file header.

```C++
#include <iostream>
#include "mahasiswa.h"

using namespace std;

int main() {
    mahasiswa mhs;
    inputMhs (mhs) ;
    cout << "rata-rata = " << rata2 (mhs) ;
    return 0; 
}
```

Penjelasan singkat guided main.cpp:
Berfungsi sebagai driver yang mengeksekusi program dengan cara mendeklarasikan variabel mhs bertipe mahasiswa, memanggil prosedur inputMhs, lalu menampilkan hasil keluaran dari fungsi rata2 ke layar.


## Unguided 

### 1. Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3*uts+0.4*uas+0.3*tugas.

```C++
#include <iostream>
#include "mahasiswa.h"
using namespace std;

float hitungNilaiAkhir(mahasiswa m) {
    return 0.3f * m.uts + 0.4f * m.uas + 0.3f * m.tugas;
}

void inputMhs(mahasiswa &m) {
    cout << "Nama   : ";
    cin >> ws;
    getline(cin, m.nama);
    cout << "NIM    : ";
    cin >> m.nim;
    cout << "UTS    : ";
    cin >> m.uts;
    cout << "UAS    : ";
    cin >> m.uas;
    cout << "Tugas  : ";
    cin >> m.tugas;
    m.nilaiAkhir = hitungNilaiAkhir(m);
}

void tampilMhs(mahasiswa m) {
    cout << "Nama        : " << m.nama << endl;
    cout << "NIM         : " << m.nim << endl;
    cout << "UTS         : " << m.uts << endl;
    cout << "UAS         : " << m.uas << endl;
    cout << "Tugas       : " << m.tugas << endl;
    cout << "Nilai Akhir : " << m.nilaiAkhir << endl;
}
```
Penjelasan singkat 1.mahasiswa.cpp:
Implementasi fungsi hitungNilaiAkhir untuk mengkalkulasi nilai total berdasarkan bobot ($0.3 \times \text{uts} + 0.4 \times \text{uas} + 0.3 \times \text{tugas}$), serta prosedur inputMhs (dilengkapi getline untuk mengakomodasi spasi pada nama) dan tampilMhs untuk mencetak data mahasiswa ke layar.   

```C++
#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED

#include <string>
using namespace std;

const int MAX_MHS = 10;

struct mahasiswa {
    string nama;
    string nim;
    float uts, uas, tugas;
    float nilaiAkhir;
};

float hitungNilaiAkhir(mahasiswa m);

void inputMhs(mahasiswa &m);

void tampilMhs(mahasiswa m);

#endif // MAHASISWA_H_INCLUDED
```
Penjelasan singkat 1.mahasiswa.h:
Definisi struktur data (struct mahasiswa) yang mencakup atribut nama, nim, nilai komponen (uts, uas, tugas), serta nilaiAkhir. Di sini juga dideklarasikan konstanta kapasitas maksimum MAX_MHS = 10 serta prototipe fungsi penghitungan nilai akhir, prosedur input, dan prosedur tampil.

```C++
#include <iostream>
#include "mahasiswa.h"
using namespace std;

int main() {
    mahasiswa dataMhs[MAX_MHS];
    int n;

    do {
        cout << "Jumlah mahasiswa (1-" << MAX_MHS << ") : ";
        cin >> n;
    } while (n < 1 || n > MAX_MHS);

    for (int i = 0; i < n; i++) {
        cout << "\n=== Data Mahasiswa ke-" << i + 1 << " ===" << endl;
        inputMhs(dataMhs[i]);
    }

    cout << "\n===== DAFTAR MAHASISWA =====" << endl;
    for (int i = 0; i < n; i++) {
        cout << "\n--- Mahasiswa ke-" << i + 1 << " ---" << endl;
        tampilMhs(dataMhs[i]);
    }
    return 0;
}
```
Penjelasan singkat 1.main.cpp:
Berfungsi sebagai driver yang mendeklarasikan array berukuran MAX_MHS, meminta pengguna memasukkan jumlah data (maksimal 10), melakukan perulangan untuk proses pengisian data (inputMhs) ke dalam elemen array, serta menampilkan kembali seluruh data mahasiswa yang telah tersimpan.


### Output Unguided 1 :

##### Output 1.1
![Screenshot Output Unguided 1_1](https://github.com/nawwarulayya/109082500153_NawwarUlayyaFrodine-StrukturData/blob/main/Modul3/UNGUIDED/1.mahasiswa/1.1%20Output.png)

##### Output 1.2
![Screenshot Output Unguided 1_2](https://github.com/nawwarulayya/109082500153_NawwarUlayyaFrodine-StrukturData/blob/main/Modul3/UNGUIDED/1.mahasiswa/1.2%20Output.png)


### 2. Buatlah ADT pelajaran sebagai berikut di dalam file “pelajaran.h”, buatlah implementasi ADT pelajaran pada file “pelajaran.cpp”, cobalah hasil implementasi ADT pada file “main.cpp”

```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;

pelajaran create_pelajaran(string namapel, string kodepel) {
    pelajaran p;
    p.namaMapel = namapel;
    p.kodeMapel = kodepel;
    return p;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}
```
Penjelasan singkat 2.pelajaran.cpp:
Implementasi dari fungsi create_pelajaran untuk membentuk objek pelajaran baru dan prosedur tampil_pelajaran untuk mencetak atribut nama serta kode mata pelajaran ke layar.

```C++
#ifndef PELAJARAN_H_INCLUDED
#define PELAJARAN_H_INCLUDED

#include <string>
using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namapel, string kodepel);

void tampil_pelajaran(pelajaran pel);

#endif // PELAJARAN_H_INCLUDED
```
Penjelasan singkat 2.pelajaran.h: 
Mendefinisikan struktur data struct pelajaran yang berisi atribut namaMapel dan kodeMapel, serta mendeklarasikan prototipe fungsi create_pelajaran dan prosedur tampil_pelajaran dengan pengaman include guard. 

```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";
    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}
```
Penjelasan singkat 2.main.cpp:
Berfungsi sebagai driver yang menginisialisasi variabel string nama dan kode pelajaran, memanggil fungsi create_pelajaran untuk mengisi struct, serta menampilkan hasilnya menggunakan prosedur tampil_pelajaran.


### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/nawwarulayya/109082500153_NawwarUlayyaFrodine-StrukturData/blob/main/Modul3/UNGUIDED/2.pelajaran/2.%20Output.png)


### 3. Buatlah program dengan ketentuan :
- 2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer
- fungsi/prosedur yang menampilkan isi sebuah array integer 2D
- fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu
- fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah pointer

```C++
#include <iostream>
#include "operasi.h"
using namespace std;

void tampilArray(int arr[BARIS][KOLOM]) {
    for (int i = 0; i < BARIS; i++) {
        for (int j = 0; j < KOLOM; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void tukarArray(int A[BARIS][KOLOM], int B[BARIS][KOLOM], int baris, int kolom) {
    int temp = A[baris][kolom];
    A[baris][kolom] = B[baris][kolom];
    B[baris][kolom] = temp;
}

void tukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
```
Penjelasan singkat 3.operasi.cpp:
Implementasi prosedur untuk mencetak isi array 2D secara matriks, menukarkan nilai elemen tertentu antara dua array 2D menggunakan variabel sementara (temp), serta menukarkan nilai yang ditunjuk oleh dua buah pointer.

```C++
#ifndef OPERASI_H_INCLUDED
#define OPERASI_H_INCLUDED

const int BARIS = 3;
const int KOLOM = 3;

void tampilArray(int arr[BARIS][KOLOM]);

void tukarArray(int A[BARIS][KOLOM], int B[BARIS][KOLOM], int baris, int kolom);

void tukarPointer(int *p1, int *p2);

#endif // OPERASI_H_INCLUDED
```
Penjelasan singkat 3.operasi.h:
Mendefinisikan konstanta ukuran array BARIS dan KOLOM bernilai 3, serta mendeklarasikan prototipe prosedur tampilArray, tukarArray, dan tukarPointer dengan pengaman include guard.

```C++
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
```
Penjelasan singkat 3.main.cpp:
Bertindak sebagai driver yang menginisialisasi dua buah array 2D berukuran 3x3 dan dua variabel pointer, menampilkan kondisi awalnya, memanggil prosedur penukaran elemen array pada indeks tertentu serta penukaran pointer, lalu menampilkan hasil akhirnya ke layar.

### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/nawwarulayya/109082500153_NawwarUlayyaFrodine-StrukturData/blob/main/Modul3/UNGUIDED/3.operasi/3.%20Output.png)


## Kesimpulan
Abstract Data Type (ADT) ini dapat disimpulkan bahwa penggunaan ADT sangat penting dalam memetakan struktur data beserta operasi-operasi dasarnya secara terstruktur ke dalam bahasa pemrograman C++. Melalui penerapan konsep modularisasi—yaitu pemisahan kode program ke dalam file header (.h) untuk definisi tipe dan prototipe fungsi, file realisasi (.cpp) untuk implementasi kode fungsi/prosedur, serta file driver (main.cpp) untuk program utama—pemeliharaan, keterbacaan, dan pengembangan kode program menjadi jauh lebih efisien dan terorganisir. Selain itu, pemanfaatan struktur data seperti struct, array, serta manipulasi pointer terbukti efektif dalam menyelesaikan berbagai kasus kompleks, mulai dari pengolahan data nilai mahasiswa, pengelolaan objek mata pelajaran, hingga pertukaran nilai pada matriks array 2 dimensi.


## Referensi
[1] Modul Praktikum Struktur Data. (2026). Modul 3: Abstract Data Type (ADT). Fakultas Informatika, Telkom University.
