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

```

## Soal 2
### 2. Buatlah sebuah algoritma dan fungsi program untuk menghapus node di tengah single linked list! (35 Poin)
**Kode Program**

```C++

```


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


Pada output tersebut, kata yang diinput oleh user adalah **Malam**. Selanjutnya, program melakukan pengecekan palindrom menggunakan `for (int i = 0; i < kata.length(); i++)`, `char hurufAwal = firstWord.pop();`, dan `char hurufAkhir = lastWord.pop();`. Karena saat huruf-huruf yang ada pada kata malam dibalik menghasilkan urutan yang sama, maka malam termasuk kata palindrome. Huruf M pada awalan kata Malam yang awalnya menggunakan kapital telah diubah oleh program menjadi huruf kecil menggunakan tolower sehingga pengecekan palindromenya sudah dalam keadaan huruf kecil semua. 


Pada output tersebut, kata yang diinput oleh user adalah **Pagi**. Selanjutnya, program melakukan pengecekan palindrom menggunakan `for (int i = 0; i < kata.length(); i++)`, `char hurufAwal = firstWord.pop();`, dan `char hurufAkhir = lastWord.pop();`. Karena saat huruf-huruf yang ada pada kata pagi dibalik tidak menghasilkan urutan yang sama yaitu igap, maka pagi bukan termasuk kata palindrome. Huruf P pada awalan kata Pagi yang awalnya menggunakan kapital telah diubah oleh program menjadi huruf kecil menggunakan tolower sehingga pengecekan palindromenya sudah dalam keadaan huruf kecil semua. 

#### Penjelasan main program:
- Variabel-variabel yang digunakan dalam program harus dideklarasikan tipe datanya terlebih dahulu. Tipe data variabel kata adalah string karena terdapat lebih dari 1 karakter. Tipe data pada variabel hurufAwal dan hurufAkhir adalah char karena hanya memerlukan 1 karakter. hurufAwal merupakan urutan huruf dengan urutan mulai dari awal hingga akhir yang kemudian akan dipasangkan dengan hurufAkhir yang urutannya dimulai dari akhir menuju ke huruf awal. Huruf pertama diperiksa palindromnya dengan huruf terakhir. Apabila tidak sama, maka akan menghasilkan **hurufAwal != hurufAkhir**. Apabila sama, akan menghasilkan **hurufAwal = hurufAkhir**.
- `bool palindrome = true;` merupakan deklarasi palindrome yaitu tipe data boolean dengan deklarasi true.
- `cout << "=== PALINDROME WORDS CHECK ===" << endl;` digunakan untuk mencetak _head of the program_ atau judul program tersebut.
- `cout << "Masukkan 1 kata: ";` dan `cin >> kata;` digunakan untuk memasukkan kata yang akan diinput oleh user.
- Pada perulangan for yang berisi `firstWord.push(tolower(kata[i]));` dan `lastWord.push(tolower(kata[i]));` digunakan untuk menambahkan huruf awal hingga akhir dengan urutan yang sesuai dan urutan berkebalikan. Huruf yang masih dalam bentuk kapital akan diubah menjadi huruf kecil semua menggunakan tolower.
- Pada perulangan for yang berisi `char hurufAwal = firstWord.pop();` dan `char hurufAkhir = lastWord.pop();` digunakan untuk mengecek apakah suatu kata palindrome atau tidak. Urutan huruf dari awal ke akhir akan diperiksa apakah sama seperti urutan huruf dari akhir ke awal atau tidak.

#### Full code Screenshot:

