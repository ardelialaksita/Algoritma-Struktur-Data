# <h1 align="center">Rekursif</h1>
<p align="center">2311110051 - Ardelia Rachma Laksita</p>

## Table of Contents
1. [Penjelasan](#penjelasan)
2. [Contoh Program](#contoh-program)
3. [Penjelasan Alur Program](#penjelasan-alur-program)
4. [Referensi](#referensi)

# Penjelasan
Rekursif adalah suatu proses dari sebuah fungsi yang dapat memanggil dirinya sendiri secara berulang-ulang [1]. Beberapa kasus yang menggunakan fungsi rekursif akan jauh lebih mudah, cepat, dan efisien. Hanya membutuhkan _space_ memori yang cukup banyak karena iterasinya yang harus dipanggil secara terus menerus. Fungsi rekursif akan terus menjalankan iterasi hingga suatu kondisi yang ditetapkan pada fungsi tersebut terpenuhi. 

### Tujuan Rekursif:
Tujuan rekursif adalah untuk melakukan pengulangan, atau looping seperti for dan while, namun dengan cara yang berbeda [3].

### Kelebihan dan Kekurangan Rekursif:
**Kelebihan:** Mempermudah penyelesaian suatu kasus sehingga menjadi lebih cepat, efektif, dan efisien.
**Kekurangan:** Membutuhkan _space_ memori yang cukup banyak karena melakukan iterasi secara berulang-ulang hingga suatu kondisi pada fungsi tersebut terpenuhi.

### Implementasi Rekursif:
- **Faktorial** 

Yaitu digunakan untuk mencari bilangan faktorial dari suatu bilangan bulat positif. Bilangan faktorial dilakukan dengan cara mengalikan n bilangan dengan (n-1) hingga n-1 = 1. 0 tidak ikut dikalikan dengan bilangan yang dicari faktorialnya (n).

- **Luas Lingkaran**

Yaitu digunakan untuk menghtiung luas lingkaran dengan r sebagai jari-jarinya.

- **Menghitung bintang pada suatu input** 

Yaitu digunakan untuk menghitung bintang beserta langkah-langkahnya pada suatu input. Berikut contoh penerapannya:

![implementasi bintang](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/76b6f270-7948-4a11-8ef6-7ec1c633bdbe)

**_Source : Sitasi 2_**

**Permutasi String** 

Yaitu digunakan untuk membantuk mempersingkat waktu pencarian permutasi. Permutasi yang tidak dilakukan dengan fungsi rekursi akan membutuhkan waktu yang banyak dan cukup melelahkan. Berikut pohon rekursi permutasi string [2].

![implementasi permutasi](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/020a851b-17c4-4c03-9925-b197ebb22586)

**_Source : Sitasi 2_**


# Contoh Program
```C++
// import library
#include<iostream>
using namespace std;

// PROGRAM REKURSIF TIDAK LANGSUNG MENCARI FAKTORIAL BILANGAN BULAT POSITIF

// fungsi faktorialB yang masih kosong
int faktorialB(int n);

// fungsi faktorialA dengan n sebagai bilangan yang dicari faktorialnya
int faktorialA(int n) {
    // jika n lebih dari 1
    if(n > 1)
        // lakukan return dengan memanggil fungsi faktorialB
        return n * faktorialB(n - 1);
    // jika n tidak lebih dari 1
    else
        // lakukan return 1
        return 1;
}

// fungsi faktorialB dengan n sebagai bilangan yang dicari faktorialnya
int faktorialB(int n) {
    // jika n lebih dari 1
    if(n > 1)
        // lakukan return dengan memanggil fungsi faktorialA
        return n * faktorialA(n - 1);
    // jika n tidak lebih dari 1
    else
        // lakukan return 1
        return 1;
}

// main program (program utama)
int main() {
    // deklarasi n
    int n;

    // user input bilangan bulat positif
    cout << "Masukkan bilangan bulat positif: ";
    cin >> n;

    // tampilkan output jika user input n kurang dari 0
    if (n < 0) {
        cout << "Input tidak valid. Harap masukkan bilangan bulat positif." << endl;
    } 
    // tampilkan output jika user input n lebih dari 0
    else {
        cout << "Faktorial dari " << n << " adalah: " << faktorialB(n) << endl;
    }
    // return code
    return 0;
}

```

# Penjelasan Alur Program
Kode tersebut digunakan untuk mencari faktorial dari suatu bilangan bulat. Program tersebut menggunakan rekursif tidak langsung dimana tidak cukup apabila hanya menggunakan 1 fungsi. Bilangan bulat yang dicari disimbolkan dengan n. `int faktorial(int n)` merupakan fungsi yang akan dipanggil untuk menjalankan proses faktorial. Apabila n > 1, maka program akan terus melakukan iterasi perkalian dari bilangan faktorial hingga mencapai n - 1 = 1.

`int faktorialB(int n);` tidak memiliki isi atau dapat dikatakan bahwa hanya digunakan untuk mendeklarasikan. Fungsi tersebut akan dipanggil pada fungsi `faktorialA()` yang berisi program untuk mencari faktorialnya. Iterasi akan terus dilakukan hingga kondisi fungsinya terpenuhi. Karena n-nya adalah 5, maka iterasi n-1 yang berjalan akan berhenti saat n - 1 = 1. 

Apabila n lebih besar dari 1, maka akan menjalankan `return n * faktorialA(n - 1);`. Sedangkan apabila n tidak lebih besar dari 1, maka program akan menjalankan return 0. 

`faktorialB()` merupakan fungsi yang digunakan untuk membantu `faktorialA()` yang berisi program untuk menghitung faktorial. Oleh karena itu, faktorialB dipaggil di dalam fungsi faktorialA. Selanjutnya, baru kita isi fungsi faktorialB yang memanggil fungsi faktorialA. 

#### Penjelasan Main Program:
- `int n;` merupakan deklarasi yang digunakan untuk merepresentasikan bilangan bulat yang ingin dicari faktorialnya.
- `cout << "Masukkan bilangan bulat positif: ";` dan `cin >> n;` akan meminta user untuk memasukkan bilangan yang ingin dicari faktorialnya.
- `if (n < 0)` yang berisi `cout << "Input tidak valid. Harap masukkan bilangan bulat positif." << endl;` artinya apabila n kurang dari 0, maka program akan mencetak "Input tidak valid. Harap masukkan bilangan bulat positif" karena program hanya akan menjalankn apabila n-nya lebih besar dari 0.
- `cout << "Faktorial dari " << n << " adalah: " << faktorialB(n) << endl;` digunakan untuk menampilkan faktorial dari bilangan yang diinput.
- Apabila n lebih besar dari 0, maka program akan menjalankan `cout << "Faktorial dari " << n << " adalah: " << faktorial(n) << endl;` dan menampilkan **"Faktorial dari ... (bilangan n) adalah: .... (faktorial bilangan tersebut)"**.
- `return 0;` merupakan kode yang menandakan bahwa program telah selesai dan berhasil. 

#### Output:
![output unguided 2](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/9b6b5dad-e38e-4e5c-b179-ee0badc0a619)

**Penjelasan Output:**
Sama seperti yang telah dijelaskan pada output unguided 1. Pada output tersebut, user memasukkan bilangan 5 untuk dicari faktorialnya. Kemudian, program menjalankan iterasi fungsi rekursif dengan cara n = 5 dikali dengan n-1 dikali dengan n-2 dikali dengan n - 3 dikali dengan n - 4 hingga 1. Karena n-4 = 1, maka iterasi dihentikan dan ditemukan faktorial dari 5 adalah 120. 

#### Full code Screenshot:
![full ss unguided 2](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/4699ed0d-8390-4665-9520-42f3509ca4d5)


# Referensi
- [1] A. A. Youztima, “Fungsi Rekursif Dengan C++,” Medium, Jan. 02, 2023. Available: https://medium.com/@anggaalhusaini/fungsi-rekursif-dengan-c-433c9250c73d. [Accessed: June 15, 2024]
- [2] M. F. Rizky, “Programming: Mengapa Pendekatan Rekursif Penting,” Medium, Mar. 11, 2024. Available: https://medium.com/@fathurwithyou/programming-mengapa-pendekatan-rekursif-penting-f348649b1bd4. [Accessed: June 17, 2024]
- [3] W. Hartanto, “Implementasi Algoritma Rekursif dengan Bahasa Pemrograman Python,” BINUS UNIVERSITY BANDUNG - Kampus Teknologi Kreatif, Dec. 04, 2019. Available: https://binus.ac.id/bandung/2019/12/implementasi-algoritma-rekursif-dengan-bahasa-pemrograman-python/. [Accessed: June 17, 2024]
