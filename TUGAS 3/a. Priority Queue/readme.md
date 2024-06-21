# <h1 align="center">Priority Queue</h1>
<p align="center">2311110051 - Ardelia Rachma Laksita</p>

## Table of Contents
1. [Penjelasan](#penjelasan)
2. [Contoh Program](#contoh-program)
3. [Penjelasan Alur Program](#penjelasan-alur-program)
4. [Referensi](#referensi)

# Penjelasan
Priority Queue adalah struktur data khusus yang memungkinkan kita menyimpan elemen-elemen dengan nilai prioritas tertentu [6]. Konsep dari Priority Queue mirip dengan Queue biasa. Yang membedakan adalah pada Priority Queue terdapat nilai prioritas elemen yang akan menentukan urutan elemen saat diambil. Pada algoritma priority queue, setiap item di queue memiliki prioritas dimana elemen dengan prioritas yang lebih tinggi akan dikeluarkan (dequeue) terlebih dahulu sebelum elemen yang memiliki prioritas lebih rendah [3]. 

Priority Queue memerlukan key-value untuk mengurutkan elemen atau item tanpa menggunakan queue [3]. Urutan dari elemen-elemen akan diabaikan di dalam operasi stack atau queue [2]. Sebuah priority queue memungkinkan untuk memperpanjang konsep dari queue melalui _setting_ atau aturan dari sebuah prioritas elemen di queue [5]. Priority queue merupakan jenis queue yang elemennya dihapus berdasarkan urutan prioritas [8]. Elemen dengan prioritas tertinggi akan diambil atau diekstrak terlebih dahulu tanpa harus memindahkan elemen-elemen lainnya. Urutannya juga tidak selalu sama, melainkan berdasarkan priority value saat itu. Prioritas dapat ditentukan menggunakan aturan yang telah ditetapkan sebelumnya atau dengan membandingkan nilai-nilai elemen [7].

Berikut 3 variasi operasi yang dapat digunakan pada priority queue [1] :
1. Insertion
2. Deletion
3. Display

Pada priority queue, insertion dan deletion juga diselesaikan berdasarkan prioritas yang ditandai [4].

### Fungsi atau Kegunaan Queue dalam Algoritma:
- **Algoritma Dijkstra**: digunakan untuk menemukan jalur terpendek dalam graf berbobot positif. Priority Queue memungkinkan pemilihan simpul berikutnya dengan bobot terkecil selama proses pencarian jalur terpendek.
- **Algoritma A (A-Star)**: digunakan dalam permasalahan pencarian jarak terpendek dengan heuristik. Priority Queue membantu memilih simpul berikutnya berdasarkan nilai fungsi heuristik dan jarak yang sudah dilalui.
- **Algoritma Huffman**: digunakan dalam kompresi data. Elemen-elemen dengan frekuensi kemunculan yang lebih tinggi diberikan prioritas lebih tinggi saat pembuatan pohon Huffman.
- **Penjadwalan Tugas**: Priority Queue membantu dalam menentukan urutan penjadwalan tugas berdasarkan prioritas yang telah ditentukan.

### Cara kerja Priority Queue:
Pada dasarnya, Priority Queue dapat diimplementasikan dengan menggunakan struktur data dasar seperti heap atau binary search tree yang memungkinkan kita untuk melakukan operasi penyisipan (insert) dan penghapusan (delete) dalam waktu logaritmik. 

### Ordering Priority Queue:
- **Ascending Priority Queue**: yaitu koleksi item atau elemen dimana itemnya dapat dimasukkan secara bebas, tapi hanya elemen terkecil yang akan dihapus.
- **Descending Priority Queue**: yaitu koleksi item atau elemen dimana itemnya bisa dilakukan pada setiap _order_, tapi hanya elemen terbesar yang akan dihapus.


# Contoh Program
```C++
#include <iostream>
#include <algorithm>
using namespace std;

// deklarasi ukuran maksimal H dan deklarasi heapSize
int H[50];
int heapSize = -1;

// fungsi void untuk dapatkan parent node
int parent(int i) {
    return (i - 1) / 2;
}

// fungsi void untuk dapatkan leftChiled node dari indeks i
int leftChild(int i) {
    return ((2 * i) + 1);
}

// fungsi void untuk dapatkan rightChild node dari indeks i
int rightChild(int i) {
    return ((2 * i) + 2);
}

// fungsi void untuk lakukan operasi shift up pada elemen dengan indeks i (elemen digerakkan ke atas heap)
void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

// fungsi void untuk lakukan operasi shift down pada elemen dengan indeks i (elemen digerakkan ke bawah heap)
void shiftDown(int i) {
    // deklarasi maxIndex
    int maxIndex = i;
    int l = leftChild(i);
    // jika leftChild (l) lebih kecil dari heapSize dan H[l] > H[maxindex]
    if (l <= heapSize && H[l] > H[maxIndex]) {
        maxIndex = l;
    }
    int r = rightChild(i);
    // jika rightChild (r) lebih kecil dari heapSize dan H[r] > H[maxindex]
    if (r <= heapSize && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    // jika indeks tidak sama dengan maxIndex
    if (i != maxIndex) {
        swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

// fungsi void untuk tambahkan elemen baru 
void insert(int p) {
    heapSize = heapSize + 1;
    H[heapSize] = p;
    shiftUp(heapSize);
}

// fungsi void untuk ekstrak (keluarkan) elemen maksimal dimana nilainya paling besar
int extractMax() {
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize - 1;
    shiftDown(0);
    return result;
}

// fungsi void untuk ubah priority elemen
void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

// mendapatkan elemen maksimum dari heap
int getMax() {
    return H[0];
}

// fungsi void untuk hapus elemen dari heap
void remove(int i) {
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

// fungsi void untuk atur ukuran elemen dan isi elemen di dalam heap oleh input user
void addHeap(int size) {
    for (int i = 0; i < size; i++) {
        int element;
        cout << "Enter element " << (i + 1) << ": ";
        cin >> element;
        insert(element);
    }
}

// main program (program utama)
int main() {
    // deklarasi a
    int a;
    // user input ukuran elemen (banyak elemen yang diinginkan)
    cout << "Enter the size of elements: ";
    cin >> a;
    // memanggil fungsi addHeap
    addHeap(a);

    // tampilkan priority queue dari elemen yang telah diinput user
    cout << "Priority Queue: ";
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    // tampilkan node yang memiliki maximum priority dengan memanggil fungsi extractMax
    cout << "Node with maximum priority: " << extractMax() << "\n";

    // tampilkan priority queue setelah ekstrak elemen maximum"
    cout << "Priority queue after extracting maximum: ";
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    // deklarasi index dan newPriority
    int indeks, newPriority;
    // user input index elemen yang ingin diubah
    cout << "Enter the Index of the priority you want to change: ";
    cin >> indeks;
    // user input new priority untuk menggantikan elemen pada index yang telah diinput
    cout << "Enter the new priority: ";
    cin >> newPriority;
    // memanggil fungsi changePriority untuk ubah elemen
    changePriority(indeks, newPriority);

    // tampilkan Priority queue setelah elemen diperbarui
    cout << "Priority queue after priority change: ";
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    // deklarasi removeElement
    int removeElement;
    // user input indeks dari elemen yang ingin dihapus
    cout << "Enter the Indeks of the element you want to remove: ";
    cin >> removeElement;
    // panggil fungsi remove untuk hapus elemen
    remove(removeElement);

    // tampilkan Priority Queue setelah elemen dihapus
    cout << "Priority queue after removing the element: ";
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    return 0;
}

```

# Penjelasan Alur Program
Kode tersebut digunakan untuk mendapatkan parent node, left child node, right child node, melakukan operasi shift up dan shift down, memasukkan atau menambahkan elemen baru, mengekstrak elemen maksimum, mengubah prioritas elemen, mendapatkan elemen maksimum, serta menghapus elemen dari heap menggunakan input user. Program tersebut hampir sama seperti Guided 1. Yang membedakan adalah program ini menggunakan input user karena heapnya telah dikonstruksi secara manual berdasarkan user. Pada Guided 1, semua elemen dan indeks yang ingin ditambah (insert), diubah (change), dihapus (remove), dan lain-lain langsung dimasukkan dalam program sehingga user tidak melakukan input pada output. Sedangkan pada unguided 1, user perlu memasukkan size elemen, elemen-elemen, dan input-inut lain sesuai dengan operasi yang diminta. 

#### Penjelasan Kode:
Berikut kode-kode dan fungsi yang terdapat pada program tersebut:
- `int H[50];` dan `int heapSize = -1;` merupakan deklarasi ukuran maksimal queue tersebut dan heapSizenya.
- `int parent(int i)` digunakan untuk mendapatkan parent node.
- `int leftChild(int i)` digunakan untuk mendapatkan leftChild node dari indeks i.
- `int rightChild(int i)` digunakan untuk mendapatkan rightChild node dari indeks i.
- `void shiftUp(int i)` digunakan untuk melakukan operasi shift up pada elemen dengan indeks i. Elemen akan digerakkan ke atas heap hingga priority terpenuhi.
- `void shiftDown(int i)` digunakan untuk melakukan operasi shift down pada elemen dengan indeks i. Elemen akan digerakkan ke bawah heap hingga priority terpenuhi.
- `void insert(int p)` digunakan untuk menambahkan atau memasukkan elemen baru pada heap.
- `int extractMax()` digunakan untuk mengekstrak elemen maksimum sehingga keluar dari heap saat ini.
- `void changePriority(int i, int p) ` digunakan untuk melakukan perubahan elemen sesuai indeks yang diinginkan dan diinputkan oleh user.
- `int getMax() ` digunakan untuk mendapatkan elemen maksimum pada heap.
- `void remove(int i)` digunakan untuk menghapus suatu elemen sesuai dengan indeks yang diinputkan oleh user.
- `void addHeap(int size)` digunakan untuk menambahkan elemen-elemen pada heap sesuai dengan size yang telah diinputkan oleh user. Banyak elemen yang dimasukkan yaitu sesuai dengan ukurannya.

#### Penjelasan Main Program:
- `int a;` merupakan deklarasi dari a yang akan digunakan untuk menginput ukuran elemen (banyak elemen) yang diinginkan.
- `cout << "Enter the size of elements: ";` dan `cin >> a;` akan meminta user untuk memasukkan ukuran (size) elemen.
- `addHeap(a);` adalah fungsi yang dipanggil untuk menambahkan elemen sesuai dengan banyak ukuran yang telah diinput.
- **"Node with maximum priority: "** digunakan untuk menampilkan node yang memiliki nilai maximum priority, artinya nilainya paling besar. Kemudian, cara untuk menampilkannya adalah dengan memanggil fungsi `extractMax()`. Selanjutnya node yang memiliki nilai maximum akan diekstrak sehingga dihapus dari heap.
- `cout << "Priority queue after extracting maximum: "` dan perulangan for `for (int i = 0; i <= heapSize; ++i)` pada line setelah kode cout tersebut digunakan untuk menampilkan Priority queue setelah node maksimumnya diesktrak sehingga pada heap saat ini memiliki nilai maksimum yang baru.
- `int indeks, newPriority;` merupakan deklarasi index dan newPriority dimana variabel tersebut dibutuhkan untuk menjalankan program perubahan priority (changePriority).
- `cout << "Enter the Index of the priority you want to change: ";` dan `cin >> indeks` akan meminta user untuk memasukkan indeks dari elemen yang ingin diubah.
- `cout << "Enter the new priority: ";` dan `cin >> newPriority;` akan meminta user untuk memasukkan elemen baru sesuai pada indeks yang telah diinput sebelumnya.
- `changePriority(indeks, newPriority);` adalah fungsi yang dipanggil untuk melakukan changePriority atau perubahan elemen.
- `cout << "Priority queue after priority change: ";` dan `for (int i = 0; i <= heapSize; ++i)` digunakan untuk menampilkan Priority queue setelah ada elemen yang diubah sebelumnya.
- `int removeElement;` merupakan deklarasi removeElement yang akan digunakan untuk program menghapus elemen.
- `cout << "Enter the Indeks of the element you want to remove: ";` dan `cin >> removeElement;` digunakan untuk menghapus elemen sesuai dengan indeks yang diinput oleh user. Indeks dimulai dari 0. Elemen maksimalnya berada pada indeks **Size Element - 1**. Misalnya, ada 10 elemen pada suatu heap, maka indeksnya adalah 0 hingga 9.
- `cout << "Priority queue after removing the element: ";` dan`for (int i = 0; i <= heapSize; ++i)` digunakan untuk menampilkan elemen saat ini setelah ada elemen yang dihapus.
- `cout << "\n"` digunakan untuk mencetak space sebanyak 1 line sebelum atau sesudah suatu tampilan output.

#### Output:
![Cuplikan layar 2024-05-20 085503](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/ac6672b0-a919-45d8-aa1f-79c6ab7d2c82)

**Penjelasan Output :**

![Cuplikan layar 2024-05-20 120411](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/595fe6bc-45fa-4412-8d40-d52a17ca9091)

Pada output tersebut, user melakukan input dengan ukuran elemen (banyak elemen) adalah 10 menggunakan **"Enter the size of element: "**. Selanjutnya, program akan melakukan iterasi sebanyak elemen yang telah diinputkan. Program akan meminta user memasukkan elemen sebanyak 10 pada bagian **"Enter element ...: "** (elemen 1 hingga 10). Kemudian, program akan menampilkan seluruh elemen yang telah diinput dengan tampilan **"Priority Queue: "**. User memasukkan elemen-elemen berikut.
- Enter element 1 : 10
- Enter element 2 : 9
- Enter element 3 : 8
- Enter element 4 : 7
- Enter element 5 : 6
- Enter element 6 : 5
- Enter element 7 : 4
- Enter element 8 : 3
- Enter element 9 : 2
- Enter element 10 : 1

![Cuplikan layar 2024-05-20 120610](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/186ac088-ff58-4e01-b860-afe135ee05c2)

Node with maximum prioritynya adalah 10. Selanjutnya, 10 diesktrak sehingga tidak ada lagi di dalam heap.

![Cuplikan layar 2024-05-20 120620](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/8e83b065-3121-4b31-846f-5b6b3d3f0232)

Pada output tersebut, elemen yang ingin diubah menggunakan changePriority adalah indeks ke-2 yaitu 8 menjadi 11 sehingga menghasilkan tampilan di atas.

![Cuplikan layar 2024-05-20 120633](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/925e50ad-6ee5-413c-a03a-307e959c3368)

Pada output tersebut, elemen yang dihapus berada pada index ke-1 yaitu 7 sehingga 7 dihapus dari heap tersebut.

#### Full code Screenshot:

# Referensi
- [1] A.A. Puntambekar, Data Structures. Edisi Pertama. Washington : Amazon Digital Services, 2020.
- [2] A.M. Jagtap dan A.S. Mali, Data Structures Using C. Edisi Pertama. Florida (US) : CRC Press, 2021.
- [3] A. Subero, Codeless Data Structures and Algorithms: Learn DSA Without Writing a Single Line of Code . Edisi Pertama. Moruga (US) : Apress Publisher, 2020.
- [4] D. Malhotra dan N. Malhotra, Data Structures and Program Design Using C++. Edisi Pertama. Virginia (US) : Mercury Learning and Information, 2019.
- [5] M. Jamro, C# Data Structures and Algorithm. Edisi Pertama. Birmingham (Inggris) : Packt Publishing, 2024.
- [6] R. Pratama, "Priority Queue: Konsep dan Penggunaan dalam Algoritma," Medium, 22 Juli 2023. [Online]. Tersedia : 
https://medium.com/@furatamarizuki/priority-queue-konsep-dan-penggunaan-dalam-algoritma-f4c1cd117ba [Diakses: 17 Juni 2024].
- [7] R. Pratama, “Queue: Pengealan, Implementasi, Operasi Dasar, dan Aplikasi,” Medium, 25 Mei 2023. [Online]. Tersedia : https://medium.com/@furatamarizuki/queue-pengenalan-implementasi-operasi-dasar-dan-aplikasi-c5eed7e871a3 [Diakses: 19 Juni 2024].
- [8] S.N. Mohanty dan P. K. Tripathy, Data Structure and Algorithms Using C++. New York City : Wiley Publishing, 2021.
