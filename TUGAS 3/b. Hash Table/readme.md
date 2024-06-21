
# <h1 align="center">Hash Table</h1>
<p align="center">2311110051 - Ardelia Rachma Laksita</p>

## Table of Contents
1. [Penjelasan](#penjelasan)
2. [Contoh Program](#contoh-program)
3. [Penjelasan Alur Program](#penjelasan-alur-program)
4. [Referensi](#referensi)

# Penjelasan
Tabel hash adalah struktur data yang memetakan kunci ke nilai menggunakan fungsi hash [1]. Tabel hash menawarkan kompleksitas waktu kasus rata-rata O(1) untuk penyisipan, penghapusan, dan pengambilan data, menjadikannya alat penting dalam banyak algoritma dan aplikasi. Table hash membutuhkan parameter key untuk operasi kuncinya. Hash table menggunakan chaining digunakan untuk menyelesaikan kasus collision [2]. 

### Implementasi Hash Table:

![Cuplikan layar 2024-06-04 104155](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/88dcc3bc-3de3-4e90-9a72-ee3ca4936f31)

**Separate Chaining**

![Cuplikan layar 2024-06-04 104223](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/452e4f69-becd-4b46-88ce-9c98d4c559f4)


**_Sitasi : 3_**

Separate Chaining adalah konsep mempertahankan struktur data (daftar tertaut) untuk menampung semua pasangan nilai kunci untuk nilai hash tertentu [3]. Pada diagram di atas, kita memiliki nilai hash yang sama untuk alice dan bob, jadi kita telah membuat rantai terpisah untuk menyimpan semua nilai kunci untuk nilai hash 0.

**Open Addressing**

Open addressing adalah teknik lain untuk menyelesaikan masalah tabrakan (collision issues) [3]. Tabel hash terdiri dari serangkaian _array of buckets_, masing-masing dengan indeks unik. Indeks array ditentukan oleh fungsi hash yang mengambil kunci sebagai masukan dan mengembalikan nilai bilangan bulat.

Ketika _collision_ terjadi, elemen baru dimasukkan ke dalam array kosong berikutnya yang tersedia di tabel. Ada beberapa teknik untuk mencari array kosong berikutnya, seperti: _Linear probing_, _Quadratic probing_, dan _Double hashing_ [3].


# Contoh Program
```C++
#include <iostream>
using namespace std;
const int MAX_SIZE = 10;

// fungsi hash sederhana
int hash_func(int key) {
    return key % MAX_SIZE;
}

// struktur data untuk setiap node
struct Node {
    long long NIM;
    int nilai;
    Node* next;
    Node(long long NIM, int nilai) : NIM(NIM), nilai(nilai), next(NULL) {}
};

// class hash table
class HashTable {
private:
    Node** table;
public:
    HashTable() {
        table = new Node*[MAX_SIZE]();
    }
    ~HashTable() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != NULL) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    // insertion
    void insert(long long NIM, int nilai) {
        int index = hash_func(NIM);
        Node* current = table[index];
        while (current != NULL) {
            if (current->NIM == NIM) {
                current->nilai = nilai;
                return;
            }
            current = current->next;
        }
        Node* node = new Node(NIM, nilai);
        node->next = table[index];
        table[index] = node;
    }

    // searching berdasarkan NIM
    int get(long long NIM) {
        int index = hash_func(NIM);
        Node* current = table[index];
        while (current != NULL) {
            if (current->NIM == NIM) {
                return current->nilai;
            }
            current = current->next;
        }
        return -1; // Tidak ditemukan
    }

    // menghapus berdasarkan NIM
    void remove(long long NIM) {
        int index = hash_func(NIM);
        Node* current = table[index];
        Node* prev = NULL;
        while (current != NULL) {
            if (current->NIM == NIM) {
                if (prev == NULL) {
                    table[index] = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    // searching berdasarkan nilai
    void getNilai(int min, int max) {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != NULL) {
                if (current->nilai >= min && current->nilai <= max) {
                    cout << "NIM: " << current->NIM << ", Nilai: " << current->nilai << endl;
                }
                current = current->next;
            }
        }
    }

    // traversal untuk menampilkan hash table
    void traverse() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != NULL) {
                cout << "NIM: " << current->NIM << ", Nilai: " << current->nilai << endl;
                current = current->next;
            }
        }
    }
};

void optionMenu() {
    cout << "================ PROGRAM DATA MAHASISWA ==================" << endl;
    cout << "1. Tambah data mahasiswa" << endl;
    cout << "2. Hapus data mahasiswa" << endl;
    cout << "3. Cari data mahasiswa berdasarkan NIM" << endl;
    cout << "4. Cari data mahasiswa berdasarkan rentang nilai (80-90)" << endl;
    cout << "5. Tampilkan semua data mahasiswa" << endl;
    cout << "6. Keluar" << endl;
    cout << "Opsi mana yang ingin Anda pilih? : ";
}

// program utama (main program)
int main() {
    HashTable ht;
    int option, NIM, nilai;

    while (true) {
        optionMenu();
        cin >> option;
        switch (option) {
            // insert data mahasiswa berisi NIM dan nilai
            case 1:
                cout << "Masukkan NIM: ";
                cin >> NIM;
                cout << "Masukkan Nilai: ";
                cin >> nilai;
                ht.insert(NIM, nilai);
                break;
            // hapus data mahasiswa
            case 2:
                cout << "Masukkan NIM yang ingin dihapus: ";
                cin >> NIM;
                ht.remove(NIM);
                break;
            // cari data mahasiswa berdasarkan NIM
            case 3:
                cout << "Masukkan NIM yang ingin dicari: ";
                cin >> NIM;
                nilai = ht.get(NIM);
                if (nilai != -1) {
                    cout << "Nilai Mahasiswa dengan NIM " << NIM << " adalah " << nilai << endl;
                } else {
                    cout << "Mahasiswa dengan NIM " << NIM << " tidak ditemukan." << endl;
                }
                break;
            // cari data mahasiswa berdasarkan nilai
            case 4:
                cout << "Mahasiswa dengan nilai antara 80 dan 90:" << endl;
                ht.getNilai(80, 90);
                break;
            // tampilkan seluruh data mahasiswa
            case 5:
                cout << "Data seluruh mahasiswa:" << endl;
                ht.traverse();
                break;
            // return
            case 6:
                return 0;
            // apabila user input pilihan selain 1-6
            default:
                cout << "Pilihan yang Anda masukkan tidak valid." << endl;
        }
        cout << endl;
    }
}

```

# Penjelasan Alur Program
Kode tersebut digunakan untuk menambahkan, menghapus, dan mencari data NIM dan nilai mahasiswa berdasarkan NIM dan rentang nilainya. Terdaoat program menu dengan 6 case. 

#### Penjelasan Kode:
- `int hash_func(int key)` merupakan fungsi hash sederhana yang digunakan untuk menghitung indeks untuk kunci yang diberikan dengan cara mengambil sisa bagi kunci tersebut dengan ukuran maksimum tabel hash (MAX_SIZE).
- `struct Node` merupakan struct merepresentasikan setiap elemen dalam tabel hash. Setiap node menyimpan NIM, nilai, dan pointer next yang menunjuk ke node berikutnya. Hash table membutuhkan parameter key untuk operasi kuncinya.
- `class HashTable` merupakan class yang menjadi bentuk implementasi dari hash table sederhana. Private classnya menyimpan deklaras `Node** table;`. Public classnya berisi perulangan for `for (int i = 0; i < MAX_SIZE; i++) ` yang akan menginisialisasi tabel dengan ukuran MAX_SIZE dan membersihkan memori yang digunakan oleh tabel hash dengan menghapus setiap node yang ada.
- `void insert(long long NIM, int nilai)` digunakan untuk menambahkan elemen baru ke dalam hash table. ` if (current->NIM == NIM)` artinya jika saat ini sudah ada NIMnya (bukan NULL), maka nilai akan diperbarui. `current = current->next;` artinya, apabila belum ada NIM, maka node baru akan ditambahkan di awal list sesuai indeksnya. Hal yang sama juga berlaku pada `current->nilai = nilai;`
- `int get(long long NIM)` digunakan untuk mendapatkan suatu nilai berdasarkan NIM. Apabila node saat ini sama dengan NIM, maka akan menjalankan `return current->nilai;` yaitu mengembalikan nilai. Sedangkan apabila NIM belum didapatkan, maka akan menjalankan `return -1`.
- `void remove(long long NIM)` digunakan untuk menghapus data berdasarkan NIM yang dimasukkan.
- `void getNilai(int min, int max)` digunakan untuk mendapatkan atau mencari data berdasarkan nilai dengan rentang 80-90.
- `void traverse()` digunakan untuk mencetak semua elemen dalam hash table.
- `void optionMenu()` berisi program menu yang akan ditampilkan untuk dipilih oleh user. Terdapat 5 menu yang dapat dilakukan oleh user beserta 1 opsi keluar apabila user ingin keluar dari program.

#### Penjelasan Main Program:
- `HashTable ht;` dan `int option, NIM, nilai;` merupakan deklarasi.
- `optionMenu()` digunakan untuk memanggil prorgam menu dan meminta user memasukkan option menggunakan `cin >> option;`.
- Pada `switch (option)` terdapat beberapa case. Case 1 akan menambahkan data mahasiswa berisi NIM dan nilai. Case 2 akan menghapus data mahasiswa meggunakan NIM yang dimasukkan. Case 3 akan melakukan pencarian (searching) data mahasiswa berdasarkan NIM. Case 4 akan melakukan pencarian (searching) data mahasiswa berdasarkan rentang nilai (80-90). Case 5 akan menampilkan seluruh data menggunakan traverse. Case 6 merupakan menu keluar dari program (selesai). Apabila pilihan yang dimasukkan selain 1, 2, 3, 4, 5, 6, maka akan menampilkan "Pilihan yang Anda masukkan tidak valid".

#### Output dan Penjelasan:

![1](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/2bf44f72-335a-481c-81b4-e26bcf7d0ff6)

Pada output tersebut, user memasukkan opsi 1 untuk menambahkan data mahasiswa yaitu NIM 23110051 dengan nilai 95. Saat ini ada 1 data dalam hash table.

![2](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/b5623787-3ea3-4a49-b097-edf9518dbb8b)

Pada output tersebut, user memasukkan opsi 1 untuk menambahkan data mahasiswa yaitu NIM 23110097 dengan nilai 85. Saat ini ada 2 data dalam hash table.

![3](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/755e6d46-9107-4ad9-993c-8475b558e099)

Pada output tersebut, user memasukkan opsi 1 untuk menambahkan data mahasiswa yaitu NIM 23110092 dengan nilai 90. Saat ini ada 3 data dalam hash table.

![4](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/10585e0c-69fc-4017-bd87-2fddef89e99b)

Pada output tersebut, user memasukkan opsi 1 untuk menambahkan data mahasiswa yaitu NIM 23110077 dengan nilai 89. Saat ini ada 4 data dalam hash table.

![5](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/5d54cf09-a9d5-4bf1-a742-84f27b0c9434)

Pada output tersebut, user memasukkan opsi 5 sehingga program menampilkan seluruh data yang ada dalam hash table saat ini setelah 4 data ditambahkan.

![6](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/a4d2ad6b-9141-4cbd-a111-a85e9fec18d8)

Pada output tersebut, user memasukkan opsi 2 untuk menghapus data mahasiswa dengan NIM 23110097 sehingga data tersebut beserta nilainya dihapus. NIM 23110097 dengan nilai 85 dihapus

![7](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/08494338-c80e-4d3b-9ee9-6feaf523d421)

Pada output tersebut, user memasukkan opsi 5 untuk menampilkan data seluruh mahasiswa saat ini setelah NIM 23110097 dihapus. Terdapat 3 data pada hash table saat ini. 

![8](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/14f53f17-46f1-4142-ac6a-03363e7af344)

Pada output tersebut, user memasukkan opsi 3 untuk mencari data mahasiswa berdasarkan NIM. NIM yang ingin dicari adalah 23110051 sehingga program menampilkan nilai mahasiswa tersebut yaitu 95.

![9](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/6dbdc8f5-ef74-4617-93c2-d735185bd517)

Pada output tersebut, user memasukkan opsi 4 sehingga program menampilkan nilai-nilai mahasiswa beserta NIM mereka yang memiliki nilai pada rentang 80-90. NIM 23110051 tidak ditampilkan karena nilainya di luar rentang 80-90.

![10](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/85df6ad4-6114-4a7e-b9bd-aeda5cefed5c)

Pada output tersebut, user memasukkan opsi 5 untuk menampilkan seluruh data mahasiswa yang ada pada hash table saat ini.

![11](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/852fa19c-11e7-41b8-b6e2-5a7b20f0f640)

Pada output tersebut, user memasukkan opsi 6 untuk keluar dari program sehingga tidak menampilkan opsi menu lagi dan program berhenti.

#### Full code Screenshot:
![full ss](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/c5de9002-048f-40a8-89a8-bbc372c174b4)


# Referensi
- [1] I. Ashraf, “Hash Table,” Medium, Dec. 27, 2023. Available: https://medium.com/@realirfanashraf/hash-table-176d0b18b59b#:~:text=A%20Hash%20Table%2C%20also%20referred%20to%20as%20a%20hash%20map,autonomously%20adds%20its%20own%20keys.. [Accessed: Jun. 03, 2024]
- [2] J. Farrier, Data Structures and Algorithms with the C++ STL. Edisi Pertama. Birmingham : Packt Publishing Ltd, 2024. https://www.google.co.id/books/edition/Data_Structures_and_Algorithms_with_the/JCf2EAAAQBAJ?hl=id&gbpv=1
- [3] V. Rana, “Everything You Need to Know About Hash Tables,” Medium, Feb. 28, 2023. Available: https://vishalrana9915.medium.com/everything-you-need-to-know-about-hash-tables-7e2bf812c7fe. [Accessed: Jun. 02, 2024]
