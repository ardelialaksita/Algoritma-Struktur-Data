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

![2D MATRIX](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/9915ca43-51c3-46d6-afda-410d3810ce0f)

**_Source: Sitasi 5_**

**2. Adjacency List**

![ADJACENCY LIST](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/f237025a-2b53-4f65-8b60-d094fe0c2628)

**_Source: Sitasi 5_**

**3. BFS Traversal**

![BFS TRAVERSAL](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/3826c76c-7759-4fdc-8575-9fbe4f25e5c5)

**_Source: Sitasi 5_**

Struktur Data yang diperlukan untuk menjalankan algoritma BFS antara lain:

- **Queue**: untuk menyimpan node anak atau terhubung yang masih perlu dijelajahi.
- **Unordered Map or Vector**: untuk mengetahui apakah suatu node tertentu dikunjungi atau tidak.


### Tree (Pohon)
Tree atau pohon yaitu kumpulan node yang saling terhubung satu sama lain dalam suatu kesatuan yang membentuk layaknya struktur sebuah pohon [2]. Struktur Tree adalah suatu cara merepresentasikan suatu struktur hirarki ( one — to many ) secara grafis yang mirip sebuah pohon, walaupun pohon tersebut hanya tampak sebagai kumpulan — node — node dari atas ke bawah [2]. Red-Black Tree adalah binary search tree yang menggunakan atribut ekstra untuk setiap nodenya, seperti warna dimana yang digunakan adalah merah atau hitam [4]. Kita juga harus menyimpan track dari parents nodenya.

### Implementasi Konsep Pohon (Tree):
![ALGORITMA POHON](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/48f09976-e47e-45ad-b126-5bf676bdee58)

_**Source: Sitasi 2**_

- Data yang pertama kali masuk akan menjadi Node Root.
- Data yang lebih kecil dari node root akan masuk dan menempati node kiri dari node Root.
- Jika ada data yang lebih besar dari Node Root maka akan masuk dan menempati node sebelah kanan dari Node Root.

### Traversal Pohon (Tree):
- **Pre-Order Traversal**: yaitu mengunjungi atau melihat node dari suatu pohon dimana dimulai dari node root, menuju ke subtrees kiri, dan terakhir ke subtrees kanan.
- **In-Order Traversal**: yaitu mengunjungi atau melihat node dari suatu pohon dimana dimulai dari node subtrees kiri, menuju ke root, dan terakhir ke subtrees kanan.
- **Post-Order Traversal**: yaitu mengunjungi atau melihat node dari suatu pohon dimana dimulai dari node subtrees kiri, menuju ke subtrees kanan, dan terakhir ke root. 


# Contoh Program
```C++

```

# Penjelasan Alur Program


# Referensi
- [1] A. Subero, Codeless Data Structures and Algorithms: Learn DSA Without Writing a Single Line of Code . Edisi Pertama. Moruga (US) : Apress Publisher, 2020.
- [2] D. Bali, “Memahami Konsep Tree dalam Struktur Data Lengkap dengan Source Code Programnya,” Medium, Jun. 14, 2021. https://daismabali.medium.com/memahami-konsep-tree-dalam-struktur-data-lengkap-dengan-source-code-programnya-acbd0a8733d6 (accessed Jun. 15, 2024).
- [3] J. Farrier, Data Structures and Algorithms with the C++ STL. Edisi Pertama. Birmingham : Packt Publishing Ltd, 2024.
- [4] S.N. Mohanty dan P. K. Tripathy, Data Structure and Algorithms Using C++. New York City : Wiley Publishing, 2021.
- [5] V. Vashist, “Graphs Data Structure in C++,” Medium, Aug. 07, 2023. https://medium.com/@vinay.vashist2003/graphs-data-structure-in-c-ab7b4205f41a (accessed Jun. 15, 2024).
