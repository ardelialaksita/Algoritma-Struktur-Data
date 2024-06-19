
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

```

# Penjelasan Alur Program


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
