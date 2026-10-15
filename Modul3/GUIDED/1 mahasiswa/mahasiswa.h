#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INLCLUDED

struct mahasiswa {
    char nim[10];
    int nilai1, nilai2;
};

void inputMhs(mahasiswa &m) ;
float rata2(mahasiswa m) ;
#endif // MAHASISWA_H_INCLUDED