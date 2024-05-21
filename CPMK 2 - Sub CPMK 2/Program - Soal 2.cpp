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
