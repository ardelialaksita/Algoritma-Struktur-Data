#include <iostream>
#include <stack>
using namespace std;

// PROGRAM MENSORTIR SEBUAH STACK SEHINGGA ELEMEN TERKECIL MENJADI ELEMEN TOP

// fungsi void mengurutkan stack
void sortStack(stack<int>& data) {
    stack<int> temp; 
    while (!data.empty()) { 
        // ambil elemen paling atas stack data
        int cur = data.top(); 
        // hapus elemen paling atas stack data
        data.pop(); 

        // pindahkan elemen-elemen yang lebih besar 
        while (!temp.empty() && temp.top() > cur) {
            // pindah elemen paling atas stack temp ke data
            data.push(temp.top()); 
            // hapus elemen paling atas stack temp
            temp.pop(); 
        }
        temp.push(cur);
    }

    // balik urutan elemen agar elemen terkecil menjadi elemen top
    while (!temp.empty()) {
        data.push(temp.top()); 
        temp.pop(); 
    }
}

int main() {
    // deklarasi stack data
    stack<int> data; 
    // tambah elemen ke stack data
    data.push(10); 
    data.push(20); 
    data.push(21); 
    data.push(12); 
    data.push(31); 

    // menyimpan salinan stack asli sebelum diurutkan
    stack<int> originalData = data;

    // panggil fungsi urutkan stack
    sortStack(data);

    // tampilkan data belum terurut
    cout << "Data sebelum terurut: ";
    while (!originalData.empty()) {
        cout << originalData.top() << " "; 
        originalData.pop();
    }
    cout << endl;

    // tampilkan hasil data terurut
    cout << "Data terurut: ";
    while (!data.empty()) {
        cout << data.top() << " "; 
        data.pop();
    }
    cout << endl;

    return 0;
}
