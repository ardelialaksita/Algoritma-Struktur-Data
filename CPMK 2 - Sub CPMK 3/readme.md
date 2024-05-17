# <h1 align="center">Tugas CPMK 2 Sub CPMK 3 (Searching)</h1>
<p align="center">2311110051 - Ardelia Rachma Laksita</p>

## Table of Contents
1. [Soal 1](#soal-1)
2. [Soal 2](#soal-2)
3. [Soal 3](#soal-3)
4. [Referensi](#referensi)

## Soal 1
### 1. Terdapat dua algoritma searching yang umum digunakan yakni, Binary Search dan Linear Search. Berikan penjelasan alur dari masing-masing algoritma tersebut, dan jelaskan runtime dari best case dan worst case masing-masing algoritma! (35 Poin)

Searching merupakan proses pencarian suatu elemen tertentu. Pada dasarnya, algoritma searching pada C++ adalah algoritma untuk mencari elemen tertentu dalam sebuah array atau struktur data lainnya [1]. Algoritma pencarian (searching algorithm) adalah algoritma yang menerima sebuah argumen kunci dan dengan langkah-langkah tertentu akan mencari rekaman dengan kunci tersebut [3]. Setelah dilakukan proses pencarian, maka akan diperoleh salah satu dari dua kemungkinan yaitu data yang dicari ditemukan (successful) atau data yang dicari tidak ditemukan (unsuccessful) [3]. Algoritma searching ada 2 yaitu sequential atau linear search dan binary search. Algoritma searching digunakan untuk mencari suatu data, baik yang sudah disortir maupun belum, menggunakan query yang spesifik [2]. 

#### Penjelasan masing-masing algoritma searching
- **1. Binary Search** yaitu pencarian yang dilakukan dengan cara membagi data menjadi 2 yaitu data sisi kanan dan data sisi kiri. Sebelumnya, ditentukan indeks awal, tengah, dan akhir terlebih dahulu. Kemudian pencarian dilakukan dengan cara mengecek nilai tengah. Apabila elemen yang dicari lebih kecil daripada nilai tengah, maka pencarian akan dilakukan pada sisi kiri (indeks awal - tengah). Sebaliknya, apabila elemen yang dicari lebih besar daripada nilai tengah, maka pencarian akan dilakukan pada sisi kanan (indeks tengah - akhir). Hal tersebut akan membuat nilai tengah menyesuaikan posisi indeks yang terbaru. Iterasi dan inisialisasi akan terus berjalan hingga nilai tengah sama seperti data yang dicari. Pada binary search harus dilakukan sorting terlebih dahulu supaya datanya sudah dalam keadaan urut.
- **2. Linear Search** yaitu pencarian yang dilakukan dengan cara melakukan pengecekan terhadap seluruh elemen yang ada secara berurutan. Waktu yang dibutuhkan untuk sequential search lebih lama dibanding binary search karena pengecekan dilakukan secara satu persatu hingga elemen yang dicari ditemukan.

#### Runtime dari best case dan worst case masing-masing algoritma searching



## Soal 2
### 2. Buatlah fungsi dari salah satu algoritma searching pada soal nomor 1, dan berikan penjelasan pada program tersebut 
Kode Program

```C++
#include <iostream>
#include <string>
using namespace std;

// deklarasi kalimat, vokal, konsonan, dan huruf
string kalimat;
int vokal = 0;
int konsonan = 0;
char huruf;

// program melakukan pencarian menggunakan binary search
bool binarysearch()
{
    // searching
    int awal, akhir, tengah;
    awal = 0;
    akhir = kalimat.size() - 1;
    while (awal <= akhir)
    {
        tengah = (awal + akhir) / 2;
        // jika indeks tengah pada kalimat sama dengan huruf, maka akan mengembalikan nilai true
        if (kalimat[tengah] == huruf)
        {
            return true;
        }
        // jika indeks tengah pada kalimat lebih kecil dari huruf, maka akan menjalankan awal = tengah + 1
        else if (kalimat[tengah] < huruf)
        {
            awal = tengah + 1;
        }
        // jika indeks tengah pada kalimat tidak lebih kecil dari huruf, maka akan menjalankan akhir = tengah - 1
        else
        {
            akhir = tengah - 1;
        }
    }
    return false;
}

// melakukan pencarian dan penghitungan jumlah huruf vokal dan huruf konsonan
void search_vokalkonsonan()
{
    for (int i = 0; i < kalimat.length(); i++)
    {
        // pencarian dan penghitungan jumlah huruf vokal
        char huruf = tolower(kalimat[i]);
        if (huruf == 'a' || huruf == 'i' || huruf == 'u' || huruf == 'e' || huruf == 'o')
        {
            vokal++;
        }
        // pencarian dan penghitungan jumlah huruf konsonan
        else if (huruf == 'b' || huruf == 'c' || huruf == 'd' || huruf == 'f' || huruf == 'g' || huruf == 'h' || huruf == 'j' || huruf == 'k' || huruf == 'l' || huruf == 'm' || huruf == 'n' || huruf == 'p' || huruf == 'q' || huruf == 'r' || huruf == 's' || huruf == 't' || huruf == 'v' || huruf == 'w' || huruf == 'x' || huruf == 'y' || huruf == 'z')
        {
            konsonan++;
        }
    }
}

// main program
int main()
{
    // mencetak header pada program
    cout << "-------------------------------------------------------------------------------------" << endl;
    cout << "===== Program Mencari Sebuah Huruf pada Suatu Kalimat Menggunakan Binary Search =====" << endl;
    // user memasukkan kalimat tanpa menggunakan huruf kapital
    cout << "Masukkan kalimat (tanpa kapital): ";
    getline(cin, kalimat);

    // user memasukkan huruf yang ingin dicari
    cout << "Masukkan huruf yang ingin Anda cari : ";
    cin >> huruf;

    // melakukan pencarian menggunakan binary search
    bool ketemu = binarysearch();
    // memanggil fungsi untuk melakukan pencarian dan penghitungan jumlah huruf vokal dan konsonan
    search_vokalkonsonan();

    // tampilkan data setelah dilakukan pencarian
    // menampilkan output jika huruf yang dicari ditemukan pada kalimat yang diinput
    if (ketemu)
    {
        cout << "Huruf '" << huruf << "' ditemukan dalam kalimat." << endl;
        cout << "Jumlah huruf vokal dalam kalimat: " << vokal << endl;
        cout << "Jumlah huruf konsonan dalam kalimat: " << konsonan << endl;
    }
    // menampilkan output jika huruf yang dicari tidak ditemukan pada kalimat yang diinput
    else
    {
        cout << "Huruf '" << huruf << "' tidak ditemukan dalam kalimat." << endl;
        cout << "Jumlah huruf vokal dalam kalimat: " << vokal << endl;
        cout << "Jumlah huruf konsonan dalam kalimat: " << konsonan << endl;
    }
    
    // mencetak footer pada program
    cout << "-------------------------------------------------------------------------------------" << endl;
    cout << endl;
    return 0;
}

```
### Output:
![Modul 4  Unguided 1 Output](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/24e4f2ad-8465-4af8-b31c-740b4ce8cbf2)

Kode tersebut digunakan untuk mencari sebuah huruf pada sebuah kalimat yang sudah diinput dengan menggunakan Binary Search. Program tersebut juga akan menampilkan jumlah huruf vokal dan konsonan pada kalimat yang diinputkan oleh user. Pencarian menggunakan binary search dilakukan dengan mencari dan mendeklarasikan indeks awal, tengah, dan akhir. Kemudian, data array dibagi menjadi 2 dengan indeks tengah sebagai **midlle** atau patokan untuk melakukan pengecekan data. Kodenya yaitu `tengah = (awal + akhir) / 2;`. Apabila data atau huruf yang dicari lebih kecil dari indeks tengah, maka pencarian akan dilakukan pada data sebelum nilai tengah dengan menjalankan kode `awal = tengah + 1;`. Apabila data atau huruf yang dicari lebih besar dari indeks tengah, maka pencarian akan dilakukan pada data setelah nilai tengah dengan menjalankan kode `akhir = tengah - 1;`.

- `string kalimat;` merupakan deklarasi untuk tipe data kalimat yaitu string. `int vokal = 0;` merupakan deklarasi untuk huruf vokal dimana inisialisasinya dimulai dari indeks ke 0. `int konsonan = 0;` merupakan deklarasi untuk huruf konsonan dimana inisialisasinya dimulai dari indeks ke -. `char huruf;` merupakan deklarasi untuk tipe data dari huruf yang dicari yaitu berupa char (karakter) dimana user hanya dapat menginputkan 1 jenis huruf.
- `void search_vokalkonsonan()` merupakan fungsi untuk melakukan pencarian dan penghitungan jumlah huruf vokal dan konsonan pada suatu kalimat. Karena dalam suatu kalimat yang diinputkan bisa jadi terdapat huruf kapital, maka `tolower` perlu digunakan untuk mengkonversi semua huruf menjadi huruf kecil (tanpa kapital) supaya dapat dideteksi oleh program. `if (huruf == 'a' || huruf == 'i' || huruf == 'u' || huruf == 'e' || huruf == 'o')` merupakan contoh manfaat dari penggunaan tolower karena huruf yang dapat dideteksi oleh program hanyalah huruf kecil.
- Apabila ditemukan huruf vokal pada kalimat yang diinputkan oleh user, maka program akan menjalankan if dimana terdapat `vokal++;`. Artinya, iterasi akan terus berjalan hingga huruf vokal dalam kalimat tersebut sudah ditemukan semua.
- Apabila ditemukan huruf konsonan pada kalimat yang diinputkan oleh user, maka program akan menjalankan else dimana terdapat `konsonan++;`. Artinya, iterasi akan terus berjalan hingga huruf konsonan dalam kalimat tersebut sudah ditemukan semua.

#### Penjelasan main program:
- `cout << "Masukkan kalimat (tanpa kapital): ";` dan `getline(cin, kalimat);` merupakan kode dimana user dapat memasukkan kalimat untuk dilakukan pencarian suatu huruf.
- `cout << "Masukkan huruf yang ingin Anda cari : ";` dan `cin >> huruf;` merupakan kode dimana user diminta untuk memasukkan suatu huruf yang ingin dicari.
- `bool ketemu = binarysearch();` akan membuat program melakukan pencarian huruf menggunakan binary search pada kalimat yang telah diinput.
- `search_vokalkonsonan();` akan membuat program melakukan pencarian dan penhitungan jumlah huruf vokal dan konsonan pada kalimat yang telah diinput.
- Apabila huruf yang dicari ditemukan pada kalimat, maka program akan menampilkan hasil menggunakan `cout << "Huruf '" << huruf << "' ditemukan dalam kalimat." << endl;` dan menghasilkan output **Huruf '...' ditemukan dalam kalimat.**. Program juga akan mencetak banyaknya huruf vokal dan huruf konsonan pada kalimat tersebut.
- Apabila huruf yang dicari tidak ditemukan pada kalimat, maka program akan menampilkan hasil menggunakan `out << "Huruf '" << huruf << "' tidak ditemukan dalam kalimat." << endl;` dan menghasilkan output **Huruf '...' tidak ditemukan dalam kalimat.**.. Program juga tetap akan mencetak banyaknya huruf vokal dan huruf konsonan pada kalimat tersebut.

Pertama-tama, user akan diminta untuk memasukkan kalimat dengan huruf kecil pada semua karakternya. Selanjutnya, user diminta untuk memasukkan huruf yang ingin dicari. Huruf yang dicari bebas sesuai keinginan user, boleh terdapat pada kalimat, boleh juga yang tidak ada pada kalimat. Selanjutnya, program akan menjalankan pencarian menggunakan binary search untuk memproses apakah huruf yang dicari oleh user ditemukan pada kalimat atau tidak. 

#### Penjelasan input oleh user:
- **Masukkan kalimat (tanpa kapital): arra is a cat miaw** artinya user memasukkan kalimat "arra is a cat miaw".
- **Masukkan huruf yang ingin Anda cari : a** artinya user ingin mencari huruf a pada kalimat tersebut.
- **Huruf 'a' ditemukan dalam kalimat.** artinya huruf 'a' ada pada kalimat "arra is a cat miaw".
- **Jumlah huruf vokal dalam kalimat: 7** artinya terdapat 7 huruf vokal pada kalimat tersebut yaitu a, a, i, a, a, i, a.
- **Jumlah huruf konsonan dalam kalimat: 7** artinya terdapat 7 huruf konsonan pada kalimat tersebut yaitu r, r, s, c, t, m, w.

### Full code of screenshot:
![Modul 4  Unguided 1 Full SS (1)](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/4e80df6d-fdc9-4f53-941c-00897442f5a4)


## Soal 3
### 3. Tulislah sebuah fungsi program dengan kondisi sebagai berikut: Terdapat sebuah sorted array of strings yang mana terdapat string kosong diantaranya, carilah lokasi/indeks dari kata yang dicari! (30 Poin)
Input: bola, {“Adi”,””,””, “”, “bermain”, “”, “bola”, “”, “”, “sedang”}

Output: 6

**Kode Program**
```C++
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// fungsi binary search untuk menemukan kayta
void binarysearch(const vector<string>& dataArray, const string& word) {
    int left = 0;
    int right = static_cast<int>(dataArray.size()) - 1;

    // apabila data di sisi kiri lebih kecil atau sama dengan data kanan
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // jika elemen tengah adalah string kosong, cari elemen non-kosong di sekitarnya
        if (dataArray[mid].empty()) {
            int l = mid - 1;
            int r = mid + 1;

            while (true) {
                if (l < left && r > right) {
                    cout << "\nData tidak ditemukan\n";
                    return; 
                } else if (r <= right && !dataArray[r].empty()) {
                    mid = r;
                    break;
                } else if (l >= left && !dataArray[l].empty()) {
                    mid = l;
                    break;
                }
                r++;
                l--;
            }
        }

        // perbandingan menggunakan binary search 
        // jika array di tengah (setelah diurutkan) memiliki isi yang sama seperti kata yang dicari
        if (dataArray[mid] == word) {
            // mencetak data ditemukan pada index ke berapa
            cout << "\nData ditemukan pada index ke- " << mid << endl;
            return;
        } 
        // jika array di tengah (setelah diurutkan) lebih kecil daripda kata yang dicari
        else if (dataArray[mid] < word) {
            // pencarian dilakukan pada sisi bagian kiri dengan operasi mid array + 1
            left = mid + 1;
        } 
        // pencarian dilakukan pada sisi bagian kanan dengan operasi mid array - 1
        else {
            right = mid - 1;
        }
    }

    // tampilkan data tidak ditemukan jika data tidak ada di dalam array
    cout << "\nData tidak ditemukan\n";
}

// fungsi void untuk menampilkan data array 
void cetakdata(const vector<string>& data) {
    cout << "Data: {";
    for (size_t i = 0; i < data.size(); ++i) {
        cout << "\"" << data[i] << "\"";
        if (i != data.size() - 1) {
            cout << ", ";
        }
    }
    cout << "}" << endl;
}

// main program (program utama)
int main() {
    // deklarasi word
    string word;
    
    // cetak header pada program
    cout << "-------------------------------------------------------------------------------------" << endl;
    cout << "================ Program Mencari Kata Menggunakan Binary Search =====================" << endl;
    
    // data yang mengandung string kosong
    vector<string> dataArray = {"Adi", "", "", "", "bermain", "", "bola", "", "", "sedang"};

    // panggil fungsi cetakData
    cetakdata(dataArray);
    
    // input kata yang ingin dicari
    cout << "Kata apa yang ingin Anda cari pada data tersebut? : ";
    cin >> word;

    // panggil fungsi untuk lakukan pencarian dengan binary search
    binarysearch(dataArray, word);

    // cetak footer pada program
    cout << "-------------------------------------------------------------------------------------" << endl;

    return 0;
}

```
Kode tersebut digunakan untuk mencari kata atau data pada sebuah array dengan menggunakan Binary Search. Penjelasan kodenya yaitu sebagai berikut.
- Fungsi `void binarysearch()` digunakan untuk melakukan pencarian menggunakan binary search. Progrma akan dijalankan saat fungsi dipanggil pada main program.
- Fungsi `void cetakdata()` digunakan untuk menampilkan seluruh data di dalam array. User akan mencari suatu kata atau data di dalam array tersebut. 
- `if (dataArray[mid] == word)` artinya apabila data tengah array sama seperti kata yang dicari, maka program akan menjalankan `cout << "\nData ditemukan pada index ke- " << mid << endl;` dan akan mencetak lokasi atau index data tersebut. Pencarian berhenti karena data telah ditemukan. 
- `dataArray[mid] < word` artinya apabila data tengah array lebih kecil dari kata yang dicari, maka akan menjalankan pencarian di sisi bagian kiri dengan mid (data tengah array) dikurangi dengan 1. Sebaliknya, apabila data tengah array lebih besar dari kata yang dicari,siaka akan menjalankan pencarian selanjutnya di sisi bagian kanan dengan mid (data tengah array) ditambah dengan 1. 
- `dataArray = {"Adi", "", "", "", "bermain", "", "bola", "", "", "sedang"};` merupakan data di dalam array yang akan user cari salah satu datanya. 
- `cetakdata(dataArray);` akan memanggil fungsi untuk menjalankan fungsi void cetakdata.
- `binarysearch(dataArray, word);` akan memanggil fungsi untuk menjalankan pencarian dengan algoritma binary search.

### Output:
![Cuplikan layar 2024-05-17 082754](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/52ee2b97-1f03-4e7c-93f8-bf1d6328e3e1)

#### Penjelasan input oleh user:
Pada **"Kata apa yang ingin Anda cari pada data tersebut? : "**, user memasukkan kata bola untuk dilakukan pencarian pada array tersebut. Jika bola ada di dalam array, maka akan mencetak index atau lokasi data "bola" tersebut. Namun, apabila tidak ada bola di array tersebut, maka akan mencetak "Data tidak ditemukan". Ternyata bola terdapat pada array tersebut yaitu pada index ke- 6 seperti yang telah ditampilkan pada output di atas. 

### Full code of screenshot:
![Cuplikan layar 2024-05-17 082716](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/022759a8-4f2c-4885-a090-d32820ba0d8a)


## Referensi
- [1] Guntara, R.G., Algoritma dan Pemrograman Dasar : Menggunakan Bahasa Pemrograman C++ dengan Contoh Kasus Aplikasi untuk Bisnis dan Manajemen. Edisi Pertama. Sulawesi Selatan : CV. Ruang Tentor, 2023.
- [2] Pasaribu, S.A., Algoritma dan Pemrograman dalam Bahasa Pascal dan C++. Edisi Pertama. Yogyakarta : Deepublish, 2023.
- [3] Putro, S.S. et al., Algoritma Pemrograman. Edisi Pertama. Malang : Media Nusa Creative (MNC Publishing), 2019.

