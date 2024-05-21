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
