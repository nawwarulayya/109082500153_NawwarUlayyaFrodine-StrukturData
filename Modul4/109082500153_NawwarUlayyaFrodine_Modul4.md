# <h1 align="center">Laporan Praktikum Modul 3 - SINGLY LINKED LIST (BAGIAN PERTAMA) </h1>
<p align="center">Nawwar Ulayya Frodine - 109082500153</p>

## Dasar Teori

### A. Singly Linked List
Singly linked list adalah struktur data linear yang tersusun dari node-node yang saling terhubung melalui pointer. Setiap node terdiri dari info untuk menyimpan data dan next untuk menyimpan alamat node berikutnya. Penelusuran hanya bisa dilakukan satu arah, dari awal hingga akhir list.

### B. Komponen List
Pointer First menunjuk ke node pertama, sedangkan node terakhir memiliki next bernilai Nil sebagai penanda akhir list. Jika First bernilai Nil, berarti list dalam keadaan kosong.

### C. Alokasi Memori Dinamis
Berbeda dengan array, node pada linked list dialokasikan secara dinamis menggunakan new dan dibebaskan dengan delete. Hal ini membuat ukuran list fleksibel, dan penyisipan atau penghapusan tidak perlu menggeser elemen lain.

### D. Abstract Data Type (ADT)
ADT adalah pendefinisian tipe data beserta operasinya. Pada praktikum ini, ADT dipisah menjadi tiga file, yaitu deklarasi tipe dan prosedur pada Singlylist.h, implementasi prosedur pada Singlylist.cpp, dan program utama pada main.cpp. Pemisahan ini membuat program lebih terstruktur dan mudah digunakan kembali.

### E. Operasi Dasar
createList membuat list kosong, alokasi membuat node baru, dealokasi menghapus node dari memori, insertFirst menambah node di awal list, dan printInfo menampilkan isi list. Karena insertFirst menyisipkan node di depan, data yang dimasukkan berurutan 2, 0, 8, 12, 9 akan menghasilkan list 9, 12, 8, 0, 2.

### F. Operasi Penghapusan
deleteFirst menghapus node pertama, deleteLast menghapus node terakhir dengan mencari node sebelumnya, dan deleteAfter menghapus node setelah node tertentu. Ketiga operasi ini perlu memperhatikan urutan perubahan pointer agar list tidak terputus.

### G. Penghitungan dan Penghapusan Seluruh List
nbList menghitung jumlah node dengan menelusuri list dari First hingga Nil. Sedangkan deleteList menghapus seluruh node satu per satu sehingga list menjadi kosong dan tidak terjadi kebocoran memori (memory leak).

## Guided 

### 1. List

```C++
//hear guard digunakan untuk mencegah file header yang sama
//di-include lebih dari sekali dalam 1 program
#ifndef LIST_H
#define LIST_H
#define NIL NULL

#include <iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //memberikan nama alias dataMahasiswa untuk struct mahasiswa

typedef struct node *address; //mendefinisikan alias address sebagai pointer ke struct node

struct node { //node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct LinkedList { //ini linked listnya
    address first;
};

//semua function & prosedure yang akan dipakai
bool isEmpty(LinkedList &list);
void createList(LinkedList &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(LinkedList List);
void insertFirst(LinkedList &List, address nodeBaru);
void insertAfter(LinkedList &List, address nodeBaru, address Prev);
void insertLast(LinkedList &List, address nodeBaru);

void delFirst(LinkedList &List);
void delLast(LinkedList &List);
void delAfter(LinkedList &List, address nodeHapus, address Prev);
int nbList(LinkedList &List);
void deleteList(LinkedList &List);

#endif
```

Penjelasan singkat guided list.h:
File header yang berisi deklarasi tipe data dan prototipe fungsi. Isinya struct mahasiswa (nama, nim, umur), struct node (data dan pointer next), serta struct LinkedList dengan pointer first. Header guard dipakai agar file tidak ter-include berulang.

