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

### 1. Array1

```C++
#include <iostream>
using namespace std;

int main() {
    int nilai[2];

    nilai[0] = 80;
    nilai[1] = 75;
    nilai[2] = 90;
    nilai[3] = 85;
    nilai[4] = 95;

    for (int i = 0; i < 5; i++) {
        cout << "Nilai ke-" << i + 1 << " = "
            << nilai[i] << endl;
    }
    
    return 0; 
}
```
Penjelasan singkat guided 1 :
Program tersebut digunakan untuk menyimpan dan menampilkan beberapa nilai menggunakan array. Variabel nilai[2] digunakan untuk membuat array yang hanya memiliki dua elemen, sedangkan program mengisi lima nilai, yaitu 80, 75, 90, 85, dan 95. Perulangan for digunakan untuk menampilkan setiap nilai. Namun, ukuran array seharusnya diubah menjadi nilai[5] agar dapat menampung kelima nilai tersebut dan menghindari akses memori di luar batas array.

### 2. Array2

```C++
#include <iostream>
using namespace std;

int main() {
    int nilai[3][3] = {
        {80, 75, 90},
        {85, 90, 88},
        {70, 80, 85}
    };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << nilai[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << nilai[1][2] << endl; 

    return 0;
}
```

Penjelasan singkat guided 2 :
Program tersebut digunakan untuk membuat dan menampilkan array dua dimensi (matriks) berukuran 3×3 yang berisi nilai. Perulangan for digunakan untuk menampilkan setiap elemen berdasarkan baris dan kolom. Setelah semua nilai ditampilkan, nilai[1][2] digunakan untuk mengambil nilai pada baris kedua dan kolom ketiga, yaitu 88.

### 3. Array3

```C++
#include <iostream>
using namespace std;

int main() {
    int data[2][2][3] = {
        {
            {10, 20, 30},
            {40, 50, 60}
        },
        {
            {70, 80, 90},
            {100, 110, 120}
        }
    };

    cout << data[0][1][2] << endl;

    return 0;
}
```

Penjelasan singkat guided 3 :
Program tersebut digunakan untuk membuat array tiga dimensi dengan ukuran 2×2×3 yang berisi beberapa data. Data disusun berdasarkan tiga indeks, yaitu lapisan, baris, dan kolom. Perintah data[0][1][2] digunakan untuk mengambil data pada lapisan pertama, baris kedua, dan kolom ketiga, sehingga menghasilkan nilai 60.

### 4. Address

```C++
#include <iostream>
using namespace std;

int main() {
    int angka = 100;

    cout << "Nilai Angka: " << angka << endl;
    cout << "Alamat angka: " << &angka << endl;

    return 0;
}
```

Penjelasan singkat guided 4 :
Program tersebut digunakan untuk menampilkan nilai variabel dan alamat memorinya. Variabel angka bertipe integer diberi nilai 100, kemudian nilai tersebut ditampilkan menggunakan cout. Simbol &angka digunakan untuk mengetahui alamat memori tempat variabel angka disimpan. Alamat memori yang ditampilkan dapat berbeda setiap kali program dijalankan.

### 5. Pointer

```C++
#include <iostream>
using namespace std;

int main() {
    int angka = 100;

    int *pointer;

    pointer = &angka;

    cout << "Nilai angka: " << angka << endl;
    cout << "Alamat angka: " << &angka << endl;
    cout << "Isi pointer: " << pointer << endl;
    cout << "Nilai dari pointer: " << *pointer << endl;

    return 0;
} 
```

Penjelasan singkat guided 5 :
Program tersebut digunakan untuk menunjukkan cara kerja pointer dalam C++. Variabel angka memiliki nilai 100, kemudian pointer pointer digunakan untuk menyimpan alamat memori dari variabel angka. Perintah &angka menampilkan alamat memori angka, sedangkan pointer menampilkan alamat yang disimpan oleh pointer dan *pointer digunakan untuk mengambil nilai yang berada pada alamat tersebut, yaitu 100.

### 6. Pointer Array

```C++
#include <iostream>
using namespace std;

int main() {
    char arr[6];

    arr[0] = 'a';
    arr[1] = 'b';
    arr[2] = 'c';
    arr[3] = 'b';
    arr[4] = 'd';
    arr[5] = 'e';

    cout << arr[3] << endl; 
    cout << &(arr[4]) << endl;

    return 0;
} 
```

Penjelasan singkat guided 6 :
Program tersebut digunakan untuk membuat array bertipe karakter (char) yang berisi beberapa huruf. Elemen arr[3] digunakan untuk menampilkan huruf pada indeks ke-3, yaitu b. Sedangkan &(arr[4]) digunakan untuk menampilkan alamat memori dari elemen arr[4], yaitu karakter d.

### 7. Function

```C++
#include <iostream>
using namespace std;

int maks3(int a, int b, int c) {
    int temp_max = a;

    if (b > temp_max) {
        temp_max = b;
    }
    if (c > temp_max) {
        temp_max = c;
    }
    return temp_max;
}

int main() {
    int x, y, z;

    cout << "Masukkan nilai 1 ";
    cin >> x;

    cout << "Masukkan nilai 2 ";
    cin >> y;
    
    cout << "Masukkan nilai 3 ";
    cin >> z;

    cout << "Nilai makismum = "
            << maks3(x, y, z);

    return 0;
}
```

