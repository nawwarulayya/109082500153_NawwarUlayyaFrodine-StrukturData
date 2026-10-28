# <h1 align="center">Laporan Praktikum Modul 4 - SINGLY LINKED LIST (BAGIAN KEDUA) </h1>
<p align="center">Nawwar Ulayya Frodine - 109082500153</p>

## Dasar Teori

### A. Singly Linked List
Singly linked list adalah struktur data dinamis yang tersusun dari rangkaian node, di mana setiap node memiliki info untuk menyimpan data dan next berupa pointer yang menunjuk ke node berikutnya. List diakses melalui pointer First, sedangkan node terakhir memiliki next bernilai Nil. List dikatakan kosong jika First = Nil. Berbeda dengan array, elemen linked list tidak dapat diakses lewat indeks sehingga harus ditelusuri (traversal) satu per satu dari awal.

Dalam C++, linked list dibuat sebagai ADT yang dipisah menjadi file header (.h) berisi deklarasi tipe dan prototype, serta file .cpp berisi implementasi fungsi. Operasi dasarnya meliputi CreateList, alokasi, dealokasi, insertFirst, dan printInfo. Selain itu, operasi searching (findElm) mencari node dengan mengunjungi setiap elemen secara berurutan sampai data ditemukan atau Nil tercapai, lalu mengembalikan alamat node tersebut. Pola penelusuran yang sama juga dipakai untuk menjumlahkan seluruh info elemen (sumInfo).


## Guided 

### 1. List Buah

```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - UPDATE -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - SEARCHING -----*/
//prosedur-prosedur untuk searching data
//prosedur untuk mencari node berdasarkan data
void FindNodeByData(linkedlist list, string data){
    if(isEmpty(list) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != Nil){
            posisi++;
            if(nodeBantu->isidata.nama == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan alamat node
void FindNodeByAddress(linkedlist list, address node) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan range data (range harga)
void FindNodeByRange(linkedlist list, float hargaAwal, float hargaAkhir) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Buah dalam range harga " << hargaAwal << " - " << hargaAkhir << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            float harga = nodeBantu->isidata.harga;
            if(harga >= hargaAwal && harga <= hargaAkhir) {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data buah dalam range harga tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}
```
Penjelasan singkat guided listBuah.cpp:
File ini berisi implementasi semua prototype di header. Bagian dasarnya adalah isEmpty untuk mengecek list kosong, createList untuk membuat list kosong, alokasi untuk membuat node baru dengan new, dan dealokasi untuk menghapus node dengan delete. Prosedur insert (insertFirst, insertAfter, insertLast) menyisipkan node di awal, setelah node tertentu, dan di akhir list, sedangkan prosedur delete (delFirst, delLast, delAfter, deleteList) menghapus node di posisi yang sesuai atau seluruh list. printList menampilkan semua data dan nbList menghitung jumlah node. Pada materi modul 5, prosedur update (updateFirst, updateLast, updateAfter) mengubah data node lewat input pengguna, dan prosedur searching (FindNodeByData, FindNodeByAddress, FindNodeByRange) mencari node berdasarkan nama, alamat, atau rentang harga sambil menampilkan posisinya.

