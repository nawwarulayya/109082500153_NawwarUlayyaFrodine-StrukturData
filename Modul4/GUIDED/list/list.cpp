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