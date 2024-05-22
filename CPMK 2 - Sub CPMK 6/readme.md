# <h1 align="center">Tugas CPMK 2 Sub CPMK 6 (Stack)</h1>
<p align="center">2311110051 - Ardelia Rachma Laksita</p>

## Table of Contents
1. [Soal 1](#soal-1)
2. [Soal 2](#soal-2)

## Soal 1
### 1. Tulislah sebuah program dari operasi stack seperti pop, push, isEmpty, isFull, dll(min 5)! (60 Poin)
Kode Program

```C++
#include <iostream>
using namespace std;

// PROGRAM OPERASI STACK

// deklarasi ukuran maksimal array buah
string arrayBuah[5];
int maksimal = 5, top = 0;

// operasi pengecekan jika array penuh
bool isFull() {
    return (top == maksimal);
}

// operasi pengecekan jika array kosong
bool isEmpty() {
    return (top == 0);
}

// operasi menambah isi array buah
void pushArrayBuah(string data) {
    if (isFull()) {
        cout << "Data telah penuh" << endl;
    } else {
        arrayBuah[top] = data;
        top++;
    }
}

// operasi menghapus isi array buah
void popArrayBuah() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dihapus" << endl;
    } else {
        arrayBuah[top - 1] = "";
        top--;
    }
}

// operasi melihat isi array buah
void peekArrayBuah(int posisi) {
    if (isEmpty()) {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    } else if (posisi > top || posisi <= 0) {
        cout << "Posisi tidak valid" << endl;
    } else {
        cout << "Posisi ke " << posisi << " adalah buah " << arrayBuah[top - posisi] << endl;
    }
}

// operasi menghitung isi stack
int countStack() {
    return top;
}

// operasi mengubah isi array buah
void changeArrayBuah(int posisi, string data) {
    if (posisi > top || posisi <= 0) {
        cout << "Posisi melebihi data yang ada atau tidak valid" << endl;
    } else {
        arrayBuah[top - posisi] = data;
    }
}

// operasi menghapus seluruh isi array buah sehingga kosong
void destroyArrayBuah() {
    for (int i = 0; i < top; i++) {
        arrayBuah[i] = "";
    }
    top = 0;
}

// tampilkan seluruh isi array buah saat ini
void printArrayBuah() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dicetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--) {
            cout << arrayBuah[i] << endl;
        }
    }
}

// main program (program utama)
int main() {
    // tambahkan isi array buah
    pushArrayBuah("Apel");
    pushArrayBuah("Durian");
    pushArrayBuah("Nanas");
    pushArrayBuah("Mangga");
    pushArrayBuah("Pepaya");

    // panggil fungsi mencetak array buah
    printArrayBuah();
    cout << "\n";

    // pengecekan apakah stack penuh atau kosong
    cout << "Apakah data stack penuh? " << (isFull() ? "Ya" : "Tidak") << endl;
    cout << "Apakah data stack kosong? " << (isEmpty() ? "Ya" : "Tidak") << endl;

    // panggil fungsi melihat array buah
    peekArrayBuah(2);
    // panggil fungsi menghapus array buah
    popArrayBuah();

    // tampilkan banyaknya data pada stack
    cout << "Banyaknya Data = " << countStack() << endl;
    
    // panggil fungsi untuk ubah array buah
    changeArrayBuah(2, "Manggis");
    // panggil fungsi mencetak array buah saat ini
    printArrayBuah();

    cout << "\n";
    // panggil fungsi menghapus seluruh isi array sehngga stack kosong
    destroyArrayBuah();
    cout << "Jumlah data setelah dihapus: " << top << endl;
    // panggil fungsi mencetak array buah saat ini
    printArrayBuah();
    
    return 0;
}

```
### Output:
![program 1 output](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/759a91ff-3971-401e-8beb-9450c6be7e00)

### Full code of screenshot:
![program 1 full ss](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/942b6241-00c1-4861-ab9c-7b0cd18529c1)


## Soal 2
### 2. Tulislah sebuah program untuk mensortir sebuah stack, sehingga item dengan nilai terkecil menjadi top pada stack tersebut! Diperbolehkan menggunakan tambahan temporary stack, namun tidak diperbolehkan untuk menyalin dari struktur data yang lain seperti array. Program stack yang dibuat dapat menggunakan operasi stack seperti push, pop, peek, dan isEmpty. (40 poin)
Kode Program

```C++

#include <iostream>
#include <stack>
using namespace std;

// PROGRAM MENSORTIR SEBUAH STACK SEHINGGA ELEMEN TERKECIL MENJADI ELEMEN TOP

// fungsi void mengurutkan stack
void sortStack(stack<int>& data) {
    stack<int> temp; 
    while (!data.empty()) { 
        // ambil elemen paling atas stack data
        int cur = data.top(); 
        // hapus elemen paling atas stack data
        data.pop(); 

        // pindahkan elemen-elemen yang lebih besar 
        while (!temp.empty() && temp.top() > cur) {
            // pindah elemen paling atas stack temp ke data
            data.push(temp.top()); 
            // hapus elemen paling atas stack temp
            temp.pop(); 
        }
        temp.push(cur);
    }

    // balik urutan elemen agar elemen terkecil menjadi elemen top
    while (!temp.empty()) {
        data.push(temp.top()); 
        temp.pop(); 
    }
}

int main() {
    // deklarasi stack data
    stack<int> data; 
    // tambah elemen ke stack data
    data.push(10); 
    data.push(20); 
    data.push(21); 
    data.push(12); 
    data.push(31); 

    // menyimpan salinan stack asli sebelum diurutkan
    stack<int> originalData = data;

    // panggil fungsi urutkan stack
    sortStack(data);

    // tampilkan data belum terurut
    cout << "Data sebelum terurut: ";
    while (!originalData.empty()) {
        cout << originalData.top() << " "; 
        originalData.pop();
    }
    cout << endl;

    // tampilkan hasil data terurut
    cout << "Data terurut: ";
    while (!data.empty()) {
        cout << data.top() << " "; 
        data.pop();
    }
    cout << endl;

    return 0;
}

```
### Output:
![program 2 output](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/516c84e5-51fe-4607-86df-549afb1d3715)

### Full code of screenshot:
![program 2 full ss](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/616b2539-a2b3-492d-afcb-dc910987010f)
