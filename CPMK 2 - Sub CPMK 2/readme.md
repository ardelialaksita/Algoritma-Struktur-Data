# <h1 align="center">Tugas CPMK 2 Sub CPMK 2 (Sorting)</h1>
<p align="center">2311110051 - Ardelia Rachma Laksita</p>

## Table of Contents
1. [Soal 1](#soal-1)
2. [Soal 2](#soal-2)
3. [Soal 3](#soal-3)
4. [Soal 4](#soal-4)

## Soal 1
### 1. Terdapat tiga algoritma sorting yang umum digunakan yakni, Bubble Sort, Selection Sort, dan Merge Sort. Berikan penjelasan alur dari masing-masing algoritma tersebut, dan jelaskan runtime dari best case dan worst case masing-masing algoritma! (35 Poin)

### Bubble Sort
Bubble sort yaitu algoritma yang melakukan perulangan untuk proses pembandingan antara tiap-tiap elemen array dan menukarnya apabila urutannya masih belum sesuai. Bubble sort merupakan salah satu algoritma pengurutan data dengan menerapkan konsep ascending atau descending secara sederhana[1]. Skema prosesnya dengan cara membandingkan elemen yang berdekatan, kemudian menukarnya apabila hasil urutannya tidak sesuai. Bubble sort merupakan gabungan dari selection sort dan insertion sort.

**Alur dari algoritma Bubble Sort:**
1. Inisialisasi array
2. Melakukan perbandingan elemen sebelumnya (misalnya: A) dengan elemen setelahnya (misalnya: B)
3. Pada ascending: Apabila elemen A lebih besar dibanding elemen B, maka tukar posisi elemen A dengan elemen B. Pada descending: Apabila elemen A lebih kecil dibanding elemen B, maka tukar posisi elemen A dengan elemen B. Ascending adalah proses sorting secara menaik sehingga elemen sebelumnya harus lebih kecil. Descending adalah proses sorting secara menurun sehingga elemen sebelumnya harus lebih besar.
4. Apabila tidak lebih besar (ascending) ataupun lebih kecil (descending) daripada elemen setelahnya, maka lakukan iterasi berikutnya.
5. Lakukan langkah 1 sampai dengan 4 hingga seluruh elemen urut. Apabila ascending, maka elemen yang paling besar akan berada pada array paling akhir. Apabila descending, maka elemen yang paling besar akan berada pada array paling awal.

**Best Case dan Worst Case Runtime Algoritma Bubble Sorting:**
- **Best Case**: O(n), yaitu terjadi saat datanya telah diurutkan, tidak perlu ada pertukaran yang dilakukan.
- **Worst Case**: O(n^2), yaitu terjadi saat datanya diurutkan secara descending saat penyusunan harus dilakukan secara ascending, begitu pula sebaliknya. Elemen harus dibandingkan dan ditukar pada setiap langkah. 

### Insertion Sort
Insertion Sort merupakan algoritma pengurutan sederhana yang mempunyai proses hampir sama seperti cara mengurutkan kartu remi[32]. Proses sorting algoritma ini yaitu dengan cara memecah elemen menjadi dua bagian yaitu diurutkan dan tidak diurutkan. Insertion Sort efisien untuk nilai data kecil[2]. Pada Insertion Sort, semua elemen akan terkena scan terlebih dahulu sehingga penukaran posisi dilakukan hanya jika terdapat suatu elemen yang posisinya tidak tepat. 

**Alur dari algoritma Insertion Sort:**
1. Inisialisasi array.
2. Simpan elemen pertama sebagai elemen yang akan dibandingkan dengan elemen berikutnya. 
3. Lakukan iterasi untuk setiap elemen selanjutnya. Bandingkan elemen saat ini dengan elemen yang telah disimpan pada langkah 2. Geser elemen yang disimpan ke kanan apabila lebih besar (ascending) atau geser ke kanan apabila lebih kecil (descending). Sisipkan elemen saat ini pada posisi yang sesuai dengan urutan. Pergeseran elemen boleh terus dilakukan hingga elemen tersebut menempati posisi yang sesuai, baik secara asceding maupun descending.
4. Lakukan langkah 1 sampai dengan 3 hingga semua elemen telah urut.

**Best Case dan Worst Case Runtime Algoritma Insertion Sorting:**
- **Best Case**: O(n), yaitu terjadi saat datanya telah diurutkan, tidak perlu ada pertukaran yang dilakukan. Insertion sort hanya perlu melakukan satu iterasi dan tidak ada perbandingan atau pertukaran yang perlu dilakukan.
- **Worst Case**: O(n^2), yaitu terjadi saat datanya diurutkan secara descending saat penyusunan harus dilakukan secara ascending, begitu pula sebaliknya. 

### Merge Sort
Merge Sort adalah algoritma yang pengurutannya dilakukan dengan _divide_ dan _conquer_ dimana array dibagi menjadi 2 sub-array, kemudian diurutkan secara rekursif. Setelah itu, sub-array yang telah diurutkan kemudian digabungkan kembali menjadi 1 array yang telah sesuai urutannya.

**Alur dari algoritma Merge Sort:**
1. Divide: yaitu memilah-milah elemen dari suatu array yang kemudian dibagi menjadi 2 sub-array.
2. Conquer: yaitu melakukan perbandingan dan pengurutan elemen pada masing-masing sub-array secara rekursif.
3. Combination: yaitu mengkombinasikan dua sub-array yang telah diurutkan menjadi satu array dengan menyesuaikan urutannya. Dengan begitu, didapatkan array yang telah urut.

**Best Case dan Worst Case Runtime Algoritma Merge Sorting:**
- **Best Case**: O(n log n), yaitu terjadi saat seluruh data telah urut. Merge sort hanya perlu melakukan satu iterasi untuk menggabungkan sub-array yang sudah diurutkan.
- **Worst Case**: O(n log n), yaitu terjadi ketika datanya diurutkan secara descending saat penyusunan harus dilakukan secara ascending, begitu pula sebaliknya. Merge Sort perlu melakukan iterasi sebanyak n untuk membagi dan menggabungkan sub-array.

## Soal 2
### 2. Buatlah fungsi dari salah satu algoritma sorting pada soal nomor 1, dan berikan penjelasan pada program tersebut (35 Poin)
Kode Program
```C++
#include <iostream>
using namespace std;

// PROGRAM ASCENDING DAN DESCENDING SORT

// sorting menggunakan insertion sort secara ascending (menaik)
void insertion_sort_ascending(char arr[], int length) {

    //deklarasi a, b, dan tmp
    int a, b;
    char tmp;

    // perulangan for dan while untuk inisialisasi pada proses insertion sort secara ascending
    for (a = 1; a < length; a++) {
        b = a;

        while (b > 0 && arr[b - 1] > arr[b]) {
            tmp = arr[b];
            arr[b] = arr[b - 1];
            arr[b - 1] = tmp;
            b--;
        } // end of while loop
    } // end of for loop
} // end of void function

// sorting menggunakan insertion sort secara descending (menurun)
void insertion_sort_descending(char arr[], int length) {

    //deklarasi a, b, dan tmp
    int a, b;
    char tmp;

    // perulangan for dan while untuk inisialisasi pada proses insertion sort secara descending
    for (a = 1; a < length; a++) {
        b = a;

        while (b > 0 && arr[b - 1] < arr[b]) {
            tmp = arr[b];
            arr[b] = arr[b - 1];
            arr[b - 1] = tmp;
            b--;
        } // end of while loop
    } // end of for loop
} // end of void function

// cetak dan tampilkan array
void print_array(char arr[], int length) {
    
    for(int a=0; a < length; a++) {
        cout << arr[a] << "\t";
    }
    cout << endl;
}

// main program
int main() {

    // deklarasi length untuk menyimpan panjang array
    int length;
    
    // user memasukkan panjang array
    cout << "Input (n) = ";
    cin >> length;

    // deklarasi array bertipe karakter dengan length yang ditentukan oleh user
    char arr[length];

    // user memasukkan beberapa karakter sesuai dengan panjang yang telah diinput
    cout << "Masukkan " << length << " karakter: " << endl;
    
    // for loop untuk menampilkan karakter ke-berapa yang akan diisi oleh user
    for (int a = 0; a < length; a++) {
        cout << "Karakter ke-" << a + 1 << ": ";
        cin >> arr[a];
    }
    cout << endl;
    
    // tampilkan karakter sebelum sorting
    cout << "Urutan karakter sebelum sorting: " << endl;
    print_array(arr, length);

    // panggil fungsi untuk mengurutkan karakter secara ascending
    insertion_sort_ascending(arr, length);

    // tampilkan karakter setelah diurutkan secara ascending
    cout << "\nUrutan karakter setelah ascending sort: " << endl;
    print_array(arr, length);

    // panggil fungsi untuk mengurutkan karakter secara descending
    insertion_sort_descending(arr, length);
    
    // tampilkan karakter setelah diurutkan secara descending
    cout << "\nUrutan karakter setelah descending sort: " << endl;
    print_array(arr, length);

    return 0;
}

```
Kode tersebut digunakan untuk melakukan sorting secara menaik (ascending) dan menurun (descending) dengan bilangan dan karakter yang diinputkan oleh user. Algoritma sorting yang digunakan adalah insertion sort. Pertama-tama, buatlah fungsi menggunakan void untuk proses insertion sort secara ascending dan descending terlebih dahulu. Fungsi tersebut akan dipanggil pada _main program_. Selanjutnya, buatlah kode untuk mencetak dan menampilkan isi array. Terakhir, buatlah main program untuk menjalankan proses sorting dan mencetak data yang belum diurutkan dan sudah diurutkan. 

- `int i, j;` dan `char tmp;` digunakan untuk mendeklarasikan i, j, dan tmp. 
- `while (j > 0 && arr[j - 1] < arr[j])` dan `while (j > 0 && arr[j - 1] > arr[j])` merupakan perbandingan untuk menentukan apakah pertukaran posisi diperlukan atau tidak. Selain itu, kode tersebut juga akan melanjutkan iterasi dan proses sorting jika tidak ada pertukaran posisi lagi yang dilakukan.
1. `j > 0 && arr[j - 1] > arr[j]` untuk sorting yang dilakukan secara ascending (menaik).
2. `j > 0 && arr[j - 1] < arr[j]` untuk sorting yang dilakukan secara descending (menurun).
- **While Loop** digunakan untuk melakukan iterasi selama proses sorting.
- **For Loop** digunakan untuk membandingkan antar elemen dan menukar posisi apabila diperlukan.

Selanjutnya, terdapat program untuk mencetak dan menampilkan isi array menggunakan fungsi void pada `void print_array(char a[], int length)` dimana `char` merupakan tipe data yaitu karakter, sedangkan `a` sebagai nama variabel array tersebut.

**Penjelasan main program :**
- `int length;` merupakan deklarasi panjang array. Panjang array tidak langsung disebutkan (hanya dideklarasikan) karena nantinya akan diinputkan oleh user. 
- `cout << "input (n) = ";` dan `cin >> length;` akan meminta user untuk memasukkan (input) panjang array. 
- `char a[length];` merupakan deklarasi tipe data yang akan diinputkan oleh user sesuai dengan length (panjang) yang telah diinputkan sebelumnya. 
- `cout << "Masukkan " << length << " karakter: " << endl;` akan menampilkan jumlah karakter yang akan diinputkan oleh user. Selanjutnya, program akan meminta user untuk memasukkan karakter sesuai posisi array menggunakan perulangan for `for (int i = 0; i < length; i++)`, `cout << "Karakter ke-" << i + 1 << ": ";` dan `cin >> a[i];`.
- `cout << "Urutan karakter sebelum sorting: " << endl;` dan `print_array(a, length);` akan menampilkan urutan karakter sebelum diurutkan.
- `insertion_sort_ascending(a, length);` akan memanggil fungsi untuk melakukan proses insertion sort secara ascending.
- `cout << "Urutan karakter setelah ascending sort: " << endl;` dan `print_array(a, length);` akan menampilkan urutan karakter setelah diurutkan secara ascending (menaik).
- `insertion_sort_descending(a, length);` akan memanggil fungsi untuk melakukan proses insertion sort secara descending.
- `cout << "Urutan karakter setelah descending sort: " << endl;` dan `print_array(a, length);` akan menampilkan urutan karakter setelah diurutkan secara descending (menurun).

### Analisis kompleksitas waktu dan ruang :
Pada program tersebut, insertion sort memiliki perulangan while di dalam perulangan for sehingga terdapat 2 perulangan pada masing-masing algoritma insertion sort ascending dan algoritma insertion sort descending. 

- **Insertion Sort Ascending** : setiap elemen array harus ditempatkan pada posisi dari terkecil ke terbesar (naik). Worse casenya adalah saat setiap elemen harus dipindahkan ke posisi awal sehingga setiap operasi dalam perulangan for akan memerlukan i operasi. Oleh karena itu, kompleksitas waktunya adalah `O(n²)`dan kompleksitas ruangnya adalah `O(1)`.
- **Insertion Sort Descending** : setiap elemen array harus ditempatkan pada posisi dari terbesar ke terkecil (turun). Worse casenya adalah saat setiap elemen harus dipindahkan ke posisi awal sehingga setiap operasi dalam perulangan for akan memerlukan i operasi. Oleh karena itu, kompleksitas waktunya adalah `O(n²)`dan kompleksitas ruangnya adalah `O(1)`. Ini serupa dengan konsep insertion sortascending.

Jika hanya terdapat 1 perulangan, maka kompleksitas waktunya adalah **O(n)**. Namun, jika terdapat perulangan di dalam perulangan, maka kompleksitas waktunya adalah **O(n²)**. Operasi dasar pada algoritma tersebut dilakukan secara konstan sehingga kompleksitas waktu algoritma insertion sort tersebut adalah `O(n²)`. Sedangkan kompleksitas ruangnya adalah `O(1)`. Kompleksitas waktunya bergantung secara kuadratik. Sedangkan kompleksitas ruangnya tidak bergantung pada ukuran array yang diurutkan. Total operasinya sebagai berikut.

`(n-1) + (n-2) + ... + n + 2 + 1`

Jadi, kedua algoritma insertion sort tersebut memiliki kompleksitas waktu `O(n²)`dan kompleksitas ruang adalah `O(1)`. 

Saat program dijalankan, maka user akan diminta untuk memasukkan panjang array. Selanjutnya, user akan diminta untuk memasukkan value array sesuai pada lokasinya masing-masing. User akan mengetahui lokasi value yang mereka inputkan terletak pada karakter ke berapa.

**Penjelasan Input dan Output sesuai data yang telah diinputkan oleh user :**
- `input (n) = 5` artinya user memasukkan 5 sebagai panjang array.
- `Masukkan 5 karakter` artinya user diminta memasukkan sebanyak 5 karakter sesuai panjang yang telah diinputkan sebelumnya.
- `Karakter ke-1: a` artinya a merupakan karakter pertama yang diinputkan oleh user.
- `Karakter ke-2: e` artinya e merupakan karakter kedua yang diinputkan oleh user.
- `Karakter ke-3: d` artinya d merupakan karakter ketiga yang diinputkan oleh user.
- `Karakter ke-4: b` artinya b merupakan karakter keempat yang diinputkan oleh user.
- `Karakter ke-5: c` artinya c merupakan karakter kelima yang diinputkan oleh user.

### Output:
![program 1 output](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/1e46da71-6a36-4886-a1c3-7a8c206c4c4d)

### Full code of screenshot:
![program 1 full ss](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/f776b3c4-7b41-43d3-9dd9-44ca65b057b3)


## Soal 3
### 3. Tulislah sebuah fungsi untuk mensorting dan mengecek dua buah array of strings, sehingga menghasilkan “anagram” dan “tidak anagram” (30 poin)

![Cuplikan layar 2024-05-22 043136](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/bf5a0e12-dfbd-4e3d-b3e7-0ca2ba9ce052)

Kode Program
```C++
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// PROGRAM SORTING DAN CEK ANAGRAM DARI DUA BUAH ARRAY OF STRINGS

// fungsi mengecek anagram
vector<string> cekAnagram(const vector<string>& array1, const vector<string>& array2) {
    // memastikan panjang kedua array sama
    if (array1.size() != array2.size()) {
        vector<string> result(array1.size(), "tidak anagram");
        return result;
    }

    vector<string> result(array1.size());
    // for looping untuk ubah semua string menjadi huruf kecil serta mengurutkan karakternya
    for (size_t i = 0; i < array1.size(); i++) {
        // deklarasi string 1 dan string 2
        string string1 = array1[i];
        string string2 = array2[i];
        
        // konversi string ke huruf kecil
        transform(string1.begin(), string1.end(), string1.begin(), ::tolower);
        transform(string2.begin(), string2.end(), string2.begin(), ::tolower);
        
        // urutkan string
        sort(string1.begin(), string1.end());
        sort(string2.begin(), string2.end());

        // bandingkan apakah kedua string merupakan anagram atau tidak
        // jika string 1 sama dengan string 2, maka anagram
        if (string1 == string2) {
            result[i] = "anagram";
        } 
        // jika string 1 tidak sama dengan string 2, maka tidak anagram
        else {
            result[i] = "tidak anagram";
        }
    }
    return result;
}

// main program (program utama)
int main() {
    // isi string 1 
    vector<string> string1 = {"bahu", "makan"};
    // isi string 2
    vector<string> string2 = {"buah", "minum"};
    
    // panggil fungsi pengecekan anagram
    vector<string> result = cekAnagram(string1, string2);
    
    // for looping untuk mencetak hasil
    for (size_t i = 0; i < string1.size(); ++i) {
        cout << "String 1: " << string1[i] << endl;
        cout << "String 2: " << string2[i] << endl;
        cout << "Result  : " << result[i] << endl;
        cout << endl;
    }
    return 0;
}

```
Kode tersebut digunakan untuk melakukan pengecekan apakah suatu kata merupakan anagram atau tidak anagram. Dua kata yang anagram adalah apabila huruf-huruf di dalam kedua kata tersebut memiliki jumlah dan isi yang sama, walaupun urutannya berbeda. Sedangkan kata yang tidak anagram adalah apabila huruf-huruf di dalam kata-kata tersebut tidak memiliki kandungan huruf yang sama, walaupun jumlahnya sama dan walaupun posisinya ditukar-tukar. 

### Output:
![program 2 output](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/8142a081-a222-44e4-97ab-7afc84e69ede)

Pada output tersebut, user menambahkan kata 'bahu' dan 'buah' serta 'makan' dan 'minum' untuk dilakukan pengecekan manakah kata yang anagram dan tidak anagram. Kata pada indeks 0 string 1 (bahu) akan dibandingkan dengan indeks 0 string 2 (buah). Sedangkan kata pada indeks 1 string 1 akan dibandingkan dengan indeks 1 string 2. 

Selanjutnya, didapatkan hasil bahwa 'bahu' dan 'buah' merupakan anagram karena memiliki jumlah huruf dan huruf yang sama yaitu a, b, h, dan u walaupun posisinya ditukar-tukar. Sedangkan pada 'makan' dan 'minum' didapatkan hasil tidak anagram karena meskipun memiliki jumlah huruf yang sama, kedua kata tersebut tidak memiliki huruf yang sama walaupun posisinya ditukar-tukar. Oleh karena itu, kedua kata tersebut tidak anagram.

### Full code of screenshot:
![program 2 full ss](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/b048a3b8-127e-4896-991e-9b226edeb805)


## Soal 4
### 4. Tulislah sebuah fungsi program dengan asumsi sebagai berikut: Terdapat dua buah sorted array A dan B yang memiliki tipe data sama, dimana array A memiliki indeks yang cukup untuk menampung array B. Gabungkan array B kedalam array A, kemudian urutkan array tersebut! (30 Poin)
Kode Program
```C++
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// PROGRAM MENGGABUNGKAN ARRAY A KE ARRAY B DAN MENGURUTKANNYA

void mergeSortedArrays(vector<int>& arrA, vector<int>& arrB) {
    // gabung array B ke array A 
    arrA.insert(arrA.end(), arrB.begin(), arrB.end());

    // urutkan array A setelah array B ditambahkan ke array A
    sort(arrA.begin(), arrA.end()); 

    // tampilkan hasil urutan ascending
    cout << "Result of Merge and Sort Array (ascending): ";
    for (const auto& i : arrA) {
        cout << i << " ";
    }
    cout << endl;

    // urutkan array A secara descending
    sort(arrA.rbegin(), arrA.rend()); 

    // tampilkan hasil urutan descending
    cout << "Result of Merge and Sort Array (descending): ";
    for (const auto& i : arrA) {
        cout << i << " ";
    }
    cout << endl;
}

// main program (program utama)
int main() {
    // isi array A
    vector<int> arrA = {10, 30, 90, 70, 50};
    // isi array B
    vector<int> arrB = {20, 60, 100, 80, 40};
    // panggil fungsi merge array A dengan B dan diurutkan dengan sort
    mergeSortedArrays(arrA, arrB);

    return 0;
}

```
Kode tersebut digunakan untuk menggabungkan array B ke array A. Kemudian, array tersebut diurutkan. Dalam hal ini, array A dapat menampung lebih banyak isi sehingga array B dapat digabungkan. 

Untuk menggabungkan array B ke array A, maka insert dilakukan pada array A menggunakan kode `arrA.insert(arrA.end(), arrB.begin(), arrB.end());`. Selanjutnya, array diurutkan menggunakan kode `sort(arrA.begin(), arrA.end());`. Sorting pada program di atas dilakukan secara ascending dan descending.

Pada main program, array A dan array B perlu diisi terlebih dahulu. 10, 30, 90, 70, dan 50 merupakan isi dari array A. Sedangkan 20, 60, 100, 80, dan 40 merupakan isi dari array B. Selanjutnya, array B digabungkan ke array A dan diurutkan dengan memanggil fungsi `mergeSortedArrays(arrA, arrB);` dimana pada fungsi tersebut telah ada kode untuk menggabungkan dan mengurutkan array. Berikut output dari program tersebut.

### Output:
![program 3 output](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/687ed3c3-a4f7-4c42-bfa8-c78fb719f32b)

### Full code of screenshot:
![program 3 full ss](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/7260dacd-b5ba-47b2-a61e-99c39c03fb1e)

