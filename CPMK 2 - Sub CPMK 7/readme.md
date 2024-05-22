# <h1 align="center">Tugas CPMK 2 Sub CPMK 7 (Queue)</h1>
<p align="center">2311110051 - Ardelia Rachma Laksita</p>

## Table of Contents
1. [Soal 1](#soal-1)
2. [Soal 2](#soal-2)

## Soal 1
### 1. Tulislah sebuah program dari operasi queue seperti enqueue/add, dequeue/remove, isEmpty, isFull, dll(min 5)! (60 Poin)
Kode Program

```C++
#include <iostream>
#include <string>
using namespace std;

// PROGRAM QUEUE MENGGUNAKAN LINKED LIST BERISI ATRIBUT NAMA DAN NIM MAHASISWA
// struct Node
struct Node {
    // deklarasi Nama dan Nim
    string Nama;
    string Nim;
    Node *next;
};

// class Queue
class Queue {
// bagian public dari class Queue
public:
    Queue() {
        // deklarasi size, data front dan data back
        size = 0;
        front = NULL;
        back = NULL;
    }

    // mengecek apakah antrian penuh atau tidak
    bool isFull() {
        return false;
    }

    // mengecek apakah antrian kosong atau tidak
    bool isEmpty() {
    return size == 0;
    }

    // tambahkan data ke dalam antrian 
    void enqueueAntrian(string Nama, string Nim) {
        Node* baru = new Node();
        baru->Nama = Nama;
        baru->Nim = Nim;
        baru->next = NULL;

        // apabila antrian kosong, maka front dan back dimulai dari node baru
        if (isEmpty()) {
            front = baru;
            back = baru;
        // apabila antrian tidak kosong, maka dimulai dari node sebelumnya (back)
        } else {
            back->next = baru;
            back = baru;
        }

        size++;
    }

    // hapus data dalam antrian (otomatis menghapus front)
    void dequeueAntrian() {
        if (isEmpty()) {
            cout << "Antrian Kosong" << endl;
        } else {
            Node* temp = front;
            front = front->next;
            delete temp;
            size--;
        }
    }

    // lihat jumlah data dalam antrian 
    int countQueue() {
        return size;
    }

    // hapus seluruh data dalam antrian (kosongkan antrian)
    void clearQueue() {
        while (!isEmpty()) {
            dequeueAntrian();
        }
    }

    // lihat data antrian teller dengan atribut nama dan NIM mahasiswa
    void viewQueue() {
        cout << "Data antrian teller: " << endl;
        Node* current = front;
        for (int i = 0; i < size; i++) {
            cout << i + 1 << ". Nama: " << current->Nama << " (Nim: " << current->Nim << ")" << endl;
            current = current->next;
        }
    }

    ~Queue() {
        clearQueue();
    }

// bagian private dari class Queue
private:
    // deklarasi data front, back, dan size
    Node* front;
    Node* back;
    int size;
};

// main program (program utama)
int main() {
    // deklarasi class Queue serta tipe data Nama dan Nim
    Queue queueTeller;
    string Nama, Nim;

    // user input nama dan NIM mahasiswa pertama
    cout << "Masukkan Nama mahasiswa: ";
    cin >> Nama;
    cout << "Masukkan NIM mahasiswa: ";
    cin >> Nim;
    // panggil fungsi untuk menambahkan data ke dalam antrian
    queueTeller.enqueueAntrian(Nama, Nim);

    // user input nama dan NIM mahasiswa kedua
    cout << "Masukkan Nama mahasiswa: ";
    cin >> Nama;
    cout << "Masukkan NIM mahasiswa: ";
    cin >> Nim;
    // panggil fungsi untuk menambahkan data ke dalam antrian
    queueTeller.enqueueAntrian(Nama, Nim);

    // lihat data di dalam antrian saat ini
    queueTeller.viewQueue();
    // tampilkan jumlah atau banyak data dalam antrian saat ini
    cout << "Jumlah antrian = " << queueTeller.countQueue() << endl;
    cout << endl;

    // hapus antrian (data yang dihapus adalah front)
    queueTeller.dequeueAntrian();
    // lihat data di dalam antrian saat ini (setelah data front sebelumnya dihapus)
    queueTeller.viewQueue();
    // tampilkan jumlah atau banyak data dalam antrian saat ini 
    cout << "Jumlah antrian = " << queueTeller.countQueue() << endl;
    cout << endl;

    // bersihkan atau hapus seluruh antrian sehingga antrian kosong
    queueTeller.clearQueue();
    // lihat data di dalam antrian saat ini (setelah semua antrian dihapus)
    queueTeller.viewQueue();
    // tampilkan jumlah atau banyak data dalam antrian saat ini
    cout << "Jumlah antrian = " << queueTeller.countQueue() << endl;
    cout << endl;

    return 0;
}

```
Kode tersebut merupakan program yang menerapkan queue dengan konsep linked list sehingga terdapat struct dan class. Kode tersebut digunakan untuk menambahkan, menghapus, menghitung, mengosongkan, dan menampilkan data antrian dengan atribut nama dan NIM mahasiswa. Pada main program, user perlu menginputkan nama dan NIM mahasiswa melalui terminal setelah kode dijalankan. Tidak diperlukan class pada queue dengan array. Sedangkan pada linked list terdapat class Queue, program harus menggunakan variabel yang kemudian memanggil fungsi-fungsi di dalam kelas. `queueTeller` merupakan variabel, sedangkan `enqueueAntrian` merupakan fungsi yang digunakan dengan cara memanggil fungsi tersebut dari kelas. Sebelum menggunakan fungsi-fungsi di dalam class Queue, queueTeller harus dideklarasikan dulu dengan class yang akan digunakan sehingga deklarasinya adalah `Queue queueTeller;`. Berikut penjelasan kodenya:

Di dalam bagian dari private class Queue terdapat deklarasi data front, back, dan size.

Di dalam bagian dari public class Queue terdapat kode-kode berikut.
- `bool isFull()` digunakan untuk mengecek apakah antrian penuh atau tidak.
- `bool isEmpty()` digunakan untuk mengecek apakah antrian kosong atau tidak.
- `void enqueueAntrian(string data)` digunakan untuk menambahkan antrian baru.
- `void dequeueAntrian()` digunakan untuk menghapus antrian. Antrian yang dihapus yaitu data front (depan).
- `int countQueue()` digunakan untuk menghitung jumlah seluruh data yang saat ini ada di dalam antrian.
- `void clearQueue()` digunakan untuk menghapus seluruh data di dalam antrian sehingga antrian menjadi kosong.
- `void viewQueue()` digunakan untuk melihat data yang saat ini berada di dalam antrian.

#### Penjelasan Main Program:
- `cout << "Masukkan Nama mahasiswa: ";` akan meminta user untuk memasukkan nama mahasiswa.
- `cin >> Nama;` akan menampilkan nama yang telah diinput oleh user.
- `cout << "Masukkan NIM mahasiswa: ";` akan meminta user untuk memasukkan nim mahasiswa.
- `cin >> Nim;` akan menampilkan nim yang telah diinput oleh user.
- `queueTeller.enqueueAntrian(Nama, Nim);` akan memanggil fungsi enqueueAntrian di dalam class Queue untuk menambahkan data nama dan  nim yang telah diinput oleh user.
- Selanjutnya, data saat ini ditampilkan dengan `queueTeller.viewQueue();`.
- `cout << "Jumlah antrian = " << queueTeller.countQueue() << endl;` akan menampilkan banyaknya data dalam antrian.

**Penjelasan Output :**

User memasukkan nama dan nim mahasiswa yang pertama yaitu Aliana dengan NIM 231111008. Kemudian, user memasukkan nama dan nim mahasiswa yang kedua yaitu Ardelia dengan NIM 2311110051. Kemudian, data ditampilkan sehingga menghasilkan output sebagai berikut.

Selanjutnya, program akan menjalankan dequeue sehingga menghapus data front pada antrian tersebut. Data yang dihapus yaitu Aliana dengan NIM 2311110008. Saat ini, hanya ada 1 antrian yaitu Ardelia dengan NIM 2311110051 yang naik menjadi posisi 1. Berikut tampilan outputnya.

Terakhir, user mengosongkan list menggunakan clearQueue sehingga seluruh antrian dihapus. Saat ini tidak ada antrian sama sekali sehingga jumlah data antriannya adalah 0. Berikut output yang dihasilkan.


## Soal 2
### 2. Sebuah selter hewan terlantar, yang mana hanya menerima kucing dan anjing, menerapkan konsep “first in, first out” dalam proses adopsi. Orang-orang yang hendak mengadopsi harus mengikuti aturan berikut: 1) mengadopsi hewan yang paling “tua” (berdasarkan waktu masuk ke selter) dan tidak dapat memilih kucing atau anjing; 2) memilih antara kucing atau anjing, namun akan menerima yang paling tua. Buatlah data struktur untuk mengimplementasikan kondisi tersebut, silahkan menggunakan beberapa operasi queue seperti enquee, dequeueAny, dequeueDog, dan dequeueCat. (40 Poin)
Kode Program

```C++
#include <iostream>
#include <queue>
#include <string>
using namespace std;

// Kelas Hewan
class Animal {
public:
    string jenis;
    int timeAdd;

    Animal(string jenis, int timeAdd) {
        this->jenis = jenis;
        this->timeAdd = timeAdd;
    }

    friend ostream& operator<<(ostream& os, const Animal& animal) {
        os << animal.jenis << " masuk: " << animal.timeAdd;
        return os;
    }
};

// Kelas Shelter
class Queue {
public:
    queue<Animal> antrianHewan;

    // Menambahkan hewan ke shelter
    void enqueue(const Animal& animal) {
        antrianHewan.emplace(animal);
    }

    // Menghapus hewan tertua dari shelter
    Animal dequeueAny() {
        if (antrianHewan.empty()) {
            return Animal("", -1);
        }
        Animal hewanTertua = antrianHewan.front();
        antrianHewan.pop();
        return hewanTertua;
    }

    // Menghapus anjing tertua dari shelter
    Animal dequeueDog() {
        Animal foundDog("", -1); // Inisialisasi dengan Animal kosong
        queue<Animal> temp;
        while (!antrianHewan.empty()) {
            Animal hewan = antrianHewan.front();
            antrianHewan.pop();
            if (hewan.jenis == "Anjing") {
                foundDog = hewan;
                break;
            } else {
                temp.push(hewan);
            }
        }
        while (!temp.empty()) {
            Animal hewan = temp.front();
            temp.pop();
            antrianHewan.push(hewan);
        }
        return foundDog;
    }

    // Menghapus kucing tertua dari shelter
    Animal dequeueCat() {
        Animal foundCat("", -1); // Inisialisasi dengan Animal kosong
        queue<Animal> temp;
        while (!antrianHewan.empty()) {
            Animal hewan = antrianHewan.front();
            antrianHewan.pop();
            if (hewan.jenis == "Kucing") {
                foundCat = hewan;
                break;
            } else {
                temp.push(hewan);
            }
        }
        while (!temp.empty()) {
            Animal hewan = temp.front();
            temp.pop();
            antrianHewan.push(hewan);
        }
        return foundCat;
    }
};

// Program Utama
int main() {
    Queue shelter;

    // Menambahkan hewan ke shelter
    Animal animal1("Anjing", 50);
    Animal animal2("Kucing", 20);
    Animal animal3("Anjing", 30);

    shelter.enqueue(animal1);
    shelter.enqueue(animal2);
    shelter.enqueue(animal3);

    // Adopsi hewan tertua (tanpa memilih jenis)
    Animal adopsiHewan = shelter.dequeueAny();
    if (adopsiHewan.jenis != "") {
        cout << "Hewan yang diadopsi: " << adopsiHewan << endl;
    } else {
        cout << "Tidak ada hewan yang tersedia untuk diadopsi." << endl;
    }

    // Adopsi hewan tertua (memilih jenis)
    string jenisHewan;
    cout << "Pilih jenis hewan yang ingin diadopsi (Anjing/Kucing): ";
    cin >> jenisHewan;

    if (jenisHewan == "Anjing" || jenisHewan == "Kucing") {
        Animal adopsiHewanResult; // Gunakan nama yang berbeda
        if (jenisHewan == "Anjing") {
            adopsiHewanResult = shelter.dequeueDog();
        } else {
            adopsiHewanResult = shelter.dequeueCat();
        }

        if (adopsiHewanResult.jenis != "") {
            cout << "Hewan yang diadopsi: " << adopsiHewanResult << endl;
        } else {
            cout << "Tidak ada " << jenisHewan << " yang tersedia untuk diadopsi." << endl;
        }
    } else {
        cout << "Jenis hewan tidak valid." << endl;
    }

    return 0;
}

```

