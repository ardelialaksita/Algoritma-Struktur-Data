# <h1 align="center">Graph and Tree</h1>
<p align="center">2311110051 - Ardelia Rachma Laksita</p>

## Table of Contents
1. [Penjelasan](#penjelasan)
2. [Contoh Program](#contoh-program)
3. [Penjelasan Alur Program](#penjelasan-alur-program)
4. [Referensi](#referensi)

# Penjelasan
Dalam pengembangan dunia nyata, sebagian besar algoritma yang bekerja pada grafik akan bekerja pada pohon karena pohon pada dasarnya adalah grafik tanpa adanya siklus [1]. Berikut penjelasan detail tentang graf dan pohon.

### Graf (Graph)
Graf menggunkan priority queue yang diimplementasikan menggunakan min-heap untuk memilih simpul selanjutnya untuk dilakukan eksplorasi [3]. Grafik adalah struktur data yang merupakan kombinasi node dan edge [5]. Node atau simpul menyimpan nama suatu variable, misalnya nama kota. Sedangkan edge (sisi) adalah koneksi antara dua node. Edge dapat diartikan jembatan karena menghubungkan antara dua node.

### Tipe-tipe Graf (Graph):
- **Directed and Undirected Graphs**: yaitu graph yang memiliki sisi dari node satu ke node yang lain. Graph yang dibuat dikenal dengan Directed Graph. Terdapat garis sederhana di antara dua nodes sebagai jembatan dari suatu graph. Inilah yang dikenal dengan Undirected graphs.
- **Weighted Graph**: yaitu graph yang setiap sisi atau jembatannya (edge) memiliki bobot sebagai nilai dari koneksi di antara dua node.
- **Cyclic and Acyclic Graphs**: dalam kasus grafik berarah (directed graph), ada kemungkinan untuk membuat jalur sedemikian rupa sehingga saat melakukan perjalanan akan berakhir pada node yang sudah dilalui. Inilah yang dinamakan Cyclic Graph. Acyclic Graph adalah kebalikan dari Cyclic Graph dimana perjalanan berakhir bukan pada node yang sudah dilalui.

### Visualisasi Graf (Graph):
**1. 2D Matrix**

![2D MATRIX](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/6413f000-8d0f-489f-8512-19d25c9df862)

**_Source: Sitasi 5_**

**2. Adjacency List**

![ADJACENCY LIST](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/66286f5a-f097-441c-9e85-4a36d5d2edf5)

**_Source: Sitasi 5_**

**3. BFS Traversal**

![BFS TRAVERSAL](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/febeb953-6327-4252-8141-a983dccd779c)

**_Source: Sitasi 5_**

Struktur Data yang diperlukan untuk menjalankan algoritma BFS antara lain:

- **Queue**: untuk menyimpan node anak atau terhubung yang masih perlu dijelajahi.
- **Unordered Map or Vector**: untuk mengetahui apakah suatu node tertentu dikunjungi atau tidak.


### Tree (Pohon)
Tree atau pohon yaitu kumpulan node yang saling terhubung satu sama lain dalam suatu kesatuan yang membentuk layaknya struktur sebuah pohon [2]. Struktur Tree adalah suatu cara merepresentasikan suatu struktur hirarki ( one — to many ) secara grafis yang mirip sebuah pohon, walaupun pohon tersebut hanya tampak sebagai kumpulan — node — node dari atas ke bawah [2]. Red-Black Tree adalah binary search tree yang menggunakan atribut ekstra untuk setiap nodenya, seperti warna dimana yang digunakan adalah merah atau hitam [4]. Kita juga harus menyimpan track dari parents nodenya.

### Implementasi Konsep Pohon (Tree):
![ALGORITMA POHON](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/3d8ca0a4-5d74-4f79-bfd0-7cc9ea12033e)

_**Source: Sitasi 2**_

- Data yang pertama kali masuk akan menjadi Node Root.
- Data yang lebih kecil dari node root akan masuk dan menempati node kiri dari node Root.
- Jika ada data yang lebih besar dari Node Root maka akan masuk dan menempati node sebelah kanan dari Node Root.

### Traversal Pohon (Tree):
- **Pre-Order Traversal**: yaitu mengunjungi atau melihat node dari suatu pohon dimana dimulai dari node root, menuju ke subtrees kiri, dan terakhir ke subtrees kanan.
- **In-Order Traversal**: yaitu mengunjungi atau melihat node dari suatu pohon dimana dimulai dari node subtrees kiri, menuju ke root, dan terakhir ke subtrees kanan.
- **Post-Order Traversal**: yaitu mengunjungi atau melihat node dari suatu pohon dimana dimulai dari node subtrees kiri, menuju ke subtrees kanan, dan terakhir ke root. 


# Contoh Program Graph
```C++
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// menyimpan deklarasi dalam struct
struct Graph {
    vector<string> simpul;
    vector<vector<int>> bobotAntarSimpul;
    int jumlahSimpul;
};

// fungsi void untuk menampilkan graph
void tampilkanGraph(const Graph& Ardelia_2311110051) {
    cout << "Simpul\t";

    // perulangan for untuk menampilkan 'Simpul' sesuai jumlah simpul yang diinput user
    for (int i = 0; i < Ardelia_2311110051.jumlahSimpul; ++i) {
        cout << Ardelia_2311110051.simpul[i] << "\t";
    }
    cout << endl;

    // perulangan for untuk menampilkan dan memasukkan bobot antar simpul sesuai jumlah simpul
    for (int i = 0; i < Ardelia_2311110051.jumlahSimpul; ++i) {
        cout << Ardelia_2311110051.simpul[i] << "\t";
        for (int j = 0; j < Ardelia_2311110051.jumlahSimpul; ++j) {
            cout << Ardelia_2311110051.bobotAntarSimpul[i][j] << "\t";
        }
        cout << endl;
    }
}

// main program (program utama)
int main() {
    // variable Ardelia_2311110051 akan memanggil kode program di dalam Graph
    Graph Ardelia_2311110051;

    // user memasukkan jumlah simpul
    cout << "Silakan masukan jumlah simpul : ";
    cin >> Ardelia_2311110051.jumlahSimpul;

    // user memasukkan nama simpul
    Ardelia_2311110051.simpul.resize(Ardelia_2311110051.jumlahSimpul);
    cout << "Silakan masukan nama simpul" << endl;
    for (int i = 0; i < Ardelia_2311110051.jumlahSimpul; ++i) {
        cout << "Simpul " << i + 1 << ": ";
        cin >> Ardelia_2311110051.simpul[i];
    }

    // user memasukkan bobot antar simpul
    Ardelia_2311110051.bobotAntarSimpul.resize(Ardelia_2311110051.jumlahSimpul, vector<int>(Ardelia_2311110051.jumlahSimpul, 0));
    cout << "Silakan masukkan bobot antar simpul" << endl;
    for (int i = 0; i < Ardelia_2311110051.jumlahSimpul; ++i) {
        for (int j = 0; j < Ardelia_2311110051.jumlahSimpul; ++j) {
            // menampilkan kota satu ke kota lain untuk disesuaikan bobotnya
            cout << Ardelia_2311110051.simpul[i] << " --> " << Ardelia_2311110051.simpul[j] << " = ";
            cin >> Ardelia_2311110051.bobotAntarSimpul[i][j];
        }
    }

    // panggil fungsi tampilkanGraph untuk menampilkan seluruh simpul beserta bobotnya
    tampilkanGraph(Ardelia_2311110051);

    cout << endl;

    // return sebagai kode bahwa program telah selesai dan berhasil
    return 0;
}

```

# Penjelasan Alur Program Graph
Kode tersebut digunakan untuk menghitung jarak dari sebuah kota ke kota lainnya. Jarak terkecilnya dilihat melalui bobot yang paling kecil antar kota. Simpul sebagai nama dari sebuah kota. Kemudian, user akan diminta memasukkan nama dan bobot antar kota tersebut karena program ini menggunakan input user. 

#### Penjelasan Kode:
- `struct Graph` menyimpan deklarasi dari simpul, jumlah simpul, dan bobot antar simpul.
- `void tampilkanGraph(const Graph& Ardelia_2311110051)` merupakan fungsi yang akan dipanggil untuk menampilkan seluruh graph beserta bobotnya.
- `cout << Ardelia_2311110051.simpul[i] << "\t";` di dalam perulangan for digunakan untuk menampilkan simpul sesuai jumlah yang telah diinputkan untuk user memasukkan nama dan bobot antar simpulnya.

#### Penjelasan Main Program:
- `Graph Ardelia_2311110051;` artinya variable Ardelia_2311110051 akan memanggil kode-kode program yang ada di dalam Graph.
- `cout << "Silakan masukan jumlah simpul : ";` dan `cin >> Ardelia_2311110051.jumlahSimpul;` meminta user untuk memasukkan jumlah simpul.
- `cout << "Silakan masukan nama simpul" << endl;` dan perulangan `for (int i = 0; i < Ardelia_2311110051.jumlahSimpul; ++i)` meminta user untuk memasukkan nama simpul sebanyak jumlah yang telah diinputkan sebelumnya.
- `cout << "Silakan masukkan bobot antar simpul" << endl;` dan perulangan `for (int i = 0; i < Ardelia_2311110051.jumlahSimpul; ++i)` meminta user memasukkan bobot antar simpul.
- `tampilkanGraph(Ardelia_2311110051);` memanggil fungsi tampilkanGraph untuk menampilkan seluruh simpul beserta bobotnya.
- `return 0;` sebagai kode bahwa program telah selesai dan berhasil.

#### Output dan Penjelasan:
![output unguided 1](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/ec9017a9-d0c6-4e66-9b57-ef5a53a9f344)

Pada output di atas, user memasukkan jumlah simpulnya ada 2 sehingga program akan meminta user memasukkan 2 nama simpul. User memasukkan BALI sebagai nama dari simpul 1 dan PALU sebagai nama dari simpul 2. Selanjutnya, program meminta user memasukkan bobot antar simpul sesuai yang ditampilkan program. User memasukkan 0,3,4, dan 0 seperti output di atas. Terakhir, program menampilkan graph yang berisi nama dan bobot antar simpul.

#### Full code Screenshot:
![full ss unguided 1](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/922b47a0-b78a-42ba-8d45-5c4b8adbeb71)


# Contoh Program Tree
```C++
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// menyimpan deklarasi dalam struct TNode
struct TNode {
    int data;
    TNode *left;
    TNode *right;

    // constructor
    TNode(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// melihat node dari root, subtree kiri, dan terakhir ke subtree kanan
void preOrder(TNode *node) {
    if (node != NULL) {
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

// melihat node dari subtree kiri, root, dan terakhir ke subtree kanan
void inOrder(TNode *node) {
    if (node != NULL) {
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
}

// melihat node dari subtree kiri, subtree kanan, dan terakhir ke root
void postOrder(TNode *node) {
    if (node != NULL) {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
}

// melakukan pencarian pada suatu node berdasarkan nilai
TNode* search_Ardelia_2311110051(TNode* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }
    TNode* leftSearch = search_Ardelia_2311110051(root->left, value);
    if (leftSearch != NULL) return leftSearch;
    return search_Ardelia_2311110051(root->right, value);
}

// menambahkan node
void addNode(TNode* &root, int parentValue, int value, char child) {
    TNode* parent = search_Ardelia_2311110051(root, parentValue);
    if (parent == NULL) {
        cout << "Parent node not found!" << endl;
        return;
    }
    if (child == 'L') {
        if (parent->left == NULL) {
            parent->left = new TNode(value);
        } else {
            cout << "Left child already exists!" << endl;
        }
    } else if (child == 'R') {
        if (parent->right == NULL) {
            parent->right = new TNode(value);
        } else {
            cout << "Right child already exists!" << endl;
        }
    } else {
        cout << "Invalid child type!" << endl;
    }
}

// tampilkan child dari node
void tampilkanChildren(TNode* node) {
    if (node == NULL) {
        cout << "Node not found!" << endl;
        return;
    }
    cout << "Children of node " << node->data << ": ";
    if (node->left != NULL) {
        cout << node->left->data << " (Left) ";
    }
    if (node->right != NULL) {
        cout << node->right->data << " (Right) ";
    }
    if (node->left == NULL && node->right == NULL) {
        cout << "None";
    }
    cout << endl;
}

// tampilkan descendants dari node
void tampilkanDescendants(TNode* node) {
    if (node == NULL) {
        cout << "Node not found!" << endl;
        return;
    }
    cout << "Descendants of node " << node->data << ": ";
    queue<TNode*> qvalue;
    qvalue.push(node);
    bool first = true;
    while (!qvalue.empty()) {
        TNode* current = qvalue.front();
        qvalue.pop();
        if (!first) {
            cout << current->data << " ";
        }
        if (current->left != NULL) {
            qvalue.push(current->left);
        }
        if (current->right != NULL) {
            qvalue.push(current->right);
        }
        first = false;
    }
    cout << endl;
}

// main program (program utama)
int main() {
    TNode* root = NULL;
    int pilihan, value, parentValue;
    char child;

    // tampilkan opsi yang dapat dipilih pada program menu
    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Tambah node root" << endl;
        cout << "2. Tambah node anak" << endl;
        cout << "3. Pre-order traversal" << endl;
        cout << "4. In-order traversal" << endl;
        cout << "5. Post-order traversal" << endl;
        cout << "6. Tampilkan child dari node" << endl;
        cout << "7. Tampilkan descendant dari node" << endl;
        cout << "8. Keluar" << endl;
        cout << "Opsi mana yang ingin Anda pilih? : ";
        cin >> pilihan;

        // jalankan case sesuai opsi yang dipilih (1-8)
        switch (pilihan) {
            // case 1 menambahkan nilai root
            case 1:
                if (root != NULL) {
                    cout << "Root already exists!" << endl;
                } else {
                    cout << "Masukkan nilai untuk root: ";
                    cin >> value;
                    root = new TNode(value);
                }
                break;
            // case 2 memasukkan nilai anak sesuai dengan node parent
            case 2:
                cout << "Masukkan nilai parent: ";
                cin >> parentValue;
                cout << "Masukkan nilai anak: ";
                cin >> value;
                cout << "L (left) atau R (right): ";
                cin >> child;
                addNode(root, parentValue, value, child);
                break;
            // case 3 menampilkan pre-order traversal
            case 3:
                cout << "Pre-order traversal: ";
                preOrder(root);
                cout << endl;
                break;
            // case 4 menampilkan in-order traversal
            case 4:
                cout << "In-order traversal: ";
                inOrder(root);
                cout << endl;
                break;
            // case 5 menampilkan post-order traversal
            case 5:
                cout << "Post-order traversal: ";
                postOrder(root);
                cout << endl;
                break;
            // case 6 menampilkan node children berdasarkan nilai node yang dimasukkan
            case 6:
                cout << "Masukkan nilai node: ";
                cin >> value;
                tampilkanChildren(search_Ardelia_2311110051(root, value));
                break;
            // case 7 menampilkan node descendants berdasarkan nilai node yang dimasukkan
            case 7:
                cout << "Masukkan nilai node: ";
                cin >> value;
                tampilkanDescendants(search_Ardelia_2311110051(root, value));
                break;
            // case 8 keluar dari prorgam
            case 8:
                return 0;
            // tampilan apabila user memasukkan opsi selain 1 hingga 8
            default:
                cout << "Opsi yang Anda pilih tidak valid! Silakan masukkan opsi lain." << endl;
        }
    }
    cout << endl;
    return 0;
}

```

# Penjelasan Alur Program Tree
Kode tersebut merupakan program menu yang digunakan untuk menambahkan node root, parents, dan anak berdasarkan node parents. Kode tersebut juga dapat digunakan untuk menampilkan pre-order, in-order, post-order, node anak da suatu node parents, dan descendants dari suatu node. Node root merupakan node teratas. Selanjutnya, root dapat menjadi node parents apabila ditambah dengan node anak pada left dan right nodenya. Node yang berperan sebagai node anak dari node root tersebut juga dapat menjadi sebuah subtree dengan menambah node anak lagi pada sisi left dan rightnya. Penjelasan lebih detail akan dipaparkan pada output dan penjelasan. 

#### Penjelasan Kode:
- `struct TNode` dan constructor di dalamnya digunakan untuk menyimpan deklarasi-deklarasi.
- `void preOrder(TNode *node)` digunakan untuk melihat node dari root, dilanjutkan ke subtree kiri, dan terakhir ke subtree kanan.
- `void inOrder(TNode *node)` digunakan untuk melihat node dari subtree kiri, dilanjutkan ke root, dan terakhir ke subtree kanan.
- `void postOrder(TNode *node)` digunakan untuk melihat node dari subtree kiri, dilanjutkan ke subtree kanan, dan terakhir ke root.
- `TNode* search(TNode* root, int value)` digunakan untuk mencari suatu node.
- `void addNode(TNode* &root, int parentValue, int value, char child)` digunakan untuk menambah suatu node berdasarkan nilai parentsnya dan letak left atu rightnya.
- `void tampilkanChildren(TNode* node)` digunakan untuk menampilkan child dari suatu node parent.
- `void tampilkanDescendants(TNode* node)` digunakan untuk menampilkan descendants dari suatu node.

#### Penjelasan Main Program:
Pada main program terdapat deklarasi `TNode* root = NULL;`, `int pilihan, value, parentValue;` dan `char child;`. Program juga mencetak pilihan-pilihan program menu. Selanjutnya, program akan meminta user memasukkan 1 opsi sesuai pilihan yang diinginkan. Berikut penjelasan case-casenya:
- `case 1:` artinya apabila user memasukkan 1, program akan meminta user untuk menambahkan nilai pada root node.
- `case 2:` artinya apabila user memasukkan 2, program akan meminta user untuk menambahkan nilai child node dari suatu nilai parents yang ditentukan oleh user juga.
- `case 3:` artinya apabila user memasukkan 3, program akan mengunjungi dan menampilkan node secara pre-order dimana dimulai dari node root, dilanjutkan ke subtrees kiri, dan terakhir ke subtrees kanan.
- `case 4:` artinya apabila user memasukkan 4, program akan mengunjungi dan menampilkan node secara in-order dimana dimulai dari node subtrees kiri, dilanjutkan ke root, dan terakhir ke subtrees kanan.
- `case 5:` artinya apabila user memasukkan 5, program akan mengunjungi dan menampilkan node secara post-order dimana dimulai dari node subtrees kiri, dilanjutkan ke subtrees kanan, dan terakhir ke root.
- `case 6:` artinya apabila user memasukkan 6, program akan menampilkan child node beserta letak left dan rightnya dari parents node yang diinputkan oleh user.
- `case 7:` artinya apabila user memasukkan 7, program akan menampilkan descendants node dari parents node yang diinputkan oleh user.
- `case 8:` artinya apabila user memasukkan 8, program akan berhenti karena 8 merupakan opsi untuk keluar dari program menu tersebut.
- `default` artinya apabila user memasukkan nilai selain 1 hingga 8, maka program akan mencetak "Opsi yang Anda pilih tidak valid! Silakan masukkan opsi lain." karena opsi pilihannya hanya 1 hingga 8.

#### Output dan Penjelasan:

#### Output 1:
![1](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/e4c8aa4e-faaf-4a77-96df-42b5859f83b0)

Pada output tersebut, user memasukkan opsi 1 dan menambahkan nilai pada node root yaitu 10. Dengan demikian, terdapat 1 node di dalam pohon tersebut yaitu 10.

#### Output 2:
![2](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/f673855b-0298-48b4-a0e4-189d121b470b)

Pada output tersebut, user memasukkan opsi 2. User memasukkan 10 sebagai parents nodenya. Selanjutnya, 5 ditambahkan pada sisi kiri (left / L) dari parents node tersebut. Saat ini, terdapat 2 node. Sisi kanan (right / R) parents node 10 masih kosong (NULL).

#### Output 3:
![3](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/da5fe566-2f90-4ae6-8884-d23ea67c838f)

Pada output tersebut, user memasukkan opsi 2. User memasukkan 10 sebagai parents nodenya. Selanjutnya, 15 ditambahkan pada sisi kanan (right / R) dari parents node tersebut. Saat ini, terdapat 3 node. Sisi kanan (right / R) parents node 10 yang awalnya kosong (NULL), saat ini sudah terisi.

#### Output 4:
![4](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/109a7b96-f222-40b0-8533-cd1c01e5398d)

Pada output tersebut, user memasukkan opsi 2. User memasukkan 5 sebagai parents nodenya. Saat ini, 5 tidak hanya sebagai child node, melainkan juga parents node karena user menambahkan child node. Selanjutnya, 2 ditambahkan pada sisi kiri (left / L) dari parents node tersebut. Saat ini, terdapat 4 node. Sisi kanan (right / R) parents node 5 masih kosong (NULL).

#### Output 5:
![5](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/2859bf18-0014-48ae-ad2d-36ac82255243)

Pada output tersebut, user memasukkan opsi 2. User memasukkan 5 sebagai parents nodenya. Saat ini, 5 tidak hanya sebagai child node, melainkan juga parents node karena user menambahkan child node. Selanjutnya, 7 ditambahkan pada sisi kanan (right / R) dari parents node tersebut. Saat ini, terdapat 5 node. Sisi kanan (right / R) parents node 5 yang awalnya kosong (NULL), saat ini sudah terisi.

#### Output 6:
![6](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/1416440f-52a7-44af-bf53-e496d41cc759)

Pada output tersebut, user memasukkan opsi 2. User memasukkan 15 sebagai parents nodenya. Saat ini, 15 tidak hanya sebagai child node, melainkan juga parents node karena user menambahkan child node. Selanjutnya, 11 ditambahkan pada sisi kiri (left / L) dari parents node tersebut. Saat ini, terdapat 6 node. Sisi kanan (right / R) parents node 15 masih kosong (NULL).

#### Output 7:
![7](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/6fdd0b5a-ac9c-4c9e-b93a-1b4f6717942f)

Pada output tersebut, user memasukkan opsi 2. User memasukkan 15 sebagai parents nodenya. Saat ini, 15 tidak hanya sebagai child node, melainkan juga parents node karena user menambahkan child node. Selanjutnya, 13 ditambahkan pada sisi kanan (right / R) dari parents node tersebut. Saat ini, terdapat 7 node. Sisi kanan (right / R) parents node 15 yang awalnya kosong (NULL), saat ini sudah terisi.

#### Output 8:
![8](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/1774171d-4c6e-468d-b921-764b706c5b8b)

Pada output tersebut, user memasukkan opsi 3 sehingga program menampilkan isi pohon secara pre-order traversal yaitu dari node root, subtrees kiri, dan terakhir subtrees kanan. Outputnya adalah 10, 5, 2, 7, 15, 11, 13.

#### Output 9:
![9](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/3dc5bd49-96ce-428d-af20-3b276907c18d)

Pada output tersebut, user memasukkan opsi 4 sehingga program menampilkan isi pohon secara in-order traversal yaitu dari node subtrees kiri, root, dan terakhir subtrees kanan. Outputnya adalah 2, 5, 7, 10, 11, 15, 13.

#### Output 10:
![10](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/7aa394f9-18d7-4c65-b72f-c90124d70607)

Pada output tersebut, user memasukkan opsi 5 sehingga program menampilkan isi pohon secara post-order traversal yaitu dari node root, subtrees kiri, dan terakhir subtrees kanan. Outputnya adalah 10, 5, 2, 7, 15, 11, 13.

#### Output 11:
![11](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/8b16672b-a693-48fb-ba0e-da1a362c8c2a)

Pada output tersebut, user memasukkan opsi 6 dan memasukkan nilai node 5 sehingga program menampilkan child node dari 5 yaitu 2 pada left dan 7 pada right.

#### Output 12:
![12](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/1a3d3024-8640-40ba-b88c-856d950bbd34)

Pada output tersebut, user memasukkan opsi 6 dan memasukkan nilai node 15 sehingga program menampilkan child node dari 5 yaitu 11 pada left dan 13 pada right.

#### Output 13:
![13](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/095dcd75-678d-4fc0-b26b-b59adb7084ef)

Jika dilihat dari output 11 dan 12, node yang ditampilkan terletak pada akhir subtrees sehingga tidak ada child node lagi di dalamnya. Sedangkan pada output 13, user memasukkan 10 sebagai parents nodenya dan program menampilkan 5 pada left dan 15 pada right sebagai child nodenya. Dengan demikian, dapat disimpulkan bahwa child node yang ditampilkan hanya dilihat dari parents node yang diinputkan, bukan seluruh child node di dalam child node berikutnya.

#### Output 14:
![14](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/05921e25-a443-4527-8dc0-eb7a9eda44ea)

Pada output tersebut, user memasukkan opsi 7 dan nilai node yang dimasukkan adalah sehingga didapatkan descendants of node 5 adalah 2 dan 7.

#### Output 15:
![15](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/f0f8748c-22ef-4a6e-bdbc-0748ca3022c5)

Pada output tersebut, user memasukkan opsi 8 sehingga keluar dari program.

#### Full code Screenshot:
![full ss unguided 2](https://github.com/ardelialaksita/Algoritma-Struktur-Data/assets/157208713/b3b63198-4e4a-4a7d-955d-d1918e76d0b9)


# Referensi
- [1] A. Subero, Codeless Data Structures and Algorithms: Learn DSA Without Writing a Single Line of Code . Edisi Pertama. Moruga (US) : Apress Publisher, 2020.
- [2] D. Bali, “Memahami Konsep Tree dalam Struktur Data Lengkap dengan Source Code Programnya,” Medium, Jun. 14, 2021. https://daismabali.medium.com/memahami-konsep-tree-dalam-struktur-data-lengkap-dengan-source-code-programnya-acbd0a8733d6 (accessed Jun. 15, 2024).
- [3] J. Farrier, Data Structures and Algorithms with the C++ STL. Edisi Pertama. Birmingham : Packt Publishing Ltd, 2024.
- [4] S.N. Mohanty dan P. K. Tripathy, Data Structure and Algorithms Using C++. New York City : Wiley Publishing, 2021.
- [5] V. Vashist, “Graphs Data Structure in C++,” Medium, Aug. 07, 2023. https://medium.com/@vinay.vashist2003/graphs-data-structure-in-c-ab7b4205f41a (accessed Jun. 15, 2024).