```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State // kondisi awal
//F.F = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(LinkedList &List) {
    if (List.first == NIL) {
        return true;
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(LinkedList &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
     List.first = NIL;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) {
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = NIL */
    address nodeBaru = new node;
    nodeBaru -> isidata.nama = nama;
    nodeBaru -> isidata.nim = nim;
    nodeBaru -> isidata.umur = umur;
    nodeBaru -> next = NIL;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node -> next = NIL;
   delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru ke dalam list
void insertFirst(LinkedList &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru -> next = List.first;
    List.first = nodeBaru;
}

void insertAfter(LinkedList &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemb list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != NIL) {
        nodeBaru -> next = Prev -> next;
        Prev -> next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(LinkedList &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu -> next != NIL) {
            nodeBantu = nodeBantu -> next;
        }
        nodeBantu -> next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada di dalam list
void delFirst(LinkedList &List) {
    /* I.S. list tidak kosong
       F.S. node pertama di list terhapus */
    address nodeHapus;
    if (!isEmpty(List)) {
        nodeHapus = List.first;
        List.first = List.first -> next;
        nodeHapus -> next = NIL;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(LinkedList &List) {
    /* I.S. list tidak kosong
       F.S. node terakhir di list terhapus */
    address nodeHapus, nodePrev;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        if (nodeHapus -> next == NIL) {
            List.first = NIL;
            dealokasi(nodeHapus);
        } else {
            while (nodeHapus -> next != NIL) {
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus -> next;
            }
            nodePrev -> next = NIL;
            dealokasi (nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(LinkedList &List, address nodeHapus, address nodePrev) {
    /* I.S. list tidak kosong, Prev alamat salah satu elemen list
       F.S. nodeBantu adalah alamat dari Prev -> next, menghapus Prev -> next dari list */
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != NIL && nodePrev -> next != NIL) {
            nodeHapus = nodePrev -> next;
            nodePrev -> next = nodeHapus -> next;
            nodeHapus -> next = NIL;
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (Prev) tidak valid" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(LinkedList List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != NIL) {
            cout << "Nama: " << nodeBantu -> isidata.nama << ", NIM: " << nodeBantu -> isidata.nim << ", Usia: " << nodeBantu -> isidata.umur << endl;
            nodeBantu = nodeBantu -> next;
        }
    }
}

//function untuk menampilkan jumlah node di dalam list
int nbList(LinkedList &List) {
    /* I.S. list sudah ada
       F.S. menampilkan jumlah node di dalam list */
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != NIL) {
        count++;
        nodeBantu = nodeBantu -> next;
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node di dalam list)
void deleteList(LinkedList &List) {
    /* I.S. lihat sudah ada
       F.S. menghapus semua node di dalam list */
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while (nodeBantu != NIL) {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu -> next;
        dealokasi(nodeHapus);
    }
    List.first = NIL;
    cout << "List sudah terhapus!" << endl;
}
```

Penjelasan singkat guided list.cpp:
File implementasi semua prosedur. Mencakup pembuatan list dan node (createList, alokasi, dealokasi), penambahan node (insertFirst, insertAfter, insertLast), penghapusan node (delFirst, delLast, delAfter), serta printList, nbList, dan deleteList untuk menampilkan, menghitung, dan menghapus seluruh list.

```C++
#include "list.h"

#include <iostream>
using namespace std;

int main() {
    LinkedList List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = NIL;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2311110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2311102173", 21);
    nodeE = alokasi("Jashua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeB);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node: " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "jumlah node: " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "jumlah node: " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```

Penjelasan singkat guided main.cpp:
Program utama yang menguji semua operasi. Lima node mahasiswa disisipkan hingga terbentuk urutan Dhimas, Rizal, Arvin, Satrio, Jashua (5 node). Setelah penghapusan, tersisa Rizal dan Satrio (2 node). Terakhir deleteList mengosongkan list sehingga jumlah node menjadi 0.


## Unguided 

### 1. Buatlah ADT Singly Linked list sebagai berikut di dalam file “Singlylist.h”. Kemudian buatlah implementasi dari procedure-procedure yang digunakan didalam file “Singlylist.cpp”. Kemudian buat program utama didalam file “main.cpp” dengan implementasi.

```C++
#ifndef SINGLYLIST_H_INCLUDED
#define SINGLYLIST_H_INCLUDED

#include <iostream>
using namespace std;

#define Nil NULL

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address First;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

#endif // SINGLYLIST_H_INCLUDED
```
Penjelasan singkat 1.singlylist.h:
File header yang berisi deklarasi ADT. #define Nil NULL menjadi penanda pointer kosong, infotype adalah alias int, dan address adalah pointer ke ElmList. struct ElmList terdiri dari info dan next, sedangkan struct List memiliki pointer First sebagai penunjuk node pertama. Bagian bawah memuat prototipe createList, alokasi, dealokasi, printInfo, dan insertFirst. Header guard dipakai agar file tidak ter-include berulang.