```C++
//Header guard digunakan untuk mencegah file header yang sama 
//di-include lebih dari sekali dalam satu program.
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL

#include<iostream>
using namespace std;

struct buah{
    string nama;
    int jumlah; 
    float harga;
};

typedef buah dataBuah; //Memberikan nama alias databuah untuk struct buah.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataBuah isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
//Materi modul 4
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

//materi modul 5 (update)
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

//materi modul 5 (searching)
void FindNodeByData(linkedlist list, string data);
void FindNodeByAddress(linkedlist list, address node);
void FindNodeByRange(linkedlist list, float hargaAwal, float HargaAkhir);

#endif
```
Penjelasan singkat listBuah.h:
File header ini berisi deklarasi struktur data dan prototype semua fungsi dan prosedur. Header guard (#ifndef ... #endif) mencegah file ter-include lebih dari sekali, dan Nil didefinisikan sebagai NULL. Struct buah menyimpan nama, jumlah, dan harga, lalu diberi alias dataBuah. Struct node berisi isidata dan pointer next, dengan address sebagai pointer ke node. Struct linkedlist menyimpan pointer first yang menunjuk node pertama. Prototype dikelompokkan menjadi materi modul 4 (insert, delete, print) dan materi modul 5 (update dan searching).

```C++
#include "listBuah.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    printList(List);
    updateLast(List);
    printList(List);
    updateAfter(List, nodeD);
    printList(List);
    
    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;
    
    FindNodeByData(List, "kelapa");
    FindNodeByAddress(List, nodeC);
    FindNodeByRange(List, 5000, 10000);
    
    delFirst(List);
    printList(List);
    delLast(List);
    printList(List);
    delAfter(List, nodeD, nodeC);
    printList(List);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```
Penjelasan singkat main.cpp:
File ini adalah program utama yang menguji seluruh fungsi. Program membuat list, mengalokasikan lima node (Jeruk, Apel, Pir, Semangka, Durian), lalu menyisipkannya dengan insertFirst, insertLast, dan insertAfter. Setelah itu data node pertama, terakhir, dan setelah nodeD diupdate, kemudian dilakukan pencarian berdasarkan nama (“kelapa”, yang tidak ada di list), alamat (nodeC), dan rentang harga 5000–10000. Program lalu menghapus node pertama, terakhir, dan setelah nodeC, dan terakhir menghapus seluruh list dengan deleteList. Setiap tahap diakhiri printList dan nbList untuk menunjukkan perubahan isi list.


## Guided 

### 1. Buatlah ADT Singly Linked list sebagai berikut di dalam file “Singlylist.h”. Kemudian buat implementasi ADT Singly Linked list pada file “Singlylist.cpp”.

```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

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

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

#endif
```
Penjelasan singkat 1.singlylist.h:
File header ini berisi deklarasi ADT singly linked list. Header guard (#ifndef ... #endif) mencegah file ter-include lebih dari sekali, dan Nil didefinisikan sebagai NULL. infotype adalah alias dari int, sedangkan address adalah pointer ke struct ElmList. Struct ElmList menyimpan info dan pointer next, dan struct List menyimpan pointer First yang menunjuk node pertama. Prototype yang dideklarasikan adalah CreateList, alokasi, dealokasi, printInfo, dan insertFirst.

```C++
#include "singlylist.h"

void CreateList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address P = L.First;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}
```
Penjelasan singkat 1.singlylist.cpp: 
File ini berisi implementasi prototype di header. CreateList membuat list kosong dengan mengisi First = Nil. alokasi membuat node baru dengan new, mengisi info, dan mengatur next = Nil, sedangkan dealokasi menghapus node dengan delete. printInfo menelusuri list dari First sampai Nil sambil menampilkan setiap info. insertFirst menyisipkan node di awal list dengan mengarahkan next milik P ke First, lalu menjadikan P sebagai First yang baru.

```C++
#include "singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    CreateList;

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
Program utama membuat list kosong, lalu mengalokasikan lima node dengan nilai 2, 0, 8, 12, dan 9 dan menyisipkan masing-masing dengan insertFirst. Karena tiap node disisipkan di depan, urutan akhirnya terbalik menjadi 9 12 8 0 2. Isi list lalu ditampilkan dengan printInfo.

### Output Unguided 1 :

##### Output
![Screenshot Output Unguided 1](https://github.com/nawwarulayya/109082500153_NawwarUlayyaFrodine-StrukturData/blob/main/Modul4/UNGUIDED/1.singlylist/Output.png)


### 2. Carilah elemen dengan info 8 dengan membuat fungsi baru. fungsi findElm( L : List, x : infotype ) : address

```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

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

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);
address findElm(List L, infotype x);

#endif
```
Penjelasan singkat 2.singlylist.h:
Isinya sama dengan nomor 1, ditambah satu prototype baru yaitu address findElm(List L, infotype x). Fungsi ini mengembalikan alamat node yang info-nya sama dengan x.

```C++
#include "singlylist.h"

void CreateList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address P = L.First;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}