Penjelasan singkat guided 7 :
Program tersebut digunakan untuk mencari nilai terbesar dari tiga bilangan. Fungsi maks3() membandingkan nilai a, b, dan c menggunakan if, kemudian menyimpan nilai terbesar pada variabel temp_max. Pada fungsi main(), pengguna memasukkan tiga nilai yang kemudian dikirim ke fungsi maks3(), sehingga program menampilkan nilai maksimum dari ketiga bilangan tersebut.

### 8. Procedure

```C++
#include <iostream>
using namespace std;

void sapa() {
    cout << "Selamat datang di Praktikum Struktur Data" << endl;
}

int main() {
    sapa();

    return 0;
}
```

Penjelasan singkat guided 8 :
Program tersebut digunakan untuk membuat fungsi sederhana tanpa parameter. Fungsi sapa() berisi perintah untuk menampilkan tulisan “Selamat datang di Praktikum Struktur Data”. Pada fungsi main(), sapa() dipanggil sehingga pesan tersebut muncul sebagai output program.

### 9. Call By

```C++
//Pointer
#include <iostream>
using namespace std;

void tukar(int *x, int *y) {
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
} 

int main() {
    int a = 4;
    int b = 6;
 
    cout << "Sebelum ditukar: " << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    tukar(&a, &b);

    cout << "\nSetelah ditukar: " << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
} 
```
```C++
//Reference
#include <iostream>
using namespace std;

void tukar(int &x, int &y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int main() {
    int a = 4;
    int b = 6;

    cout << "Sebelum ditukar: " << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    tukar(a, b);

    cout << "\nSetelah ditukar: " << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    
    return 0;
}
```
```C++
//Value
#include <iostream>
using namespace std;

void tukar(int x, int y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int main() {
    int a = 4;
    int b = 6;

    cout << "Sebelum ditukar: " << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    tukar(a, b);

    cout << "\nSetelah ditukar: " << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    
    return 0;
}
```

Penjelasan singkat guided 9 :
Ketiga program tersebut memiliki tujuan yang sama, yaitu menukar nilai dua variabel, tetapi menggunakan metode yang berbeda. Pada pointer, alamat variabel a dan b dikirim menggunakan &, sehingga nilai asli dapat diubah melalui *x dan *y. Pada reference, parameter x dan y menjadi referensi langsung dari a dan b, sehingga perubahan nilai di dalam fungsi juga mengubah nilai aslinya. Sedangkan pada value, yang dikirim hanya salinan nilai a dan b, sehingga proses pertukaran hanya terjadi di dalam fungsi dan nilai asli tetap a = 4 dan b = 6.

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
![Screenshot Output Unguided 1_1](https://github.com/nawwarulayya/109082500153_NawwarUlayyaFrodine-StrukturData/blob/main/Modul2/UNGUIDED/Output%201.1.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/nawwarulayya/109082500153_NawwarUlayyaFrodine-StrukturData/blob/main/Modul2/UNGUIDED/Output%201.2.png)

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
![Screenshot Output Unguided 2_1](https://github.com/nawwarulayya/109082500153_NawwarUlayyaFrodine-StrukturData/blob/main/Modul2/UNGUIDED/Output%202.1.png)

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/nawwarulayya/109082500153_NawwarUlayyaFrodine-StrukturData/blob/main/Modul2/UNGUIDED/Output%202.2.png)

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
![Screenshot Output Unguided 3_1](https://github.com/nawwarulayya/109082500153_NawwarUlayyaFrodine-StrukturData/blob/main/Modul2/UNGUIDED/Output%203.1.png)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/nawwarulayya/109082500153_NawwarUlayyaFrodine-StrukturData/blob/main/Modul2/UNGUIDED/Output%203.2.png)

Penjelasan unguided 3 :
Program ini digunakan untuk mengolah array yang berisi 10 data. Program menyediakan menu untuk menampilkan isi array, mencari nilai maksimum, mencari nilai minimum, dan menghitung nilai rata-rata. Pencarian maksimum dan minimum menggunakan function, sedangkan perhitungan rata-rata menggunakan procedure void. Menu dibuat menggunakan if-else dan perulangan do-while.

## Kesimpulan
Dapat disimpulkan bahwa array dapat digunakan untuk menyimpan dan mengolah sekumpulan data, termasuk data dalam bentuk matriks. Pointer dan reference dapat digunakan untuk mengakses serta mengubah nilai variabel melalui fungsi. Selain itu, penggunaan fungsi dan prosedur membuat program menjadi lebih terstruktur dan mengurangi pengulangan kode. Dengan memahami konsep tersebut, pengolahan data dalam program C++ menjadi lebih mudah dan terorganisir.

## Referensi
[1] Modul 2 Struktur Data 21 – Pengenalan Bahasa C++ (Bagian Kedua), materi Praktikum Struktur Data, Universitas Telkom.
<br>[2] Materi Array, Pointer, Fungsi, Prosedur, dan Parameter Fungsi pada Modul 2 Struktur Data.