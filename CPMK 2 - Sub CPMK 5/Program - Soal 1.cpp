#include <iostream>
#include <unordered_set>
using namespace std;

// PROGRAM DOUBLE LINKED LIST UNTUK MENGHAPUS DUPLIKASI DATA
// deklarasi data, next, dan previous dalam struct node.
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(NULL), prev(NULL) {}
};

// fungsi void untuk menghapus duplikasi data
void hapusDuplikasi(Node* head) {
    if (head == NULL) return;

    // unordered_set library yang berisi deklarasi list
    unordered_set<int> list;
    // deklarasi current = head dengan pointer
    Node* current = head;

    // saat data current tidak sama dengan NULL, artinya ada nilainya
    while (current != NULL) {
        if (list.find(current->data) != list.end()) {
            // data current akan dihapus karena ada duplikasi data
            Node* hapus = current;
            if (current->prev) current->prev->next = current->next;
            if (current->next) current->next->prev = current->prev;
            current = current->next;
            delete hapus;
        } else {
            // tidak ada duplikasi data
            list.insert(current->data);
            current = current->next;
        }
    }
}

// fungsi void menambahkan node baru pada linked list
void tambahData(Node*& head, int data) {
    Node* nodeBaru = new Node(data);
    // jika head (data depan) sama dengan NULL (tidak ada nilainya), maka buat node baru
    if (head == NULL) {
        head = nodeBaru;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = nodeBaru;
    nodeBaru->prev = temp;
}

// fungsi void untuk mencetak list
void cetakList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// main program
int main() {
    // header program
    cout << "------------------------------------------------------------------------------" << endl;
    cout << " ============ PROGRAM MENGHAPUS DUPLIKASI DATA PADA UNSORTED LIST ============" << endl;
    
    // deklarasi node head
    Node* head = NULL;
    // tambah data pada head list
    tambahData(head, 70);
    tambahData(head, 80);
    tambahData(head, 100);
    tambahData(head, 100);
    tambahData(head, 80);
    tambahData(head, 90);

    // tampilkan data yang telah ditambahkan
    cout << "List: ";
    // panggil fungsi yang mencetak data 
    cetakList(head);

    // tampilkan data yang telah ditambahkan (sebelum duplikasi data dihapus)
    cout << "List sebelum duplikasi data dihapus: ";
    // panggil fungsi yang mencetak data 
    cetakList(head);
    
    // panggil fungsi untuk menghapus duplikasi data
    hapusDuplikasi(head);
    
    // tampilkan data setelah duplikasi dihapus
    cout << "List setelah duplikasi data dihapus: ";
    // panggil fungsi yang mencetak data saat ini
    cetakList(head);

    // footer program
    cout << "------------------------------------------------------------------------------" << endl;

    return 0;
}