address findElm(List L, infotype x) {
    address P = L.First;
    while (P != Nil) {
        if (P->info == x) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}
```
Penjelasan singkat 2.singlylist.cpp: 
Implementasi fungsi dari nomor 1 tetap dipakai, ditambah fungsi findElm. Fungsi ini menelusuri list dari First secara berurutan. Jika info suatu node sama dengan x, alamat node tersebut langsung dikembalikan. Jika sampai Nil belum ditemukan, fungsi mengembalikan Nil.

```C++
#include "singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    CreateList;

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
    
    address P = findElm(L, 8);
    if (P != Nil) {
        cout << P->info << " ditemukan dalam list" << endl;
    } else {
        cout << "8 tidak ditemukan dalam list" << endl;
    }

    return 0;
}
```
Penjelasan singkat 2.main.cpp:
Program mengisi list dengan lima node seperti nomor 1, lalu memanggil findElm(L, 8) dan menyimpan hasilnya di P. Jika P tidak Nil, program menampilkan “8 ditemukan dalam list”, dan jika Nil, program menampilkan “8 tidak ditemukan dalam list”.

### Output Unguided 2 :

##### Output
![Screenshot Output Unguided 2](https://github.com/nawwarulayya/109082500153_NawwarUlayyaFrodine-StrukturData/blob/main/Modul4/UNGUIDED/2.singlylist/Output.png)


### 3. Hitunglah jumlah total info seluruh elemen (9+12+8+0+2=31).

```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

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

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);
address findElm(List L, infotype x);
int sumInfo(List L);

#endif
```
Penjelasan singkat 3.singlylist.h:
Isinya sama dengan nomor 2, ditambah prototype int sumInfo(List L) yang mengembalikan jumlah seluruh nilai info dalam list.

```C++
#include "Singlylist.h"

void CreateList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address P = L.First;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}

address findElm(List L, infotype x) {
    address P = L.First;
    while (P != Nil) {
        if (P->info == x) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

int sumInfo(List L) {
    int total = 0;
    address P = L.First;
    while (P != Nil) {
        total += P->info;
        P = P->next;
    }
    return total;
}
```
Penjelasan singkat 3.singlylist.cpp: 
Implementasi fungsi sebelumnya tetap dipakai, ditambah sumInfo. Fungsi ini menyiapkan variabel total = 0, lalu menelusuri list dari First sampai Nil sambil menambahkan P->info ke total pada setiap node. Setelah selesai, total dikembalikan.

```C++
#include "singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    CreateList;

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

    cout << "Total info dari kelima elemen adalah " << sumInfo(L) << endl;

    return 0;
}
```
Penjelasan singkat 3.main.cpp:
Program mengisi list dengan lima node (9, 12, 8, 0, 2), lalu memanggil sumInfo(L) dan menampilkan hasilnya, yaitu “Total info dari kelima elemen adalah 31”.

### Output Unguided 3 :

##### Output
![Screenshot Output Unguided 3](https://github.com/nawwarulayya/109082500153_NawwarUlayyaFrodine-StrukturData/blob/main/Modul4/UNGUIDED/1.singlylist/Output.png)


## Kesimpulan
Singly linked list dapat diimplementasikan dalam C++ menggunakan ADT yang dipisah menjadi file header dan file implementasi, dengan pointer sebagai penghubung antar node. Operasi dasar seperti CreateList, alokasi, insertFirst, dan printInfo berhasil membentuk dan menampilkan isi list. Operasi searching (findElm) dan penelusuran seluruh elemen (sumInfo) bekerja dengan pola traversal yang sama, yaitu menelusuri list dari First sampai Nil. Hasilnya, elemen dengan info 8 berhasil ditemukan dan total info seluruh elemen adalah 31. Praktikum ini juga menunjukkan bahwa alokasi memori dinamis harus dikelola dengan benar agar list berfungsi sesuai yang diharapkan.


## Referensi
[1] Laboratorium Informatika, Modul 5 Praktikum Struktur Data: Singly Linked List (Bagian Kedua). Bandung, Indonesia: Telkom University, 2026.