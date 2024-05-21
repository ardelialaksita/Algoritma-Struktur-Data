#include <iostream>
using namespace std;

// PROGRAM OPERASI STACK

// deklarasi ukuran maksimal array buah
string arrayBuah[5];
int maksimal = 5, top = 0;

// operasi pengecekan jika array penuh
bool isFull() {
    return (top == maksimal);
}

// operasi pengecekan jika array kosong
bool isEmpty() {
    return (top == 0);
}

// operasi menambah isi array buah
void pushArrayBuah(string data) {
    if (isFull()) {
        cout << "Data telah penuh" << endl;
    } else {
        arrayBuah[top] = data;
        top++;
    }
}

// operasi menghapus isi array buah
void popArrayBuah() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dihapus" << endl;
    } else {
        arrayBuah[top - 1] = "";
        top--;
    }
}

// operasi melihat isi array buah
void peekArrayBuah(int posisi) {
    if (isEmpty()) {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    } else if (posisi > top || posisi <= 0) {
        cout << "Posisi tidak valid" << endl;
    } else {
        cout << "Posisi ke " << posisi << " adalah buah " << arrayBuah[top - posisi] << endl;
    }
}

// operasi menghitung isi stack
int countStack() {
    return top;
}

// operasi mengubah isi array buah
void changeArrayBuah(int posisi, string data) {
    if (posisi > top || posisi <= 0) {
        cout << "Posisi melebihi data yang ada atau tidak valid" << endl;
    } else {
        arrayBuah[top - posisi] = data;
    }
}

// operasi menghapus seluruh isi array buah sehingga kosong
void destroyArrayBuah() {
    for (int i = 0; i < top; i++) {
        arrayBuah[i] = "";
    }
    top = 0;
}

// tampilkan seluruh isi array buah saat ini
void printArrayBuah() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dicetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--) {
            cout << arrayBuah[i] << endl;
        }
    }
}

// main program (program utama)
int main() {
    // tambahkan isi array buah
    pushArrayBuah("Apel");
    pushArrayBuah("Durian");
    pushArrayBuah("Nanas");
    pushArrayBuah("Mangga");
    pushArrayBuah("Pepaya");

    // panggil fungsi mencetak array buah
    printArrayBuah();
    cout << "\n";

    // pengecekan apakah stack penuh atau kosong
    cout << "Apakah data stack penuh? " << (isFull() ? "Ya" : "Tidak") << endl;
    cout << "Apakah data stack kosong? " << (isEmpty() ? "Ya" : "Tidak") << endl;

    // panggil fungsi melihat array buah
    peekArrayBuah(2);
    // panggil fungsi menghapus array buah
    popArrayBuah();

    // tampilkan banyaknya data pada stack
    cout << "Banyaknya Data = " << countStack() << endl;
    
    // panggil fungsi untuk ubah array buah
    changeArrayBuah(2, "Manggis");
    // panggil fungsi mencetak array buah saat ini
    printArrayBuah();

    cout << "\n";
    // panggil fungsi menghapus seluruh isi array sehngga stack kosong
    destroyArrayBuah();
    cout << "Jumlah data setelah dihapus: " << top << endl;
    // panggil fungsi mencetak array buah saat ini
    printArrayBuah();
    
    return 0;
}
