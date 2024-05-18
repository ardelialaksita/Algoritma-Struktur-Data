
# <h1 align="center">Tugas CPMK 2 Sub CPMK 4 (Struct)</h1>
<p align="center">2311110051 - Ardelia Rachma Laksita</p>

## Table of Contents
1. [Soal 1](#soal-1)
2. [Referensi](#referensi)

## Soal 1
### 1. Berikan penjelasan dari struct dan buatlah sebuah contoh program dari struct! (100 poin)
Struct atau struktur data adalah salah satu tipe data di C++ yang memungkinkan kita untuk menggabungkan beberapa tipe data yang berbeda menjadi satu kesatuan logis [2]. Isinya dapat berupa variabel dan fungsi sebagai anggota atau elemennya. Struct dapat digunakan untuk merepresentasikan data yang memiliki banyak elemen dan objek yang kompleks. Apabila ingin menambahkan struct ke dalam struct lain yang bertipe sama, operator relasional tidak bisa digunakan pada variabel struct [7]. Contohnya `if (mahasiswa == mahasiswaBaru)` adalah tindakan ilegal. 

Beberapa anggota dalam struct memungkinkan digunakan secara bersamaan. Struct termasuk data komposit dan lebih dikenali di C++ [4]. Dalam mengakses suatu _field_, notasi seperti berikut digunakan : **_Variabel_struct.namefield_** [3]. Pengikatan struct (struct _bindings_) memungkinkan pembongkaran elemen dari tuples, pairs, atau objects ke dalam variabel dengan nama terpisah sehingga dapat dibaca dengan mudah [1]. Sintaks ini menyederhanakan akses beberapa elemen yang dikembalikan dari suatu fungsi atau menguraikan struktur data yang kompleks [1]. Struct juga dapat meningkatkan kejelasan dari kode. 

Sebuah semikolon (yang berada setelah kurung kurawal kanan) sangat penting untuk mengakhiri statement struct [5]. Semikolon di akhir definisi struct merupakan bagian dari sintaks [8]. Pelabelan struct sama seperti tipe-tipe data C++ yang lain. Deklarasi suatu struct adalah definisi suatu tipe baru [6].

### Penerapan atau Penggunaan Struct :
- Struct memungkinkan anggota digunakan secara bersamaan.
- Anggota atau elemen struct dapat didefinisikan dengan tipe yang berbeda.
- Tipe struct yang telah didefinisikan dapat digunakan untuk mendeklarasikan variabel.
- Pada akhir statement struct harus menggunakan sebuah semikolon (;).

**Kode Program**
```C++
#include <iostream>
using namespace std;

// PROGRAM STRUCT DAFTAR BUKU FAVORIT
// mendefinisikan struktur buku dengan panjang array sebanyak 5 pada masing-masing kategori
struct buku {
    string judulBuku[5]; // deklarasi tipe data judulBuku dan banyak datanya
    string pengarang[5]; // deklarasi tipe data pengarang dan banyak datanya
    string penerbit[5]; // deklarasi tipe data penerbit dan banyak datanya
    int tebalHalaman[5]; // deklarasi tipe data tebal Halaman dan banyak datanya
    int hargaBuku[5]; // deklarasi tipe data hargaBuku dan banyak datanya
};

int main() {
    // deklarasi variabel favorit dengan tipe buku
    buku favorit;

    // mengisi data ke dalam variabel favorit
    // data buku pertama
    favorit.judulBuku[0] = "Overthinking is My Hobby";
    favorit.pengarang[0] = "Alvi Syahrin";
    favorit.penerbit[0] = "Kawah Media";
    favorit.tebalHalaman[0] = 268;
    favorit.hargaBuku[0] = 99000;

    //data buku kedua
    favorit.judulBuku[1] = "Insecurity is My Middle Name";
    favorit.pengarang[1] = "Alvi Syahrin";
    favorit.penerbit[1] = "Kawah Media";
    favorit.tebalHalaman[1] = 264;
    favorit.hargaBuku[1] = 99000;

    // data buku ketiga
    favorit.judulBuku[2] = "Autumn in Paris";
    favorit.pengarang[2] = "Ilana Tan";
    favorit.penerbit[2] = "Gramedia Pustaka Utama";
    favorit.tebalHalaman[2] = 260;
    favorit.hargaBuku[2] = 79000;

    // data buku keempat
    favorit.judulBuku[3] = "The Star and I";
    favorit.pengarang[3] = "Ilana Tan";
    favorit.penerbit[3] = "Gramedia Pustaka Utama";
    favorit.tebalHalaman[3] = 344;
    favorit.hargaBuku[3] = 99000;

    // data buku kelima
    favorit.judulBuku[4] = "Teluk Alaska";
    favorit.pengarang[4] = "Eka Aryani";
    favorit.penerbit[4] = "Bumi Semesta Media";
    favorit.tebalHalaman[4] = 408;
    favorit.hargaBuku[4] = 99000;

    // menampilkan seluruh informasi buku favorit
    cout << "============ DAFTAR BUKU FAVORIT SAYA ============" << endl;
    // perulangan for untuk menampilkan data masing-masing buku
    for (int i=0; i < 5; i++) {
        cout << "\n \tBuku ke-" << i+1 << endl;
        cout << "\tJudul Buku    : " << favorit.judulBuku[i] << endl;
        cout << "\tPengarang     : " << favorit.pengarang[i] << endl;
        cout << "\tPenerbit      : " << favorit.penerbit[i] << endl;
        cout << "\tTebal Halaman : " << favorit.tebalHalaman[i] << " halaman" << endl;
        cout << "\tHarga Buku    : Rp " << favorit.hargaBuku[i] << endl;
    }
    // return sebagai kode bahwa program telah selesai dan berhasil
    return 0;
}

```
Kode tersebut digunakan untuk menampilkan data tentang buku favorit dengan panjang 5 array sehingga terdapat 5 buku favorit. Kategori buku terdiri atas judulBuku, pengarang, penerbit, tebalHalaman, dan hargaBuku. Program tersebut tidak menggunakan _input user_ karena datanya langsung diisi pada kode program. 

Pada `struct buku { };` berisi kode-kode deklarasi struct buku tersebut yaitu judul buku, pengarang, dan penerbit yang bertipe data string, serta tebal halaman dan harga buku yang bertipe integer. `string judulBuku;`, `string pengarang;`, `string penerbit;`, `int tebalHalaman;`, `int hargaBuku;` merupakan bentuk deklarasinya. 

#### Penjelasan main program:
- `favorit.judulBuku[i]` digunakan untuk memasukkan data judul buku. 
- `favorit.pengarang[i]` digunakan untuk memasukkan data pengarang buku.
- `favorit.penerbit[i]` digunakan untuk memasukkan data penerbit buku.
- `favorit.tebalHalaman[i]` digunakan untuk memasukkan data tebal halaman buku.
- `favorit.hargaBuku[i]` digunakan untuk memasukkan data harga buku.

`[i]` artinya indeks, digunakan untuk mengetahui posisi buku ke berapa yang datanya sedang dimasukkan. Karena panjang arraynya adalah 5, maka i-nya terdiri atas 0-4. Berikut penjelasan singkatnya.

- `favorit.judulBuku[1] = "Insecurity is My Middle Name";` merupakan judul buku yang terletak pada indeks ke-1 yaitu "Insecurity is My Middle name".
- `favorit.pengarang[1] = "Alvi Syahrin";` merupakan pengarang buku yang terletak pada indeks ke-1 yaitu Alvi Syahrin.
- `favorit.penerbit[1] = "Kawah Media";` merupakan penerbit buku yang terletak pada indeks ke-1 yaitu Kawah Media.
- `favorit.tebalHalaman[1] = 264;` merupakan tebal halaman buku yang terletak pada indeks ke-1 yaitu sebanyak 264 halaman.
- `favorit.hargaBuku[1] = 99000;` merupakan harga buku yang terletak pada indeks ke-1 yaitu Rp99.000,00.

Setelah data dimasukkan pada kode-kode di atas, buatlah kode untuk menampilkan data-data tersebut yaitu dengan menggunakan cout. `cout << "============ DAFTAR BUKU FAVORIT SAYA ============" << endl;` akan menampilkan _head_ atau _title of the program_ yaitu Daftar Buku Favorit Saya. 
- `cout << "\tJudul Buku : " << favorit.judulBuku[i] << endl;` digunakan untuk menampilkan judul buku dengan memanggil kode `favorit.judulBuku[i]` untuk menampilkan data buku pada suatu indeks tertentu pada [i].
- `cout << "\tPengarang : " << favorit.pengarang[i] << endl;` digunakan untuk menampilkan pengarang buku dengan memanggil kode `favorit.pengarang[i]` untuk menampilkan data buku pada suatu indeks tertentu pada [i].
- `cout << "\tPenerbit : " << favorit.penerbit[i] << endl;` digunakan untuk menampilkan penerbit buku dengan memanggil kode `favorit.penerbit[i]` untuk menampilkan data buku pada suatu indeks tertentu pada [i].
- `cout << "\tTebal Halaman: " << favorit.tebalHalaman[i] << " halaman" << endl;`digunakan untuk menampilkan tebal halaman buku dengan memanggil kode `favorit.tebalHalaman[i]` untuk menampilkan data buku pada suatu indeks tertentu pada [i].
- `cout << "\tHarga Buku : Rp " << favorit.hargaBuku[i] << endl;` digunakan untuk menampilkan harga buku dengan memanggil kode `favorit.hargaBuku[i]` untuk menampilkan data buku pada suatu indeks tertentu pada [i].
- `/t` digunakan untuk membuat indentasi atau _space_ kosong pada suatu kode sehingga dapat dibaca dengan lebih terstruktur, fungsinya hampir sama seperti tab (membuat data lebih memiliki awalan yang agak menjorok).


## Referensi
- [1] Farrier, J., Data Structures and Algorithms with the C++ STL. Edisi Pertama. Birmingham : Packt Publishing Ltd, 2024.
- [2] Guntara, R.G., Algoritma dan Pemrograman Dasar : Menggunakan Bahasa Pemrograman C++ dengan Contoh Kasus Aplikasi untuk Bisnis dan Manajemen. Edisi Pertama. Sulawesi Selatan : CV. Ruang Tentor, 2023.
- [3] Nengsih, Y.G., et al., Konsep Algoritma dan Pemrograman : Mengenal Konsep Dasar dan Praktis dalam Bahasa Pascal dan C. Edisi Pertama. Bandung : INDIE PRESS, 2022.
- [4] Putro, S.S. et al., Algoritma Pemrograman. Edisi Pertama. Malang : Media Nusa Creative (MNC Publishing), 2019.
- [5] Satrio, E. dan Pakpahan, S., Pemrograman C++ untuk Pembelajar Mandiri. Jakarta : Penerbit CAHAYA INFORMATIKA, 2019.
- [6] Siahaan, V. dan Sianipar, R.H., Buku Pintar Pemrograman C++. Sumatera Utara : Balige Publishing, 2020.
- [7] Siahaan, V. dan Sianipar, R.H., Pemrograman C++. Sumatera Utara : Sparta Publisher, 2019.
- [8] Siahaan, V. dan Sianipar, R.H., THREE COOKBOOKS IN ONE: Visual C++, Visual Basic, Visual C#. Sumatera Utara : Balige Publishing, 2020.