```C++
#include "singlylist.h"

void createList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P -> info = x;
    P -> next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address P = L.First;
    while (P != Nil) {
        cout << P -> info << " ";
        P = P -> next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    P -> next = L.First;
    L.First = P;
}

void deleteFirst(List &L, address &P) {
    if (L.First != Nil) {
        P = L.First;
        L.First = P -> next;
        P -> next = Nil;
    } else {
        P = Nil;
    }
}

void deleteLast(List &L, address &P) {
    if (L.First == Nil) {
        P = Nil;
    } else if (L.First -> next == Nil) {
        P = L.First;
        L.First = Nil;
    } else {
        address Q = L.First;
        while (Q -> next -> next != Nil) {
            Q = Q -> next;
        }
        P = Q -> next;
        Q -> next = Nil;
    }
}

void deleteAfter(List &L, address Prec, address &P) {
    if (Prec != Nil && Prec -> next != Nil) {
        P = Prec -> next;
        Prec -> next = P -> next;
        P -> next = Nil;
    } else {
        P = Nil;
    }
}

int nbList(List L) {
    int jumlah = 0;
    address P = L.First;
    while (P != Nil) {
        jumlah++;
        P = P -> next;
    }
    return jumlah;
}

void deleteList(List &L) {
    address P;
    while (L.First != Nil) {
        deleteFirst(L, P);
        dealokasi(P);
    }
}
```
Penjelasan singkat 1.singlylist.cpp:
File implementasi semua prosedur. createList membuat list kosong (First = Nil), alokasi membuat node baru dengan new, dan dealokasi menghapus node dengan delete. insertFirst menyisipkan node di awal list, sedangkan printInfo mencetak isi list dari First sampai Nil. Untuk penghapusan, deleteFirst, deleteLast, dan deleteAfter melepas node dari list (alamatnya disimpan di P), nbList menghitung jumlah node, dan deleteList menghapus semua node dengan deleteFirst lalu dealokasi secara berulang.

```C++
#include "singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);
    return 0;
}
```
Penjelasan singkat 1.main.cpp:
Program utama yang membuat list kosong, lalu mengalokasikan lima node (2, 0, 8, 12, 9) dan menyisipkannya dengan insertFirst. Karena disisipkan di depan, urutan akhirnya 9, 12, 8, 0, 2, sehingga printInfo menampilkan 9 12 8 0 2.


### Output Unguided 1 :

