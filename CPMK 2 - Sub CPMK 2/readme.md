# <h1 align="center">Tugas CPMK 2 Sub CPMK 2 (Sorting)</h1>
<p align="center">2311110051 - Ardelia Rachma Laksita</p>

## Table of Contents
1. [Soal 1](#soal-1)
2. [Soal 2](#soal-2)

## Soal 1
### 1. Terdapat tiga algoritma sorting yang umum digunakan yakni, Bubble Sort, Selection Sort, dan Merge Sort. Berikan penjelasan alur dari masing-masing algoritma tersebut, dan jelaskan runtime dari best case dan worst case masing-masing algoritma! (35 Poin)

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

### Output:
![program 1 output](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/135d7689-9f08-41c2-8712-a962058250d2)

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

### Output:
![program 2 output](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/8142a081-a222-44e4-97ab-7afc84e69ede)

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

### Output:
![program 3 output](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/687ed3c3-a4f7-4c42-bfa8-c78fb719f32b)

### Full code of screenshot:
![program 3 full ss](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/7260dacd-b5ba-47b2-a61e-99c39c03fb1e)

