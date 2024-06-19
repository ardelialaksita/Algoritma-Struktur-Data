# <h1 align="center">Priority Queue and Heaps</h1>
<p align="center">2311110051 - Ardelia Rachma Laksita</p>

## Table of Contents
1. [Penjelasan](#penjelasan)
2. [Contoh Program](#contoh-program)
3. [Penjelasan Alur Program](#penjelasan-alur-program)

# Penjelasan
Priority Queue adalah struktur data khusus yang memungkinkan kita menyimpan elemen-elemen dengan nilai prioritas tertentu [10]. Konsep dari Priority Queue mirip dengan Queue biasa. Yang membedakan adalah pada Priority Queue terdapat nilai prioritas elemen yang akan menentukan urutan elemen saat diambil. Pada algoritma priority queue, setiap item di queue memiliki prioritas dimana elemen dengan prioritas yang lebih tinggi akan dikeluarkan (dequeue) terlebih dahulu sebelum elemen yang memiliki prioritas lebih rendah [3]. 

Priority Queue memerlukan key-value untuk mengurutkan elemen atau item tanpa menggunakan queue [3]. Urutan dari elemen-elemen akan diabaikan di dalam operasi stack atau queue [2]. Sebuah priority queue memungkinkan untuk memperpanjang konsep dari queue melalui _setting_ atau aturan dari sebuah prioritas elemen di queue [8]. Priority queue merupakan jenis queue yang elemennya dihapus berdasarkan urutan prioritas [12]. Elemen dengan prioritas tertinggi akan diambil atau diekstrak terlebih dahulu tanpa harus memindahkan elemen-elemen lainnya. Urutannya juga tidak selalu sama, melainkan berdasarkan priority value saat itu. Prioritas dapat ditentukan menggunakan aturan yang telah ditetapkan sebelumnya atau dengan membandingkan nilai-nilai elemen [11].

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
