# <h1 align="center">Tugas CPMK 2 Sub CPMK 5 (Linked List)</h1>
<p align="center">2311110051 - Ardelia Rachma Laksita</p>

## Table of Contents
1. [Soal 1](#soal-1)
2. [Soal 2](#soal-2)
3. [Soal 3](#soal-3)

## Soal 1
### 1. Buatlah sebuah fungsi program untuk menghilangkan duplikasi data pada unsorted linked list (single atau double atau circular) (40 Poin)

**Kode Program**

```C++
#include <iostream>
#include <unordered_set>
using namespace std;

// PROGRAM DOUBLE LINKED LIST UNTUK MENGHAPUS DUPLIKASI DATA
// deklarasi data, next, dan previous dalam struct node.
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(NULL), prev(NULL) {}
};

// fungsi void untuk menghapus duplikasi data
void hapusDuplikasi(Node* head) {
    if (head == NULL) return;

    // unordered_set library yang berisi deklarasi list
    unordered_set<int> list;
    // deklarasi current = head dengan pointer
    Node* current = head;

    // saat data current tidak sama dengan NULL, artinya ada nilainya
    while (current != NULL) {
        if (list.find(current->data) != list.end()) {
            // data current akan dihapus karena ada duplikasi data
            Node* hapus = current;
            if (current->prev) current->prev->next = current->next;
            if (current->next) current->next->prev = current->prev;
            current = current->next;
            delete hapus;
        } else {
            // tidak ada duplikasi data
            list.insert(current->data);
            current = current->next;
        }
    }
}

// fungsi void menambahkan node baru pada linked list
void tambahData(Node*& head, int data) {
    Node* nodeBaru = new Node(data);
    // jika head (data depan) sama dengan NULL (tidak ada nilainya), maka buat node baru
    if (head == NULL) {
        head = nodeBaru;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = nodeBaru;
    nodeBaru->prev = temp;
}

// fungsi void untuk mencetak list
void cetakList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// main program
int main() {
    // header program
    cout << "------------------------------------------------------------------------------" << endl;
    cout << " ============ PROGRAM MENGHAPUS DUPLIKASI DATA PADA UNSORTED LIST ============" << endl;
    
    // deklarasi node head
    Node* head = NULL;
    // tambah data pada head list
    tambahData(head, 70);
    tambahData(head, 80);
    tambahData(head, 100);
    tambahData(head, 100);
    tambahData(head, 80);
    tambahData(head, 90);

    // tampilkan data yang telah ditambahkan
    cout << "List: ";
    // panggil fungsi yang mencetak data 
    cetakList(head);

    // tampilkan data yang telah ditambahkan (sebelum duplikasi data dihapus)
    cout << "List sebelum duplikasi data dihapus: ";
    // panggil fungsi yang mencetak data 
    cetakList(head);
    
    // panggil fungsi untuk menghapus duplikasi data
    hapusDuplikasi(head);
    
    // tampilkan data setelah duplikasi dihapus
    cout << "List setelah duplikasi data dihapus: ";
    // panggil fungsi yang mencetak data saat ini
    cetakList(head);

    // footer program
    cout << "------------------------------------------------------------------------------" << endl;

    return 0;
}

```
Kode tersebut digunakan untuk ...

#### Output:
![Cuplikan layar 2024-05-19 000237](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/0476e2ad-75e6-4807-a33e-df8ffc462235)

#### Full code Screenshot:
![Cuplikan layar 2024-05-19 000221](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/a306e350-0b5b-47f9-b6db-47b6fd1cbc3d)


## Soal 2
### 2. Buatlah sebuah algoritma dan fungsi program untuk menghapus node di tengah single linked list! (35 Poin)
**Kode Program**

```C++
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// PROGRAM MENGHAPUS NODE TENGAH PADA SINGLE LINKED LIST
// deklarasi struct variabel data dan next
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

// fungsi void menambahkan node baru di linked list
void tambahData(Node*& head, int data) {
    Node* nodeBaru = new Node(data);
    if (head == NULL) {
        head = nodeBaru;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = nodeBaru;
}

// fungsi void menghapus nilai pada linked list
void deleteMidNode(Node*& head, int dataValue) {
    // apabila nilai masih kosong
    if (head == NULL) {
        cout << "List masih kosong!" << endl;
        return;
    }

    // apabila list tidak kosong dan data telah berhasil dihapus
    if (head->data == dataValue) {
        Node* hapus = head;
        head = head->next;
        delete hapus;
        cout << "Data " << dataValue << " berhasil dihapus." << endl;
        return;
    }

    Node* current = head;
    while (current->next != NULL && current->next->data != dataValue) {
        current = current->next;
    }

    // apabila data yang ingin dihapus oleh user tidak ada di dalam list
    if (current->next == NULL) {
        cout << "Data " << dataValue << " tidak ditemukan dalam list." << endl;
        return;
    }

    // apabila data ditemukan dalam list dan data telah berhasil dihapus
    Node* hapus = current->next;
    current->next = current->next->next;
    delete hapus;
    cout << "Data " << dataValue << " berhasil dihapus." << endl;
}

// tampilkan isi linked list
void cetakList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// main program (program utama)
int main() {
    // deklarasi head dan nilai
    Node* head = NULL;
    int nilai;
    
    // header program
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << " ============ PROGRAM MENGHAPUS NODE TENGAH PADA SINGLE LINKED LIST ============" << endl;
    
    // tambah data pada list
    tambahData(head, 500);
    tambahData(head, 600);
    tambahData(head, 700);
    tambahData(head, 800);
    tambahData(head, 900);

    // tampilkan data yang telah ditambahkan (sebelum dihapus)
    cout << "List sebelum data dihapus: ";
    // memanggil fungsi cetakList untuk print data saat ini
    cetakList(head);
    
    // input user memilih data yang ingin dihapus
    cout << "Data manakah yang ingin Anda hapus?: ";
    cin >> nilai;
    // memanggil fungsi deleteMidNode untuk hapus data sesuai pilihan input user
    deleteMidNode(head, nilai);
    
    // tampilkan data saat ini (baik ada atau tidak ada yang dihapus)
    cout << "List data terbaru saat ini: ";
    // memanggil fungsi cetakList untuk print data saat ini
    cetakList(head);

    // footer program
    cout << "--------------------------------------------------------------------------------" << endl;

    return 0;
}

```
Kode tersebut digunakan untuk ...

#### Output:
![Cuplikan layar 2024-05-18 235938](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/b601b152-0ba8-440c-a923-f0b175bf25cd)

#### Full code Screenshot:
![Cuplikan layar 2024-05-18 235921](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/48fccfda-6185-4fa2-bb71-6c2da7dc5172)


## Soal 3
### 3. Buatlah sebuah program untuk mengecek apakah linked list adalah sebuah palindrom! (50 Poin)
**Kode Program**

```C++
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// PROGRAM PENGECEKAN PALINDROME
// class deret huruf 
class deretHuruf {
    // bagian public dari class deretHuruf
    public:
    deretHuruf() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    // menambahkan huruf
    void push(char hurufAwal) {
        node* temp = new node;
        temp->words = hurufAwal;
        temp->next = NULL;

        if (size == 0) {
            head = temp;
            tail = temp;
            head->prev = NULL;
        }
        else {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        size++;
    }

    // menghapus huruf
    char pop() {
        char words = head->words;
        if (head == tail) {
            delete head;
        }
        else {
            node* temp = head;
            head = head->next;
            head->prev;
            temp->next = NULL;
            delete temp;
        }
        size--;
        return words;
    }
    
    // bagian private dari class deretHuruf berisi struct dari node
    private:
    struct node {
        char words;
        node* next;
        node* prev;
    };

    // deklarasi size, words, dhead, dan tail menggunakan pointer node dalam private class deretHuruf
    int size;
    char words;
    node* head;
    node* tail;
};

// class stack (tumpukan) huruf
class stack {
    // bagian public dari class stack
    public:
    stack() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    // menambahkan huruf
    void push (char hurufAwal) {
        node* temp = new node;
        temp->words = hurufAwal;
        temp->next = NULL;

        if (size == 0) {
            head = temp;
            tail = temp;
            tail->prev = NULL;
        }

        else {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        size++;
    }

    // menghapus huruf
    char pop() {
        words = tail->words;
        if (head == tail) {
            delete head;  
        }

        else{
            node* temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            temp->prev = NULL;
            delete temp;
        }
        size--;
        return words;
    }

    // bagian private dari class stack berisi struct
    private:
    struct node{
        char words;
        node* next;
        node *prev;
    };

    // deklarasi size, words, head, dan tail dalam private class stack
    int size;
    char words;
    node* head;
    node* tail;
};


// main program (program utama)
int main() {

    // deklarasi kata, hurufAwal, hurufAkhir, checkAgain, firstWord pada class stack dan lastWord pada class words
    string kata;
    char hurufAwal;
    char hurufAkhir;
    char checkAgain;   
    stack firstWord;
    deretHuruf lastWord;
    
    // deklarasi palindrome
    bool palindrome = true;
    // tampilkan head atau judul dari program 
    cout << "=== PALINDROME WORDS CHECK ===" << endl;

    // user menginput kata
    cout << "Masukkan 1 kata: ";
    cin >> kata;
    cout << endl;

    // perulangan for untuk push firstWord dan lastWord 
    for (int i = 0; i < kata.length(); i++) {
        firstWord.push(tolower(kata[i]));
        lastWord.push(tolower(kata[i]));
    }

    // perulangan for untuk pop dan pengecekan palindrome
    for (int i = 0; i < kata.length(); i++) {
        char hurufAwal = firstWord.pop();
        char hurufAkhir = lastWord.pop();

        if (hurufAwal != hurufAkhir) {
            cout << hurufAwal << " != " << hurufAkhir << endl;
            palindrome = false;
        } else {
            cout << hurufAwal << " = " << hurufAkhir << endl; 
        }
    }

    cout << endl;

    // tampilkan hasil
    if (palindrome) {
        cout << "Kata tersebut merupakan kata palindrome." << endl;
        cout << "Semua huruf pada kata tersebut sama sehingga akan menghasilkan urutan huruf yang sama apabila kata dibalik." << endl;
    } else {
        cout << "Kata tersebut bukan merupakan kata palindrome." << endl;
        cout << "Terdapat urutan huruf yang tidak sama sehingga apabila kata tersebut dibalik maka tidak akan menghasilkan bacaan yang sama." << endl;
    }
    cout << "================================================================================================================================" << endl;
    cout << endl;
    return 0;
}

```
Kode tersebut digunakan untuk mengecek apakah suatu kata palindrome atau tidak. Apabila kata tersebut dibalik, maka akan menghasilkan urutan huruf yang sama seperti kata yang belum dibalik. Terdapat dua class pada program tersebut yaitu class deretHuruf dan class stack. Terdapat push yang digunakan untuk menambahkan data, serta terdapat pula pop yang digunakan untuk menghapus data. Pada bagian private masing-masing class harus terdapat deklarasi variabel. Tolower digunakan untuk mengkonversi semua huruf kapital menjadi kecil. 

#### Output dan Penjelasan:

![Cuplikan layar 2024-05-06 200046](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/3f95a46b-8646-41da-91b0-de39a57ac60c)
Pada output tersebut, kata yang diinput oleh user adalah **Malam**. Selanjutnya, program melakukan pengecekan palindrom menggunakan `for (int i = 0; i < kata.length(); i++)`, `char hurufAwal = firstWord.pop();`, dan `char hurufAkhir = lastWord.pop();`. Karena saat huruf-huruf yang ada pada kata malam dibalik menghasilkan urutan yang sama, maka malam termasuk kata palindrome. Huruf M pada awalan kata Malam yang awalnya menggunakan kapital telah diubah oleh program menjadi huruf kecil menggunakan tolower sehingga pengecekan palindromenya sudah dalam keadaan huruf kecil semua. 

![Cuplikan layar 2024-05-06 200058](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/a46231bb-95ba-4601-9e52-7600644c4daf)
Pada output tersebut, kata yang diinput oleh user adalah **Pagi**. Selanjutnya, program melakukan pengecekan palindrom menggunakan `for (int i = 0; i < kata.length(); i++)`, `char hurufAwal = firstWord.pop();`, dan `char hurufAkhir = lastWord.pop();`. Karena saat huruf-huruf yang ada pada kata pagi dibalik tidak menghasilkan urutan yang sama yaitu igap, maka pagi bukan termasuk kata palindrome. Huruf P pada awalan kata Pagi yang awalnya menggunakan kapital telah diubah oleh program menjadi huruf kecil menggunakan tolower sehingga pengecekan palindromenya sudah dalam keadaan huruf kecil semua. 

#### Penjelasan main program:
- Variabel-variabel yang digunakan dalam program harus dideklarasikan tipe datanya terlebih dahulu. Tipe data variabel kata adalah string karena terdapat lebih dari 1 karakter. Tipe data pada variabel hurufAwal dan hurufAkhir adalah char karena hanya memerlukan 1 karakter. hurufAwal merupakan urutan huruf dengan urutan mulai dari awal hingga akhir yang kemudian akan dipasangkan dengan hurufAkhir yang urutannya dimulai dari akhir menuju ke huruf awal. Huruf pertama diperiksa palindromnya dengan huruf terakhir. Apabila tidak sama, maka akan menghasilkan **hurufAwal != hurufAkhir**. Apabila sama, akan menghasilkan **hurufAwal = hurufAkhir**.
- `bool palindrome = true;` merupakan deklarasi palindrome yaitu tipe data boolean dengan deklarasi true.
- `cout << "=== PALINDROME WORDS CHECK ===" << endl;` digunakan untuk mencetak _head of the program_ atau judul program tersebut.
- `cout << "Masukkan 1 kata: ";` dan `cin >> kata;` digunakan untuk memasukkan kata yang akan diinput oleh user.
- Pada perulangan for yang berisi `firstWord.push(tolower(kata[i]));` dan `lastWord.push(tolower(kata[i]));` digunakan untuk menambahkan huruf awal hingga akhir dengan urutan yang sesuai dan urutan berkebalikan. Huruf yang masih dalam bentuk kapital akan diubah menjadi huruf kecil semua menggunakan tolower.
- Pada perulangan for yang berisi `char hurufAwal = firstWord.pop();` dan `char hurufAkhir = lastWord.pop();` digunakan untuk mengecek apakah suatu kata palindrome atau tidak. Urutan huruf dari awal ke akhir akan diperiksa apakah sama seperti urutan huruf dari akhir ke awal atau tidak.

#### Full code Screenshot:
![Cuplikan layar 2024-05-06 200024](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/a936a239-c282-4098-acce-539f35b653a4)