##### Output
![Screenshot Output Unguided 1](https://github.com/nawwarulayya/109082500153_NawwarUlayyaFrodine-StrukturData/blob/main/Modul4/UNGUIDED/1.singlylist/Output.png)


### 2. Dari soal Latihan pertama, lakukan penghapusan node 9 menggunakan deleteFirst(), node 2 menggunakan deleteLast(), dan node 8 menggunakan deleteAfter(). Kemudian tampilkan jumlah node yang tersimpan menggunakan nbList() dan lakukan penghapusan seluruh node menggunakan deleteList().

```C++
#ifndef SINGLYLIST_H_INCLUDED
#define SINGLYLIST_H_INCLUDED

#include <iostream>
using namespace std;

#define Nil NULL

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address First;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address Prec, address &P);
int nbList(List L);
void deleteList(List &L);

#endif // SINGLYLIST_H_INCLUDED
```
Penjelasan singkat 2.singlylist.h:
File header yang berisi deklarasi ADT. #define Nil NULL menjadi penanda pointer kosong, infotype adalah alias int, dan address adalah pointer ke ElmList. struct ElmList terdiri dari info dan next, sedangkan struct List memiliki pointer First. Bagian bawah memuat prototipe seluruh prosedur, yaitu createList, alokasi, dealokasi, printInfo, insertFirst, serta tambahan untuk Soal 2: deleteFirst, deleteLast, deleteAfter, nbList, dan deleteList.

```C++
#include "singlylist.h"

void createList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P -> info = x;
    P -> next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address P = L.First;
    while (P != Nil) {
        cout << P -> info << " ";
        P = P -> next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    P -> next = L.First;
    L.First = P;
}

void deleteFirst(List &L, address &P) {
    if (L.First != Nil) {
        P = L.First;
        L.First = P -> next;
        P -> next = Nil;
    } else {
       P = Nil; 
    }
}

void deleteLast(List &L, address &P) {
    if (L.First == Nil) {
        P = Nil;
    } else if (L.First -> next == Nil) {
        P = L.First;
        L.First = Nil;
    } else {
        address Q = L.First;
        while (Q -> next -> next != Nil) {
            Q = Q -> next;
        }
        P = Q -> next;
        Q -> next = Nil;
    }
}

void deleteAfter(List &L, address Prec, address &P) {
    if (Prec != Nil && Prec -> next != Nil) {
        P = Prec -> next;
        Prec -> next = P -> next;
        P -> next = Nil;
    } else {
        P = Nil;
    }
}

int nbList(List L) {
    int jumlah = 0;
    address P = L.First;
    while (P != Nil) {
        jumlah++;
        P = P -> next;
    }
    return jumlah;
}

void deleteList(List &L) {
    address P;
    while (L.First != Nil) {
        deleteFirst(L, P);
        dealokasi(P);
    }
}
```
Penjelasan singkat 2.singlylist.cpp: 
File implementasi semua prosedur. createList membuat list kosong, alokasi membuat node baru dengan new, dan dealokasi menghapus node dengan delete. insertFirst menyisipkan node di awal, sedangkan printInfo mencetak isi list. deleteFirst, deleteLast, dan deleteAfter melepas node dari list dan menyimpan alamatnya di P, lalu node tersebut dihapus dari memori dengan dealokasi. nbList menghitung jumlah node, dan deleteList menghapus semua node dengan deleteFirst dan dealokasi secara berulang.

```C++
#include "singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    address P;
    createList(L);

    P1 = alokasi(2); insertFirst(L, P1);
    P2 = alokasi(0); insertFirst(L, P2);
    P3 = alokasi(8); insertFirst(L, P3);
    P4 = alokasi(12); insertFirst(L, P4);
    P5 = alokasi(9); insertFirst(L, P5);

    deleteFirst(L, P);
    dealokasi(P);

    deleteLast(L, P);
    dealokasi(P);

    deleteAfter(L, P4, P);
    dealokasi(P);

    printInfo(L);
    cout << "Jumlah node: " << nbList(L) << endl;

    cout << endl;
    deleteList(L);
    cout << "- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node: " << nbList(L) << endl;

    return 0;
}
```
Penjelasan singkat 2.main.cpp:
Program utama membuat list dengan lima node (2, 0, 8, 12, 9) menggunakan insertFirst, sehingga terbentuk list 9, 12, 8, 0, 2. Kemudian deleteFirst menghapus 9, deleteLast menghapus 2, dan deleteAfter(L, P4, P) menghapus 8 (node setelah 12). Tersisa 12 dan 0, sehingga printInfo menampilkan 12 0 dan nbList menampilkan jumlah node 2. Terakhir, deleteList menghapus seluruh node sehingga list kosong dan jumlah node menjadi 0. Output sesuai dengan yang diharapkan soal.

### Output Unguided 2 :

##### Output
![Screenshot Output Unguided 2](https://github.com/nawwarulayya/109082500153_NawwarUlayyaFrodine-StrukturData/blob/main/Modul4/UNGUIDED/2.singlylist/Output.png)


## Kesimpulan
Singly linked list terbukti menjadi struktur data dinamis yang tersusun dari node-node yang dihubungkan oleh pointer next, dengan pointer First sebagai penunjuk node pertama. Penerapan ADT dengan memisahkan kode ke dalam file header, implementasi, dan program utama membuat program lebih terstruktur dan mudah digunakan kembali. Operasi insertFirst menghasilkan urutan list 9, 12, 8, 0, 2 dari data yang dimasukkan secara berurutan, sedangkan operasi deleteFirst, deleteLast, dan deleteAfter berhasil menghapus node tertentu sehingga tersisa 12 dan 0 dengan jumlah node 2. Fungsi deleteList mampu menghapus seluruh node dan melakukan dealokasi sehingga jumlah node menjadi 0 serta tidak terjadi kebocoran memori.


## Referensi
[1] Laboratorium Informatika, Modul 4 Praktikum Struktur Data: Singly Linked List. Bandung, Indonesia: Telkom University, 2026.
