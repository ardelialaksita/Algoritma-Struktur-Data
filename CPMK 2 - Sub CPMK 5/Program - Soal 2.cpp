#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// PROGRAM MENGHAPUS NODE TENGAH PADA SINGLE LINKED LIST
// deklarasi struct variabel data dan next
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

// fungsi void menambahkan node baru di linked list
void tambahData(Node*& head, int data) {
    Node* nodeBaru = new Node(data);
    if (head == NULL) {
        head = nodeBaru;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = nodeBaru;
}

// fungsi void menghapus nilai pada linked list
void deleteMidNode(Node*& head, int dataValue) {
    // apabila nilai masih kosong
    if (head == NULL) {
        cout << "List masih kosong!" << endl;
        return;
    }

    // apabila list tidak kosong dan data telah berhasil dihapus
    if (head->data == dataValue) {
        Node* hapus = head;
        head = head->next;
        delete hapus;
        cout << "Data " << dataValue << " berhasil dihapus." << endl;
        return;
    }

    Node* current = head;
    while (current->next != NULL && current->next->data != dataValue) {
        current = current->next;
    }

    // apabila data yang ingin dihapus oleh user tidak ada di dalam list
    if (current->next == NULL) {
        cout << "Data " << dataValue << " tidak ditemukan dalam list." << endl;
        return;
    }

    // apabila data ditemukan dalam list dan data telah berhasil dihapus
    Node* hapus = current->next;
    current->next = current->next->next;
    delete hapus;
    cout << "Data " << dataValue << " berhasil dihapus." << endl;
}

// tampilkan isi linked list
void cetakList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// main program (program utama)
int main() {
    // deklarasi head dan nilai
    Node* head = NULL;
    int nilai;
    
    // header program
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << " ============ PROGRAM MENGHAPUS NODE TENGAH PADA SINGLE LINKED LIST ============" << endl;
    
    // tambah data pada list
    tambahData(head, 500);
    tambahData(head, 600);
    tambahData(head, 700);
    tambahData(head, 800);
    tambahData(head, 900);

    // tampilkan data yang telah ditambahkan (sebelum dihapus)
    cout << "List sebelum data dihapus: ";
    // memanggil fungsi cetakList untuk print data saat ini
    cetakList(head);
    
    // input user memilih data yang ingin dihapus
    cout << "Data manakah yang ingin Anda hapus?: ";
    cin >> nilai;
    // memanggil fungsi deleteMidNode untuk hapus data sesuai pilihan input user
    deleteMidNode(head, nilai);
    
    // tampilkan data saat ini (baik ada atau tidak ada yang dihapus)
    cout << "List data terbaru saat ini: ";
    // memanggil fungsi cetakList untuk print data saat ini
    cetakList(head);

    // footer program
    cout << "--------------------------------------------------------------------------------" << endl;

    return 0;
}
