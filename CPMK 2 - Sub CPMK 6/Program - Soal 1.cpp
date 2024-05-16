#include <iostream>
using namespace std;

string arrayBuah[5];
int maksimal = 5, top = 0;

bool isFull() {
    return (top == maksimal);
}

bool isEmpty() {
    return (top == 0);
}

void pushArrayBuah(string data) {
    if (isFull()) {
        cout << "Data telah penuh" << endl;
    } else {
        arrayBuah[top] = data;
        top++;
    }
}

void popArrayBuah() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dihapus" << endl;
    } else {
        arrayBuah[top - 1] = "";
        top--;
    }
}

void peekArrayBuah(int posisi) {
    if (isEmpty()) {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    } else if (posisi > top || posisi <= 0) {
        cout << "Posisi tidak valid" << endl;
    } else {
        cout << "Posisi ke " << posisi << " adalah buah " << arrayBuah[top - posisi] << endl;
    }
}

int countStack() {
    return top;
}

void changeArrayBuah(int posisi, string data) {
    if (posisi > top || posisi <= 0) {
        cout << "Posisi melebihi data yang ada atau tidak valid" << endl;
    } else {
        arrayBuah[top - posisi] = data;
    }
}

void destroyArrayBuah() {
    for (int i = 0; i < top; i++) {
        arrayBuah[i] = "";
    }
    top = 0;
}

void printArrayBuah() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dicetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--) {
            cout << arrayBuah[i] << endl;
        }
    }
}

int main() {
    pushArrayBuah("Apel");
    pushArrayBuah("Durian");
    pushArrayBuah("Nanas");
    pushArrayBuah("Mangga");
    pushArrayBuah("Pepaya");

    printArrayBuah();
    cout << "\n";

    cout << "Apakah data stack penuh? " << (isFull() ? "Ya" : "Tidak") << endl;
    cout << "Apakah data stack kosong? " << (isEmpty() ? "Ya" : "Tidak") << endl;

    peekArrayBuah(2);
    popArrayBuah();

    cout << "Banyaknya Data = " << countStack() << endl;
    changeArrayBuah(2, "Manggis");
    printArrayBuah();

    cout << "\n";
    destroyArrayBuah();
    cout << "Jumlah data setelah dihapus: " << top << endl;
    printArrayBuah();
    return 0;
}
